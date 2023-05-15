#version 330 core 
out vec4 FragColor; 
in vec3 Normal; 
in vec3 Position; 
uniform vec3 viewPos; 
uniform samplerCube skybox; 
void main() { 
	vec3 I = normalize(Position - viewPos); 
	vec3 R = reflect(I, normalize(Normal));
	// float ratio = 1.00 / 2.42;

	// vec3 R = refract(I, normalize(Normal), ratio);

	FragColor = vec4(texture(skybox, R).rgb, 1.0);
}
