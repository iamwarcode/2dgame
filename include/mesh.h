#ifndef MESH_H
#define MESH_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <math.h>

#define PI 3.13159265

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
    void Sphere();
};
    
#endif
  