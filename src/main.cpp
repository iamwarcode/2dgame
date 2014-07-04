#undef main
#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <window.h>
#include <shader.h>

int main(int argc, char *argv[]){
  Window w(600, 450, "2d game");
  Shader s("../shaders/basic");
  glUseProgram(s.program);
  
  while(w.running){
      w.Event();
      w.Clear(1,1,1,1);
      w.SwapBuffers();
  }
  
  return 0;
}