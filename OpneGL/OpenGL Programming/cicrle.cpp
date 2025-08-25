#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    float cx = 0.0f, cy = 0.0f, r = 0.5f;
    int num_segments = 100;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for(int i = 0; i <= num_segments; i++) {
            float angle = 2.0f * M_PI * i / num_segments;
            float x = cx + r * cos(angle);
            float y = cy + r * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Filled Circle Example");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
