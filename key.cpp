#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define CAR_WIDTH 4
#define TRACK_WIDTH 2.7*CAR_WIDTH
#define TorusRadius 1.0
#define ACCELERATION 0.25f
#define FRICTIONAL_DECELERATION   ACCELERATION/1.5f
#define ROTATIONAL_ACCELERATION  ACCELERATION/(TorusRadius+(TorusRadius/4.0f))
#define ROTATIONAL_DECCELERATION FRICTIONAL_DECELERATION/(TorusRadius+(TorusRadius/4.0f))
#define MAXIMUM_VELOCITY_FOR_SATURATION 2.0f
#define INCREMENT 0.1f
#define DISTANCE 0.025f
#define ROTATE_ANGLE 5

extern GLfloat frontdirx,frontdiry,frontdirz;
extern GLfloat carPositionx,carPositiony,carPositionz;
extern GLfloat leftdirx,leftdiry,leftdirz;
extern GLfloat rightdirx,rightdiry,rightdirz;
extern GLfloat carLookx,carLooky,carLookz;
GLfloat anglex=0,angley=0,anglez=0;

GLfloat t=0,v=0,u=0,omega=0,omega0=0,theta=0;
bool* keyStates = new bool[256];
bool* keySpecialStates = new bool[256];

GLfloat camerax=0,cameray=6,cameraz=10,referencex=0,referencey=0,referencez=-3,upx=0,upy=1,upz=0;
GLfloat x,y,z;
GLfloat mod;
GLfloat r;

GLint stop1=0,stop2=0;

void unitVector(GLfloat x1,GLfloat y1,GLfloat z1)
{
    mod = sqrt(x1*x1+y1*y1+z1*z1);     
    x=x1/mod;
    y=y1/mod;
    z=z1/mod;
}

void handleKeypress(unsigned char key,int x, int y) {
	keyStates[key] = true;
}

void keyUp(unsigned char key,int x,int y) {
    keyStates[key] = false;
    if(key=='w')
    {
         stop1=1;
    }
    if(key=='s')
    {
         stop2=1;       
    }     
}

void specialUp(int key ,int x,int y) {
    keySpecialStates[key] = false;
}

void specialKey(int key,int x,int y) {
    keySpecialStates[key] = true;     
}

int exceeds(GLfloat *angle)
{
      GLint q;
      q=(GLint)(*angle/360.0);
      if(q>=1) *angle-=360.0*q;    
}


int exceeds2(GLfloat *angle)
{
      GLint q;
      q=(GLint)(*angle/360.0);
      if(q<=-1) *angle+=360.0*q;    
}

