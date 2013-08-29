#include <iostream>
#include <stdlib.h> 
#include <GL/glut.h>
#include<stdio.h>
#include<time.h>
#include<cmath>
#define PI 3.14159
#define DEG2RAD 3.14159/180
#include "imageloader.h"
using namespace std;

//variables ,functions, and structures intiallization
typedef struct
{
	float x,y,z;
}point;
typedef struct
{
	float x,y,z,rot;
}pointx;
typedef struct
{
	float x,y,z,rot;
	int c,r;
}pointf;
typedef struct
{
	point a,b,c,d;
}square;
typedef struct
{
	point a,b,c,d,e,f;
}block;
point roboc,tower,heli;
pointf coin[12];
pointx robocx[10],bullet;
point mousePos;	
square tiles[100];
float vincx=0.0,vincy=0.0,hincx=6.0,hincy=0.0,theta=0.0f;
int coun=0,i=0,ju=0,teler=0,wa=0,tow=0,tv=0,count1=0,cam=0,tcam=0,c=0,f=0,r=0,robottile=0,tsel=41,u=rand()%99+1,tele=rand()%99+1,cx=683,cy=384;
float _angle = 30.0f,alpha=1.0,yaw=0.0,pitch=0.0,roboha=0.0f,robola=0.0f,trans[100],transl=0.0f,roboca=0.0f,sp=-0.15,fla=0;
float robola1=0.0f,roboha1=0.0f,jum=0.0,_cameraAngle = 0.0f,z=-5.0f,b=0.0f,x=-1.0f,roboh=-1.30,d=0.0,dx=0.0,dy=0.0,vx=1.0,vz=1.0,oh=0.4;
float mouse_x=0.0,mouse_y=0.0,mouse_z=0.0;
char text_s[40],text1_s[40];
int font=(int)GLUT_BITMAP_8_BY_13,bullets=10,lives=3;
int fire=0,fired=0,gun[10],coins=0,flag[100],he=0,cf=0,wia,hia,flag1=0,tf=0,prevkey,clear[100],obs[100],teleport[100];
void handleMouseclick(int button, int state, int x, int y);
void drawtiles();
void move(float x);
void handlekeypress2(int key, int x, int y);
void createsquares(point a, point b,point c,point d,float z);
void createblock(point a,point b,float z,float z1,float r,int y);
void createblock1(point a,point b,float z,float z1);
void drawhand(float z,int i,float y, float u);
void update3(int x);
void update4(int x);
void update6(int x);
int check(float x,float z);
void checkxy();
void checkx(float x,float z);
void update(int va);
void update1(int x);
void update2(int x);
void drawCylinder(float h);   
void drawFlag(float h);
void drawTriangle_f(float h);
void resetPerspectiveProjection();
void setOrthographicProjection();
void renderBitmapString(float x, float y, void *font,char *st);
void showText(void);
void drawrobotx(pointx x,float t);
void jumpy();
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
		glTexImage2D(GL_TEXTURE_2D,  0,GL_RGB,											 				 image->width, image->height,		 0,                            //The border of the image
		GL_RGB,  GL_UNSIGNED_BYTE, image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId6,_textureId5,_textureId,_textureId4,_textureId1,_textureId2,_textureId3; //The id of the texture
void drawTriangle_f(float h) { 

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId6);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glNormal3f(0.0f,0.0f,1.0f);

	glBegin(GL_QUADS);
//	glColor3f(0.2f, 0.3f, 1.0f);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(0, 3*h/4, 0.0f);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(h/4, h*3/4, 0.0f);
	//glColor3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f,1.0f);
//	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(h/4, h, 0.0f);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(0.0f, h, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawFlag(float h){
	glPushMatrix();     
	drawCylinder(h);
	glPopMatrix();

	//glRotatef(90, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	drawTriangle_f(h);
	glPopMatrix();
}
void drawCylinder(float h){
	glColor3f(0.2f,0.1f,0.4f);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadratic,0.1f,0.1f,h,32,32);
}
void showText(void)
{
	sprintf(text_s,"%d",bullets);
	glColor3f(1.0f,1.0f,1.0f);
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	//glColor3f(1.0f,1.0f,1.0f);
	glColor3f((float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX);
	renderBitmapString(650,40,(char *)font,"Level #2");
	glColor3f((float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX);
	renderBitmapString(50,60,(char *)font,"#Bullets: ");
	renderBitmapString(160,60,(void *)font,text_s);
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
	gluOrtho2D(0, wia, 0, hia);
	glScalef(1, -1, 1);
	glTranslatef(0, -hia, 0);
	glMatrixMode(GL_MODELVIEW);
}
void resetPerspectiveProjection()
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

//draw coins 
void draw_coins()
{

	for(int i=0;i<12;i++)
	{
		if(cf==0)
		{
		int u=rand()%99+1;
		while(clear[u]==1)
			u=rand()%99+1;
		coin[i].r=u;
		coin[i].c=0;
		}
		coin[i].x=(tiles[coin[i].r].a.x+tiles[coin[i].r].b.x)/2;
		if(flag[coin[i].r]==1)
			coin[i].y=tiles[coin[i].r].a.y+trans[coin[i].r]+0.3;
		else if(obs[coin[i].r]==1)
			coin[i].y=tiles[coin[i].r].a.y+0.3;
		else
			coin[i].y=tiles[coin[i].r].a.y+0.3;
		coin[i].z=(tiles[coin[i].r].a.z+tiles[coin[i].r].d.z)/2;
	//	}
		if(coin[i].c==0)
		{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId5);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();
	glTranslatef(coin[i].x,coin[i].y,coin[i].z);
	glPushMatrix();
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f,1.0f,1.0f);
	glNormal3f(0.0f,0.0f,1.0f);
	glBegin(GL_TRIANGLES);
//	glColor3f(0.1f,0.2f,0.6f);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(0.0f, 0.3f, 0.0f);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-0.15f, 0.0f, 0.0f);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(0.15f, 0.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
//	glColor3f(0.1f,0.2f,0.6f);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(-0.15f, 0.0f, 0.0f);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(0.15f, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	}
	}

}
void fire_bullets()
{
	int count=0;
	if(fired==0)
	{
			bullet.x=roboc.x;
			bullet.y=roboc.y;
			bullet.z=roboc.z;
			bullet.rot=roboca;
			glPushMatrix();
			glTranslatef(bullet.x,bullet.y,bullet.z);
			glColor3f(0.4,0.2,0.5);
			glutSolidSphere(0.05,40,40);
			glPopMatrix();
			fired=1;
	}
	else
	{
		float g=bullet.rot;
		if(g==0.0||g==360.0||g==-360.0)
		{
			bullet.z+=-0.03f;
			glPushMatrix();
			glTranslatef(bullet.x,bullet.y,bullet.z);
			glColor3f(1.0,0.2,0.5);
			glutSolidSphere(0.05,40,40);
			glPopMatrix();
		}
		if(g==90.0||g==-270.0)
		{
			bullet.x+=0.03f;
			glPushMatrix();
			glTranslatef(bullet.x,bullet.y,bullet.z);
			glColor3f(1.0,0.2,0.5);
			glutSolidSphere(0.05,40,40);
			glPopMatrix();
		}
		if(g==-90.0||g==270.0)
		{
			bullet.x+=-0.03f;
			glPushMatrix();
			glTranslatef(bullet.x,bullet.y,bullet.z);
			glColor3f(1.0,0.2,0.5);
			glutSolidSphere(0.05,40,40);
			glPopMatrix();
		}
		if(g==180.0||g==-180.0)
		{
			bullet.z+=0.03f;
			glPushMatrix();
			glTranslatef(bullet.x,bullet.y,bullet.z);
			glColor3f(1.0,0.2,0.5);
			glutSolidSphere(0.05,20,20);
			glPopMatrix();
		}
		int fl=0;
		for(i=0;i<100;i++)
		{
			if(i%10==0&&i!=0)
				count=(count+1)%2;
			if(count==0&&tiles[i].a.x<=bullet.x&&tiles[i].b.x>=bullet.x&&tiles[i].a.z>=bullet.z&&tiles[i].d.z<=bullet.z)
			{
				fl=1;
				if(flag[i]==1&&tiles[i].a.y+trans[i]>bullet.y)
				{
					fired=0;
					fire=0;
					break;
				}
				if(obs[i]==1&&tiles[i].a.y>bullet.y)
				{	
					fired=0;
					fire=0;
					break;
				}
					
			}
			if(count==1&&tiles[i].a.x>=bullet.x&&tiles[i].b.x<=bullet.x&&tiles[i].a.z<=bullet.z&&tiles[i].d.z>=bullet.z)
			{
				fl=1;
				if(flag[i]==1&&tiles[i].a.y+trans[i]>bullet.y)
				{	
					fired=0;
					fire=0;
					break;
				}
				if(obs[i]==1&&tiles[i].a.y>bullet.y)
				{	
					fired=0;
					fire=0;
					break;
				}
			}		

		}
		if(fl==0)
		{
			fired=0;
			fire=0;
		}

	//}
		
	}
	

}
void drawWater(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glDisable(GL_DEPTH_TEST);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0,1,1,0,-1,1);
	glColor3f(1.0f,1.0f,1.0f);
	glNormal3f(0.0f,0.0f,1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f,1.0f);
	glVertex2f(0,0);
	glTexCoord2f(0.0f,1.0f);
	glVertex2f(1.0,0);
	glTexCoord2f(0.0f,0.0f);
	glVertex2f(1,1);
	glTexCoord2f(1.0f,0.0f);
	glVertex2f(0,1);
	glEnd();
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}

