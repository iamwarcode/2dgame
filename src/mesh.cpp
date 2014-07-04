#include <mesh.h>
    
Mesh::Mesh(){
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
}
    
Mesh::~Mesh(){
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
}

void Mesh::Triangle(){
  float v[] = {
    -0.5, -0.5, 0,
     0,    0.5, 0,
     0.5, -0.5, 0
  };
  
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 0, 0);
  glBindVertexArray(0);
}

void Mesh::Draw(){
  glBindVertexArray(vao);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
  glBindVertexArray(0);
}
  