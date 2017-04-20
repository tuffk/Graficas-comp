
uniform float posX, posY, posZ;


varying vec3 N;
varying vec3 vertex;

#define shininess 20.0

void main (void)
{
	// Material Color:
	vec4 color0 = vec4(0.0, 0.8, 0.0, 1.0);
	         
	// Specular Color:
	vec4 color2 = vec4(1.0, 0.8, 0.0, 1.0);
				// Lighting
	vec3 eyePos = vec3(0.0,0.0,5.0);
	vec3 lightPos = vec3(posX,posY,posZ);
	
	vec3 V = normalize(eyePos - vertex);
	vec3 L = normalize(lightPos - vertex);
	vec3 R = normalize(-reflect(L, N));
	
	float spec = pow(max(dot(R,V),0.0), shininess);   
	float diffuse = max(dot(N,L),0.0);
	gl_FragColor = spec*color2 + diffuse*color0;
		
}
   
