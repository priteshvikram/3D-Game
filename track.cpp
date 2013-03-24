#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define BUMP_STRIP_ANGLE 22.5

char *road = "road.png";
char *filename1 = "side1.png";

extern GLuint setNewTexture(char *filename);

void footpath(GLfloat x,GLfloat z1,GLfloat z2,GLint dir,GLfloat startangle,GLfloat endangle)
{
    GLfloat theta,x1,thetar,thetar22,thetar2;
    GLfloat j;
    static GLuint texNamePath=0;
    static int flagPath=0;
    if(flagPath==0)
    { 
          texNamePath=setNewTexture(filename1);
          flagPath=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, texNamePath);
    }
    if(dir==0)
    {
          // Down
          glBegin(GL_QUADS);
          glTexCoord2f(0.0,0.0); glVertex3f(x,0,-z1);
          glTexCoord2f(0.0,1.0); glVertex3f(x,0,-z2-1);
          glTexCoord2f(1.0,1.0); glVertex3f(x+0.5,0,-z2-1);
          glTexCoord2f(1.0,0.0); glVertex3f(x+0.5,0,-z1);
          glEnd();
          // Up
          glBegin(GL_QUADS);
          glTexCoord2f(0.0,0.0); glVertex3f(x,0.25,-z1);
          glTexCoord2f(0.0,1.0); glVertex3f(x,0.25,-z2-1);
          glTexCoord2f(1.0,1.0); glVertex3f(x+0.5,0.25,-z2-1);
          glTexCoord2f(1.0,0.0); glVertex3f(x+0.5,0.25,-z1);
          glEnd();
          // Right
          glBegin(GL_QUADS);
          glTexCoord2f(0.0,0.0); glVertex3f(x+0.5,0.25,-z1);
          glTexCoord2f(0.0,1.0); glVertex3f(x+0.5,0.25,-z2-1);
          glTexCoord2f(1.0,1.0); glVertex3f(x+0.5,0,-z2-1);
          glTexCoord2f(1.0,0.0); glVertex3f(x+0.5,0,-z1);
          glEnd();
          // Left
          glBegin(GL_QUADS);
          glTexCoord2f(0.0,0.0); glVertex3f(x,0,-z1);
          glTexCoord2f(0.0,1.0); glVertex3f(x,0,-z2-1);
          glTexCoord2f(1.0,1.0); glVertex3f(x,0.25,-z2-1);
          glTexCoord2f(1.0,0.0); glVertex3f(x,0.25,-z1);
          glEnd();
    }
    else if(dir==1)
    {
          x1=2/(2.0*sin((45.0/(z2-z1))*(M_PI/180.0)));
          for(theta=startangle;theta<=endangle;theta+=(90/(z2-z1)))
          {
                thetar2=theta;
                if(thetar2>=45.0f && thetar2<=90.0f)
                       thetar2-=45.0f;
                if(thetar2>=90.0f && thetar2<=135.0f)
                       thetar2-=90.0f;
                if(thetar2>=135.0f && thetar2<=180.0f)
                       thetar2-=135.0f;
                thetar=theta*(M_PI/180.0);
                thetar22=(theta+(90/(z2-z1)))*(M_PI/180.0);
                glBegin(GL_QUADS);
                glTexCoord2f(0.0,(thetar2/45.0)); glVertex3f(-x1+(x1+x)*cos(thetar),0,-z1-(x1+x)*sin(thetar));
                glTexCoord2f(0.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x1+(x1+x)*cos(thetar22),0,-z1-(x1+x)*sin(thetar22));
                glTexCoord2f(1.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x1+(x1+x+0.5f)*cos(thetar22),0,-z1-(x1+x+0.5f)*sin(thetar22));
                glTexCoord2f(1.0,(thetar2/45.0)); glVertex3f(-x1+(x1+x+0.5f)*cos(thetar),0,-z1-(x1+x+0.5f)*sin(thetar));
                glEnd();
                glBegin(GL_QUADS);
                glTexCoord2f(0.0,(thetar2/45.0)); glVertex3f(-x1+(x1+x)*cos(thetar),0.25,-z1-(x1+x)*sin(thetar));
                glTexCoord2f(0.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x1+(x1+x)*cos(thetar22),0.25,-z1-(x1+x)*sin(thetar22));
                glTexCoord2f(1.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x1+(x1+x+0.5f)*cos(thetar22),0.25,-z1-(x1+x+0.5f)*sin(thetar22));
                glTexCoord2f(1.0,(thetar2/45.0)); glVertex3f(-x1+(x1+x+0.5f)*cos(thetar),0.25,-z1-(x1+x+0.5f)*sin(thetar));
                glEnd();
                glBegin(GL_QUADS);
                glTexCoord2f(0.0,(thetar2/45.0)); glVertex3f(-x1+(x1+x)*cos(thetar),0,-z1-(x1+x)*sin(thetar));
                glTexCoord2f(0.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x1+(x1+x)*cos(thetar22),0,-z1-(x1+x)*sin(thetar22));
                glTexCoord2f(1.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x1+(x1+x)*cos(thetar22),0.25,-z1-(x1+x)*sin(thetar22));
                glTexCoord2f(1.0,(thetar2/45.0)); glVertex3f(-x1+(x1+x)*cos(thetar),0.25,-z1-(x1+x)*sin(thetar));
                glEnd();
                glBegin(GL_QUADS);
                glTexCoord2f(0.0,(thetar2/45.0)); glVertex3f(-x1+(x1+x+0.5f)*cos(thetar),0,-z1-(x1+x+0.5f)*sin(thetar));
                glTexCoord2f(0.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x1+(x1+x+0.5f)*cos(thetar22),0,-z1-(x1+x+0.5f)*sin(thetar22));
                glTexCoord2f(1.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x1+(x1+x+0.5f)*cos(thetar22),0.25,-z1-(x1+x+0.5f)*sin(thetar22));
                glTexCoord2f(1.0,(thetar2/45.0)); glVertex3f(-x1+(x1+x+0.5f)*cos(thetar),0.25,-z1-(x1+x+0.5f)*sin(thetar));
                glEnd();
          }
    }
}

