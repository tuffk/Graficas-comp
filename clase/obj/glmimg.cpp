#include <string.h>
#include <math.h>
#include "Texture.h"
#ifdef __APPLE__
    #include <GLUT/glut.h>
#elif defined __linux__ || defined _WIN32 || defined _WIN64
    #include <GL/glut.h>
#endif
#include "glmimg.h"



#ifndef GL_BGR
#define GL_BGR GL_BGR_EXT
#endif

#ifndef GL_BGRA
#define GL_BGRA GL_BGRA_EXT
#endif

static GLint gl_max_texture_size;

GLuint glmLoadTexture(char *filename, GLboolean alpha, GLboolean repeat, GLboolean filtering, GLboolean mipmaps, GLfloat *texcoordwidth, GLfloat *texcoordheight)
{
    GLuint tex;
    int width, height,pixelsize;
    int type;
    int filter_min, filter_mag;
    GLubyte *data, *rdata;
    double xPow2, yPow2;
    int ixPow2, iyPow2;
    int xSize2, ySize2;
    GLint retval;

    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &gl_max_texture_size);
	char *numefis = filename;
    while (*numefis==' ') numefis++;
	Texture ttt;
	LoadTGA(&ttt,(char *)numefis);
	data = ttt.imageData;
	width = ttt.width;
	height = ttt.height;
	type = ttt.type;
	
    if(data == NULL) 
	{
		char err[80];
		sprintf(err,"Nu am putut incarca o textura %s!",numefis);
		printf("ERROR");
    }


    switch(type) {
    case GL_LUMINANCE:
	pixelsize = 1;
	break;
    case GL_RGB:
    case GL_BGR:
	pixelsize = 3;
	break;
    case GL_RGBA:
    case GL_BGRA:
	pixelsize = 4;
	break;
    default:
	printf( "glmLoadTexture(): unknown type 0x%x", type);
	pixelsize = 0;
	break;
    }

    if((pixelsize*width) % 4 == 0)
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    else
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    xSize2 = width;
	ySize2 = height;

    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);   
    
    if(filtering) 
	{
		filter_min = (mipmaps) ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR;
		filter_mag = GL_LINEAR;
    }
    else 
	{
		filter_min = (mipmaps) ? GL_NEAREST_MIPMAP_NEAREST : GL_NEAREST;
		filter_mag = GL_NEAREST;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter_min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter_mag);
   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (repeat) ? GL_REPEAT : GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (repeat) ? GL_REPEAT : GL_CLAMP);

	
    if(mipmaps)		
			gluBuild2DMipmaps(GL_TEXTURE_2D, type, xSize2, ySize2, type, GL_UNSIGNED_BYTE, data);        
	else
			glTexImage2D(GL_TEXTURE_2D, 0, type, xSize2, ySize2, 0, type, GL_UNSIGNED_BYTE, data);   
   
    
    free(data);

    
	/**texcoordwidth = 1.;		// texcoords are in [0,1]
	*texcoordheight = 1.;*/
    
    
	*texcoordwidth = xSize2;		// size of texture coords 
	*texcoordheight = ySize2;
    
   
    return tex;
}
