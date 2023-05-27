#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<math.h>
#define PI   3.14159265358979323846

float _moveAll = 0.0f;

bool rainday = false;

GLfloat position_bird = 0.0f;
GLfloat speed_bird = 0.03f;

GLfloat position_car=0.0f;
GLfloat speed_car=0.02f;

bool birdCtrl = false;
GLfloat rotatei = 0.0f;
GLfloat rotatej = 0.0f;

GLfloat positionRain = 0.0f;
GLfloat speedRain = 0.01f;

float day3 = 0.0f;
float nytground = 0.3;
float treeCtrl = 0.5;
float skyCtrl = 0.2;
float moonCtrl = 0.2;
float cloudCtrl = 0.7;
bool nyt = true;
bool stopAll = true;
bool rt = true;


void circle(GLfloat x, GLfloat y, GLfloat r){
       int i;
       int triangleAmount = 20; //# of triangles used to draw circle
       GLfloat twicePi = 2.0f * PI;
       glBegin(GL_TRIANGLE_FAN);

       glVertex2f(x, y); // center of circle
       for(i = 0; i <= triangleAmount;i++) {
       glVertex2f(
          x+(r*cos(i * twicePi / triangleAmount)),
          y+(r*sin(i * twicePi / triangleAmount))
                );
       }
       glEnd();
}
void Idle(){
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}

void ground(){
    glBegin(GL_QUADS);                   //Roadside walkway
    glColor3f(0.4f, 0.5f, 0.4f);
    glVertex2f(-1,0.5);
    glVertex2f(1,0.5);
    glVertex2f(1,0.4);
    glVertex2f(-1,0.4);
    glEnd();
    glBegin(GL_QUADS);                   //Mosque back field
    glColor3f(0.0f, nytground, 0.0f);
    glVertex2f(-1.0,1.1);
    glVertex2f(1,1.1);
    glVertex2f(1,0.5);
    glVertex2f(-1.0,0.5);
    glEnd();
}

void ground2(){
    glBegin(GL_QUAD_STRIP);               //Right-Down Corner field
    glColor3f(0.0f, nytground, 0.0f);
    glVertex2f(0.5,0.0);
    glVertex2f(0.5,-0.7);
    glVertex2f(2,0.0);
    glVertex2f(2.0,-0.7);
    glEnd();
}

void water(){
    glBegin(GL_QUAD_STRIP);                //water
    glColor3f(0.0f, 0.7f, 1.0f);
    glVertex2f(0.2,0.0);
    glVertex2f(0.2,-0.7);
    glVertex2f(-2,0.0);
    glVertex2f(-2.0,-0.7);
    glEnd();

}

