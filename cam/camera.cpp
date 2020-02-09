#include <cv.h>
#include <highgui.h>
//#include <iostream>
//#include <stdlib.h>
//#include <cstdlib>

#include "game.h"

using namespace std;

Game* game;

int xRedCont = 0; //new x position of Red object
int yRedCont = 0; //new y position of Red object
int yyRedCont = 0; //old y position of Red object
int xxRedCont = 0; //old x position of Red object

int xYellowCont=0; //new x position of Yellow object
int yYellowCont=0; //new y position of Yellow object
int yyYellowCont=0; //old y position of Yellow object
int xxYellowCont=0;//old x position of Yellow object

int width=0; //box width
int height=0; //box height

int menuItem; //selected menu option






//get Red Thresholded image
IplImage* threshRed(IplImage* img)
{
	//create image
	IplImage* imgThreshold = NULL;
	imgThreshold = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);
	cvInRangeS(img, cvScalar(170, 110, 90), cvScalar(180, 255, 255),imgThreshold);
	return imgThreshold;
	cvReleaseImage (&imgThreshold);
}


//get Yellow Thresholded image
IplImage* threshYellow(IplImage* imgHSV)
{
	//create image
	IplImage* imgThresholdYellow = NULL;
	imgThresholdYellow = cvCreateImage(cvGetSize(imgHSV), IPL_DEPTH_8U, 1);
	//do thresholding by specifying the color range to be extracted from frame

	//cvInRangeS(imgHSV, cvScalar(20, 100, 100), cvScalar(30, 255, 255),imgThresholdYellow);//20,150
	cvInRangeS(imgHSV, cvScalar(21, 127, 127), cvScalar(70, 255, 255),imgThresholdYellow);
	return imgThresholdYellow;
	cvReleaseImage (&imgThresholdYellow);
}

//Menu Action based on position of Red Object
void Game::doMenuAction(){

	if ( yRedCont >= 100 && yRedCont <= 200 && xRedCont >= 400 && xRedCont <= 500 ){
	//if ( yRedCont >= 1 && yRedCont <= 100 && xRedCont >= 200 && xRedCont <= 300 ){
		menuItem=1;
	}
	else if ( yRedCont >= 300 && yRedCont <= 400 && xRedCont >= 400 && xRedCont <= 500  ){
	//else if ( yRedCont >= 200 && yRedCont <= 300 && xRedCont >= 200 && xRedCont <= 300  ){
		menuItem=2;
	}
	else if ( yRedCont >= 100 && yRedCont <= 200 && xRedCont >= 100 && xRedCont <= 200  ){
	//else if ( yRedCont >= 1 && yRedCont <= 100 && xRedCont >= 1 && xRedCont <= 100  ){
		menuItem=3;
	}
	else if ( yRedCont >= 300 && yRedCont <= 400 && xRedCont >= 100 && xRedCont <= 200  )
	//else if ( yRedCont >= 200 && yRedCont <= 300 && xRedCont >= 1 && xRedCont <= 100  )
		menuItem=4;

	else if ( yRedCont >= 300 && yRedCont <= 400 && xRedCont >= 300 && xRedCont <= 400  )
	//else if ( yRedCont >= 200 && yRedCont <= 300 && xRedCont >= 200 && xRedCont <= 200  )
		menuItem=5;

	game->menuItems(menuItem);
}