//To jump in y 
void jumpy()
{
	dx+=0.1;
	if(ju!=1)
	{
		r=1;
		dy=((dx)-(10.0/16.0)*(dx*dx));
		coun++;
	}
	else
	{
		r=0;
		vx=1.0;
		vz=1.0;
		dx=0.0;
		dy=0.0;
	}
};
//to handle the key when it is pressed
void keySpecialUp (int key, int x, int y) {
		fla=1;
		if(key==GLUT_KEY_UP)
		{
		if(roboca==0.0||roboca==360.0||roboca==-360.0)
		{	
			vz+=0.1;
		}
		if(roboca==90.0||roboca==-270.0)
		{
			vx+=0.1;		
		}
		if(roboca==-90.0||roboca==270.0)
		{
			vx+=0.1;
		}
		if(roboca==-180.0||roboca==180.0)
		{
			vz+=0.1;
		}
		}
};  
void drawrobot();

//to get the mouse coordinates
void GetOGLPos(int x,int y)
{	
	/*GLint viewport[4];
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
	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);*/
	if(x>cx)
	{
		yaw+=0.5;
		cx=x;
	}
	if(x<cx)
	{
		yaw-=0.5;
		cx=x;
	}
	if(y>cy)
	{
		pitch-=0.5;
		cy=y;
	}
	if(y<cy)
	{
		pitch+=0.5;
		cy=y;
	}
//	printf("%f %f\n",yaw,pitch);
	//mouse_x=x-683;
//	if(y<=384)
//		mouse_y=384
//	mouse_x=x;
//	mouse_y=y;
//	mouse_z=posZ;
	return;
}

//Called when a key is pressed
void handleKeypress(unsigned char key,int x, int y) 
{
	if(key==27){
		exit(0);
	}
	if(key==106)
	{
		r=1;
	}
	if(key==102)
	{
		cam=(cam+1)%2;

	}
	if(key==112)
	{
		tcam=(tcam+1)%2;
	}
	if(key==119)
	{
		tow=(tow+1)%2;
	}
	if(key==116)
	{	
		tv=(tv+1)%2;
	}
	if(key==104)
	{
		he=(he+1)%2;
	}
	if(key==103)
	{
		fire=1;
	}
}
/*void fire_bullets()
{
	if(bullets>0)
	{
		if(roboca==0.0f||roboca==360.0f||roboca==-360.0f)
		{
			glPushMatrix();
			glTranslatef(roboc.x,roboc.y,roboc.z-0.13);

		}


	}
}*/
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH);
	glEnable(GL_COLOR_MATERIAL); // Enable coloring
//	glEnable(GL_LIGHTING); //Enable lighting
//	glEnable(GL_LIGHT0); //Enable light #0
//	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	glShadeModel(GL_SMOOTH); //Enable smooth shading
	//glEnable(GL_LINE_SMOOTH)1;
	Image* image = loadBMP("grass.bmp");
	_textureId = loadTexture(image);
	image = loadBMP("tree.bmp");
	_textureId1=loadTexture(image);
	image = loadBMP("teleport.bmp");
	_textureId2=loadTexture(image);
	image = loadBMP("night.bmp");
	_textureId3=loadTexture(image);
	image = loadBMP("clear.bmp");
	_textureId4=loadTexture(image);
	image = loadBMP("coin.bmp");
	_textureId5=loadTexture(image);
	image = loadBMP("end.bmp");
	_textureId6=loadTexture(image);
	delete image;
//	glClearColor(0.196078, 0.6, 0.80, 1.0f);

}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(60.0,(double)w / (double)h,1.0,200.0);
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

