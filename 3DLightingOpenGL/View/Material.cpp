#include "material.h"
#include "../OpenGlDependencies/stb_image.h"

// this is the main matrial class that will be used to assging textures to objects 
material::material(const char*filePath, int newId) {

	id = newId;

	//stbi_set_flip_vertically_on_load(true); // most image applications will actually have the top left coordinate as 0,0 where as opegl has the bottom right as 0,0 soits best to flip the image on loading 
	int w, h, colourChannel;


	
	unsigned char* imageData = stbi_load(filePath, &w, &h, &colourChannel,0); // load the image data assginig it as an unsigned char passing in a refernce to the vairbale we want to store the widhtmheight, and colour channles of the image in along with the format we want to load the image with in this case STBI_RGB_ALPHA
	glGenTextures(1, &texture); // create the texture using gl create texture passsing in a reference to the texture attribute of the class

	if (imageData) {


		GLenum format ;

		if (colourChannel == 1) {
			format = GL_RED;
		}
		else if (colourChannel == 3) {
			format = GL_RGB;
		}
		else if (colourChannel == 4) {
			format = GL_RGBA;
		}
		std::cout << colourChannel << std::endl;

		
		glBindTexture(GL_TEXTURE_2D, texture); // bind the texture for use
		glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format, GL_UNSIGNED_BYTE, imageData); // load the image dataa specifcying the mimap value which will sclae the texture depeding on the distance along with lowering the resolution if further away then we specifcy the format we want for the texture 
		// then we specifcy the widht height and then a 0(legacy stuff0) then we specify the format again then the type of our texture data(its an usnigned char so unisgned byte) then we speciy the texture data
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // here we specify a texture paramter using gltextureprameteri and in this case we specifcy what we want to do if the texture doesnt fit to what we are covering in this case we tell open gl to wrap it around the area in the s whihc is the x axis for texture coords
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);// here we do the same above for the y
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); // here we specify how opengl should filter the image based on distances this line tells opnegl to use linear interpolctaion the closer we get to the image whihc is much more accurate but more costly(this is also know as bilenaer filtering0 whichi will give a combination of the textures colours dpeding on the postion of the texture cooridnate relative to its neighbours
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// here we say to use the nearest whihc will sleect the part of the texture that is closest to the center of the each image pixel meaning its less accurate but less expsinve rpesentation of the texture 

	}
	else {
		std::cout << "could not load texture: " << filePath << std::endl;
	}
	


	stbi_image_free(imageData); // then once weve bound the image data we free it as it is no longer needed
}

material::~material() {
	glDeleteTextures(1, &texture);
}

void material::use() {

	glActiveTexture(GL_TEXTURE0 + id);
	glBindTexture(GL_TEXTURE_2D, texture);
}
int material::getId() {
	return id;
}