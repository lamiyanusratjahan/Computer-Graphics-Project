#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265358979323846

int currentScene = 1;

bool isDay = true;
bool manualDayNight = false;
float sunY = 1.8f;
float moonY = -0.5f;
float cloudX = 0.0f;
float shipX = -1.5f;
float smokeY = 0.0f;
bool birdFly = true;
float birdX = 0.0f;
float birdY = 0.0f;
float birdSpeed = 0.02f;
bool birdStop = true;
float shipSpeed = 0.5f;
bool shipStop = true;


int i;
int triangleAmount = 30;
GLfloat twicePi = 2.0f * PI;
GLfloat r = 0.06f;



bool showBird = true;
bool birdMove = true;
bool carMove  = false;

float birdX1 = 0.0f;
float birdX2 = 0.0f;
float birdSpeed1 = 0.05f;
float birdSpeed2 = 0.05f;

float carX = 0.0f;
float carSpeed = 0.03f;
float wheelAngle = 0.0f;
float timeOfDay = 0.0f;



float _run = 0.0;
float _run1 = 0.0;
float _run2 = 0.0;
float _run3 = 0.0;

float cloudSpeed = 0.004f;
float daySpeed = 0.005f;
float cloudRun = 0.0f;


float rainSpeed  = 0.05f;

bool isRaining = false;
bool cloudMove = false;




void drawCircle(float x, float y, float radius) {
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * PI * i / numSegments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}


