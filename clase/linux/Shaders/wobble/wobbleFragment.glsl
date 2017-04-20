
varying vec4 color;
varying float LightIntensity;

void main (void)
{
	
    gl_FragColor =  color*LightIntensity;
}

