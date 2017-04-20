
varying vec3 L;
varying vec3 V;

uniform vec3  SurfaceColor;    // = (0.7, 0.6, 0.18)
uniform float SpecularFactor;  // = 0.5

uniform sampler2D bumpNormal;

void main (void)
{

	vec3 normDelta = 2.0 * (texture2D(bumpNormal, gl_TexCoord[0].st).rgb - 0.5);
    normDelta= normalize(normDelta);
        
    vec3 diffuse = SurfaceColor * max(dot(normDelta, L), 0.0);
    vec3 R = normalize(-reflect(L, normDelta));
    
    float spec = max(dot(R, V), 0.0);
    spec *= SpecularFactor;
    diffuse = min(diffuse + spec, vec3(1.0));

    gl_FragColor = vec4(diffuse, 1.0);
 
}

