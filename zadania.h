#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <GL/glut.h>
#include <cmath>



void zadanie1(int argc, char** argv);
void init();
void draw();
void drawStar();
void drawSpiral();
void rotation(int value);
void zadanie2(int argc, char** argv);

void init2();

void reshape(GLsizei W, GLsizei H);

void showAxis(void);

void fig0(void);

void fig1(void);

void scene(void);

void drawFigure(void);
