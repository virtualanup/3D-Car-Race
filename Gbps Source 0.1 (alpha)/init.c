#include"init.h"



void gbps_InitWindow(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(GBPS_WINDOW_WIDTH,GBPS_WINDOW_HEIGHT);
    glutInitWindowPosition(100,100);
    glutCreateWindow("GBPS Extreme Racing");

    //gbps_InitFog();
    gbps_LoadResources();

    glClearColor(0.0,0.0,0.0,1);

    //gl enables

    glShadeModel(GL_LINEAR);//avs might well change to flat
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);//??

    glEnable(GL_CULL_FACE);//glFrontFace()for GL_CW or GL_CCW
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_FOG);
    glEnable(GL_TEXTURE_2D);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//might not need

    glutReshapeFunc(gbps_WindowResize);

    glutIgnoreKeyRepeat(1);

    FILE* file=fopen("score.txt","rb");
    if(file!=NULL)
    {
        fread(&highscore,sizeof(long),1,file);
    }
    else
    {
        file==fopen("score.txt","wb");
        fwrite(0,sizeof(long),1,file);
    }
    fclose(file);
}

void gbps_InitFog(void)
{
    GLfloat fogColor[4] = {0.8, 0.8, 0.8, 1.0};
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogf(GL_FOG_DENSITY, 0.35);
    glHint(GL_FOG_HINT, GL_FASTEST);
    glFogf(GL_FOG_START, 125.0);
    glFogf(GL_FOG_END, 130.0);
}
void gbps_WindowResize(int w, int h)
{
    gbps_WindowHeight=h;
    gbps_WindowWidth=w;
    // Prevent a divide by zero
    if(h == 0)h = 1;

    float ratio = 1.0f * w / h;
    glViewport(0, 0, w, h);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the clipping volume
    gluPerspective(45,ratio,1,1000);
    glMatrixMode(GL_MODELVIEW);
    if(gbps_GamePlaying>0)
        game_changeCamera(0,0);//change camera if the game is running

}
/*
Loads the textures in the memory
*/
void gbps_LoadResources()
{
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    //textures
    GBPS_texArr[GBPS_TEXTURE_CAR1] = SOIL_load_OGL_texture
                                    (
                                        "res/car.jpg",
                                        SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                                    );

    GBPS_texArr[GBPS_TEXTURE_ROAD] = SOIL_load_OGL_texture
                                     (
                                         "res/img_road.jpg",
                                         SOIL_LOAD_AUTO,
                                         SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_TEXTURE_REPEATS
                                     );

    GBPS_texArr[GBPS_TEXTURE_TYRE] = SOIL_load_OGL_texture
                                     (
                                         "res/tyre.jpg",
                                         SOIL_LOAD_AUTO,
                                         SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                                     );
    GBPS_texArr[GBPS_TEXTURE_MENUBACK] = SOIL_load_OGL_texture
                                         (
                                                 "res/menu1.jpg",
                                                 SOIL_LOAD_AUTO,
                                                 SOIL_CREATE_NEW_ID,
                                                 SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                                         );
    GBPS_texArr[GBPS_TEXTURE_MENU1] = SOIL_load_OGL_texture
                                      (
                                          "res/menu11.jpg",
                                          SOIL_LOAD_AUTO,
                                          SOIL_CREATE_NEW_ID,
                                          SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                                      );


     GBPS_texArr[GBPS_TEXTURE_MENU2] = SOIL_load_OGL_texture
                                      (
                                          "res/menu12.jpg",
                                          SOIL_LOAD_AUTO,
                                          SOIL_CREATE_NEW_ID,
                                          SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                                      );
    //objects


    GBPS_texArr[GBPS_intro]=SOIL_load_OGL_texture
                             (
                                 "res/intro/1.jpg",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                            );

       GBPS_texArr[GBPS_TEXTURE_SURR]=SOIL_load_OGL_texture
                             (
                                 "res/sand.jpg",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                            );
        GBPS_texArr[GBPS_TEXTURE_SKY]=SOIL_load_OGL_texture
                             (
                                 "res/sky.jpg",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                            );
        GBPS_texArr[GBPS_TEXTURE_TREE]=SOIL_load_OGL_texture
                             (
                                 "res/tree.png",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                            );

                                    GBPS_texArr[GBPS_TEXTURE_SPEED]=SOIL_load_OGL_texture
                             (
                                 "res/speedometer.png",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                            );

             GBPS_texArr[GBPS_TEXTURE_PTR]=SOIL_load_OGL_texture
                             (
                                 "res/pointer.png",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                            );

            GBPS_texArr[GBPS_TEXTURE_GO]=SOIL_load_OGL_texture
                             (
                                 "res/gameover.png",
                                 SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y
                            );






    //objects

    if (!car1)
    {
        car1 = glmReadOBJ("res/car.obj");
        //if (!pmodel1) exit(0);
        //glmUnitize(pmodel1);// This will rescale the object to fit into the unity matrix

    }
    if (!tyre1)
    {
        tyre1 = glmReadOBJ("res/wheel.obj");
        //if (!pmodel1) exit(0);
        //glmUnitize(pmodel1);// This will rescale the object to fit into the unity matrix

    }
}
