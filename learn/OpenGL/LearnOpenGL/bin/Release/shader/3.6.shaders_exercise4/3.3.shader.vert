#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

uniform vec2 xyOffset;

void main() {
    gl_Position = vec4(aPos.x + xyOffset.x, aPos.y + xyOffset.y, aPos.z, 1.0);
    ourColor = (aColor + abs(gl_Position.xyz) + abs(vec3(xyOffset.x, xyOffset.y, xyOffset.x + xyOffset.y / 2))) / 3;
}