#include "cube.h"

// this class comes under the model classification and handles things such as moving the cube and orientating it along with creating a martix to repsent its current global space postion 
cube::cube(glm::vec3 pos,glm::vec3 colour) {
	position = pos; // we first pass in a psotion that gets assginged to the cubes postion vector which will be used to tranlsate the cube in its model matrix
	colour = colour;

	axis = generateRandom(0.0f,1.0f);
	
	lightMat = new lightMaterial();



}






void cube::update(float dt,glm::vec3 target){



	transform = glm::mat4{ 1.0f };
	transform = glm::translate(transform, position);
	transform = glm::rotate(transform,(float)glfwGetTime(),axis);

}




glm::vec3 cube::generateRandom(float minRange, float maxRange) {
	glm::vec3 randomVec = { 0.0f,0.0f,0.0f };
	randomVec.x = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange));
	randomVec.y = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange));
	randomVec.z = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange));
	return randomVec;
}
glm::mat4 cube::getModelTransform() { // used to get the cubes model matrix and will retunr a transformed identity matrix that reprsentes the cubes current postion in global space
	

	return transform; // return the cubes model matrix 



}


glm::vec3 cube::getColour() {
	return colour;
}
glm::vec3 cube::getPos() {
	return position;
}
void cube::setColour(glm::vec3 newColour) {
	colour = newColour;
}
lightMaterial* cube::getLightMatRef() {
	return lightMat;
}

