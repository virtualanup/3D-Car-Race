#include <stdio.h>
#include"mainmenu.h"
#include"init.h"
#include"game.h"
int main(int argc,char * argv[])
{
    gbps_InitWindow(argc,argv);
    //glutFullScreen();
    //run the main menu
    gbps_EnterMainMenu();//let the game begin
    glutMainLoop();
    return 0;
}
