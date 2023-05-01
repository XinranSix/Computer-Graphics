#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture0; 
uniform sampler2D textureSmile; 

void main()
{
   FragColor = mix(texture(texture0, TexCoord), texture(textureSmile, vec2(TexCoord.x,TexCoord.y)), 0.2); 
}