void drawVillage()
{


glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /// Sky
    if (isDay) {
        glBegin(GL_QUADS);
        glColor3ub(135, 206, 235);
        glVertex2f(-2.0f, 2.0f);
        glVertex2f(2.0f, 2.0f);
        glVertex2f(2.0f, 0.80f);
        glVertex2f(-2.0f, 0.80f);
        glEnd();
    }
    else {
        glBegin(GL_QUADS);
        glColor3ub(10, 10, 40);
        glVertex2f(-2.0f, 2.0f);
        glVertex2f(2.0f, 2.0f);
        glVertex2f(2.0f, 0.80f);
        glVertex2f(-2.0f, 0.80f);
        glEnd();
    }

    ///River
    glBegin(GL_QUADS);
    glColor3ub(38, 154, 214);
    glVertex2f(-2.0f, 0.80f);
    glVertex2f(2.0f, 0.80f);
    glVertex2f(2.0f, -2.0f);
    glVertex2f(-2.0f, -2.0f);
    glEnd();

    /// Ship
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.8f, 0.19f);
    glVertex2f(-1.2f, 0.19f);
    glVertex2f(-1.077f, 0.47f);
    glVertex2f(-1.19f, 0.29f);
    glVertex2f(-1.9f, 0.29f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(-1.85f, 0.29f);
    glVertex2f(-1.25f, 0.29f);
    glVertex2f(-1.25f, 0.47f);
    glVertex2f(-1.85f, 0.47f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-1.8f, 0.47f);
    glVertex2f(-1.35f, 0.47f);
    glVertex2f(-1.35f, 0.61f);
    glVertex2f(-1.8f, 0.61f);
    glEnd();

    glBegin(GL_POLYGON);      ///  Window
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.8f, 0.44f);
    glVertex2f(-1.72f, 0.44f);
    glVertex2f(-1.72f, 0.35f);
    glVertex2f(-1.8f, 0.35f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.62f, 0.44f);
    glVertex2f(-1.56f, 0.44f);
    glVertex2f(-1.56f, 0.35f);
    glVertex2f(-1.62f, 0.35f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.40f, 0.44f);
    glVertex2f(-1.32f, 0.44f);
    glVertex2f(-1.32f, 0.35f);
    glVertex2f(-1.40f, 0.35f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.7f, 0.48f);
    glVertex2f(-1.62f, 0.48f);
    glVertex2f(-1.62f, 0.58f);
    glVertex2f(-1.7f, 0.58f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.5f, 0.48f);
    glVertex2f(-1.42f, 0.48f);
    glVertex2f(-1.42f, 0.58f);
    glVertex2f(-1.5f, 0.58f);
    glEnd();

    glPopMatrix();

    ///  STARS
    if (!isDay) {
        glPointSize(3);
        glBegin(GL_POINTS);
        glColor3ub(255, 255, 255);

        glVertex2f(-1.7f, 1.8f);
        glVertex2f(-1.8f, 1.7f);
        glVertex2f(-1.9f, 1.9f);
        glVertex2f(-1.6f, 1.8f);
        glVertex2f(-1.5f, 1.9f);
        glVertex2f(-1.2f, 1.8f);
        glVertex2f(-1.3f, 1.6f);
        glVertex2f(-1.1f, 1.9f);
        glVertex2f(-1.0f, 1.8f);

        glVertex2f(1.1f, 1.8f);
        glVertex2f(1.2f, 1.8f);
        glVertex2f(1.3f, 1.5f);
        glVertex2f(1.4f, 1.9f);
        glVertex2f(1.5f, 1.0f);
        glVertex2f(1.6f, 1.9f);
        glVertex2f(1.7f, 1.9f);
        glVertex2f(1.8f, 1.8f);

        glVertex2f(-0.7f, 1.8f);
        glVertex2f(-0.8f, 1.7f);
        glVertex2f(-0.9f, 1.9f);
        glVertex2f(-0.6f, 1.8f);
        glVertex2f(-0.5f, 1.9f);
        glVertex2f(-0.2f, 1.8f);
        glVertex2f(-0.3f, 1.6f);
        glVertex2f(-0.1f, 1.9f);
        glVertex2f(0.0f, 1.8f);
        glVertex2f(0.1f, 1.8f);
        glVertex2f(0.2f, 1.8f);
        glVertex2f(0.3f, 1.5f);
        glVertex2f(0.4f, 1.9f);
        glVertex2f(0.5f, 1.0f);
        glVertex2f(0.6f, 1.9f);
        glVertex2f(0.7f, 1.9f);
        glVertex2f(0.8f, 1.8f);
        glEnd();
    }

    /// BACKGROUND TREE
    glBegin(GL_POLYGON);      // LEFT TREE 1
    glColor3ub(34, 139, 34);
    glVertex2f(-1.5f, 0.8f);
    glVertex2f(-2.0f, 0.8f);
    glVertex2f(-1.97f, 0.90f);
    glVertex2f(-1.53f, 0.90f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(-1.53f, 0.90f);
    glVertex2f(-1.97f, 0.90f);
    glVertex2f(-1.85f, 1.05f);
    glVertex2f(-1.65f, 1.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(-1.65f, 1.05f);
    glVertex2f(-1.85f, 1.05f);
    glVertex2f(-1.75f, 1.10f);
    glEnd();

    glBegin(GL_POLYGON);    //LEFF Tree 2
    glColor3ub(34, 139, 34);
    glVertex2f(-1.0f, 0.8f);
    glVertex2f(-1.5f, 0.8f);
    glVertex2f(-1.47f, 0.90f);
    glVertex2f(-1.03f, 0.90f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(-1.03f, 0.90f);
    glVertex2f(-1.47f, 0.90f);
    glVertex2f(-1.35f, 1.05f);
    glVertex2f(-1.15f, 1.05f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(-1.15f, 1.05f);
    glVertex2f(-1.35f, 1.05f);
    glVertex2f(-1.25f, 1.10f);
    glEnd();

    glBegin(GL_POLYGON);    //LEFF Tree 3
    glColor3ub(34, 139, 34);
    glVertex2f(-0.5f, 0.8f);
    glVertex2f(-1.0f, 0.8f);
    glVertex2f(-0.97f, 0.90f);
    glVertex2f(-0.53f, 0.90f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(-0.53f, 0.90f);
    glVertex2f(-0.97f, 0.90f);
    glVertex2f(-0.85f, 1.05f);
    glVertex2f(-0.65f, 1.05f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(-0.65f, 1.05f);
    glVertex2f(-0.85f, 1.05f);
    glVertex2f(-0.75f, 1.10f);
    glEnd();

    glBegin(GL_POLYGON);     //LEFF Tree 4
    glColor3ub(34, 139, 34);
    glVertex2f(-0.0f, 0.8f);
    glVertex2f(-0.5f, 0.8f);
    glVertex2f(-0.47f, 0.90f);
    glVertex2f(-0.03f, 0.90f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(-0.03f, 0.90f);
    glVertex2f(-0.47f, 0.90f);
    glVertex2f(-0.35f, 1.05f);
    glVertex2f(-0.15f, 1.05f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(-0.15f, 1.05f);
    glVertex2f(-0.35f, 1.05f);
    glVertex2f(-0.25f, 1.10f);
    glEnd();

    glBegin(GL_POLYGON);     //RIGHT TREE 5
    glColor3ub(34, 139, 34);
    glVertex2f(1.5f, 0.8f);
    glVertex2f(2.0f, 0.8f);
    glVertex2f(1.97f, 0.90f);
    glVertex2f(1.53f, 0.90f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(1.53f, 0.90f);
    glVertex2f(1.97f, 0.90f);
    glVertex2f(1.85f, 1.05f);
    glVertex2f(1.65f, 1.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(1.65f, 1.05f);
    glVertex2f(1.85f, 1.05f);
    glVertex2f(1.75f, 1.10f);
    glEnd();

    glBegin(GL_POLYGON);     //RIGHT TREE 6
    glColor3ub(34, 139, 34);
    glVertex2f(1.0f, 0.8f);
    glVertex2f(1.5f, 0.8f);
    glVertex2f(1.47f, 0.90f);
    glVertex2f(1.03f, 0.90f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(1.03f, 0.90f);
    glVertex2f(1.47f, 0.90f);
    glVertex2f(1.35f, 1.05f);
    glVertex2f(1.15f, 1.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(1.15f, 1.05f);
    glVertex2f(1.35f, 1.05f);
    glVertex2f(1.25f, 1.10f);
    glEnd();

    glBegin(GL_POLYGON);     //RIGHT TREE 7
    glColor3ub(34, 139, 34);
    glVertex2f(0.5f, 0.8f);
    glVertex2f(1.0f, 0.8f);
    glVertex2f(0.97f, 0.90f);
    glVertex2f(0.53f, 0.90f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(0.53f, 0.90f);
    glVertex2f(0.97f, 0.90f);
    glVertex2f(0.85f, 1.05f);
    glVertex2f(0.65f, 1.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(0.65f, 1.05f);
    glVertex2f(0.85f, 1.05f);
    glVertex2f(0.75f, 1.10f);
    glEnd();

    glBegin(GL_POLYGON);     //RIGHT TREE 8
    glColor3ub(34, 139, 34);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.5f, 0.8f);
    glVertex2f(0.47f, 0.90f);
    glVertex2f(0.03f, 0.90f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(0.03f, 0.90f);
    glVertex2f(0.47f, 0.90f);
    glVertex2f(0.35f, 1.05f);
    glVertex2f(0.15f, 1.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(0.15f, 1.05f);
    glVertex2f(0.35f, 1.05f);
    glVertex2f(0.25f, 1.10f);
    glEnd();

    ///GROUND
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);

    glVertex2f(0.7f, -0.0f);
    glVertex2f(2.0f, -0.0f);
    glVertex2f(2.0f, -2.0f);
    glVertex2f(0.7f, -2.0f);

    glVertex2f(0.5f, -2.0f);
    glVertex2f(0.28f, -1.8f);
    glVertex2f(0.7f, -1.6f);
    glVertex2f(0.7f, -1.75f);
    glVertex2f(0.3f, -1.4f);
    glVertex2f(0.3f, -1.18f);

    glVertex2f(0.7f, -1.0f);

    glVertex2f(0.7f, -1.17f);
    glVertex2f(0.24f, -0.97f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.7f, -0.8f);
    glVertex2f(0.38f, -0.65f);
    glVertex2f(0.7f, -0.44f);

    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.3f, -0.4f);
    glEnd();

    ///HOUSE BODY
    glBegin(GL_POLYGON);
    glColor3ub(205, 133, 63);
    glVertex2f(1.9f, -0.4f);
    glVertex2f(1.1f, -0.4f);
    glVertex2f(1.1f, 0.1f);
    glVertex2f(1.9f, 0.1f);
    glEnd();

    /// HOUSE ROOF
    glBegin(GL_TRIANGLES);
    glColor3ub(139, 0, 0);
    glVertex2f(1.95f, 0.1f);
    glVertex2f(1.05f, 0.1f);
    glVertex2f(1.5f, 0.4f);
    glEnd();

    /// DOOR
    glBegin(GL_POLYGON);
    glColor3ub(101, 67, 33);
    glVertex2f(1.55f, -0.4f);
    glVertex2f(1.45f, -0.4f);
    glVertex2f(1.45f, -0.15f);
    glVertex2f(1.55f, -0.15f);
    glEnd();

    ///LEFT WINDOW
    glBegin(GL_POLYGON);
    glColor3ub(173, 216, 230);
    glVertex2f(1.8f, -0.1f);
    glVertex2f(1.65f, -0.1f);
    glVertex2f(1.65f, 0.05f);
    glVertex2f(1.8f, 0.05f);
    glEnd();

    ///RIGHT WINDOW
    glBegin(GL_POLYGON);
    glColor3ub(173, 216, 230);
    glVertex2f(1.35f, -0.1f);
    glVertex2f(1.2f, -0.1f);
    glVertex2f(1.2f, 0.05f);
    glVertex2f(1.35f, 0.05f);
    glEnd();

    ///CHIMNEY
    glBegin(GL_POLYGON);
    glColor3ub(120, 60, 60);
    glVertex2f(1.35f, 0.15f);
    glVertex2f(1.3f, 0.15f);
    glVertex2f(1.3f, 0.35f);
    glVertex2f(1.35f, 0.35f);
    glEnd();

    /// SMOKE
    if (isDay) {
        glPushMatrix();
        glTranslatef(0.0f, smokeY, 0.0f);

        glColor3ub(200, 200, 200);

        glBegin(GL_POLYGON);
        for (int i = 0; i < 40; i++)
        {
            float a = 2.0f * 3.1416f * i / 40;
            glVertex2f(1.325f + cos(a) * 0.03f,
                       0.40f + sin(a) * 0.03f);
        }
        glEnd();

        glBegin(GL_POLYGON);
        for (int i = 0; i < 40; i++)
        {
            float a = 2.0f * 3.1416f * i / 40;
            glVertex2f(1.28f + cos(a) * 0.025f,
                       0.46f + sin(a) * 0.025f);
        }
        glEnd();

        glPopMatrix();
    }

    ///TREE 1
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(0.91f, -0.1f);      //height
    glVertex2f(0.91f, -0.7f);
    glVertex2f(0.94f, -0.7f);      //height
    glVertex2f(0.94f, -0.1f);
    glEnd();

    ///TREE 2//
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(1.14f, -0.0f);      //height
    glVertex2f(1.14f, -0.7f);
    glVertex2f(1.17f, -0.7f);      //height
    glVertex2f(1.17f, -0.0f);
    glEnd();

    ///TREE3 //
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(1.81f, -0.0f);      //height
    glVertex2f(1.81f, -0.7f);
    glVertex2f(1.84f, -0.7f);      //height
    glVertex2f(1.84f, -0.0f);
    glEnd();

    ///LEAF 1//
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(0.80f, -0.1f);      //height
    glVertex2f(1.05f, -0.1f);
    glVertex2f(0.925f, 0.2f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(0.85f, 0.1f);      //height
    glVertex2f(1.00f, 0.1f);
    glVertex2f(0.925f, 0.4f);
    glEnd();

    ///LEAF 2//
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(1.03f, -0.0f);      ///height
    glVertex2f(1.28f, -0.0f);
    glVertex2f(1.155f, 0.2f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(1.06f, 0.1f);      //height
    glVertex2f(1.25f, 0.1f);
    glVertex2f(1.155f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(1.08f, 0.2f);
    glVertex2f(1.23f, 0.2f);
    glVertex2f(1.155f, 0.5f);
    glEnd();

    ///LEAF 3//
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(1.70f, -0.0f);      //height
    glVertex2f(1.95f, -0.0f);
    glVertex2f(1.825f, 0.2f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(1.74f, 0.1f);      //height
    glVertex2f(1.91f, 0.1f);
    glVertex2f(1.825f, 0.4f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(1.76f, 0.2f);
    glVertex2f(1.89f, 0.2f);
    glVertex2f(1.825f, 0.5f);
    glEnd();


     ///fence
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 102);
    glVertex2f(1.7f, -0.6f);   //width
    glVertex2f(2.0f, -0.60f);
    glVertex2f(2.0f, -0.60f);
    glVertex2f(1.7f, -0.6f);
    glVertex2f(1.7f, -0.5f);   //width
    glVertex2f(2.0f, -0.50f);
    glVertex2f(2.0f, -0.50f);
    glVertex2f(1.7f, -0.5f);
    glVertex2f(1.7f, -0.7f);    //width
    glVertex2f(2.0f, -0.70f);
    glVertex2f(2.0f, -0.70f);
    glVertex2f(1.7f, -0.7f);

    glVertex2f(1.76f, -0.5f);      //height
    glVertex2f(1.76f, -0.7f);
    glVertex2f(1.78f, -0.7f);
    glVertex2f(1.78f, -0.5f);
    glVertex2f(1.86f, -0.5f);      //height
    glVertex2f(1.86f, -0.7f);
    glVertex2f(1.88f, -0.7f);
    glVertex2f(1.88f, -0.5f);
    glVertex2f(1.96f, -0.5f);      //height
    glVertex2f(1.96f, -0.7f);
    glVertex2f(1.98f, -0.7f);
    glVertex2f(1.98f, -0.5f);
    glEnd();

    ///Fence
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 102);
    glVertex2f(0.9f, -0.6f);   //width
    glVertex2f(1.2f, -0.60f);
    glVertex2f(1.2f, -0.60f);
    glVertex2f(0.9f, -0.6f);
    glVertex2f(0.9f, -0.5f);   //width
    glVertex2f(1.2f, -0.50f);
    glVertex2f(1.2f, -0.50f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.9f, -0.7f);    //width
    glVertex2f(1.2f, -0.70f);
    glVertex2f(1.2f, -0.70f);
    glVertex2f(0.9f, -0.7f);

    glVertex2f(0.96f, -0.5f);      //height
    glVertex2f(0.96f, -0.7f);
    glVertex2f(0.98f, -0.7f);
    glVertex2f(0.98f, -0.5f);
    glVertex2f(1.06f, -0.5f);      //height
    glVertex2f(1.06f, -0.7f);
    glVertex2f(1.08f, -0.7f);
    glVertex2f(1.08f, -0.5f);
    glVertex2f(1.16f, -0.5f);      //height
    glVertex2f(1.16f, -0.7f);
    glVertex2f(1.18f, -0.7f);
    glVertex2f(1.18f, -0.5f);
    glEnd();

    /// Ship
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.85f, 0.29f);
    glVertex2f(-1.25f, 0.29f);
    glVertex2f(-1.25f, 0.47f);
    glVertex2f(-1.85f, 0.47f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-1.25f, 0.29f);
    glVertex2f(-1.25f, 0.47f);
    glVertex2f(-1.85f, 0.47f);
    glVertex2f(-1.85f, 0.29f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.8f, 0.47f);
    glVertex2f(-1.35f, 0.47f);
    glVertex2f(-1.35f, 0.61f);
    glVertex2f(-1.8f, 0.61f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.35f, 0.47f);
    glVertex2f(-1.35f, 0.61f);
    glVertex2f(-1.8f, 0.61f);
    glVertex2f(-1.8f, 0.47f);
    glEnd();
    glPopMatrix();

    ///GROUND 1
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);

    glVertex2f(-0.7f, -0.0f);
    glVertex2f(-2.0f, -0.0f);
    glVertex2f(-2.0f, -2.0f);
    glVertex2f(-0.7f, -2.0f);

    glVertex2f(-0.5f, -2.0f);
    glVertex2f(-0.28f, -1.8f);
    glVertex2f(-0.7f, -1.6f);
    glVertex2f(-0.7f, -1.75f);
    glVertex2f(-0.3f, -1.4f);
    glVertex2f(-0.3f, -1.18f);

    glVertex2f(-0.7f, -1.0f);

    glVertex2f(-0.7f, -1.17f);
    glVertex2f(-0.24f, -0.97f);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.7f, -0.8f);
    glVertex2f(-0.38f, -0.65f);
    glVertex2f(-0.7f, -0.44f);

    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.3f, -0.4f);
    glEnd();

    glColor3ub(38, 154, 214);///river
    glColor3ub(153, 153, 102);///way


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);///boat1///
    glVertex2f(0.1f, -1.01f);
    glVertex2f(-0.2f, -1.01f);
    glVertex2f(-0.2f, -1.08f);
    glVertex2f(0.1f, -1.08f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(122, 122, 82);
    glVertex2f(0.2f, -0.93f);
    glVertex2f(0.1f, -1.01f);
    glVertex2f(-0.2f, -1.01f);
    glVertex2f(-0.3f, -0.93f);
    glVertex2f(-0.2f, -0.91f);
    glVertex2f(0.1f, -0.91f);
    glEnd();

    ///boat1
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1f, -1.01f);
    glVertex2f(0.2f, -0.93f);
    glVertex2f(0.1f, -1.08f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-0.2f, -1.01f);
    glVertex2f(-0.3f, -0.93f);
    glVertex2f(-0.2f, -1.08f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1f, -0.91f);
    glVertex2f(-0.2f, -0.91f);
    glVertex2f(0.1f, -0.91f);
    glVertex2f(0.2f, -0.93f);
    glVertex2f(-0.2f, -0.91f);
    glVertex2f(-0.3f, -0.93f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.1f, -0.91f);
    glVertex2f(0.1f, -1.01f);
    glVertex2f(0.0f, -0.91f);
    glVertex2f(0.0f, -1.01f);
    glVertex2f(-0.1f, -0.91f);
    glVertex2f(-0.1f, -1.01f);
    glVertex2f(-0.2f, -0.91f);
    glVertex2f(-0.2f, -1.01f);
    glEnd();

    ///MOON
    if (!isDay) {
        int m;
        GLfloat x4 = 1.66f; GLfloat y4 = 1.8f; GLfloat radius4 = .12f;
        int triangleAmount4 = 20;
        GLfloat twicePi4 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x4, y4);
        for (m = 0; m <= triangleAmount4; m++) {
            glVertex2f(
                x4 + (radius4 * cos(m * twicePi4 / triangleAmount4)),
                y4 + (radius4 * sin(m * twicePi4 / triangleAmount4))
            );
        }
        glEnd();
    }

    ///CLOUD1
    if (isDay) {
        glPushMatrix();
        glTranslatef(cloudX, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.45f, 1.65f);
        glVertex2f(-0.45f, 1.80f);
        glVertex2f(-1.0f, 1.80f);
        glVertex2f(-1.0f, 1.65f);
        glEnd();
        int n;
        GLfloat x5 = -0.45f; GLfloat y5 = 1.73f; GLfloat radius5 = .09f;
        int triangleAmount5 = 20;
        GLfloat twicePi5 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x5, y5);
        for (n = 0; n <= triangleAmount5; n++) {
            glVertex2f(
                x5 + (radius5 * cos(n * twicePi5 / triangleAmount5)),
                y5 + (radius5 * sin(n * twicePi5 / triangleAmount5))
            );
        }
        glEnd();

        int o;
        GLfloat x6 = -1.0f; GLfloat y6 = 1.73f; GLfloat radius6 = .15f;
        int triangleAmount6 = 20;
        GLfloat twicePi6 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x6, y6);
        for (o = 0; o <= triangleAmount6; o++) {
            glVertex2f(
                x6 + (radius6 * cos(o * twicePi6 / triangleAmount6)),
                y6 + (radius6 * sin(o * twicePi6 / triangleAmount6))
            );
        }
        glEnd();

        int p;
        GLfloat x7 = -0.55f; GLfloat y7 = 1.79f; GLfloat radius7 = .07f;
        int triangleAmount7 = 20;
        GLfloat twicePi7 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x7, y7);
        for (p = 0; p <= triangleAmount6; p++) {
            glVertex2f(
                x7 + (radius7 * cos(p * twicePi7 / triangleAmount7)),
                y7 + (radius7 * sin(p * twicePi7 / triangleAmount7))
            );
        }
        glEnd();

        int q;
        GLfloat x8 = -0.7f; GLfloat y8 = 1.80f; GLfloat radius8 = .12f;
        int triangleAmount8 = 20;
        GLfloat twicePi8 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x8, y8);
        for (q = 0; q <= triangleAmount6; q++) {
            glVertex2f(
                x8 + (radius8 * cos(q * twicePi8 / triangleAmount8)),
                y8 + (radius8 * sin(q * twicePi8 / triangleAmount8))
            );
        }
        glEnd();

        int r;
        GLfloat x9 = -0.85f; GLfloat y9 = 1.73f; GLfloat radius9 = .10f;
        int triangleAmount9 = 20;
        GLfloat twicePi9 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x9, y9);
        for (r = 0; r <= triangleAmount6; r++) {
            glVertex2f(
                x9 + (radius9 * cos(r * twicePi9 / triangleAmount9)),
                y9 + (radius9 * sin(r * twicePi9 / triangleAmount9))
            );
        }
        glEnd();

        int s;
        GLfloat x10 = -0.69f; GLfloat y10 = 1.69f; GLfloat radius10 = .14f;
        int triangleAmount10 = 20;
        GLfloat twicePi10 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x10, y10);
        for (s = 0; s <= triangleAmount6; s++) {
            glVertex2f(
                x10 + (radius10 * cos(s * twicePi10 / triangleAmount10)),
                y10 + (radius10 * sin(s * twicePi10 / triangleAmount10))
            );
        }
        glEnd();

        int t;
        GLfloat x11 = -0.53f; GLfloat y11 = 1.69f; GLfloat radius11 = .12f;
        int triangleAmount11 = 20;
        GLfloat twicePi11 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x11, y11);
        for (t = 0; t <= triangleAmount6; t++) {
            glVertex2f(
                x11 + (radius11 * cos(t * twicePi11 / triangleAmount11)),
                y11 + (radius11 * sin(t * twicePi11 / triangleAmount11))
            );
        }
        glEnd();

        glPopMatrix();
    }

    ///CLOUD2
    if (isDay) {
        glPushMatrix();
        glTranslatef(cloudX, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.45f, 1.65f);
        glVertex2f(0.45f, 1.80f);
        glVertex2f(1.0f, 1.80f);
        glVertex2f(1.0f, 1.65f);
        glEnd();
        int n1;
        GLfloat x51 = 0.45f; GLfloat y51 = 1.73f; GLfloat radius51 = .09f;
        int triangleAmount51 = 20;
        GLfloat twicePi51 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x51, y51);
        for (n1 = 0; n1 <= triangleAmount51; n1++) {
            glVertex2f(
                x51 + (radius51 * cos(n1 * twicePi51 / triangleAmount51)),
                y51 + (radius51 * sin(n1 * twicePi51 / triangleAmount51))
            );
        }
        glEnd();

        int o1;
        GLfloat x61 = 1.0f; GLfloat y61 = 1.73f; GLfloat radius61 = .15f;
        int triangleAmount61 = 20;
        GLfloat twicePi61 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x61, y61);
        for (o1 = 0; o1 <= triangleAmount61; o1++) {
            glVertex2f(
                x61 + (radius61 * cos(o1 * twicePi61 / triangleAmount61)),
                y61 + (radius61 * sin(o1 * twicePi61 / triangleAmount61))
            );
        }
        glEnd();

        int p1;
        GLfloat x71 = 0.55f; GLfloat y71 = 1.79f; GLfloat radius71 = .07f;
        int triangleAmount71 = 20;
        GLfloat twicePi71 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x71, y71);
        for (p1 = 0; p1 <= triangleAmount61; p1++) {
            glVertex2f(
                x71 + (radius71 * cos(p1 * twicePi71 / triangleAmount71)),
                y71 + (radius71 * sin(p1 * twicePi71 / triangleAmount71))
            );
        }
        glEnd();

        int q1;
        GLfloat x81 = 0.7f; GLfloat y81 = 1.80f; GLfloat radius81 = .12f;
        int triangleAmount81 = 20;
        GLfloat twicePi81 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x81, y81);
        for (q1 = 0; q1 <= triangleAmount61; q1++) {
            glVertex2f(
                x81 + (radius81 * cos(q1 * twicePi81 / triangleAmount81)),
                y81 + (radius81 * sin(q1 * twicePi81 / triangleAmount81))
            );
        }
        glEnd();

        int r1;
        GLfloat x91 = 0.85f; GLfloat y91 = 1.73f; GLfloat radius91 = .10f;
        int triangleAmount91 = 20;
        GLfloat twicePi91 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x91, y91);
        for (r1 = 0; r1 <= triangleAmount61; r1++) {
            glVertex2f(
                x91 + (radius91 * cos(r1 * twicePi91 / triangleAmount91)),
                y91 + (radius91 * sin(r1 * twicePi91 / triangleAmount91))
            );
        }
        glEnd();

        int s1;
        GLfloat x101 = 0.69f; GLfloat y101 = 1.69f; GLfloat radius101 = .14f;
        int triangleAmount101 = 20;
        GLfloat twicePi101 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x101, y101);
        for (s1 = 0; s1 <= triangleAmount101; s1++) {
            glVertex2f(
                x101 + (radius101 * cos(s1 * twicePi101 / triangleAmount101)),
                y101 + (radius101 * sin(s1 * twicePi101 / triangleAmount101))
            );
        }
        glEnd();

        int t1;
        GLfloat x111 = 0.53f; GLfloat y111 = 1.69f; GLfloat radius111 = .12f;
        int triangleAmount111 = 20;
        GLfloat twicePi111 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x111, y111);
        for (t1 = 0; t1 <= triangleAmount111; t1++) {
            glVertex2f(
                x111 + (radius111 * cos(t1 * twicePi111 / triangleAmount111)),
                y111 + (radius111 * sin(t1 * twicePi111 / triangleAmount111))
            );
        }
        glEnd();

        glPopMatrix();
    }

    ///CLOUD3
    if (isDay) {
        int u;
        GLfloat x12 = -0.1f; GLfloat y12 = 1.33f; GLfloat radius12 = .09f;
        int triangleAmount12 = 20;
        GLfloat twicePi12 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x12, y12);
        for (u = 0; u <= triangleAmount12; u++) {
            glVertex2f(
                x12 + (radius12 * cos(u * twicePi12 / triangleAmount12)),
                y12 + (radius12 * sin(u * twicePi12 / triangleAmount12))
            );
        }
        glEnd();

        int v;
        GLfloat x13 = -0.2f; GLfloat y13 = 1.27f; GLfloat radius13 = .12f;
        int triangleAmount13 = 20;
        GLfloat twicePi13 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x13, y13);
        for (v = 0; v <= triangleAmount13; v++) {
            glVertex2f(
                x13 + (radius13 * cos(v * twicePi13 / triangleAmount13)),
                y13 + (radius13 * sin(v * twicePi13 / triangleAmount13))
            );
        }
        glEnd();

        int w;
        GLfloat x14 = -0.33f; GLfloat y14 = 1.29f; GLfloat radius14 = .09f;
        int triangleAmount14 = 20;
        GLfloat twicePi14 = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(x14, y14);
        for (w = 0; w <= triangleAmount14; w++) {
            glVertex2f(
                x14 + (radius14 * cos(w * twicePi14 / triangleAmount14)),
                y14 + (radius14 * sin(w * twicePi14 / triangleAmount14))
            );
        }
        glEnd();
    }

    ///House
    glBegin(GL_QUADS);
    glColor3f(205, 133, 63); // House body 2
    glVertex2f(-0.9f, 0.1f);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-1.3f, -0.3f);
    glVertex2f(-1.3f, 0.1f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // house upper part 2
    glVertex2f(-1.0f, 0.4f);
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-1.5f, 0.1f);
    glVertex2f(-1.3f, 0.4f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // House door 2
    glVertex2f(-1.0f, -0.0f);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-1.1f, -0.3f);
    glVertex2f(-1.1f, -0.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // House window 2
    glVertex2f(-1.15f, -0.1f);
    glVertex2f(-1.15f, -0.20f);
    glVertex2f(-1.25f, -0.20f);
    glVertex2f(-1.25f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(205, 133, 63); // House body 1
    glVertex2f(-1.3f, -0.0f);
    glVertex2f(-1.8f, -0.0f);
    glVertex2f(-1.8f, -0.5f);
    glVertex2f(-1.3f, -0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // House door 1
    glVertex2f(-1.6f, -0.1f);
    glVertex2f(-1.7f, -0.1f);
    glVertex2f(-1.7f, -0.5f);
    glVertex2f(-1.6f, -0.5f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // House window 1
    glVertex2f(-1.4f, -0.2f);
    glVertex2f(-1.5f, -0.2f);
    glVertex2f(-1.5f, -0.3f);
    glVertex2f(-1.4f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(138, 0, 0);    // house upper part 1
    glVertex2f(-1.2f, 0.0f);
    glVertex2f(-1.9f, 0.0f);
    glVertex2f(-1.7f, 0.3f);
    glVertex2f(-1.4f, 0.3f);
    glEnd();

    glBegin(GL_POLYGON);        //grass1
    glColor3ub(0, 102, 0);
    glVertex2f(-1.89f, -0.5f);
    glVertex2f(-1.86f, -0.450f);
    glVertex2f(-1.84f, -0.150f);
    glVertex2f(-1.87f, -0.350f);
    glVertex2f(-1.89f, -0.5f);
    glVertex2f(-1.92f, -0.450f);
    glVertex2f(-1.94f, -0.150f);
    glVertex2f(-1.91f, -0.350f);
    glVertex2f(-1.89f, -0.5f);
    glVertex2f(-1.88f, -0.350f);
    glVertex2f(-1.89f, -0.150f);
    glVertex2f(-1.90f, -0.350f);
    glEnd();

    glBegin(GL_POLYGON);        //grass2
    glColor3ub(0, 102, 0);
    glVertex2f(-0.90f, -0.6f);
    glVertex2f(-0.87f, -0.550f);
    glVertex2f(-0.85f, -0.250f);
    glVertex2f(-0.88f, -0.450f);
    glVertex2f(-0.90f, -0.6f);
    glVertex2f(-0.89f, -0.550f);
    glVertex2f(-0.90f, -0.250f);
    glVertex2f(-0.91f, -0.450f);
    glVertex2f(-0.90f, -0.6f);
    glVertex2f(-0.93f, -0.550f);
    glVertex2f(-0.95f, -0.250f);
    glVertex2f(-0.92f, -0.450f);
    glEnd();

    glBegin(GL_POLYGON);        //grass3
    glColor3ub(0, 102, 0);
    glVertex2f(-0.60f, -0.5f);
    glVertex2f(-0.57f, -0.450f);
    glVertex2f(-0.55f, -0.150f);
    glVertex2f(-0.58f, -0.350f);
    glVertex2f(-0.60f, -0.5f);
    glVertex2f(-0.59f, -0.450f);
    glVertex2f(-0.60f, -0.150f);
    glVertex2f(-0.61f, -0.350f);
    glVertex2f(-0.60f, -0.5f);
    glVertex2f(-0.63f, -0.450f);
    glVertex2f(-0.65f, -0.150f);
    glVertex2f(-0.62f, -0.350f);
    glEnd();

    glBegin(GL_POLYGON);        //grass4
    glColor3ub(0, 102, 0);
    glVertex2f(-0.79f, -0.57f);
    glVertex2f(-0.76f, -0.450f);
    glVertex2f(-0.74f, -0.150f);
    glVertex2f(-0.78f, -0.350f);
    glVertex2f(-0.79f, -0.57f);
    glVertex2f(-0.78f, -0.450f);
    glVertex2f(-0.79f, -0.150f);
    glVertex2f(-0.80f, -0.350f);
    glVertex2f(-0.79f, -0.57f);
    glVertex2f(-0.82f, -0.450f);
    glVertex2f(-0.84f, -0.150f);
    glVertex2f(-0.81f, -0.350f);
    glEnd();
    glBegin(GL_POLYGON);        //grass5
    glColor3ub(0, 102, 0);
    glVertex2f(-0.69f, -0.53f);
    glVertex2f(-0.66f, -0.450f);
    glVertex2f(-0.64f, -0.150f);
    glVertex2f(-0.68f, -0.350f);
    glVertex2f(-0.69f, -0.53f);
    glVertex2f(-0.68f, -0.450f);
    glVertex2f(-0.69f, -0.150f);
    glVertex2f(-0.70f, -0.350f);
    glVertex2f(-0.69f, -0.53f);
    glVertex2f(-0.72f, -0.450f);
    glVertex2f(-0.74f, -0.150f);
    glVertex2f(-0.71f, -0.350f);
    glEnd();

    ///TREE 1//
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-0.91f, -0.1f);      //height
    glVertex2f(-0.91f, -0.7f);
    glVertex2f(-0.94f, -0.7f);      //height
    glVertex2f(-0.94f, -0.1f);
    glEnd();

    ///LEAF 1
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(-0.80f, -0.1f);      //height
    glVertex2f(-1.05f, -0.1f);
    glVertex2f(-0.925f, 0.2f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(-0.85f, 0.1f);      //height
    glVertex2f(-1.00f, 0.1f);
    glVertex2f(-0.925f, 0.4f);
    glEnd();

    ///TREE3
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(-1.81f, -0.0f);      //height
    glVertex2f(-1.81f, -0.7f);
    glVertex2f(-1.84f, -0.7f);      //height
    glVertex2f(-1.84f, -0.0f);
    glEnd();

    ///LEAF 3
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(-1.70f, -0.0f);      //height
    glVertex2f(-1.95f, -0.0f);
    glVertex2f(-1.825f, 0.2f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 100, 0);
    glVertex2f(-1.74f, 0.1f);      //height
    glVertex2f(-1.91f, 0.1f);
    glVertex2f(-1.825f, 0.4f);
    glEnd();

    ///BIRD
    if (isDay && birdFly) {
        glPushMatrix();
        glTranslatef(birdX, birdY, 0.0f);
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.8f, 1.55f);
        glVertex2f(-1.7f, 1.65f);
        glVertex2f(-1.95f, 1.63f);
        glVertex2f(-1.9f, 1.53f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(217, 217, 217);
        glVertex2f(-1.78f, 1.641f);
        glVertex2f(-1.88f, 1.8f);
        glVertex2f(-1.85f, 1.639f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(242, 242, 242);
        glVertex2f(-1.78f, 1.641f);
        glVertex2f(-1.91f, 1.75f);
        glVertex2f(-1.87f, 1.639f);
        glEnd();

        glPointSize(2.5);
        glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.74f, 1.635f);
        glEnd();
        glPopMatrix();
    }

    ///BIRD
    if (isDay && birdFly) {
        glPushMatrix();
        glTranslatef(birdX, birdY, 0.0f);
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.5f, 1.35f);
        glVertex2f(-1.4f, 1.45f);
        glVertex2f(-1.65f, 1.43f);
        glVertex2f(-1.6f, 1.33f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(217, 217, 217);
        glVertex2f(-1.48f, 1.441f);
        glVertex2f(-1.58f, 1.6f);
        glVertex2f(-1.55f, 1.439f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3ub(242, 242, 242);
        glVertex2f(-1.48f, 1.441f);
        glVertex2f(-1.61f, 1.55f);
        glVertex2f(-1.57f, 1.439f);
        glEnd();

        glPointSize(2.5);
        glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.44f, 1.435f);
        glEnd();
        glPopMatrix();
    }

    ///BIRD 3
    if (isDay && birdFly) {
        glPushMatrix();
        glTranslatef(birdX, birdY, 0.0f);
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 1.15f);
        glVertex2f(0.1f, 1.25f);
        glVertex2f(-0.15f, 1.23f);
        glVertex2f(-0.1f, 1.13f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub(220, 220, 220);
        glVertex2f(0.02f, 1.24f);
        glVertex2f(-0.08f, 1.4f);
        glVertex2f(-0.05f, 1.23f);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub(240, 240, 240);
        glVertex2f(0.02f, 1.24f);
        glVertex2f(-0.11f, 1.35f);
        glVertex2f(-0.07f, 1.23f);
        glEnd();
        glPointSize(2.5);
        glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.06f, 1.21f);
        glEnd();
        glPopMatrix();
    }

    ///SUN
    if (isDay) {
        int s;
        GLfloat sunX = 1.66f; GLfloat sunY2 = 1.8f; GLfloat sunRadius = .15f;
        int triangleAmount = 30;
        GLfloat twicePi = 2.0f * PI;
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255, 223, 0);
        glVertex2f(sunX, sunY2);
        for (s = 0; s <= triangleAmount; s++) {
            glVertex2f(
                sunX + (sunRadius * cos(s * twicePi / triangleAmount)),
                sunY2 + (sunRadius * sin(s * twicePi / triangleAmount))
            );
        }
        glEnd();
    }


}

void drawCity()
{



       ///Sky
    if (isDay) {
    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235); //Blue sky
    glVertex2f(-2.0f, -0.8f);
    glVertex2f( 3.0f, -0.8f);
    glVertex2f( 3.0f,  2.0f);
    glVertex2f(-2.0f,  2.0f);
    glEnd();
}
else {
    glBegin(GL_POLYGON);
    glColor3ub(10, 10, 30); //Dark sky
    glVertex2f(-2.0f, -0.8f);
    glVertex2f( 3.0f, -0.8f);
    glVertex2f( 3.0f,  2.0f);
    glVertex2f(-2.0f,  2.0f);
    glEnd();
}


     ///Sun
if (isDay) {
    int i;
    GLfloat sunX = 1.66f;
    GLfloat sunRadius = 0.12f;
    int sunTriangle = 40;
    GLfloat sunTwicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.9f, 0.0f);
    glVertex2f(sunX, sunY);

    for (i = 0; i <= sunTriangle; i++) {
        glVertex2f(
            sunX + (sunRadius * cos(i * sunTwicePi / sunTriangle)),
            sunY + (sunRadius * sin(i * sunTwicePi / sunTriangle))
        );
    }
    glEnd();
}

      ///Moon
if (!isDay) {
    GLfloat moonX = 1.66f;
    GLfloat moonRadius = 0.12f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(moonX, moonY);

    for (int m = 0; m <= 40; m++) {
        glVertex2f(
            moonX + moonRadius * cos(m * 2 * PI / 40),
            moonY + moonRadius * sin(m * 2 * PI / 40)
        );
    }
    glEnd();
}



    ///Buildings

    ///Building1
    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 255);
    glVertex2f(-2.0f, -0.8f);
    glVertex2f(-1.5f, -0.8f);
    glVertex2f(-1.5f, 0.8f);
    glVertex2f(-2.0f, 0.8f);
    glEnd();

    ///Building2
    glBegin(GL_POLYGON);
    glColor3ub(255, 204, 153);
    glVertex2f(-1.5f, -0.8f);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.5f, 1.0f);
    glEnd();

    ///Building3
    glBegin(GL_POLYGON);
    glColor3ub(204, 204, 102);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(-0.5f, -0.8f);
    glVertex2f(-0.5f, 1.4f);
    glVertex2f(-1.0f, 1.4f);
    glEnd();

    ///Building4
    glBegin(GL_POLYGON);
    glColor3ub(170, 170, 255);
    glVertex2f(-0.5f, -0.8f);
    glVertex2f(0.0f, -0.8f);
    glVertex2f(0.0f, 1.6f);
    glVertex2f(-0.5f, 1.6f);
    glEnd();

    ///Building5
    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 204);
    glVertex2f(0.0f, -0.8f);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(0.5f, 1.2f);
    glVertex2f(0.0f, 1.2f);
    glEnd();

    ///Building6
    glBegin(GL_POLYGON);
    glColor3ub(204, 204, 153);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.5f, 1.0f);
    glEnd();

    ///Building7
    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 204);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.5f, -0.8f);
    glVertex2f(1.5f, 1.3f);
    glVertex2f(1.0f, 1.3f);
    glEnd();

    ///Building8
    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 255);
    glVertex2f(1.5f, -0.8f);
    glVertex2f(2.0f, -0.8f);
    glVertex2f(2.0f, 1.0f);
    glVertex2f(1.5f, 1.0f);
    glEnd();

    ///Building9
    glBegin(GL_POLYGON);
    glColor3ub(255, 204, 255);
    glVertex2f(2.0f, -0.8f);
    glVertex2f(2.5f, -0.8f);
    glVertex2f(2.5f, 1.1f);
    glVertex2f(2.0f, 1.1f);
    glEnd();

   ///Building10
    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 255);
    glVertex2f(2.5f, -0.8f);
    glVertex2f(3.0f, -0.8f);
    glVertex2f(3.0f, 1.2f);
    glVertex2f(2.5f, 1.2f);
    glEnd();


     ///Windows

    glBegin(GL_POLYGON);
    glColor3ub(169, 169, 169);
    glVertex2f(-2.0f, -0.8f);
    glVertex2f(-1.5f, -0.8f);
    glVertex2f(-1.5f, 0.8f);
    glVertex2f(-2.0f, 0.8f);
    glEnd();


    glColor3ub(173, 216, 230);
    glBegin(GL_POLYGON);
    glVertex2f(-1.8f, 0.5f);
    glVertex2f(-1.6f, 0.5f);
    glVertex2f(-1.6f, 0.7f);
    glVertex2f(-1.8f, 0.7f);
    glEnd();


    glColor3ub(176, 224, 230);
    glBegin(GL_POLYGON);
    glVertex2f(-1.8f, 0.1f);
    glVertex2f(-1.6f, 0.1f);
    glVertex2f(-1.6f, 0.3f);
    glVertex2f(-1.8f, 0.3f);
    glEnd();


   glBegin(GL_POLYGON);
   glVertex2f(-1.35f, 0.40f);
   glVertex2f(-1.09f, 0.40f);
   glVertex2f(-1.09f, 0.60f);
   glVertex2f(-1.35f, 0.60f);
   glEnd();


   glBegin(GL_POLYGON);
   glVertex2f(-1.35f, 0.15f);
   glVertex2f(-1.09f, 0.15f);
   glVertex2f(-1.09f, 0.35f);
   glVertex2f(-1.35f, 0.35f);
   glEnd();


   glBegin(GL_POLYGON);
   glVertex2f(-1.35f, -0.10f);
   glVertex2f(-1.09f, -0.10f);
   glVertex2f(-1.09f, 0.10f);
   glVertex2f(-1.35f, 0.10f);
   glEnd();



