#pragma once
#include "../OpenGlDependencies/config.h"
#include "../View/lightMaterial.h"
class cube {
private:
	glm::vec3 position, colour;
	lightMaterial* lightMat;

	glm::mat4 transform;
	glm::vec3 axis;

public:
	cube(glm::vec3 pos,glm::vec3 colour);
	void update(float dt,glm::vec3 target);
	glm::mat4 getModelTransform();
	glm::vec3 getColour();
	glm::vec3 generateRandom(float minRange, float maxRange);
	void setColour(glm::vec3);
	
	glm::vec3 getPos();

	lightMaterial* getLightMatRef();



};