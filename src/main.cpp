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
  Mesh t;
  Music music("../assets/music/always.mp3");
  
  music.Play();
  
  t.Sphere();
  
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
  
  while(w.running){
      w.Event();
      w.Clear(0, 0.5, 0.5,1);
        s.Use();
        model = glm::rotate(model, 1.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        glUniformMatrix4fv(m, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(v, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(p, 1, GL_FALSE, glm::value_ptr(proj));
        t.Draw();
        
      w.SwapBuffers();
  }
  
  return 0;
}