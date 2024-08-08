#pragma once
#include "config.h"


 struct lightProperties {
	 
	 glm::vec3 ambient;
	 float quadratic;
	 glm::vec3 diffuse;
	 float linear;
	 glm::vec3 specular;
	 float constant;
	 glm::vec3 position;
	 float std140Padding;
	


	
};
class lightObject {
private:
	lightProperties pointLightProperties;
	glm::vec3 position, velocity;
	glm::vec3 colour;

	

public:
	
	
	lightObject(glm::vec3 initialPos);
	glm::mat4 getModelTransform();
	glm::vec3 getColour();
	glm::vec3 getPos();
	lightProperties getProperties();
	glm::vec3 getRandomVector(float minRange, float maxRange);

	void setColour(const glm::vec4 &colour);   



};