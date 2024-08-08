#include "scene.h"

// the secene class will manage all of the objects in the game world and call the methods of those objects to update their positions when needed 
scene::scene(GLFWwindow*window):cam(glm::vec3{ 0.0f,0.0f,-1.0f },glm::vec3{0.0f,1.0f,0.0f},glm::vec3{0.0f,5.0f,0.0f},-180.0f,0.0f,45.0f,2.5f,0.1f){
	

	for (int i = 0; i < 10; i++) {

		
		cubes.push_back(cube(positions[i], {1.0f, 0.5f, 0.31f}));


	}
	updateLightProperties();

	sceneWindow = window;
	newLight = new lightObject({ 3.0f, 1.0f, -2.0f });
}


void scene::scrollWheelCallBack(GLFWwindow* window, double offsetX, double offsetY) {

	cam.processScrollWheel((float)offsetY);
}

void scene::moveCamera(cameraInput inputDir, float dt) {

	cam.processKeyboard(inputDir, dt);
	

}
 const int scene::getFixedLightNum() {
	 return fixedPointLightNum;
}
 lightObject* scene::getLightObjects() {

	 return lights;

 }

 lightProperties *scene:: getFixedLights() {

	 return lightObjectProperties;
 }

 size_t scene::getLightSize() {
	 return sizeof(lights);
 }

void scene::rotateCamera(float offsetX, float offsetY, bool constrainPitch) { 

	cam.processMouseInput(offsetX,offsetY,constrainPitch);

}


void scene::updateLightProperties() {
	for (int i = 0; i < fixedPointLightNum; i++) {

		lightObjectProperties[i] = lights[i].getProperties();


	}
	

};

void scene::updateLightColour() {

	glm::vec3 lightCol;
	lightCol.x = sin(glfwGetTime() * 3.0f);
	lightCol.y = sin(glfwGetTime() * 4.0f);
	lightCol.z = sin(glfwGetTime() * 1.3f);

	newLight->setColour(glm::vec4(lightCol,1.0f));


}
void scene::update(float dt) {

	/*updateLightColour();*/
	
	for (cube& cube : cubes) { // for each value with the type cube in the vector we get a refernce to it and then call the update method of the object that has the current shared memoery loctaion of the rfernce variable cube 
	   cube.update(dt,cam.getPos());
	}
	


}