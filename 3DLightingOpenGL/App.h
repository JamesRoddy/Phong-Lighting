#pragma once
#include "../OpenGlDependencies//config.h"
#include "../View/Renderer.h"
#include "../Model/scene.h"

class app {

public:
	app();
	~app();
	void run();
	void setUpGLFW();
	bool appHandleInput(float dt);
	void cursorCallBack(GLFWwindow* window, double  mouseX, double  mouseY);
private:
	GLFWwindow* window;
	int height;
	int width;
	renderer* render;
	scene* newScene;
	bool mButtonDown = false;


	


};