//update function
void update(int value) {
		_angle += 8.0f;
		if (_angle > 360) {
				_angle -= 360;
		}
		for(int i=0;i<100;i++)
		{
		if(trans[i]>=0.6)
			flag1=1;
		if(trans[i]<=-0.6)
			flag1=0;
		if(flag1==0)
		{
			trans[i]+=(0.1/50)*(i+1);
		}
		if(flag1==1)
		{
			trans[i]-=(0.1/50)*(i+1);
		}
		}
	robola1+=8.0;
	if(robola1>26)
		robola1=-26;
	roboha1+=8.0;
	if(roboha1>26)
		roboha1=-26;
	glutPostRedisplay();	
	glutTimerFunc(80, update, 0);
}
void update6(int x)
{

		for(i=0;i<10;i++)
		{
			if(gun[i]!=1&&bullet.x>=robocx[i].x-0.18&&bullet.x<=robocx[i].x+0.18&&bullet.y>=robocx[i].y-0.09&&bullet.y<=robocx[i].y+18&&bullet.z>=robocx[i].z-0.18&&bullet.z<=robocx[i].z+0.18)
			{
				fired=0;
				fire=0;
				gun[i]=1;
				break;
			}
		}
		for(i=0;i<12;i++)
		{
			if(coin[i].c==0&&bullet.x+0.2>=coin[i].x&&bullet.x-0.2<=coin[i].x&&bullet.y+0.2>=coin[i].y&&bullet.y-0.2<=coin[i].y&&bullet.z+0.2>=coin[i].z&&bullet.z-0.2<=coin[i].z)
			{
				bullets++;
				fired=0;
				fire=0;
				coin[i].c=1;
				break;
			}
		}
	for(i=0;i<12;i++)
	{
		if(coin[i].c==0&&roboc.x+0.09>=coin[i].x&&roboc.x-0.09<=coin[i].x&&roboc.y+0.09>=coin[i].y&&roboc.y-0.09<=coin[i].y&&roboc.z+0.09>=coin[i].z&&roboc.z-0.09<=coin[i].z)
		{
				bullets++;
				coin[i].c=1;
				break;
		}
	}

	glutPostRedisplay();	
	glutTimerFunc(200, update6, 0);
}

//second update function
void update1(int va)
{
	if(vx>1.0&&fla==0)
	{
		vx=vx-0.5;
		if(prevkey==GLUT_KEY_UP)
			move(1.0);
	}
	if(vz>1.0&&fla==0)
	{
		vz=vz-0.5;
		if(prevkey==GLUT_KEY_UP)
			move(1.0);
	}
	/*for(int i=0;i<4;i++)
	{
	//	printf("%f %f %f %f %f %f\n",roboc.x,roboc.y,roboc.z,robocx[i].x,robocx[i].y,robocx[i].z);
		if(roboc.x+0.18>=robocx[i].x&&roboc.x-0.18<=robocx[i].x&&roboc.y==robocx[i].y&&roboc.z+0.18>=robocx[i].z&&roboc.z-0.18<=robocx[i].z)
			exit(0);
	}*/
	if(alpha<1.0)
		alpha+=0.1;
	glutPostRedisplay();	
	glutTimerFunc(130, update1, 1);
}

void update4(int x)
{
	int r;
	for(int i=0;i<10;i++)
	{
		if(gun[i]==0)
		{
		r=rand()%4+1;
		if(r==1)
			robocx[i].rot=90.0f;
		if(r==2)
			robocx[i].rot=-90.0f;
		if(r==3)
			robocx[i].rot=0.0f;
		if(r==4)
			robocx[i].rot=180.0f;
		}
	}
	glutPostRedisplay();	
	glutTimerFunc(700, update4, 1);
}
//third update function
void update2(int xa)
{
	//printf("update %d\n",r);
	if(r==1)
	{
		jumpy();
		if(flag[robottile]==1&&coun==1)
			jum=trans[robottile];
		else if(obs[robottile]==1&&coun==1)
			jum=oh;
		else if(flag[robottile]!=1&&obs[robottile]!=1&&coun==1)
			jum=0.0;
		roboc.y=roboh+jum+2*dy;
		move(1.0);
	//	printf("after move %f \n",roboc.y);
	}
	if(r==0)
	{
		dx=0.0;
		dy=0.0;
		coun=0;
		ju=0;
		jum=0.0;
	}

	glutPostRedisplay();	
	glutTimerFunc(30, update2, 1);
}
//random walk
void update3(int r)
{
	for(int i=0;i<10;i++)
	{
		if(gun[i]==0)
		{
	if(robocx[i].rot==0.0||robocx[i].rot==-360.0||robocx[i].rot==360.0)
	{
		robocx[i].z-=0.2;
		if(robocx[i].z<tiles[9].d.z)
		{
			if(robocx[i].rot==360)
				robocx[i].rot=90.0;
			else
				robocx[i].rot+=90.0;
			robocx[i].z+=0.2;
		}
	}
	if(robocx[i].rot==180.0||robocx[i].rot==-180.0)
	{
		robocx[i].z+=0.2;
		if(robocx[i].z>tiles[0].a.z)
		{
			robocx[i].rot+=90.0;
			robocx[i].z-=0.2;
		}
	}
	if(robocx[i].rot==90.0|| robocx[i].rot==-270.0)
	{
		robocx[i].x+=0.2;
		if(robocx[i].x>tiles[92].d.x)
		{
			robocx[i].rot+=90.0;
			robocx[i].x-=0.2;
		}
	}
	if(robocx[i].rot==-90.0|| robocx[i].rot==270.0)
	{
		robocx[i].x-=0.2;
		if(robocx[i].x<tiles[0].a.x)
		{
			robocx[i].rot+=90.0f;
			robocx[i].x+=0.2;
		}
	}
		}
	}
	checkxy();
	glutPostRedisplay();	
	glutTimerFunc(100, update3, 0);
}
//Draws the 3D scene
void drawScene() {
	//Second Intialization
	count1=0;
	z=-4.5f;
	x=-1.2f;
	b=0.0f;
	flag[0]=0;
	vincx=-1.6;vincy=0.0;hincx=9.0;hincy=0.0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawWater();
	showText();
	//printtext(600, 300, "points");
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(cam==1)
	{
		if(roboca==90.0||roboca==-270.0)
			gluLookAt(roboc.x,roboc.y+0.16,roboc.z,roboc.x+0.8,roboc.y+0.16,roboc.z,0,1,0);
		else if(roboca==-90.0||roboca==270.0)
			gluLookAt(roboc.x,roboc.y+0.16,roboc.z,roboc.x-0.8,roboc.y+0.16,roboc.z,0,1,0);
		else if(roboca==0.0||roboca==360.0||roboca==-360.0)
			gluLookAt(roboc.x,roboc.y+0.16,roboc.z,roboc.x,roboc.y+0.16,roboc.z-0.8,0,1,0);
		else
			gluLookAt(roboc.x,roboc.y+0.16,roboc.z,roboc.x,roboc.y+0.16,roboc.z+0.8,0,1,0);
	}
	if(tcam==1)
	{
		if(roboca==90.0||roboca==-270.0)
			gluLookAt(roboc.x-1.4,roboc.y+0.16+0.5,roboc.z,roboc.x,roboc.y+0.16,roboc.z,0,1,0);
		else if(roboca==-90.0||roboca==270.0)
			gluLookAt(roboc.x+1.4,roboc.y+0.16+0.5,roboc.z,roboc.x,roboc.y+0.16,roboc.z,0,1,0);
		else if(roboca==0.0||roboca==360.0||roboca==-360.0)
			gluLookAt(roboc.x,roboc.y+0.16+0.5,roboc.z+1.4,roboc.x,roboc.y+0.16,roboc.z,0,1,0);
		else
			gluLookAt(roboc.x,roboc.y+0.16+0.5,roboc.z-1.4,roboc.x,roboc.y+0.16,roboc.z,0,1,0);
	}
	if(tow==1)
	{
		gluLookAt(tower.x,tower.y,tower.z,tiles[44].a.x,tiles[44].a.y,tiles[44].a.z,0,1,0);
	}
	if(tv==1)
	{
		gluLookAt(tiles[u].a.x,tiles[u].a.y+2.0,tiles[u].a.z,roboc.x,roboc.y,roboc.z,0,1,0);
	}
/*	if(he==1)
	{
		//glTranslatef(heli.x,heli.y,heli.z);
		gluLookAt(heli.x,heli.y,heli.z,-cos((PI/180)*yaw)-cos((PI/180)*(pitch)),-sin((PI/180)*(pitch)),-sin((PI/180)*(yaw)),0,1,0);
	}*/
	//printf("%f %f\n",vx,vz);
	if(fla==0&&(vx<1.0||vz<1.0))
	{
		vx=1.0;
		vz=1.0;
	}
	glPushMatrix();
	
	drawtiles();

	draw_coins();
	checkx(roboc.x,roboc.z);
	if(teleport[robottile]==1)
	{
		roboc.y=tiles[tele].a.y+0.3+flag[tele]*trans[tele];
		roboc.x=(tiles[tele].a.x+tiles[tele].b.x)/2;
		roboc.z=(tiles[tele].a.z+tiles[tele].d.z)/2;
	}
	if(fire==1&&fired==0&&bullets>0)
	{
		fire_bullets();
		bullets-=1;
	}
	if(bullets==0)
	{
		fire=0;
		fired=0;
	}
	if(fired==1)
	{
		fire_bullets();
	}
	for(i=0;i<10;i++)
	{
		if(gun[i]==0&&roboc.x+0.18>=robocx[i].x&&roboc.x-0.18<=robocx[i].x&&roboc.y+0.18>=robocx[i].y&&roboc.y-0.18<=robocx[i].y&&roboc.z+0.18>=robocx[i].z&&roboc.z-0.18<=robocx[i].z)
		{
			exit(0);
		}
	}
	drawrobot();
	checkxy();
	for(int i=0;i<10;i++)
	{
		if(gun[i]==0)
			drawrobotx(robocx[i],robocx[i].rot);
	}
	if(clear[robottile]==1)
	{
		wa++;
		if(wa==10)
		{
			exit(0);
		}
	}
	if(robottile==90)
	{
		printf("Well Done!!!!!!!");
		exit(0);
	}
	glPushMatrix();
	glTranslatef((tiles[90].a.x+tiles[90].b.x)/2,-1.6,(tiles[90].a.z+tiles[90].d.z)/2);
	drawFlag(4.0);
	glPopMatrix();
	glPopMatrix();
	c++;
	cf++;
	glutSwapBuffers();
//	printf("tile %d\n",robottile);
	fla=0;
}

