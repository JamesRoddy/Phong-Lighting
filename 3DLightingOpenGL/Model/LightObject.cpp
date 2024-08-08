
#include "lightObject.h" 



lightObject::lightObject(glm::vec3 initialPos) {

	pointLightProperties.constant = 1.0f;
	pointLightProperties.linear = 0.09f;
	pointLightProperties.quadratic = 0.032f;
	pointLightProperties.position = initialPos;
	pointLightProperties.diffuse = glm::vec3{ 1.0f,1.0f,1.0f };
	pointLightProperties.ambient = glm::vec3{ 0.2f,0.2f,0.2f };
	pointLightProperties.specular = glm::vec3{ 1.0f,1.0f,1.0f };

	colour = pointLightProperties.diffuse;
	
	


}



glm::vec3 lightObject::getRandomVector(float minRange, float maxRange) {
	glm::vec3 randomVec;
	randomVec.x = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange));
	randomVec.y = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange));
	randomVec.z = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange));
	return randomVec;
}

glm::mat4 lightObject::getModelTransform() {

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, pointLightProperties.position);
	model = glm::scale(model, glm::vec3{ 0.2f });
	return model;



}


glm::vec3 lightObject::getColour() {
	return colour;
}


lightProperties lightObject::getProperties() {

	return pointLightProperties;

}
glm::vec3 lightObject::getPos() {
	return pointLightProperties.position;
}

void lightObject::setColour(const glm::vec4 &newColour) {

	colour = newColour;
	pointLightProperties.diffuse = newColour;

}