//Find Red Object's Contours
void GetContours(IplImage* img, IplImage* thr){


	//create box
	CvPoint2D32f boxp[4];
	//create a sequence
	CvSeq* seq=NULL;

	//create storage to store contours
	static CvMemStorage* storage = NULL;
	if( storage==NULL ) {
		storage =cvCreateMemStorage();
	}

	//find contours function
	cvFindContours(thr,storage,&seq,sizeof(CvContour),CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE);

	//draw boxes of contours while red is detected
	for( ; seq!=0; seq = seq->h_next ){

		cvApproxPoly(seq,sizeof(CvContour),storage,CV_POLY_APPROX_DP,3,0);

		cvContourArea(seq,CV_WHOLE_SEQ);

		CvRect box =cvBoundingRect(seq,0);

		CvBox2D box1 = cvMinAreaRect2(seq,storage);
		cvBoxPoints(box1,boxp);

		//draw the contours
		cvDrawContours(img, seq, CV_RGB(150,0,0),CV_RGB(150,0,0), -2, CV_FILLED, 8);//,cvPoint(0,0)
		//create box to surround contours
		cvRectangle( img, cvPoint(box.x, box.y + box.height), cvPoint(box.x + box.width, box.y), CV_RGB(0, 0, 255), 1, 8, 0 );

		if (box.height>20 && box.width>20 )
		{
			CvMoments moment;
			cvMoments(thr, &moment, 1); //0

			int m10= (int) cvGetSpatialMoment(&moment, 1, 0); //x
			int m01 = (int) cvGetSpatialMoment(&moment, 0, 1); //y
			int m00 = (int) cvGetSpatialMoment(&moment, 0, 0); //area

			//positions of Red Object
			xRedCont = m10/m00;
			yRedCont = m01/m00;	

			//once x and y are defined and the menu appears we call the domenuaction function
			if (menuStart){
				game->doMenuAction();
			}


			cvLine(img, cvPoint(xRedCont ,yRedCont), cvPoint(xRedCont ,yRedCont), cvScalar(0,0,255),5); 

			//printf("new: (%d,%d)\n",xRedCont ,yRedCont);

			if  ( ( yRedCont + 5 < yyRedCont ) || ( yRedCont  > yyRedCont + 5 ) ) {

			//pass values to moveRedPlayer method to provide movement
				game->moveRedPlayer(yRedCont ,yyRedCont);}

			//printf("old: (%d,%d)\n\n\n", xxRedCont ,yyRedCont);	

			//save old positions
			yyRedCont = yRedCont;
			xxRedCont = xRedCont;
		}
		cvClearSeq(seq);

	}

	if( storage!=NULL ) {
		cvReleaseMemStorage(&storage);
	}

}

//Find Yellow Object's Contours
void GetYellowContours(IplImage* img, IplImage* thr){

	static CvMemStorage* storage2 = NULL;

	if( storage2==NULL ) {
		storage2 =cvCreateMemStorage();
	}

	CvPoint2D32f boxp2[4];
	CvSeq* seq2=NULL;

	cvFindContours(thr,storage2,&seq2,sizeof(CvContour),CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE);//,cvPoint (0,0)


	for( ; seq2!=0; seq2 = seq2->h_next ){

		cvApproxPoly(seq2,sizeof(CvContour),storage2,CV_POLY_APPROX_DP,3,0);

		cvContourArea(seq2,CV_WHOLE_SEQ);

		CvRect box =cvBoundingRect(seq2,0);

		CvBox2D box1 = cvMinAreaRect2(seq2,storage2);
		cvBoxPoints(box1,boxp2);

		cvDrawContours(img, seq2, CV_RGB(0,0,150),CV_RGB(0,0,150), -2, CV_FILLED, 8);
		cvRectangle( img, cvPoint(box.x, box.y + box.height), cvPoint(box.x + box.width, box.y), CV_RGB(255, 0, 0), 1, 8, 0 );


		if( box.height > height && box.width > width )
		{
			height = box.height;
			width = box.width;
		}


		if( height >=box.height && width >=box.width && box.height>10 && box.width>10 )
		{

			CvMoments moment2;
			cvMoments(thr, &moment2, 0); //1

			double m10= cvGetSpatialMoment(&moment2, 1, 0); //x
			double m01 = cvGetSpatialMoment(&moment2, 0, 1); //y
			double m00 = cvGetSpatialMoment(&moment2, 0, 0); //area

			//positions of Yellow Object
			xYellowCont = (int) (m10 / m00);
			yYellowCont = (int) (m01 / m00);	

			cvLine(img, cvPoint(xYellowCont ,yYellowCont), cvPoint(xYellowCont ,yYellowCont), cvScalar(255,0,0),5); 
			//printf("new yellow: (%d,%d)\n",xYellowCont ,yYellowCont);

			
			if  ( ( yYellowCont + 5 < yyYellowCont ) || ( yYellowCont  > yyYellowCont + 5 ) ) {
			//pass values to moveYellowPaddle method to provide movement
				game->moveYellowPaddle(yYellowCont ,yyYellowCont);}

			//printf("old yellow: (%d,%d)\n\n\n", xxYellowCont, yyYellowCont);	

			//save old positions
			yyYellowCont = yYellowCont;
			xxYellowCont = xYellowCont;

		}
	}

	//cvClearMemStorage(storage2);
	if( storage2!=NULL ) {
		cvReleaseMemStorage(&storage2);

	}
}


