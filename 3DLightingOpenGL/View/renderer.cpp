#include "Renderer.h"




renderer::renderer(GLFWwindow*window,float w,float h) { /// this render class is reposnible for drawing everthing to the iwndow and therefore will need refernces to thinsg such as the material class, and the meshes for objects
	this->window = window; // the renderer will also take a refernce to the window so that the swpa buffers method can be used in the main render method 
	this->h = h; // get the widht and height of the window so we can claulcate the aspect ratio for the projection matrix that we will assging in this particualr class to the uniform in the shader 
	this->w = w;

	lightShader = new ShaderClass("vertex.txt", "LightShader.txt");
	combinedLighting = new ShaderClass("vertex.txt", "combinedLight.txt");
}


void renderer::render(scene *scene) { // this is the main render loop that we will call inside of our app update method 

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // first we clear everhting for the next frame to render

	
	glm::mat4 perspective = glm::perspective(scene->cam.getFovy(), this->w / this->h, 0.1f, 100.0f); 
	// generate the perspective matrix that will be used to transform all vertcicies back into NDC before being rasterized 
	
	

	renderCubes(scene, perspective);
	useLightSource(scene,perspective);

	glfwSwapBuffers(window); // finally this is where we swap the window buffers as everhting has been prepeared for the next frame 
	  

	




}


// this method of the renderer class will enable what we need from open gl along with locating all the uniform matrices that we need from the shader and asginging them to the location attributes of this class  
void renderer::configure_OpenGL(GLFWwindow* window, scene *scene) { // this is where we enable everhitng we need to for opengl along with getting the locations for all the  unfiorms we need in order to render the obejcts9 in this case just the matrices uniforms in the vertex shader)

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // setting background colour for the window 
	glEnable(GL_DEPTH_TEST); // enabling depth testing to allow use of the depth buffer 

	int w, h; // ensuring that the window is sized approprtiatley using glview and getting the current size of the window 
	glfwGetFramebufferSize(window, &w, &h); // passing in the width anf hieght vairbale by rfernce so that the actaul widht and height of window is assgined to the memory locations of these two vairbales
	glViewport(0, 0, w, h); // definng the dimseions of the window

	

	//uniform buffer
	combinedLighting->use();
    unsigned int index = glGetUniformBlockIndex(combinedLighting->shaderProgram, "fixedLights");

	glUniformBlockBinding(combinedLighting->shaderProgram, index, 0);

	glGenBuffers(1, &lightBuff);
	glBindBuffer(GL_UNIFORM_BUFFER, lightBuff);

	glBufferData(GL_UNIFORM_BUFFER, scene->getLightSize(), NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	glBindBufferBase(GL_UNIFORM_BUFFER, 0, lightBuff);

	glBindBuffer(GL_UNIFORM_BUFFER, lightBuff);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, scene->getLightSize(), scene->getFixedLights());
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	

	// attaching lighting shader to OpengGl within the  and defining the initial attributes for each struct that represents a type of light 
	combinedLighting->use();
  
	combinedLighting->setVec3("directionalLightProperties.ambient", glm::vec3{ 0.05,0.05f,0.05f });
	combinedLighting->setVec3("directionalLightProperties.diffuse", glm::vec3{ 0.2f,0.2f,0.2f });
	combinedLighting->setVec3("directionalLightProperties.specular", glm::vec3{ 0.7f });
	combinedLighting->setVec3("directionalLightProperties.direction",glm::vec3{ -0.2f, -1.0f, -0.3f });

;   combinedLighting->setFloat("spotLightProperties.constant", 1.0f);
    combinedLighting->setFloat("spotLightProperties.linear", 0.35f);
    combinedLighting->setFloat("spotLightProperties.quadratic", 0.44f);

    combinedLighting->setVec3("spotLightProperties.ambient", glm::vec3{ 0.4f });
    combinedLighting->setVec3("spotLightProperties.diffuse", glm::vec3{ 1.0f,1.0f,1.0f });
    combinedLighting->setVec3("spotLightProperties.specular", glm::vec3(1.0f));

	

	
}






void renderer::useCombinedLightShader(scene* scene, const glm::mat4& perspective, const int& diffId, const int& specId, const int& emissionId) {

	combinedLighting->use();

	combinedLighting->setMat4("perspective", 1, GL_FALSE, perspective);// assigning  the persetcive matrix to the uniform in the shader 

	combinedLighting->setMat4("view", 1, GL_FALSE, scene->cam.getViewMatrix()); /// assigning view matrix 
	combinedLighting->setFloat("time", glfwGetTime());
	combinedLighting->setInt("objectMaterial.diffuse", diffId);
	combinedLighting->setInt("objectMaterial.specular", specId);
	combinedLighting->setInt("objectMaterial.emissionMap", emissionId);

	combinedLighting->setVec3("camPos", scene->cam.getPos());
	combinedLighting->setVec3("camDir", scene->cam.getDir());
	combinedLighting->setFloat("spotLightProperties.inner", glm::cos(glm::radians(12.5f)));	
	combinedLighting->setFloat("spotLightProperties.outer", glm::cos(glm::radians(17.5f)));


}




void  renderer::renderCubes(scene* scene, const glm::mat4& perspective) {
	
	
	diffuseTexture->use(); // bind both the diffuse and specular maps and pass the corresponding id into the lighting shader 
	specularTexture->use();
	emissionMap->use();
	useCombinedLightShader(scene, perspective, diffuseTexture->getId(), specularTexture->getId(),emissionMap->getId());
	

	for (cube& cubes : scene->cubes) { 

     
		combinedLighting->setFloat("objectMaterial.shininess", cubes.getLightMatRef()->getShinieness()); 
		combinedLighting->setMat4("model", 1,GL_FALSE,cubes.getModelTransform());

		cubeMesh->draw(); // bind associated vertex attribute buffer with infomration on how the vertex buffer attached should be read such as the byte stride for each vertex 

	}
	


}



void renderer::useLightSource(scene* scene, const glm::mat4 &perspective) {

	lightShader->use();

	
	lightShader->setMat4("perspective", 1, GL_FALSE, perspective);
	lightShader->setMat4("view", 1,GL_FALSE,scene->cam.getViewMatrix());
	
	lightObject* lightObj = scene->getLightObjects();
	for (int i = 0; i < scene->getFixedLightNum(); i++) {
		lightShader->setMat4("model", 1, GL_FALSE,lightObj->getModelTransform()); 
		lightShader->setVec3("lightingColour", lightObj->getColour());
		
		light->draw();
		lightObj++;
	}
	

}
void renderer::deleteDrawables() {
	// deallocate resources 
	cubeMesh->~CubeMesh();
	emissionMap->~material();
	diffuseTexture->~material();
	specularTexture->~material(); 
	
	delete cubeMesh;
	delete diffuseTexture;
	delete specularTexture; 
	delete emissionMap;
	glDeleteBuffers(1, &lightBuff);




}
void renderer::make_assets() {

    cubeMesh = new CubeMesh({ 0.25f,0.25f,0.25f });

	
	light = new lightMesh(0.5, 0.5, 0.5);
	
    diffuseTexture = new material( "textures/container2.png", 0);
	specularTexture = new material("textures/container2_specular.png",1);
	emissionMap = new material("textures/matrix.jpg", 2);

}


