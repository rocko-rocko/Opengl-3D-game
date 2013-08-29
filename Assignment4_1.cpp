#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include "Robot.h"
#include "imageloader.h"
#include "text3d.h"
#include<stdlib.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include "sound.h"
#include<time.h>
#include<vector>
#include<utility>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <deque>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include<iterator>
using namespace std;
#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LL long long
#define LLU unsigned long long
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size()) 
#define SORT(c) sort(ALL(c)) 
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FOR(i,start,end) for(int i=start;i<end;i++)
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9
#define mt(x, y, z) mp(mp(x,y),z)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
template <class T> string str(T Number){

	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	return Result;
}
template <typename T>
  T StringToNumber ( const string &Text )
  {
     istringstream ss(Text);
     T result;
     return ss >> result ? result : 0;
  }
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
double rnd(float d) //for rounding values
{
	          return floor(d + 0.49);
}
#define DEG2RAD(deg) (deg * PI / 180)

typedef struct {
	float x;
	float y;
	float z;
	int flag;
}coord;
// Function Declarations
void drawScene();
void update(int value);
void drawBox(float x,float z,float dis);
void drawBall(float rad);
void drawDiamond();
void drawFlag(float h);
void drawTriangle_f(float h);
void drawCylinder(float h);		  
void drawTriangle();
void initRendering();
void handleResize(int w, int h);
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handlekeyrelease(int key, int x , int y);
void handleMouseclick(int button, int state, int x, int y);
void drawCube(float x,float y,float z,float dis,int tile);
// Global Variables
int count_f=0;
int count_m=0;
int count_c=0;
int status=0;
int count_j=0;
float ball_x = 1.0f;
float ball_y = 0.0f;
float ball_velx = 0.01f;
float ball_vely = 0.02f;
float ball_rad = 0.2f;
float tri_x = 0.0f;
float tri_y = 0.0f;
float theta = 0.0f; 
int pits[10][10]={{0}};
int window_w,window_h;
float box_len=100;
float  _angle = 135.0f;
float _angle_tile= 315.0f;
char curr_dir='f';
int axis=3;
float angleto=0.0;
int count_t=0;
int go=1;
float magnitude=0.0;
int inertia=0;
// constants for arm and leg movement states
Robot::Robot()
{
	armAngles[LEFT] = 0.0;
	armAngles[RIGHT] = 0.0;
	legAngles[LEFT] = 0.0;
	legAngles[RIGHT] = 0.0;

	armStates[LEFT] = FORWARD_STATE;
	armStates[RIGHT] = BACKWARD_STATE;

	legStates[LEFT] = FORWARD_STATE;
	legStates[RIGHT] = BACKWARD_STATE;
}

Robot::~Robot()
{
}

