#version 330 core
out vec4 FragColor;

in vec4 vPos;

void main() {
    FragColor = vPos;
}