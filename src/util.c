// 作成者: j19426 西澤駿太郎
#include "util.h"

#include <stdio.h>
#include <string.h>

#include "opengl.h"

int timeDelta = 0;
int fps = 0;

void deltaTimeUpdate() {
  static int timeBefore = 0;
  static int timeBeforeCalcFps = 0;
  static int frameCount = 0;

  int timeNow = glutGet(GLUT_ELAPSED_TIME);
  timeDelta = timeNow - timeBefore;
  timeBefore = timeNow;

  frameCount++;
  if (1000 < timeNow - timeBeforeCalcFps) {
    fps = frameCount;
    timeBeforeCalcFps = timeNow;
    frameCount = 0;
  }
}

void fpsDraw() {
  char fpsStr[8];
  snprintf(fpsStr, 8, "%02d fps", fps);
  unsigned int length = strlen(fpsStr);

  glColor3ub(0x00, 0x00, 0x00);
  glRasterPos2f(6.0F, 5.0F);
  for (unsigned int i = 0; i < length; i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, fpsStr[i]);
  }

  glColor3ub(0xFF, 0xFF, 0xFF);
  glRasterPos2f(5.0F, 6.0F);
  for (unsigned int i = 0; i < length; i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, fpsStr[i]);
  }
}
