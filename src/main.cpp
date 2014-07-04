#undef main
#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <window.h>
#include <shader.h>
#include <mesh.h>

int main(int argc, char *argv[]){
  Window w(600, 450, "2d game");
  Shader s("../shaders/basic");
  Shader red("../shaders/red");
  Mesh m;
  
  
  m.Triangle();
  
  while(w.running){
      w.Event();
      w.Clear(1,1,1,1);
        red.Use();
        m.Draw();
        s.Use();
        m.Draw();
      w.SwapBuffers();
  }
  
  return 0;
}