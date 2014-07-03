#undef main
#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>
#include <sstream>

#include <window.h>
#include <shader.h>

int main(int argc, char *argv[]){
  Window w(600, 450, "2d game");
  Shader s("../shaders/basic");
  
  float vertices[] = {
    0.0, 0.5, 0.0,
    0.5, -0.5, 0.0,
    -0.5, -0.5, 0.0
  };
  
  float color[] = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
  };
  
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  
  GLuint vbo[2];
  glGenBuffers(2, vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(0);
  
  glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(1);
  
  glUseProgram(s.program);
  
  SDL_Event e;
  int running = 1;
  
  std::stringstream fps;
  Uint32 start;
  while(running){
      start = SDL_GetTicks();
    
      if(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT) {
          running = 0;
          break;
        }  
      }
      
      w.Clear(1,1,1,1);
      glDrawArrays(GL_TRIANGLES, 0, 3);
      w.SwapBuffers();
      if(SDL_GetTicks()-start < 17){
        SDL_Delay(17-(SDL_GetTicks()-start));
      }
      
      fps<<"fps = "<<SDL_GetTicks()-start;
      w.SetTitle(fps.str());
      fps.str("");
  }
  
  return 0;
}