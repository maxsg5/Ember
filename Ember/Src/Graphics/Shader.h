#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>

struct shaderSource
{
    std::string vertexSource;
    std::string fragmentSource;
};

class Shader
{
public:
    Shader(const std::string& filepath);
    unsigned int getId(void);
    void setVec3(const char* location, glm::vec3 uniform);
    void setVec4(const char* location, glm::vec4 uniform);
    void setMat4(const char* location, glm::mat4 uniform);
    void setInt(const char* location, int uniform);
    void setFloat(const char* location, float unifrom);
    void use(void);

private:
    int m_ID;
    shaderSource parseShader(const std::string& filePath);
    unsigned int compileShader(const std::string& source, unsigned int type);
    int checkUniform(const char* location);

};
