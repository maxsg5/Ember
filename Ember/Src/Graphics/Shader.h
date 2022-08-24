#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../Math/glm.hpp"

struct shaderSource
{
    std::string vertexSource;
    std::string fragmentSource;
};

class Shader
{
public:
    Shader(const std::string& filepath);
    uint32_t getId(void);
    void setVec3(const char* location, glm::vec3 uniform);
    void setVec4(const char* location, glm::vec4 uniform);
    void setMat4(const char* location, glm::mat4 uniform);
    void setInt(const char* location, int32_t uniform);
    void setFloat(const char* location, float unifrom);
    void use(void);

private:
    int32_t m_ID;
    shaderSource parseShader(const std::string& filePath);
    uint32_t compileShader(const std::string& source, uint32_t type);
    int32_t checkUniform(const char* location);

};