//initialize camera and do actions
void* Game::initCam(void* arg){


	//initialize capture from camera
	CvCapture* capture = NULL;
	capture = cvCreateCameraCapture(CV_CAP_ANY);//detect all cameras

	//cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 250); 
	//cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 250); 

	if(!capture)
	{
		printf("Error! Could not detect camera!");
		return NULL;
	}

	//create cam window
	cvNamedWindow("cam",1);
	//cvResizeWindow("cam",200,200);

	while(true)
	{
		//create image to store frames from camera
		IplImage* camera = NULL;

		//store frame in camera image
		camera = cvQueryFrame(capture);

		if(!camera)
			break;


		//create HSV image from camera mage
		IplImage* HSV = NULL;

		//initialize once and avoid allocating images all the time causing memory allocation error
		if (HSV == NULL){
			HSV = cvCreateImage(cvGetSize(camera),IPL_DEPTH_8U, 3);
			cvCvtColor(camera, HSV, CV_BGR2HSV);}

		//create red  and yellow thresholded image by calling threshRed ad threshYellow functions and passing the HSV image image created
		IplImage* imgThreshold = NULL;

		if (imgThreshold == NULL){
			imgThreshold = threshRed(HSV);}

		IplImage* imgThresholdYellow = NULL;

		if (imgThresholdYellow == NULL) {
			imgThresholdYellow = threshYellow(HSV);}

		//cvNamedWindow("Red Threshold");
		//cvNamedWindow("Yellow Threshold");

		//do further thresholding
		cvThreshold(imgThreshold,imgThreshold,100,255,CV_THRESH_BINARY);
		cvThreshold(imgThresholdYellow,imgThresholdYellow,100,255,CV_THRESH_BINARY);


		//call the GetContours function do detect the red object's contours
		GetContours(camera,imgThreshold);

		//call the GetYellowContours function do detect the yellow object's contours if needed(depending on game selection)
		if ( menuItem==2 || menuItem==3 ){
			GetYellowContours(camera,imgThresholdYellow);
		}


		cvShowImage("cam", camera);

		//cvShowImage("Red Threshold", imgThreshold);
		//cvShowImage("Yellow Threshold", imgThresholdYellow);


		//release capture and delete data when window destroyed or when game is over
		if ( ( cv::waitKey(10) >= 0 ) || ( gameOver==true ) ){


			cvReleaseImage(&HSV);
			cvReleaseImage(&imgThreshold);
			cvReleaseImage(&imgThresholdYellow);

			cvReleaseCapture(&capture);

			//cvDestroyWindow("Red Threshold");
			//cvDestroyWindow("Yellow Threshold");
			cvDestroyWindow("cam");			

			break;
		}

		cvReleaseImage(&HSV);
		cvReleaseImage(&imgThreshold);
		cvReleaseImage(&imgThresholdYellow);

	}

	cvReleaseCapture(&capture);

	return NULL;
}