void road(){
    glBegin(GL_QUADS);                     //Road X-axis
    glColor3f(0.05f, 0.05f, 0.05f);
    glVertex2f(-1,0.4);
    glVertex2f(1,0.4);
    glVertex2f(1,0.0);
    glVertex2f(-1,0.0);
    glEnd();

    glLineWidth(8.0);                      //X-axis road middle green line boarder
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-2.0,0.2);
    glVertex2f(2.0,0.2);
    glVertex2f(-2.0,0.0);
    glVertex2f(0.2,0.0);
    glVertex2f(0.5,0.0);
    glVertex2f(2.0,0.0);
    glVertex2f(0.2,0.015);
    glVertex2f(0.2,-0.7);
    glVertex2f(0.5,0.015);
    glVertex2f(0.5,-0.7);

    glVertex2f(0.35,-0.15);
    glVertex2f(0.35,-0.7);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);                  //X-axis road middle green line
    glColor3f(0.0f, 0.3f, 0.0f);
    glVertex2f(-2.0,0.2);
    glVertex2f(2.0,0.2);
    glVertex2f(0.35,-0.15);
    glVertex2f(0.35,-0.7);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);                   //white lines
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.425,-0.2);
    glVertex2f(0.425,-0.4);

    glVertex2f(-1.8,0.1);
    glVertex2f(-2.0,0.1);
    glVertex2f(-1.4,0.1);
    glVertex2f(-1.6,0.1);
    glVertex2f(-1.0,0.1);
    glVertex2f(-1.2,0.1);
    glVertex2f(-0.8,0.1);
    glVertex2f(-0.6,0.1);
    glVertex2f(-0.3,0.1);
    glVertex2f(-0.1,0.1);

    glVertex2f(0.2,0.1);
    glVertex2f(0.4,0.1);
    glVertex2f(0.7,0.1);
    glVertex2f(0.9,0.1);
    glVertex2f(1.1,0.1);
    glVertex2f(1.3,0.1);
    glVertex2f(1.5,0.1);
    glVertex2f(1.7,0.1);
    glVertex2f(1.9,0.1);
    glVertex2f(2.0,0.1);

    glVertex2f(-1.6,0.3);
    glVertex2f(-1.8,0.3);
    glVertex2f(-1.2,0.3);
    glVertex2f(-1.4,0.3);
    glVertex2f(-0.8,0.3);
    glVertex2f(-1.0,0.3);
    glVertex2f(-0.6,0.3);
    glVertex2f(-0.4,0.3);
    glVertex2f(-0.1,0.3);
    glVertex2f(0.1,0.3);

    glVertex2f(0.4,0.3);
    glVertex2f(0.6,0.3);
    glVertex2f(0.8,0.3);
    glVertex2f(1.0,0.3);
    glVertex2f(1.2,0.3);
    glVertex2f(1.4,0.3);
    glVertex2f(1.8,0.3);
    glVertex2f(1.6,0.3);

    glVertex2f(0.275,0.1); //road2 lines
    glVertex2f(0.275,-0.1);
    glVertex2f(0.275,-0.4); //road2 lines
    glVertex2f(0.275,-0.6);

    glVertex2f(-1.6,-0.2); //water lines
    glVertex2f(-1.8,-0.2);
    glVertex2f(-1.1,-0.2);
    glVertex2f(-1.3,-0.2);
    glVertex2f(-0.9,-0.2);
    glVertex2f(-0.7,-0.2);
    glVertex2f(-0.3,-0.2);
    glVertex2f(-0.1,-0.2);
    glVertex2f(-1.7,-0.4);
    glVertex2f(-1.9,-0.4);
    glVertex2f(-1.2,-0.4);
    glVertex2f(-1.4,-0.4);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-1.0,-0.4);
    glVertex2f(-0.6,-0.4);
    glVertex2f(-0.4,-0.4);
    glVertex2f(-0.15,-0.4);
    glVertex2f(0.1,-0.4);
    glEnd();
}
void road2(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glBegin(GL_QUADS);
	glColor3f(0.05f, 0.05f, 0.05f);
	   glVertex2f(0.2f, -0.7f);
       glVertex2f(0.2f, 0.02f);
       glVertex2f(0.5f, 0.02f);
	   glVertex2f(0.5f, -0.7f);
	   glEnd();
    glPopMatrix();
}
void Mosque(){
  glTranslatef(0.0, 0.0, 0.0);
  glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);       //front wall
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.75);
    glVertex2f(0.2, 1.2);
    glVertex2f(-0.8, 1.2);
    glVertex2f(-0.8, 0.75);
    glEnd();

    glBegin(GL_POLYGON);             //clock backside
    glVertex2f(-0.15, 1.2);
    glVertex2f(-0.15, 1.7);
    glVertex2f(-0.45, 1.7);
    glVertex2f(-0.45, 1.2);
    glEnd();


    glColor3f(0.0, 0.0, 0.0);        //lines left side part
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2f(-0.78, 1.15);
    glVertex2f(-0.78, 1.05);
    glVertex2f(-0.76, 1.15);
    glVertex2f(-0.76, 1.05);
    glVertex2f(-0.74, 1.15);
    glVertex2f(-0.74, 1.05);
    glVertex2f(-0.72, 1.15);
    glVertex2f(-0.72, 1.05);
    glVertex2f(-0.70, 1.15);
    glVertex2f(-0.70, 1.05);
    glVertex2f(-0.68, 1.15);
    glVertex2f(-0.68, 1.05);
    glVertex2f(-0.66, 1.15);
    glVertex2f(-0.66, 1.05);
    glVertex2f(-0.64, 1.15);
    glVertex2f(-0.64, 1.05);
    glVertex2f(-0.62, 1.15);
    glVertex2f(-0.62, 1.05);
    glVertex2f(-0.60, 1.15);
    glVertex2f(-0.60, 1.05);
    glVertex2f(-0.58, 1.15);
    glVertex2f(-0.58, 1.05);
    glVertex2f(-0.56, 1.15);
    glVertex2f(-0.56, 1.05);
    glVertex2f(-0.54, 1.15);
    glVertex2f(-0.54, 1.05);
    glVertex2f(-0.52, 1.15);
    glVertex2f(-0.52, 1.05);
    glVertex2f(-0.50, 1.15);
    glVertex2f(-0.50, 1.05);
    glVertex2f(-0.48, 1.15);
    glVertex2f(-0.48, 1.05);
    glVertex2f(-0.46, 1.15);
    glVertex2f(-0.46, 1.05);
    glEnd();
    circle(-0.76f, 0.98f, 0.025f);
    circle(-0.70f, 0.98f, 0.025f);
    circle(-0.64f, 0.98f, 0.025f);
    circle(-0.58f, 0.98f, 0.025f);
    circle(-0.52f, 0.98f, 0.025f);
    glLineWidth(30.0);
    glBegin(GL_LINES);
    glVertex2f(-0.76f, 0.98);
    glVertex2f(-0.76, 0.90);
    glVertex2f(-0.70f, 0.98);
    glVertex2f(-0.70, 0.90);
    glVertex2f(-0.64f, 0.98);
    glVertex2f(-0.64, 0.90);
    glVertex2f(-0.58f, 0.98);
    glVertex2f(-0.58, 0.90);
    glVertex2f(-0.52f, 0.98);
    glVertex2f(-0.52, 0.90);
    glEnd();
    glLineWidth(8.0);
    glBegin(GL_LINES);
    glVertex2f(-0.48f, 1.0);
    glVertex2f(-0.48, 0.90);
    glVertex2f(-0.46f, 1.0);
    glVertex2f(-0.46, 0.90);
    glEnd();

  glPushMatrix();                     //Line Right side part
  glTranslatef(0.64, 0.0, 0.0);
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2f(-0.78, 1.15);
    glVertex2f(-0.78, 1.05);
    glVertex2f(-0.76, 1.15);
    glVertex2f(-0.76, 1.05);
    glVertex2f(-0.74, 1.15);
    glVertex2f(-0.74, 1.05);
    glVertex2f(-0.72, 1.15);
    glVertex2f(-0.72, 1.05);
    glVertex2f(-0.70, 1.15);
    glVertex2f(-0.70, 1.05);
    glVertex2f(-0.68, 1.15);
    glVertex2f(-0.68, 1.05);
    glVertex2f(-0.66, 1.15);
    glVertex2f(-0.66, 1.05);
    glVertex2f(-0.64, 1.15);
    glVertex2f(-0.64, 1.05);
    glVertex2f(-0.62, 1.15);
    glVertex2f(-0.62, 1.05);
    glVertex2f(-0.60, 1.15);
    glVertex2f(-0.60, 1.05);
    glVertex2f(-0.58, 1.15);
    glVertex2f(-0.58, 1.05);
    glVertex2f(-0.56, 1.15);
    glVertex2f(-0.56, 1.05);
    glVertex2f(-0.54, 1.15);
    glVertex2f(-0.54, 1.05);
    glVertex2f(-0.52, 1.15);
    glVertex2f(-0.52, 1.05);
    glVertex2f(-0.50, 1.15);
    glVertex2f(-0.50, 1.05);
    glVertex2f(-0.48, 1.15);
    glVertex2f(-0.48, 1.05);
    glVertex2f(-0.46, 1.15);
    glVertex2f(-0.46, 1.05);
    glEnd();
    circle(-0.72f, 0.98f, 0.025f);
    circle(-0.66f, 0.98f, 0.025f);
    circle(-0.60f, 0.98f, 0.025f);
    circle(-0.54f, 0.98f, 0.025f);
    circle(-0.48f, 0.98f, 0.025f);
    glLineWidth(30.0);
    glBegin(GL_LINES);
    glVertex2f(-0.72f, 0.98);
    glVertex2f(-0.72, 0.90);
    glVertex2f(-0.66f, 0.98);
    glVertex2f(-0.66, 0.90);
    glVertex2f(-0.60f, 0.98);
    glVertex2f(-0.60, 0.90);
    glVertex2f(-0.54f, 0.98);
    glVertex2f(-0.54, 0.90);
    glVertex2f(-0.48f, 0.98);
    glVertex2f(-0.48, 0.90);
    glEnd();
    glLineWidth(8.0);
    glBegin(GL_LINES);
    glVertex2f(-0.76f, 1.0f);
    glVertex2f(-0.76f, 0.90f);
    glVertex2f(-0.78f, 1.0f);
    glVertex2f(-0.78f, 0.90f);
    glEnd();
  glPopMatrix();


