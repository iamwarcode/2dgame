#version 330

out vec4 color;

void main(){
  vec2 resolution = vec2(600.0, 450.0);
  float aspect = resolution.x/resolution.y;
  vec2 position = (gl_FragCoord.xy/resolution.xy) - vec2(0.5);
  position.x = aspect*position.x;  
  float len = 1.0-length(position);

  color = vec4(vec3(len)*vec3(0,1,1),1.0);
}