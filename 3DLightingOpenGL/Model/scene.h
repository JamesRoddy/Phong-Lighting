#pragma once
#include "../OpenGlDependencies/config.h"
#include "../newCamera.h"

#include "cube.h"
#include "lightObject.h"

class scene {
public:

	void update(float dt);
	void updateLightColour();
	void updateLightProperties();
	scene(GLFWwindow* window);
	void moveCamera(cameraInput InputDirection, float dt);
	void rotateCamera(float offsetX, float offsetY, bool constrainPitch);
	void scrollWheelCallBack(GLFWwindow* window, double offsetX, double offsetY);
	size_t getLightSize();
	lightObject* getLightObjects();
	lightProperties *getFixedLights();
	const int getFixedLightNum();
	std::vector<cube>cubes;
	
	lightObject* newLight;
	
	camera cam;


private:
	static const int fixedPointLightNum = 4;
	
	
	lightObject lights[fixedPointLightNum] = {
		glm::vec3(0.7f,  0.2f,  2.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f,  2.0f, -12.0f),
		glm::vec3(0.0f,  0.0f, -3.0f) };
	
	lightProperties lightObjectProperties[fixedPointLightNum];

	
	

	static const int cubePositionCount = 10;
	glm::vec3 positions[cubePositionCount] = { glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f) };
	
	GLFWwindow* sceneWindow;


};