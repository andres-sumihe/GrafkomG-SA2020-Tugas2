#define _USE_MATH_DEFINES
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <string>
using namespace std;


double sMx;
double sMy;
double sVy;
double sVx;
double sBx;
double sBy;
double sMrx;
double sMry;
void planet(double r, double xx, double yy, int n,  bool orbit) {
	double count = (double)n;
	glBegin((orbit) ? GL_LINE_LOOP : GL_POLYGON );
	for (int i = 0; i < n; i++) {
		double x = r * cos(2 * M_PI * i / count);
		double y = r * sin(2 * M_PI * i / count);
		glVertex2d(xx+x, yy+y);
	}
	glEnd();
}
int j = 0;
void revolusi(double r, int days, string nama_planet) {
	
	double x = r * cos(2 * M_PI * j / days);
	double y = r * sin(2 * M_PI * j / days);

	j++;

	if (nama_planet == "merkurius") {
		sMx = x;
		sMy = y;
		cout << x << endl;
	}
	if (nama_planet == "venus") {
		sVx = x;
		sVy = y;
		cout << x << endl;
	}
	if (nama_planet == "bumi") {
		sBx = x;
		sBy = y;
		cout << x << endl;
	}
	if (nama_planet == "mars") {
		sMrx = x;
		sMry = y;
		cout << x << endl;
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(105, 105, 105);
	planet(70.0,0.0,0.0, 60, true);
	planet(140.0, 0.0, 0.0, 60, true);
	planet(250.0, 0.0, 0.0, 60, true);
	planet(400.0, 0.0, 0.0, 60, true);
	
	glColor3ub(255, 255, 0);
	planet(30.0, 0.0, 0.0, 60, false);

	glColor3ub(138, 135, 131);
	planet(8.0, sMx, sMy, 60, false);
	glColor3ub(179, 89, 11	);
	planet(20.0, sVx, sVy, 60, false);
	glColor3ub(50, 102, 168);
	planet(24.0,  sBx, sBy, 60, false);
	glColor3ub(217, 31, 7);
	planet(18.0, sMrx, sMry, 60, false);

	glColor3ub(138, 135, 131);
	glBegin(GL_POINTS);
	glPointSize(1);
	glVertex2d(sBx + 30, sBy + 30);
	glEnd();
	

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
	// Waktu Revolusi --> 1 Detik = 10 Hari Bumi
	revolusi(70, 880, "merkurius" );
	revolusi(140, 2240, "venus" );
	revolusi(250, 3650, "bumi" );
	revolusi(400, 6870, "mars" );
	std::cout << sBx << std::endl;
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_POINT_SMOOTH);

	glutTimerFunc(0, timer, 0);
	glutDisplayFunc(display);

	myinit();
	glutMainLoop();

	return 0;
}