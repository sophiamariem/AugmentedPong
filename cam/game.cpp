#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <time.h>
#include <ctime>

#include "game.h"

using namespace std;

Game* game4;


float y = 0.0; //y coord on left paddle (2 provide movement)
float pY = 0.0; //y coord on right paddle (2 provide movement)
float bpX = 0.0; //x coord on bottom paddle (2 provide movement)
float tpX = 0.0; //x coord on top paddle (2 provide movement)

float xdir = 1.0; //x speed and direction of ball
float ydir = 1.0; //y speed and direction of ball

GLfloat bX = 20.0f; //x pos of ball
GLfloat bY = 0.0f; //y pos of ball

//scores
int compScore = 0;
int plScore = 0;
int playerTeam = 0;
int compTeam = 0;

bool gameOver=false;
bool zero = true;

bool menuStart;


//create menu and initialize menuItem to 0 once
void Game::Menu() {
	createMenu();
	if (zero==true && menuItem==0){
		zero = false;
		game4->menuItems(menuItem);}
}

//initialize methods that are to be displayed

void Game::Control() {
	leftPaddle(y);
	rightPaddle(pY);
	Ball(bX, bY);
	drawLines();
	moveBall();
	drawState();
	scores(compScore, plScore, compTeam, playerTeam);
}


void Game::One(){
	moveAIPaddle();
}

void Game::Four(){
	leftPaddle(y);
	rightPaddle(pY);
	topPaddle(tpX);
	bottomPaddle(bpX);
	Ball(bX, bY);
	drawLines();
	moveHorPaddles();
	moveBall();
	scores(compScore, plScore, compTeam, playerTeam);
}

//Create left paddle
void Game::leftPaddle(float y) {
	
	glPushMatrix();
	glBegin(GL_QUADS);

	//front
	glColor3f(0.5f, 0.0f, 0.3f);
	glVertex2f(cfx1, cfy2+y); //x1 y1
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(cfx2, cfy2+y); //x2 y1
	glColor3f(0.0f, 0.25f, 0.5f);
	glVertex2f(cfx2, cfy1+y); //x2 y2
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex2f(cfx1, cfy1+y); //x1 y2

	//up
	glColor3f(0.5f, 0.0f, 0.3f);
	glVertex2f(cfx1, cfy2+y); //x1 y1
	glVertex2f(cfx2, cfy2+y); //x2 y1
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(cux2, cuy1+y); //x2 y2
	glVertex2f(cux1, cuy1+y); //x1 y2

	//left
	glColor3f(0.5f, 0.0f, 0.3f);
	glVertex2f(cfx1, cfy2+y); //x1 y1
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(cux1, cuy1+y); //x2 y1
	glColor3f(0.0f, 0.25f, 0.5f);
	glVertex2f(cux1, (cfy1+7)+y); //x2 y2
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex2f(cfx1, cfy1+y); //x1 y2

	glEnd();
	glPopMatrix();

}

//Create right paddle
void Game::rightPaddle(float pY) {
	
	glPushMatrix();
	glBegin(GL_QUADS);

	//front
	glColor3f(0.0f, 0.25f, 0.5f);
	glVertex2f(pfx2, pfy2+pY); //x2 y1
	glColor3f(0.0f, 0.0f, 0.5f);	
	glVertex2f(pfx1, pfy2+pY); //x1 y1
	glColor3f(0.5f, 0.0f, 0.3f);
	glVertex2f(pfx1, pfy1+pY); //x1 y2
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(pfx2, pfy1+pY); //x2 y2

	//down
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(pbx1+2, pby2+pY); //x1 y2
	glVertex2f(pbx2+2, pby2+pY); //x2 y2
	glColor3f(0.5f, 0.0f, 0.3f);
	glVertex2f(pfx2, pfy1+pY); //x2 y1	
	glVertex2f(pfx1, pfy1+pY); //x1 y1	

	//right
	glColor3f(0.0f, 0.0f, 0.5f);	
	glVertex2f(pbx2+2, (pfy2-7)+pY); //x2 y1
	glColor3f(0.0f, 0.25f, 0.5f);
	glVertex2f(pfx2, pfy2+pY); //x1 y1
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(pfx2, (pby2+7)+pY); //x1 y2
	glColor3f(0.5f, 0.0f, 0.3f);
	glVertex2f(pbx2+2, pby2+pY); //x2 y2

	glEnd();
	glPopMatrix();
}


