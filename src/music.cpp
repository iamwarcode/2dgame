#include <music.h>
    
Music::Music(const std::string& path){
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
  music = Mix_LoadMUS(path.c_str());
}
    
Music::~Music(){
  Mix_FreeMusic(music);
}
  
void Music::Play(){
  Mix_PlayMusic(music, -1);
}