#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "game.h"

using namespace std;

//draw Main Menu
void Game::createMenu(){

	menuItem = 0;

	glPushMatrix();
	glBegin(GL_QUADS);

	glColor3f(0.96f, 0.76f, 0.16f);

	//Esc
	glVertex2f(970.0, 460.0); //x1 y1
	glVertex2f(770.0, 460.0); //x2 y1
	glVertex2f(770.0, 560.0); //x2 y2
	glVertex2f(970.0, 560.0); //x1 y2

	//4-player
	glVertex2f(30.0, 40.0); //x1 y1
	glVertex2f(230.0, 40.0); //x2 y1
	glVertex2f(230.0, 140.0); //x2 y2
	glVertex2f(30.0, 140.0); //x1 y2

	//2-player
	glVertex2f(770.0, 40.0); //x1 y1
	glVertex2f(970.0, 40.0); //x2 y1
	glVertex2f(970.0, 140.0); //x2 y2
	glVertex2f(770.0, 140.0); //x1 y2

	//1-player
	glVertex2f(30.0, 460.0); //x1 y1
	glVertex2f(230.0, 460.0); //x2 y1
	glVertex2f(230.0, 560.0); //x2 y2
	glVertex2f(30.0, 560.0); //x1 y2

	//Help
	glColor3f(0.96f, 0.96f, 0.5f);

	glVertex2f(400.0, 20.0); //x1 y1
	glVertex2f(600.0, 20.0); //x2 y1
	glVertex2f(600.0, 90.0); //x2 y2
	glVertex2f(400.0, 90.0); //x1 y2

	glEnd();
	glPopMatrix();
}

//draw pong text
void Game::PongText(){

	glPushMatrix();
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);

	//draw P
	//p1
	glVertex2f(300.0, 200.0); //x1 y1
	glVertex2f(330.0, 200.0); //x2 y1
	glVertex2f(330.0, 400.0); //x2 y2
	glVertex2f(300.0, 400.0); //x1 y2

	//p2
	glVertex2f(330.0, 375.0); //x1 y1
	glVertex2f(390.0, 375.0); //x2 y1
	glVertex2f(390.0, 400.0); //x2 y2
	glVertex2f(330.0, 400.0); //x1 y2

	//p3
	glVertex2f(350.0, 300.0); //x1 y1
	glVertex2f(390.0, 300.0); //x2 y1
	glVertex2f(390.0, 375.0); //x2 y2
	glVertex2f(350.0, 375.0); //x1 y2

	//p4
	glVertex2f(330.0, 275.0); //x1 y1
	glVertex2f(390.0, 275.0); //x2 y1
	glVertex2f(390.0, 300.0); //x2 y2
	glVertex2f(330.0, 300.0); //x1 y2

	//draw O
	//o1
	glVertex2f(400.0, 200.0); //x1 y1
	glVertex2f(430.0, 200.0); //x2 y1
	glVertex2f(430.0, 400.0); //x2 y2
	glVertex2f(400.0, 400.0); //x1 y2

	//o2
	glVertex2f(430.0, 400.0); //x1 y1
	glVertex2f(450.0, 400.0); //x2 y1
	glVertex2f(450.0, 375.0); //x2 y2
	glVertex2f(430.0, 375.0); //x1 y2

	//o3
	glVertex2f(430.0, 200.0); //x1 y1
	glVertex2f(450.0, 200.0); //x2 y1
	glVertex2f(450.0, 225.0); //x2 y2
	glVertex2f(430.0, 225.0); //x1 y2

	//o4
	glVertex2f(450.0, 200.0); //x1 y1
	glVertex2f(490.0, 200.0); //x2 y1
	glVertex2f(490.0, 400.0); //x2 y2
	glVertex2f(450.0, 400.0); //x1 y2

	//draw N
	//n1
	glVertex2f(500.0, 200.0); //x1 y1
	glVertex2f(530.0, 200.0); //x2 y1
	glVertex2f(530.0, 400.0); //x2 y2
	glVertex2f(500.0, 400.0); //x1 y2

	//n2
	glVertex2f(530.0, 375.0); //x1 y1
	glVertex2f(565.0, 375.0); //x2 y1
	glVertex2f(565.0, 400.0); //x2 y2
	glVertex2f(530.0, 400.0); //x1 y2

	//n3
	glVertex2f(565.0, 200.0); //x1 y1
	glVertex2f(590.0, 200.0); //x2 y1
	glVertex2f(590.0, 400.0); //x2 y2
	glVertex2f(565.0, 400.0); //x1 y2

	//draw G
	//g1
	glVertex2f(600.0, 200.0); //x1 y1
	glVertex2f(630.0, 200.0); //x2 y1
	glVertex2f(630.0, 400.0); //x2 y2
	glVertex2f(600.0, 400.0); //x1 y2

	//g2
	glVertex2f(630.0, 380.0); //x1 y1
	glVertex2f(680.0, 380.0); //x2 y1
	glVertex2f(680.0, 400.0); //x2 y2
	glVertex2f(630.0, 400.0); //x1 y2

	//g3
	glVertex2f(630.0, 200.0); //x1 y1
	glVertex2f(700.0, 200.0); //x2 y1
	glVertex2f(700.0, 225.0); //x2 y2
	glVertex2f(630.0, 225.0); //x1 y2

	//g4
	glVertex2f(685.0, 225.0); //x1 y1
	glVertex2f(700.0, 225.0); //x2 y1
	glVertex2f(700.0, 290.0); //x2 y2
	glVertex2f(685.0, 290.0); //x1 y2

	//g5
	glVertex2f(660.0, 270.0); //x1 y1
	glVertex2f(685.0, 270.0); //x2 y1
	glVertex2f(685.0, 290.0); //x2 y2
	glVertex2f(660.0, 290.0); //x1 y2

	glEnd();
	glPopMatrix();
}

void Game::DrawMenuText()
{

	glColor3f(0.49f, 0.13f, 1.0f);

	int i, one, two, four, esc, descr, help;

	char *onepl = "One-Player Game";
	glRasterPos2f(58, 510);
	one = (int) strlen(onepl);
	for (i = 0; i < one; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, onepl[i]);}


	char *twopl = "Two-Player Game";
	glRasterPos2f(55, 90);
	two = (int) strlen(twopl);
	for (i = 0; i < two; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, twopl[i]);}

	char *fourpl = "Four-Player Game";
	glRasterPos2f(799, 510);
	four = (int) strlen(fourpl);
	for (i = 0; i < four; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, fourpl[i]);}


	char *escp = "Exit Game";
	glRasterPos2f(830, 90);
	esc = (int) strlen(escp);
	for (i = 0; i < esc; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, escp[i]);}

	char *instruct = "Instructions/Help";
	glRasterPos2f(430, 55);
	help = (int) strlen(instruct );
	for (i = 0; i < help; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, instruct[i]);}

	glColor3f(1.0f, 0.0f, 1.0f);
	char *desc = "A U G M E N T E D !";
	glRasterPos2f(528, 170);
	descr = (int) strlen(desc);
	for (i = 0; i < descr; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, desc[i]);}


}