#pragma once
#include "config.h"
class lightMesh {
public:
	lightMesh(float length, float width, float height);
	void draw();

private:
	unsigned int VBO, VAO;
	unsigned int vertexCount;


};