//Middle Part of mosque

    glLineWidth(2.5);                    //Upper 3 line
    glBegin(GL_LINES);
    glVertex2f(-0.15, 1.57);
    glVertex2f(-0.45, 1.57);
    glVertex2f(-0.15, 1.6);
    glVertex2f(-0.45, 1.6);
    glVertex2f(-0.15, 1.63);
    glVertex2f(-0.45, 1.63);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);             //Doors
    circle(-0.24f, 1.16f, 0.022f);
    circle(-0.30f, 1.26f, 0.022f);
    circle(-0.36f, 1.16f, 0.022f);
    glLineWidth(25);
    glBegin(GL_LINES);
    glVertex2f(-0.36, 1.16);
    glVertex2f(-0.36, 1.0);
    glVertex2f(-0.30, 1.26);
    glVertex2f(-0.30, 1.0);
    glVertex2f(-0.24, 1.16);
    glVertex2f(-0.24, 1.0);
    glEnd();
    glLineWidth(30);
    glBegin(GL_LINES);
    glVertex2f(-0.36, 1.1);
    glVertex2f(-0.36, 1.0);
    glVertex2f(-0.30, 1.1);
    glVertex2f(-0.30, 1.0);
    glVertex2f(-0.24, 1.1);
    glVertex2f(-0.24, 1.0);
    glEnd();

    glLineWidth(1);                       //Door Boarder
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.2, 1.0);
    glVertex2f(-0.2, 1.31);
    glVertex2f(-0.4, 1.31);
    glVertex2f(-0.4, 1.0);
    glEnd();

    glColor3f(0.8, 0.6, 0.3);             //Front ground
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.2, 0.75);
    glVertex2f(-0.15, 0.85);
    glVertex2f(-0.45, 0.85);
    glVertex2f(-0.8, 0.75);
    glVertex2f(-0.8, 0.5);
    glEnd();

    glBegin(GL_POLYGON);                //Front ground left field
    glColor3f(0.0f, nytground, 0.0f);
    glVertex2f(-0.52, 0.5);
    glVertex2f(-0.48, 0.72);
    glVertex2f(-0.8, 0.70);
    glVertex2f(-0.8, 0.5);
    glEnd();

    glBegin(GL_POLYGON);                //Front Ground Right field
    glColor3f(0.0f, nytground, 0.0f);
    glVertex2f(0.2, 0.5);
    glVertex2f(0.2, 0.70);
    glVertex2f(-0.12, 0.72);
    glVertex2f(-0.08, 0.5);
    glEnd();


    glColor3f(0.4, 0.4, 0.4);             //Stairway
    glBegin(GL_POLYGON);
    glVertex2f(-0.17, 0.77);
    glVertex2f(-0.10, 0.8);
    glVertex2f(-0.20, 1.0);
    glVertex2f(-0.40, 1.0);
    glVertex2f(-0.50, 0.8);
    glVertex2f(-0.43, 0.77);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);           //Steps down to up
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.50, 0.8);
    glVertex2f(-0.43, 0.77);
    glVertex2f(-0.17, 0.77);
    glVertex2f(-0.10, 0.8);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.48, 0.83);
    glVertex2f(-0.42, 0.80);
    glVertex2f(-0.18, 0.80);
    glVertex2f(-0.12, 0.83);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.47, 0.86);
    glVertex2f(-0.41, 0.83);
    glVertex2f(-0.19, 0.83);
    glVertex2f(-0.13, 0.86);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.45, 0.89);
    glVertex2f(-0.40, 0.86);
    glVertex2f(-0.20, 0.86);
    glVertex2f(-0.15, 0.89);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.44, 0.92);
    glVertex2f(-0.39, 0.89);
    glVertex2f(-0.21, 0.89);
    glVertex2f(-0.16, 0.92);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.42, 0.95);
    glVertex2f(-0.38, 0.92);
    glVertex2f(-0.22, 0.92);
    glVertex2f(-0.17, 0.95);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.41, 0.98);
    glVertex2f(-0.37, 0.95);
    glVertex2f(-0.23, 0.95);
    glVertex2f(-0.19, 0.98);
    glEnd();

    glBegin(GL_POLYGON);                //Door front floor
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(-0.22, 0.955);
    glVertex2f(-0.19, 0.980);
    glVertex2f(-0.20, 1.0);
    glVertex2f(-0.40, 1.0);
    glVertex2f(-0.41, 0.980);
    glVertex2f(-0.38, 0.955);
    glEnd();

    glLineWidth(1);                    //clock
    glColor3f(1.0, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25, 1.4);
    glVertex2f(-0.25, 1.5);
    glVertex2f(-0.35, 1.5);
    glVertex2f(-0.35, 1.4);
    glEnd();

  glPushMatrix();
  glTranslatef(-0.3, 1.45, 0.0);
    if(rt){                                //1
    glRotatef(rotatei,0.0, 0.0, 1.0);
    }
    glColor3ub(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-0.05, 0.0);
    glVertex2f(0.0f, 0.0f);
    glEnd();

     if(rt){                               //2
    glRotatef(-rotatej,0.0,0.0,0.1);
    }
    glBegin(GL_LINES);
    glVertex2f(-0.05, 0.0f);
    glVertex2f(0.0f, 0.0);
    glEnd();
    if(rt){
     rotatei+=0.0001f;
     rotatej+=0.5f;
    }
  glPopMatrix();
  glPopMatrix();
}