//Create top paddle
void Game::topPaddle(float tpX) {
	
	glPushMatrix();
	glBegin(GL_QUADS);

	//front
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(thx2+tpX, thy1); //x2 y1
	glColor3f(0.0f, 0.0f, 0.5f);	
	glVertex2f(thx1+tpX, thy1); //x1 y1
	glVertex2f(thx1+tpX, thy2); //x1 y2
	glColor3f(0.6f, 0.1f, 0.3f);
	glVertex2f(thx2+tpX, thy2); //x2 y2

	//up
	glColor3f(0.0f, 0.25f, 0.5f);	
	glVertex2f((thx1-7)+tpX, thy1+7); //x1 y2
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f((thx2-7)+tpX, thy1+7); //x2 y2
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(thx2+tpX, thy1); //x2 y1	
	glColor3f(0.0f, 0.0f, 0.5f);	
	glVertex2f(thx1+tpX, thy1); //x1 y1	

	//left
	glColor3f(0.0f, 0.0f, 0.5f);	
	glVertex2f(thx1+tpX, thy1); //x2 y1
	glVertex2f((thx1-7)+tpX, thy1+7); //x1 y1
	glVertex2f((thx1-7)+tpX, thy2+7); //x1 y2
	glVertex2f(thx1+tpX, thy2); //x2 y2

	glEnd();
	glPopMatrix();
}

//Create bottom paddle
void Game::bottomPaddle(float bpX) {//float botx
	
	glPushMatrix();
	glBegin(GL_QUADS);

	//front
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex2f(bhx2+bpX, bhy1); //x2 y1
	glColor3f(0.6f, 0.1f, 0.3f);
	glVertex2f(bhx1+bpX, bhy1); //x1 y1
	glVertex2f(bhx1+bpX, bhy2); //x1 y2
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex2f(bhx2+bpX, bhy2); //x2 y2

	//bottom
	glColor3f(0.6f, 0.1f, 0.3f);
	glVertex2f(bhx1+bpX, bhy2); //x1 y2
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex2f(bhx2+bpX, bhy2); //x2 y2
	glColor3f(0.0f, 0.25f, 0.5f);
	glVertex2f(bhx2+7+bpX, bhy2-7); //x2 y1		
	glColor3f(0.5f, 0.2f, 0.3f);
	glVertex2f(bhx1+7+bpX, bhy2-7); //x1 y1	

	//right
	glColor3f(0.0f, 0.0f, 0.5f);	
	glVertex2f(bhx2+7+bpX, bhy1-7); //x2 y1
	glVertex2f(bhx2+bpX, bhy1); //x1 y1
	glVertex2f(bhx2+bpX, bhy2); //x1 y2
	glVertex2f(bhx2+7+bpX, bhy2-7); //x2 y2

	glEnd();
	glPopMatrix();
}

//create ball
void Game::Ball(GLfloat bX, GLfloat bY){

	glPushMatrix();
	glTranslatef(bX, bY, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.6f, 0.38f);
	float c = 20.0;
	for (int i = 0; i < 1000; i++)
	{
		glVertex3d(14.0*cos(c*i),14.0*sin(c*i),0.2f);
	}
	glEnd();
	glPopMatrix(); 
}


//draw dividing line
void Game::drawLines(){

	glPushMatrix();
	float i=0;

	glLineWidth(2);
	glEnable(GL_LINE_SMOOTH);

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(500.0 ,0.0);
	for ( ; i<=600.0f; i++ ){
		i+=4.0f;
		glVertex2f(500.0 ,i);}
	glEnd();
	glPopMatrix(); 
}


//do scores by calling appropriate method
void Game::scores( int &compScore, int &plScore, int &compTeam, int &playerTeam )
{

	if ( menuItem == 1 || menuItem == 2 ){

		game4->doScores(compScore, plScore);
		game4->doGameOver(compScore, plScore);

	}

	else if (menuItem == 3) {

		game4->doTeamScores(compTeam, playerTeam);
		game4->doTeamGameOver(compTeam, playerTeam);

	}

}

