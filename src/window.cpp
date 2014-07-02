#include <window.h>
    
Window::Window(int width, int height, const std::string& title){
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  
  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
  
  context = SDL_GL_CreateContext(window);
  
  glewExperimental = GL_TRUE;
  glewInit();
  
  Clear(1,0,0,1);
}
    
Window::~Window(){
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();  
}

void Window::Clear(float r, float g, float b, float a){
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Window::SwapBuffers(){
  SDL_GL_SwapWindow(window);
}

void Window::SetTitle(const std::string& title){
  SDL_SetWindowTitle(window, title.c_str());
}
  