void trackTurnLeft(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2,GLfloat startangle,GLfloat endangle)
{
    GLfloat theta,x,thetar,thetar22,thetar2;
    //GLfloat i,j;
    static GLuint texName5=0;
    static int flag5=0;
    if(flag5==0)
    { 
          texName5=setNewTexture(road); 
          flag5=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, texName5);
    }
    x=2/(2.0*sin((45.0/(z2-z1))*(M_PI/180.0)));
    for(theta=startangle;theta<=endangle;theta+=(90/(z2-z1)))
    {
         thetar2=theta;
         if(thetar2>=45.0f && thetar2<=90.0f)
                thetar2-=45.0f;
         if(thetar2>=90.0f && thetar2<=135.0f)
                thetar2-=90.0f;
         if(thetar2>=135.0f && thetar2<=180.0f)
                thetar2-=135.0f;
         thetar=theta*(M_PI/180.0);
         thetar22=(theta+(90/(z2-z1)))*(M_PI/180.0);
         glBegin(GL_QUADS);
         glTexCoord2f(0.0,(thetar2/45.0)); glVertex3f(-x+(x+x1)*cos(thetar),0,-z1-(x+x1)*sin(thetar));
         glTexCoord2f(0.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x+(x+x1)*cos(thetar22),0,-z1-(x+x1)*sin(thetar22));
         glTexCoord2f(1.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(-x+(x+x2)*cos(thetar22),0,-z1-(x+x2)*sin(thetar22));
         glTexCoord2f(1.0,(thetar2/45.0)); glVertex3f(-x+(x+x2)*cos(thetar),0,-z1-(x+x2)*sin(thetar));
         glEnd();
    }
    footpath(x1-0.5,z1,z2,1,startangle,endangle);
    footpath(x2,z1,z2,1,startangle,endangle);     
}

void trackTurnRight(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2,GLfloat angle)
{
    GLfloat theta,x,thetar,thetar22,thetar2;
    GLfloat i,j;
    static GLuint texName6=0;
    static int flag6=0;
    if(flag6==0)
    { 
          texName6=setNewTexture(road); 
          flag6=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, texName6);
    }
    x=2/(2.0*sin((45.0/(z2-z1))*(M_PI/180.0)));
    for(theta=0;theta<angle;theta+=(90/(z2-z1)))
    {
         thetar2=theta;
         if(thetar2>=45.0f && thetar2<=90.0f)
                thetar2-=45.0f;
         if(thetar2>=90.0f && thetar2<=135.0f)
                thetar2-=90.0f;
         if(thetar2>=135.0f && thetar2<=180.0f)
                thetar2-=135.0f;
         thetar=theta*(M_PI/180.0);
         thetar22=(theta+(90/(z2-z1)))*(M_PI/180.0);
         glBegin(GL_QUADS);
         glTexCoord2f(0.0,(thetar2/45.0)); glVertex3f(x+(x+x1+0.5f)*cos(thetar)-0.5,0,-z1-(x+x1+0.5f)*sin(thetar));
         glTexCoord2f(0.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(x+(x+x1+0.5f)*cos(thetar22)-0.5,0,-z1-(x+x1+0.5f)*sin(thetar22));
         glTexCoord2f(1.0,(2.0/(z2-z1))+(thetar2/45.0)); glVertex3f(x+(x+x2)*cos(thetar22)-0.5,0,-z1-(x+x2)*sin(thetar22));
         glTexCoord2f(1.0,(thetar2/45.0)); glVertex3f(x+(x+x2)*cos(thetar)-0.5,0,-z1-(x+x2)*sin(thetar));
         glEnd();
    }
    //footpath(x1,z1,z2);
    //footpath(x2,z1,z2);     
}