Robot robot;
int moving_tiles=0;
float curr_x=-45;
float curr_y=22;
float curr_z=45;
float pcurr_x=0;
float pcurr_y=0;
float pcurr_z=-2.0;
float eyes_x=curr_x-1;
float eyes_y=curr_y-0.25;
float eyes_z=curr_z-1;
float peyes_x=pcurr_x+1;
float peyes_y=pcurr_y+0.25;
float peyes_z=pcurr_z+1;
float dis=0;
float ini_x=0.0;
float ini_y=0.0;
float block_height=0.0;
float block_width=0.0;
float block_length=0.0;
coord blocks[100][100];
float initial_height=22;
float po_x=((int)(curr_x/10-1))*1;
float po_z=((int)(curr_z/10+1))*1;
vector< pair<int,int> > tiles_po;
int select_tile=0;
int count_e=0;
int rev=0;
int rev_yes=0;
int timer=0;
float prev_x=-5;
float prev_z=4;
float mouse_x;
float mouse_y;
float mouse_z;
int count_h=0;
float tower_x=box_len/2-20;
float tower_y=box_len/2+20;
float tower_z=box_len/2+60;
float curr_tower_x=tower_x;
float curr_tower_y=tower_y;
float curr_tower_z=tower_z;
float velocity=0.0;
float up=0;
float down=0;
int points=0;
void showText(void);
void renderBitmapString(float x, float y, void *font,char *string);
void setOrthographicProjection();
void resetPerspectiveProjection();
int font=(int)GLUT_BITMAP_8_BY_13;
char text_s[11],text_s1[11];
void Robot::DrawCube(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);	// top face
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	// front face
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	// right face
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);	// left face
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	// bottom face
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);	// back face
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glEnd();
	glPopMatrix();
}
void Robot::DrawArm(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f( 0.647059,0.164706,0.1647061);	// red
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 4.0f, 1.0f);		// arm is a 1x4x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
void drawBall(float rad) {

	glBegin(GL_TRIANGLE_FAN);
	for(int i=0 ; i<360 ; i++) {
		glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
	}   
	glEnd();
}
void showText(void)
{
sprintf(text_s,"%d",points);
glColor3f(1.0f,1.0f,1.0f);
setOrthographicProjection();
glPushMatrix();
glLoadIdentity();
glColor3f((float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX);
renderBitmapString(650,40,(char *)font,"Level 1");
glColor3f((float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX);
renderBitmapString(50,60,(char *)font,"Points");
renderBitmapString(135,60,(void *)font,text_s);
glPopMatrix();
resetPerspectiveProjection();
}
void renderBitmapString(float x, float y, void *font,char *st)
{
char *c;
glRasterPos2f(x, y);
for (c=st; *c != '\0'; c++)
{
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}
}
void setOrthographicProjection()
{
glMatrixMode(GL_PROJECTION);
glPushMatrix();
glLoadIdentity();
gluOrtho2D(0, window_w, 0, window_h);
glScalef(1, -1, 1);
glTranslatef(0, -window_h, 0);
glMatrixMode(GL_MODELVIEW);
}
void resetPerspectiveProjection()
{
glMatrixMode(GL_PROJECTION);
glPopMatrix();
glMatrixMode(GL_MODELVIEW);
}
void drawDiamond(){
glBegin(GL_TRIANGLE_FAN);
glColor3f( 1,   1,   0) ; glVertex3f(  0, 1.414, 0); 
glColor3f(   1, 1,   0); glVertex3f(  1, 0, 1); 
glColor3f(   1,   1, 0); glVertex3f(  1, 0,-1);
glColor3f(   1, 1,   0); glVertex3f( -1, 0,-1);
glColor3f(   1,   1, 0); glVertex3f( -1, 0, 1); 
glColor3f(   1, 1,   0); glVertex3f(  1, 0, 1); 
glEnd();
glBegin(GL_TRIANGLE_FAN);
glColor3f (1,   0,   0 ); glVertex3f  (0,-1.414, 0); 
glColor3f (  1, 0,   0 ); glVertex3f  (1, 0, 1); 
glColor3f (  1,   0, 0 ); glVertex3f (-1, 0, 1); 
glColor3f (  1, 0,   0 ); glVertex3f (-1, 0,-1);
glColor3f (  1,   0, 0 ); glVertex3f  (1, 0,-1);
glColor3f (  1, 0,   0 ); glVertex3f  (1, 0, 1);
glEnd();
}
void drawTriangle_f(float h) {

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, h, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, 2*h/3, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(h*sqrt(3)/2, h*0.5, 0.0f);
	glEnd();
}

void drawFlag(float h){
	glPushMatrix();        
	drawCylinder(h);
	glPopMatrix();

	//glRotatef(90, 0.0f, 0.0f, 1.0f);
	drawTriangle_f(h);
}
void drawCylinder(float h){		  
GLUquadricObj *quadratic;
quadratic = gluNewQuadric();
glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
gluCylinder(quadratic,0.1f,0.1f,h,32,32);
}

void Robot::DrawHead(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f( 0.647059,0.164706,0.1647061);	// red
	glTranslatef(xPos, yPos, zPos);
	glScalef(2.0f, 2.0f, 2.0f);		// head is a 2x2x2 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	// Draw Ball
	glPushMatrix();
	glTranslatef(-0.5/2, -0.25, -1.0f);
	glColor3f(0,0,0);
	drawBall(0.1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5/2, -0.25, -1.0f);
	glColor3f(0,0,0);
	drawBall(0.1);
	glPopMatrix();
	glPopMatrix();
}

void Robot::DrawTorso(float xPos, float yPos, float zPos){

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);	// blue
	glTranslatef(xPos, yPos, zPos);
	glScalef(3.0f, 5.0f, 2.0f);		// torso is a 3x5x2 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Robot::DrawLeg(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);

	// draw the foot
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	DrawFoot(0.0f, -5.0f, 0.0f);
	glPopMatrix();		

	glScalef(1.0f, 5.0f, 2.0f);		// leg is a 1x5x1 cube
	glColor3f(0.623529,0.623529,0.372549);	// khakhi

	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Robot::DrawFoot(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 0.5f, 3.0f);
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Robot::DrawRobot(float xPos, float yPos, float zPos)
{
	//printf("here");
	xPos=curr_x;
	yPos=curr_y;
	zPos=curr_z;
	glPushMatrix();	
	glTranslatef(xPos, yPos, zPos);	// draw robot at desired coordinates
	glRotatef(angleto,0,1,0);

	// draw head and torso parts
	DrawHead(1.0f, 2.0f, 0.0f);		
	DrawTorso(1.5f, 0.0f, 0.0f);

	// move the left arm away from the torso and rotate it to give "walking" effect
	glPushMatrix();
	//	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngles[LEFT], 1.0f, 0.0f, 0.0f);
	DrawArm(2.5f, 0.0f, -0.5f);
	glPopMatrix();

	// move the right arm away from the torso and rotate it to give "walking" effect
	glPushMatrix();
	//	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngles[RIGHT], 1.0f, 0.0f, 0.0f);
	DrawArm(-1.5f, 0.0f, -0.5f);
	glPopMatrix();

	// move the left leg away from the torso and rotate it to give "walking" effect
	glPushMatrix();					
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(legAngles[LEFT], 1.0f, 0.0f, 0.0f);
	DrawLeg(-0.5f, -5.0f, -0.5f);
	glPopMatrix();

	// move the right leg away from the torso and rotate it to give "walking" effect

	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(legAngles[RIGHT], 1.0f, 0.0f, 0.0f);
	DrawLeg(1.5f, -5.0f, -0.5f);
	glPopMatrix();

	glPopMatrix();	// pop back to original coordinate system
}

void Robot::Prepare(float dt)
{
	// if leg is moving forward, increase angle, else decrease angle
	for (int side = 0; side < 2; side++)
	{
		if(status!=0){
			// arms
			if (armStates[side] == FORWARD_STATE)
			{
				//printf("believe\n");
				armAngles[side] += 20.0f * dt;
			}else
				armAngles[side] -= 20.0f * dt;

			// change state if exceeding angles
			if (armAngles[side] >= 15.0f)
				armStates[side] = BACKWARD_STATE;
			else if (armAngles[side] <= -15.0f)
				armStates[side] = FORWARD_STATE;

			// legs
			if (legStates[side] == FORWARD_STATE)
				legAngles[side] += 20.0f * dt;
			else
				legAngles[side] -= 20.0f * dt;

			// change state if exceeding angles
			if (legAngles[side] >= 15.0f)
				legStates[side] = BACKWARD_STATE;
			else if (legAngles[side] <= -15.0f)
				legStates[side] = FORWARD_STATE;		
		}
	}
}
void GetOGLPos(int x,int y)
{	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLdouble winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );

	winX = (double)x;
	winY = (double)viewport[3] - (double)y;
	glReadPixels( (double)x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
	mouse_x=posX;
	mouse_y=posY;
	mouse_z=posZ;
	mouse_x*=1000;
	mouse_y*=1000;
	mouse_z*=1000;
	//cout<<mouse_x<<" "<<mouse_y<<" "<<mouse_z<<"\n";
	return;
}

void My_mouse_routine(int x, int y)
{

	mouse_x = x;
	mouse_y = y;
	//cout<<mouse_x<<" "<<mouse_y<<"\n";

}
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
			0,                            //0 for now
			GL_RGB,                       //Format OpenGL uses for image
			image->width, image->height,  //Width and height
			0,                            //The border of the image
			GL_RGB, //GL_RGB, because pixels are stored in RGB format
			GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
			//as unsigned numbers
			image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}
float angle_text = -30.0f;
float angle_diamond = -30.0f;
float scale_text;
float computeScale(const char* strs[4]) {
	float text_maxWidth = 0;
	for(int i = 0; i < 4; i++) {
		float text_width = t3dDrawWidth(strs[i]);
		if (text_width > text_maxWidth) {
			text_maxWidth = text_width;
		}   
	}   

	return 2.6f / text_maxWidth;
}


const char* STRS[4] = {"You", "Lose","The","Game"};
const char* STRS1[4] = {"You", "Won","The","Game"};
const char* STRS2[4] = {"Slippery Tile!", "You","Are","Dead"};
void cleanup() {
        t3dCleanup();
	}

GLuint _textureId; //The id of the texture
GLuint _textureId1; //The id of the texture
GLuint _textureId2; //The id of the texture
GLuint _textureId3; //The id of the texture
GLuint _textureId4; //The id of the texture
GLuint _textureId5; //The id of the texture
GLuint _textureId6; //The id of the texture
int over=0;
vector< pair<int,int> > coins;
int main(int argc, char **argv) {
	srand ( time(NULL) );
	int i,j;
	for(i=0;i<10;i++){for(j=0;j<5;j++){
		pair<int,int> b(i,1+rand()%9);
		if(j%2==0){pits[b.first][b.second]=1;if(!cpresent(coins,mp(b.first,b.second)))coins.pb(mp(b.first,b.second));}
		else pits[b.first][b.second]=5;
		tiles_po.push_back(b);
		if(j%2==0)
			moving_tiles++;
	}
	for(j=0;j<10;j++){
		blocks[i][j].flag=0;
		if(pits[i][j]!=5){
			if(j%3==0 && pits[i][j]!=1)pits[i][j]=2;
			if(j%4==0 && pits[i][j]!=1 && pits[i][j]!=2)pits[i][j]=3;
			if(j%5==0 && pits[i][j]!=1 && pits[i][j]!=2 && pits[i][j]!=3)pits[i][j]=4;
		}
	}
	}
	for(i=9;i>=0;i--){for(j=0;j<10;j++)cout<<pits[j][i]<<" ";cout<<"\n";}
	// pits[0][0]=4;

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);

	window_w = glutGet(GLUT_SCREEN_WIDTH);
	window_h = glutGet(GLUT_SCREEN_HEIGHT);
	int w=window_w;
	int h=window_h;
	int windowWidth = w * 2 / 3;
	int windowHeight = h * 2 / 3;
	box_len=100;

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

	glutCreateWindow("3D-GAME");  // Setup the window
	initRendering();
	 scale_text = computeScale(STRS);
	// Register callbacks
	//glutPassiveMotionFunc( My_mouse_routine );
	glutPassiveMotionFunc(GetOGLPos);
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	//glutIgnoreKeyRepeat(GLUT_KEY_REPEAT_ON);
	glutKeyboardFunc(handleKeypress1);
	glutSpecialFunc(handleKeypress2);
	glutSpecialUpFunc(handlekeyrelease);
	glutMouseFunc(handleMouseclick);
	glutReshapeFunc(handleResize);
	glutFullScreen();
	glutTimerFunc(10, update, 0);

	glutMainLoop();
	return 0;
}

