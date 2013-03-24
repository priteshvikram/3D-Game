#include <stdlib.h>
#include <GL/glut.h>

#define FOV 60.0f

extern GLfloat camerax,cameray,cameraz,referencex,referencey,referencez,upx,upy,upz;

int width,height;
int wprev=0,hprev=0;

void mouse(int x,int y)
{
       int w,h;
       w=-(width/2)+x;
       h=-(height/2)+y;
       referencex+=(w-wprev)/FOV;
       referencey-=(h-hprev)/FOV;
       wprev=w;
       hprev=h;
}
