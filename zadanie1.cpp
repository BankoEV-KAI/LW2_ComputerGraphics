#include "zadania.h"

float angle = 0;
float rotationSpeed = 0.01;
int spiralDirection = 1;

void zadanie1(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("LW2_CompuerGraphics_Ex1");

    init();

    glutDisplayFunc(draw);
    glutTimerFunc(25, rotation, 0);

    glutMainLoop();

}

void init() {
    glClearColor(0.45, 0.48, 0.52, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    drawSpiral();

    float radius = 0.1 * angle;
    float x = radius * cos(angle);
    float y = radius * sin(angle);

    glPushMatrix();
    glTranslatef(x, y, 0);
    drawStar();
    glPopMatrix();

    glutSwapBuffers();
}

void drawStar() {
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);  

    for (int i = 0; i <= 5; ++i) {
        float theta = static_cast<float>(i * 4 + 1) * M_PI / 5;
        float x = 0.1 * cos(theta);
        float y = 0.1 * sin(theta);
        glVertex2f(x, y);
    }

    glEnd();
}

void drawSpiral() {
    glColor3f(1, 1, 1);
   
    glBegin(GL_LINE_STRIP);

    for (float t = 0; t <= 10; t += 0.01) {
        float radius = 0.1 * t;
        float x = radius * cos(t);
        float y = radius * sin(t);
        glVertex2f(x, y);
    }

    glEnd();
}

void rotation(int value) {
    angle += rotationSpeed * spiralDirection;

    if (angle >= 10 || angle <= 0) {
        spiralDirection *= -1;
    }

    glutPostRedisplay();
    glutTimerFunc(16, rotation, 0);
}