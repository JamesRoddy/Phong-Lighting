#include "ShaderClass.h"





ShaderClass::ShaderClass(const std::string& vertexPath, const std::string& fragPath) {
	
	std::string line;
	std::ifstream vertexFile ;  // file objects to read from
	std::ifstream fragFile;
	std::stringstream vertexSrcCode;  // stream to store the incoming shader source code 
	std::stringstream fragSrcCode;

	vertexFile.open(vertexPath); // initialize file objects
	fragFile.open(fragPath);

	if (!fragFile || !vertexFile) {
		std::cout << "couldnt load frag or vertex shader" << std::endl;
	}

	vertexSrcCode << vertexFile.rdbuf(); // read from each of the vertex and fragment files 
	fragSrcCode << fragFile.rdbuf();
    
	std::string sFrag = fragSrcCode.str();
	std::string sVertex = vertexSrcCode.str();

	if (fragSrcCode.str() == "" || vertexSrcCode.str() == "") {
		std::cout << " shader file is either an  empty file or couldnt be read" << std::endl;
	}

	const char* cVertex = sVertex.c_str();
	const char* cFrag = sFrag.c_str();

	vertexSrcCode.str("");
	fragSrcCode.str("");
	vertexFile.close();
	fragFile.close();


	unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER); // generate shader prorgams  
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &cVertex, NULL); // generate shader source code 
	glShaderSource(fragShader, 1, &cFrag, NULL);
	glCompileShader(vertexShader);

	// check for any compliatio  errors
	int success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {

		char info[1024];
		glGetShaderInfoLog(vertexShader, 1024, NULL, info);

		std::cout << "vertex shader comp error at: "<<vertexPath<<"\n" << info;




	}
	glCompileShader(fragShader);
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	if (!success) {

		char info[1024];
		glGetShaderInfoLog(fragShader, 1024, NULL, info);

		std::cout << "frag comp error at " << fragPath << "\n" << info;



	}

	// create the shader prorgam to attach the generated shader object to 
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);

	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);
	if (!success) {

		char info[1024];
		glGetProgramInfoLog(shaderProgram, 1024, NULL, info);

		std::cout << "shader program error  \n" << info;




	}

	glDeleteShader(fragShader);
	glDeleteShader(vertexShader);








}



void ShaderClass::use() {
	glUseProgram(shaderProgram);
}


unsigned int ShaderClass::getProgramId(){
	return shaderProgram;
}


// setters for various uniforms contained within the shader 

void ShaderClass::setMat4(const std::string &name, int amount, GLboolean transpose, const glm::mat4 &mat4X4) {

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), amount, transpose, &mat4X4[0][0]);

}

void ShaderClass::setVec3(const std::string &name, const glm::vec3 &vec3) {


	glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &vec3[0]);


}
void ShaderClass::setVec4(const std::string& name, const glm::vec4& vec4) {


	glUniform4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, &vec4[0]);


}

void ShaderClass::setFloat(const std::string& name, const float& value) {

	glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
}
void ShaderClass::setVec3Arr(const std::string& name, const  float *vec3, int size) {

	glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), size, vec3);

}
void ShaderClass::setInt(const std::string& name, const int& value) {

	
	glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);


}

void ShaderClass::bindUniformBuff(const std::string& name, int binding) {

	unsigned int index = glGetUniformBlockIndex(shaderProgram, name.c_str()); 
	glUniformBlockBinding(shaderProgram, index, binding);

}

unsigned int ShaderClass::getBuffIndex(const std::string &name) {

	return glGetUniformBlockIndex(shaderProgram, name.c_str());

}