void tree(){
                                           //from the left
  glPushMatrix();                          //tree-2
  glTranslatef(-0.3f,0.05f,0.0f);
    glLineWidth(20.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.53f);
    glEnd();
    glColor3f(1.0f, treeCtrl, 0.0f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);
  glPopMatrix();

  glPushMatrix();                          //Tree 1
  glTranslatef(-0.4f,0.0f,0.0f);
    glLineWidth(20.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.53f);
    glEnd();
    glColor3f(0.0f, treeCtrl, 0.0f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);
  glPopMatrix();


  glPushMatrix();                          //Tree 3
  glTranslatef(-0.12f,0.03f,0.0f);
    glLineWidth(20.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.53f);
    glEnd();
    glColor3f(0.0f, treeCtrl, 0.0f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);
  glPopMatrix();


  glPushMatrix();                          //tree 4
  glTranslatef(0.1f,0.0f,0.0f);
    glLineWidth(20.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.53f);
    glEnd();
    glColor3f(0.5f, treeCtrl, 0.2f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);
  glPopMatrix();
}

void roundtree(){

//from left to right

    glPointSize(10);                    //tree-1
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.6, 0.0);
    glVertex2f(-0.8, 0.55);
    glEnd();
    glColor3f(0.0, 0.9, 0.0);
    circle(-0.8, 0.6, 0.03);

  glPushMatrix();                       //tree-2
  glTranslatef(0.08, 0.0, 0.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.6, 0.0);
    glVertex2f(-0.8, 0.55);
    glEnd();
    glColor3f(0.0, 0.9, 0.0);
    circle(-0.8, 0.6, 0.03);
  glPopMatrix();

  glPushMatrix();                       //tree-3
  glTranslatef(0.16, 0.0, 0.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.6, 0.0);
    glVertex2f(-0.8, 0.55);
    glEnd();
    glColor3f(0.0, 0.9, 0.0);
    circle(-0.8, 0.6, 0.03);
  glPopMatrix();

  glPushMatrix();                       //tree-4
  glTranslatef(0.24, 0.0, 0.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.6, 0.0);
    glVertex2f(-0.8, 0.55);
    glEnd();
    glColor3f(0.0, 0.9, 0.0);
    circle(-0.8, 0.6, 0.03);
  glPopMatrix();

  glPushMatrix();                       //tree-5
  glTranslatef(0.75, 0.0, 0.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.6, 0.0);
    glVertex2f(-0.8, 0.55);
    glEnd();
    glColor3f(0.0, 0.9, 0.0);
    circle(-0.8, 0.6, 0.03);
  glPopMatrix();

  glPushMatrix();                       //tree-6
  glTranslatef(0.83, 0.0, 0.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.6, 0.0);
    glVertex2f(-0.8, 0.55);
    glEnd();
    glColor3f(0.0, 0.9, 0.0);
    circle(-0.8, 0.6, 0.03);
  glPopMatrix();

  glPushMatrix();                       //tree-7
  glTranslatef(0.91, 0.0, 0.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.6, 0.0);
    glVertex2f(-0.8, 0.55);
    glEnd();
    glColor3f(0.0, 0.9, 0.0);
    circle(-0.8, 0.6, 0.03);
  glPopMatrix();

  glPushMatrix();                       //tree-8
  glTranslatef(0.99, 0.0, 0.0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.6, 0.0);
    glVertex2f(-0.8, 0.55);
    glEnd();
    glColor3f(0.0, 0.9, 0.0);
    circle(-0.8, 0.6, 0.03);
  glPopMatrix();

}

