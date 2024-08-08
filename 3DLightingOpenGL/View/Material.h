#pragma once
#include "../OpenGlDependencies/config.h"
#include "../OpenGlDependencies/stb_image.h"
class material {
public:
	material(const char* filename,int id);
	~material();
	int getId();
	void use();

private:
	unsigned int texture;
	int id;



};
