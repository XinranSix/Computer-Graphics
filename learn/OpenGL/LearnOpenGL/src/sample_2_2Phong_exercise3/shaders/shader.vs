#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view; 
uniform mat4 projection;
uniform vec3 lightPos;

out vec3 LightColor;

uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main() {
    gl_Position = projection*view*model*vec4(aPos.x,aPos.y,aPos.z, 1.0);

    vec3  Normal = mat3(transpose(inverse(model))) * aNormal;
    vec3 Position = vec3(model * vec4(aPos, 1.0f));

     // 环境光
        float ambientStrength = 0.1f;
        vec3 ambient = ambientStrength * lightColor;

        // 漫反射
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(lightPos - Position);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lightColor;

        // 高光
        float specularStrength = 0.5;
        vec3 viewDir = normalize(viewPos - Position);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
        vec3 specular = specularStrength * spec * lightColor;

         LightColor = ambient + diffuse + specular;


}