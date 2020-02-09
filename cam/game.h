#include <GL/glut.h>

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

extern bool gameOver;
extern bool menuStart;
extern bool gameDone;
extern bool gameDone2;

extern int menuItem;
extern int previousmenuItem;


//scores
extern int compScore;
extern int plScore;
extern int playerTeam;
extern int compTeam;

//ball's speed values
static const float speedplus= 1.75;//3.0
static const float speedminus= -1.75;

//drawing values
static const float radius= 15.0; //ball size

//---------------vertical------------------
static const float cfx1= 14.0; //front of left paddle x1
static const float cfx2= 44.0; //front of left paddle x2

static const float cfy1= 0.0; //73.0; //front of left paddle y1
static const float cfy2= 113.0; //210.0; //front of left paddle y2

static const float pfy1= 7.0; //73.0; //front of right paddle y1
static const float pfy2= 120.0; //210.0; //front of right paddles y2

static const float cux1= 4.0; //top of left paddle x1 from x1y2
static const float cux2= 37.0; //top of left paddle x2 from x2y2
static const float cuy1= 120.0; //top of left paddle y1


static const float pfx1= 956.0; //front of right paddle x1
static const float pfx2= 986.0; //front of right paddle x2

static const float pbx1= 963.0; //bottom of right paddle x1
static const float pbx2= 993.0; //bottom of right paddle x2
static const float pby2= 0.0; //bottom of right paddle y2


//---------------horizontal------------------
static const float thx1= 7.0; //231.0; //front of top horizontal paddle x1
static const float thx2= 120.0; //368.0; //front of top horizontal paddle x2

static const float bhx1= 0.0; //231.0; //front of bottom horizontal paddle x1
static const float bhx2= 113.0; //368.0; //front of bottom horizontal paddle x2

static const float thy1= 586.0; //top paddle's y1
static const float thy2= 556.0; //top paddle's y2

static const float bhy1= 44.0; //bottom paddle's y1
static const float bhy2= 14.0; //bottom paddle's y2


class Game {

public : 

	//GLUT Controls
	void Control();
	void Escape(unsigned char, int, int); 
	void Resize(int, int);

	//Menu Actions
	void createMenu();
	void PongText();
	void Menu();
	void One();
	void Four();
	void Help();
	void doMenuAction();
	void menuItems(int &);


	//Game Design
	void leftPaddle(float);
	void rightPaddle(float);
	void topPaddle(float);
	void bottomPaddle(float);
	void Ball(GLfloat, GLfloat);
	void drawLines();
	void DrawMenuText();
	void drawState();

	//Methods that Provide Movement
	void moveAIPaddle();
	void moveRedPlayer(int&, int&);
	void moveYellowPaddle(int&, int&);
	void moveHorPaddles();
	void moveBall();

	//Scores
	void scores(int&, int&, int&, int&);
	void doScores(int& , int&);
	void doTeamScores(int& , int&);
	void doGameOver(int& , int&);
	void doTeamGameOver(int& , int&);

	//Camera
	void* initCam(void*);

	//cleanup
	~Game();

};


#endif