#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 Color;
uniform mat4 m;
uniform mat4 v;
uniform mat4 p;

void main(){
  Color = color;
  gl_Position = vec4(position.x, -position.y, position.z, 1.0);
}