void keySpecialOperations()
{
      if(keyStates['a'])
      {
            if(angley<=20)
                   angley+=0.4;
      }
      if(keyStates['d'])
      {
            if(angley>=-20)
                   angley-=0.4;
      }
      if(stop1==1)
      {
            t+=INCREMENT;
            if(v<0)
            {
                   goto label;
                   stop1=0;
            }
            if(v>=0)
            {
                    v=u-FRICTIONAL_DECELERATION*t;
                    omega=omega0-ROTATIONAL_DECCELERATION*t;
                    theta=(omega0*t)+(0.5*(-ROTATIONAL_DECCELERATION)*t*t);
                    r=(u*t)+(0.5*(-FRICTIONAL_DECELERATION)*t*t);
            }
            unitVector(frontdirx,frontdiry,frontdirz);
            x*=r;
            y*=r;
            z*=r;
            carPositionx+=x;
            carPositiony+=y;
            carPositionz+=z;
            anglex+=theta*(180.0/M_PI);
            t-=INCREMENT;
            u=v;
            omega0=omega;
            cameray=carPositiony+6.0f;
            cameraz=carPositionz+13.0f;
            referencez=carPositionz;       
      }
      label:
      if(stop2==1)
      {
            t+=INCREMENT;
            if(v>0)
            {
                  stop2=0;  
                  goto label2;
            }
            if(v<0)
            {
                   v=u+FRICTIONAL_DECELERATION*t;
                   omega=omega0+ROTATIONAL_DECCELERATION*t;
                   theta=(omega0*t)+(0.5*(ROTATIONAL_DECCELERATION)*t*t);
                   r=(u*t)+(0.5*(FRICTIONAL_DECELERATION)*t*t);
            }
            unitVector(frontdirx,frontdiry,frontdirz);
            x*=r;
            y*=r;
            z*=r;
            carPositionx+=x;
            carPositiony+=y;
            carPositionz+=z;
            anglex+=theta*(180.0/M_PI);
            t-=INCREMENT;
            u=v;
            omega0=omega;
            cameray=carPositiony+6.0f;
            cameraz=carPositionz+13.0f;
            referencez=carPositionz;                 
      }
      label2:
      if(keyStates['w'])
      {
            t+=INCREMENT;
            if(v>=MAXIMUM_VELOCITY_FOR_SATURATION) 
            {
                   r=v*t;
                   theta=omega*t;
                   unitVector(frontdirx,frontdiry,frontdirz);
                   x*=r;
                   y*=r;
                   z*=r;
                   carPositionx+=x;
                   carPositiony+=y;
                   carPositionz+=z;
                   anglex+=theta*(180.0/M_PI);
                   t-=INCREMENT;
                   cameray=carPositiony+6.0f;
                   cameraz=carPositionz+13.0f;
                   referencez=carPositionz;
            }
            else
            {
                   if(v<0)
                   {
                           v=u+(ACCELERATION+FRICTIONAL_DECELERATION)*t;
                           omega=omega0+(ROTATIONAL_ACCELERATION+ROTATIONAL_DECCELERATION)*t;
                           theta=(omega0*t)+(0.5*(ROTATIONAL_ACCELERATION+ROTATIONAL_DECCELERATION)*t*t);
                           r=(u*t)+(0.5*(ACCELERATION+FRICTIONAL_DECELERATION)*t*t);
                   }
                   else
                   {
                           v=u+(ACCELERATION-FRICTIONAL_DECELERATION)*t;
                           omega=omega0+(ROTATIONAL_ACCELERATION-ROTATIONAL_DECCELERATION)*t;
                           theta=(omega0*t)+(0.5*(ROTATIONAL_ACCELERATION-ROTATIONAL_DECCELERATION)*t*t);
                           r=(u*t)+(0.5*(ACCELERATION-FRICTIONAL_DECELERATION)*t*t);
                   }
                   unitVector(frontdirx,frontdiry,frontdirz);
                   x*=r;
                   y*=r;
                   z*=r;
                   carPositionx+=x;
                   carPositiony+=y;
                   carPositionz+=z;
                   anglex+=theta*(180.0/M_PI);                   
                   t-=INCREMENT;
                   u=v;
                   omega0=omega;
                   cameray=carPositiony+6.0f;
                   cameraz=carPositionz+13.0f;
                   //fprintf(stdout,"\ncameraz=%f\ncarPositionz=%f\n",cameraz,carPositionz);
                   referencez=carPositionz;
            }                   
      }
      if(keyStates['s'])
      {
            t+=INCREMENT;
            if(v<=-MAXIMUM_VELOCITY_FOR_SATURATION) 
            {
                   r=v*t;
                   theta=omega*t;
                   unitVector(frontdirx,frontdiry,frontdirz);
                   x*=r;
                   y*=r;
                   z*=r;
                   carPositionx+=x;
                   carPositiony+=y;
                   carPositionz+=z;
                   anglex+=theta*(180.0/M_PI);
                   t-=INCREMENT;
                   cameray=carPositiony+6.0f;
                   cameraz=carPositionz+13.0f;
                   referencez=carPositionz;
            }
            else
            {
                   if(v>=0)
                   {
                           v=u+(-ACCELERATION-FRICTIONAL_DECELERATION)*t;
                           omega=omega0+(-ROTATIONAL_ACCELERATION-ROTATIONAL_DECCELERATION)*t;
                           theta=(omega0*t)+(0.5*(-ROTATIONAL_ACCELERATION-ROTATIONAL_DECCELERATION)*t*t);
                           r=(u*t)+(0.5*(-ACCELERATION-FRICTIONAL_DECELERATION)*t*t);
                   }
                   else
                   {
                           v=u+(-ACCELERATION+FRICTIONAL_DECELERATION)*t;
                           omega=omega0+(-ROTATIONAL_ACCELERATION+ROTATIONAL_DECCELERATION)*t;
                           theta=(omega0*t)+(0.5*(-ROTATIONAL_ACCELERATION+ROTATIONAL_DECCELERATION)*t*t);
                           r=(u*t)+(0.5*(-ACCELERATION+FRICTIONAL_DECELERATION)*t*t);
                   }
                   unitVector(frontdirx,frontdiry,frontdirz);
                   x*=r;
                   y*=r;
                   z*=r;
                   carPositionx+=x;
                   carPositiony+=y;
                   carPositionz+=z;
                   anglex+=theta*(180.0/M_PI); 
                   t-=INCREMENT;
                   u=v;
                   omega0=omega;
                   cameray=carPositiony+6.0f;
                   cameraz=carPositionz+13.0f;
                   referencez=carPositionz;
            }
      }      
      if(keyStates[27])
      {
            glutHideWindow();
            exit(0);
      } 
      if(keySpecialStates[GLUT_KEY_LEFT])
      {     
            if(camerax>=-TRACK_WIDTH/2.0f)
            camerax-=0.05;
      }
      if(keySpecialStates[GLUT_KEY_RIGHT])
      {     
            if(camerax<=TRACK_WIDTH/2.0f)
            camerax+=0.05;
      }
      if(keySpecialStates[GLUT_KEY_UP])
      {
            unitVector(referencex-camerax,referencey-cameray,referencez-cameraz);
            if(mod!=0 && mod>=6)
            {
                  camerax+=DISTANCE*x;
                  cameray+=DISTANCE*y;
                  cameraz+=DISTANCE*z;
            }
      }
      if(keySpecialStates[GLUT_KEY_DOWN])
      {            
            unitVector(referencex-camerax,referencey-cameray,referencez-cameraz);
            if(mod!=0 && mod<=14)
            {
                  camerax-=DISTANCE*x;
                  cameray-=DISTANCE*y;
                  cameraz-=DISTANCE*z;
            }
      }
}
