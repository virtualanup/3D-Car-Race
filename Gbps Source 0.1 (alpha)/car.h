#ifndef GBPS_CAR_H
#define GBPS_CAR_H
/*
car.h
structures and functions for handling car
*/
#include"common.h"

#define MAX_CAR_ROT 15
#define MAX_CAR_SIDE_POS 3
typedef struct
{
    float x,y;//position of car (in 2D)
    // GLMmodel *CarModel,*TyreModel; //there is only one car model for now
    int CarTexture;//single tyre texture for now...
    float vel,acc;//velocity and acceleration
    float rot;//rotation(of car)
    float TyreRot;//rotation of tyre
    //some state variables that may be used in any way
    int state1,state2,state3;
    int type;//type of car(for computer cars only)

} Gbps_Car;
enum CarTypes {
    CAR_CONSTANT_VEL,CAR_CONSTANT_VEL_MOVING
};

void RenderCar(Gbps_Car Car);

#endif
