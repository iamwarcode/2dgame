#version 330

out vec4 color;

void main(){
  vec2 resolution = vec2(600.0, 450.0);
  vec2 position = (gl_FragCoord.xy / resolution.xy) - vec2(0.5);  
  float len = length(position);

  color = vec4(vec3(1-len)*vec3(0,1,1),1.0);
}