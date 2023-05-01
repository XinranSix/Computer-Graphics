#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTexCoords;

out VS_OUT{
    vec2 TexCoords;
}vs_out;

uniform mat4 model;
layout (std140) uniform Matrices { 
    mat4 projection; 
    mat4 view; 
}; 

void main()
{
    vs_out.TexCoords = aTexCoords;    
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}