//Drawing the tiles
void drawtiles()
{
	//glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0,1.0f,1.0f);
	glNormal3f(0.0f,0.0f,1.0f);
	glBegin(GL_QUADS);
	/*if(robottile==0)
		glColor3f(1.0f,0.2f,0.1f);
	else
		glColor3f(0.0f,1.0f,0.0f);*/
	transl=flag[0]*trans[0];
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(tiles[0].a.x,tiles[0].a.y, z);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(tiles[0].b.x,tiles[0].b.y, z);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(tiles[0].c.x,tiles[0].c.y, z-1.2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(tiles[0].d.x,tiles[0].d.y, z-1.2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	createblock(tiles[0].a,tiles[0].b,z,z,transl,i);
	createblock(tiles[0].a,tiles[0].d,z,z-1.2,transl,i);
	createblock(tiles[0].d,tiles[0].c,z-1.2,z-1.2,transl,i);
	createblock(tiles[0].b,tiles[0].c,z,z-1.2,transl,i);
	tiles[0].a.z=z;tiles[0].b.z=z;tiles[0].c.z=z-1.2;tiles[0].d.z=z-1.2;
	for(i=1;i<100;i++)
	{
		transl=flag[i]*trans[i];
		//glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		if(teleport[i]==1)
			glBindTexture(GL_TEXTURE_2D, _textureId2);
		else if (clear[i]==1)
			glBindTexture(GL_TEXTURE_2D, _textureId4);
		else
			glBindTexture(GL_TEXTURE_2D, _textureId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0,1.0f,1.0f);
		glNormal3f(0.0f,0.0f,1.0f);
		glBegin(GL_QUADS);
		/*if(i%2==0)
			glColor3f(0.0f,1.0f,0.0f);
		else
			glColor3f(0.0f,0.0f,1.0f);
		if(i==robottile)
			glColor3f(1.0f,0.2f,0.1f);
		if(teleport[i]==1)
			glColor3f(0.5f,0.5f,0.5f);*/
		if(i%10!=0)
		{
			b=z+x;
			tiles[i].a.x=tiles[i-1].d.x;
			tiles[i].a.y=vincx;
			tiles[i].b.x=tiles[i-1].c.x;
			tiles[i].b.y=vincx;
			tiles[i].c.x=tiles[i].b.x;
			tiles[i].c.y=vincx;
			tiles[i].d.x=tiles[i].a.x;
			tiles[i].d.y=vincx;
			if(clear[i]==0&&obs[i]==0)
			{
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(tiles[i].a.x,tiles[i].a.y+transl,b);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(tiles[i].b.x,tiles[i].b.y+transl,b);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(tiles[i].c.x,tiles[i].c.y+transl,b+x);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(tiles[i].d.x,tiles[i].d.y+transl,b+x);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			}
			if(clear[i]==0&&obs[i]==1)
			{
			glTexCoord2f(0.0f, 0.0f);
			tiles[i].a.y=vincx+oh;
			tiles[i].b.y=vincx+oh;
			tiles[i].c.y=vincx+oh;
			tiles[i].d.y=vincx+oh;
			glVertex3f(tiles[i].a.x,tiles[i].a.y,b);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(tiles[i].b.x,tiles[i].b.y,b);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(tiles[i].c.x,tiles[i].c.y,b+x);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(tiles[i].d.x,tiles[i].d.y,b+x);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			//glEnable(GL_TEXTURE_2D);
			}
			if(clear[i]==1)
			{
			glTexCoord2f(0.0f, 0.0f);
			//glColor3f(0.0f,0.0f,0.0f);
			tiles[i].a.y=vincx-0.8;
			tiles[i].b.y=vincx-0.8;
			tiles[i].c.y=vincx-0.8;
			tiles[i].d.y=vincx-0.8;
			glVertex3f(tiles[i].a.x,tiles[i].a.y,b);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(tiles[i].b.x,tiles[i].b.y,b);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(tiles[i].c.x,tiles[i].c.y,b+x);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(tiles[i].d.x,tiles[i].d.y,b+x);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			}
			tiles[i].a.z=b;tiles[i].b.z=b;tiles[i].c.z=b+x;tiles[i].d.z=b+x;
			//if(flag[i]==1)
		//	{
			createblock(tiles[i].a,tiles[i].b,b,b,transl,i);
			createblock(tiles[i].a,tiles[i].d,b,b+x,transl,i);
			createblock(tiles[i].d,tiles[i].c,b+x,b+x,transl,i);
			createblock(tiles[i].b,tiles[i].c,b,b+x,transl,i);
			//}
			z=b;
		}
		else
		{
			
			if(count1%2==0)
			{
			tiles[i].a.x=tiles[i-1].c.x+hincx/10;
			tiles[i].a.y=vincx;
			tiles[i].b.x=tiles[i-1].c.x;
			tiles[i].b.y=vincx;
			tiles[i].c.x=tiles[i-1].b.x;
			tiles[i].c.y=vincx;
			tiles[i].d.x=tiles[i-1].b.x+hincx/10;
			tiles[i].d.y=vincx;
			}
			else
			{
			tiles[i].a.x=tiles[i-1].d.x;
			tiles[i].a.y=vincx;
			tiles[i].b.x=tiles[i-1].d.x+hincx/10;
			tiles[i].b.y=vincx;
			tiles[i].c.x=tiles[i-1].a.x+hincx/10;
			tiles[i].c.y=vincx;
			tiles[i].d.x=tiles[i-1].a.x;
			tiles[i].d.y=vincx;
			}
			if(clear[i]==0&&obs[i]==0)
			{
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(tiles[i].a.x,tiles[i].a.y+transl, z+x);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(tiles[i].b.x,tiles[i].b.y+transl, z+x);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(tiles[i].c.x,tiles[i].c.y+transl, z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(tiles[i].d.x,tiles[i].d.y+transl, z);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			}
			if(clear[i]==0&&obs[i]==1)
			{
			tiles[i].a.y=vincx+oh;
			tiles[i].b.y=vincx+oh;
			tiles[i].c.y=vincx+oh;
			tiles[i].d.y=vincx+oh;
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(tiles[i].a.x,tiles[i].a.y,b);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(tiles[i].b.x,tiles[i].b.y,b);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(tiles[i].c.x,tiles[i].c.y,b+x);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(tiles[i].d.x,tiles[i].d.y,b+x);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			}
			if(clear[i]==1)
			{
		//	glColor3f(0.0f,0.0f,0.0f);
			tiles[i].a.y=vincx-0.8;
			tiles[i].b.y=vincx-0.8;
			tiles[i].c.y=vincx-0.8;
			tiles[i].d.y=vincx-0.8;
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(tiles[i].a.x,tiles[i].a.y, z+x);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(tiles[i].b.x,tiles[i].b.y, z+x);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(tiles[i].c.x,tiles[i].c.y, z);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(tiles[i].d.x,tiles[i].d.y, z);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			}

			tiles[i].a.z=z+x;tiles[i].b.z=z+x;tiles[i].c.z=z;tiles[i].d.z=z;
			//if(flag[i]==1)
			//{
			createblock(tiles[i].a,tiles[i].b,z+x,z+x,transl,i);
			createblock(tiles[i].a,tiles[i].d,z+x,z,transl,i);
			createblock(tiles[i].d,tiles[i].c,z,z,transl,i);
			createblock(tiles[i].b,tiles[i].c,z+x,z,transl,i);
		//	}
			count1++;
			z=z+x;
			x=-1.0*x;
			//sp=-1.0*sp;
		}
	}

}

//Draw Squares
void createsquares(point a, point b,point c,point d,float z)
{
	glBegin(GL_QUADS);
	glVertex3f(a.x,a.y,z);
	glVertex3f(b.x,b.y,z);
	glVertex3f(c.x,c.y,z);
	glVertex3f(d.x,d.y,z);
	glEnd();

}

//Draw hand
void drawhand(float z,int i,float roboha,float robola)
{
	point a,b,c,d,e,f,g,h;
	if(i==0)
	{
	a.x=0.09;a.y=0.0;b.x=0.13;b.y=0.0;
	c.x=0.09;c.y=-0.16;d.x=0.13;d.y=-0.16;
	e.x=-0.09;e.y=0.0;f.x=-0.13;f.y=0.0;
	g.x=-0.09;g.y=-0.16;h.x=-0.13;h.y=-0.16;}
	else
	{
	a.x=0.03;a.y=-0.08;b.x=0.06;b.y=-0.08;
	c.x=0.03;c.y=-0.30;d.x=0.06;d.y=-0.30;
	e.x=-0.03;e.y=-0.08;f.x=-0.06;f.y=-0.08;
	g.x=-0.03;g.y=-0.30;h.x=-0.06;h.y=-0.30;}
	glPushMatrix();
	if(i==0)
		glRotatef(roboha,1.0f,0.0f,0.0f);	
	else
		glRotatef(robola,1.0f,0.0f,0.0f);	
	createsquares(a,b,d,c,-0.02);
	createsquares(a,b,d,c,0.02);
	createblock1(b,d,-0.02,0.02);
	createblock1(a,c,-0.02,0.02);
	createblock1(a,b,-0.02,0.02);
	createblock1(c,d,-0.02,0.02);
	glPopMatrix();
	
	glPushMatrix();
	if(i==0)
		glRotatef(-roboha,1.0f,0.0f,0.0f);	
	else
		glRotatef(-robola,1.0f,0.0f,0.0f);	
	createsquares(e,f,h,g,-0.02);
	createsquares(e,f,h,g,0.02);
	createblock1(e,g,-0.02,0.02);
	createblock1(f,h,-0.02,0.02);
	createblock1(e,f,-0.02,0.02);
	createblock1(g,h,-0.02,0.02);
	glPopMatrix();
}

//Draw Robot
void drawrobot()
{
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(roboc.x,roboc.y,roboc.z);
	glRotatef(-roboca,0.0f,1.0f,0.0f);
	glColor4f(0.71f,0.65f,0.26f,alpha);
	glutSolidCube(0.18);//0.16
	glPushMatrix();
	glColor4f(0.72f,0.45f,0.20f,alpha);
	glTranslatef(0.0f,0.18f,0.0f);
	glutSolidSphere(0.09, 40, 40);//0.08	
	glPopMatrix();
	glPushMatrix();
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glTranslatef(0.0f,0.0f,-0.12f);
	glColor4f(0.4f,0.2f,0.5f,alpha);
	gluDisk(quadratic,0.0f,0.05f,40,40);
	glPopMatrix();
	glPushMatrix();
	glColor4f(0.0f,0.0f,0.0f,alpha);//0.1
	glTranslatef(0.05f,0.19f,-0.07f);//0.17
	glutSolidSphere(0.018, 40, 40);	
	glPopMatrix();
	glPushMatrix();
	glColor4f(0.0f,0.0f,0.0f,alpha);//0.1
	glTranslatef(-0.05f,0.19f,-0.07f);//0.17
	glutSolidSphere(0.018, 40, 40);	
	glPopMatrix();
	glPushMatrix();
	glColor4f(0.196078f,0.6f,0.8f,alpha);
	drawhand(roboc.z,0,roboha,robola);
	glPopMatrix();
	glPushMatrix();
	glColor4f(1.0f,0.0f,0.0f,alpha);
	drawhand(roboc.z,1,roboha,robola);
	glPopMatrix();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);

}
void drawrobotx(pointx w,float t)
{
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(w.x,w.y,w.z);
	glRotatef(-t,0.0f,1.0f,0.0f);
	glColor3f(0.53f,0.12f,0.47f);
	glutSolidCube(0.18);//0.16
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.0f,0.18f,0.0f);
	glutWireSphere(0.09, 40, 40);//0.08	
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);//0.1
	glTranslatef(0.05f,0.19f,-0.06f);//0.17
	glutSolidSphere(0.018, 40, 40);	
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	glTranslatef(-0.05f,0.19f,-0.06f);//0.17
	glutSolidSphere(0.018, 40, 40);	
	glPopMatrix();
	glPushMatrix();
	glColor3f(1.0f,0.11f,0.68f);
	drawhand(w.z,0,roboha1,robola1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.72f,0.45f,0.20f);
	drawhand(w.z,1,roboha1,robola1);
	glPopMatrix();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);

}


