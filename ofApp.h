#pragma once

#include "ofMain.h"
#include "ofxBullet.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"
#include <iostream>  
#include <fstream>  
#include <string>  

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	vector <ofxBulletBox*>		bounds;
	ofxBulletCustomShape*		boundsShape;
	ofMaterial					boundsMat;
	float						boundsWidth;
	ofEasyCam					cam;

	ofxBulletSphere*			sphere;

	bool spherebug = false;
	ofxBulletBox*				car;
	//ofxBulletCustomShape		octane;

	void createArena();

	ofBoxPrimitive box;
	float angle;
	ofLight light;
	bool bOrbit, bRoll;
	float angleH, roll;

	//Punteggio
	int num_partita = 0;
	int	 score = 0;

	//Variabili di movimento
	int forza = 250;
	int frizione = -25;


	bool colpito = false;

	/****** ARENA ******/
	ofxBulletWorldRigid			world;
	


	// GROUND //
	int xGround = 120;
	int zGround = 100;
	int yGround = 1;
	ofxBulletBox ground;

	// BACK WALL //
	int xBack = 100;
	int yBack = 50;
	int zBack = 5;
	ofxBulletBox back;


	// BACK WALL LEFT AND RIGHT //
	int xBack1 = 40;
	int yBack1 = 60;
	int zBack1 = 5;
	ofxBulletBox back1;
	ofxBulletBox back2;

	//TARGET//
	int xTarget = 40;
	int yTarget = 30;
	int zTarget = 5;
	ofxBulletBox target;

	//RIGHT WALL//
	int xRight = 5;
	int yRight = 60;
	int zRight = 100;
	ofxBulletBox right;

	//LEFT WALL//
	int xLeft = 5;
	int yLeft = 60;
	int zLeft = 100;
	ofxBulletBox left;

	/*CELING//
	int xCeiling= 120;
	int yCeiling = 100;
	int zCeiling = 0.05;*/
	ofxBulletBox ceiling;

	//FRONT WALL//
	int xFront = 120;
	int yFront = 60;
	int zFront = 5;
	ofxBulletBox front;


	/****** GUI ******/
	ofxPanel gui_game;
	ofxPanel gui_setting;
	ofxPanel gui_first;
	ofxPanel gui_stats;
	void drawInitialGui();
	void drawFirstGui();
	void drawGuiGame();
	void drawGuiSetting();
	ofxFloatSlider ball_radius;
	ofxFloatSlider ball_restitution;
	ofxFloatSlider car_width;
	ofxFloatSlider car_height;
	ofxToggle lockCamera;
	ofxButton resetBallButton;
	ofxButton resetCarButton;
	ofxButton playGame;
	ofxButton restartGame;
	ofxButton buttonHistory;
	ofxToggle setting;
	ofxButton rules;
	ofxLabel labelGame;
	ofxLabel labelPoint;
	ofxLabel labelSeconds;
	ofxLabel labelNumMatch;
	ofxLabel labelMatch;
	ofxLabel labelBall;
	ofxLabel labelCar;

	/*GUI MUSIC*/
	ofxPanel gui_music;
	ofxFloatSlider volume=0.2; //MUSICA INIZIALE DEL GIOCO E MUSICA BACKGROUND : SONO ESCLUSI GLI EFFETTI

	
	
	void resetTarget();

	void resetBall();
	void resetCar();
	void play();
	void restartPlay();
	bool initialMenu = false; //mostra menu iniziale

	/***** TIME *****/
	double start_timer;
	double end_timer;
	double time_game = 10000; //300.000 are 5 minutes -- 125.000 are 2 minutes
	int timer = 0;

	bool started = false;
	double start_countdown;
	double end_countdown;
	double time_countdown = 5000; 
	int countdown = 0;
	int scelta = 0;

	//PARTITA CONCLUSA
	bool completed = false;
	int timeCompleted = 0;

	/*LEVELS*/
	ofxPanel gui_level;
	ofxButton levelButton;
	//int selectLevel = 0;
	void createObstacle();

	/*LEVEL 4*/
	void level4();
	bool checkLevel4 = false;
	bool reverseLevel4 = false;


	/*LEVEL 5*/
	void level5();
	bool checkLevel5 = false;
	bool reverseLevel5 = false;

	/*LEVEL 6*/
	void level6();
	bool checkLevel6 = false;
	bool reverseLevel6 = false;

	// OSTACOLO 6//
	int xOst6 = 40;
	int yOst6 = yBack1/2;
	int zOst6 = 5;
	ofxBulletBox ostacolo6;

	/*LEVEL 7*/
	void level7();
	bool checkLevel7 = false;
	bool reverseLevel7 = false;

	// OSTACOLO 7//
	int xOst7 = xGround;
	int yOst7 = yBack1 / 2;
	int zOst7 = yGround;
	ofxBulletBox ostacolo7;


	/*LEVEL 8*/
	void level8();
	bool checkLevel8 = false;
	bool reverseLevel8 = false;


	/*LEVEL 9*/
	void level9();
	bool checkLevel9 = false;
	bool reverseLevel9 = false;


	/*LEVEL 10*/
	void level10();
	bool checkLevel10 = false;
	bool reverseLevel10 = false;


	// OSTACOLO 9//
	int xOst9 = 15;
	int yOst9 = 15;
	int zOst9 = 15;
	ofxBulletBox ostacolo9;


	int readLevel;
	void settingLevel();
	/*GUI LEVELS*/
	
	float overflow_target=0;
	float overflow = 0;
	ofxIntSlider levels=1;
	

	//3D OBJECT

	ofxAssimpModelLoader octaneModel;
	vector<ofxBulletCustomShape*>	logos;
	ofVboMesh mesh;
	bool bUsingMesh=true;
	ofNode meshNode;
	//ofxBulletWorldRigid			world;
	ofMaterial						logoMat;


	//background
	ofImage background;


	//SOUNDS
	ofSoundPlayer   soundCountdown;

	//Effect Gol
	//int frame_gol = 10000000;
	void effectGol();
	ofSoundPlayer   soundGol;
	ofSoundPlayer   voiceGol;
	ofSoundPlayer   whistle;

	double start_effect;
	double end_effect;
	double time_effect = 4000; //4000 are 4 second for effet
	int effect = 0;



	//Ball Effect
	
	ofSoundPlayer   soundBall;

	//Sound in Game
	ofSoundPlayer   generalSound;

	//Sound Car
	ofSoundPlayer   soundAcc;


	//StartGame
	ofSoundPlayer initSound;

	/**** TEXTURE ***/
	ofTexture textureBall;
	ofTexture textureGround;
	ofTexture textureWheels;
	ofTexture textureWall;

	//SCOREBOARD
	ofImage scoreboard;


	/***** CAR *****/

	ofBoxPrimitive wheel1, wheel2, wheel3, wheel4, point_left, point_right, point_center, origin;
	float distance = 5;

	bool rotation_left = false;
	bool rotation_right = false;
	bool marcia = false;
	bool retromarcia = false;

	void resetLeftRightPoint();
	void createCar();
	void drawCar();

	bool muovi_avanti = false;
	void moveW();
	void moveD(int deg);
	void moveA(int deg);
	void moveS();
	bool controlArena();
	 

	float speed = 0.05;
	float max_speed = 1;
	int rallentamento_marcia = true; //rallentamento in avanti

	ofVec3f eur_deg, eur_deg1;
	float theta = 0;
	float wheel_deg = speed + 1;




	//regolamento
	vector < string > linesOfTheFile;

	void readRules();
	bool activeRules = false;

	//NickName
	string nickname;
	void insertNick();

	//Leadboard
	//vector < string > linesOfTheFile;
	void readHistory();
	bool activeHistory = false;
	bool savedHistory = false;


	
	//FONT
	ofTrueTypeFont title;
	ofTrueTypeFont subtitle;
	ofTrueTypeFont label;
};

