#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define CAR_LENGTH 8
#define CAR_WIDTH 4
#define NO_OF_SIDES_ALONG_TORUS_RADIUS 32
#define NO_OF_SIDES_ALONG_TORUS_CROSSECTION 16
#define TorusRadius 1.0
#define NO_OF_RIMS 4.0
#define RIM_THICKNESS 10.0f
#define WIND_SHIELD_WIDTH 1
#define WIND_SHIELD_ELEVATION 1.05

GLfloat carPositionx=0,carPositiony=0,carPositionz=-3;
GLfloat frontdirx=0,frontdiry=0,frontdirz=-1;
GLfloat leftdirx=-1,leftdiry=0,leftdirz=0;
GLfloat rightdirx=1,rightdiry=0,rightdirz=0;
GLfloat carLookx=0,carLooky=0,carLookz=-4;

char *tyrefile = "tyre.png";

extern GLuint setNewTexture(char *filename); 
extern GLfloat x,y,z;
extern GLfloat mod;
extern void unitVector(GLfloat x1,GLfloat y1,GLfloat z1);
extern GLfloat anglex,angley,anglez;

void tyre();
void axle();
void tyre_cover();
void car_floor();
void mudguard();
void cornors(int i,int j);
void floorfront();
void door(float angle,float shift);
void floorcircles();

