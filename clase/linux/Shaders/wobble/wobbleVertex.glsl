
uniform float roll;
uniform vec3 LightPosition;

varying float LightIntensity;
varying vec4 color;


float specularContribution = 0.1;
float diffuseContribution  = 1.0 - specularContribution;

void main(void)
{ 

	vec3 ecPosition = vec3 (gl_ModelViewMatrix * gl_Vertex);
    vec3 tnorm      = normalize(gl_NormalMatrix * gl_Normal);
    vec3 lightVec   = normalize(LightPosition - ecPosition);
    vec3 reflectVec = reflect(-lightVec, tnorm);
    vec3 viewVec    = normalize(-ecPosition);
	
	vec4 pos = gl_Vertex;


    float spec      = clamp(dot(reflectVec, viewVec), 0.0, 1.0);
    spec            = pow(spec, 16.0);

    LightIntensity  = diffuseContribution * max(dot(lightVec, tnorm), 0.0)
                      + specularContribution * spec;

	float disp = 0.2*sin(roll)+0.2;
	vec4 dispDir = vec4(gl_Normal,1.0);
	pos += disp*dispDir;
	
	color = gl_Vertex; 
    
       
    //gl_Position     = ftransform();
	gl_Position    = gl_ModelViewProjectionMatrix*pos;  	
}

/*

uniform float roll;
uniform vec3 LightPosition;

void main(void)
{
	vec4 pos = gl_Vertex;
	
	float disp = 0.2*sin(roll)+0.2;
	vec4 dispDir = vec4(gl_Normal,1.0);
	pos += disp*dispDir;
	
	gl_Position     = gl_ModelViewProjectionMatrix*pos;
}
*/


