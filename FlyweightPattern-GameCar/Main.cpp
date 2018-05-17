#include "stdafx.h"
#include <windows.h>
#include <GL\glut.h>
#include <Math.h>
#include <iostream>
#include <thread>
#include <vector>
#include "Lawan.h"
#include "typeLawan.h"
#include "factory.h"

#define PHI  3.14159265f;
using namespace std;

GLfloat radius = 0.2f;
//GLfloat x = 0.0f, y = 0.0f;
GLfloat X_Max, X_Min, Y_Max, Y_Min;
GLfloat color = 1.0f;

float posx = 0.0f, posy = 0.0f;
float realX, realY;

vector<Lawan*> arrayOfLawan;

int refreshMillis = 33;

void initGL() {
	glClearColor(0.0, 0.0, 0.0, 255.0);
}

void drawCircle(GLfloat x, GLfloat y) {
	//float ab = x-al;
	//GLfloat ix = al;
	///cout << al << endl;
	glTranslatef(x, y, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, color, 0.0f);
	glVertex2f(0.0f, 0.0f);
	int numSegments = 200;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++)
	{
		angle = i * 2.0f * PHI;
		angle = angle / numSegments;
		glVertex2f(cos(angle)*radius, sin(angle)*radius);
	}
	glEnd();
}

void drawSquare(/*Obstacle _obstacle*/) {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.2f, 0.2f, 0.0);
	glVertex3f(0.2f, -0.2f, 0.0);
	glVertex3f(-0.2f, -0.2f, 0.0);
	glVertex3f(-0.2f, 0.2f, 0.0);
	glEnd();
}

void drawRect(float _x, float _y, float _width, float _height, int _colour) {
	_width /= 320;
	_height /= 320;
	_x /= 320;
	_y /= 320;
	_x -= 1.0f;
	_y -= 1.0f;
	_x -= _width / 2;
	_y -= _height / 2;
	switch (_colour)
	{
	case 1:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	case 2:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case 3:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	case 4:
		glColor3f(1.0f, 1.0f, 0.0f);
		break;
	case 5:
		glColor3f(1.0f, 0.0f, 1.0f);
		break;
	case 6:
		glColor3f(0.0f, 1.0f, 1.0f);
		break;
	default:
		glColor3f(1.0f, 1.0f, 1.0f);
		break;
	}
	glBegin(GL_QUADS);
	glVertex2f(_x, _y);
	glVertex2f(_x + _width, _y);
	glVertex2f(_x + _width, _y + _height);
	glVertex2f(_x, _y + _height);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	for (vector<Lawan*>::const_iterator i = arrayOfLawan.begin(); i != arrayOfLawan.end(); ++i) {
		drawRect((*i)->x, (*i)->y, (*i)->type.width, (*i)->type.height, (*i)->type.colour);
	}
	glutSwapBuffers();
}


void Timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, Timer, 0);
}

int windowWidth = 640, windowHeight = 640, windowXPost = 0, windowYPost = 0;

void Update() {
	//cout << "Update" << endl;
}

void startGLUT() {
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(windowXPost, windowYPost);
	glutCreateWindow("Flyweight Pattern");
	glutDisplayFunc(display); 
	glutTimerFunc(0, Timer, 0); 
	initGL();
	glutMainLoop();
}

void createObstacle(int _id, float _x, float _y, float _width, float _height, float _speed, int _colour) {
	typeLawan *type = factory::getType(_id, _width, _height, _speed, _colour);
	Lawan *lawan = new Lawan();
	lawan->setLawanPos(_x, _y);
	lawan->settypeLawan(*type);
	arrayOfLawan.push_back(lawan);
}

int main(int argc, char**argv) {
	int a, size, speed, counter = 0;
	glutInit(&argc, argv);
	thread first(startGLUT);
	while (true) {
		Sleep(33);
		for (vector<Lawan*>::const_iterator i = arrayOfLawan.begin(); i != arrayOfLawan.end(); ++i) {
			(*i)->update();
		}
		if (counter == 30) {
			size = rand() % 20 + 1;
			speed = rand() % 4 + 1;
			createLawan(rand() % 8, 640, rand() % 500 + 70, size * 5, size * 5, speed, rand() % 7);
			counter = 0;
		}
		counter++;
	}
}