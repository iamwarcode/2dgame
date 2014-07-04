#ifndef MESH_H
#define MESH_H

#define GLEW_STATIC
#include <GL/glew.h>
    
class Mesh{
  private:
    GLuint vao;
    GLuint vbo;
    int NUM_VERTICES;
  public:
    Mesh();
    ~Mesh();
    void Triangle();
    void Draw();
    void Quad(float x, float y, float width, float height);
};
    
#endif
  