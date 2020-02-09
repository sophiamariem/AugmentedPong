#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "game.h"


void Game::doScores(int &compScore, int &plScore)
{

	/********************** print out scores **********************/

	glColor3f(80.0f, 0.0f, 0.0f);

	int i, psize, usize, p2size, p3size;

	if (menuItem == 1) {
		char *comp = "Computer :";
		glRasterPos2f(250, 5); 
		psize = (int) strlen(comp);
		for (i = 0; i < psize; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, comp[i]);} }

	if (menuItem == 2) {
		char *pl2 = "Yellow User :";
		glRasterPos2f(240, 5); 
		p2size = (int) strlen(pl2 );
		for (i = 0; i < p2size; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pl2 [i]);} }

	char computerscore[15];
	sprintf_s(computerscore, "%d", compScore);
	glRasterPos2f(355, 5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)computerscore);

	if (menuItem == 1 ){
		char *user = "User :";
		glRasterPos2f(650, 5);
		usize = (int) strlen(user);
		for (i = 0; i < usize; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, user[i]);}}

	if (menuItem == 2) {
		char *pl3 = "Red User :";
		glRasterPos2f(605, 5); 
		p3size = (int) strlen(pl3 );
		for (i = 0; i < p3size; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pl3 [i]);} }

	char playerscore[15];
	sprintf_s(playerscore, "%d", plScore);
	glRasterPos2f(710, 5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)playerscore);
}

void Game::doTeamScores(int &compTeam, int &playerTeam)
{
	int i,compT, plT;

	char *AITeam = "Computer Team :";
	glRasterPos2f(150, 5); 
	compT = (int) strlen(AITeam);
	for (i = 0; i < compT; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, AITeam[i]);}

	char compTScore[15];
	sprintf_s(compTScore, "%d", compTeam);
	glRasterPos2f(305, 5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)compTScore);

	char *userTeam = "User Team :";
	glRasterPos2f(650, 5);
	plT = (int) strlen(userTeam);
	for (i = 0; i < plT; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, userTeam[i]);}

	char plTScore[15];
	sprintf_s(plTScore, "%d", playerTeam);
	glRasterPos2f(760, 5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)plTScore);

}

void showEscape(){
	int i, over;
	glColor3f(1.0f, 0.0f, 1.0f);
	char *esc = "PRESS ESCAPE TO EXIT OR RIGHT-CLICK FOR OTHER OPTIONS!";
	glRasterPos2f(226, 250); 
	over = (int) strlen(esc);
	for (i = 0; i < over; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, esc[i]);}
}



void Game::doGameOver ( int &compScore, int &plScore)
{
	/**********************game over**********************/
	int i, over;

	if ( compScore>=15 || plScore>=15 ) 
	{

		glClear(GL_COLOR_BUFFER_BIT);
		glutIdleFunc(NULL);
		glColor3f(80.0f, 0.0f, 0.0f);

		if (menuItem==1){
			if ( compScore > plScore ){
				char *comp = "GAME OVER! COMPUTER PLAYER WINS!";
				glRasterPos2f(309, 300);
				over = (int) strlen(comp);
				for (i = 0; i < over; i++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, comp[i]);}
			}

			if ( compScore < plScore ){
				char *pl = "GAME OVER! YOU WIN!";
				glRasterPos2f(378, 300);
				over = (int) strlen(pl);
				for (i = 0; i < over; i++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pl[i]);}
			}	
		}

		if (menuItem==2){
			if ( compScore > plScore ){
				char *yel = "GAME OVER! YELLOW PLAYER WINS!";
				glRasterPos2f(309, 300);
				over = (int) strlen(yel);
				for (i = 0; i < over; i++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, yel[i]);}
			}
			if ( compScore < plScore ){
				char *red = "GAME OVER! RED PLAYER WINS!";
				glRasterPos2f(308, 300);
				over = (int) strlen(red);
				for (i = 0; i < over; i++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, red[i]);}
			}	
		}


		showEscape();
		gameDone = true;
	}
}

void Game::doTeamGameOver ( int &compTeam, int &playerTeam )
{
	/**********************game over**********************/
	int i, over;

	if ( playerTeam>=15 || compTeam>=15 ){

		glClear(GL_COLOR_BUFFER_BIT);
		glutIdleFunc(NULL);
		glColor3f(80.0f, 0.0f, 0.0f);

		if ( compTeam > playerTeam ){
			char *cTeam = "GAME OVER! COMPUTER TEAM WINS!";
			glRasterPos2f(324, 300);
			over = (int) strlen(cTeam);
			for (i = 0; i < over; i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cTeam[i]);}
		}

		if ( compTeam < playerTeam ){
			char *pTeam = "GAME OVER! YOUR TEAM WINS!";
			glRasterPos2f(352, 300);
			over = (int) strlen(pTeam);
			for (i = 0; i < over; i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, pTeam[i]);}
		}

		showEscape();
		gameDone2 = true;
	}

}