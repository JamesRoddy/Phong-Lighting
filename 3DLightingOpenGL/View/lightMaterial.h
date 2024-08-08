#pragma once

#include "config.h"
class lightMaterial {

public:
	lightMaterial();
	lightMaterial(glm::vec3 amb, glm::vec3 diff, glm::vec3 spec, float shininess);
	glm::vec3 getAmbient();
	glm::vec3 getDiffuse();
	glm::vec3 getSpecular(); 
	void setAmbient(glm::vec3 properties);
	void setDiffuse(glm::vec3 properties);
	void setSpecular(glm::vec3 properties);
	float getShinieness();
	void setshininess(float value);
	glm::vec3 getRandomVector(float minRange, float maxRange);

private:
	glm::vec3 ambient,diffuse,specular;
	float shininess;


};