void sky(){
    glBegin(GL_QUADS);//sky
	glColor3f(skyCtrl, skyCtrl, skyCtrl);
	glVertex2f(-1.0f, 1.1f);
	glVertex2f(-1.0f, 2.8f);
	glVertex2f(1.0f, 2.8f);
	glVertex2f(1.0f, 1.1f);
	glEnd();
}
void moon(){
    glColor3f(0.9f, 0.9f, 0.9f);               //Sun
    circle(-0.75f, 2.0f, 0.1f);

    glColor3f(moonCtrl, moonCtrl, moonCtrl);   //Moon
    circle(-0.73f, 2.0f, 0.09f);
}
void clouds(){

  glPushMatrix();
    glColor3f(cloudCtrl, cloudCtrl, cloudCtrl);
    circle(-0.06f, 2.0f, 0.05f);
    circle(-0.16f, 2.0f, 0.10f);
    circle(-0.25f, 2.0f, 0.08f);
    circle(-0.34f, 2.0f, 0.05f);

  glPushMatrix();
  glTranslatef(0.8f, 0.0f,0.0f);
    circle(-0.27f, 2.0f,0.06f);
    circle(-0.16f, 2.0f,0.10f);
    circle(-0.04f, 2.0f,0.08f);
  glPopMatrix();
}

