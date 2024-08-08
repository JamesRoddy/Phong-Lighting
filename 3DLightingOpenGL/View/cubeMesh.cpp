#include "CubeMesh.h"


CubeMesh::CubeMesh(glm::vec3 size) {
    make_mesh(size.x, size.y, size.z);


}

void CubeMesh::make_mesh(float l, float w, float h) {

    std::vector<float>vertexAttribs{
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, -1.0f, 0.0f,0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f,0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, -1.0f, 1.0f,1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,-1.0f,  1.0f,1.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,-1.0f,  0.0f,1.0f,
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,-1.0f,  0.0f,0.0f,

    -0.5f, -0.5f, 0.5f,   1.0f, 0.0f,0.0f,  0.0f,0.0f,1.0f,  0.0f,0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,  0.0f,0.0f,1.0f,  1.0f,0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,  0.0f,0.0f,1.0f,  1.0f,1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,  0.0f,0.0f,1.0f, 1.0f,1.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,  0.0f,0.0f,1.0f, 0.0f,1.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,  0.0f,0.0f,1.0f, 0.0f,0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f, -1.0f,0.0f,0.0f, 1.0f,0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f, -1.0f,0.0f,0.0f, 1.0f,1.0f,
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f, -1.0f,0.0f,0.0f, 0.0f,1.0f,
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f, -1.0f,0.0f,0.0f, 0.0f,1.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f, -1.0f,0.0f,0.0f, 0.0f,0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f, -1.0f,0.0f,0.0f, 1.0f,0.0f,
      
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,  1.0f,0.0f,0.0f, 1.0f,0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,0.0f,  1.0f,0.0f,0.0f, 1.0f,1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,  1.0f,0.0f,0.0f, 0.0f,1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,0.0f,  1.0f,0.0f,0.0f, 0.0f,1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,  1.0f,0.0f,0.0f, 0.0,0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,  1.0f,0.0f,0.0f, 1.0f,0.0f,
        
    -0.5f, -0.5f, -0.5f,   1.0f, 0.0f,0.0f, 0.0f,-1.0f,0.0f ,0.0f,1.0f,
     0.5f, -0.5f, -0.5f,   1.0f, 0.0f,0.0f, 0.0f,-1.0f,0.0f ,1.0f,1.0f,
     0.5f, -0.5f,  0.5f,   1.0f, 0.0f,0.0f, 0.0f,-1.0f,0.0f ,1.0f,0.0f,
     0.5f, -0.5f,  0.5f,   1.0f, 0.0f,0.0f, 0.0f,-1.0f,0.0f ,1.0f,0.0f,
    -0.5f, -0.5f,  0.5f,   1.0f, 0.0f,0.0f, 0.0f,-1.0f,0.0f ,0.0f,0.0f,
    -0.5f, -0.5f, -0.5f,   1.0f, 0.0f,0.0f, 0.0f,-1.0f,0.0f ,0.0f,1.0f,

    -0.5f,  0.5f, -0.5f,   1.0f, 0.0f,0.0f, 0.0f,1.0f,0.0f ,0.0f,1.0f,
     0.5f,  0.5f, -0.5f,   1.0f, 0.0f,0.0f, 0.0f,1.0f,0.0f ,1.0f,1.0f,
     0.5f,  0.5f,  0.5f,   1.0f, 0.0f,0.0f, 0.0f,1.0f,0.0f ,1.0f,0.0f,
     0.5f,  0.5f,  0.5f,   1.0f, 0.0f,0.0f, 0.0f,1.0f,0.0f ,1.0f,0.0f,
    -0.5f,  0.5f,  0.5f,   1.0f, 0.0f,0.0f, 0.0f,1.0f,0.0f ,0.0f,0.0f,
    -0.5f,  0.5f, -0.5f,   1.0f, 0.0f,0.0f, 0.0f,1.0f,0.0f ,0.0f,1.0f,
    };

    vertexCount = 36; 
    glGenVertexArrays(1, &VAO); // generate vertex array object that will store infomration on how the associated vertex buffer should be read defning the byte stride for each vertex along with pointers to specifc attributes of the vertex   
    glBindVertexArray(VAO); // memeory allocated for the VAO by opengl 

    glGenBuffers(1, &VBO); // generate vertex buffer object that will be used to store all of the vertex data 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexAttribs.size() * sizeof(float), vertexAttribs.data(), GL_STATIC_DRAW); // define the buffer data 

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11*sizeof(float), (void*)0); /// define the layout location of the vertex attribute when it is passed to the vertex shader, the type of data , the byte stride to the next vertex and the offset for the specifc attribute(in this case it is 0)
    glEnableVertexAttribArray(0); 

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11*sizeof(float), (void*)12);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11* sizeof(float), (void*)24);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)36);
    glEnableVertexAttribArray(3);

}

void CubeMesh::draw() {

    glBindVertexArray(VAO); // bind the associated vertex array before drawing ensuring that it is fead into the vertex shader 
    glDrawArrays(GL_TRIANGLES, 0, vertexCount); // define the primitve to be used in order to draw the vertcices and the number of vertecies 

}

CubeMesh::~CubeMesh() {
    // deallocate buffers 
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);



}