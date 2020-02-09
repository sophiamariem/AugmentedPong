#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "game.h"

using namespace std;

//create Help content
void Game::Help(){

	int i, h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15, h16, h17, h18, h19, h20, h21, h22;

	glColor3f(1.0f, 0.0f, 1.0f);

	char *in1 = "Welcome to PONG AUGMENTED !";
	glRasterPos2f(400, 570);
	h1 = (int) strlen(in1);
	for (i = 0; i < h1; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, in1[i]);}

	glColor3f(1.0f, 1.0f, 1.0f);

	char *in2 = "This game has 3 modes: One-Player Mode, Two-Player Mode and Four-Player Mode. To access these modes you will have to use your desired RED object.";
	glRasterPos2f(5, 520);
	h2 = (int) strlen(in2);
	for (i = 0; i < h2; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in2[i]);} 

	char *in3 = "For the One-Player mode please hold your red object at the top left, for the Two-Player mode at the bottom left and for the Four-Player mode at the top right (same as the Menu";
	glRasterPos2f(5, 495);
	h3 = (int) strlen(in3);
	for (i = 0; i < h3; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in3[i]);}

	char *in4 = "Items positions on the Menu screen! ).";
	glRasterPos2f(5, 480);
	h4 = (int) strlen(in4);
	for (i = 0; i < h4; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in4[i]);}

	char *in5 = "There are also two other menu options as you may have noticed on the Menu screen. These are: Exit and Instructions/Help. The latter refers to this section while the former";
	glRasterPos2f(5, 465);
	h5 = (int) strlen(in5);
	for (i = 0; i < h5; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in5[i]);}

	char *in6 = "exits the game.";
	glRasterPos2f(5, 450);
	h6 = (int) strlen(in6);
	for (i = 0; i < h6; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in6[i]);}

	glColor3f(1.0f, 0.0f, 1.0f);
	char *in17 = "ONE-PLAYER MODE:";
	glRasterPos2f(5, 420);
	h17 = (int) strlen(in17);
	for (i = 0; i < h17; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in17[i]);}

	glColor3f(1.0f, 1.0f, 1.0f);
	char *in7 = "The One-player mode is when your are playing against the computer. You control the paddle on the right by moving your red object up and/or down depending on the direction";
	glRasterPos2f(5, 405);
	h7 = (int) strlen(in7);
	for (i = 0; i < h7; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in7[i]);}

	char *in8 = "you want your paddle to move while the computer controls the paddle on the left.";
	glRasterPos2f(5, 390);
	h8 = (int) strlen(in8);
	for (i = 0; i < h8; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in8[i]);}

	char *in20 = "You score a point when the computer misses the ball and if you miss the ball the computer scores a point.";
	glRasterPos2f(5, 375);
	h20 = (int) strlen(in20);
	for (i = 0; i < h20; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in20[i]);}

	glColor3f(1.0f, 0.0f, 1.0f);
	char *in18 = "TWO-PLAYER MODE:";
	glRasterPos2f(5, 345);
	h18 = (int) strlen(in18);
	for (i = 0; i < h18; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in18[i]);}

	glColor3f(1.0f, 1.0f, 1.0f);
	char *in9 = "You can also invite a friend to play and choose the Two-player mode where you still control the right paddle with your red object and your friend controls the left paddle";
	glRasterPos2f(5, 330);
	h9 = (int) strlen(in9);
	for (i = 0; i < h9; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in9[i]);}

	char *in10 = "with a yellow object again by moving it up and/or down. Points are scored as with the One-Player mode game.";
	glRasterPos2f(5, 315);
	h10 = (int) strlen(in10);
	for (i = 0; i < h10; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in10[i]);}


	glColor3f(1.0f, 0.0f, 1.0f);
	char *in19 = "FOUR-PLAYER MODE:";
	glRasterPos2f(5, 285);
	h19 = (int) strlen(in19);
	for (i = 0; i < h19; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in19[i]);}

	glColor3f(1.0f, 1.0f, 1.0f);

	char *in11 = "The Four-Player mode is similar to the Two-Player mode as you play with a friend again one controlling the right paddle with the red object and the left paddle with a";
	glRasterPos2f(5, 270);
	h11 = (int) strlen(in11);
	for (i = 0; i < h11; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in11[i]);}

	char *in12 = "yellow object. However, you and your friend now play as a team against two computer paddles which are situated horizontally on the top and bottom of the screen.";
	glRasterPos2f(5, 255);
	h12 = (int) strlen(in12);
	for (i = 0; i < h12; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in12[i]);}

	char *in13 = "If one of the computer paddles misses the ball you and your friend score, whilst if you or you friend misses the ball, the computer scores.";
	glRasterPos2f(5, 240);
	h13 = (int) strlen(in13);
	for (i = 0; i < h13; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in13[i]);}


	char *in14 = "All games end when one user or team scores 15 points! At this point you can return to the Main Menu and select another mode or exit.";
	glRasterPos2f(5, 195);
	h14 = (int) strlen(in14);
	for (i = 0; i < h14; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in14[i]);}

	char *in15 = "At any point of any game-mode you may choose to pause/resume the current game, exit, retrun to the Main Menu or access this section by right-clicking on the game window.";
	glRasterPos2f(5, 180);
	h15 = (int) strlen(in15);
	for (i = 0; i < h15; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in15[i]);}

	char *in22 = "Please remember however that you can only resume the game, while in the game and not after you have left the game-mode for the Back to Menu or Help Options.";
	glRasterPos2f(5, 165);
	h22 = (int) strlen(in22);
	for (i = 0; i < h22; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in22[i]);}

	char *in21 = "P.S. A small hack: To make the ball speed faster, right-click while in a game-mode!";
	glRasterPos2f(5, 145);
	h21 = (int) strlen(in21);
	for (i = 0; i < h21; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, in21[i]);}

	char *in16 = "Hope you enjoy PONG AUGMENTED!";
	glRasterPos2f(377, 30);
	h16 = (int) strlen(in16);
	for (i = 0; i < h16; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, in16[i]);}
}