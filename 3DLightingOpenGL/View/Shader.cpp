#include "Shader.h"


unsigned int make_moudle(const std::string& filePath, unsigned int shaderModule) {
     
    std::ifstream file;
    std::stringstream srcCode;
    std::string line;

    file.open(filePath);
    if (file) {
        std::cout << "file exists" << std::endl;
    }
    while (std::getline(file, line)) {
        std::cout << "line: "<<line << std::endl;
        srcCode << line << "\n";
    }

    std::string shaderString = srcCode.str();
    const char* shader = shaderString.c_str();
    srcCode.str("");
    file.close();

    unsigned int shaderModules = glCreateShader(shaderModule);
    glShaderSource(shaderModules, 1, &shader, NULL);
    glCompileShader(shaderModules);

    int success;
    glGetShaderiv(shaderModules, GL_COMPILE_STATUS, &success);

    if (!success) {
        char errorlog[1024];
        glGetShaderInfoLog(shaderModules, 1024, NULL, errorlog);

        std::cout << "shader compilation error: \n" << errorlog<<std::endl;

    }

    return shaderModules;

}



unsigned int make_shader_program( const std::string &vertexPath, const std::string &fragmentPath) {

    std::vector<unsigned int>shaders;
    
    shaders.push_back(make_moudle(vertexPath, GL_VERTEX_SHADER));
    shaders.push_back(make_moudle(fragmentPath, GL_FRAGMENT_SHADER));

    unsigned int newShaderProgram = glCreateProgram();

    for (unsigned shaderModule : shaders) {
        glAttachShader(newShaderProgram, shaderModule);
    }
    glLinkProgram(newShaderProgram);

    int success;
    glGetProgramiv(newShaderProgram,GL_COMPILE_STATUS,&success);

    if (!success) {
        char errorlog[1024];
        glGetProgramInfoLog(newShaderProgram, 1024, NULL, errorlog);

        std::cout << "shader program error: \n" << errorlog << std::endl;


    }

    return newShaderProgram;




}