//Create upper block
void createblock1(point a,point b,float z,float z1)
{

	glBegin(GL_QUADS);
	//glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(a.x,a.y,z);
	glVertex3f(b.x,b.y,z);
	glVertex3f(b.x,b.y,z1);
	glVertex3f(a.x,a.y,z1);
	glEnd();
}

//Create side walls
void createblock(point a,point b,float z,float z1,float transl,int i)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0,1.0f,1.0f);
	glBegin(GL_QUADS);
	//glColor3f(1.0f,1.0f,1.0f);
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(a.x,-2.4,z);
//	glColor3f(0.0f,0.5f,0.3f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(b.x,-2.4,z1);
//	glColor3f(0.2f,0.2f,0.2f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(b.x,b.y+transl,z1);
//	glColor3f(0.5f,0.5f,0.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(a.x,a.y+transl,z);
	glEnd();
//	glColor3f(1.0,1.0f,1.0f);
	glDisable(GL_TEXTURE_2D);
}

//check height
int check(float t,float e)
{
	//printf("xr %d\n",robottile);
	int i,j=0;
	for(i=0;i<100;i++)
	{
		if(i%10==0&&i!=0)
		{if(j==0)j=1;
			else j=0;
		}
if(j==0&&(roboca==90.0||roboca==270.0||roboca==-90.0||roboca==-270.0)&&(tiles[i].a.x<=t&&tiles[i].b.x>=t)&&tiles[i].a.z>=e&&tiles[i].d.z<=e)
		{
	//			if(i!=robottile)
	//			{
				if(flag[i]*trans[i]!=0.0)
				{
					if(r==0)
					{
					if(roboc.y>=(tiles[i].a.y)+(flag[i]*trans[i]))
					{
						roboc.y=tiles[i].a.y+0.30+trans[i];
						return 1;
					}
					else
						return 0;
					}
					else
					{
					//	printf("%f %f\n",roboc.x,roboc.y);
						if(roboc.y-0.3<tiles[i].a.y+(flag[i]*trans[i]) )
						{
							//roboc.y=tiles[i].a.y+0.30+trans;
							roboc.y=roboh;
							ju=1;
							r=0;
							return 0;
						}
						return 1;
					}
				}	
				if(obs[i]==1)
				{

					if(r==0)
					{
					if(roboc.y>=tiles[i].a.y)
					{
						roboc.y=tiles[i].a.y;
						return 1;
					}
					else
						return 0;
					}
					else
					{
						if(roboc.y-0.300 < tiles[i].a.y)
						{
							roboc.y=roboh;
							ju=1;
							r=0;
							return 0;
						}
						return 1;
					}
				}
				if(flag[i]*trans[i]==0.0&&obs[i]==0)
				{
					//printf("enter\n");
					if(r==0)
					{
					if(roboc.y >(tiles[i].a.y))
					{
						roboc.y=tiles[i].a.y+0.30;
						return 1;
					}
					else
						return 0;
					}
					else
					{
						if(roboc.y-0.3<=tiles[i].a.y)
						{
							roboc.y=tiles[i].a.y+0.30;
							ju=1;
							return 0;
						}
						return 1;
					}
				}
			//	}
		}
if(j==0&&(roboca==0.0||roboca==-360.0||roboca==360.0||roboca==-180.0||roboca==180.0)&&(tiles[i].a.z>=e&&tiles[i].d.z<=e)&&tiles[i].a.x<=t&&tiles[i].b.x>=t)
		{
				//printf("enter %f %f %d %d\n",roboc.y,tiles[i].a.y,flag[i],obs[i]);
			//	if(i!=robottile)
			//	{
				if(flag[i]*trans[i]!=0.0)
				{
					if(r==0)
					{
					if(roboc.y>=(tiles[i].a.y)+(flag[i]*trans[i]))
					{
						roboc.y=tiles[i].a.y+0.30+trans[i];
						return 1;
					}
					else
						return 0;
					}
					else
					{
					//	printf("%f %f\n",roboc.x,roboc.y);
						if(roboc.y-0.3<tiles[i].a.y+(flag[i]*trans[i]) )
						{
							//roboc.y=tiles[i].a.y+0.30+trans;
							roboc.y=roboh;
							ju=1;
							r=0;
							return 0;
						}
						return 1;
					}
				}	
				if(obs[i]==1)
				{

					if(r==0)
					{
					if(roboc.y>=tiles[i].a.y)
					{
						roboc.y=tiles[i].a.y;
						return 1;
					}
					else
						return 0;
					}
					else
					{
						if(roboc.y-0.300 < tiles[i].a.y)
						{
							roboc.y=roboh;
							ju=1;
							r=0;
							return 0;
						}
						return 1;
					}
				}
				if(flag[i]*trans[i]==0.0&&obs[i]==0)
				{
					//printf("enter\n");
					if(r==0)
					{
					if(roboc.y >(tiles[i].a.y))
					{
						roboc.y=tiles[i].a.y+0.30;
						return 1;
					}
					else
						return 0;
					}
					else
					{
						if(roboc.y-0.3<=tiles[i].a.y)
						{
							roboc.y=tiles[i].a.y+0.30;
							ju=1;
							return 0;
						}
				}
				}
			//	}
		}
if(j==1&&(roboca==0.0||roboca==-360.0||roboca==360.0||roboca==-180.0||roboca==180.0)&&(tiles[i].a.z<=e&&tiles[i].d.z>=e)&&tiles[i].a.x>=t&&tiles[i].b.x<=t)
		{
				//printf("enter %f %f %d %d\n",roboc.y,tiles[i].a.y,flag[i],obs[i]);
			//	if(i!=robottile)
			//	{
				if(flag[i]*trans[i]!=0.0)
				{
					if(r==0)
					{
					if(roboc.y>=(tiles[i].a.y)+(flag[i]*trans[i]))
					{
						roboc.y=tiles[i].a.y+0.30+trans[i];
						return 1;
					}
					else
						return 0;
					}
					else
					{
					//	printf("%f %f\n",roboc.x,roboc.y);
						if(roboc.y-0.3<tiles[i].a.y+(flag[i]*trans[i]) )
						{
							//roboc.y=tiles[i].a.y+0.30+trans;
							roboc.y=roboh;
							ju=1;
							r=0;
							return 0;
						}
						return 1;
					}
				}	
				if(obs[i]==1)
				{

					if(r==0)
					{
					if(roboc.y>=tiles[i].a.y)
					{
						roboc.y=tiles[i].a.y;
						return 1;
					}
					else
						return 0;
					}
					else
					{
						if(roboc.y-0.300 < tiles[i].a.y)
						{
							roboc.y=roboh;
							ju=1;
							r=0;
							return 0;
						}
						return 1;
					}
				}
				if(flag[i]*trans[i]==0.0&&obs[i]==0)
				{
					//printf("enter\n");
					if(r==0)
					{
					if(roboc.y >(tiles[i].a.y))
					{
						roboc.y=tiles[i].a.y+0.30;
						return 1;
					}
					else
						return 0;
					}
					else
					{
						if(roboc.y-0.3<=tiles[i].a.y)
						{
							roboc.y=tiles[i].a.y+0.30;
							ju=1;
							return 0;
						}
					}
				}
		//}
		}
if(j==1&&(roboca==90.0||roboca==270.0||roboca==-90.0||roboca==-270.0)&&(tiles[i].a.x>=t&&tiles[i].b.x<=t)&&tiles[i].a.z<=e&&tiles[i].d.z>=e)
			{
				//printf("enter %f %f %d %d\n",roboc.y,tiles[i].a.y,flag[i],obs[i]);
			//	if(i!=robottile)
			//	{
				if(flag[i]*trans[i]!=0.0)
				{
					if(r==0)
					{
					if(roboc.y>=(tiles[i].a.y)+(flag[i]*trans[i]))
					{
						roboc.y=tiles[i].a.y+0.30+trans[i];
						return 1;
					}
					else
						return 0;
					}
					else
					{
					//	printf("%f %f\n",roboc.x,roboc.y);
						if(roboc.y-0.3<tiles[i].a.y+(flag[i]*trans[i]) )
						{
							//roboc.y=tiles[i].a.y+0.30+trans;
							roboc.y=roboh;
							ju=1;
							r=0;
							return 0;
						}
						return 1;
					}
				}	
				if(obs[i]==1)
				{

					if(r==0)
					{
					if(roboc.y>=tiles[i].a.y)
					{
						roboc.y=tiles[i].a.y;
						return 1;
					}
					else
						return 0;
					}
					else
					{
						if(roboc.y-0.300 < tiles[i].a.y)
						{
							roboc.y=roboh;
							ju=1;
							r=0;
							return 0;
						}
						return 1;
					}
				}
				if(flag[i]*trans[i]==0.0&&obs[i]==0)
				{
					//printf("enter\n");
					if(r==0)
					{
					if(roboc.y >(tiles[i].a.y))
					{
						roboc.y=tiles[i].a.y+0.30;
						return 1;
					}
					else
						return 0;
					}
					else
					{
						if(roboc.y-0.3<=tiles[i].a.y)
						{
							roboc.y=tiles[i].a.y+0.30;
							ju=1;
							return 0;
						}
					}
				}
			//}
			}	
	}
	return 1;

}

