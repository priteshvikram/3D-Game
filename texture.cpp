#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

static GLubyte *texture;
static GLubyte *texture2;

extern bool loadPngImage(char *name,int &outWidth,int &outHeight,bool &outHasAlpha,GLubyte **outData);

GLuint setNewTexture(char *filename) 
{
    GLuint texName;
    GLint width,height;
    bool hasAlpha;
    bool success = loadPngImage(filename,width,height,hasAlpha,&texture);
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);
    free(texture);
    return texName;       
}

void setSubTexture(GLuint texName,GLint xoffset,GLint yoffset, GLsizei width, GLsizei height)
{
     glBindTexture(GL_TEXTURE_2D, texName);
     glTexImage2D(GL_TEXTURE_2D, 0,xoffset,yoffset,width,height, GL_RGBA, GL_UNSIGNED_BYTE, texture2);    
}
