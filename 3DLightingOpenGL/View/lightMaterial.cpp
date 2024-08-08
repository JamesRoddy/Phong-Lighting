#include "lightMaterial.h"


lightMaterial::lightMaterial() {
	ambient = { 1.0f,1.0f,1.0f };
	diffuse = { 1.0f,1.0f,1.0f };
	specular = { 0.5f,0.5f,0.5f };
	shininess = 32;
}



glm::vec3 lightMaterial::getRandomVector(float minRange, float maxRange) {
	glm::vec3 randomVec;
	randomVec.x = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange)) ;
	randomVec.y = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange));
	randomVec.z = minRange + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (maxRange - minRange));
	return randomVec;
}


lightMaterial::lightMaterial(glm::vec3 amb, glm::vec3 diff, glm::vec3 spec, float shine) {

	ambient = amb;
	diffuse = diff;
	specular = spec;
	shininess = shine;


}


glm::vec3 lightMaterial::getAmbient() {
	return ambient;

}

glm::vec3 lightMaterial::getDiffuse() {
	return diffuse;

}


glm::vec3 lightMaterial::getSpecular() {
	return specular;

}


void lightMaterial::setSpecular(glm::vec3 properties) {

	specular = properties;

};

void lightMaterial::setDiffuse(glm::vec3 properties) {

	diffuse = properties;

};

void lightMaterial::setshininess(float value) {

	shininess = value;
}

float lightMaterial::getShinieness() {

	return shininess ;
}