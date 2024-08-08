#pragma once
#include "config.h"
#include "../Model//scene.h"
#include "../View/CubeMesh.h"
#include "../View/Material.h"
#include "../View/ShaderClass.h"
#include "../View//lightMesh.h"
#include "../View/Material.h"
#include<iostream>

class renderer {
public :
	renderer(GLFWwindow* window,float w,float h);
	void configure_OpenGL(GLFWwindow* window, scene * scene);
	void render(scene* scene);
	void renderCubes(scene* scene, const glm::mat4& perspective);
	void useLightSource(scene* scene, const glm::mat4 &perspective);
	void useCombinedLightShader(scene* scene, const glm::mat4& perspective, const int& diffId, const int& specId, const int& emissionId);

	void make_assets(); 
	void deleteDrawables();

private:
	float w, h;
	unsigned  modelLocation, viewLocation, perspectiveLocation,lightBuff;
	GLFWwindow* window;
	CubeMesh* cubeMesh;


	ShaderClass* lightShader;
	
	ShaderClass* combinedLighting;
	lightMesh* light;
	
	material* specularTexture;
	material* diffuseTexture;
	material* emissionMap;



};