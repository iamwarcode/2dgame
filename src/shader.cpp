#include <shader.h>

std::string readfile(const std::string & path){
    std::ifstream file;
    file.open(path.c_str());
    
    std::string output;
    std::string line;
    
    if(file.is_open()){
      while(file.good()){
        getline(file, line);
        output.append(line+"\n");
      }
    }else{
      std::cerr<<"Unable to read file "<<path<<std::endl;
    }
    return output;
}

Shader::Shader(const std::string& path){
    program = glCreateProgram();
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    
    const GLchar *p;
    std::string source = readfile(path+".vsh");
    p = source.c_str();
    glShaderSource(vs, 1, &p, NULL);
    glCompileShader(vs);
    
    GLint status;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &status);
    
    if(status == GL_FALSE){
      std::cout<<"error in vs";
    }
    
    source = readfile(path+".fsh");
    p = source.c_str();
    glShaderSource(fs, 1, &p, NULL);
    glCompileShader(fs);
    
    glGetShaderiv(fs, GL_COMPILE_STATUS, &status);
    
    if(status == GL_FALSE){
      std::cout<<"error in fs";
    }
    
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    
    glLinkProgram(program);
}
    
Shader::~Shader(){
    
}

void Shader::Use(){
  glUseProgram(program);
}
  