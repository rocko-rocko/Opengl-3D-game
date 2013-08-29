#include <GL/glut.h>
#include<iostream>
#include "Robot.h"
#include<stdio.h>
using namespace std;


char curr_dir='f';
float angleto=0.0;
int up=0;
int down=0;
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
float curr_x=0;
float curr_y=0;
float curr_z=0;
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
		glColor3f(1.0f, 0.0f, 0.0f);	// red
		glTranslatef(xPos, yPos, zPos);
		glScalef(1.0f, 4.0f, 1.0f);		// arm is a 1x4x1 cube
		DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Robot::DrawHead(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);	// white
		glTranslatef(xPos, yPos, zPos);
		glScalef(2.0f, 2.0f, 2.0f);		// head is a 2x2x2 cube
		DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Robot::DrawTorso(float xPos, float yPos, float zPos){

	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);	// blue
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
		glColor3f(1.0f, 1.0f, 0.0f);	// yellow
		DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

void Robot::DrawFoot(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
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
void drawScene()
{	up=down=0;
	cout<<curr_x<<" "<<curr_y<<" "<<curr_z<<"\n";
	cout<<"dir: "<<curr_dir<<"\n";
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -50.0f);
	glRotatef(180.0f,0,1,0);
	robot.DrawRobot(curr_x,curr_y,curr_z);
	glPopMatrix();
	glutSwapBuffers();

}
void update(int value){
	robot.Prepare(0.05);
	glutTimerFunc(10, update, 0);
}
void handleKeypress2(int key,int x,int z);
int main(int argc, char **argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	int windowWidth = w * 2 / 3;
	int windowHeight = h * 2 / 3;

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

	glutCreateWindow("CSE251_sampleCode");  // Setup the window
	initRendering();

	// Register callbacks
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	//glutKeyboardFunc(handleKeypress1);
	glutSpecialFunc(handleKeypress2);
	//glutMouseFunc(handleMouseclick);
	glutReshapeFunc(handleResize);
	glutTimerFunc(10, update, 0);

	glutMainLoop();

	//	robot.DrawArm();
	return 0;
}
void initRendering() {

	glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // Setting a background color
}

// Function called when the window is resized
void handleResize(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	gluPerspective(45.0f, 1.14, 0.1f, 800.0f);
	gluPerspective(45.0f, (float)w/(float)h, 0.1f,200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void handleKeypress2(int key,int x,int z) {
	//int index=position;
				if (key == GLUT_KEY_LEFT){
					if(curr_dir=='f'){cout<<"here\n";angleto=90.0;curr_dir='l';}
					else{
					if(curr_dir=='l'){angleto=180.0;curr_dir='b';}
					else{
					if(curr_dir=='r'){angleto=0.0;curr_dir='f';}
					else{
					if(curr_dir=='b'){angleto=-90.0;curr_dir='r';}
							}
					}
					}
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
				}
				if (key == GLUT_KEY_UP){
		if(curr_dir=='l')curr_x-=0.1;
		if(curr_dir=='r')curr_x+=0.1;
		if(curr_dir=='f')curr_z-=0.1;
		if(curr_dir=='b')curr_z+=0.1;
				}
				if (key == GLUT_KEY_DOWN){down=1;
		if(curr_dir=='l')curr_x+=0.1;
		if(curr_dir=='r')curr_x-=0.1;
		if(curr_dir=='f')curr_z+=0.1;
		if(curr_dir=='b')curr_z-=0.1;
				}
}
