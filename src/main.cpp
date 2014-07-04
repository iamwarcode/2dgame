#undef main
#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <window.h>
#include <shader.h>
#include <mesh.h>
#include <music.h>

int main(int argc, char *argv[]){
  Window w(600, 450, "2d game");
  Shader s("../shaders/basic");
  Shader red("../shaders/red");
  Mesh m,n;
  Music music("../assets/music/always.mp3");
  
  m.Quad(-0.9, 0.0, 0.05, 0.5);
  n.Quad(+0.9, 0.0, 0.05, 0.5);
  
  music.Play();
  
  while(w.running){
      w.Event();
      w.Clear(0.5, 0.5, 0.5,1);
        red.Use();
        m.Draw();
        s.Use();
        n.Draw();
      w.SwapBuffers();
  }
  
  return 0;
}