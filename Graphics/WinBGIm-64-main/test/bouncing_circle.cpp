#include "graphics.h"
#include <conio.h> // for kbhit() and getch()

int main()
{
  // Initialize graphics mode
  int gd = DETECT, gm;
  char driverPath[] = "";
  initgraph(&gd, &gm, driverPath);

  // Ball properties
  int x = 300;                     // horizontal position (center)
  int y = 50;                      // starting vertical position
  int radius = 50;                 // ball radius
  int ground = getmaxy() - radius; // ground level
  float dy = 2;                    // falling speed

  // Gravity effect (acceleration)
  float gravity = 0.8;      // smaller = slower fall
  float bounceFactor = 0.7; // energy loss on bounce

  while (!kbhit())
  {
    cleardevice();

    // Draw ground line
    setcolor(BLACK);
    line(0, ground + radius, getmaxx(), ground + radius);

    // Draw the ball
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, radius);
    floodfill(x, y, WHITE);

    // Update position
    y += (int)dy;
    dy += gravity;

    // Bounce when hitting the ground
    if (y >= ground)
    {
      y = ground;              // reset to ground level
      dy = -dy * bounceFactor; // reverse direction and lose energy
    }

    delay(20);
  }

  getch();
  closegraph();
  return 0;
}
