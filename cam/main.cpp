#include <GL/glut.h>
#include <GL/freeglut.h>
#include <pthread.h>

#pragma comment(lib,"pthreadVC2.lib")
#pragma comment(lib,"pthreadVCE2.lib")
#pragma comment(lib,"pthreadVSE2.lib")
//#include <cxcore.h> 
#include <iostream>

#include "game.h"

static int window;

Game* game2;

bool restart = false;
int previousmenuItem = 0;
bool gameDone = false;
bool gameDone2 = false;

bool active = false;


void* glutLoop(void* arg)
{
	glutMainLoop();	
	return NULL;
}


void Escape(unsigned char key, int x, int y) { //when Escape is pressed exit
	switch (key) {
	case 27:
		//exit(0);
		//glutLoop(NULL);
		gameOver=true;
		glutDestroyWindow(window);
		exit(0);
		break;
	}
}


void Resize(int w, int h) {
	glViewport(0, 0, w, h);	//convert from coordinates to pixel values
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glMatrixMode(GL_MODELVIEW);  //switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
}


void viewAll(){

	Display();
	game2->Control();
	glutSwapBuffers();

}


void mOne() {
	game2->One();
	viewAll();
}


void mFour() {
	Display();
	game2->Four();	
	glutSwapBuffers();
}

void mHelp(){
	Display();
	game2->Help();
	glutSwapBuffers();
}

// Pop-up Menu items
enum gameMenu
{
	mainMenu,
	Pause,
	Resume,
	Exit,
	Instructions,
};

void backtoMenu(){

	Display();
	game2->DrawMenuText();
	game2->Menu();
	game2->PongText();
	glutSwapBuffers();

	menuItem=0;
	menuStart=true;

	if (active == true)
		game2->menuItems(menuItem);
}

void viewMenu(){

	Display();
	game2->DrawMenuText();
	game2->Menu();
	game2->PongText();
	glutSwapBuffers();
	game2->menuItems(menuItem);
}

void Game::menuItems(int &menuItem){


	if ( menuItem==0){
		menuStart=true;
		glutDisplayFunc(viewMenu);
		glutIdleFunc(viewMenu);
		//glutPostRedisplay();
	}

	//1-player
	if( menuItem==1){
		menuStart=false;
		if (previousmenuItem ==2 ) {
			compScore = 0;
			plScore = 0;
		}
		if ( (previousmenuItem == 1 ) && (gameDone == true) ){
			compScore = 0;
			plScore = 0;
			gameDone=false;
		}
		glutDisplayFunc(mOne);
		glutIdleFunc(mOne);
		previousmenuItem=1;

	}

	//2-=player
	else if (menuItem==2){
		menuStart=false;
		if (previousmenuItem == 1 ) {
			compScore = 0;
			plScore = 0;
		}
		if ( (previousmenuItem == 2 ) && (gameDone == true) ){
			compScore = 0;
			plScore = 0;
			gameDone=false;
		}
		glutDisplayFunc(viewAll);
		glutIdleFunc(viewAll);
		previousmenuItem=2;

	}

	//4-player
	else if (menuItem==3){
		menuStart=false;
		if ( (previousmenuItem == 3 ) && (gameDone2 == true) ){
			compTeam = 0;
			playerTeam = 0;
			gameDone2=false;
		}
		glutDisplayFunc(mFour);
		glutIdleFunc(mFour);
		previousmenuItem=3;
	}

	//Esc
	else if (menuItem==4){
		menuStart=false;
		//exit(0);
		//glutLeaveMainLoop();
		gameOver=true;
		glutDestroyWindow(window);
		exit(0);
	}

	//Help
	else if (menuItem==5){
		glutDisplayFunc(mHelp);
		glutIdleFunc(mHelp);
		menuStart=false;
	}

	//Preview Main Menu again
	else if (menuItem==6){
		glutDisplayFunc(backtoMenu);
		glutIdleFunc(backtoMenu);
	}
}





void initRender() { //initialize OpenGL rendering
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1000,0,600);
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.192f, 0.153f, 0.208f, 1.0f); 

}

void* camera(void* arg){
	game2->initCam(arg);
	return NULL;
}

//initialize and display Menu
void initMenu() {

	menuStart=true;
	glutDisplayFunc(viewMenu);
	glutIdleFunc(viewMenu);

}



//add menu items
void addMenu(){
	glutAddMenuEntry("Back to Main Menu", mainMenu);
	glutAddMenuEntry("Pause Game", Pause);
	glutAddMenuEntry("Resume Game", Resume);
	glutAddMenuEntry("Exit Game", Exit);
	glutAddMenuEntry("Instructions/Help", Instructions);
}


// pop-up menu
void menu(int item)
{

	if (item == mainMenu) {

		menuItem=6;
		menuStart=true;
		game2->menuItems(menuItem);
		glutPostRedisplay();
	}

	else if (item == Pause) {

		glutIdleFunc(NULL);
		glutPostRedisplay();
	}

	else if( (item == Resume) && ( (previousmenuItem == 1) ||(previousmenuItem == 2)  || (previousmenuItem == 3) ) && ((menuItem == 1) ||(menuItem == 2)  || (menuItem == 3) ) ) {	
		game2->menuItems(previousmenuItem);
		glutPostRedisplay();
	}

	else if( (item == Resume) && ( (menuItem != 1) ||(menuItem != 2)  || (menuItem != 3) )) {	
		game2->menuItems(menuItem);
		glutPostRedisplay();
	}

	else if (item == Exit) {
		//exit(1);
		//glutMainLoop();
		//exit(0);
		gameOver=true;
		glutDestroyWindow(window);
		exit(0);
	}

	else if (item == Instructions){

		menuItem=5;
		game2->menuItems(menuItem);
		glutPostRedisplay();
	}

	else //default
		glutPostRedisplay();
	

	glutPostRedisplay();

}


void initGlut(int argc, char** argv) {
	
	glutInit(&argc, argv); //initialize glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //display mode
	glutInitWindowPosition(140, 100); //window position on screen
	glutInitWindowSize(1000, 600); //window size (x,y)

	window = glutCreateWindow("Pong"); //create the window and name it Pong

	initRender();
	initMenu();

	glutKeyboardFunc(Escape);
	glutReshapeFunc(Resize);
	glutCreateMenu(menu); //create pop-up menu

	addMenu();

	glutAttachMenu(GLUT_RIGHT_BUTTON); //make pop-up menu available when right-click

	glutPostRedisplay();
}




int main(int argc, char** argv) {

	initGlut(argc,argv);
	pthread_t tId;
	pthread_attr_t tAttr;
	pthread_attr_init(&tAttr);

	pthread_create(&tId, &tAttr, camera, NULL);
	glutLoop(NULL);

	return 0;
}