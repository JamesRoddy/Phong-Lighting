#pragma once
#include "../OpenGlDependencies/config.h"

class CubeMesh {
public:
	void make_mesh(float l, float w, float h);

	CubeMesh(glm::vec3 size);
	~CubeMesh();
	void draw();
private:
	
	unsigned int VBO, VAO, vertexCount;


	

};