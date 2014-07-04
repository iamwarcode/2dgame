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
    
    glDrawArrays(GL_POINTS, 0, NUM_VERTICES);
    
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


void Mesh::Sphere(){
  glPointSize(5);
  glEnable(GL_DEPTH_TEST);
  
  float v[1428];
  int width  = 32;
  int height = 16;
  
  float theta, phi;
  int i, j, t, ntri, nvec;
  int rad=1;
  
  for(t=0, j=1; j<height-1; j++){
    for(i=0; i<width; i++){
      theta = float(j)/(height-1) * PI;
      phi = float(i)/(width-1)*2*PI;
      v[t++]   = rad*sinf(theta)*cosf(phi);
      v[t++]   = rad*cosf(theta);
      v[t++]   = -rad*sinf(theta)*sinf(phi);    
    }
  }
  
  NUM_VERTICES=1428;
  
  glBindVertexArray(vao);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, 0, 0);
  glBindVertexArray(0);
}
  