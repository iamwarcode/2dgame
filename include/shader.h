#ifndef SHADER_H
#define SHADER_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string.h>

class Shader{
  public:
    GLuint program;
    Shader(const std::string& path);
    ~Shader();
};
    
#endif
  