glColor3ub(173, 216, 230);
glBegin(GL_POLYGON);
glVertex2f(-0.8f, 0.90f);
glVertex2f(-0.6f, 0.90f);
glVertex2f(-0.6f, 1.10f);
glVertex2f(-0.8f, 1.10f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(-0.8f, 0.65f);
glVertex2f(-0.6f, 0.65f);
glVertex2f(-0.6f, 0.85f);
glVertex2f(-0.8f, 0.85f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(-0.8f, 0.40f);
glVertex2f(-0.6f, 0.40f);
glVertex2f(-0.6f, 0.60f);
glVertex2f(-0.8f, 0.60f);
glEnd();


    glColor3ub(173, 216, 230);
glBegin(GL_POLYGON);
glVertex2f(-0.3f, 1.3f);
glVertex2f(-0.1f, 1.3f);
glVertex2f(-0.1f, 1.5f);
glVertex2f(-0.3f, 1.5f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(-0.3f, 0.95f);
glVertex2f(-0.1f, 0.95f);
glVertex2f(-0.1f, 1.1f);
glVertex2f(-0.3f, 1.1f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(-0.3f, 0.9f);
glVertex2f(-0.1f, 0.9f);
glVertex2f(-0.1f, 0.7f);
glVertex2f(-0.3f, 0.7f);
glEnd();



   glColor3ub(173, 216, 230);
glBegin(GL_POLYGON);
glVertex2f(0.2f, 1.0f);
glVertex2f(0.4f, 1.0f);
glVertex2f(0.4f, 1.15f);
glVertex2f(0.2f, 1.15f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(0.2f, 0.75f);
glVertex2f(0.4f, 0.75f);
glVertex2f(0.4f, 0.95f);
glVertex2f(0.2f, 0.95f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(0.2f, 0.45f);
glVertex2f(0.4f, 0.45f);
glVertex2f(0.4f, 0.65f);
glVertex2f(0.2f, 0.65f);
glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(153, 204, 255);
    glVertex2f(0.5f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, 1.6f);
    glVertex2f(0.5f, 1.6f);
    glEnd();
    glColor3ub(173, 216, 230);


glBegin(GL_POLYGON);
glVertex2f(0.7f, 1.35f);
glVertex2f(0.9f, 1.35f);
glVertex2f(0.9f, 1.55f);
glVertex2f(0.7f, 1.55f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(0.7f, 1.05f);
glVertex2f(0.9f, 1.05f);
glVertex2f(0.9f, 1.25f);
glVertex2f(0.7f, 1.25f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(0.7f, 0.75f);
glVertex2f(0.9f, 0.75f);
glVertex2f(0.9f, 0.95f);
glVertex2f(0.7f, 0.95f);
glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(204, 153, 255);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.5f, -0.8f);
    glVertex2f(1.5f, 1.8f);
    glVertex2f(1.0f, 1.8f);
    glEnd();
    glColor3ub(173, 216, 230);


glBegin(GL_POLYGON);
glVertex2f(1.2f, 1.55f);
glVertex2f(1.4f, 1.55f);
glVertex2f(1.4f, 1.70f);
glVertex2f(1.2f, 1.70f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(1.2f, 1.45f);
glVertex2f(1.4f, 1.45f);
glVertex2f(1.4f, 1.30f);
glVertex2f(1.2f, 1.30f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(1.2f, 1.05f);
glVertex2f(1.4f, 1.05f);
glVertex2f(1.4f, 1.25f);
glVertex2f(1.2f, 1.25f);
glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    glVertex2f(1.5f, -0.8f);
    glVertex2f(2.0f, -0.8f);
    glVertex2f(2.0f, 1.4f);
    glVertex2f(1.5f, 1.4f);
    glEnd();


    glColor3ub(173, 216, 230);
glBegin(GL_POLYGON);
glVertex2f(1.7f, 1.20f);
glVertex2f(1.9f, 1.20f);
glVertex2f(1.9f, 1.35f);
glVertex2f(1.7f, 1.35f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(1.7f, 0.95f);
glVertex2f(1.9f, 0.95f);
glVertex2f(1.9f, 1.15f);
glVertex2f(1.7f, 1.15f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(1.7f, 0.65f);
glVertex2f(1.9f, 0.65f);
glVertex2f(1.9f, 0.85f);
glVertex2f(1.7f, 0.85f);
glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(204, 255, 204);
    glVertex2f(2.0f, -0.8f);
    glVertex2f(2.5f, -0.8f);
    glVertex2f(2.5f, 1.2f);
    glVertex2f(2.0f, 1.2f);
    glEnd();


    glColor3ub(173, 216, 230);
glBegin(GL_POLYGON);
glVertex2f(2.2f, 1.05f);
glVertex2f(2.4f, 1.05f);
glVertex2f(2.4f, 1.18f);
glVertex2f(2.2f, 1.18f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(2.2f, 0.75f);
glVertex2f(2.4f, 0.75f);
glVertex2f(2.4f, 0.95f);
glVertex2f(2.2f, 0.95f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(2.2f, 0.45f);
glVertex2f(2.4f, 0.45f);
glVertex2f(2.4f, 0.65f);
glVertex2f(2.2f, 0.65f);
glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(204, 204, 255);
    glVertex2f(2.5f, -0.8f);
    glVertex2f(3.0f, -0.8f);
    glVertex2f(3.0f, 1.6f);
    glVertex2f(2.5f, 1.6f);
    glEnd();
   glColor3ub(173, 216, 230);



glBegin(GL_POLYGON);
glVertex2f(2.7f, 1.15f);
glVertex2f(2.9f, 1.15f);
glVertex2f(2.9f, 1.35f);
glVertex2f(2.7f, 1.35f);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(2.7f, 0.85f);
glVertex2f(2.9f, 0.85f);
glVertex2f(2.9f, 1.05f);
glVertex2f(2.7f, 1.05f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(2.7f, 0.55f);
glVertex2f(2.9f, 0.55f);
glVertex2f(2.9f, 0.75f);
glVertex2f(2.7f, 0.75f);
glEnd();


     ///Road
glBegin(GL_POLYGON);
glColor3ub(50, 50, 50);
glVertex2f(-2.0f, -2.0f);
glVertex2f( 3.0f, -2.0f);
glVertex2f( 3.0f, -0.8f);
glVertex2f(-2.0f, -0.8f);
glEnd();



    glColor3ub(255, 255, 255);

// Dash1
glBegin(GL_POLYGON);
glVertex2f(-1.8f, -1.40f);
glVertex2f(-1.4f, -1.40f);
glVertex2f(-1.4f, -1.30f);
glVertex2f(-1.8f, -1.30f);
glEnd();

// Dash2
glBegin(GL_POLYGON);
glVertex2f(-1.0f, -1.40f);
glVertex2f(-0.6f, -1.40f);
glVertex2f(-0.6f, -1.30f);
glVertex2f(-1.0f, -1.30f);
glEnd();

// Dash3
glBegin(GL_POLYGON);
glVertex2f(-0.2f, -1.40f);
glVertex2f(0.2f, -1.40f);
glVertex2f(0.2f, -1.30f);
glVertex2f(-0.2f, -1.30f);
glEnd();

// Dash4
glBegin(GL_POLYGON);
glVertex2f(0.6f, -1.40f);
glVertex2f(1.0f, -1.40f);
glVertex2f(1.0f, -1.30f);
glVertex2f(0.6f, -1.30f);
glEnd();

// Dash5
glBegin(GL_POLYGON);
glVertex2f(1.4f, -1.40f);
glVertex2f(1.8f, -1.40f);
glVertex2f(1.8f, -1.30f);
glVertex2f(1.4f, -1.30f);
glEnd();

// Dash6
glBegin(GL_POLYGON);
glVertex2f(2.2f, -1.40f);
glVertex2f(2.6f, -1.40f);
glVertex2f(2.6f, -1.30f);
glVertex2f(2.2f, -1.30f);
glEnd();


      ///Wheel
glPushMatrix();
glTranslatef(-1.4f, -0.2f, 0.0f);
glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);
glTranslatef(1.4f, 0.2f, 0.0f);

glColor3ub(120, 120, 120);
glBegin(GL_POLYGON);
glVertex2f(-0.8f, -0.2f);
glVertex2f(-0.9f,  0.1f);
glVertex2f(-1.1f,  0.4f);
glVertex2f(-1.4f,  0.5f);
glVertex2f(-1.7f,  0.4f);
glVertex2f(-1.9f,  0.1f);
glVertex2f(-2.0f, -0.2f);
glVertex2f(-1.9f, -0.5f);
glVertex2f(-1.7f, -0.8f);
glVertex2f(-1.4f, -0.9f);
glVertex2f(-1.1f, -0.8f);
glVertex2f(-0.9f, -0.5f);
glEnd();


///Spoke
glColor3ub(160, 160, 160);
glBegin(GL_LINES);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-0.8f, -0.2f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-2.0f, -0.2f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-1.4f,  0.5f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-1.4f, -0.9f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-1.0f,  0.3f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-1.8f,  0.3f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-1.0f, -0.7f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-1.8f, -0.7f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-0.9f, -0.4f);

glVertex2f(-1.4f, -0.2f);
glVertex2f(-1.9f, -0.4f);

glEnd();


///Cabin

//Right
GLfloat x = -0.80f, y = -0.20f;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 200, 255);
glVertex2f(x, y);
for(i=0;i<=triangleAmount;i++)
    glVertex2f(x+r*cos(i*twicePi/triangleAmount),
               y+r*sin(i*twicePi/triangleAmount));
glEnd();

//Upper-Right
x=-1.05f; y=0.30f;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,0,255);
glVertex2f(x,y);
for(i=0;i<=triangleAmount;i++)
    glVertex2f(x+r*cos(i*twicePi/triangleAmount),
               y+r*sin(i*twicePi/triangleAmount));
glEnd();

//Top
x=-1.40f; y=0.50f;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(180,0,255);
glVertex2f(x,y);
for(i=0;i<=triangleAmount;i++)
    glVertex2f(x+r*cos(i*twicePi/triangleAmount),
               y+r*sin(i*twicePi/triangleAmount));
glEnd();

//Upper-Left
x=-1.75f; y=0.30f;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,150,0);
glVertex2f(x,y);
for(i=0;i<=triangleAmount;i++)
    glVertex2f(x+r*cos(i*twicePi/triangleAmount),
               y+r*sin(i*twicePi/triangleAmount));
glEnd();

//Left
x=-2.00f; y=-0.20f;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0,150,255);
glVertex2f(x,y);
for(i=0;i<=triangleAmount;i++)
    glVertex2f(x+r*cos(i*twicePi/triangleAmount),
               y+r*sin(i*twicePi/triangleAmount));
glEnd();

//Lower-Left
x=-1.75f; y=-0.70f;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(150,255,150);
glVertex2f(x,y);
for(i=0;i<=triangleAmount;i++)
    glVertex2f(x+r*cos(i*twicePi/triangleAmount),
               y+r*sin(i*twicePi/triangleAmount));
glEnd();

//Bottom
x=-1.40f; y=-0.90f;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0,255,120);
glVertex2f(x,y);
for(i=0;i<=triangleAmount;i++)
    glVertex2f(x+r*cos(i*twicePi/triangleAmount),
               y+r*sin(i*twicePi/triangleAmount));
glEnd();

//Lower-Right
x=-1.05f; y=-0.70f;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0,0,255);
glVertex2f(x,y);
for(i=0;i<=triangleAmount;i++)
    glVertex2f(x+r*cos(i*twicePi/triangleAmount),
               y+r*sin(i*twicePi/triangleAmount));
glEnd();

glPopMatrix();


///Car1
glPushMatrix();
glTranslatef(carX, 0.0f, 0.0f);

//Body
glColor3ub(220, 50, 50);
glBegin(GL_POLYGON);
glVertex2f(-1.8f, -1.30f);
glVertex2f(-1.2f, -1.30f);
glVertex2f(-1.2f, -1.15f);
glVertex2f(-1.8f, -1.15f);
glEnd();


//Roof
glBegin(GL_POLYGON);
glVertex2f(-1.65f, -1.15f);
glVertex2f(-1.35f, -1.15f);
glVertex2f(-1.40f, -1.05f);
glVertex2f(-1.60f, -1.05f);
glEnd();

//Wheel
glColor3ub(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2f(-1.65f, -1.30f);
glVertex2f(-1.62f, -1.27f);
glVertex2f(-1.58f, -1.27f);
glVertex2f(-1.55f, -1.30f);
glVertex2f(-1.58f, -1.33f);
glVertex2f(-1.62f, -1.33f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(-1.35f, -1.30f);
glVertex2f(-1.32f, -1.27f);
glVertex2f(-1.28f, -1.27f);
glVertex2f(-1.25f, -1.30f);
glVertex2f(-1.28f, -1.33f);
glVertex2f(-1.32f, -1.33f);
glEnd();

///Car2

//Body
glColor3ub(60, 120, 220);
glBegin(GL_POLYGON);
glVertex2f(-0.3f, -1.30f);
glVertex2f(0.4f, -1.30f);
glVertex2f(0.4f, -1.15f);
glVertex2f(-0.3f, -1.15f);
glEnd();

//Roof
glBegin(GL_POLYGON);
glVertex2f(-0.15f, -1.15f);
glVertex2f(0.25f, -1.15f);
glVertex2f(0.15f, -1.05f);
glVertex2f(-0.05f, -1.05f);
glEnd();

//Wheel
glColor3ub(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2f(-0.15f, -1.30f);
glVertex2f(-0.12f, -1.27f);
glVertex2f(-0.08f, -1.27f);
glVertex2f(-0.05f, -1.30f);
glVertex2f(-0.08f, -1.33f);
glVertex2f(-0.12f, -1.33f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(0.25f, -1.30f);
glVertex2f(0.28f, -1.27f);
glVertex2f(0.32f, -1.27f);
glVertex2f(0.35f, -1.30f);
glVertex2f(0.32f, -1.33f);
glVertex2f(0.28f, -1.33f);
glEnd();


///Car3

//Body
glColor3ub(240, 200, 60);
glBegin(GL_POLYGON);
glVertex2f(1.2f, -1.30f);
glVertex2f(1.9f, -1.30f);
glVertex2f(1.9f, -1.15f);
glVertex2f(1.2f, -1.15f);
glEnd();

//Roof
glBegin(GL_POLYGON);
glVertex2f(1.35f, -1.15f);
glVertex2f(1.75f, -1.15f);
glVertex2f(1.65f, -1.05f);
glVertex2f(1.45f, -1.05f);
glEnd();

//Wheel
glColor3ub(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2f(1.35f, -1.30f);
glVertex2f(1.38f, -1.27f);
glVertex2f(1.42f, -1.27f);
glVertex2f(1.45f, -1.30f);
glVertex2f(1.42f, -1.33f);
glVertex2f(1.38f, -1.33f);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(1.75f, -1.30f);
glVertex2f(1.78f, -1.27f);
glVertex2f(1.82f, -1.27f);
glVertex2f(1.85f, -1.30f);
glVertex2f(1.82f, -1.33f);
glVertex2f(1.78f, -1.33f);
glEnd();

glPopMatrix();

///BIRD1

if (isDay && showBird)
{
    glPushMatrix();
    glTranslatef(birdX1, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-1.8f, 1.55f);
    glVertex2f(-1.7f, 1.65f);
    glVertex2f(-1.95f,1.63f);
    glVertex2f(-1.9f, 1.53f);
    glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.78f, 1.641f);
glVertex2f(-1.88f, 1.80f);
glVertex2f(-1.85f, 1.639f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.78f, 1.641f);
glVertex2f(-1.91f, 1.75f);
glVertex2f(-1.87f, 1.639f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.74f, 1.635f);
glEnd();


///BIRD2
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.5f,  1.35f);
glVertex2f(-1.4f,  1.45f);
glVertex2f(-1.65f, 1.43f);
glVertex2f(-1.6f,  1.33f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.48f, 1.441f);
glVertex2f(-1.58f, 1.60f);
glVertex2f(-1.55f, 1.439f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.48f, 1.441f);
glVertex2f(-1.61f, 1.55f);
glVertex2f(-1.57f, 1.439f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.44f, 1.435f);
glEnd();

///BIRD3
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.2f,  1.50f);
glVertex2f(-1.1f,  1.60f);
glVertex2f(-1.35f, 1.58f);
glVertex2f(-1.30f, 1.48f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.18f, 1.591f);
glVertex2f(-1.28f, 1.75f);
glVertex2f(-1.25f, 1.589f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.18f, 1.591f);
glVertex2f(-1.31f, 1.70f);
glVertex2f(-1.27f, 1.589f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.14f, 1.575f);
glEnd();


glPopMatrix();
}

///Star
glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);


glVertex2f(-1.7f, 1.8f);


glVertex2f(-1.2f, 1.6f);


glVertex2f(-0.8f, 1.9f);


glVertex2f(-0.2f, 1.7f);


glVertex2f(0.4f, 1.85f);


glVertex2f(0.9f, 1.65f);


glVertex2f(1.3f, 1.9f);


glVertex2f(1.9f, 1.75f);


glVertex2f(2.4f, 1.85f);

glEnd();



}

void drawMountain() {

        ///Sky

if (isDay)
{
    glBegin(GL_POLYGON);
    glColor3ub(180, 225, 250);   //Day sky

glVertex2f(-2.0f,  2.0f);
glVertex2f( 2.0f,  2.0f);
glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
    glEnd();
}
else
{
    glBegin(GL_POLYGON);
    glColor3ub(10, 10, 30);      //Night sky


glVertex2f(-2.0f,  2.0f);
glVertex2f( 2.0f,  2.0f);
glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);

    glEnd();
}

///CLOUD
if(isDay){

glPushMatrix();
glTranslatef(_run3, 0.0f, 0.0f);

///CLOUD1
glPushMatrix();
glTranslatef(-0.5f, 1.5f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
for(int i=0;i<200;i++)
{
    float pi = 3.1416f;
    float A = (i * 2 * pi) / 200;
    float r = 0.12f;
    glVertex2f(r*cos(A), r*sin(A));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.38f, 1.45f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
for(int i=0;i<200;i++)
{
    float pi = 3.1416f;
    float A = (i * 2 * pi) / 200;
    float r = 0.15f;
    glVertex2f(r*cos(A), r*sin(A));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.62f, 1.5f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
for(int i=0;i<200;i++)
{
    float pi = 3.1416f;
    float A = (i * 2 * pi) / 200;
    float r = 0.12f;
    glVertex2f(r*cos(A), r*sin(A));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.55f, 1.45f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
for(int i=0;i<200;i++)
{
    float pi = 3.1416f;
    float A = (i * 2 * pi) / 200;
    float r = 0.15f;
    glVertex2f(r*cos(A), r*sin(A));
}
glEnd();
glPopMatrix();

glPopMatrix();


///CLOUD2
glPushMatrix();
glTranslatef(_run3, 0.0f, 0.0f);

glPushMatrix();
glTranslatef(0.5f, 1.5f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
for(int i=0;i<200;i++)
{
    float pi = 3.1416f;
    float A = (i * 2 * pi) / 200;
    float r = 0.12f;
    glVertex2f(r*cos(A), r*sin(A));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.38f, 1.45f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
for(int i=0;i<200;i++)
{
    float pi = 3.1416f;
    float A = (i * 2 * pi) / 200;
    float r = 0.15f;
    glVertex2f(r*cos(A), r*sin(A));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.62f, 1.5f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
for(int i=0;i<200;i++)
{
    float pi = 3.1416f;
    float A = (i * 2 * pi) / 200;
    float r = 0.12f;
    glVertex2f(r*cos(A), r*sin(A));
}
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.55f, 1.45f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
for(int i=0;i<200;i++)
{
    float pi = 3.1416f;
    float A = (i * 2 * pi) / 200;
    float r = 0.15f;
    glVertex2f(r*cos(A), r*sin(A));
}
glEnd();
glPopMatrix();

glPopMatrix();
}


     ///Sun
if (isDay) {
    int i;
    GLfloat sunX = 1.66f;
    GLfloat sunRadius = 0.12f;
    int sunTriangle = 40;
    GLfloat sunTwicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.9f, 0.0f);
    glVertex2f(sunX, sunY);

    for (i = 0; i <= sunTriangle; i++) {
        glVertex2f(
            sunX + (sunRadius * cos(i * sunTwicePi / sunTriangle)),
            sunY + (sunRadius * sin(i * sunTwicePi / sunTriangle))
        );
    }
    glEnd();
}

      ///Moon
if (!isDay) {
    GLfloat moonX = 1.66f;
    GLfloat moonRadius = 0.12f;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(moonX, moonY);

    for (int m = 0; m <= 40; m++) {
        glVertex2f(
            moonX + moonRadius * cos(m * 2 * PI / 40),
            moonY + moonRadius * sin(m * 2 * PI / 40)
        );
    }
    glEnd();
}


///GROUND1
    glBegin(GL_POLYGON);
	glColor3ub(120, 200, 120);


	glVertex2f(-0.7f,  -0.0f);
	glVertex2f(-2.0f,  -0.0f);
    glVertex2f(-2.0f,  -2.0f);
    glVertex2f(-0.7f,  -2.0f);

    glVertex2f(-0.5f,  -2.0f);
    glVertex2f(-0.28f,  -1.8f);
    glVertex2f(-0.7f,  -1.6f);
    glVertex2f(-0.7f,  -1.75f);
    glVertex2f(-0.3f,  -1.4f);
    glVertex2f(-0.3f,  -1.18f);

    glVertex2f(-0.7f,  -1.0f);


    glVertex2f(-0.7f,  -1.17f);
    glVertex2f(-0.24f,  -0.97f);
    glVertex2f(-0.7f,  -0.6f);
    glVertex2f(-0.7f,  -0.8f);
    glVertex2f(-0.38f,  -0.65f);
    glVertex2f(-0.7f,  -0.44f);

    glVertex2f(-0.7f,  -0.6f);
    glVertex2f(-0.3f,  -0.4f);
    glEnd();



   ///GROUND2
   glBegin(GL_POLYGON);
	glColor3ub(120, 200, 120);


	glVertex2f(0.7f,  -0.0f);
	glVertex2f(2.0f,  -0.0f);
    glVertex2f(2.0f,  -2.0f);
    glVertex2f(0.7f,  -2.0f);

    glVertex2f(0.5f,  -2.0f);
    glVertex2f(0.28f,  -1.8f);
    glVertex2f(0.7f,  -1.6f);
    glVertex2f(0.7f,  -1.75f);
    glVertex2f(0.3f,  -1.4f);
    glVertex2f(0.3f,  -1.18f);

    glVertex2f(0.7f,  -1.0f);


    glVertex2f(0.7f,  -1.17f);
    glVertex2f(0.24f,  -0.97f);
    glVertex2f(0.7f,  -0.6f);
    glVertex2f(0.7f,  -0.8f);
    glVertex2f(0.38f,  -0.65f);
    glVertex2f(0.7f,  -0.44f);

    glVertex2f(0.7f,  -0.6f);
    glVertex2f(0.3f,  -0.4f);
    glEnd();


///MOUNTAIN1
glBegin(GL_POLYGON);
glColor3ub(225, 245, 235);


glVertex2f(-2.0f, 0.20f);
glVertex2f(-1.7f, 0.35f);
glVertex2f(-1.4f, 0.50f);
glVertex2f(-1.1f, 0.65f);
glVertex2f(-0.8f, 0.80f);
glVertex2f(-0.5f, 0.95f);
glVertex2f(-0.2f, 0.85f);
glVertex2f( 0.1f, 0.75f);
glVertex2f( 0.4f, 0.85f);
glVertex2f( 0.7f, 1.00f);
glVertex2f( 1.0f, 0.85f);
glVertex2f( 1.3f, 0.70f);
glVertex2f( 1.6f, 0.55f);
glVertex2f( 1.9f, 0.40f);
glVertex2f( 2.0f, 0.35f);

glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
glEnd();


///MOUNTAIN2
glBegin(GL_POLYGON);
glColor3ub(205, 235, 220);


glVertex2f(-2.0f, 0.05f);
glVertex2f(-1.6f, 0.30f);
glVertex2f(-1.2f, 0.55f);
glVertex2f(-0.8f, 0.90f);
glVertex2f(-0.4f, 1.20f);
glVertex2f( 0.0f, 0.95f);
glVertex2f( 0.4f, 0.80f);
glVertex2f( 0.8f, 1.05f);
glVertex2f( 1.2f, 1.30f);
glVertex2f( 1.6f, 0.95f);
glVertex2f( 2.0f, 0.65f);

glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
glEnd();


///MOUNTAIN3
glColor3ub(180, 220, 200);


glVertex2f(-2.0f, -0.10f);
glVertex2f(-1.7f,  0.20f);
glVertex2f(-1.3f,  0.45f);
glVertex2f(-0.9f,  0.75f);
glVertex2f(-0.5f,  1.05f);
glVertex2f(-0.1f,  0.80f);
glVertex2f( 0.3f,  0.60f);
glVertex2f( 0.7f,  0.85f);
glVertex2f( 1.1f,  1.10f);
glVertex2f( 1.5f,  0.80f);
glVertex2f( 1.9f,  0.50f);
glVertex2f( 2.0f,  0.40f);

glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
glEnd();


///TREE 1
glBegin(GL_POLYGON);
glColor3ub(110,70,35);
glVertex2f(0.65f,-0.55f);
glVertex2f(0.68f,-0.55f);
glVertex2f(0.68f,-0.40f);
glVertex2f(0.65f,-0.40f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(40,120,60);
glVertex2f(0.55f,-0.40f);
glVertex2f(0.78f,-0.40f);
glVertex2f(0.67f,-0.15f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.58f,-0.25f);
glVertex2f(0.76f,-0.25f);
glVertex2f(0.67f, 0.00f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.61f,-0.10f);
glVertex2f(0.73f,-0.10f);
glVertex2f(0.67f, 0.15f);
glEnd();


///TREE 2
glBegin(GL_POLYGON);
glColor3ub(110,70,35);
glVertex2f(0.85f,-0.65f);
glVertex2f(0.89f,-0.65f);
glVertex2f(0.89f,-0.45f);
glVertex2f(0.85f,-0.45f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(38,118,58);
glVertex2f(0.72f,-0.45f);
glVertex2f(1.02f,-0.45f);
glVertex2f(0.87f,-0.10f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.75f,-0.25f);
glVertex2f(1.00f,-0.25f);
glVertex2f(0.87f, 0.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.78f,-0.05f);
glVertex2f(0.97f,-0.05f);
glVertex2f(0.87f, 0.25f);
glEnd();


///TREE 3
glBegin(GL_POLYGON);
glColor3ub(105,65,30);
glVertex2f(1.05f,-0.75f);
glVertex2f(1.10f,-0.75f);
glVertex2f(1.10f,-0.50f);
glVertex2f(1.05f,-0.50f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(35,115,55);
glVertex2f(0.85f,-0.50f);
glVertex2f(1.30f,-0.50f);
glVertex2f(1.08f,-0.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.90f,-0.25f);
glVertex2f(1.25f,-0.25f);
glVertex2f(1.08f, 0.20f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.95f,-0.05f);
glVertex2f(1.20f,-0.05f);
glVertex2f(1.08f, 0.45f);
glEnd();


///TREE 4
glBegin(GL_POLYGON);
glColor3ub(100,60,28);
glVertex2f(1.30f,-0.90f);
glVertex2f(1.38f,-0.90f);
glVertex2f(1.38f,-0.55f);
glVertex2f(1.30f,-0.55f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(30,110,50);
glVertex2f(1.00f,-0.55f);
glVertex2f(1.70f,-0.55f);
glVertex2f(1.34f, 0.15f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.08f,-0.20f);
glVertex2f(1.60f,-0.20f);
glVertex2f(1.34f, 0.45f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.15f, 0.05f);
glVertex2f(1.55f, 0.05f);
glVertex2f(1.34f, 0.75f);
glEnd();

///TREE 5 (smaller)
glBegin(GL_POLYGON);
glColor3ub(95,55,25);
glVertex2f(1.58f,-1.00f);
glVertex2f(1.64f,-1.00f);
glVertex2f(1.64f,-0.70f);
glVertex2f(1.58f,-0.70f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(25,105,48);
glVertex2f(1.35f,-0.70f);
glVertex2f(1.90f,-0.70f);
glVertex2f(1.61f,-0.35f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.40f,-0.50f);
glVertex2f(1.85f,-0.50f);
glVertex2f(1.61f,-0.15f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.45f,-0.30f);
glVertex2f(1.80f,-0.30f);
glVertex2f(1.61f, 0.05f);
glEnd();


///TREE 7
glBegin(GL_POLYGON);
glColor3ub(90,50,22);
glVertex2f(0.95f,-0.95f);
glVertex2f(1.00f,-0.95f);
glVertex2f(1.00f,-0.70f);
glVertex2f(0.95f,-0.70f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(18,95,40);
glVertex2f(0.80f,-0.70f);
glVertex2f(1.15f,-0.70f);
glVertex2f(0.98f,-0.40f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.85f,-0.55f);
glVertex2f(1.10f,-0.55f);
glVertex2f(0.98f,-0.20f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.90f,-0.35f);
glVertex2f(1.05f,-0.35f);
glVertex2f(0.98f, 0.00f);
glEnd();

///TREE 8
glColor3ub(85,45,20);
glVertex2f(1.15f,-0.95f);
glVertex2f(1.20f,-0.95f);
glVertex2f(1.20f,-0.70f);
glVertex2f(1.15f,-0.70f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(15,90,38);
glVertex2f(1.00f,-0.70f);
glVertex2f(1.35f,-0.70f);
glVertex2f(1.18f,-0.40f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.05f,-0.55f);
glVertex2f(1.30f,-0.55f);
glVertex2f(1.18f,-0.20f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.10f,-0.35f);
glVertex2f(1.25f,-0.35f);
glVertex2f(1.18f, 0.00f);
glEnd();


/// TREE 6
glBegin(GL_POLYGON);
glColor3ub(95,55,25);
glVertex2f(1.70f,-1.20f);
glVertex2f(1.76f,-1.20f);
glVertex2f(1.76f,-0.90f);
glVertex2f(1.70f,-0.90f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(20,100,45);
glVertex2f(1.45f,-0.90f);
glVertex2f(2.00f,-0.90f);
glVertex2f(1.73f,-0.55f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.50f,-0.75f);
glVertex2f(1.95f,-0.75f);
glVertex2f(1.73f,-0.40f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.55f,-0.60f);
glVertex2f(1.90f,-0.60f);
glVertex2f(1.73f,-0.20f);
glEnd();

/// FRONT TREE
glBegin(GL_POLYGON);
glColor3ub(95,55,25);
glVertex2f(0.85f,-1.20f);
glVertex2f(0.90f,-1.20f);
glVertex2f(0.90f,-0.95f);
glVertex2f(0.85f,-0.95f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(20,100,45);
glVertex2f(0.70f,-0.95f);
glVertex2f(1.05f,-0.95f);
glVertex2f(0.88f,-0.65f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.73f,-0.80f);
glVertex2f(1.02f,-0.80f);
glVertex2f(0.88f,-0.50f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.77f,-0.62f);
glVertex2f(0.98f,-0.62f);
glVertex2f(0.88f,-0.30f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(80,170,90);
glVertex2f(0.90f,-1.20f);
glVertex2f(0.95f,-1.20f);
glVertex2f(0.92f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.95f,-1.20f);
glVertex2f(1.00f,-1.20f);
glVertex2f(0.98f,-1.00f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.00f,-1.20f);
glVertex2f(1.05f,-1.20f);
glVertex2f(1.02f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(75,165,85);
glVertex2f(1.30f,-0.95f);
glVertex2f(1.35f,-0.95f);
glVertex2f(1.32f,-0.80f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.35f,-0.95f);
glVertex2f(1.40f,-0.95f);
glVertex2f(1.38f,-0.78f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(80,170,90);
glVertex2f(0.85f,-1.20f);
glVertex2f(0.90f,-1.20f);
glVertex2f(0.88f,-1.00f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.90f,-1.20f);
glVertex2f(0.95f,-1.20f);
glVertex2f(0.93f,-0.98f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.95f,-1.20f);
glVertex2f(1.00f,-1.20f);
glVertex2f(0.98f,-1.02f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(75,165,85);
glVertex2f(1.10f,-0.95f);
glVertex2f(1.15f,-0.95f);
glVertex2f(1.13f,-0.75f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.15f,-0.95f);
glVertex2f(1.20f,-0.95f);
glVertex2f(1.18f,-0.78f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.20f,-0.95f);
glVertex2f(1.25f,-0.95f);
glVertex2f(1.23f,-0.80f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(70,160,80);
glVertex2f(1.45f,-1.05f);
glVertex2f(1.50f,-1.05f);
glVertex2f(1.48f,-0.85f);
glEnd();


///FLOWRR
glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.05f,-1.05f);
glVertex2f(1.05f,-0.95f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(255,220,70);
glVertex2f(1.03f,-0.95f);
glVertex2f(1.07f,-0.95f);
glVertex2f(1.05f,-0.90f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.30f,-1.00f);
glVertex2f(1.30f,-0.90f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(255,120,170);
glVertex2f(1.28f,-0.90f);
glVertex2f(1.32f,-0.90f);
glVertex2f(1.30f,-0.85f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(0.95f,-1.10f);
glVertex2f(0.95f,-1.00f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(245,245,245);
glVertex2f(0.93f,-1.00f);
glVertex2f(0.97f,-1.00f);
glVertex2f(0.95f,-0.95f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(95,185,105);
glVertex2f(1.65f,-1.30f);
glVertex2f(1.70f,-1.30f);
glVertex2f(1.68f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.70f,-1.30f);
glVertex2f(1.75f,-1.30f);
glVertex2f(1.73f,-1.00f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.75f,-1.30f);
glVertex2f(1.80f,-1.30f);
glVertex2f(1.78f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.80f,-1.30f);
glVertex2f(1.85f,-1.30f);
glVertex2f(1.83f,-1.00f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(80,170,90);
glVertex2f(1.72f,-1.30f);
glVertex2f(1.77f,-1.30f);
glVertex2f(1.75f,-0.95f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.82f,-1.30f);
glVertex2f(1.87f,-1.30f);
glVertex2f(1.85f,-0.92f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.74f,-1.20f);
glVertex2f(1.74f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255,220,70);
glVertex2f(1.72f,-1.05f);
glVertex2f(1.76f,-1.05f);
glVertex2f(1.74f,-1.00f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.90f,-1.18f);
glVertex2f(1.90f,-1.03f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(180,90,200);
glVertex2f(1.88f,-1.03f);
glVertex2f(1.92f,-1.03f);
glVertex2f(1.90f,-0.98f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.82f,-1.22f);
glVertex2f(1.82f,-1.07f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255,130,170);
glVertex2f(1.80f,-1.07f);
glVertex2f(1.84f,-1.07f);
glVertex2f(1.82f,-1.02f);
glEnd();

///GRASS
glColor3ub(70,160,80);

glBegin(GL_TRIANGLES);
glVertex2f(-2.00f,-0.85f);
glVertex2f(-1.95f,-0.85f);
glVertex2f(-1.97f,-0.65f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(-1.85f,-0.90f);
glVertex2f(-1.80f,-0.90f);
glVertex2f(-1.83f,-0.68f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(-1.70f,-0.88f);
glVertex2f(-1.65f,-0.88f);
glVertex2f(-1.68f,-0.65f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(-1.55f,-0.90f);
glVertex2f(-1.50f,-0.90f);
glVertex2f(-1.53f,-0.67f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(-1.40f,-0.92f);
glVertex2f(-1.35f,-0.92f);
glVertex2f(-1.38f,-0.68f);
glEnd();



/// BACK TREE
glBegin(GL_POLYGON);
glColor3ub(110,70,40);
glVertex2f(-1.65f,-1.05f);
glVertex2f(-1.58f,-1.05f);
glVertex2f(-1.58f,-0.75f);
glVertex2f(-1.65f,-0.75f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(50,150,90);

glVertex2f(-1.615f,-0.30f);
glVertex2f(-1.48f,-0.35f);
glVertex2f(-1.40f,-0.45f);
glVertex2f(-1.38f,-0.55f);
glVertex2f(-1.40f,-0.65f);
glVertex2f(-1.48f,-0.75f);
glVertex2f(-1.615f,-0.80f);
glVertex2f(-1.75f,-0.75f);
glVertex2f(-1.83f,-0.65f);
glVertex2f(-1.85f,-0.55f);
glVertex2f(-1.83f,-0.45f);
glVertex2f(-1.75f,-0.35f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(110,70,40);
glVertex2f(-1.95f,-0.95f);
glVertex2f(-1.89f,-0.95f);
glVertex2f(-1.89f,-0.75f);
glVertex2f(-1.95f,-0.75f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(50,150,90);


glVertex2f(-1.92f,-0.40f);
glVertex2f(-1.80f,-0.45f);
glVertex2f(-1.73f,-0.55f);
glVertex2f(-1.71f,-0.65f);
glVertex2f(-1.73f,-0.75f);
glVertex2f(-1.80f,-0.83f);
glVertex2f(-1.92f,-0.87f);
glVertex2f(-2.04f,-0.83f);
glVertex2f(-2.11f,-0.75f);
glVertex2f(-2.13f,-0.65f);
glVertex2f(-2.11f,-0.55f);
glVertex2f(-2.04f,-0.45f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(110,70,40);
glVertex2f(-1.20f,-1.20f);
glVertex2f(-1.10f,-1.20f);
glVertex2f(-1.10f,-0.65f);
glVertex2f(-1.20f,-0.65f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(50,150,90);


glVertex2f(-1.15f, 0.00f);
glVertex2f(-0.95f,-0.05f);
glVertex2f(-0.80f,-0.20f);
glVertex2f(-0.75f,-0.35f);
glVertex2f(-0.80f,-0.50f);
glVertex2f(-0.95f,-0.65f);
glVertex2f(-1.15f,-0.70f);
glVertex2f(-1.35f,-0.65f);
glVertex2f(-1.50f,-0.50f);
glVertex2f(-1.55f,-0.35f);
glVertex2f(-1.50f,-0.20f);
glVertex2f(-1.35f,-0.05f);
glEnd();

///GRASS
  glBegin(GL_POLYGON);
glColor3ub(0, 102, 0);
glVertex2f(-1.89f, -1.30f);
glVertex2f(-1.86f, -1.25f);
glVertex2f(-1.84f, -0.95f);
glVertex2f(-1.87f, -1.15f);
glVertex2f(-1.89f, -1.30f);
glVertex2f(-1.92f, -1.25f);
glVertex2f(-1.94f, -0.95f);
glVertex2f(-1.91f, -1.15f);
glVertex2f(-1.89f, -1.30f);
glVertex2f(-1.88f, -1.15f);
glVertex2f(-1.89f, -0.95f);
glVertex2f(-1.90f, -1.15f);
glEnd();

glBegin(GL_POLYGON);        ///grass2
glColor3ub(0, 102, 0);
glVertex2f(-0.90f, -1.40f);
glVertex2f(-0.87f, -1.35f);
glVertex2f(-0.85f, -1.05f);
glVertex2f(-0.88f, -1.25f);
glVertex2f(-0.90f, -1.40f);
glVertex2f(-0.89f, -1.35f);
glVertex2f(-0.90f, -1.05f);
glVertex2f(-0.91f, -1.25f);
glVertex2f(-0.90f, -1.40f);
glVertex2f(-0.93f, -1.35f);
glVertex2f(-0.95f, -1.05f);
glVertex2f(-0.92f, -1.25f);
glEnd();

glBegin(GL_POLYGON);        ///grass3
glColor3ub(0, 102, 0);
glVertex2f(-0.60f, -1.30f);
glVertex2f(-0.57f, -1.25f);
glVertex2f(-0.55f, -0.95f);
glVertex2f(-0.58f, -1.15f);
glVertex2f(-0.60f, -1.30f);
glVertex2f(-0.59f, -1.25f);
glVertex2f(-0.60f, -0.95f);
glVertex2f(-0.61f, -1.15f);
glVertex2f(-0.60f, -1.30f);
glVertex2f(-0.63f, -1.25f);
glVertex2f(-0.65f, -0.95f);
glVertex2f(-0.62f, -1.15f);
glEnd();

glBegin(GL_POLYGON);        ///grass4
glColor3ub(0, 102, 0);
glVertex2f(-0.79f, -1.37f);
glVertex2f(-0.76f, -1.25f);
glVertex2f(-0.74f, -0.95f);
glVertex2f(-0.78f, -1.15f);
glVertex2f(-0.79f, -1.37f);
glVertex2f(-0.78f, -1.25f);
glVertex2f(-0.79f, -0.95f);
glVertex2f(-0.80f, -1.15f);
glVertex2f(-0.79f, -1.37f);
glVertex2f(-0.82f, -1.25f);
glVertex2f(-0.84f, -0.95f);
glVertex2f(-0.81f, -1.15f);
glEnd();

glBegin(GL_POLYGON);        ///grass5
glColor3ub(0, 102, 0);
glVertex2f(-0.69f, -1.33f);
glVertex2f(-0.66f, -1.25f);
glVertex2f(-0.64f, -0.95f);
glVertex2f(-0.68f, -1.15f);
glVertex2f(-0.69f, -1.33f);
glVertex2f(-0.68f, -1.25f);
glVertex2f(-0.69f, -0.95f);
glVertex2f(-0.70f, -1.15f);
glVertex2f(-0.69f, -1.33f);
glVertex2f(-0.72f, -1.25f);
glVertex2f(-0.74f, -0.95f);
glVertex2f(-0.71f, -1.15f);
glEnd();


 ///rains
if (isRaining && isDay)

{

glPushMatrix();

	glBegin(GL_LINES);
	glColor3ub(255,255,255);
	glLoadIdentity();

    glVertex2f(-.0,1.9);
	glVertex2f(-.0,1.8);
	glVertex2f(-.0,1.6);
	glVertex2f(-.0,1.5);
	glVertex2f(-.0,1.3);
	glVertex2f(-.0,1.2);
	glVertex2f(-.0, 1);
	glVertex2f(-.0,.9);
	glVertex2f(-.0,.7);
	glVertex2f(-.0,.6);
	glVertex2f(-.0,.4);
	glVertex2f(-.0,.3);
	glVertex2f(-.0,.1);
	glVertex2f(-.0,.0);
	glVertex2f(-.1,2);
	glVertex2f(-.1,1.9);
	glVertex2f(-.1,1.7);
	glVertex2f(-.1,1.6);
	glVertex2f(-.1,1.4);
	glVertex2f(-.1,1.3);
	glVertex2f(-.1,1.1);
	glVertex2f(-.1, 1);
	glVertex2f(-.1,.8);
	glVertex2f(-.1,.7);
	glVertex2f(-.1,.5);
	glVertex2f(-.1,.4);
	glVertex2f(-.1,.2);
	glVertex2f(-.1,.1);
    glVertex2f(-.2,1.9);
	glVertex2f(-.2,1.8);
	glVertex2f(-.2,1.6);
	glVertex2f(-.2,1.5);
	glVertex2f(-.2,1.3);
	glVertex2f(-.2,1.2);
	glVertex2f(-.2, 1);
	glVertex2f(-.2,.9);
	glVertex2f(-.2,.7);
	glVertex2f(-.2,.6);
	glVertex2f(-.2,.4);
	glVertex2f(-.2,.3);
	glVertex2f(-.2,.1);
	glVertex2f(-.2,.0);
    glVertex2f(-.3,2);
	glVertex2f(-.3,1.9);
	glVertex2f(-.3,1.7);
	glVertex2f(-.3,1.6);
	glVertex2f(-.3,1.4);
	glVertex2f(-.3,1.3);
	glVertex2f(-.3,1.1);
	glVertex2f(-.3, 1);
	glVertex2f(-.3,.8);
	glVertex2f(-.3,.7);
	glVertex2f(-.3,.5);
	glVertex2f(-.3,.4);
	glVertex2f(-.3,.2);
	glVertex2f(-.3,.1);
    glVertex2f(-.4,1.9);
	glVertex2f(-.4,1.8);
	glVertex2f(-.4,1.6);
	glVertex2f(-.4,1.5);
	glVertex2f(-.4,1.3);
	glVertex2f(-.4,1.2);
	glVertex2f(-.4, 1);
	glVertex2f(-.4,.9);
	glVertex2f(-.4,.7);
	glVertex2f(-.4,.6);
	glVertex2f(-.4,.4);
	glVertex2f(-.4,.3);
	glVertex2f(-.4,.1);
	glVertex2f(-.4,.0);
    glVertex2f(-.5,2);
	glVertex2f(-.5,1.9);
	glVertex2f(-.5,1.7);
	glVertex2f(-.5,1.6);
	glVertex2f(-.5,1.4);
	glVertex2f(-.5,1.3);
	glVertex2f(-.5,1.1);
	glVertex2f(-.5, 1);
	glVertex2f(-.5,.8);
	glVertex2f(-.5,.7);
	glVertex2f(-.5,.5);
	glVertex2f(-.5,.4);
	glVertex2f(-.5,.2);
	glVertex2f(-.5,.1);
    glVertex2f(-.6,1.9);
	glVertex2f(-.6,1.8);
	glVertex2f(-.6,1.6);
	glVertex2f(-.6,1.5);
	glVertex2f(-.6,1.3);
	glVertex2f(-.6,1.2);
	glVertex2f(-.6, 1);
	glVertex2f(-.6,.9);
	glVertex2f(-.6,.7);
	glVertex2f(-.6,.6);
	glVertex2f(-.6,.4);
	glVertex2f(-.6,.3);
	glVertex2f(-.6,.1);
	glVertex2f(-.6,.0);
    glVertex2f(-.7,2);
	glVertex2f(-.7,1.9);
	glVertex2f(-.7,1.7);
	glVertex2f(-.7,1.6);
	glVertex2f(-.7,1.4);
	glVertex2f(-.7,1.3);
	glVertex2f(-.7,1.1);
	glVertex2f(-.7, 1);
	glVertex2f(-.7,.8);
	glVertex2f(-.7,.7);
	glVertex2f(-.7,.5);
	glVertex2f(-.7,.4);
	glVertex2f(-.7,.2);
	glVertex2f(-.7,.1);
    glVertex2f(-.8,1.9);
	glVertex2f(-.8,1.8);
	glVertex2f(-.8,1.6);
	glVertex2f(-.8,1.5);
	glVertex2f(-.8,1.3);
	glVertex2f(-.8,1.2);
	glVertex2f(-.8, 1);
	glVertex2f(-.8,.9);
	glVertex2f(-.8,.7);
	glVertex2f(-.8,.6);
	glVertex2f(-.8,.4);
	glVertex2f(-.8,.3);
	glVertex2f(-.8,.1);
	glVertex2f(-.8,.0);
    glVertex2f(-.9,2);
	glVertex2f(-.9,1.9);
	glVertex2f(-.9,1.7);
	glVertex2f(-.9,1.6);
	glVertex2f(-.9,1.4);
	glVertex2f(-.9,1.3);
	glVertex2f(-.9,1.1);
	glVertex2f(-.9, 1);
	glVertex2f(-.9,.8);
	glVertex2f(-.9,.7);
	glVertex2f(-.9,.5);
	glVertex2f(-.9,.4);
	glVertex2f(-.9,.2);
	glVertex2f(-.9,.1);
    glVertex2f(-1,1.9);
	glVertex2f(-1,1.7);
	glVertex2f(-1,1.6);
	glVertex2f(-1,1.4);
	glVertex2f(-1,1.3);
	glVertex2f(-1,1.1);
	glVertex2f(-1, 1);
	glVertex2f(-1,.8);
	glVertex2f(-1,.7);
	glVertex2f(-1,.5);
	glVertex2f(-1,.4);
	glVertex2f(-1,.2);
	glVertex2f(-1,.1);
	glVertex2f(-1,.0);
    glVertex2f(-1.1,2);
	glVertex2f(-1.1,1.9);
	glVertex2f(-1.1,1.7);
	glVertex2f(-1.1,1.6);
	glVertex2f(-1.1,1.4);
	glVertex2f(-1.1,1.3);
	glVertex2f(-1.1,1.1);
	glVertex2f(-1.1, 1);
	glVertex2f(-1.1,.8);
	glVertex2f(-1.1,.7);
	glVertex2f(-1.1,.5);
	glVertex2f(-1.1,.4);
	glVertex2f(-1.1,.2);
	glVertex2f(-1.1,.1);
    glVertex2f(-1.2,1.9);
	glVertex2f(-1.2,1.8);
	glVertex2f(-1.2,1.6);
	glVertex2f(-1.2,1.5);
	glVertex2f(-1.2,1.3);
	glVertex2f(-1.2,1.2);
	glVertex2f(-1.2, 1);
	glVertex2f(-1.2,.9);
	glVertex2f(-1.2,.7);
	glVertex2f(-1.2,.6);
	glVertex2f(-1.2,.4);
	glVertex2f(-1.2,.3);
	glVertex2f(-1.2,.1);
    glVertex2f(-1.2,.0);
    glVertex2f(-1.3,2);
	glVertex2f(-1.3,1.9);
	glVertex2f(-1.3,1.7);
	glVertex2f(-1.3,1.6);
	glVertex2f(-1.3,1.4);
	glVertex2f(-1.3,1.3);
	glVertex2f(-1.3,1.1);
	glVertex2f(-1.3, 1);
	glVertex2f(-1.3,.8);
	glVertex2f(-1.3,.7);
	glVertex2f(-1.3,.5);
	glVertex2f(-1.3,.4);
	glVertex2f(-1.3,.2);
	glVertex2f(-1.3,.1);
    glVertex2f(-1.4,1.9);
	glVertex2f(-1.4,1.8);
	glVertex2f(-1.4,1.6);
	glVertex2f(-1.4,1.5);
	glVertex2f(-1.4,1.3);
	glVertex2f(-1.4,1.2);
	glVertex2f(-1.4, 1);
	glVertex2f(-1.4,.9);
	glVertex2f(-1.4,.7);
	glVertex2f(-1.4,.6);
	glVertex2f(-1.4,.4);
	glVertex2f(-1.4,.3);
	glVertex2f(-1.4,.1);
	glVertex2f(-1.4,.0);
    glVertex2f(-1.5,2);
	glVertex2f(-1.5,1.9);
	glVertex2f(-1.5,1.7);
	glVertex2f(-1.5,1.6);
	glVertex2f(-1.5,1.4);
	glVertex2f(-1.5,1.3);
	glVertex2f(-1.5,1.1);
	glVertex2f(-1.5, 1);
	glVertex2f(-1.5,.8);
	glVertex2f(-1.5,.7);
	glVertex2f(-1.5,.5);
	glVertex2f(-1.5,.4);
	glVertex2f(-1.5,.2);
	glVertex2f(-1.5,.1);
    glVertex2f(-1.6,1.9);
	glVertex2f(-1.6,1.8);
	glVertex2f(-1.6,1.6);
	glVertex2f(-1.6,1.5);
	glVertex2f(-1.6,1.3);
	glVertex2f(-1.6,1.2);
	glVertex2f(-1.6, 1);
	glVertex2f(-1.6,.9);
	glVertex2f(-1.6,.7);
	glVertex2f(-1.6,.6);
	glVertex2f(-1.6,.4);
	glVertex2f(-1.6,.3);
	glVertex2f(-1.6,.1);
	glVertex2f(-1.6,.0);
    glVertex2f(-1.7,2);
	glVertex2f(-1.7,1.9);
	glVertex2f(-1.7,1.7);
	glVertex2f(-1.7,1.6);
	glVertex2f(-1.7,1.4);
	glVertex2f(-1.7,1.3);
	glVertex2f(-1.7,1.1);
	glVertex2f(-1.7, 1);
	glVertex2f(-1.7,.8);
	glVertex2f(-1.7,.7);
	glVertex2f(-1.7,.5);
	glVertex2f(-1.7,.4);
	glVertex2f(-1.7,.2);
	glVertex2f(-1.7,.1);
    glVertex2f(-1.8,1.9);
	glVertex2f(-1.8,1.8);
	glVertex2f(-1.8,1.6);
	glVertex2f(-1.8,1.5);
	glVertex2f(-1.8,1.3);
	glVertex2f(-1.8,1.2);
	glVertex2f(-1.8, 1);
	glVertex2f(-1.8,.9);
	glVertex2f(-1.8,.7);
	glVertex2f(-1.8,.6);
	glVertex2f(-1.8,.4);
	glVertex2f(-1.8,.3);
	glVertex2f(-1.8,.1);
	glVertex2f(-1.8,.0);
    glVertex2f(-1.9,2);
	glVertex2f(-1.9,1.9);
	glVertex2f(-1.9,1.7);
	glVertex2f(-1.9,1.6);
	glVertex2f(-1.9,1.4);
	glVertex2f(-1.9,1.3);
	glVertex2f(-1.9,1.1);
	glVertex2f(-1.9, 1);
	glVertex2f(-1.9,.8);
	glVertex2f(-1.9,.7);
	glVertex2f(-1.9,.5);
	glVertex2f(-1.9,.4);
	glVertex2f(-1.9,.2);
	glVertex2f(-1.9,.1);
    glVertex2f(.1,2);
	glVertex2f(.1,1.9);
	glVertex2f(.1,1.7);
	glVertex2f(.1,1.6);
	glVertex2f(.1,1.4);
	glVertex2f(.1,1.3);
	glVertex2f(.1,1.1);
	glVertex2f(.1, 1);
	glVertex2f(.1,.8);
	glVertex2f(.1,.7);
	glVertex2f(.1,.5);
	glVertex2f(.1,.4);
	glVertex2f(.1,.2);
	glVertex2f(.1,.1);
    glVertex2f(.2,1.9);
	glVertex2f(.2,1.8);
	glVertex2f(.2,1.6);
	glVertex2f(.2,1.5);
	glVertex2f(.2,1.3);
	glVertex2f(.2,1.2);
	glVertex2f(.2, 1);
	glVertex2f(.2,.9);
	glVertex2f(.2,.7);
	glVertex2f(.2,.6);
	glVertex2f(.2,.4);
	glVertex2f(.2,.3);
	glVertex2f(.2,.1);
	glVertex2f(.2,.0);
    glVertex2f(.3,2);
	glVertex2f(.3,1.9);
	glVertex2f(.3,1.7);
	glVertex2f(.3,1.6);
	glVertex2f(.3,1.4);
	glVertex2f(.3,1.3);
	glVertex2f(.3,1.1);
	glVertex2f(.3, 1);
	glVertex2f(.3,.8);
	glVertex2f(.3,.7);
	glVertex2f(.3,.5);
	glVertex2f(.3,.4);
	glVertex2f(.3,.2);
	glVertex2f(.3,.1);
    glVertex2f(.4,1.9);
	glVertex2f(.4,1.8);
	glVertex2f(.4,1.6);
	glVertex2f(.4,1.5);
	glVertex2f(.4,1.3);
	glVertex2f(.4,1.2);
	glVertex2f(.4, 1);
	glVertex2f(.4,.9);
	glVertex2f(.4,.7);
	glVertex2f(.4,.6);
	glVertex2f(.4,.4);
	glVertex2f(.4,.3);
	glVertex2f(.4,.1);
	glVertex2f(.4,.0);
    glVertex2f(.5,2);
	glVertex2f(.5,1.9);
	glVertex2f(.5,1.7);
	glVertex2f(.5,1.6);
	glVertex2f(.5,1.4);
	glVertex2f(.5,1.3);
	glVertex2f(.5,1.1);
	glVertex2f(.5, 1);
	glVertex2f(.5,.8);
	glVertex2f(.5,.7);
	glVertex2f(.5,.5);
	glVertex2f(.5,.4);
	glVertex2f(.5,.2);
	glVertex2f(.5,.1);
    glVertex2f(.6,1.9);
	glVertex2f(.6,1.8);
	glVertex2f(.6,1.6);
	glVertex2f(.6,1.5);
	glVertex2f(.6,1.3);
	glVertex2f(.6,1.2);
	glVertex2f(.6, 1);
	glVertex2f(.6,.9);
	glVertex2f(.6,.7);
	glVertex2f(.6,.6);
	glVertex2f(.6,.4);
	glVertex2f(.6,.3);
	glVertex2f(.6,.1);
	glVertex2f(.6,.0);
    glVertex2f(.7,2);
	glVertex2f(.7,1.9);
	glVertex2f(.7,1.7);
	glVertex2f(.7,1.6);
	glVertex2f(.7,1.4);
	glVertex2f(.7,1.3);
	glVertex2f(.7,1.1);
	glVertex2f(.7, 1);
	glVertex2f(.7,.8);
	glVertex2f(.7,.7);
	glVertex2f(.7,.5);
	glVertex2f(.7,.4);
	glVertex2f(.7,.2);
	glVertex2f(.7,.1);
    glVertex2f(.8,1.9);
	glVertex2f(.8,1.8);
	glVertex2f(.8,1.6);
	glVertex2f(.8,1.5);
	glVertex2f(.8,1.3);
	glVertex2f(.8,1.2);
	glVertex2f(.8, 1);
	glVertex2f(.8,.9);
	glVertex2f(.8,.7);
	glVertex2f(.8,.6);
	glVertex2f(.8,.4);
	glVertex2f(.8,.3);
	glVertex2f(.8,.1);
	glVertex2f(.8,.0);
    glVertex2f(.9,2);
	glVertex2f(.9,1.9);
	glVertex2f(.9,1.7);
	glVertex2f(.9,1.6);
	glVertex2f(.9,1.4);
	glVertex2f(.9,1.3);
	glVertex2f(.9,1.1);
	glVertex2f(.9, 1);
	glVertex2f(.9,.8);
	glVertex2f(.9,.7);
	glVertex2f(.9,.5);
	glVertex2f(.9,.4);
	glVertex2f(.9,.2);
	glVertex2f(.9,.1);
    glVertex2f(1.0,1.9);
	glVertex2f(1.0,1.7);
	glVertex2f(1.0,1.6);
	glVertex2f(1.0,1.4);
	glVertex2f(1.0,1.3);
	glVertex2f(1.0,1.1);
	glVertex2f(1.0, 1);
	glVertex2f(1.0,.8);
	glVertex2f(1.0,.7);
	glVertex2f(1.0,.5);
	glVertex2f(1.0,.4);
	glVertex2f(1.0,.2);
	glVertex2f(1.0,.1);
	glVertex2f(1.0, .0);
    glVertex2f(1.1,2);
	glVertex2f(1.1,1.9);
	glVertex2f(1.1,1.7);
	glVertex2f(1.1,1.6);
	glVertex2f(1.1,1.4);
	glVertex2f(1.1,1.3);
	glVertex2f(1.1,1.1);
	glVertex2f(1.1, 1);
	glVertex2f(1.1,.8);
	glVertex2f(1.1,.7);
	glVertex2f(1.1,.5);
	glVertex2f(1.1,.4);
	glVertex2f(1.1,.2);
	glVertex2f(1.1,.1);
    glVertex2f(1.2,1.9);
	glVertex2f(1.2,1.8);
	glVertex2f(1.2,1.6);
	glVertex2f(1.2,1.5);
	glVertex2f(1.2,1.3);
	glVertex2f(1.2,1.2);
	glVertex2f(1.2, 1);
	glVertex2f(1.2,.9);
	glVertex2f(1.2,.7);
	glVertex2f(1.2,.6);
	glVertex2f(1.2,.4);
	glVertex2f(1.2,.3);
	glVertex2f(1.2,.1);
    glVertex2f(1.2,.0);
    glVertex2f(1.3,2);
	glVertex2f(1.3,1.9);
	glVertex2f(1.3,1.7);
	glVertex2f(1.3,1.6);
	glVertex2f(1.3,1.4);
	glVertex2f(1.3,1.3);
	glVertex2f(1.3,1.1);
	glVertex2f(1.3, 1);
	glVertex2f(1.3,.8);
	glVertex2f(1.3,.7);
	glVertex2f(1.3,.5);
	glVertex2f(1.3,.4);
	glVertex2f(1.3,.2);
	glVertex2f(1.3,.1);
	glVertex2f(1.4,1.9);
	glVertex2f(1.4,1.8);
	glVertex2f(1.4,1.6);
	glVertex2f(1.4,1.5);
	glVertex2f(1.4,1.3);
	glVertex2f(1.4,1.2);
	glVertex2f(1.4, 1);
	glVertex2f(1.4,.9);
	glVertex2f(1.4,.7);
	glVertex2f(1.4,.6);
	glVertex2f(1.4,.4);
	glVertex2f(1.4,.3);
	glVertex2f(1.4,.1);
	glVertex2f(1.4,.0);
    glVertex2f(1.5,2);
	glVertex2f(1.5,1.9);
	glVertex2f(1.5,1.7);
	glVertex2f(1.5,1.6);
	glVertex2f(1.5,1.4);
	glVertex2f(1.5,1.3);
	glVertex2f(1.5,1.1);
	glVertex2f(1.5, 1);
	glVertex2f(1.5,.8);
	glVertex2f(1.5,.7);
	glVertex2f(1.5,.5);
	glVertex2f(1.5,.4);
	glVertex2f(1.5,.2);
	glVertex2f(1.5,.1);
    glVertex2f(1.6,1.9);
	glVertex2f(1.6,1.8);
	glVertex2f(1.6,1.6);
	glVertex2f(1.6,1.5);
	glVertex2f(1.6,1.3);
	glVertex2f(1.6,1.2);
	glVertex2f(1.6, 1);
	glVertex2f(1.6,.9);
	glVertex2f(1.6,.7);
	glVertex2f(1.6,.6);
	glVertex2f(1.6,.4);
	glVertex2f(1.6,.3);
	glVertex2f(1.6,.1);
	glVertex2f(1.6,.0);
    glVertex2f(1.7,2);
	glVertex2f(1.7,1.9);
	glVertex2f(1.7,1.7);
	glVertex2f(1.7,1.6);
	glVertex2f(1.7,1.4);
	glVertex2f(1.7,1.3);
	glVertex2f(1.7,1.1);
	glVertex2f(1.7, 1);
	glVertex2f(1.7,.8);
	glVertex2f(1.7,.7);
	glVertex2f(1.7,.5);
	glVertex2f(1.7,.4);
	glVertex2f(1.7,.2);
	glVertex2f(1.7,.1);
    glVertex2f(1.8,1.9);
	glVertex2f(1.8,1.8);
	glVertex2f(1.8,1.6);
	glVertex2f(1.8,1.5);
	glVertex2f(1.8,1.3);
	glVertex2f(1.8,1.2);
	glVertex2f(1.8, 1);
	glVertex2f(1.8,.9);
	glVertex2f(1.8,.7);
	glVertex2f(1.8,.6);
	glVertex2f(1.8,.4);
	glVertex2f(1.8,.3);
	glVertex2f(1.8,.1);
	glVertex2f(1.8,.0);
    glVertex2f(1.9,2);
	glVertex2f(1.9,1.9);
	glVertex2f(1.9,1.7);
	glVertex2f(1.9,1.6);
	glVertex2f(1.9,1.4);
	glVertex2f(1.9,1.3);
	glVertex2f(1.9,1.1);
	glVertex2f(1.9, 1);
	glVertex2f(1.9,.8);
	glVertex2f(1.9,.7);
	glVertex2f(1.9,.5);
	glVertex2f(1.9,.4);
	glVertex2f(1.9,.2);
	glVertex2f(1.9,.1);
    glVertex2f(-.0,-2);
    glVertex2f(-.0,-1.9);
	glVertex2f(-.0,-1.8);
	glVertex2f(-.0,-1.6);
	glVertex2f(-.0,-1.5);
	glVertex2f(-.0,-1.3);
	glVertex2f(-.0,-1.2);
	glVertex2f(-.0, -1);
	glVertex2f(-.0,-.9);
	glVertex2f(-.0,-.7);
	glVertex2f(-.0,-.6);
	glVertex2f(-.0,-.4);
	glVertex2f(-.0,-.3);
	glVertex2f(-.0,-.1);
    glVertex2f(-.1,-1.9);
	glVertex2f(-.1,-1.7);
	glVertex2f(-.1,-1.6);
	glVertex2f(-.1,-1.4);
	glVertex2f(-.1,-1.3);
	glVertex2f(-.1,-1.1);
	glVertex2f(-.1, -1);
	glVertex2f(-.1,-.8);
	glVertex2f(-.1,-.7);
	glVertex2f(-.1,-.5);
	glVertex2f(-.1,-.4);
	glVertex2f(-.1,-.2);
	glVertex2f(-.1,-.1);
	glVertex2f(-.1,-.0);
    glVertex2f(-.2,-2);
	glVertex2f(-.2,-1.9);
	glVertex2f(-.2,-1.8);
	glVertex2f(-.2,-1.6);
	glVertex2f(-.2,-1.5);
	glVertex2f(-.2,-1.3);
	glVertex2f(-.2,-1.2);
	glVertex2f(-.2, -1);
	glVertex2f(-.2,-.9);
	glVertex2f(-.2,-.7);
	glVertex2f(-.2,-.6);
	glVertex2f(-.2,-.4);
	glVertex2f(-.2,-.3);
	glVertex2f(-.2,-.1);
    glVertex2f(-.3,-1.9);
	glVertex2f(-.3,-1.7);
	glVertex2f(-.3,-1.6);
	glVertex2f(-.3,-1.4);
	glVertex2f(-.3,-1.3);
	glVertex2f(-.3,-1.1);
	glVertex2f(-.3, -1);
	glVertex2f(-.3,-.8);
	glVertex2f(-.3,-.7);
	glVertex2f(-.3,-.5);
	glVertex2f(-.3,-.4);
	glVertex2f(-.3,-.2);
	glVertex2f(-.3,-.1);
	glVertex2f(-.3,-.0);
    glVertex2f(-.4,-2);
	glVertex2f(-.4,-1.9);
	glVertex2f(-.4,-1.8);
	glVertex2f(-.4,-1.6);
	glVertex2f(-.4,-1.5);
	glVertex2f(-.4,-1.3);
	glVertex2f(-.4,-1.2);
	glVertex2f(-.4, -1);
	glVertex2f(-.4,-.9);
	glVertex2f(-.4,-.7);
	glVertex2f(-.4,-.6);
	glVertex2f(-.4,-.4);
	glVertex2f(-.4,-.3);
	glVertex2f(-.4,-.1);
    glVertex2f(-.5,-1.9);
	glVertex2f(-.5,-1.7);
	glVertex2f(-.5,-1.6);
	glVertex2f(-.5,-1.4);
	glVertex2f(-.5,-1.3);
	glVertex2f(-.5,-1.1);
	glVertex2f(-.5, -1);
	glVertex2f(-.5,-.8);
	glVertex2f(-.5,-.7);
	glVertex2f(-.5,-.5);
	glVertex2f(-.5,-.4);
	glVertex2f(-.5,-.2);
	glVertex2f(-.5,-.1);
	glVertex2f(-.5,-.0);
    glVertex2f(-.6,-2);
	glVertex2f(-.6,-1.9);
	glVertex2f(-.6,-1.8);
	glVertex2f(-.6,-1.6);
	glVertex2f(-.6,-1.5);
	glVertex2f(-.6,-1.3);
	glVertex2f(-.6,-1.2);
	glVertex2f(-.6, -1);
	glVertex2f(-.6,-.9);
	glVertex2f(-.6,-.7);
	glVertex2f(-.6,-.6);
	glVertex2f(-.6,-.4);
	glVertex2f(-.6,-.3);
	glVertex2f(-.6,-.1);
    glVertex2f(-.7,-1.9);
	glVertex2f(-.7,-1.7);
	glVertex2f(-.7,-1.6);
	glVertex2f(-.7,-1.4);
	glVertex2f(-.7,-1.3);
	glVertex2f(-.7,-1.1);
	glVertex2f(-.7, -1);
	glVertex2f(-.7,-.8);
	glVertex2f(-.7,-.7);
	glVertex2f(-.7,-.5);
	glVertex2f(-.7,-.4);
	glVertex2f(-.7,-.2);
	glVertex2f(-.7,-.1);
    glVertex2f(-.7,-.0);
    glVertex2f(-.8,-2);
	glVertex2f(-.8,-1.9);
	glVertex2f(-.8,-1.8);
	glVertex2f(-.8,-1.6);
	glVertex2f(-.8,-1.5);
	glVertex2f(-.8,-1.3);
	glVertex2f(-.8,-1.2);
	glVertex2f(-.8, -1);
	glVertex2f(-.8,-.9);
	glVertex2f(-.8,-.7);
	glVertex2f(-.8,-.6);
	glVertex2f(-.8,-.4);
	glVertex2f(-.8,-.3);
	glVertex2f(-.8,-.1);
	glVertex2f(-.9,-1.9);
	glVertex2f(-.9,-1.7);
	glVertex2f(-.9,-1.6);
	glVertex2f(-.9,-1.4);
	glVertex2f(-.9,-1.3);
	glVertex2f(-.9,-1.1);
	glVertex2f(-.9, -1);
	glVertex2f(-.9,-.8);
	glVertex2f(-.9,-.7);
	glVertex2f(-.9,-.5);
	glVertex2f(-.9,-.4);
	glVertex2f(-.9,-.2);
	glVertex2f(-.9,-.1);
	glVertex2f(-.9,-.0);
    glVertex2f(-1,-2);
	glVertex2f(-1,-1.9);
	glVertex2f(-1,-1.7);
	glVertex2f(-1,-1.6);
	glVertex2f(-1,-1.4);
	glVertex2f(-1,-1.3);
	glVertex2f(-1,-1.1);
	glVertex2f(-1, -1);
	glVertex2f(-1,-.8);
	glVertex2f(-1,-.7);
	glVertex2f(-1,-.5);
	glVertex2f(-1,-.4);
	glVertex2f(-1,-.2);
	glVertex2f(-1,-.1);
    glVertex2f(-1.1,-1.9);
	glVertex2f(-1.1,-1.7);
	glVertex2f(-1.1,-1.6);
	glVertex2f(-1.1,-1.4);
	glVertex2f(-1.1,-1.3);
	glVertex2f(-1.1,-1.1);
	glVertex2f(-1.1, -1);
	glVertex2f(-1.1,-.8);
	glVertex2f(-1.1,-.7);
	glVertex2f(-1.1,-.5);
	glVertex2f(-1.1,-.4);
	glVertex2f(-1.1,-.2);
	glVertex2f(-1.1,-.1);
	glVertex2f(-1.1,-.0);
    glVertex2f(-1.2,-2);
    glVertex2f(-1.2,-1.9);
	glVertex2f(-1.2,-1.8);
	glVertex2f(-1.2,-1.6);
	glVertex2f(-1.2,-1.5);
	glVertex2f(-1.2,-1.3);
	glVertex2f(-1.2,-1.2);
	glVertex2f(-1.2, -1);
	glVertex2f(-1.2,-.9);
	glVertex2f(-1.2,-.7);
	glVertex2f(-1.2,-.6);
	glVertex2f(-1.2,-.4);
	glVertex2f(-1.2,-.3);
	glVertex2f(-1.2,-.1);
    glVertex2f(-1.3,-1.9);
	glVertex2f(-1.3,-1.7);
	glVertex2f(-1.3,-1.6);
	glVertex2f(-1.3,-1.4);
	glVertex2f(-1.3,-1.3);
	glVertex2f(-1.3,-1.1);
	glVertex2f(-1.3, -1);
	glVertex2f(-1.3,-.8);
	glVertex2f(-1.3,-.7);
	glVertex2f(-1.3,-.5);
	glVertex2f(-1.3,-.4);
	glVertex2f(-1.3,-.2);
	glVertex2f(-1.3,-.1);
    glVertex2f(-1.3,-.0);
    glVertex2f(-1.4,-2);
    glVertex2f(-1.4,-1.9);
	glVertex2f(-1.4,-1.8);
	glVertex2f(-1.4,-1.6);
	glVertex2f(-1.4,-1.5);
	glVertex2f(-1.4,-1.3);
	glVertex2f(-1.4,-1.2);
	glVertex2f(-1.4, -1);
	glVertex2f(-1.4,-.9);
	glVertex2f(-1.4,-.7);
	glVertex2f(-1.4,-.6);
	glVertex2f(-1.4,-.4);
	glVertex2f(-1.4,-.3);
	glVertex2f(-1.4,-.1);
    glVertex2f(-1.5,-1.9);
	glVertex2f(-1.5,-1.7);
	glVertex2f(-1.5,-1.6);
	glVertex2f(-1.5,-1.4);
	glVertex2f(-1.5,-1.3);
	glVertex2f(-1.5,-1.1);
	glVertex2f(-1.5, -1);
	glVertex2f(-1.5,-.8);
	glVertex2f(-1.5,-.7);
	glVertex2f(-1.5,-.5);
	glVertex2f(-1.5,-.4);
	glVertex2f(-1.5,-.2);
	glVertex2f(-1.5,-.1);
	glVertex2f(-1.5,-.0);
    glVertex2f(-1.6,-2);
    glVertex2f(-1.6,-1.9);
	glVertex2f(-1.6,-1.8);
	glVertex2f(-1.6,-1.6);
	glVertex2f(-1.6,-1.5);
	glVertex2f(-1.6,-1.3);
	glVertex2f(-1.6,-1.2);
	glVertex2f(-1.6, -1);
	glVertex2f(-1.6,-.9);
	glVertex2f(-1.6,-.7);
	glVertex2f(-1.6,-.6);
	glVertex2f(-1.6,-.4);
	glVertex2f(-1.6,-.3);
	glVertex2f(-1.6,-.1);
    glVertex2f(-1.7,-1.9);
	glVertex2f(-1.7,-1.7);
	glVertex2f(-1.7,-1.6);
	glVertex2f(-1.7,-1.4);
	glVertex2f(-1.7,-1.3);
	glVertex2f(-1.7,-1.1);
	glVertex2f(-1.7, -1);
	glVertex2f(-1.7,-.8);
	glVertex2f(-1.7,-.7);
	glVertex2f(-1.7,-.5);
	glVertex2f(-1.7,-.4);
	glVertex2f(-1.7,-.2);
	glVertex2f(-1.7,-.1);
	glVertex2f(-1.7,-.0);
    glVertex2f(-1.8,-2);
    glVertex2f(-1.8,-1.9);
	glVertex2f(-1.8,-1.8);
	glVertex2f(-1.8,-1.6);
	glVertex2f(-1.8,-1.5);
	glVertex2f(-1.8,-1.3);
	glVertex2f(-1.8,-1.2);
	glVertex2f(-1.8, -1);
	glVertex2f(-1.8,-.9);
	glVertex2f(-1.8,-.7);
	glVertex2f(-1.8,-.6);
	glVertex2f(-1.8,-.4);
	glVertex2f(-1.8,-.3);
	glVertex2f(-1.8,-.1);
    glVertex2f(-1.9,-1.9);
	glVertex2f(-1.9,-1.7);
	glVertex2f(-1.9,-1.6);
	glVertex2f(-1.9,-1.4);
	glVertex2f(-1.9,-1.3);
	glVertex2f(-1.9,-1.1);
	glVertex2f(-1.9, -1);
	glVertex2f(-1.9,-.8);
	glVertex2f(-1.9,-.7);
	glVertex2f(-1.9,-.5);
	glVertex2f(-1.9,-.4);
	glVertex2f(-1.9,-.2);
	glVertex2f(-1.9,-.1);
	glVertex2f(-1.9,-.0);
    glVertex2f(.1,-2);
	glVertex2f(.1,-1.9);
	glVertex2f(.1,-1.7);
	glVertex2f(.1,-1.6);
	glVertex2f(.1,-1.4);
	glVertex2f(.1,-1.3);
	glVertex2f(.1,-1.1);
	glVertex2f(.1, -1);
	glVertex2f(.1,-.8);
	glVertex2f(.1,-.7);
	glVertex2f(.1,-.5);
	glVertex2f(.1,-.4);
	glVertex2f(.1,-.2);
	glVertex2f(.1,-.1);
    glVertex2f(.2,-1.9);
	glVertex2f(.2,-1.8);
	glVertex2f(.2,-1.6);
	glVertex2f(.2,-1.5);
	glVertex2f(.2,-1.3);
	glVertex2f(.2,-1.2);
	glVertex2f(.2, -1);
	glVertex2f(.2,-.9);
	glVertex2f(.2,-.7);
	glVertex2f(.2,-.6);
	glVertex2f(.2,-.4);
	glVertex2f(.2,-.3);
	glVertex2f(.2,-.1);
	glVertex2f(.2,-.0);
    glVertex2f(.3,-2);
	glVertex2f(.3,-1.9);
	glVertex2f(.3,-1.7);
	glVertex2f(.3,-1.6);
	glVertex2f(.3,-1.4);
	glVertex2f(.3,-1.3);
	glVertex2f(.3,-1.1);
	glVertex2f(.3, -1);
	glVertex2f(.3,-.8);
	glVertex2f(.3,-.7);
	glVertex2f(.3,-.5);
	glVertex2f(.3,-.4);
	glVertex2f(.3,-.2);
	glVertex2f(.3,-.1);
    glVertex2f(.4,-1.9);
	glVertex2f(.4,-1.8);
	glVertex2f(.4,-1.6);
	glVertex2f(.4,-1.5);
	glVertex2f(.4,-1.3);
	glVertex2f(.4,-1.2);
	glVertex2f(.4, -1);
	glVertex2f(.4,-.9);
	glVertex2f(.4,-.7);
	glVertex2f(.4,-.6);
	glVertex2f(.4,-.4);
	glVertex2f(.4,-.3);
	glVertex2f(.4,-.1);
	glVertex2f(.4,-.0);
    glVertex2f(.5,-2);
	glVertex2f(.5,-1.9);
	glVertex2f(.5,-1.7);
	glVertex2f(.5,-1.6);
	glVertex2f(.5,-1.4);
	glVertex2f(.5,-1.3);
	glVertex2f(.5,-1.1);
	glVertex2f(.5, -1);
	glVertex2f(.5,-.8);
	glVertex2f(.5,-.7);
	glVertex2f(.5,-.5);
	glVertex2f(.5,-.4);
	glVertex2f(.5,-.2);
	glVertex2f(.5,-.1);
    glVertex2f(.6,-1.9);
	glVertex2f(.6,-1.8);
	glVertex2f(.6,-1.6);
	glVertex2f(.6,-1.5);
	glVertex2f(.6,-1.3);
	glVertex2f(.6,-1.2);
	glVertex2f(.6, -1);
	glVertex2f(.6,-.9);
	glVertex2f(.6,-.7);
	glVertex2f(.6,-.6);
	glVertex2f(.6,-.4);
	glVertex2f(.6,-.3);
	glVertex2f(.6,-.1);
	glVertex2f(.6,-.0);
    glVertex2f(.7,-2);
	glVertex2f(.7,-1.9);
	glVertex2f(.7,-1.7);
	glVertex2f(.7,-1.6);
	glVertex2f(.7,-1.4);
	glVertex2f(.7,-1.3);
	glVertex2f(.7,-1.1);
	glVertex2f(.7, -1);
	glVertex2f(.7,-.8);
	glVertex2f(.7,-.7);
	glVertex2f(.7,-.5);
	glVertex2f(.7,-.4);
	glVertex2f(.7,-.2);
	glVertex2f(.7,-.1);
    glVertex2f(.8,-1.9);
	glVertex2f(.8,-1.8);
	glVertex2f(.8,-1.6);
	glVertex2f(.8,-1.5);
	glVertex2f(.8,-1.3);
	glVertex2f(.8,-1.2);
	glVertex2f(.8, -1);
	glVertex2f(.8,-.9);
	glVertex2f(.8,-.7);
	glVertex2f(.8,-.6);
	glVertex2f(.8,-.4);
	glVertex2f(.8,-.3);
	glVertex2f(.8,-.1);
	glVertex2f(.8,-.0);
    glVertex2f(.9,-2);
	glVertex2f(.9,-1.9);
	glVertex2f(.9,-1.7);
	glVertex2f(.9,-1.6);
	glVertex2f(.9,-1.4);
	glVertex2f(.9,-1.3);
	glVertex2f(.9,-1.1);
	glVertex2f(.9, -1);
	glVertex2f(.9,-.8);
	glVertex2f(.9,-.7);
	glVertex2f(.9,-.5);
	glVertex2f(.9,-.4);
	glVertex2f(.9,-.2);
	glVertex2f(.9,-.1);
    glVertex2f(1.0,-1.9);
	glVertex2f(1.0,-1.7);
	glVertex2f(1.0,-1.6);
	glVertex2f(1.0,-1.4);
	glVertex2f(1.0,-1.3);
	glVertex2f(1.0,-1.1);
	glVertex2f(1.0, -1);
	glVertex2f(1.0,-.8);
	glVertex2f(1.0,-.7);
	glVertex2f(1.0,-.5);
	glVertex2f(1.0,-.4);
	glVertex2f(1.0,-.2);
	glVertex2f(1.0,-.1);
	glVertex2f(1.0,- .0);
    glVertex2f(1.1,-2);
	glVertex2f(1.1,-1.9);
	glVertex2f(1.1,-1.7);
	glVertex2f(1.1,-1.6);
	glVertex2f(1.1,-1.4);
	glVertex2f(1.1,-1.3);
	glVertex2f(1.1,-1.1);
	glVertex2f(1.1, -1);
	glVertex2f(1.1,-.8);
	glVertex2f(1.1,-.7);
	glVertex2f(1.1,-.5);
	glVertex2f(1.1,-.4);
	glVertex2f(1.1,-.2);
	glVertex2f(1.1,-.1);
    glVertex2f(1.2,-1.9);
	glVertex2f(1.2,-1.8);
	glVertex2f(1.2,-1.6);
	glVertex2f(1.2,-1.5);
	glVertex2f(1.2,-1.3);
	glVertex2f(1.2,-1.2);
	glVertex2f(1.2, -1);
	glVertex2f(1.2,-.9);
	glVertex2f(1.2,-.7);
	glVertex2f(1.2,-.6);
	glVertex2f(1.2,-.4);
	glVertex2f(1.2,-.3);
	glVertex2f(1.2,-.1);
    glVertex2f(1.2,-.0);
    glVertex2f(1.3,-2);
	glVertex2f(1.3,-1.9);
	glVertex2f(1.3,-1.7);
	glVertex2f(1.3,-1.6);
	glVertex2f(1.3,-1.4);
	glVertex2f(1.3,-1.3);
	glVertex2f(1.3,-1.1);
	glVertex2f(1.3, -1);
	glVertex2f(1.3,-.8);
	glVertex2f(1.3,-.7);
	glVertex2f(1.3,-.5);
	glVertex2f(1.3,-.4);
	glVertex2f(1.3,-.2);
	glVertex2f(1.3,-.1);
    glVertex2f(1.4,-1.9);
	glVertex2f(1.4,-1.8);
	glVertex2f(1.4,-1.6);
	glVertex2f(1.4,-1.5);
	glVertex2f(1.4,-1.3);
	glVertex2f(1.4,-1.2);
	glVertex2f(1.4, -1);
	glVertex2f(1.4,-.9);
	glVertex2f(1.4,-.7);
	glVertex2f(1.4,-.6);
	glVertex2f(1.4,.4);
	glVertex2f(1.4,-.3);
	glVertex2f(1.4,-.1);
	glVertex2f(1.4,-.0);
    glVertex2f(1.5,-2);
	glVertex2f(1.5,-1.9);
	glVertex2f(1.5,-1.7);
	glVertex2f(1.5,-1.6);
	glVertex2f(1.5,-1.4);
	glVertex2f(1.5,-1.3);
	glVertex2f(1.5,-1.1);
	glVertex2f(1.5, -1);
	glVertex2f(1.5,-.8);
	glVertex2f(1.5,-.7);
	glVertex2f(1.5,-.5);
	glVertex2f(1.5,-.4);
	glVertex2f(1.5,-.2);
	glVertex2f(1.5,-.1);
    glVertex2f(1.6,-1.9);
	glVertex2f(1.6,-1.8);
	glVertex2f(1.6,-1.6);
	glVertex2f(1.6,-1.5);
	glVertex2f(1.6,-1.3);
	glVertex2f(1.6,-1.2);
	glVertex2f(1.6, -1);
	glVertex2f(1.6,-.9);
	glVertex2f(1.6,-.7);
	glVertex2f(1.6,-.6);
	glVertex2f(1.6,-.4);
	glVertex2f(1.6,-.3);
	glVertex2f(1.6,-.1);
	glVertex2f(1.6,-.0);
    glVertex2f(1.7,-2);
	glVertex2f(1.7,-1.9);
	glVertex2f(1.7,-1.7);
	glVertex2f(1.7,-1.6);
	glVertex2f(1.7,-1.4);
	glVertex2f(1.7,-1.3);
	glVertex2f(1.7,-1.1);
	glVertex2f(1.7, -1);
	glVertex2f(1.7,-.8);
	glVertex2f(1.7,-.7);
	glVertex2f(1.7,-.5);
	glVertex2f(1.7,-.4);
	glVertex2f(1.7,-.2);
	glVertex2f(1.7,-.1);
    glVertex2f(1.8,-1.9);
	glVertex2f(1.8,-1.8);
	glVertex2f(1.8,-1.6);
	glVertex2f(1.8,-1.5);
	glVertex2f(1.8,-1.3);
	glVertex2f(1.8,-1.2);
	glVertex2f(1.8,- 1);
	glVertex2f(1.8,-.9);
	glVertex2f(1.8,-.7);
	glVertex2f(1.8,-.6);
	glVertex2f(1.8,-.4);
	glVertex2f(1.8,-.3);
	glVertex2f(1.8,-.1);
	glVertex2f(1.8,-.0);
    glVertex2f(1.9,-2);
	glVertex2f(1.9,-1.9);
	glVertex2f(1.9,-1.7);
	glVertex2f(1.9,-1.6);
	glVertex2f(1.9,-1.4);
	glVertex2f(1.9,-1.3);
	glVertex2f(1.9,-1.1);
	glVertex2f(1.9, -1);
	glVertex2f(1.9,-.8);
	glVertex2f(1.9,-.7);
	glVertex2f(1.9,-.5);
	glVertex2f(1.9,-.4);
	glVertex2f(1.9,-.2);
	glVertex2f(1.9,-.1);
    glEnd();
	glPopMatrix();
}


///BIRD1

if (isDay && showBird)
{
    glPushMatrix();
    glTranslatef(birdX1, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-1.8f, 1.55f);
    glVertex2f(-1.7f, 1.65f);
    glVertex2f(-1.95f,1.63f);
    glVertex2f(-1.9f, 1.53f);
    glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.78f, 1.641f);
glVertex2f(-1.88f, 1.80f);
glVertex2f(-1.85f, 1.639f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.78f, 1.641f);
glVertex2f(-1.91f, 1.75f);
glVertex2f(-1.87f, 1.639f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.74f, 1.635f);
glEnd();


///BIRD2
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.5f,  1.35f);
glVertex2f(-1.4f,  1.45f);
glVertex2f(-1.65f, 1.43f);
glVertex2f(-1.6f,  1.33f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.48f, 1.441f);
glVertex2f(-1.58f, 1.60f);
glVertex2f(-1.55f, 1.439f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.48f, 1.441f);
glVertex2f(-1.61f, 1.55f);
glVertex2f(-1.57f, 1.439f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.44f, 1.435f);
glEnd();

///BIRD3
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.2f,  1.50f);
glVertex2f(-1.1f,  1.60f);
glVertex2f(-1.35f, 1.58f);
glVertex2f(-1.30f, 1.48f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.18f, 1.591f);
glVertex2f(-1.28f, 1.75f);
glVertex2f(-1.25f, 1.589f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.18f, 1.591f);
glVertex2f(-1.31f, 1.70f);
glVertex2f(-1.27f, 1.589f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.14f, 1.575f);
glEnd();


glPopMatrix();
}

///Star
glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);


glVertex2f(-1.7f, 1.8f);


glVertex2f(-1.2f, 1.6f);


glVertex2f(-0.8f, 1.9f);


glVertex2f(-0.2f, 1.7f);


glVertex2f(0.4f, 1.85f);


glVertex2f(0.9f, 1.65f);


glVertex2f(1.3f, 1.9f);


glVertex2f(1.9f, 1.75f);


glVertex2f(2.4f, 1.85f);

glEnd();


}


void timer(int value)
{

    if (!manualDayNight) {
        if (isDay)
        {
            sunY -= 0.015f;
            if (sunY < -0.5f) {
                isDay = false;
                moonY = -0.5f;
            }
        }
        else
        {
            moonY += 0.015f;
            if (moonY > 1.8f) {
                isDay = true;
                sunY = 1.8f;
            }
        }
    }


    if (isDay) {
        cloudX += 0.003f;
        if (cloudX > 3.0f) cloudX = -3.0f;
    }


    if (isDay) {
        shipX += 0.5f;
        if (shipX > 2.5f) shipX = -2.5f;
    }


    if (isDay) {
        smokeY += 0.02f;
        if (smokeY > 0.3f) smokeY = 0.0f;
    }
    else {
        smokeY = 0.0f;
    }


    if (isDay && birdFly && !birdStop) {
        birdX += birdSpeed;
        if (birdX > 4.0f) birdX = -1.0f;
    }


    timeOfDay += 0.0001f;
    if (timeOfDay >= 1.0f)
    {
        timeOfDay = 0.0f;
        isDay = !isDay;
    }


if (birdMove && isDay)
{
    birdX1 += birdSpeed1;
    birdX2 += birdSpeed2;

    if (birdX1 > 4.0f)
        birdX1 = -4.0f;

        if (birdX2 > 4.0f)
            birdX2 = -4.0f;
}


if (carMove)
{
    carX += carSpeed;

    if (carX > 4.0f)
        carX = -4.0f;
}

wheelAngle += 0.4f;
if (wheelAngle >= 360.0f)
    wheelAngle = 0.0f;

     timeOfDay += daySpeed;

    if(timeOfDay >= 1.0f)
        timeOfDay = 0.0f;


    if(timeOfDay < 0.5f)
        isDay = true;
    else
        isDay = false;


    if(birdMove && isDay)
    {
        birdX1 += birdSpeed1;
        if(birdX1 > 4.0f) birdX1 = -4.0f;
    }


    if(cloudMove && isDay)
    {
        _run3 += 0.04f;
        if(_run3 > 2.5f) _run3 = -2.5f;
    }

    if (isRaining)
{
    _run -= rainSpeed;
    if (_run < -2.0f)
        _run = 0.0f;
}


    glutPostRedisplay();
     glutTimerFunc(50, timer, 0);
}

void keyboard(unsigned char key, int, int)
{
    if (key == 'n' || key == 'N') {
        manualDayNight = true;
        isDay = !isDay;

        if (isDay) {
            sunY = 1.8f;
            moonY = -0.5f;
            birdStop = true;
        }
        else {
            sunY = -0.5f;
            moonY = 1.8f;
            birdStop = true;
        }
    }

    if (key == 'k' || key == 'K') {
        shipStop = !shipStop;
    }

     if (key == 'r' || key == 'R') {

     isRaining = !isRaining;
   }

     if (key == 'c' || key == 'C') {

     cloudMove = !cloudMove;
   }

     if (key == 'w' || key == 'W')
    {
        carMove = true;
    }

    if (key == 's' || key == 'S')
    {
        carMove = false;
    }

     if (key == '1') currentScene = 1; // Village
    if (key == '2') currentScene = 2; // City
    if (key == '3') currentScene = 3; // Mountain

    glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        birdStop = !birdStop;
    }

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        birdMove = !birdMove;
    }

     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        birdMove = !birdMove;
    }

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    if (currentScene == 1)
        drawVillage();
    else if (currentScene == 2)
        drawCity();
    else if (currentScene == 3)
        drawMountain();

    glutSwapBuffers();
}




int main(int argc, char** argv)
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scenery Project");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

     glutMouseFunc(mouse);

     glutTimerFunc(16, timer, 0);


    glutMainLoop();

    return 0;
}