//Main function
int main(int argc, char** argv) {
	
	//Initialize GLUT
	int q;
	srand(time(NULL));
	tiles[0].a.x=-4.5;//3.5
	tiles[0].a.y=-1.6;
	tiles[0].b.x=-3.6;//2.8
	tiles[0].b.y=-1.6;
	tiles[0].c.x=tiles[0].b.x;
	tiles[0].c.y=tiles[0].b.y;
	tiles[0].d.x=tiles[0].a.x;
	tiles[0].d.y=tiles[0].a.y;
	heli.x=0.0;heli.y=0.0;heli.z=4.0;
	tower.x=-4.0;tower.y=4.0;tower.z=-0.0;
	for(i=0;i<100;i++)
	{
		flag[i]=0;
		clear[i]=0;
		obs[i]=0;
		teleport[i]=0;
		trans[i]=0.0;

	}
	for(i=0;i<45;i++)
	{
		q=rand()%100;
		if(q!=0&&q!=u)
			flag[q]=1;
	}
	for(i=1;i<15;i++)
	{
		//while(flag[q]==1)
			q=rand()%100;
		//printf("%d\n",q);
		if(q!=0&&flag[q]!=1&&q!=tele&&q!=90&&q!=u)
			clear[q]=1;
	}
	for(i=0;i<25;i++)
	{
		q=rand()%100;
		if(q!=0&&flag[q]!=1&&clear[q]!=1)
			obs[q]=1;
	}
	for(i=0;i<12;i++)
	{
		q=rand()%100;
		if(q!=0&&clear[q]!=1&&q!=tele&&q!=90)
		{
			teleport[q]=1;
		}
	}
	//robotintialize();
	roboc.x=-4.4;roboc.y=-1.30;roboc.z=-5.0;
	for(i=0;i<10;i++)
	{
		robocx[i].y=roboc.y;
		if(i==0)
		{
			robocx[i].x=roboc.x+1.0;
			robocx[i].z=roboc.z-3.0;
		}
		else
		{
			robocx[i].x=roboc.x+i*0.9;
			robocx[i].z=roboc.z-i*1.1;
		}
		gun[i]=0;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	wia = glutGet(GLUT_SCREEN_WIDTH);
	hia = glutGet(GLUT_SCREEN_HEIGHT);
	int windowWidth = wia * 2 / 3;
	int windowHeight = hia * 2 / 3;
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((wia - windowWidth) / 2, (hia - windowHeight) / 2);

	
	//Create the window
	glutCreateWindow("~Clumsy Walker~");
	initRendering();
	
	//value intialization

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutPassiveMotionFunc(GetOGLPos);
	//GetCursorPos(&mousePos);
	glutSpecialFunc(handlekeypress2);
	glutSpecialUpFunc(keySpecialUp);
	glutMouseFunc(handleMouseclick);
	glutReshapeFunc(handleResize);
	glutTimerFunc(30,update2,1);
	glutTimerFunc(80, update, 0); 
	glutTimerFunc(130,update1,1);
	glutTimerFunc(100,update3,0);
	glutTimerFunc(700,update4,0);
	glutTimerFunc(200,update6,0);
	glutMainLoop();
	
	return 0;
}

//To handle mouse click
void handleMouseclick(int button, int state, int x, int y) {
		
	if (state == GLUT_DOWN)
	{
		tf=1;
		if (button == GLUT_LEFT_BUTTON)
			theta += 5.0;
		else if (button == GLUT_RIGHT_BUTTON)
			theta -= 5.0;
	}
	if(button==3)
	{
		heli.z+=0.3;	
	}
	if(button==4)
	{
		heli.z-=0.3;

	}
}

//To check the coordinates of robot
void checkx(float t,float e)
{
	int i,j=0,fl=0;
	for(i=0;i<100;i++)
	{
		if(i%10==0&&i!=0)
		{if(j==0)j=1;
			else j=0;
		}
		if(j==0&&tiles[i].a.x<=t&&tiles[i].b.x>=t)
		{
			if(tiles[i].a.z>=e&&tiles[i].d.z<=e)
			{
				fl=1;
					if(flag[i]*trans[i]!=0.0)
					{
							if(r==0)
							{
								roboc.y=tiles[i].a.y+0.30+trans[i];
								robottile=i;}
					}
					else
					{
							if(r==0)
							{
							roboc.y=tiles[i].a.y+0.30;
							robottile=i;}

					}
					break;
			}
		}
		if(j==1&&tiles[i].a.x>=t&&tiles[i].b.x<=t)
		{
			if(tiles[i].a.z<=e&&tiles[i].d.z>=e)
			{
				fl=1;
				if(flag[i]*trans[i]!=0.0)
				{
							if(r==0)
							{
								robottile=i;
								roboc.y=tiles[i].a.y+0.30+trans[i];
							}

				}
				else
				{
					if(r==0)
					{
					roboc.y=tiles[i].a.y+0.30;
					robottile=i;}

				}
				break;
			}
		}
	}
	if(roboc.y>4.0)
	{
		printf("yes");
		fl=0;
	}
	if(fl==0)
	{
		exit(0);
	}

}

void checkxy()
{
	int q;
	for(q=0;q<10;q++)
	{
	int i,j=0;
	float t=robocx[q].x,e=robocx[q].z;
	for(i=0;i<100;i++)
	{
		if(i%10==0&&i!=0)
		{if(j==0)j=1;
			else j=0;
		}
		if(j==0&&tiles[i].a.x<=t&&tiles[i].b.x>=t)
		{
			if(tiles[i].a.z>=e&&tiles[i].d.z<=e)
			{
					if(flag[i]*trans[i]!=0.0)
					{
							robocx[q].y=roboh+trans[i];
					}
					if (obs[i]==1)
					{
							robocx[q].y=roboh+oh;

					}
					if(clear[i]==1)
					{
						robocx[q].y=roboh-0.8;
					}
					if(obs[i]!=1&&flag[i]!=1&&clear[i]!=1)
					{
							robocx[q].y=roboh;
					}
					

			}
		}
		if(j==1&&tiles[i].a.x>=t&&tiles[i].b.x<=t)
		{
			if(tiles[i].a.z<=e&&tiles[i].d.z>=e)
			{
				if(flag[i]*trans[i]!=0.0)
				{
						robocx[q].y=roboh+trans[i];

				}
				if(obs[i]==1)
				{
						robocx[q].y=roboh+oh;
				}
					if(clear[i]==1)
					{
						robocx[q].y=roboh-0.8;
					}
				if(obs[i]!=1&&flag[i]!=1 && clear[i]!=1)
				{
					robocx[q].y=roboh;

				}
			}
		}
	}
	}

}
	
//handle up,right controls
void handlekeypress2(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT)
	{
		if(roboca==360.0||roboca==-360.0)
			roboca=0.0;
		roboca-=90.0f;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(roboca==360.0||roboca==-360.0)
			roboca=0.0;
		roboca+=90.0f;
	}
	if(key == GLUT_KEY_UP)
	{
		prevkey=key;
		move(1.0);
	}
	if(key == GLUT_KEY_DOWN)
	{
		prevkey=key;
		move(-1.0);
	}
}

