#ifndef GAME_H
#define GAME_H
#include"common.h"
#include"car.h"
#include"linkedlist.h"
#include"object.h"


float gbps_camDist;//distance of camera from the car
int gbps_aziy;//rotation about y axis
int gbps_elex;//elevation from the x axis
float gbps_camUp;//up camera
extern int gbps_rtLtKey;
extern int gbps_upDownKey;
extern int gbps_TotalOpponentCars;
extern int game_over;
long gbps_locct;//last opponent car created time
long gbps_lsoct;//last side object created time

long gbps_score;

long elapsed_time,total_time;//some time storing variables

double gbps_road_loop;

Gbps_Car PlayerCar;
gbpsLinkedList OpponentCars;
gbpsLinkedList SideObjects;

void gbps_EnterGame();
void gbps_GameLoop();
void gbps_LeaveGame();
void gbps_PauseGame();
void gbps_ResumeGame();
void gbps_RenderGame();
void UpdateGameLogic();
void UpdatePlayerCar();
void UpdateOpponentCars();

//keyboard and mouse handling functions
void gbps_GameSpecialKey(int key, int x, int y);
void gbps_GameSpecialKeyUp(int key, int x, int y);
void gbps_GameAsciiKey(int key, int x, int y);
void gbps_GameMouse(int button,int state,int x,int y);
void gbps_GameMouseWheel(int button, int dir, int x, int y);
void gbps_GameMouseMove(int x,int y);


void game_changeCamera(int x,int y);


void DEBUG_drwCord(void);
#endif