void BumpyTrack(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2,GLfloat BumpRadius)
{
    GLfloat i;    
    GLfloat x,y,z,theta,thetar=0,thetar22;
    static GLuint texName2=0;
    static int flag2=0;
    if(flag2==0)
    { 
          texName2=setNewTexture(road); 
          flag2=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, texName2);
    }
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0); glVertex3f(x1,0,-z1);
    glTexCoord2f(0.0,0.45); glVertex3f(x1,0,-((z2+z1)/2.0)+BumpRadius+0.5f);
    glTexCoord2f(1.0,0.45); glVertex3f(x2,0,-((z2+z1)/2.0)+BumpRadius+0.5f);
    glTexCoord2f(1.0,0.0); glVertex3f(x2,0,-z1);
    glEnd();
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); 
    glBegin(GL_QUADS);
    for(theta=0,i=0.45;theta<=180.0;theta+=BUMP_STRIP_ANGLE,i+=(BUMP_STRIP_ANGLE/180.0f))
    {
         thetar=theta*(M_PI/180.0);
         thetar22=(theta+BUMP_STRIP_ANGLE)*(M_PI/180.0);
         x=x1;
         y=BumpRadius*sin(thetar);
         z=-((z2+z1)/2.0)+BumpRadius*cos(thetar)+BumpRadius;
         glTexCoord2f(0.0,i);
         glVertex3f(x,y,z);
         
         x=x1;
         y=BumpRadius*sin(thetar22);
         z=-((z2+z1)/2.0)+BumpRadius*cos(thetar22)+BumpRadius;
         glTexCoord2f(0.0,i+(BUMP_STRIP_ANGLE/180.0f));
         glVertex3f(x,y,z);
         
         x=x2;
         y=BumpRadius*sin(thetar22);
         z=-((z2+z1)/2.0)+BumpRadius*cos(thetar22)+BumpRadius;
         glTexCoord2f(1.0,i+(BUMP_STRIP_ANGLE/180.0f));
         glVertex3f(x,y,z);
         
         x=x2;
         y=BumpRadius*sin(thetar);
         z=-((z2+z1)/2.0)+BumpRadius*cos(thetar)+BumpRadius;
         glTexCoord2f(1.0,i);
         glVertex3f(x,y,z);
    }
    glEnd();
    //glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); 
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.55); glVertex3f(x1,0,-((z2+z1)/2.0)-BumpRadius+0.5);
    glTexCoord2f(0.0,1.0); glVertex3f(x1,0,-z2);
    glTexCoord2f(1.0,1.0); glVertex3f(x2,0,-z2);
    glTexCoord2f(1.0,0.55); glVertex3f(x2,0,-((z2+z1)/2.0)-BumpRadius+0.5);
    glEnd();
    footpath(x1-0.5,z1,z2,0,0,0);
    footpath(x2,z1,z2,0,0,0);  
}

void trackStraight(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2)
{
    GLint i,j;
    static GLuint texName=0;
    static int flag=0;
    if(flag==0)
    { 
          texName=setNewTexture(road); 
          flag=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, texName);
    }
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); 
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0.0);  glVertex3f(x1,0,-z1);
    glTexCoord2f(0.0,1.0);  glVertex3f(x1,0,-z2);
    glTexCoord2f(1.0,1.0);  glVertex3f(x2,0,-z2);
    glTexCoord2f(1.0,0.0);  glVertex3f(x2,0,-z1);
    glEnd();
    footpath(x1-0.5,z1,z2,0,0,0);
    footpath(x2,z1,z2,0,0,0);
}
