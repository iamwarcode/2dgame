#undef main
#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <window.h>
#include <sstream>

int main(int argc, char *argv[]){
  Window w(600, 450, "2d game");
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
      w.Clear(1.0f, 1.0f, 1.0f, 1.0f);
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