#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define NO_OF_SIDES_ALONG_TORUS_RADIUS 32
#define TorusRadius 1.0
#define AXLE_LENGTH 2.3f
#define FRONT_BACK_DISTANCE  4.0f

void body()
{
    GLfloat angle1,angler;
    GLfloat x,y,z;
    for(GLfloat i=0;i<(2.0f*AXLE_LENGTH)-0.5f;i+=0.5)
    {
           glBegin(GL_QUAD_STRIP);
           for(angle1=0.0-(2*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle1<=220-((360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle1+=(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))
           {
                  angler=angle1*(M_PI/180.0);
                  z=(TorusRadius+((1.5*TorusRadius)/4.0))*cos(angler);
                  y=(TorusRadius+((1.5*TorusRadius)/4.0))*sin(angler);
                  x=0;
                  glVertex3f(x+i,y,z);
                  z=(TorusRadius+((1.5*TorusRadius)/4.0))*cos(angler);
                  y=(TorusRadius+((1.5*TorusRadius)/4.0))*sin(angler);
                  x=0;
                  glVertex3f(x+0.5f+i,y,z);
           }
           glEnd();
    }
    for(GLfloat i=0;i<(2.0f*AXLE_LENGTH)-0.5f;i+=0.5)
    {
           glBegin(GL_QUAD_STRIP);
           for(angle1=-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle1<220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS);angle1+=(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))
           {
                  angler=angle1*(M_PI/180.0);
                  z=(TorusRadius+((1.5*TorusRadius)/4.0))*cos(angler);
                  y=(TorusRadius+((1.5*TorusRadius)/4.0))*sin(angler);
                  x=0;
                  glVertex3f(x+i,y,z);
                  z=(TorusRadius+((1.5*TorusRadius)/4.0))*cos(angler);
                  y=(TorusRadius+((1.5*TorusRadius)/4.0))*sin(angler);
                  x=0;
                  glVertex3f(x+0.5f+i,y,z);
           }
           glEnd();
    }
    for(GLfloat i=0;i<(2.0f*AXLE_LENGTH)-0.5f;i+=0.5)
    {
           glBegin(GL_QUAD_STRIP);
           glVertex3f(i,((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),((5.5*TorusRadius)/4.0f)*cos(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i+0.5,((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),((5.5*TorusRadius)/4.0f)*cos(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i,((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),5.68*FRONT_BACK_DISTANCE+((5.5*TorusRadius)/4.0f)*cos(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i+0.5,((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),5.68*FRONT_BACK_DISTANCE+((5.5*TorusRadius)/4.0f)*cos(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glEnd();
    }
    for(GLfloat i=0.5;i<(2.0f*AXLE_LENGTH)-1;i+=0.5)
    {
           glBegin(GL_QUAD_STRIP);
           glVertex3f(i,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i+0.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-3.2*FRONT_BACK_DISTANCE-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i+0.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-3.2*FRONT_BACK_DISTANCE-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glEnd();
    }
    glBegin(GL_QUAD_STRIP);
           glVertex3f(1,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-3.2*FRONT_BACK_DISTANCE-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(3.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-3.2*FRONT_BACK_DISTANCE-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(1,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-3.2*FRONT_BACK_DISTANCE-0.5-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(3.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-3.2*FRONT_BACK_DISTANCE-0.5-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
    glEnd();         
}
