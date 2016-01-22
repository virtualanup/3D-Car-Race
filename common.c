#include"common.h"

int gbps_WindowHeight=GBPS_WINDOW_HEIGHT,
gbps_WindowWidth=GBPS_WINDOW_WIDTH;
long highscore=0;
void gbps_PrintText(int x, int y, float r, float g, float b, int font, char *string)
{
  glColor3f( r, g, b );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}
