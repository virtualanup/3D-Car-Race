#include"mainmenu.h"
char* MenuOptions[]= {"Start","About","Exit"};
int flag=0;
int MainMenuPos[]= {3.0,2.0,1.0,0.0,-1};
int initial_flag=1;
int start=1;
int i;
int lasty=60;
float alphaa=0.0;
float y_final=4.0;


void gbps_MM_mouse(int x,int y){

   printf("x:%d    y:%d     diff:%d      ",x,y,lasty-y);
    if(x>=0 && x<=325){
        if(y>=56 && y<=217){
            if((lasty-y)<=-40){
                for(i=0; i<=40; i++)
                {
                menu_cur_pos-=0.018;
                gbps_RenderMainMenu();
                }
                lasty=y;


            }


        }



    }


}

void show_new()
{
    switch(initial_flag)
    {


    case 1:

        alphaa+=0.025;
        break;

    case 2:
        alphaa-=0.025;
        break;

    }

}

void render_new_texture()
{

    switch (flag)
    {
    case 1:
        tex_app=GBPS_texArr[GBPS_TEXTURE_MENU1];

        break;

    case 2:
        tex_app=GBPS_texArr[GBPS_TEXTURE_MENU2];
        break;
    }

}

void menu_modify()
{

    for(i=0; i<=40; i++)
    {

        y_final-=0.1;
        gbps_RenderMainMenu();
    }
    render_new_texture();
    for(i=0; i<40; i++)
    {
        y_final+=0.1;
         gbps_RenderMainMenu();
    }



}
void gbps_EnterMainMenu()
{
    selection=0;
    menu_cur_pos=MainMenuPos[selection];
    flag=1;
     render_new_texture();
    gbps_PositionReset();
    //set the glut functions
    glutDisplayFunc(gbps_RenderMainMenu);

    glutSpecialFunc(gbps_MainMenuSpecialKey);
    glutKeyboardFunc(gbps_MainMenuAsciiKey);
    //glutPassiveMotionFunc(gbps_MM_mouse);
    gpbs_MainMenuLoop();
}

void gbps_LeaveMainMenu()
{
    flag=0;
    /*
    It's illigal to set the display callback to NULL.
    The initgame function will register its own callback function
    so we dont have to worry
    */
    // glutDisplayFunc(NULL);

    glutSpecialFunc(NULL);
    glutKeyboardFunc(NULL);
}

void gbps_PositionReset()
{
    selection=0;
    menu_cur_pos=MainMenuPos[selection];
    switch(flag)
    {
    case 1:
        extreme_low=0;
        extreme_up=3;

        break;
    case 2:
        extreme_low=0;
        extreme_up=4;

        break;

    }
}

void gbps_mm_EnterEvents()
{
    if(initial_flag<2)
        return;
    switch(flag)
    {

    case 1:
        if(selection==MM_START_GAME)
        {
            //start game
            gbps_LeaveMainMenu();
            gbps_EnterGame();

        }
        if(selection==MM_OPTIONS)
        {

            flag=2;
            menu_modify();
            gbps_PositionReset();
        }
        if(selection==MM_CREDITS)
        {
            //blah blah
        }

        if(selection==MM_QUIT)
        {
            exit(0);
        }
        break;

    case 2:
        if(selection==MM_BACK)
        {
            flag=1;
            menu_modify();
            gbps_PositionReset();

        }
        break;

    }
}

