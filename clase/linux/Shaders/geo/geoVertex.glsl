#version 120
#extension GL_EXT_geometry_shader4 : enable

void main(void)
{
	
	gl_TexCoord[0] = vec4(abs(gl_Normal), 0.0);
	gl_Position = gl_Vertex;
}

