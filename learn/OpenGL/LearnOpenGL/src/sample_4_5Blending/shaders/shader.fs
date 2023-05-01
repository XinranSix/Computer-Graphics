#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

struct Material {
     sampler2D texture_diffuse1; 
}; 
uniform Material material;

void main()
{    
    vec4 fragColor = texture(material.texture_diffuse1, TexCoords);
    if(fragColor.a<0.1) discard;
    FragColor=fragColor;
}