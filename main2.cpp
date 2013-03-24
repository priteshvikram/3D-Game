#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "main.h"

#define GRASS_WIDTH 10
#define ACCELERATION 0.005f
#define ROTATIONAL_ACCELERATION 0.01f
#define ROTATIONAL_DECCELERATION ROTATIONAL_ACCELERATION/2.0f
#define FRICTIONAL_DECELERATION   ACCELERATION/1.1f

extern GLfloat t,v;

extern bool* keyStates;
extern int width,height;

void init()
{
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	glEnable(GL_BLEND);
	glShadeModel(GL_SMOOTH);
	glPointSize(10);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	width=w;
	height=h;
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(FOV,(double)w / (double)h,0.01f,200.0f);                
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();
}

void drawScene()
{
    GLfloat x,y,z;
        
    glColor3f(1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glPushMatrix();
    keySpecialOperations();/*
    if(keyStates['w'])
    {
         fprintf(stdout,"* cameraz=%f\nreferencez=%f\n",cameraz,referencez);
    }*/
    //gluLookAt(-5*TRACK_WIDTH-13.5,12,18,-TRACK_WIDTH-13.5,2,-1,0,1,0);
    gluLookAt(camerax,cameray,cameraz,referencex,referencey,referencez,upx,upy,upz);
    // tack draw
    trackStraight(-(TRACK_WIDTH/2.0f),(TRACK_WIDTH/2.0f),-(6*TorusRadius),0);
    trackStraight(-(TRACK_WIDTH/2.0f),(TRACK_WIDTH/2.0f),0,3*CAR_LENGTH);
    bumpdraw(-(TRACK_WIDTH/2.0f)-1.5,CAR_LENGTH,1);
    BumpyTrack(-(TRACK_WIDTH/2.0f),(TRACK_WIDTH/2.0f),3*CAR_LENGTH,6*CAR_LENGTH,(TorusRadius/2.0f));
    trackStraight(-(TRACK_WIDTH/2.0f),(TRACK_WIDTH/2.0f),6*CAR_LENGTH,9*CAR_LENGTH);
    bumpdraw((TRACK_WIDTH/2.0f),6*CAR_LENGTH,0);
    for(GLint i=0;i<=3*GRASS_WIDTH;i+=GRASS_WIDTH)
    {
          grass(-(TRACK_WIDTH/2.0f)-i,(TRACK_WIDTH/2.0f)-i,-(6*TorusRadius),0);
          grass(-(TRACK_WIDTH/2.0f)-i,(TRACK_WIDTH/2.0f)-i,1,3*CAR_LENGTH);
          grass(-(TRACK_WIDTH/2.0f)-i,(TRACK_WIDTH/2.0f)-i,3*CAR_LENGTH+1,6*CAR_LENGTH);
          grass(-(TRACK_WIDTH/2.0f)-i,(TRACK_WIDTH/2.0f)-i,6*CAR_LENGTH+1,9*CAR_LENGTH-1);
    }
    turnleft(-(TRACK_WIDTH/2.0f)-1,6*CAR_LENGTH,1);
    trackTurnLeft(-(TRACK_WIDTH/2.0f),(TRACK_WIDTH/2.0f),9*CAR_LENGTH,13*CAR_LENGTH,0,180.0f);
    trackStraight(-5*TRACK_WIDTH-2.25,-4*TRACK_WIDTH-2.25,6*CAR_LENGTH,9*CAR_LENGTH);
    BumpyTrack(-5*TRACK_WIDTH-2.25,-4*TRACK_WIDTH-2.25,3*CAR_LENGTH,6*CAR_LENGTH,(TorusRadius/2.0f));
    trackStraight(-5*TRACK_WIDTH-2.25,-4*TRACK_WIDTH-2.25,0,3*CAR_LENGTH);
    trackStraight(-5*TRACK_WIDTH-2.25,-4*TRACK_WIDTH-2.25,-(6*TorusRadius),0);
    trackTurnLeft(-(TRACK_WIDTH/2.0f),(TRACK_WIDTH/2.0f),-1.2*CAR_LENGTH,2.8*CAR_LENGTH,180.0f,355.5f);
    //trackTurnRight(-(int)(TRACK_WIDTH/2.0f)-1,(int)(TRACK_WIDTH/2.0f),8*CAR_LENGTH,12*CAR_LENGTH,180.0f);
    glTranslatef(0.0f,TorusRadius-(TorusRadius/2.75),0.0f);
    glScalef(0.5f,0.5f,0.5f);
    assembly();
    glScalef(2.0f,2.0f,2.0f);
    glTranslatef(0.0f,-TorusRadius+(TorusRadius/2.75),0.0f);
    glFlush();
    glPopMatrix();   
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500); 
	glutCreateWindow("Basic");
	glutSetCursor(GLUT_CURSOR_NONE);
	glutFullScreen();
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutKeyboardUpFunc(keyUp);
	glutReshapeFunc(handleResize);
	glutSpecialFunc(specialKey);
	glutSpecialUpFunc(specialUp);
	glutPassiveMotionFunc(mouse);
	init();
	glutMainLoop();
	return 0;
}