void assembly()
{
    GLfloat posx=0,posy=0,posz=0;
    glBegin(GL_POINTS);
    glVertex3f(carPositionx,carPositiony,carPositionz);
    glEnd();
/*-------------------------------------------- Front tyre ----------------------------------------------------------------------------------*/
    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posy=carPositiony;
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    /* Transformations { */
    glTranslatef(posx,posy,posz);
    glRotatef(anglex,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glRotatef(angley,0,1,0);
    glRotatef(anglez,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    /*  } */
    tyre();   // code for bulding left tyre
    /* Reverting Back Transformations { */
    glRotatef(-anglez,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glRotatef(-angley,0,1,0);
    glRotatef(-anglex,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glTranslatef(-posx,-posy,-posz);
    /* } */
    glTranslatef(posx,posy,posz);
    glRotatef(angley,0,1,0);
    mudguard();
    glRotatef(-angley,0,1,0);
    glTranslatef(-posx,-posy,-posz);
/*-------------------------------------------- Front axle ----------------------------------------------------------------------------------*/    
    glTranslatef(posx,posy,posz);
    axle();
    glTranslatef(-posx,-posy,-posz);
/*-------------------------------------------- Front axle ----------------------------------------------------------------------------------*/
    posx=carPositionx+rightdirx*(CAR_WIDTH/2.0f);
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    /* Transformations { */
    glTranslatef(posx,posy,posz);
    glRotatef(anglex,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glRotatef(angley,0,1,0);
    glRotatef(anglez,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    /*  } */
    tyre();    // code for building right tyre
    /* Reverting Back Transformations { */
    glRotatef(-anglez,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glRotatef(-angley,0,1,0);
    glRotatef(-anglex,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glTranslatef(-posx,-posy,-posz);
    /*  } */
    glTranslatef(posx,posy,posz);
    glRotatef(angley,0,1,0);
    mudguard();
    glRotatef(-angley,0,1,0);
    glTranslatef(-posx,-posy,-posz);
/*-------------------------------------------- Front tyre ----------------------------------------------------------------------------------*/


    
/*-------------------------------------------- Back tyre ----------------------------------------------------------------------------------*/
    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posz=carPositionz+(-1*frontdirz)*(CAR_LENGTH/2.0f);
    
    glTranslatef(posx,posy,posz);
    glRotatef(anglex,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glRotatef(anglez,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    tyre();
    glRotatef(-anglez,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glRotatef(-anglex,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glTranslatef(-posx,-posy,-posz);
    glTranslatef(posx,posy,posz);
    mudguard();
    glTranslatef(-posx,-posy,-posz);
/*-------------------------------------------- Back axle ----------------------------------------------------------------------------------*/        
    glTranslatef(posx,posy,posz);
    axle();
    glTranslatef(-posx,-posy,-posz);
/*-------------------------------------------- Back axle ----------------------------------------------------------------------------------*/        
    posx=carPositionx+rightdirx*(CAR_WIDTH/2.0f);
    posz=carPositionz+(-1*frontdirz)*(CAR_LENGTH/2.0f);
    
    glTranslatef(posx,posy,posz);
    glRotatef(anglex,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glRotatef(anglez,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    tyre();
    glRotatef(-anglez,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glRotatef(-anglex,-cos(angley*(M_PI/180.0)),0,sin(angley*(M_PI/180.0)));
    glTranslatef(-posx,-posy,-posz);
    glTranslatef(posx,posy,posz);
    mudguard();
    glTranslatef(-posx,-posy,-posz);
/*-------------------------------------------- Back tyre ----------------------------------------------------------------------------------*/


    // Front tyre cover
    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    glTranslatef(posx,posy,posz);
    tyre_cover();
    glTranslatef(-posx,-posy,-posz);
    // Back tyre cover
    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posz=carPositionz+(-1*frontdirz)*(CAR_LENGTH/2.0f);
    glTranslatef(posx,posy,posz);
    tyre_cover();
    glTranslatef(-posx,-posy,-posz);     
    // floor
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    glTranslatef(posx,posy,posz);
    car_floor();
    glTranslatef(-posx,-posy,-posz); 
    // floor
    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posy=carPositiony+0.1;
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f)-0.1;
    /* Transformations { */
    glTranslatef(posx,posy,posz);
    floorfront();
    floorcircles();
    glTranslatef(-posx,-posy,-posz);
    
    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posy=carPositiony;
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    
    glTranslatef(posx,posy,posz);
    cornors(-180,0);
    glTranslatef(-posx,-posy,-posz);    
    
    posx=carPositionx+rightdirx*(CAR_WIDTH/2.0f);
    posy=carPositiony;
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    
    glTranslatef(posx,posy,posz);
    cornors(0,180);
    glTranslatef(-posx,-posy,-posz);

    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    glTranslatef(posx,posy,posz);
    door(0,-0.15);
    glTranslatef(-posx,-posy,-posz);
    
    posx=carPositionx+rightdirx*(CAR_WIDTH/2.0f);
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    glTranslatef(posx,posy,posz);
    door(160,0.15);
    glTranslatef(-posx,-posy,-posz);
    
    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posy=carPositiony+1.25*TorusRadius;
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    /* Transformations { */
    glTranslatef(posx,posy,posz);                                                               
    floorfront();
    floorcircles();
    glTranslatef(-posx,-posy,-posz);    
     
    GLfloat angle,angler,y,z,x1,z1;
    for(angle=200.0-((360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle>=165;angle-=0.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))
    {
          angler=angle*(M_PI/180.0);
          z=((5.5*TorusRadius)/4.0)*cos(angler);
          y=((5.5*TorusRadius)/4.0)*sin(angler);
          glTranslatef(posx,y+0.65,posz+z+1.3);                                                               
          floorcircles();
          glTranslatef(-posx,-y-0.65,-posz-z-1.3);
    }
    GLfloat radius=CAR_WIDTH/2.0f;
    glTranslatef(posx,y+0.625,posz+z+1.2);
    glBegin(GL_LINES);
    for(angle=-37.5;angle>=-140;angle-=2.5)
    {
           angler=angle*(M_PI/180.0f);
           x=radius+radius*cos(angler);
           y=((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f));
           z=-1.38+((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f))+(radius-1.5)*sin(angler);
           glVertex3f(x,y-0.5,z);
           glVertex3f(x,y,z);
    }
    glEnd();
    glTranslatef(-posx,-y-0.625,-posz-z-1.2);
    
    posx=carPositionx+leftdirx*(CAR_WIDTH/2.0f);
    posy=carPositiony+1.25*TorusRadius;
    posz=carPositionz+frontdirz*(CAR_LENGTH/2.0f);
    glTranslatef(posx,posy,posz);
    
    angler=-37.5*(M_PI/180.0f);
    x=radius+radius*cos(angler);
    y=-1+((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f));
    z=-3.05+((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f))+(radius-1.5)*sin(angler);
    
    angler=-140*(M_PI/180.0f);
    x1=radius+radius*cos(angler);
    z1=-3.05+((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f))+(radius-1.5)*sin(angler);
    
    glBegin(GL_QUAD_STRIP);
    glVertex3f(x,y,z);
    glVertex3f(x,y-0.95,z);
    glVertex3f((x+x1)/2,y-0.1,z-0.6);
    glVertex3f((x+x1)/2,y-0.9,z-0.4);
    glVertex3f(x1,y,z1);
    glVertex3f(x1,y-0.95,z1);
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glVertex3f(x,y-0.95,z);
    glVertex3f(x,y-1.15,z-0.1);
    glVertex3f((x+x1)/2,y-0.9,z-0.4);
    glVertex3f((x+x1)/2,y-1.15,z-0.4);
    glVertex3f(x1,y-0.95,z1);
    glVertex3f(x1,y-1.15,z1-0.1);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(x1,y,z1);
    glVertex3f(x1,y+1.25,z1+4.5);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(x,y,z1);
    glVertex3f(x,y+1.25,z1+4.5);
    glEnd();
    GLfloat angler2,i;
    for(angle=0,i=0;angle<90;angle+=10,i+=0.15)
    {
          angler=angle*(M_PI/180.0f);
          angler2=(angle+10)*(M_PI/180.0f);
          glBegin(GL_QUAD_STRIP);
          glVertex3f(x1,y+0.001*sin(angler)+i,z1+4.5-4.5*cos(angler));
          glVertex3f(x,y+0.001*sin(angler)+i,z1+4.5-4.5*cos(angler));
          glVertex3f(x1,y+0.001*sin(angler2)+i+0.15,z1+4.5-4.5*cos(angler2));
          glVertex3f(x,y+0.001*sin(angler2)+i+0.15,z1+4.5-4.5*cos(angler2));
          glEnd();
    }
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.25*(x+x1)/2,y+0.01*sin(angler)+i-0.15,z1+4.5-4.5*cos(angler));
    glVertex3f(1.75*(x1+x)/2,y+0.01*sin(angler)+i-0.15,z1+4.5-4.5*cos(angler));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION,z1+6-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION,z1+6-4.5*cos(angler2));
    glEnd();
    // ceiling
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION,z1+6-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION,z1+6-4.5*cos(angler2));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION,z1+9-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION,z1+9-4.5*cos(angler2));
    glEnd();
    // back wind sheild
    glBegin(GL_QUAD_STRIP);
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION,z1+9-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/6,z1+12-4.5*cos(angler2));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION,z1+9-4.5*cos(angler2));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/6,z1+12-4.5*cos(angler2));
    glEnd();
    glBegin(GL_QUAD_STRIP);
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/6,z1+12-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/12-0.1,z1+12.5-4.5*cos(angler2));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/6,z1+12-4.5*cos(angler2));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/12-0.1,z1+12.5-4.5*cos(angler2));
    glEnd();
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/12-0.1,z1+12.5-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/12-0.1,z1+12.5-4.5*cos(angler2));
    
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i-1.6,z1+13.25-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i-1.6,z1+13.25-4.5*cos(angler2));
    
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i-2.25,z1+13.15-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i-2.25,z1+13.15-4.5*cos(angler2));
    
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i-2.35,z1+12.5-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i-2.35,z1+12.5-4.5*cos(angler2));
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.25*(x+x1)/2,y+0.01*sin(angler)+i-0.3,z1+4.5-4.5*cos(angler));
    glVertex3f(1.75*(x1+x)/2,y+0.01*sin(angler)+i-0.3,z1+4.5-4.5*cos(angler));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION-0.15,z1+6-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION-0.15,z1+6-4.5*cos(angler2));
    glEnd();
    // ceiling
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION-0.15,z1+6-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION-0.15,z1+6-4.5*cos(angler2));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION-0.15,z1+9-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION-0.15,z1+9-4.5*cos(angler2));
    glEnd();
    // back wind sheild
    glBegin(GL_QUAD_STRIP);
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION-0.15,z1+9-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/6-0.15,z1+12-4.5*cos(angler2));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION-0.15,z1+9-4.5*cos(angler2));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/6-0.15,z1+12-4.5*cos(angler2));
    glEnd();
    
    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.25*(x+x1)/2,y+0.01*sin(angler)+i-0.3,z1+4.5-4.5*cos(angler));
    glVertex3f(1.75*(x1+x)/2,y+0.01*sin(angler)+i-0.3,z1+4.5-4.5*cos(angler));
    glVertex3f(0.15*(x+x1)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/6-0.15,z1+12-4.5*cos(angler2));
    glVertex3f(1.85*(x1+x)/2,y+0.01*sin(angler2)+i+WIND_SHIELD_ELEVATION/6-0.15,z1+12-4.5*cos(angler2));
    glEnd();
    glTranslatef(-posx,-posy,-posz);                                                                                                                        
}