// Function to draw objects on the screen
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	// Draw Box
	glTranslatef(0.0f, 0.0f, -5.0f);
		//Add ambient light
		GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

		//Add positioned light
		GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
		GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

		//Add directed light
		GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
		//Coming from the direction (-1, 0.5, 0.5)
		GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	if(over>0){	
	if(over==1){
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -8.0f);
		glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(-angle_text, 0.0f, 1.0f, 0.0f);

		//Draw the strings along the sides of a square
		glScalef(scale_text, scale_text, scale_text);
		glColor3f(0.3f, 1.0f, 0.3f);
		for(int i = 0; i < 4; i++) {
			glPushMatrix();
			glRotatef(90 * i, 0, 1, 0);
			glTranslatef(0, 0, 1.5f / scale_text);
			t3dDraw3D(STRS[i], 0, 0, 0.2f);
			glPopMatrix();
		}
		glPopMatrix();
	}
	if(over==2){
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -8.0f);
		glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(-angle_text, 0.0f, 1.0f, 0.0f);

		//Draw the strings along the sides of a square
		glScalef(scale_text, scale_text, scale_text);
		glColor3f(0.3f, 1.0f, 0.3f);
		for(int i = 0; i < 4; i++) {
			glPushMatrix();
			glRotatef(90 * i, 0, 1, 0);
			glTranslatef(0, 0, 1.5f / scale_text);
			t3dDraw3D(STRS1[i], 0, 0, 0.2f);
			glPopMatrix();
		}
			glPopMatrix();
	}
	if(over==3){
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -8.0f);
		glRotatef(20.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(-angle_text, 0.0f, 1.0f, 0.0f);

		//Draw the strings along the sides of a square
		glScalef(scale_text, scale_text, scale_text);
		glColor3f(0.3f, 1.0f, 0.3f);
		for(int i = 0; i < 4; i++) {
			glPushMatrix();
			glRotatef(90 * i, 0, 1, 0);
			glTranslatef(0, 0, 1.5f / scale_text);
			t3dDraw3D(STRS2[i], 0, 0, 0.2f);
			glPopMatrix();
		}
			glPopMatrix();
	}
	}
	else{
		//glPushMatrix();
		//glTranslatef(curr_x,curr_y,curr_z);
		//glPopMatrix();

		if(count_f%2!=0){
			float a=eyes_x-peyes_x;
			float b=eyes_y-peyes_y;
			float c=eyes_z-peyes_z;
			//gluLookAt(eyes_x,eyes_y,eyes_z,a/sqrt(a*a+b*b+c*c)*100,b/sqrt(a*a+b*b+c*c)*100,c/sqrt(a*a+b*b+c*c)*100,0,peyes_z,-peyes_y);
			if(curr_dir=='l')
				gluLookAt(curr_x-4,curr_y+10,curr_z,curr_x-4-50*sin(DEG2RAD(angleto)),10,curr_z-50*cos(DEG2RAD(angleto)),0,1,0);
			if(curr_dir=='r')
				gluLookAt(curr_x+4,curr_y+10,curr_z,curr_x+4-50*sin(DEG2RAD(angleto)),10,curr_z-50*cos(DEG2RAD(angleto)),0,1,0);
			if(curr_dir=='b')
				gluLookAt(curr_x,curr_y+10,curr_z+4,curr_x-50*sin(DEG2RAD(angleto)),10,curr_z+4-50*cos(DEG2RAD(angleto)),0,1,0);
			if(curr_dir=='f')
				gluLookAt(curr_x,curr_y+10,curr_z-4,curr_x-50*sin(DEG2RAD(angleto)),10,curr_z-4-50*cos(DEG2RAD(angleto)),0,1,0);
			/*if(curr_dir=='l')
			  gluLookAt(curr_x,curr_y,curr_z,-10,30,curr_z,0,1,0);
			  if(curr_dir=='r')
			  gluLookAt(curr_x,curr_y,curr_z,10,30,curr_z,0,1,0);
			  if(curr_dir=='b')
			  gluLookAt(curr_x,curr_y,curr_z,curr_x,30,10,0,1,0);
			  if(curr_dir=='f')
			  gluLookAt(curr_x,curr_y,curr_z,curr_x,30,-10,0,1,0);*/
		}
		else{
			if(count_c%2!=0){
				if(curr_dir=='l')
					gluLookAt(curr_x+10,curr_y+10,curr_z+4,curr_x-50*sin(DEG2RAD(angleto)),10,curr_z-50*cos(DEG2RAD(angleto)),0,1,0);
				if(curr_dir=='r')
					gluLookAt(curr_x-10,curr_y+10,curr_z-4,curr_x-50*sin(DEG2RAD(angleto)),10,curr_z-50*cos(DEG2RAD(angleto)),0,1,0);
				if(curr_dir=='b')
					gluLookAt(curr_x+4,curr_y+10,curr_z-10,curr_x-50*sin(DEG2RAD(angleto)),10,curr_z-50*cos(DEG2RAD(angleto)),0,1,0);
				if(curr_dir=='f')
					gluLookAt(curr_x-4,curr_y+10,curr_z+10,curr_x-50*sin(DEG2RAD(angleto)),10,curr_z-50*cos(DEG2RAD(angleto)),0,1,0);
			}

			else{	    
				if(count_t%2!=0){
					//gluLookAt(box_len/2*sin(DEG2RAD(_angle)),box_len/2,(box_len/2+100)*cos(DEG2RAD(_angle)),0,0,0,0,1,-0.5);
					gluLookAt(box_len/2,box_len/2,box_len/2+20,0,0,0,0,1,0);
					glRotatef(_angle, 0, 1, 0);
				}
				else{
					if(count_e==1){
						int x=tiles_po[select_tile].first;
						int z=tiles_po[select_tile].second;
						gluLookAt(x*dis*1.0-45,blocks[x][z].y,45-z*dis*1.0,x*dis*1.0-45+90*cos(DEG2RAD(_angle_tile)),blocks[x][z].y,90*sin(DEG2RAD(_angle_tile))+45-z*dis*1.0,0,1,0);
					}
					else{
						if(count_h==1){
							gluLookAt(curr_tower_x,curr_tower_y,curr_tower_z,mouse_x,mouse_y,mouse_z,0,1,0);
						}
						else	
							gluLookAt(0,box_len/2,box_len,0,0,0,0,1,0);
					}
				}
			}
		}
		// gluLookAt(0,100,0,0,0,0,0,1,-0.5);

		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId2);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(0,1,0);
		glBegin(GL_QUADS);
		glColor3f(1,1,1);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-window_w/2,0 ,window_h/2);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-window_w/2,0 ,-window_h/2);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(window_w/2,0 ,-window_h/2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(window_w/2,0 ,window_h/2);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId6);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(0,0,1);
		glBegin(GL_QUADS);
		glColor3f(1,1,1);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-window_w/2,window_h/2,-100);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-window_w/2,-0,-100);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(window_w/2,-0,-100);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(window_w/2,window_h/2,-100);
		glEnd();
		glDisable(GL_TEXTURE_2D);*/
		float i,j;
		int m=0,n=0;
		dis=box_len/10;
		int count_x=0;
		int total=0;
		int flag=0;
		//float po_x;
		//float po_z;
		if(curr_x>=0)po_x=((int)(curr_x/10))*1;
		else po_x=((int)(curr_x/10-1))*1;
		if(curr_z>=0)po_z=((int)(curr_z/10+1))*1;
		else po_z=((int)(curr_z/10))*1;
		if(po_x<-5 || po_x >4 || po_z<-4 || po_z>5){over=1;
		cout<<"Your Points "<<points<<"\n";
		cout<<"You Lose\nBe careful on edges\n";}
		if(po_x==4 && po_z == -4){
		over=2;
		cout<<"Your Points "<<points<<"\n";
		cout<<"You Win\n";}
		for(int i=0;i<coins.size();i++){
		glPushMatrix();
		glTranslatef(-45+10*coins[i].first,22,45-10*coins[i].second);
		glColor3f(1,1,1);
		//drawBall(1.0f);
		//glutSolidSphere(1.0f, 20 ,20);
		glRotatef(-angle_diamond, 0.0f, 1.0f, 0.0f);
		drawDiamond();
		glPopMatrix();
		}
		for( i=-box_len/2;i<box_len/2;i+=dis){
			int count_y=0;
			m=count_x;
			for(j=box_len/2;j>-box_len/2;j-=dis){
				n=count_y;
				// if(total%2==0)glColor3f(1.0f,0.5f,0.0f);
				// else glColor3f(0,0,1);
				int tile=0;
				if(count_j==0 && (int)(po_x)==(int)(i/10) && (int)(po_z)==(int)(j/10)){tile=1;/*cout<<"po_x "<<po_x<<"po_z "<<po_z<<"i "<<i<<"j "<<j<<"\n";*/
				}
				//cout<<"curr_x "<<(int)curr_x<<"curr_z "<<(int)curr_z<<"\n";
				vector< pair<int,int> >::iterator it=find(all(coins),mp((int)(po_x+5),(int)(fabs(po_z-5))));
				if(it!=coins.end()){coins.erase(it);points++;}
				// else cout<<"no\n";
				//cout<<po_x<<" "<<po_z<<"\n";
				//cout<<(int)(curr_x/10)<<" "<<(int)(curr_z/10)<<"\n";
				// cout<<(int)(curr_x)*10<<" "<<(int)(curr_z)*10<<"\n";
				//if(count_y==pits[count_x] && count_x!=0 && count_x!=9)
				if(pits[m][n]!=1 || (m==9 && n==9))
				{
					if((pits[m][n]==4 && tile==1 && (int)prev_x==(int)po_x && (int)prev_z==(int)po_z && timer==40)||(blocks[count_x][count_y].flag==1)){
						blocks[count_x][count_y].y=12;
						blocks[count_x][count_y].flag=1;
						curr_y=12;
						drawCube(i,0,j,dis,tile);
						over=3;
						cout<<"Your Points "<<points<<"\n";
						cout<<"These tiles are slippery\nGame Over\n";
						//exit(0);
						//cout<<"hi";
					}
					else{ 
						if(pits[m][n]==5){
							blocks[count_x][count_y].y=27;
							if(tile==1)
							drawCube(i,15,j,dis,tile);
							else
							drawCube(i,15,j,dis,pits[m][n]+10);
							}
						else{
							blocks[count_x][count_y].y=22;
							if(tile==1)
							drawCube(i,10,j,dis,1);
							else
							drawCube(i,10,j,dis,pits[m][n]+10);
						}
					}

				}

				else{
					/*	    if(flag==0){
						    drawCube(i,block_height,j,dis,tile);
						    blocks[count_x][count_y].y=12+block_height;
						    }
						    if(flag==1)
						    {drawCube(i+block_width,20,j,dis,tile);
						    blocks[count_x][count_y].y=32;
						    }
						    if(flag==2)
						    {drawCube(i,20,j+block_length,dis,tile);
						    blocks[count_x][count_y].y=32;}*/
					if(tile==1)	    
					drawCube(i,block_height,j,dis,tile);
					else
					drawCube(i,block_height,j,dis,pits[m][n]+10);
					blocks[count_x][count_y].y=12+block_height;

				}
				blocks[count_x][count_y].x=i;
				blocks[count_x][count_y].z=j;

				count_y++;
				total++;
				//	m++;	
			}
			flag++;
			flag%=3;
			total++;
			count_x++;
			//  n++;
		}

		glPopMatrix();
		glPushMatrix();
		//glRotatef(180.0f,0,1,0);
		/*if(count_j==0){
		  float X=abs((int)(po_x)+5);
		  float Y=abs((int)(po_x)-5);
		  if(curr_dir=='l')
		  if(curr_y>=blocks[abs((int)(po_x)+5)][abs((int)(po_z)-5)].y || curr_y<22){go=1;
		  curr_y=blocks[abs((int)(po_x)+5)][abs((int)(po_z)-5)].y;}
		  else{
		  curr_y=blocks[abs((int)(po_x)+5)][abs((int)(po_z)-5)].y;
		  go=1;}
		  }*/
		if(count_j==0){
			curr_y=blocks[abs((int)(po_x)+5)][abs((int)(po_z)-5)].y;
			if(pits[abs((int)(po_x)+5)][abs((int)(po_z)-5)]==3){
				if(po_x>=-4 && po_z<4){curr_x-=10.0;curr_z+=10.0;}
			}
			if(pits[abs((int)(po_x)+5)][abs((int)(po_z)-5)]==4){
				if(prev_x==po_x && prev_z==po_z && timer<40 && curr_y>=22)timer++;
				else timer=0;
			}
			prev_x=po_x;
			prev_z=po_z;
		}
		showText();
		glPushMatrix();
		glTranslatef(45.0f, 10 ,-45.0f);
		drawFlag(20);
		glPopMatrix();
		robot.DrawRobot(curr_x,curr_y,curr_z);
		glPopMatrix();
	}
		glPopMatrix();
		glutSwapBuffers();
}
// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update(int value) {
	//float ini_u=sqrt(2*dis);
	//float period=(2*ini_u)*10/(10*sqrt(2));
	//float inc_x=2*dis/(period*10);
	//float inc_x=2*dis/(period);
	//float height=(ini_u*ini_u)/(40*2);
	//float height=(ini_u*ini_u)/(40);
	//float inc_y=2*height/(period*5);
	//float inc_y=2*height/(period);
	//float travel=(ini_u*ini_u)/10;
	if(over>0){
		angle_text += 1.5f;
		if (angle_text > 360) {
			angle_text -= 360;
		}
		glutPostRedisplay();
	}

		angle_diamond += 1.5f;
		if (angle_diamond > 360) {
			angle_diamond -= 360;
		}
	int X=abs((int)(po_x)+5);
	int Z=abs((int)(po_z)-5);
	/*if(up==1){
	  velocity+=0.1;
	  }
	  else{
	  if(down==1){
	  velocity-=0.1;
	  }
	  }*/
	if(up==0 && down==0){
		//cout<<"hi\n";
		if(velocity>0){velocity-=0.2;status=1;
			inertia=1;
			if(velocity<0)velocity=0;	
		}
		else{
			if(velocity<0){velocity+=0.2;status=1;
				inertia=1;
				if(velocity>0)velocity=0;	
			}
		}

		if(curr_dir=='l'){
			if(X>0){
			if(blocks[X-1][Z].y>curr_y)go=0;
			else go=1;}
			else go=1;
		}
		if(curr_dir=='r'){
			if(X<9){
			if(blocks[X+1][Z].y>curr_y)go=0;
			else go=1;}
			else go=1;
		}
		if(curr_dir=='f'){
		if(Z<9){
			if(blocks[X][Z+1].y>curr_y)go=0;
			else go=1;}
			else go=1;
		}
		if(curr_dir=='b'){
		if(Z>0){
			if(blocks[X][Z-1].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(go==1){
			if(velocity>0){
				if(curr_dir=='l'){curr_x-=velocity;}
				if(curr_dir=='r'){curr_x+=velocity;}
				if(curr_dir=='f'){curr_z-=velocity;}
				if(curr_dir=='b'){curr_z+=velocity;}
			}
		}
	}
	else inertia=0;
	//cout<<velocity<<"\n";
	float travel=2*10;
	float inc_x=0.5;
	float inc_y=1*5/(10/0.5);
	float height=initial_height+5-22;
	/*cout<<"dis"<<dis<<"\n";
	  cout<<"ini_u"<<ini_u<<"\n";
	  cout<<"period"<<period<<"\n";
	  cout<<"inc_x"<<inc_x<<"\n";
	  cout<<"inc_y"<<inc_y<<"\n";
	  cout<<"height"<<height<<"\n";
	  cout<<"travel"<<travel<<"\n";
	  cout<<"ini_x"<<ini_x<<"\n";
	  cout<<"ini_y"<<ini_y<<"\n";*/
	if(count_t%2!=0){
		_angle += 1.0f;
		if (_angle > 360) {
			_angle -= 360;
		}
	}
	if(count_e%2!=0){
		_angle_tile +=1.0f;
		_angle_tile=fmod(_angle_tile,360);
	}
	if(count_j==1){
		if(rev==0){	
			if(curr_dir=='l')curr_x-=inc_x;
			if(curr_dir=='r')curr_x+=inc_x;
			if(curr_dir=='f')curr_z-=inc_x;
			if(curr_dir=='b')curr_z+=inc_x;
		}
		else
		{if(rev_yes==1){	
				       if(curr_dir=='l')curr_x+=inc_x;
				       if(curr_dir=='r')curr_x-=inc_x;
				       if(curr_dir=='f')curr_z+=inc_x;
				       if(curr_dir=='b')curr_z-=inc_x;
			       }
		}
		//curr_y+=inc_y;
		curr_y=initial_height+(ini_x-(ini_x*ini_x)/(2*dis));
		ini_x+=inc_x;
		ini_y+=inc_y;
		if(ini_y>=height){ini_y=height;
			inc_y*=-1.0;
		}
		//	if(ini_x>=travel && curr_y<=22){count_j=0;curr_y=22;ini_x=ini_y=0;}
		if(curr_y<22){
			if(rev_yes==1){rev++;rev%=2;}
			if(rev==0){count_j=0;rev_yes=0;}
			curr_y=22;ini_x=ini_y=0;}
	}

	static float minus_h;
	if(block_height>=20.0)minus_h=-1;
	if(block_height<=0.0)minus_h=1;
	block_height+=0.5*minus_h;
	static float minus_l;
	if(block_length>=10.0)minus_l=-1;
	if(block_length<=0.0)minus_l=1;
	block_length+=0.5*minus_l;
	static float minus_w;
	if(block_width>=10.0)minus_w=-1;
	if(block_width<=0.0)minus_w=1;
	block_width+=0.5*minus_w;
	//cout<<block_height<<"\n";	
	robot.Prepare(0.2);
	status=0;
	//if(inertia==1 && count_j==0)
	glutTimerFunc(10, update, 0);
	/*  else 
	    {inertia=0;
	    glutTimerFunc(10, update, 0);
	    }*/
}

//cout<<"dis"<<"\n";
void drawBox(float x,float z,float dis) {
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(x,0.0f,z);
	glVertex3f(x,0.0f,z-dis);
	glVertex3f(x+dis,0.0f,z-dis);
	glVertex3f(x+dis,0.0f,z);
	glEnd();
}

void drawCube(float x,float y,float z,float dis,int tile){
	if(1){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
	//face in xy plane
	glColor3f(1,1,1);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x,0 ,z-dis );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+dis, 0, z-dis);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+dis, y, z-dis);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y, z-dis);
	glEnd();
	glBegin(GL_QUADS);
	//face in yz plane
	glColor3f(1,1,1);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, 0, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, 0, z-dis);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x, y, z-dis);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x, y, z);
	glEnd();
	glBegin(GL_QUADS);
	//|| to xy plane.
	glColor3f(1,1,1);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x, 0, z);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+dis, y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+dis, 0, z);
	glEnd();
	glBegin(GL_QUADS);
	//|| to yz plane
	glColor3f(1,1,1);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(x+dis,0 ,z );
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(x+dis, 0, z-dis);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(x+dis, y, z-dis);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(x+dis, y, z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, NULL);
	}
	//face in zx plance
	if(tile==1){
		glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(x,0.0f,z);
		glColor3f(1,0,0);
		glVertex3f(x,0.0f,z-dis);
		glColor3f(1,0,0);
		glVertex3f(x+dis,0.0f,z-dis);
		glColor3f(1,0,0);
		glVertex3f(x+dis,0.0f,z);
		glEnd();
	}
	else{
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, NULL);
		glEnable(GL_TEXTURE_2D);
		if(tile==12)glBindTexture(GL_TEXTURE_2D, _textureId3);
		if(tile==13)glBindTexture(GL_TEXTURE_2D, _textureId4);
		if(tile==14)glBindTexture(GL_TEXTURE_2D, _textureId5);
		if(tile<12 || tile>14)glBindTexture(GL_TEXTURE_2D, _textureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glColor3f(1,1,1);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x,0.0f,z);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x,0.0f,z-dis);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x+dis,0.0f,z-dis);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x+dis,0.0f,z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	//|| to zx plane
	if(tile==1){
		glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(x,y,z);
		glColor3f(1,0,0);
		glVertex3f(x,y,z-dis);
		glColor3f(1,0,0);
		glVertex3f(x+dis,y,z-dis);
		glColor3f(1,0,0);
		glVertex3f(x+dis,y,z);
		glEnd();
	}
	else{
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, NULL);
		glEnable(GL_TEXTURE_2D);
		if(tile==12)glBindTexture(GL_TEXTURE_2D, _textureId3);
		if(tile==13)glBindTexture(GL_TEXTURE_2D, _textureId4);
		if(tile==14)glBindTexture(GL_TEXTURE_2D, _textureId5);
		if(tile<12 || tile>14)glBindTexture(GL_TEXTURE_2D, _textureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBegin(GL_QUADS);
		glColor3f(1,1,1);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(x,y,z-dis);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(x+dis,y,z-dis);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x+dis,y,z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	glFlush();
}
// Initializing some openGL 3D rendering options
void initRendering() {

	glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
	glEnable(GL_DEPTH);
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // Setting a background color
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	glShadeModel(GL_SMOOTH); //Enable smooth shading
	t3dInit();
	Image* image = loadBMP("grass.bmp");
	_textureId = loadTexture(image);
	image = loadBMP("8.bmp");
	_textureId1 = loadTexture(image);
	image = loadBMP("sea2.bmp");
	_textureId2 = loadTexture(image);
	image = loadBMP("startend.bmp");
	_textureId3 = loadTexture(image);
	image = loadBMP("rsz_7.bmp");
	_textureId4 = loadTexture(image);
	image = loadBMP("sea2.bmp");
	_textureId5 = loadTexture(image);
	delete image;	
	glClearColor(0.196078,  0.6,0.80,1.0);
}

