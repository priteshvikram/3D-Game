#include <stdlib.h>
#include <GL/glut.h>

extern GLuint setNewTexture(char *filename);

char *bump = "bump.png";
char *bumpback = "back.png";
char *neck = "neck.png";

void bumpdraw(GLfloat x1,GLfloat z1,GLint side)
{
    static GLuint texName6=0;
    static int flag6=0;
    static GLuint texName7=0;
    static int flag7=0;
    static GLuint texName8=0;
    static int flag8=0;
    if(flag6==0)
    { 
          texName6=setNewTexture(bump); 
          flag6=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, side==1?texName6:texName7);
    }
    glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1,2,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1,3,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+1,3,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+1,2,-z1);
    glEnd();     
    if(flag7==0)
    { 
          texName7=setNewTexture(bumpback); 
          flag7=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, side==1?texName7:texName6);
    }
    glPolygonMode(GL_BACK,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1,2,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1,3,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+1,3,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+1,2,-z1);
    glEnd();
    if(flag8==0)
    { 
          texName8=setNewTexture(neck); 
          flag8=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D,texName8);
    }
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1+0.425,0,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1+0.425,2,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+0.525,2,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+0.525,0,-z1);
    glEnd();     
}
