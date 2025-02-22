#include <GL/glut.h>
#include <cmath>

float carPos = -1.0f, carSpeed1 = 0.01f;
float carPos2 = -0.5f, carSpeed2 = 0.012f;
float carPos3 = 0.0f, carSpeed3 = 0.014f;
float carPos4 = 0.5f, carSpeed4 = 0.016f;
float cloudPos = -1.2f;
float sunY = 0.8f;
bool sunRising = true;

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

void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.7f, sunY, 0.1f, 30);
}

void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.1f, 20);
    drawCircle(x + 0.1f, y + 0.05f, 0.1f, 20);
    drawCircle(x - 0.1f, y + 0.05f, 0.1f, 20);
}

void drawSky() {
    glColor3f(0.53f, 0.81f, 0.98f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
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

void drawField() {
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-1.2f, -1.1f);
    glVertex2f(1.2f, -1.1f);
    glVertex2f(1.2f, -0.5f);
    glVertex2f(-1.2f, -0.5f);
    glEnd();
}

void drawHouse(float x, float y) {
    glColor3f(0.8f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 0.1f, y);
    glVertex2f(x + 0.1f, y + 0.1f);
    glVertex2f(x, y + 0.1f);
    glEnd();

    glColor3f(0.5f, 0.3f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.02f, y + 0.1f);
    glVertex2f(x + 0.12f, y + 0.1f);
    glVertex2f(x + 0.05f, y + 0.15f);
    glEnd();
}

void drawHill() {
    glColor3f(0.3f, 0.6f, 0.3f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-0.5f, 0.2f);
    glVertex2f(0.0f, -0.3f);

    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(1.0f, -0.3f);
    glEnd();
}

void drawTree(float x, float y) {
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.02f, y);
    glVertex2f(x + 0.02f, y);
    glVertex2f(x + 0.02f, y + 0.1f);
    glVertex2f(x - 0.02f, y + 0.1f);
    glEnd();

    glColor3f(0.0f, 0.8f, 0.0f);
    drawCircle(x, y + 0.12f, 0.05f, 20);
}

void drawCar(float x, float y) {
    glColor3f(0.3f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.05f, y - 0.02f);
    glVertex2f(x + 0.05f, y - 0.02f);
    glVertex2f(x + 0.05f, y + 0.02f);
    glVertex2f(x - 0.05f, y + 0.02f);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f);
    drawCircle(x - 0.03f, y - 0.02f, 0.015f, 20);
    drawCircle(x + 0.03f, y - 0.02f, 0.015f, 20);
}

void update(int value) {
    carPos += carSpeed1;
    carPos2 += carSpeed2;
    carPos3 += carSpeed3;
    carPos4 += carSpeed4;
    if (carPos > 1.2f) carPos = -1.2f;
    if (carPos2 > 1.2f) carPos2 = -1.2f;
    if (carPos3 > 1.2f) carPos3 = -1.2f;
    if (carPos4 > 1.2f) carPos4 = -1.2f;

    cloudPos += 0.005f;
    if (cloudPos > 1.2f) cloudPos = -1.2f;

    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawSky();
    drawSun();
    drawCloud(cloudPos, 0.8f);
    drawHill();
    drawHouse(-0.75f, -0.2f);
    drawHouse(0.5f, -0.2f);
    drawRoad();
    drawField();

    drawTree(-0.85f, -0.2f);
    drawTree(-0.6f, -0.1f);
    drawTree(-0.4f, -0.2f);
    drawTree(0.3f, -0.1f);
    drawTree(0.4f, 0.00f);
    drawTree(0.65f, -0.15f);

    drawTree(0.65f, -0.8f);
    drawTree(0.2f, -0.85f);
    drawTree(-0.2f, -0.8f);
    drawTree(-0.6f, -0.75f);
    drawTree(-0.85f, -0.9f);
    drawHouse(0.4f, -0.8f);
    drawHouse(-0.05f, -0.85f);
    drawHouse(-0.48f, -0.9f);

    drawCar(carPos, -0.4f);
    drawCar(carPos2, -0.4f);
    drawCar(carPos3, -0.4f);
    drawCar(carPos4, -0.4f);

    glutSwapBuffers();
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
    glutCreateWindow("Village Road");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(50, update, 0);
    glutMainLoop();
    return 0;
}
