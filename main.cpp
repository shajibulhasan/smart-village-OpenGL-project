#include <GL/glut.h>
#include <cmath>

float carPos = -1.0f;
float carPos2 = -0.5f;
float carPos3 = 0.0f;
float carPos4 = 0.5f;
float cloudPos = -1.2f;
bool isDay = true;

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawSky() {
    glColor3f(isDay ? 0.53f : 0.1f, isDay ? 0.81f : 0.1f, isDay ? 0.98f : 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
}

void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.1f, 20);
    drawCircle(x + 0.1f, y + 0.05f, 0.1f, 20);
    drawCircle(x - 0.1f, y + 0.05f, 0.1f, 20);
}

void drawRoad() {
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-1.2f, -0.3f);
    glVertex2f(1.2f, -0.3f);
    glVertex2f(1.2f, -0.5f);
    glVertex2f(-1.2f, -0.5f);
    glEnd();
}

void drawCar(float position) {
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(position, -0.35f);
    glVertex2f(position + 0.2f, -0.35f);
    glVertex2f(position + 0.2f, -0.25f);
    glVertex2f(position, -0.25f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(position + 0.05f, -0.37f, 0.02f, 20);
    drawCircle(position + 0.15f, -0.37f, 0.02f, 20);
}

void drawTree(float x, float y) {
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.03f, y - 0.2f);
    glVertex2f(x + 0.03f, y - 0.2f);
    glVertex2f(x + 0.03f, y);
    glVertex2f(x - 0.03f, y);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
    drawCircle(x, y + 0.05f, 0.08f, 20);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawSky();
    drawCloud(cloudPos, 0.8f);

    drawRoad();
    drawCar(carPos);
    drawCar(carPos2);
    drawCar(carPos3);
    drawCar(carPos4);

    drawTree(-0.8f, -0.2f);
    drawTree(0.8f, -0.2f);
    drawTree(0.6f, -0.1f);

    glutSwapBuffers();
}

void update(int value) {
    carPos += 0.01f;
    carPos2 += 0.01f;
    carPos3 += 0.01f;
    carPos4 += 0.01f;
    if (carPos > 1.4f) carPos = -1.4f;
    if (carPos2 > 1.4f) carPos2 = -1.4f;
    if (carPos3 > 1.4f) carPos3 = -1.4f;
    if (carPos4 > 1.4f) carPos4 = -1.4f;

    cloudPos += 0.005f;
    if (cloudPos > 1.4f) cloudPos = -1.4f;

    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}

void init() {
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.2, 1.2, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Smart Village");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(50, update, 0);
    glutMainLoop();
    return 0;
}
