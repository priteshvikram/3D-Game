#include <stdlib.h>
#include <GL/glut.h>

extern GLuint setNewTexture(char *filename);

char *left = "left.png";
char *leftback = "back.png";

char *right = "right.png";
char *rightback = "back.png";

extern char *neck;

void turnleft(GLfloat x1,GLfloat z1,GLint side)
{
    static GLuint texName9=0;
    static int flag9=0;
    static GLuint texName10=0;
    static int flag10=0;
    static GLuint texName11=0;
    static int flag11=0;
    if(flag9==0)
    { 
          texName9=setNewTexture(left); 
          flag9=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, side==1?texName9:texName10);
    }
    glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1,2,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1,3,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+1,3,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+1,2,-z1);
    glEnd();     
    if(flag10==0)
    { 
          texName10=setNewTexture(leftback); 
          flag10=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, side==1?texName10:texName9);
    }
    glPolygonMode(GL_BACK,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1,2,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1,3,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+1,3,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+1,2,-z1);
    glEnd();
    if(flag11==0)
    { 
          texName11=setNewTexture(neck); 
          flag11=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D,texName11);
    }
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1+0.425,0,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1+0.425,2,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+0.525,2,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+0.525,0,-z1);
    glEnd();     
}

void turnright(GLfloat x1,GLfloat z1,GLint side)
{
    static GLuint texName12=0;
    static int flag12=0;
    static GLuint texName13=0;
    static int flag13=0;
    static GLuint texName11=0;
    static int flag11=0;
    if(flag12==0)
    { 
          texName12=setNewTexture(right); 
          flag12=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, side==1?texName12:texName13);
    }
    glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1,2,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1,3,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+1,3,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+1,2,-z1);
    glEnd();     
    if(flag13==0)
    { 
          texName13=setNewTexture(rightback); 
          flag13=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, side==1?texName13:texName12);
    }
    glPolygonMode(GL_BACK,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1,2,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1,3,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+1,3,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+1,2,-z1);
    glEnd();
    if(flag11==0)
    { 
          texName11=setNewTexture(neck); 
          flag11=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D,texName11);
    }
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1+0.425,0,-z1);
    glTexCoord2f(0.0,1.0); glVertex3f(x1+0.425,2,-z1);
    glTexCoord2f(1.0,1.0); glVertex3f(x1+0.525,2,-z1);
    glTexCoord2f(1.0,0.0); glVertex3f(x1+0.525,0,-z1);
    glEnd();     
}
