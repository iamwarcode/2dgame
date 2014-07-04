#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <string>
#include <SDL_mixer.h>

class Music{
  private:
    Mix_Music *music;
  public:
    Music(const std::string& path);
    ~Music();
    void Play();
};
    
#endif
  