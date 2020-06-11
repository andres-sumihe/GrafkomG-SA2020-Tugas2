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

//Satelit Alam
double sBBx;
double sBBy;

double sBPx;
double sBPy;

double sBDx;
double sBDy;

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

void garis(double r_pointsX1 ,double r_pointsY1, double r_pointsX2, double r_pointsY2) {
	glBegin(GL_LINES);

	glVertex2d(r_pointsX1, r_pointsY1);
	glVertex2d(r_pointsX2, r_pointsY2);

	glEnd();
}
int j = 0;
void revolusi(double r, int days, string nama_planet) {
	
	double x = r * cos(2 * M_PI * j / days);
	double y = r * sin(2 * M_PI * j / days);

	j++;

	if (nama_planet == "merkurius") {
		sMx = x; sMy = y;
		cout << x << endl;
	}
	if (nama_planet == "venus") {
		sVx = x; sVy = y;
		cout << x << endl;
	}
	if (nama_planet == "bumi") {
		sBx = x; sBy = y;
		cout << x << endl;
	}
	if (nama_planet == "mars") {
		sMrx = x; sMry = y;
		cout << x << endl;
	}
	//Satelit Alam
	if (nama_planet == "bulan") {
		sBBx = x; sBBy = y;
		cout << x << endl;
	}
	if (nama_planet == "phobos") {
		sBPx = x; sBPy = y;
		cout << x << endl;
	}
	if (nama_planet == "deimos") {
		sBDx = x; sBDy = y;
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

	//Satelit Alam
	planet(35.0, sBx, sBy, 60, true);
	planet(35.0, sMrx, sMry, 60, true);
	planet(45.0, sMrx, sMry, 60, true);

	garis(0.0,0.0,sMx, sMy);
	garis(0.0,0.0,sVx, sVy);
	garis(0.0,0.0,sBx, sBy );
	garis(0.0,0.0,sMrx, sMry);
	garis(sBx, sBy, sBx + sBBx, sBy + sBBy);
	garis( sMrx, sMry, sMrx + sBPx, sMry + sBPy);
	garis( sMrx, sMry, sMrx + sBDx, sMry + sBDy);
	
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
	glPointSize(3.0f);
	glVertex2d(sBx + sBBx, sBy + sBBy);
	glEnd();

	glColor3ub(138, 135, 131);
	glBegin(GL_POINTS);
	glPointSize(1.0f);
	glVertex2d(sMrx + sBPx, sMry + sBPy);
	glEnd();

	glColor3ub(138, 135, 131);
	glBegin(GL_POINTS);
	glPointSize(2.0f);
	glVertex2d(sMrx + sBDx, sMry + sBDy);

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
	// Waktu Revolusi --> 1 Detik Program = 10 Hari Bumi
	revolusi(70, 880, "merkurius" );
	revolusi(140, 2240, "venus" );
	revolusi(250, 3650, "bumi" );
	revolusi(400, 6870, "mars" );
	
	//bulan 29.5 Hari
	revolusi(35, 295, "bulan" );

	// Untuk Kecepatan Revolusi Phobos dan Deimos tidak menggunakan waktu revolusi
	// yang diapakai untuk planet lainnya karena perputaran akan sangat cepat
	// Phobos Memiliki Kecepatan Revolusi 7 Jam dan Deimos 30 Jam
	revolusi(35, 295, "phobos" );
	revolusi(45, 395, "deimos" );
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