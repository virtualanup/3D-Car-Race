#ifndef GBPS_MAINMENU_H
#define GBPS_MAINMENU_H
/*
mainmenu.h
Handles the main menu
*/
#include"common.h"

void gbps_EnterMainMenu();
void gbps_LeaveMainMenu();
void gbps_RenderMainMenu();
void gpbs_MainMenuLoop();

void gbps_PositionReset();
void gbps_MenuReset();
void gbps_mm_EnterEvents();

void gbps_MainMenuSpecialKey(int key, int x, int y);
void gbps_MainMenuAsciiKey(int key, int x, int y);
int selection;
float menu_cur_pos;
extern char* MenuOptions[];

enum gbps_MainMenuSelection{MM_START_GAME,MM_OPTIONS,MM_CREDITS,MM_QUIT,MM_BACK};
extern int MainMenuPos[];
int extreme_low,extreme_up;
extern int flag;


#endif
