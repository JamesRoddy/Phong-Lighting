#pragma once
#include "config.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>

class ShaderClass {
public:
	ShaderClass(const std::string &vertexPath,const std::string &fragPath);
	void use();
	void setInt(const std::string& name, const int &value);
	void setMat4(const std::string &name,int amount,GLboolean transpose,const glm::mat4&mat4X4);
	void setVec3(const std::string &name, const glm::vec3 &vec3);
	void setVec3Arr(const std::string& name, const float * vec3,int size);
	void setFloat(const std::string &name, const float &value);
	void setVec4(const std::string& name, const glm::vec4& vec4);
	void bindUniformBuff(const std::string& name, int binding);
	unsigned int getBuffIndex(const std::string &name);
	unsigned int getProgramId();
	unsigned int shaderProgram;
private:

	

};