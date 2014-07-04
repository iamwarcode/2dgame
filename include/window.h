#ifndef WINDOW_H
#define WINDOW_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <iostream>
#include <string>    

class Window{
  private:
    SDL_Window    *window;
    SDL_GLContext context;
    SDL_Event e;
  public:
    Window(int width, int height, const std::string& title);
    ~Window();
    void Clear(float r, float g, float b, float a);
    void SwapBuffers();
    void SetTitle(const std::string& title);
    
    void Event();
    
    int running;
};
    
#endif
  