void banch(){

  glPushMatrix();
  glTranslatef(-0.1,-0.9f,0.0f);
    glBegin(GL_QUAD_STRIP);         //Bench sitting area
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.9f, 0.65f);
    glVertex2f(1.0f, 0.65f);
    glVertex2f(0.87f, 0.63f);
    glVertex2f(1.03f, 0.63f);
    glEnd();

    glLineWidth(2.5);                //Bench leg
    glBegin(GL_LINES);
    glColor3f(1.5f, 0.5f, 0.0f);
    glVertex2f(0.885f, 0.55f);
    glVertex2f(0.885f, 0.625f);
    glVertex2f(1.015f, 0.55f);
    glVertex2f(1.015f, 0.625f);
    glEnd();
    glLineWidth(3.0);
    glColor3f(1.5f, 0.5f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.87f, 0.625f);
    glVertex2f(1.03f, 0.625f);
    glEnd();

    glLineWidth(2.0);               //Bench backside lines
    glBegin(GL_LINES);
    glVertex2f(0.91f, 0.65f);
    glVertex2f(0.91f, 0.75f);
    glVertex2f(0.99f, 0.65f);
    glVertex2f(0.99f, 0.75f);
    glVertex2f(0.9f, 0.68f);
    glVertex2f(1.0f, 0.68f);
    glVertex2f(0.9f, 0.70f);
    glVertex2f(1.0f, 0.70f);
    glVertex2f(0.9f, 0.72f);
    glVertex2f(1.0f, 0.72f);
    glVertex2f(0.9f, 0.65f);
    glVertex2f(0.9f, 0.58f);
    glVertex2f(1.0f, 0.65f);
    glVertex2f(1.0f, 0.58f);
    glEnd();
  glPopMatrix();
}

void lamppost(){

  glPushMatrix();
  glTranslatef(-0.1, -1.1, 0.0);
    glLineWidth(10.0);                   //lamppost's ground body
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 0.52f);
    glEnd();

    glLineWidth(4.0);                    //lamppost's middle-top body
    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 1.0f);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 1.0f);
    glVertex2f(0.68f, 1.0f);
    glVertex2f(0.75f, 1.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);               //Lamppost bulb body
    glVertex2f(0.75f, 1.03f);
    glVertex2f(0.75f, 0.97f);
    glVertex2f(0.76f, 1.03f);
    glVertex2f(0.79f, 0.97f);
    glEnd();

    if(nyt){                              //lamppost light in night mode
        glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 0.9f, 0.9f);
        glVertex2f(0.75f, 0.97f);
        glVertex2f(0.79f, 0.97f);
        glVertex2f(0.75f, 0.7f);
        glVertex2f(0.9f, 0.7f);
        glEnd();
    }
  glPopMatrix();
}


void lamppost1(){

  glPushMatrix();
  glTranslatef(-1.69, 0.0, 0.0);
    glLineWidth(10.0);                   //lamppost's ground body
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 0.52f);
    glEnd();

    glLineWidth(4.0);                    //lamppost's middle-top body
    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 1.0f);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 1.0f);
    glVertex2f(0.68f, 1.0f);
    glVertex2f(0.75f, 1.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);               //Lamppost bulb body
    glVertex2f(0.75f, 1.03f);
    glVertex2f(0.75f, 0.97f);
    glVertex2f(0.76f, 1.03f);
    glVertex2f(0.79f, 0.97f);
    glEnd();

    if(nyt){                              //lamppost light in night mode
        glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 0.9f, 0.9f);
        glVertex2f(0.75f, 0.97f);
        glVertex2f(0.79f, 0.97f);
        glVertex2f(0.75f, 0.7f);
        glVertex2f(0.9f, 0.7f);
        glEnd();
    }
  glPopMatrix();
}

void signallight(){

    glLineWidth(7.0);                       //signal light body
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 1.0f);
    glVertex2f(0.2,-0.2);
    glVertex2f(0.23,-0.17);
    glEnd();
    glLineWidth(13.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 1.0f);
    glVertex2f(0.23,-0.17);
    glVertex2f(0.33,-0.17);
    glEnd();
    glColor3f(1.0f, 1.0f, 0.0f);            //yellow
    circle(0.25f,-0.17f,0.015f);
    glColor3f(0.0f, 1.0f, 0.0f);            //green
    circle(0.279f,-0.17f,0.015f);
    glColor3f(1.0f, 0.0f, 0.0f);            //red
    circle(0.312f,-0.17f,0.015f);
}