//display which state is currently in progress
void Game::drawState(){

	int i, sizefor1, sizefor2;

	if (menuItem == 1)
	{
		char *state1 = "This is the 1-player Game";
		glRasterPos2f(402, 585); 
		sizefor1 = (int) strlen(state1);
		for (i = 0; i < sizefor1; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, state1[i]);}
	}

	if (menuItem == 2)
	{
		char *state2 = "This is the 2-player Game";
		glRasterPos2f(402, 585); 
		sizefor2 = (int) strlen(state2);
		for (i = 0; i < sizefor2; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, state2[i]);}
	}

}


//move right player according to the position of the red object
void Game::moveRedPlayer(int &yRedCont, int &yyRedCont){

	if ( (pfy2+pY) < 600.0f) {
		if ( yRedCont < yyRedCont )
		{
			pY += 80.0;
		}
	}

	if ( (pby2+pY) > 0.0f) {
		if ( yRedCont > yyRedCont )
		{		
			pY -= 80.0;
		}
	}

	if  ((pby2+pY)== -80.0f)
	{
		pY+=80.0f;
	}

	if ((pfy2+pY) == 680.0f)
	{
		pY-=80.0f;
	}

}

//get random number to assign a random speed to the paddles as to allow them to miss ball
float getRandom(){	

	srand((unsigned)time(NULL));

	//generate a specific random number (until 9.0 from 1.0)
	float r = (float)(( rand() %9 ) + 1);
	float v= ( r/10 );

	return v;

}

//move left computer paddle
void Game::moveAIPaddle(){

	float v = getRandom();

	//move up
	if ( (cuy1+y) < bY)
	{
		y+= +v * 3.95; //6.25f;
	}

	//move down
	if ( (cfy1+y) > bY)
	{
		y-= +v * 3.95; //6.25f;
	}

}

//move horizontal paddles
void Game::moveHorPaddles(){

	float v = getRandom();

	//move top
	if (((thx1-7)+tpX)>=0.0f) {
		//move left
		if  ( bX< ((thx1-7)+tpX) ) 
		{
			tpX-= +v * 3.72;//11.0f;
		}

	}

	//move bottom
	if ((bhx1+bpX)>=0.0f ) {
		//move left
		if ( bX< (bhx1+bpX) ) 
		{
			bpX-= +v * 3.92;//12.5f;
		}

	}

	//move top
	if ( (thx2+tpX)<=1000.0f){
		//move right
		if ( bX> (thx2+tpX) )
		{
			tpX+= +v* 3.98; //11.25f;
		}
	}

	//move bottom
	if (((bhx2+7)+bpX)<=1000.0f){
		//move right
		if ( bX> ((bhx2+7)+bpX) ) 
		{
			bpX+= +v * 3.83;//10.5f;
		}
	}



	//if out of bounds
	if  ((thx1-7+tpX)<=-80.0f) {
		tpX=0.0f;
	}


	if ((bhx1+bpX)<=-80.0f) {
		bpX=0.0f;
	}
	if ((thx2+tpX)>=1080.0f) {

		tpX=878.0f;
	}

	if ((bhx2+7+bpX)==1080.0f) {
		bpX=878.0f;
	}


}

//move left player according to the position of the yellow object
void Game::moveYellowPaddle(int &yYellow, int &yyYellow){

	if ( (cuy1+y) <= 600.0f)
	{
		if (yYellow < yyYellow)
		{
			y+= 80.0f;
		}
	}

	if ( (cfy1+y)>= 0.0f)
	{
		if (yYellow > yyYellow)
		{		
			y-= 80.0f;
		}
	}

	if  ((cfy1+y)== -80.0f){
		y+=80.0f;
	}
	if ((cuy1+y) == 680.0f){
		y-=80.0f;
	}

}


