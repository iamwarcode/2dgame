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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main(int argc, char *argv[]){
  Window w(600, 450, "2d game");
  Shader s("../shaders/basic");
  Shader red("../shaders/red");
  Mesh t,q;
  Music music("../assets/music/rainbow.mp3");
  
  music.Play();
  
  t.Quad(0,0,2,2);
  
  glm::mat4 model;
  glm::mat4 view;
  glm::mat4 proj;
  
  GLint m = glGetUniformLocation(s.program, "m");
  GLint v = glGetUniformLocation(s.program, "v");
  GLint p = glGetUniformLocation(s.program, "p");
  
  view = glm::lookAt(
    glm::vec3(0.0f, 0.0f,  4.0f),
    glm::vec3(0.0f, 0.0f,  0.0f),
    glm::vec3(0.0f, 1.0f,  0.0f)
  );
  
  
  proj = glm::perspective(45.0f, 600.0f/450.0f, 1.0f ,10.0f);
  float delta = 0;
  while(w.running){
      w.FPS(0);
      w.Event();
      w.Clear(0, 0.5, 0.5,1);
        red.Use();
        q.Quad(delta, delta ,0.5, 0.5);
        t.Draw();
        s.Use();
        q.Draw();
      w.SwapBuffers();
      delta = delta + w.FPS(60)/1000.0f;
  }
  
  return 0;
}
