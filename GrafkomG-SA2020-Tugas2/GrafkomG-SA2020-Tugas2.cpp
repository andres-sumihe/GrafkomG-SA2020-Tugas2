#define _USE_MATH_DEFINES
#include <iostream>

#include <math.h>
#include <GL/glut.h>

int matahari = 0;
int merkuriusX = 50;
int merkuriusY = 50;
int venusX = 80;
int venusY = 80;
int bumiX = 150;
int bumiY = 150;
int marsX = 250;
int marsY = 250;
void planet(double r, int n, int planetCoorX, int planetCoorY) {
	double n2 = (double)n;
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++) {
		double x = r * cos(r * M_PI * i / n);
		double y = r * sin(r * M_PI * i / n);
		glVertex2d(planetCoorX+x,planetCoorY+y);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(255, 245, 0);
	planet(30.0, 360, 0, 0);

	glColor3ub(255, 245, 0);
	planet(3.0, 360, merkuriusX, merkuriusY);
	
	glColor3ub(255, 245, 240);
	planet(5.0, 360, venusX, venusY);
	
	glColor3ub(10, 10, 255);
	planet(10.0, 360, bumiX, bumiY);
	
	glColor3ub(255, 245, 0);
	planet(12.0, 360, marsX, marsY);
	
	glutSwapBuffers();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}
void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, timer, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");

	glutTimerFunc(0, timer, 0);
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();

	return 0;
}