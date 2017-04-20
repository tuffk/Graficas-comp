#version 120
#extension GL_EXT_geometry_shader4 : enable

void main(void)
{
	vec4 v1 = gl_PositionIn[0]; vec4 v2 = gl_PositionIn[1];
	vec4 v3 = gl_PositionIn[2]; vec4 l1 = v2 - v1; vec4 l2 = v3 - v1;

	// create the original triangle.
	gl_Position = gl_ModelViewProjectionMatrix * v1; 	
	gl_FrontColor = vec4(0.0, 1.0, 0.2, 0.0);
	EmitVertex();

	gl_Position = gl_ModelViewProjectionMatrix * v2; 	
	gl_FrontColor = vec4(0.0, 1.0, 0.2, 0.0);
	EmitVertex();

	gl_Position = gl_ModelViewProjectionMatrix * v3; 	
	gl_FrontColor = vec4(0.0, 1.0, 0.2, 0.0);
	EmitVertex();
	EndPrimitive();
    
	vec3 l1n = l1.xyz; vec3 l2n = l2.xyz;
	// create a 2nd fancy triangle on top of surface
	vec3 N = cross(l1n.xyz, l2n.xyz); N = normalize(N);
	vec4 middle = v1 + 0.333 * l1 + 0.333 * l2;
	// create the face normal triangle.
	gl_Position = gl_ModelViewProjectionMatrix * middle;         
	gl_FrontColor = gl_TexCoordIn[0][0]; 
	EmitVertex();
	
	gl_FrontColor = gl_TexCoordIn[0][0]; 
	gl_Position = gl_ModelViewProjectionMatrix * (middle + 0.2 * vec4(N, 0.0));
	EmitVertex();
	
	gl_FrontColor = gl_TexCoordIn[0][0]; 
	gl_Position = gl_ModelViewProjectionMatrix * (middle + vec4(0.1,0.1,0.1,0.0));
	EmitVertex();
	EndPrimitive();
}