void door(float angle,float shift)
{
    GLfloat angle1,angler,angle2,angler2;
    GLfloat x,y,z;
    glBegin(GL_QUAD_STRIP);
    for(angle1=-(2*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS)),angle2=215.0-((360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle1<=-10.0,angle2>=120;angle1+=(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS),angle2-=(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))
    {
          angler=angle1*(M_PI/180.0);
          angler2=angle2*(M_PI/180.0);
          z=((6*TorusRadius)/4.0)*cos(angler);
          y=((6*TorusRadius)/4.0)*sin(angler);
          x=0.06*CAR_LENGTH*cos(angle+angler);
          glVertex3f(x+shift,y,z);
          z=((6*TorusRadius)/4.0)*cos(angler2);
          y=((6*TorusRadius)/4.0)*sin(angler2);
          x=0.06*CAR_LENGTH*cos(angle+angler);
          glVertex3f(x+shift,y,z+CAR_LENGTH);
    }
    glEnd();
}

void floorcircles()
{
    GLfloat radius=CAR_WIDTH/2.0f,angle,angler; 
    glBegin(GL_LINE_STRIP);
    for(angle=-190;angle<=-140;angle+=5)
    {
           angler=angle*(M_PI/180.0f);
           x=radius+radius*cos(angler);
           y=((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f));
           z=-0.33+((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f))+(radius+0.28)*sin(angler);
           glVertex3f(x,y,z);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for(angle=10;angle>=-40;angle-=5)
    {
           angler=angle*(M_PI/180.0f);
           x=radius+radius*cos(angler);
           y=((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f));
           z=-0.33+((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f))+(radius+0.28)*sin(angler);
           glVertex3f(x,y,z);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for(angle=-37.5;angle>=-140;angle-=2.5)
    {
           angler=angle*(M_PI/180.0f);
           x=radius+radius*cos(angler);
           y=((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f));
           z=-1.46+((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f))+(radius-1.5)*sin(angler);
           glVertex3f(x,y,z);
    }
    glEnd();
}

void floorfront()
{
    for(GLfloat i=0;i<CAR_WIDTH;i+=0.5)
    {
           glBegin(GL_QUAD_STRIP);
           glVertex3f(i,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i+0.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-0.39*CAR_LENGTH-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i+0.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-0.39*CAR_LENGTH-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glEnd();
    }
    glBegin(GL_QUAD_STRIP);
           glVertex3f(0.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-0.39*CAR_LENGTH-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(3.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-0.39*CAR_LENGTH-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(0.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-0.40*CAR_LENGTH-1-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(3.5,((5.5*TorusRadius)/4.0f)*sin((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),-0.40*CAR_LENGTH-1-((5.5*TorusRadius)/4.0f)*cos((220.0-(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
    glEnd();
    //floorcircles();
}

void cornors(int m,int n)
{
    GLfloat angle,angler,x,y,z,r=0.05;
    for(GLfloat i=-(CAR_LENGTH/16)+(5.5*TorusRadius)/4;i<=(CAR_LENGTH)-(5.5*TorusRadius)/4;i+=0.25)
    {
           glBegin(GL_LINE_STRIP);
           for(angle=m;angle<=n;angle+=20)
           {
                  angler=angle*(M_PI/180.0f);
                  x=r*sin(angler);
                  y=((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f))+r+r*cos(angler);
                  z=i;
                  glVertex3f(x,y,z);                           
           }
           glEnd();
                
    } 
}

void car_floor()
{
    for(GLfloat i=0;i<CAR_WIDTH;i+=0.5)
    {
           glBegin(GL_QUAD_STRIP);
           glVertex3f(i,((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),((5.5*TorusRadius)/4.0f)*cos(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i+0.5,((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),((5.5*TorusRadius)/4.0f)*cos(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i,((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),0.7*CAR_LENGTH+((5.5*TorusRadius)/4.0f)*cos(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glVertex3f(i+0.5,((5.5*TorusRadius)/4.0f)*sin(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)),0.7*CAR_LENGTH+((5.5*TorusRadius)/4.0f)*cos(-(2.5*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0f)));
           glEnd();
    }     
}

void tyre_cover()
{
    GLfloat angle1,angler;
    GLfloat x,y,z;
    for(GLfloat i=0;i<CAR_WIDTH;i+=0.5)
    {
           glBegin(GL_QUAD_STRIP);
           for(angle1=-(2*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle1<=220.0-((360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle1+=(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))
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
}

void mudguard()
{
     GLfloat angle1,angle2,angler2,angler,angler22;
     // Mud Guard
     for(angle1=0.0-(2*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle1<180.0-(2*(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS));angle1+=(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))
     {
           angler=angle1*(M_PI/180.0);
           angler22=(angle1+(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0);
           glBegin(GL_QUAD_STRIP);
           for(angle2=-90.0;angle2<=90.0;angle2+=(360.0/NO_OF_SIDES_ALONG_TORUS_CROSSECTION))
           {
                  angler2=angle2*(M_PI/180.0);
                  z=(TorusRadius+((1.5*TorusRadius)/4.0)*cos(angler2))*cos(angler);
                  y=(TorusRadius+((1.5*TorusRadius)/4.0)*cos(angler2))*sin(angler);
                  x=((1.5*TorusRadius)/4.0)*sin(angler2);
                  glVertex3f(x,y,z);
                  z=(TorusRadius+((1.5*TorusRadius)/4.0)*cos(angler2))*cos(angler22);
                  y=(TorusRadius+((1.5*TorusRadius)/4.0)*cos(angler2))*sin(angler22);
                  x=((1.5*TorusRadius)/4.0)*sin(angler2);
                  glVertex3f(x,y,z);
           }
           glEnd();
    }     
}

void axle()
{
     // axle
     GLfloat angler,angle2,angler2;
     GLfloat r1=TorusRadius-(TorusRadius/4.0);
     GLfloat r2=TorusRadius-(TorusRadius/1.3);
     GLfloat r=(r1-r2)/3.0;
     GLfloat x2,x,y,z;
     for(x2=0;x2<CAR_WIDTH;x2+=(CAR_WIDTH/20.0))
     {
           glBegin(GL_QUAD_STRIP);
           for(angle2=0.0;angle2<=360.0;angle2+=(360.0/NO_OF_SIDES_ALONG_TORUS_CROSSECTION))
           {
                  angler2=angle2*(M_PI/180.0);
                  x=0.0+x2;
                  y=r*cos(angler2);
                  z=r*sin(angler2);
                  glVertex3f(x,y,z);
                  glVertex3f(x+(CAR_WIDTH/20.0),y,z);
           }
           glEnd();
     }     
}

void tyre() {
	
    GLfloat i,j;
    static GLuint texName4=0;
    static int flag4=0;
    if(flag4==0)
    { 
          texName4=setNewTexture(tyrefile); 
          flag4=1;
    }
    else
    {
          glBindTexture(GL_TEXTURE_2D, texName4);
    }
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); 
    GLfloat x,y,z;
    GLfloat angle1,angler,angle2,angler2,angler22,angler33;
    // Tyre
    for(angle1=0.0,i=0.0f;angle1<360.0;angle1+=(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS),i+=(1/NO_OF_SIDES_ALONG_TORUS_RADIUS))
     {
           angler=angle1*(M_PI/180.0);
           angler22=(angle1+(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0);
           glBegin(GL_QUADS);
           for(angle2=0.0,j=0.0f;angle2<360.0;angle2+=(360.0/NO_OF_SIDES_ALONG_TORUS_CROSSECTION),j+=(1/NO_OF_SIDES_ALONG_TORUS_CROSSECTION))
           {
                  angler2=angle2*(M_PI/180.0);
                  angler33=(angle2+(360.0/NO_OF_SIDES_ALONG_TORUS_CROSSECTION))*(M_PI/180.0);
                  
                  z=(TorusRadius+(TorusRadius/4.0)*cos(angler2))*cos(angler);
                  y=(TorusRadius+(TorusRadius/4.0)*cos(angler2))*sin(angler);
                  x=(TorusRadius/4.0)*sin(angler2);
                  glTexCoord2f(j,i); glVertex3f(x,y,z);
                  
                  z=(TorusRadius+(TorusRadius/4.0)*cos(angler2))*cos(angler22);
                  y=(TorusRadius+(TorusRadius/4.0)*cos(angler2))*sin(angler22);
                  x=(TorusRadius/4.0)*sin(angler2);
                  glTexCoord2f(j,i+(1/NO_OF_SIDES_ALONG_TORUS_RADIUS)); glVertex3f(x,y,z);
                  
                  z=(TorusRadius+(TorusRadius/4.0)*cos(angler33))*cos(angler22);
                  y=(TorusRadius+(TorusRadius/4.0)*cos(angler33))*sin(angler22);
                  x=(TorusRadius/4.0)*sin(angler33);
                  glTexCoord2f(j+(1/NO_OF_SIDES_ALONG_TORUS_CROSSECTION),i+(1/NO_OF_SIDES_ALONG_TORUS_RADIUS)); glVertex3f(x,y,z);
                  
                  z=(TorusRadius+(TorusRadius/4.0)*cos(angler33))*cos(angler);
                  y=(TorusRadius+(TorusRadius/4.0)*cos(angler33))*sin(angler);
                  x=(TorusRadius/4.0)*sin(angler33);
                  glTexCoord2f(j+(1/NO_OF_SIDES_ALONG_TORUS_CROSSECTION),i); glVertex3f(x,y,z);
           }
           glEnd();
     }
     // rim of tyre
     //cirlce
     angle2=180.0;
     angler2=angle2*(M_PI/180.0);
     for(angle1=0.0;angle1<360.0;angle1+=(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))
     {
           angler=angle1*(M_PI/180.0);
           angler22=(angle1+(360.0/NO_OF_SIDES_ALONG_TORUS_RADIUS))*(M_PI/180.0);
           glBegin(GL_QUAD_STRIP);
           z=(TorusRadius+(TorusRadius/1.25)*cos(angler2))*cos(angler);
           y=(TorusRadius+(TorusRadius/1.25)*cos(angler2))*sin(angler);
           x=0.0;
           glVertex3f(x,y,z);
           z=(TorusRadius+(TorusRadius/1.25)*cos(angler2))*cos(angler22);
           y=(TorusRadius+(TorusRadius/1.25)*cos(angler2))*sin(angler22);
           x=0.0;
           glVertex3f(x,y,z);
           z=(TorusRadius+(TorusRadius/1.3)*cos(angler2))*cos(angler);
           y=(TorusRadius+(TorusRadius/1.3)*cos(angler2))*sin(angler);
           x=0.0;
           glVertex3f(x,y,z);
           z=(TorusRadius+(TorusRadius/1.3)*cos(angler2))*cos(angler22);
           y=(TorusRadius+(TorusRadius/1.3)*cos(angler2))*sin(angler22);
           x=0.0;
           glVertex3f(x,y,z);
           glEnd();
     }
     // four half circular rim
     GLfloat r1=TorusRadius-(TorusRadius/4.0);
     GLfloat r2=TorusRadius-(TorusRadius/1.3);
     GLfloat r=(r1-r2)/2.0;
     GLfloat mid=(r1+r2)/2.0;
     for(angle1=0.0;angle1<360.0;angle1+=(360.0/NO_OF_RIMS))
     {
           angler=angle1*(M_PI/180.0);
           angler22=(angle1-RIM_THICKNESS)*(M_PI/180.0);
           glBegin(GL_QUAD_STRIP);
           for(angle2=0.0+angle1;angle2<=180.0+angle1;angle2+=11.25)
           {
                  angler2=angle2*(M_PI/180.0);
                  z=mid*cos(angler)+(r)*cos(angler2);
                  y=mid*sin(angler)+(r)*sin(angler2);
                  x=0.0;
                  glVertex3f(x,y,z);
                  z=mid*cos(angler22)+(r)*cos(angler2);
                  y=mid*sin(angler22)+(r)*sin(angler2);
                  x=0.0;
                  glVertex3f(x,y,z);
           }
           glEnd();
     }
}