void car(){

  glTranslatef(-position_car, 0.0, 0.0);      //Red car body
  glPushMatrix();
    glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.9f, 0.255f);
	glVertex2f(-0.9f, 0.33f);
	glVertex2f(-0.87f, 0.39f);
	glVertex2f(-0.8f, 0.39f);
	glVertex2f(-0.75f, 0.32f);
	glVertex2f(-0.7f, 0.3f);
	glVertex2f(-0.7f, 0.255f);
	glEnd();

	glBegin(GL_POLYGON);                         //Red car front window
	glColor3f(0.05f, 0.05f, 0.05f);
	glVertex2f(-0.89f, 0.33f);
	glVertex2f(-0.87f, 0.38f);
	glVertex2f(-0.835f, 0.38f);
	glVertex2f(-0.835f, 0.33f);
	glEnd();

	glBegin(GL_POLYGON);                        //Red car back window
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.83f, 0.33f);
	glVertex2f(-0.83f, 0.38f);
	glVertex2f(-0.8f, 0.38f);
	glVertex2f(-0.76f, 0.325f);
	glEnd();

	if(nyt){                                    //headlight in night mode
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.9f, 0.8f);
	    glVertex2f(-0.7f, 0.29f);
	    glVertex2f(-0.60f, 0.22f);
	    glVertex2f(-0.43f, 0.22f);
	    glEnd();
	}

  glPushMatrix();                                //Red car left wheel
  glTranslatef(-0.86,0.25,0);
    if(rt){
    glRotatef(rotatei,0,0.0,0.1);
    }
    glColor3f(0.4f, 0.4f, 0.4f);
    circle(0.0f, 0.0f, 0.03f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.0f, 0.0f, 0.02f);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.0f, 0.0f, 0.01f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.03f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.03f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.03f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.03f);
	glEnd();
  glPopMatrix();
	if(rt){
	rotatei -=0.05f;
	}

  glPushMatrix();                                   //Red car right wheel
  glTranslatef(-0.75,0.25,0);
	if(rt){
    glRotatef(rotatei,0,0.0,0.1);
	}
    glColor3f(0.4f, 0.4f, 0.4f);
    circle(0.0f, 0.0f, 0.03f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.0f, 0.0f, 0.02f);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.0f, 0.0f, 0.01f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.03f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.03f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.03f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.03f);
    glEnd();
  glPopMatrix();
	if(rt){
	rotatei -=0.05f;
	}
  glPopMatrix();
}

void car2(){

  glPushMatrix();                            //Pink car body
  glTranslatef(position_car, -0.20, 0.0);
    glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.8f, 0.8f);
	glVertex2f(0.9f, 0.255f);
	glVertex2f(0.9f, 0.33f);
	glVertex2f(0.87f, 0.39f);
	glVertex2f(0.8f, 0.39f);
	glVertex2f(0.75f, 0.32f);
	glVertex2f(0.7f, 0.3f);
	glVertex2f(0.7f, 0.255f);
	glEnd();
	glBegin(GL_POLYGON);                 //Pink car front window
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(0.83f, 0.33f);
	glVertex2f(0.83f, 0.38f);
	glVertex2f(0.8f, 0.38f);
	glVertex2f(0.76f, 0.325f);
	glEnd();
	glBegin(GL_POLYGON);                 //Pink car back window
	glColor3f(0.05f, 0.05f, 0.05f);
	glVertex2f(0.89f, 0.33f);
	glVertex2f(0.87f, 0.38f);
	glVertex2f(0.835f, 0.38f);
	glVertex2f(0.835f, 0.33f);
	glEnd();

	if(nyt){                             //Pink car headlight in night mode
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.9f, 0.8f);
	    glVertex2f(0.7f, 0.29f);
	    glVertex2f(0.60f, 0.22f);
	    glVertex2f(0.43f, 0.22f);
	    glEnd();
	}

  glPushMatrix();                          //Pink Car back wheel
  glTranslatef(0.86,0.25,0);
    if(rt){
    glRotatef(-rotatei,0,0.0,0.1);
    }
    glColor3f(0.4f, 0.4f, 0.4f);
    circle(0.0f, 0.0f, 0.03f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.0f, 0.0f, 0.02f);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.0f, 0.0f, 0.01f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.03f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.03f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.03f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.03f);
	glEnd();
  glPopMatrix();
	if(rt){
	rotatei -=0.05f;
	}

  glPushMatrix();                           //Pink Car front wheel
  glTranslatef(0.75,0.25,0);
	if(rt){
    glRotatef(-rotatei,0,0.0,0.1);
	}
    glColor3f(0.4f, 0.4f, 0.4f);
    circle(0.0f, 0.0f, 0.03f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.0f, 0.0f, 0.02f);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.0f, 0.0f, 0.01f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.03f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.03f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.03f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.03f);
	glEnd();
  glPopMatrix();
	if(rt){
	rotatei -=0.05f;
	}
  glPopMatrix();

}


void ship(){
  glPushMatrix();
  glPushMatrix();
  glTranslatef(-1.8,0.0f,0.0f);
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.7f, 0.7f);
    glVertex2f(0.3,0.0);
    glVertex2f(0.75,0.0);
    glVertex2f(0.4,-0.1);
    glVertex2f(0.7,-0.1);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.6,0.0);
    glVertex2f(0.7,0.0);
    glVertex2f(0.6,0.1);
    glVertex2f(0.7,0.1);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.65,0.1);
    glVertex2f(0.69,0.1);
    glVertex2f(0.65,0.2);
    glVertex2f(0.69,0.2);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.75f, 0.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, day3);
    circle(0.67f, 0.05f, 0.015f);

    if(nyt){
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(0.65f,0.17f);
    glVertex2f(0.65,0.15f);
    glVertex2f(0.3,-0.05);
    glVertex2f(0.3,0.23);
    glEnd();
    }

    glPopMatrix();
}

