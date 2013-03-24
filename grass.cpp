#include <stdlib.h>
#include <GL/glut.h>

#define GRASS_WIDTH 10

char *grassFile = "grass.png";

extern GLuint setNewTexture(char *filename);

void grass(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2)
{
    static GLuint texName3=0;
    static int flag3=0;
    if(flag3==0)
    { 
          texName3=setNewTexture(grassFile); 
          flag3=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, texName3);
    }
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0);  glVertex3f(x1-GRASS_WIDTH-0.5,0,-z1);
    glTexCoord2f(0.0,1.0);  glVertex3f(x1-GRASS_WIDTH-0.5,0,-z2-1);
    glTexCoord2f(1.0,1.0);  glVertex3f(x1-0.5,0,-z2-1);
    glTexCoord2f(1.0,0.0);  glVertex3f(x1-0.5,0,-z1);
    glEnd();
}
