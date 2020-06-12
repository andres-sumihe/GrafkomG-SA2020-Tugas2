#define _USE_MATH_DEFINES
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
//#include <GL/freeglut.h>
#include <string>
using namespace std;


double coorMerkuriusX;
double coorMerkuriusY;
double coorVenusX;
double coorVenusY;
double coorBumiX;
double coorBumiY;
double coorMarsX;
double coorMarsY;

//Satelit Alam
double coorBulanBumiX;
double coorBulanBumiY;

double coorBulanPhobosX;
double coorBulanPhobosY;

double coorBulanDeimosX;
double coorBulanDeimosY;

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

void Satelites(double x1,double x2, float size){
	glColor3ub(138, 135, 131);
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2d(x1, x2);
	glEnd();
}

void garis(double r_pointsX1 ,double r_pointsY1, double r_pointsX2, double r_pointsY2) {
	glBegin(GL_LINES);
	glVertex2d(r_pointsX1, r_pointsY1);
	glVertex2d(r_pointsX2, r_pointsY2);
	glEnd();
}


int countRevolusi = 0;
void revolusi(double r, int days, string nama_planet) {
	
	double x = r * cos(2 * M_PI * countRevolusi / days);
	double y = r * sin(2 * M_PI * countRevolusi / days);

	countRevolusi++;

	if (nama_planet == "merkurius") {coorMerkuriusX = x; coorMerkuriusY = y;}
	if (nama_planet == "venus") {coorVenusY = x; coorVenusX = y;}
	if (nama_planet == "bumi") {coorBumiX = x; coorBumiY = y;}
	if (nama_planet == "mars") {coorMarsX = x; coorMarsY = y;}
	//Satelit Alam
	if (nama_planet == "bulan") {coorBulanBumiX = x; coorBulanBumiY = y;}
	if (nama_planet == "phobos") {coorBulanPhobosX = x; coorBulanPhobosY = y;}
	if (nama_planet == "deimos") {coorBulanDeimosX = x; coorBulanDeimosY = y;}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(105, 105, 105);
	planet(70.0,0.0,0.0, 60, true);
	planet(140.0, 0.0, 0.0, 60, true);
	planet(250.0, 0.0, 0.0, 60, true);
	planet(400.0, 0.0, 0.0, 60, true);

	//Satelit Alam
	planet(35.0, coorBumiX, coorBumiY, 60, true);
	planet(35.0, coorMarsX, coorMarsY, 60, true);
	planet(45.0, coorMarsX, coorMarsY, 60, true);

	garis(0.0,0.0,coorMerkuriusX, coorMerkuriusY);
	garis(0.0,0.0,coorVenusY, coorVenusX);
	garis(0.0,0.0,coorBumiX, coorBumiY );
	garis(0.0,0.0,coorMarsX, coorMarsY);
	garis(coorBumiX, coorBumiY, coorBumiX + coorBulanBumiX, coorBumiY + coorBulanBumiY);
	garis( coorMarsX, coorMarsY, coorMarsX + coorBulanPhobosX, coorMarsY + coorBulanPhobosY);
	garis( coorMarsX, coorMarsY, coorMarsX + coorBulanDeimosX, coorMarsY + coorBulanDeimosY);
	
	glColor3ub(255, 255, 0);
	planet(30.0, 0.0, 0.0, 60, false);

	glColor3ub(138, 135, 131);
	planet(8.0, coorMerkuriusX, coorMerkuriusY, 60, false);
	glColor3ub(179, 89, 11	);
	planet(20.0, coorVenusY, coorVenusX, 60, false);
	glColor3ub(50, 102, 168);
	planet(24.0,  coorBumiX, coorBumiY, 60, false);
	glColor3ub(217, 31, 7);
	planet(18.0, coorMarsX, coorMarsY, 60, false);

	Satelites(coorBumiX + coorBulanBumiX, coorBumiY + coorBulanBumiY, 3.0f);
	Satelites(coorMarsX + coorBulanPhobosX, coorMarsY + coorBulanPhobosY, 1.0f);
	Satelites(coorMarsX + coorBulanDeimosX, coorMarsY + coorBulanDeimosY, 2.0f);


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
	glutTimerFunc(1000 / 30, timer, 0); // 30 FPS
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
	//Initial Source Code from https://bit.ly/GrakomUtility
	//Reference Video from https://www.youtube.com/watch?v=Xlcn0SpzyCQ

	// Dont Forget to visit https://codemaster.my.id :D
}