#include <mesh.h>
    
Mesh::Mesh(){
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
}
    
Mesh::~Mesh(){
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
}

void Mesh::Draw(){
  glBindVertexArray(vao);
    
    glDrawArrays(GL_TRIANGLES, 0, NUM_VERTICES);
    
  glBindVertexArray(0);
}

void Mesh::Triangle(){
  float v[] = {
    -0.5, -0.5, 0,
     0,    0.5, 0,
     0.5, -0.5, 0
  };
  
  NUM_VERTICES = 3;
  
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 0, 0);
  glBindVertexArray(0);
}

void Mesh::Quad(float x, float y, float width, float height){
  float v[] = {
    x-width/2, y+height/2, 0.0,
    x-width/2, y-height/2, 0.0,
    x+width/2, y+height/2, 0.0,
    
    x+width/2, y+height/2, 0.0,
    x-width/2, y-height/2, 0.0,
    x+width/2, y-height/2, 0.0
  };
  
  NUM_VERTICES = 6;
  
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 0, 0);
  glBindVertexArray(0);

}
  