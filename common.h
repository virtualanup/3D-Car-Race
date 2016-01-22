#ifndef GBPS_COMMON_H
#define GBPS_COMMON_H
/*
common.h
includes all the necessary global header files and constant definitions. All the c files may include this common header.
It also contains declaration for some common functions
copyright (c) 2011 GBPS Team
*/
#include<stdio.h>
#include<gl\freeglut.h>
#include<soil\soil.h>
#include <stdlib.h>
#include<time.h>
#include"glm.h"

#define GBPS_WINDOW_HEIGHT 480
#define GBPS_WINDOW_WIDTH 640

#define GBPS_fps 30
#define GBPS_nf 1000/GBPS_fps

//float car_crash_angle=0.0;
int gbps_GamePlaying;//is the game play on? 0-off, 1-pause, 2-running 3-Game over
//textures
GLuint GBPS_texArr[20];//no of textures required

//models
GLuint tex_app;
GLMmodel* car1 ;
GLMmodel* tyre1;
//extern float car_crash_angle=0.0;
enum gbps_Textures{
    GBPS_TEXTURE_CAR1=0,
    GBPS_TEXTURE_ROAD,
    GBPS_TEXTURE_TYRE,
    GBPS_TEXTURE_MENUBACK,
    GBPS_TEXTURE_MENU1,
    GBPS_TEXTURE_MENU2,
    GBPS_intro,
    GBPS_TEXTURE_SURR,
    GBPS_TEXTURE_SKY,
    GBPS_TEXTURE_TREE,
    GBPS_TEXTURE_SPEED,
    GBPS_TEXTURE_PTR,
    GBPS_TEXTURE_GO};
extern long highscore;
extern int gbps_WindowHeight,gbps_WindowWidth;

void gbps_PrintText(int x, int y, float r, float g, float b, int font, char *string);
#endif