// Function called when the window is resized
void handleResize(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) {

	if (key == 27) {
	cleanup();
		exit(0);     // escape key is pressed
	}
	if(key=='m'){
	//sound("Stage 1_ Contra Music - YouTube.raw");
	sound("temp1.raw");
	}
	if(over==2 && key=='y'){system("./main");exit(0);}
	int X=abs((int)(po_x)+5);
	int Z=abs((int)(po_z)-5);
	if(key=='c'){count_c++;if(count_c==1)count_f=0;}
	if(key=='f'){count_f++;if(count_f==1)count_c=0;}
	if(key=='j'){count_j=1;initial_height=curr_y;
		if(curr_dir=='l' && X>1){
			if(pits[X-2][Z]==2)rev_yes=1;
			else rev_yes=0;
		}
		if(curr_dir=='r' && X<8){
			if(pits[X+2][Z]==2)rev_yes=1;
			else rev_yes=0;
		}
		if(curr_dir=='f' && Z<8){
			if(pits[X][Z+2]==2)rev_yes=1;
			else rev_yes=0;
		}
		if(curr_dir=='b' && Z>1){
			if(pits[X][Z-2]==2)rev_yes=1;
			else rev_yes=0;
		}
	}
	if(key=='t'){count_t+=1;}
	if(key=='s'){select_tile++;select_tile%=moving_tiles;_angle_tile=315.0f;}
	if(key=='e'){count_e++;count_e%=2;}
	if(key=='h'){count_h++;count_h%=2;}
}