void gbps_RenderMainMenu()
{
    //gbps_PositionReset();
    if(alphaa>1.0)
    {
        initial_flag=2;
        //alphaa=0;
    }
    show_new();


    if(alphaa<0)
    {
        start=2;
    }





    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glDisable( GL_TEXTURE_2D );
    gluLookAt(-0,0,10.0,0,0,0,0,1.0,0.0);
    //selection
    /*glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, GBPS_texArr[GBPS_TEXTURE_MENUBACK]);
    glScalef(4.3,4.3,1.0);
    glTranslatef(0,0,-5.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0);
    glVertex2f(-2.0,-1.5);
    glTexCoord2f(1.0,0);
    glVertex2f(2.0,-1.5);
    glTexCoord2f(1.0,1.0);
    glVertex2f(2.0,1.5);
    glTexCoord2f(0.0,1.0);
    glVertex2f(-2.0,1.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glPushMatrix();
    glEnable(GL_BLEND);     // Turn Blending On
    glDisable(GL_DEPTH_TEST);
    glColor4f(1.0,1.0,1.0,0.2);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glTranslatef(-5.0,menu_cur_pos,0);
    glScalef(1.0,0.8,1.0);


    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0);
    glVertex2f(0,0);
    glTexCoord2f(1.0,0);
    glVertex2f(5.0,0);
    glTexCoord2f(1.0,1.0);
    glVertex2f(5.0+menu_cur_pos/3,1.0);
    glTexCoord2f(0.0,1.0);
    glVertex2f(0-menu_cur_pos/20,1.0);
    glEnd();

    glDisable(GL_BLEND);     // Turn B
    glEnable(GL_DEPTH_TEST);
    glColor4f(1.0,1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_BLEND);     // Turn Blending On
    glDisable(GL_DEPTH_TEST);
    glColor4f(1.0,1.0,1.0,0.9);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, GBPS_texArr[GBPS_TEXTURE_MENU1]);
    glTranslatef(0,0.5,-2.0);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0,0);
    glVertex2f(-7.0,0);
    glTexCoord2f(1.0,0);
    glVertex2f(0.0,0);
    glTexCoord2f(1.0,1.0);
    glVertex2f(0.0,4.0);
    glTexCoord2f(0.0,1.0);
    glVertex2f(-7.0,4.0);
    glEnd();
    glDisable(GL_BLEND);     // Turn B
    glEnable(GL_DEPTH_TEST);

    glDisable(GL_TEXTURE_2D);
    glColor4f(1.0,1.0,1.0,1.0);
    glPopMatrix();





    glPopMatrix();
    glutSwapBuffers();
    */
    if(start==1){
		glPushMatrix();
		glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);

		glEnable(GL_BLEND);     // Turn Blending On
		glDisable(GL_DEPTH_TEST);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE);
		glColor4f(1.0,1.0,1.0,alphaa);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, GBPS_texArr[GBPS_intro]);
        //printf("%f",alphaa);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0,0);glVertex2f(-4.0,-3.0);
		glTexCoord2f(1.0,0);glVertex2f(4.0,-3.0);
		glTexCoord2f(1.0,1.0);glVertex2f(4.0, 3.0);
		glTexCoord2f(0.0,1.0);glVertex2f(-4.0,3.0);
		glEnd();


		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);     // Turn B
	    glEnable(GL_DEPTH_TEST);
		glColor4f(1.0,1.0,1.0,1.0);
		glPopMatrix();
	}
	else{
		glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, GBPS_texArr[GBPS_TEXTURE_MENUBACK]);
	glScalef(4.3,4.3,1.0);
	glTranslatef(0,0,-5.0);

	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0);glVertex2f(-2.0,-1.5);
		glTexCoord2f(1.0,0);glVertex2f(2.0,-1.5);
		glTexCoord2f(1.0,1.0);glVertex2f(2.0,1.5);
		glTexCoord2f(0.0,1.0);glVertex2f(-2.0,1.5);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();


	glPushMatrix();
		glPushMatrix();

			glEnable(GL_BLEND);     // Turn Blending On
			//glDisable(GL_DEPTH_TEST);
			glColor4f(1.0,1.0,1.0,0.3);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE);
			glScalef(0.8,0.7,1.0);
            glTranslatef(0.0,0.6,0.00);
			glTranslatef(-5.0,menu_cur_pos,0.00);
            glScalef(1.0,0.8,1.0);


			glBegin(GL_QUADS);
				glTexCoord2f(0.0,0);glVertex2f(0,0);
				glTexCoord2f(1.0,0);glVertex2f(5.0,0);
				glTexCoord2f(1.0,1.0);glVertex2f(5.0+menu_cur_pos/3,1.0);
				glTexCoord2f(0.0,1.0);glVertex2f(0-menu_cur_pos/20,1.0);
			glEnd();

		glDisable(GL_BLEND);     // Turn B
	    glEnable(GL_DEPTH_TEST);
	  glColor4f(1.0,1.0,1.0,1.0);
		glPopMatrix();


		//for menu
		glPushMatrix();
		glEnable(GL_BLEND);     // Turn Blending On
			glDisable(GL_DEPTH_TEST);
			glColor4f(1.0,1.0,1.0,0.9);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, tex_app);
		glTranslatef(0,0.5,-2.0);
		glScalef(0.8,0.8,1.0);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0,0);glVertex2f(-7.0,0);
		glTexCoord2f(1.0,0);glVertex2f(0.0,0);
		glTexCoord2f(1.0,1.0);glVertex2f(0.0, y_final);
		glTexCoord2f(0.0,1.0);glVertex2f(-7.0, y_final);
		glEnd();
		glDisable(GL_BLEND);     // Turn B
	    glEnable(GL_DEPTH_TEST);

		glDisable(GL_TEXTURE_2D);
		 glColor4f(1.0,1.0,1.0,1.0);
		glPopMatrix();

		}



	glPopMatrix();


		glPopMatrix();

	glutSwapBuffers();
}
void gbps_MainMenuSpecialKey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT :
        break;

    case GLUT_KEY_RIGHT :
        break;
    case GLUT_KEY_UP :
        if(selection>extreme_low)
        {
            menu_cur_pos=MainMenuPos[selection];
            //printf("key up top condition selection=%d and el=%d and eu=%d\n",selection,extreme_low,extreme_up);
            for(i=0; i<=40; i++)
            {
                menu_cur_pos+=0.025;
                gbps_RenderMainMenu();
            }
            selection--;

        }
        else
        {
            //printf("key up down condition selection=%d and el=%d and eu=%d\n",selection,extreme_low,extreme_up);
            selection=extreme_up;

        }
        menu_cur_pos=MainMenuPos[selection];
        gbps_RenderMainMenu();
        break;
    case GLUT_KEY_DOWN :
        if(selection<extreme_up)
        {
            menu_cur_pos=MainMenuPos[selection];
            //printf("key down top condition selection=%d and el=%d and eu=%d\n",selection,extreme_low,extreme_up);
            for(i=0; i<=40; i++)
            {
                menu_cur_pos-=0.025;
                gbps_RenderMainMenu();
            }
            selection++;

        }
        else
        {
            //printf("key down down condition selection=%d and el=%d and eu=%d\n",selection,extreme_low,extreme_up);
            selection=extreme_low;
        }
        menu_cur_pos=MainMenuPos[selection];
        gbps_RenderMainMenu();
        break;



    }
}

void gbps_MainMenuAsciiKey(int key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 13:
        gbps_mm_EnterEvents();
        break;
    }
}

void gpbs_MainMenuLoop()
{
    if(flag>0)
    {
        glutPostRedisplay();
        glutTimerFunc(GBPS_nf,gpbs_MainMenuLoop,0);
    }
    else
    {
        //do nothing....
    }
}
