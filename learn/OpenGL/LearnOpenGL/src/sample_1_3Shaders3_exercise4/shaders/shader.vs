#version 330 core
layout(location=0)in vec3 aPos;
layout(location=1)in vec3 aColor;

out vec4 ourColor;

uniform float xoffset;
uniform float yoffset;

void main()
{
    gl_Position=vec4(aPos.x+xoffset,aPos.y+yoffset,aPos.z,1.f);
    ourColor= (gl_Position + 1) /2;
}