
varying vec3 L;
varying vec3 V;

uniform vec3 LightPosition;

void main(void) 
{
	vec3 eyePos = vec3 (0.0,0.0,5.0);
	vec3 vertex = vec3 (gl_ModelViewMatrix * gl_Vertex);
	
	V = normalize (eyePos - vertex);
	L = normalize (LightPosition - vertex);
    
    // Calculating tangent space (Normal, Binormal and Tangent)
    vec3 N = normalize(gl_NormalMatrix * gl_Normal);
    vec3 T;
    T.x = -gl_Normal.y;
    T.y = gl_Normal.x;
    T.z = gl_Normal.z;
    T = normalize (gl_NormalMatrix * T);
  
    vec3 B = cross(N, T);

    vec3 St; // tangent space
    St.x = dot(L, T);
    St.y = dot(L, B);
    St.z = dot(L, N);
    L = normalize(St);

    St.x = dot(V, T);
    St.y = dot(V, B);
    St.z = dot(V, N);
    V = normalize(St);
    
    
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_TexCoord[1] = gl_MultiTexCoord1;    
    gl_Position    = gl_ModelViewProjectionMatrix*gl_Vertex;  
	//gl_Position = ftransform();
}