//move ball and do collision detection
void Game::moveBall(){

	int i=0;
	int j=0;

	//update ball direction and speed
	bX+= xdir;
	bY+= ydir;

	//initial ball position
	if ( bY <= 1 )
	{
		bX = 500.0;
		bY = 300.0;
		xdir = speedplus;
		ydir = speedplus;
	}


	/**********************collision with window borders **********************/

	//right border
	if ( bX >= 985.0 ) //window width-radius
	{
		if ( menuItem == 3){
			compTeam++;
		}
		xdir= speedminus;
		compScore++;

		//update ball position in center of window
		if ( bY >= 300.0 && i<2 ) //center of window
		{
			xdir = speedminus;
			ydir = speedminus;
			i++;
		}
		else 
			xdir = speedplus;
		bX = 500.0;
	}

	//left border
	else if (bX <= radius) 
	{
		if ( menuItem == 3){
			compTeam++;
		}
		xdir= speedplus;
		plScore++;

		//update ball position in center of window
		if (bY >= 300.0 && j>2 )
		{
			xdir = speedminus;
			ydir = speedplus;
			j++;
		}
		else 
			xdir = speedplus;
		bX = 500.0;
	}


	//top border
	if(bY >= 585.0) //window height-radius
	{
		if ( menuItem == 3){
			playerTeam++;
		}
		ydir = speedminus;
	}

	//bottom border
	else if (bY <= radius){
		if ( menuItem == 3){
			playerTeam++;
		}
		ydir = speedplus;
	}


	/**********************collision with paddles**********************/


	if ( menuItem == 3 ){
		//top paddle
		if ( (bY <= (thy2-radius)) && (bY >= (thy2-radius-1)) && (bX >= ((thx1-7)+tpX)) && (bX <=(thx2+tpX)) )
		{
			ydir = speedminus;
		}

		//bottom paddle
		if ( (bY >= (bhy1+radius)) && (bY <= (bhy1+radius+1)) && (bX >= (bhx1+bpX)) && (bX <= ((bhx2+7)+bpX)) )
		{
			ydir = speedplus;
		}
	}

	//left paddle ---- left side
	if ( (bX <= (cfx2+radius) ) && ( (cfy1+y) <= bY ) && ( bY <= (cfy2+7+y) ) )
	{
		xdir = speedplus;
	}

	//right paddle ---- right side
	if ( ( bX >=(pfx1-radius) ) && ( ((pfy1-7)+pY) <=bY ) && ( bY <= (pfy2+pY) ) ) 
	{
		xdir = speedminus;
	}

	//top of left paddle
	if ( (bX >=cux1) && ( bX <= (cux2+7) ) && ( bY >= ((cuy1+radius-1) +y) ) && ( bY <= ((cuy1+radius) +y)) )
	{
		ydir = speedplus;
		xdir = speedplus;
	}

	//top of right paddle
	if ( (bX >= pfx1) && ( bX <= pfx2 ) && ( bY >= ((pfy1+radius -1) +pY) ) && ( bY <= (pfy1+radius +pY) ) )
	{
		ydir = speedplus;
		xdir = speedminus;
	}

	//bottom of left paddle
	if ( (bX >=cfx1) && ( bX <=cfx2 ) && ( bY >= ((cfy2-radius) +y) ) && ( bY <= ((cfy2-radius+1) +y) ) )
	{
		ydir = speedminus;
		xdir = speedplus;
	}

	//bottom of right paddle
	if ( (bX >=(pbx1-7) ) && ( bX <= pbx2) && ( bY >=((pby2-radius) +pY) ) && ( bY <=((pby2-radius +1) +pY) ) )
	{
		ydir = speedminus;
		xdir = speedminus;
	}


}


//destructor
Game::~Game(){

	y = 0.0; //y coord on left paddle (2 provide movement)
	pY = 0.0; //y coord on right paddle (2 provide movement)
	bpX = 0.0; //x coord on bottom left paddle (2 provide movement)
	tpX = 0.0; //x coord on top left paddle (2 provide movement)

	xdir = 0.0; //x speed and direction of ball
	ydir = 0.0; //y speed and direction of ball

	GLfloat bX = 0.0f; //x pos of ball
	GLfloat bY = 0.0f; //y pos of ball

	compScore = 0;
	plScore = 0;
	playerTeam = 0;
	compTeam = 0;

	gameOver=false;

	menuStart=false;


}