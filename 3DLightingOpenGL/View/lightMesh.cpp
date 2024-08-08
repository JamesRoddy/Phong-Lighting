#include "lightMesh.h" 


lightMesh::lightMesh(float length, float width, float height) {


	std::vector<float> vertexAttribs{
		//back face
		-width,-height,-length,1.0f,1.0f,1.0f,
	    -width,height,-length,1.0f,1.0f,1.0f,
		width,height,-length,1.0f,1.0f,1.0f,
		-width,-height,-length,1.0f,1.0f,1.0f, 
		width,-height,-length,1.0f,1.0f,1.0f, 
		width,height,-length,1.0f,1.0f,1.0f,

		//front face
		-width,-height,length,1.0f,1.0f,1.0f,
		-width,height,length,1.0f,1.0f,1.0f,
		width,height,length,1.0f,1.0f,1.0f,
		-width,-height,length,1.0f,1.0f,1.0f,
		width,-height,length,1.0f,1.0f,1.0f,
		width,height,length,1.0f,1.0f,1.0f,

		//top face
		-width,height,-length,1.0f,1.0f,1.0f,
		width,height,-length,1.0f,1.0f,1.0f,
		-width,height,length,1.0f,1.0f,1.0f,
		width,height,-length,1.0f,1.0f,1.0f,
		width,height,length,1.0f,1.0f,1.0f,
		-width,height,length,1.0f,1.0f,1.0f,

		//bottom face
	  - width,-height,-length,1.0f,1.0f,1.0f,
		width,-height,-length,1.0f,1.0f,1.0f,
		-width,-height,length,1.0f,1.0f,1.0f,
		width,-height,-length,1.0f,1.0f,1.0f,
		width,-height,length,1.0f,1.0f,1.0f,
		-width,-height,length,1.0f,1.0f,1.0f,
		//right face
		width, height,-length,1.0f,1.0f,1.0f,
		width,-height,-length,1.0f,1.0f,1.0f,
		width, height,length,1.0f,1.0f,1.0f,
		width, height, length,1.0f,1.0f,1.0f,
		width,-height,length,1.0f,1.0f,1.0f,
		width,-height,-length,1.0f,1.0f,1.0f,

		-width, height,-length,1.0f,1.0f,1.0f,
		-width,-height,-length,1.0f,1.0f,1.0f,
		-width, height,length,1.0f,1.0f,1.0f,
		-width, height, length,1.0f,1.0f,1.0f,
		-width,-height,length,1.0f,1.0f,1.0f,
		-width,-height,-length,1.0f,1.0f,1.0f,






	  /*- width,-height,-length,1.0f,1.0f,1.0f,
		width,-height,-length,1.0f,1.0f,1.0f,
		-width,-height,length,1.0f,1.0f,1.0f,
		width,-height,-length,1.0f,1.0f,1.0f,
		width,-height,length,1.0f,1.0f,1.0f,
		-width,-height,length,1.0f,1.0f,1.0f*/

	/*	- width,-height,-length,1.0f,1.0f,1.0f,
		 width,height,-length,1.0f,1.0f,1.0f,
		-width,height,-length,1.0f,1.0f,1.0f,*/
		
		/*-width,height,-length,1.0f,1.0f,1.0f,
		width,height,length,1.0f,1.0f,1.0f,
		width,height,-length,1.0f,1.0f,1.0f*/



	};

	vertexCount = 30;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexAttribs.size() * sizeof(vertexAttribs[0]), vertexAttribs.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)12);
	glEnableVertexAttribArray(1);



}

void lightMesh::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
}