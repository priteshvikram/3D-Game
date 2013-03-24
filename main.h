#define CAR_LENGTH 5
#define CAR_WIDTH 4
#define TRACK_WIDTH 2.7*CAR_WIDTH
#define TorusRadius 1.0
#define FOV 60.0f
#define STEP 2

extern void keySpecialOperations();
extern void trackTurnLeft(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2,GLfloat startangle,GLfloat endangle);
extern void trackTurnRight(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2,GLfloat angle);
extern void BumpyTrack(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2,GLfloat BumpRadius);
extern void trackStraight(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2);
extern void grass(GLfloat x1,GLfloat x2,GLfloat z1,GLfloat z2);
extern void tyre();
extern void handleKeypress(unsigned char key,int x, int y);
extern void keyUp(unsigned char key,int x,int y);
extern void specialUp(int key ,int x,int y);
extern void specialKey(int key,int x,int y);
extern void assembly(void);
extern void mouse(int x,int y);
extern void bumpdraw(GLfloat x1,GLfloat z1,GLint side);
extern void turnleft(GLfloat x1,GLfloat z1,GLint side);
extern void turnright(GLfloat x1,GLfloat z1,GLint side);

extern GLfloat camerax,cameray,cameraz,referencex,referencey,referencez,upx,upy,upz;