//move the robot
void move(float x)
{
		if(roboca==0.0||roboca==360.0||roboca==-360.0)
		{
			if(check(roboc.x,roboc.z-(x*0.04*vz)-(x*0.09))==1)
			{
			//printf("check %d\n",check(roboc.x,roboc.z-(x*0.04*vz)-(x*0.09)));
			roboc.z-=x*0.04*vz;
			}
		}
		if(roboca==90.0||roboca==-270.0)
		{
			if(check(roboc.x+(x*0.04*vx)+(x*0.09),roboc.z)==1)
			{	
			//printf("check %d\n",check(roboc.x+(x*0.04*vx)+(x*0.09),roboc.z));
			roboc.x+=x*0.04*vx;
			}
		}
		if(roboca==-90.0||roboca==270.0)
		{
			if(check(roboc.x-(x*0.04*vx)-(x*0.09),roboc.z)==1)
			{
			//printf("check %d\n",check(roboc.x-(x*0.04*vx)-(x*0.09),roboc.z));
			roboc.x-=x*0.04*vx;
			}
		}
		if(roboca==-180.0||roboca==180.0)
		{
			if(check(roboc.x,roboc.z+x*0.04*vz+(x*0.09))==1)
			{
			//printf("check %d\n",check(roboc.x,roboc.z+x*0.04*vz+(x*0.09)));
			roboc.z+=x*0.04*vz;	
			}
		}
		checkx(roboc.x,roboc.z);
		if(roboc.z<tiles[9].d.z||roboc.z>tiles[0].a.z||roboc.x<tiles[0].a.x||roboc.x>tiles[99].a.x)
		{
			printf("Better Luck Next time!!!\n");
			exit(0);
		}
		if(roboha>=27.0)
			f=1;
		if(roboha<=-27.0)
			f=0;
		if(f==0)
		{
			roboha+=9.0f;
			robola+=6.0f;
		}
		else
		{
			roboha-=9.0f;
			robola-=6.0f;
		}

}