void bird(){

//bird 1 (right to left)

  glPushMatrix();                       //bird-1 head
  glTranslatef(-position_bird, 0.9f, 0.0f);
    if(birdCtrl){
    int i;
	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;
    glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);                  //bird-1 body
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);                 //bird-1 hand
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();

//2nd bird

    GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);                    //bird-2 body
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

//3rd bird

    GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glBegin(GL_POLYGON);                        //bird-3 body
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

//4th bird

	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);

		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);                            //bird-4 body
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();

    }
  glPopMatrix();
}

void Rain(){

  glPushMatrix();
  glTranslatef(0.0, -positionRain, 0.0f);
    if(rainday){
  glPushMatrix();
  glTranslatef(0.0, 0.5f, 0.0f);

    GLfloat xR= -1.05;
    GLfloat yR = 2.05;

    glBegin(GL_LINES);
    glColor3ub(18, 18, 18);
    for(int i=0;i<=105;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-.02,yR-.04);

    xR += .02;
    }
    glEnd();

    for(int j=0;j<=150;j++)
    {
    xR = -1.8;
    yR= yR-.05;
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i=0;i<=250;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-.02,yR-.04);

    xR += .02;
    }
    glEnd();
    }
  glPopMatrix();
    }
  glPopMatrix();
}

void update_bird(int value){

    if(position_bird <-1.0)
    {
        position_bird = 1.0f;
    }
    position_bird -= speed_bird;

	glutTimerFunc(100, update_bird, 0);
}


void update_car(int value){

    if(position_car <-1.8)
    {
        position_car = 0.6f;
    }
    position_car -= speed_car;

	glutTimerFunc(100, update_car, 0);
}


void updateRain(int value) {
    if(positionRain >.14)
        {positionRain = 0.0f;}

    positionRain += speedRain;

	glutPostRedisplay();

	glutTimerFunc(100, updateRain, 0);
}


void myKeyboard (unsigned char key, int x, int y) {
    glutPostRedisplay();
    switch (key)
    {
    case 'r':
        rainday = true;
        sndPlaySound(NULL,SND_ASYNC);
        sndPlaySound("Rain-sounds.wav",SND_ASYNC|SND_LOOP);
        break;
    case 't':
        rainday = false;
        sndPlaySound(NULL,SND_ASYNC);
        break;
    case 's':
        stopAll = false;
        speed_bird = 0.0;
        speed_car=0.0;
        rt = false;
        sndPlaySound(NULL,SND_ASYNC);
        break;
    case 'd':
        stopAll = true;
        speed_bird = 0.03;
        speed_car=0.03;
        rt = true;
        break;
    default:
    break;

    }
}
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			    day3 = 0.9f;
			    nytground = 0.5f;
			    treeCtrl = 0.7f;
			    skyCtrl = 0.9f;
			    moonCtrl = 1.0f;
			    cloudCtrl = 1.0f;
			    nyt = false;
			    birdCtrl = true;
			    sndPlaySound(NULL,SND_ASYNC);
                sndPlaySound("Morning-sounds.wav",SND_ASYNC|SND_LOOP);
			}
			if (button == GLUT_RIGHT_BUTTON)
            {
                day3 = 0.0f;
                nytground = 0.3;
                treeCtrl = 0.5;
                skyCtrl = 0.2;
                moonCtrl = 0.2;
                cloudCtrl = 0.7;
                nyt = true;
                birdCtrl = false;
                sndPlaySound(NULL,SND_ASYNC);
                sndPlaySound("Night-sounds.wav",SND_ASYNC|SND_LOOP);
			}
	glutPostRedisplay();
}
void display() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0f, -0.55f, 0.0f);
	glScalef(1.0f, 0.65f, 0.0f);
	sky();
	moon();
	clouds();
	ground();
	water();
	ground2();
	road2();
	road();
	tree();
	banch();
	lamppost();
	lamppost1();
	signallight();
	Mosque();
	roundtree();
	ship();
	car();
	car2();
	bird();
	Rain();
	glPopMatrix();
	Idle();

	glFlush();  // Render now
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(1100,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow(" r-rain.   t-rain stop.   s-all stop.   d-all start.   Mouse Right-night.   Mouse Left-day.  ");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100, update_bird, 0);
    glutTimerFunc(100, updateRain, 0);
    glutTimerFunc(100, update_car, 0);
    glutMainLoop();
    return 0;
}