void handlekeyrelease(int key, int x , int y){
	if(key==GLUT_KEY_UP)up=0;
	if(key==GLUT_KEY_DOWN)down=0;
	//cout<<"bye\n";
}
void handleKeypress2(int key,int x,int z) {
	//int index=position;
	status=1;
	int X=abs((int)(po_x)+5);
	int Z=abs((int)(po_z)-5);
	if (key == GLUT_KEY_LEFT){
		if(curr_dir=='f'){angleto=90.0;curr_dir='l';}
		else{
			if(curr_dir=='l'){angleto=180.0;curr_dir='b';}
			else{
				if(curr_dir=='r'){angleto=0.0;curr_dir='f';}
				else{
					if(curr_dir=='b'){angleto=-90.0;curr_dir='r';}
				}
			}
		}
		go=1;
	}
	if (key == GLUT_KEY_RIGHT){
		if(curr_dir=='f'){angleto=-90.0;curr_dir='r';}
		else{
			if(curr_dir=='l'){angleto=0.0;curr_dir='f';}
			else{
				if(curr_dir=='r'){angleto=180.0;curr_dir='b';}
				else{
					if(curr_dir=='b'){angleto=90.0;curr_dir='l';}

				}
			}
		}
		go=1;
	}

	if (key == GLUT_KEY_UP){
		if(curr_dir=='l'){
			if(X>0){
			if(blocks[X-1][Z].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(curr_dir=='r'){
		if(X<9){
			if(blocks[X+1][Z].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(curr_dir=='f' ){
			if(Z<9){
			if(blocks[X][Z+1].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(curr_dir=='b'){
			if(Z>0){
			if(blocks[X][Z-1].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(go==1){
			up=1;
			velocity+=0.1;
			if(velocity>0){
				if(curr_dir=='l'){curr_x-=velocity;pcurr_x-=0.5;}
				if(curr_dir=='r'){curr_x+=velocity;pcurr_x+=0.5;}
				if(curr_dir=='f'){curr_z-=velocity;pcurr_z-=0.5;}
				if(curr_dir=='b'){curr_z+=velocity;pcurr_z+=0.5;}
			}
		}
		//	else up=0;
	}
	if (key == GLUT_KEY_DOWN){
		if(curr_dir=='r'){
			if(X>0){
			if(blocks[X-1][Z].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(curr_dir=='l'){
		if(X<9){
			if(blocks[X+1][Z].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(curr_dir=='b'){
		if(Z<9){
			if(blocks[X][Z+1].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(curr_dir=='f' ){
		if(Z>0){
			if(blocks[X][Z-1].y>curr_y)go=0;
			else go=1;
			}
			else go=1;
		}
		if(go==1){
			down=1;
			velocity-=0.1;
			if(velocity<0){	
				if(curr_dir=='l'){curr_x-=velocity;pcurr_x+=0.5;}
				if(curr_dir=='r'){curr_x+=velocity;pcurr_x-=0.5;}
				if(curr_dir=='f'){curr_z-=velocity;pcurr_z+=0.5;}
				if(curr_dir=='b'){curr_z+=velocity;pcurr_z-=0.5;}
			}
		}
	}
	//			else down=0;
	//cout<<curr_x<<" "<<curr_y<<" "<<curr_z<<"\n";
	/*cout<<curr_dir<<"\n";*/
	eyes_x=curr_x+1;
	eyes_y=curr_y+0.25;
	eyes_z=curr_z+1;
	peyes_x=pcurr_x+1;
	peyes_y=pcurr_y+0.25;
	peyes_z=pcurr_z+1;
}

void handleMouseclick(int button, int state, int x, int y) {

	float max=sqrt((mouse_x-tower_x)*(mouse_x-tower_x)+(mouse_y-tower_y)*(mouse_y-tower_y)+(mouse_z-tower_z)*(mouse_z-tower_z));
	float unit_x=(mouse_x-tower_x)/max;
	float unit_y=(mouse_y-tower_y)/max;
	float unit_z=(mouse_z-tower_z)/max;
	if(button==3){
		if(magnitude<max);
		magnitude++;
		curr_tower_x=tower_x+magnitude*(unit_x);
		curr_tower_y=tower_y+magnitude*(unit_y);
		curr_tower_z=tower_z+magnitude*(unit_z);
	}          
	if(button==4){
		if(magnitude>0)magnitude--;
		if(magnitude>0){	 
			curr_tower_x-=1*(unit_x);
			curr_tower_y-=1*(unit_y);
			curr_tower_z-=1*(unit_z);
		}
	}
}
