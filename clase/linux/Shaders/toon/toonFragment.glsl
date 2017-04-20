
uniform float posX, posY, posZ;

varying vec3 N;
varying vec3 vertex;

#define shininess 20.0

void main (void)
{
	// Material Color:
	vec4 color0 = vec4(0.0, 0.8, 0.0, 1.0);
	
	// Silhouette Color:
	vec4 color1 = vec4(0.0, 0.0, 0.0, 1.0);
	         
	// Specular Color:
	vec4 color2 = vec4(1.0, 0.8, 0.0, 1.0);
				// Lighting
	vec3 eyePos = vec3(0.0,0.0,5.0);
	vec3 lightPos = vec3(posX,posY,posZ);
	
	vec3 V = normalize(eyePos - vertex);
	vec3 L = normalize(lightPos - vertex);
	vec3 R = normalize(-reflect(L, N));
	
	float silhouette = max(dot(N,V), 0.0);	
	float spec = pow(max(dot(R,V), 0.0), shininess);   
	float diffuse = max(dot(N,L),0.0);
	
	if(silhouette<0.4) {
		gl_FragColor = color1;
	} else {
		gl_FragColor = color0;
	} 
	
	if (spec < 0.2) {
		gl_FragColor *=0.8;
	} else {
		gl_FragColor = color2;
	}
	
	if (diffuse < 0.5)
		gl_FragColor *=0.8;
	
		
}

