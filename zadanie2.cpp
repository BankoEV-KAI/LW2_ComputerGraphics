#include "zadania.h"

#include <windows.h>

GLfloat R = 600 / 600; //Форматное соотношение
GLfloat w = 50; //Ширина мирового окна
GLfloat h; //Высота мирового окна
GLfloat l, r, b, t; //Параметры мирового окна



void zadanie2(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("LW2_CopmuterGraphics_Ex2");
	glutDisplayFunc(drawFigure);
	init2();
	glutMainLoop();

}

void init2(void) {
	h = w / R; l = -w / 2; r = w / 2; b = -h / 2; t = h / 2; //Расчет параметров мирового окна
	glClearColor(0.45, 0.48, 0.52, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(l, r, b, t);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void showAxis(void)
{
	glColor4f(0, 0, 1, 0.5);
	glEnable(GL_LINE_STIPPLE);// Открываем режим рисования линий
	glLineStipple(2, 0X00FF);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0, t);
		glVertex2f(0, 0);
		glVertex2f(r, 0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}
void fig0(void)
{
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 10.0);
		glVertex2f(10.0, 10.0);
		glVertex2f(10.0, 0.0);
	glEnd();
}

void fig1(void) {

	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(0.0, 5.0);
		glVertex2f(10.0, 0.0);
		glVertex2f(0.0, -5.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(5.0, 2.5);
		glVertex2f(5.0, -2.5);
		glVertex2f(2.0, -2.5);
		glVertex2f(2.0, 2.5);
	glEnd();
}


void drawFigure(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i <= 4; i++) {
		glLoadIdentity();
		glRotatef(90 * i, 0, 0, 1);
		fig0();
	}
	showAxis();
	glPopMatrix();
	for (int i = 0; i <= 3; i++) {
		glLoadIdentity();
		glRotatef(90 * i, 0, 0, 1);
		glTranslatef(10, 0, 0);
		fig1();
		showAxis();
	}
	glPushMatrix();
	

	
	glutSwapBuffers();
}