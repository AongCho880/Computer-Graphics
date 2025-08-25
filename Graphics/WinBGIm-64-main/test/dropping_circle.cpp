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
  int dy = 2;                      // falling speed

  // Gravity effect (acceleration)
  int gravity = 1;

  while (!kbhit())
  { // loop until a key is pressed
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
    y += dy;
    dy += gravity; // increase speed (gravity)

    // Stop at ground
    if (y >= ground)
    {
      y = ground;
      dy = 0; // stop moving
    }

    delay(30);
  }

  getch();
  closegraph();
  return 0;
}
