#include"object.h"
#include"game.h"
void RenderTree(GBPS_Tree Tree)
{
    //

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();//for the current object
    glTranslatef(Tree.x,-1.0,-Tree.y);//Object translate

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);     // Turn Blending On
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glRotatef(45.0,0,1.0,0);
    glBindTexture(GL_TEXTURE_2D, GBPS_texArr[GBPS_TEXTURE_TREE]);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0);
    glVertex3f(-5.0,-5.0,0);
    glTexCoord2d(0.0,1.0);
    glVertex3f(-5.0,5.0,0.0);
    glTexCoord2d(1.0,1.0);
    glVertex3f(5.0,5.0,0.0);
    glTexCoord2d(1.0,0.0);
    glVertex3f(5.0,-5.0,0.0);
    //glTranslatef(0.0,0.0,a);

    glEnd();
    glPushMatrix();
    glRotatef(90.0,0,1.0,0);
    glBegin(GL_QUADS);
    glTexCoord2d(0.0,0.0);
    glVertex3f(-5.0,-5.0,0);
    glTexCoord2d(0.0,1.0);
    glVertex3f(-5.0,5.0,0.0);
    glTexCoord2d(1.0,1.0);
    glVertex3f(5.0,5.0,0.0);
    glTexCoord2d(1.0,0.0);
    glVertex3f(5.0,-5.0,0.0);
    //glTranslatef(0.0,0.0,a);

    glEnd();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);
    // DEBUG_drwCord();
    glDisable(GL_BLEND);     // Turn Blending On
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
}


void render_speedometer(){
       static float aaa=0;
    if(aaa==0.0)
        aaa=PlayerCar.vel;
    if(aaa>PlayerCar.vel)
        aaa-=0.05;
    else if(aaa<PlayerCar.vel)
        aaa+=0.05;
       // aaa++;
        glPushMatrix();
       // printf("%f",);

    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);     // Turn Blending On
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);






    glPushMatrix();
         glTranslatef(-4.0,-3.0,0.0);
        glScalef(0.3,0.3,0.3);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, GBPS_texArr[GBPS_TEXTURE_SPEED]);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0,0.0);
        glVertex3f(-5.0,-5.0,0);
        glTexCoord2d(0.0,1.0);
        glVertex3f(-5.0,5.0,0.0);
        glTexCoord2d(1.0,1.0);
        glVertex3f(5.0,5.0,0.0);
        glTexCoord2d(1.0,0.0);
        glVertex3f(5.0,-5.0,0.0);
    //glTranslatef(0.0,0.0,a);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();





    glPushMatrix();
       // glTranslatef(4.0,3.0,0.0);




        glTranslatef(-4.0,-3.0,0.0);
        float deg=-aaa*40+70;
        if(fabs(deg)>150)
            deg=150;
        glRotatef(deg,0,0,1.0);
        glScalef(0.3,0.3,0.3);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, GBPS_texArr[GBPS_TEXTURE_PTR]);
        glBegin(GL_QUADS);
        glTexCoord2d(0.0,0.0);
        glVertex3f(-5.0,-5.0,0);
        glTexCoord2d(0.0,1.0);
        glVertex3f(-5.0,5.0,0.0);
        glTexCoord2d(1.0,1.0);
        glVertex3f(5.0,5.0,0.0);
        glTexCoord2d(1.0,0.0);
        glVertex3f(5.0,-5.0,0.0);
        //glTranslatef(0.0,0.0,a);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // DEBUG_drwCord();
    glDisable(GL_BLEND);     // Turn Blending On
    glEnable(GL_DEPTH_TEST);

    glPopMatrix();





}


void render_game_over(){
    static float pqr=1.0;
    if(pqr>=0.2){
        pqr-=0.1;

    }

    glEnable(GL_BLEND);     // Turn Blending On
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glBindTexture(GL_TEXTURE_2D, GBPS_texArr[GBPS_TEXTURE_GO]);

        glScalef(pqr,pqr,1.0);


        glBegin(GL_QUADS);
            glTexCoord2d(0.0,0.0);glVertex3f(-20.0,-5.0,3.0);
            glTexCoord2d(0.0,1.0);glVertex3f(-20.0,5.0,3.0);
            glTexCoord2d(1.0,1.0);glVertex3f(20.0,5.0,3.0);
            glTexCoord2d(1.0,0.0);glVertex3f(20.0,-5.0,3.0);


        glEnd();


        glDisable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);

    glPopMatrix();

}
