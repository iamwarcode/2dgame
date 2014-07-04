#ifndef MESH_H
#define MESH_H

#define GLEW_STATIC
#include <GL/glew.h>
    
class Mesh{
  private:
    GLuint vao;
    GLuint vbo;
  public:
    Mesh();
    ~Mesh();
    void Triangle();
    void Draw();
};
    
#endif
  