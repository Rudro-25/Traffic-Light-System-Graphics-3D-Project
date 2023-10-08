/*
  ----Graphics 3D Project: Traffic-Light-System-Graphics-3D-Project ---
                ----Control Instruction---
                    F10-Red
                    F11-Yellow
                    F12-Green
                    Page Up- Door opn/cls (circularly)
                    left/right arrorw - cloud movement
                    F4/F5 -camera lft/right movement
                    F6/F7- camera up/down movement
                    F8/F9 - camera zoom in/out
                    F2 - sun scaling
*/

//add window.h header
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <cmath>
#endif

#define SPEED 5.0                  //speed of traffic
float doorAngle = 0.0f;
bool doorOpen = false;
float i=0.0;                        //movement of car
float m=0.0;                        //movement of clouds
float n=0.0;                        //movement of plane along x-axis
float o=0.0;                        //  and y-axis
float c=0.0;                        //movement of comet	SS
int light=1;                        //1 for green-light, 0 for red-light, 2 for yellow
int day=1;                          //1 for day ,0 for night
int plane=0;                        //1 for plane
int comet=0;                        //1 for comet
int segments= 100;
int radius= 0.5f;

static int a=0,a1 = 0;
double x = 0, Sx = 0, Sy = 0, Sz = 0, tx = 0, ty = 0, tz = 0, big=0, doorx = 0, movecar = 0;
double posx = 0, posy = 0, posz = 2, eyex = 0, eyey = 0, eyez = 0, upx = 0, upy = 1, upz = 0;
void update(int value) {

    if(movecar<7){
        movecar += 0.03;
        if(movecar>=7) movecar = 0;
    }
    
    glutPostRedisplay();
    if(light==1) glutTimerFunc(16, update, 0); // 60 FPS
}

void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: x = (x - 0.1);
                        if(x<-1)
                        {
                            x = 3.5;
                        }
                        break;
    case GLUT_KEY_RIGHT: x = (x + 0.1);
                        if(x>3.5)
                        {
                            x = x-3.5;
                        }
                        break;
    case GLUT_KEY_F1: (a -= 5) %= 360; break;
    case GLUT_KEY_F2: if(big > 1){
                                big = 0;
                            }
                            else
                            {
                                big += 0.1;
                            }
                            break;
                     
    //case GLUT_KEY_F3: ballMoveBack(); break;
    case GLUT_KEY_F4: posx += 0.5; break;
    case GLUT_KEY_F5: posx -= 0.5; break;
    case GLUT_KEY_F6: posy += 0.5; break;
    case GLUT_KEY_F7: posy -= 0.5; break;
    case GLUT_KEY_F8: posz += 0.5; break;
    case GLUT_KEY_F9: posz -= 0.5; break;
    case GLUT_KEY_F10: light=0; break;
    case GLUT_KEY_F11: light=2; break;
    case GLUT_KEY_F12 : light=1; glutTimerFunc(0, update, 0); break;
    case GLUT_KEY_UP: // car move left
            movecar+=0.1;
            break;
        case GLUT_KEY_DOWN: // car move right
            movecar-=0.1;
            break;
    case GLUT_KEY_PAGE_UP: if(doorx > 0.09){
                                doorx = 0;
                            }
                            else
                            {
                                doorx += 0.1;
                            }
                            break;
    //case GLUT_KEY_F12:
    default: return;
  }
  glutPostRedisplay();
}

void spin(int value)
{
    a1 = a1 - 5;
    if(a1 < -360)
    {
        a1 = a1 + 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, spin, 0);
}

void fan()
{
    //fan1
    //back
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.05,0.8,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.05,0.8,0);

        glVertex3f(-0.05,0.8,0);
        glVertex3f(0,0.7,0);

        glVertex3f(0,0.7,0);
        glVertex3f(-0.2,0.4,0);

        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.25,0.5,0);
    glEnd();

    //left
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.25,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.05,0.8,0.05);

        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(-0.05,0.8,0);

        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.25,0.5,0);

        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.25,0.5,0.05);
    glEnd();

    //right
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.2,0.4,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(0,0.7,0.05);

        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0);

        glVertex3f(0,0.7,0);
        glVertex3f(-0.2,0.4,0);

        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.2,0.4,0.05);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.25,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.2,0.4,0.05);

        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(-0.2,0.4,0);

        glVertex3f(-0.2,0.4,0);
        glVertex3f(-0.25,0.5,0);

        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.25,0.5,0.05);
    glEnd();

    //top
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0);
        glVertex3f(-0.05,0.8,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(0,0.7,0.05);

        glVertex3f(0,0.7,0.05);
        glVertex3f(0,0.7,0);

        glVertex3f(0,0.7,0);
        glVertex3f(-0.05,0.8,0);

        glVertex3f(-0.05,0.8,0);
        glVertex3f(-0.05,0.8,0.05);
    glEnd();

    //front
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(0,0.7,0.05);
        glVertex3f(-0.05,0.8,0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.275,0.45,0.05);
        glVertex3f(-0.05,0.8,0.05);

        glVertex3f(-0.05,0.8,0.05);
        glVertex3f(0,0.7,0.05);

        glVertex3f(0,0.7,0.05);
        glVertex3f(-0.2,0.4,0.05);

        glVertex3f(-0.2,0.4,0.05);
        glVertex3f(-0.25,0.5,0.05);
    glEnd();

  //fan2
   //back
   glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.05,0.1,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.3,0.3,0);

        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.1,0,0);

        glVertex3f(-0.1,0,0);
        glVertex3f(-0.05,0.1,0);

        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.25,0.4,0);
    glEnd();

    //left
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.25,0.4,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.05,0.1,0.05);

        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.05,0.1,0);

        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.25,0.4,0);

        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.25,0.4,0.05);
    glEnd();

    //right
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.3,0.3,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.1,0,0.05);

        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0);

        glVertex3f(-0.1,0,0);
        glVertex3f(-0.3,0.3,0);

        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.3,0.3,0.05);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.25,0.4,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.3,0.3,0.05);

        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.3,0.3,0);

        glVertex3f(-0.3,0.3,0);
        glVertex3f(-0.25,0.4,0);

        glVertex3f(-0.25,0.4,0);
        glVertex3f(-0.25,0.4,0.05);
    glEnd();

    //top
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0);
        glVertex3f(-0.05,0.1,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.1,0,0.05);

        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.1,0,0);

        glVertex3f(-0.1,0,0);
        glVertex3f(-0.05,0.1,0);

        glVertex3f(-0.05,0.1,0);
        glVertex3f(-0.05,0.1,0.05);
    glEnd();

    //front
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.25,0.4,0.05);
        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.05,0.1,0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.275,0.45,0.05);
        glVertex3f(-0.05,0.1,0.05);

        glVertex3f(-0.05,0.1,0.05);
        glVertex3f(-0.1,0,0.05);

        glVertex3f(-0.1,0,0.05);
        glVertex3f(-0.3,0.3,0.05);

        glVertex3f(-0.3,0.3,0.05);
        glVertex3f(-0.25,0.4,0.05);
    glEnd();

    //fan3
    //back
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.35,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.5,0.1,0);

        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.55,0.2,0);

        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.35,0.5,0);

        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.3,0.4,0);
    glEnd();

    //left
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.3,0.4,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.5,0.1,0.05);

        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0);

        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.3,0.4,0);

        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.3,0.4,0.05);
    glEnd();

    //right
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.35,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.55,0.2,0.05);

        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.55,0.2,0);

        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.35,0.5,0);

        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.35,0.5,0.05);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.35,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.3,0.4,0.05);

        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.3,0.4,0);

        glVertex3f(-0.3,0.4,0);
        glVertex3f(-0.35,0.5,0);

        glVertex3f(-0.35,0.5,0);
        glVertex3f(-0.35,0.5,0.05);
    glEnd();

    //top
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.55,0.2,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.5,0.1,0.05);

        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.5,0.1,0);

        glVertex3f(-0.5,0.1,0);
        glVertex3f(-0.55,0.2,0);

        glVertex3f(-0.55,0.2,0);
        glVertex3f(-0.55,0.2,0.05);
    glEnd();

    //front
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.4,0.05);
        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.35,0.5,0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.275,0.45,0.05);
        glVertex3f(-0.5,0.1,0.05);

        glVertex3f(-0.5,0.1,0.05);
        glVertex3f(-0.55,0.2,0.05);

        glVertex3f(-0.55,0.2,0.05);
        glVertex3f(-0.35,0.5,0.05);

        glVertex3f(-0.35,0.5,0.05);
        glVertex3f(-0.3,0.4,0.05);
    glEnd();

    //fan4
    //back
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.25,0.6,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.5,0.8,0);

        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.45,0.9,0);

        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.25,0.6,0);

        glVertex3f(-0.25,0.6,0);
        glVertex3f(-0.3,0.5,0);
    glEnd();

    //left
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.5,0.8,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.3,0.5,0.05);

        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.3,0.5,0);

        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.5,0.8,0);

        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.5,0.8,0.05);
    glEnd();

    //right
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.25,0.6,0.05);
        glVertex3f(-0.25,0.6,0);
        glVertex3f(-0.45,0.9,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.25,0.6,0.05);

        glVertex3f(-0.25,0.6,0.05);
        glVertex3f(-0.25,0.6,0);

        glVertex3f(-0.25,0.6,0);
        glVertex3f(-0.45,0.9,0);

        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.45,0.9,0.05);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.35,0.6,0.05);
        glVertex3f(-0.35,0.6,0);
        glVertex3f(-0.3,0.5,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.35,0.6,0.05);

        glVertex3f(-0.35,0.6,0.05);
        glVertex3f(-0.35,0.6,0);

        glVertex3f(-0.35,0.6,0);
        glVertex3f(-0.3,0.5,0);

        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.3,0.5,0.05);
    glEnd();

    //top
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.5,0.8,0);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.45,0.9,0.05);

        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.45,0.9,0);

        glVertex3f(-0.45,0.9,0);
        glVertex3f(-0.5,0.8,0);

        glVertex3f(-0.5,0.8,0);
        glVertex3f(-0.5,0.8,0.05);
    glEnd();

    //front
    glBegin(GL_QUADS);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.25,0.6,0.05);
    glEnd();
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-0.275,0.45,0.05);
        glVertex3f(-0.5,0.8,0.05);

        glVertex3f(-0.5,0.8,0.05);
        glVertex3f(-0.45,0.9,0.05);

        glVertex3f(-0.45,0.9,0.05);
        glVertex3f(-0.25,0.6,0.05);

        glVertex3f(-0.25,0.6,0.05);
        glVertex3f(-0.3,0.5,0.05);
    glEnd();
}

void cloud(){
    glColor3f (1, 1, 1); //first cloud
    glPushMatrix();
        glTranslatef(0.5, 1.8, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.4, 1.75, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.3, 1.8, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.5, 1.9, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.35, 1.88, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();

    //second cloud
    glPushMatrix();
        glTranslatef(1.2, 1.8, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.3, 1.85, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.25, 1.75, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.4, 1.8, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(1.35, 1.73, 0);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
}

static void idle(void)
{
    glutPostRedisplay();
}


void tiang()
{
    glBegin(GL_QUADS);
        glColor3f(0.4,0.4,0.4);
        //back
        glVertex3f(-0.3,-0.3,0);
        glVertex3f(-0.25,-0.3,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.3,0.5,0);
        //left
        glColor3f(0,0,0);
        glVertex3f(-0.3,-0.3,0.05);
        glVertex3f(-0.3,-0.3,0);
        glVertex3f(-0.3,0.5,0);
        glVertex3f(-0.3,0.5,0.05);
        //right
        glColor3f(0,0,0);
        glVertex3f(-0.25,-0.3,0.05);
        glVertex3f(-0.25,-0.3,0);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.25,0.5,0.05);
        //bottom
        glColor3f(0.4,0.4,0.4);
        glVertex3f(-0.3,-0.3,0.05);
        glVertex3f(-0.25,-0.3,0.05);
        glVertex3f(-0.25,-0.3,0);
        glVertex3f(-0.3,-0.3,0);
        //top
        glColor3f(0.4,0.4,0.4);
        glVertex3f(-0.3,0.5,0.05);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.25,0.5,0);
        glVertex3f(-0.3,0.5,0);
        //front
        glColor3f(0.4,0.4,0.4);
        glVertex3f(-0.3,-0.3,0.05);
        glVertex3f(-0.25,-0.3,0.05);
        glVertex3f(-0.25,0.5,0.05);
        glVertex3f(-0.3,0.5,0.05);

    glEnd();

}

void tree()
{
    glBegin(GL_QUADS);
        glColor3f(0.3,0.2,0.14);
        //back
        glVertex3f(-0.3,-0.3,1.45);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.3,0,1.45);
        //left
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.3,-0.3,1.45);
        glVertex3f(-0.3,0,1.45);
        glVertex3f(-0.3,0,1.5);
        //right
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.25,0,1.5);
        //bottom
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.3,-0.3,1.45);
        //top
        glVertex3f(-0.3,0,1.5);
        glVertex3f(-0.25,0,1.5);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.3,0,1.45);
        //front
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,0,1.5);
        glVertex3f(-0.3,0,1.5);

    glEnd();

    //leave
    glColor3f (0.4, 1, 0.2);
    glPushMatrix();
        glTranslatef(-0.3, -0.05, 1.4);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.2, 0.05, 1.4);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.4, -0.03, 1.4);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.35, 0.1, 1.4);
        glutSolidSphere(0.1,36,2);
    glPopMatrix();

}

void lamp(){
    glBegin(GL_QUADS);
        glColor3f(0.6,0,0);
        //back
        glVertex3f(-0.3,-0.3,1.45);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.3,0,1.45);
        //left
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.3,-0.3,1.45);
        glVertex3f(-0.3,0,1.45);
        glVertex3f(-0.3,0,1.5);
        //right
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.25,0,1.5);
        //bottom
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.45);
        glVertex3f(-0.3,-0.3,1.45);
        //top
        glVertex3f(-0.3,0,1.5);
        glVertex3f(-0.25,0,1.5);
        glVertex3f(-0.25,0,1.45);
        glVertex3f(-0.3,0,1.45);
        //front
        glVertex3f(-0.3,-0.3,1.5);
        glVertex3f(-0.25,-0.3,1.5);
        glVertex3f(-0.25,0,1.5);
        glVertex3f(-0.3,0,1.5);
    glEnd();

    glColor3f(1.0, 1.0, 0);
    glPushMatrix();
        glTranslatef(-0.28, 0.02, 1.43);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();
}
void background(){
    //field
    //glColor3f (1, 0.2, 0.2);
    glTranslatef(-0.5, -0.4, 0);
    glScalef(0.5,0.5,0.5);
    glRotatef(10, 1, 1, 0);

    //front
    glColor3f (0.5, 0.2, 0.7);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (2, 0, 2);
        glVertex3f (2, 0.1, 2);
        glVertex3f (0, 0.1, 2);
    glEnd();


    //bottom
    glColor3f (0.5, 0.2, 0.7);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (2, 0, 2);
        glVertex3f (2.5, 0, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    //up
    glColor3f (0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0.1, 2);
        glVertex3f (2, 0.1, 2);
        glVertex3f (2.5, 0.1, 0);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //left
    glColor3f (0.5, 0.2, 0.7);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, 2);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0, 0.1, 0);
    glEnd();

    //right
    glColor3f (0.5, 0.2, 0.7);
    glBegin(GL_QUADS);
        glVertex3f (2, 0, 2);
        glVertex3f (2.5, 0, 0);
        glVertex3f (2.5, 0.1, 0);
        glVertex3f (2, 0.1, 2);
    glEnd();

    //back
    glColor3f (0.5, 0.2, 0.7);
    glBegin(GL_QUADS);
        glVertex3f (2.5, 0, 0);
        glVertex3f (2.5, 0.1, 0);
        glVertex3f (0, 0.1, 0);
        glVertex3f (0, 0, 0);
    glEnd();

    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 0);
        glVertex3f(1.6, 0.1, 0);
    glEnd();
    //road_line
    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0.1, 0);
        glVertex3f(1.6, 0.1, 0);
    glEnd();

    //Road
    glColor3f (0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
        // //front
        glVertex3f (0, 0, 2.4);
        glVertex3f (2, 0, 2.4);
        glVertex3f (2, 0.1, 2.4);
        glVertex3f (0, 0.1, 2.4);
        // //bottom
        glVertex3f (0, 0, 2.4);
        glVertex3f (2, 0, 2.4);
        glVertex3f (2, 0, 2);
        glVertex3f (0, 0, 2);
        //back
        glVertex3f (0, 0, 2);
        glVertex3f (2, 0, 2);
        glVertex3f (2, 0.1, 2);
        glVertex3f (0, 0.1, 2);
        //up
        glVertex3f (0, 0.1, 2.4);
        glVertex3f (2, 0.1, 2.4);
        glVertex3f (2, 0.1, 2);
        glVertex3f (0, 0.1, 2);
        // //left
        glVertex3f (0, 0, 2.4);
        glVertex3f (0, 0.1, 2.4);
        glVertex3f (0, 0.1, 2);
        glVertex3f (0, 0, 2);
        // //right
        glVertex3f (2, 0, 2.4);
        glVertex3f (2, 0.1, 2.4);
        glVertex3f (2, 0.1, 2);
        glVertex3f (2, 0, 2);
    glEnd();
    // //Home
    // //front
    // glColor3f (0, 0, 0);
    // glBegin(GL_QUADS);
    //     glVertex3f (0.1, 0, 0);
    //     glVertex3f (0.5, 0, 0);
    //     glVertex3f (0.5, 0.5, 0.2);
    //     glVertex3f (0.1,0.51, 0.2);
    // glEnd();
}

void square(){
    //front
   // glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (2, 0, 0);
        glVertex3f (2, 2, 0);
        glVertex3f (0, 2, 0);
    glEnd();


    //bottom
    //glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (2, 0, 0);
        glVertex3f (2, 0, 2);
        glVertex3f (0, 0, 2);
    glEnd();

    //up
    //glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 2, 0);
        glVertex3f (2, 2, 0);
        glVertex3f (2, 2, 2);
        glVertex3f (0, 2, 2);
    glEnd();

    //left
    //glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 2, 0);
        glVertex3f (0, 2, 2);
        glVertex3f (0, 0, 2);
    glEnd();

    //right
    //glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (2, 0, 0);
        glVertex3f (2, 2, 0);
        glVertex3f (2, 2, 2);
        glVertex3f (2, 0, 2);
    glEnd();

    //back
    //glColor3f (0.2, 0.8, 0.2);
    glBegin(GL_QUADS);
        glVertex3f (0, 0, 2);
        glVertex3f (2, 0, 2);
        glVertex3f (2, 2, 2);
        glVertex3f (0, 2, 2);
    glEnd();
}

void home(){
   glPushMatrix();
   glColor3f (0,0,0.8);
   glTranslatef(-0.9, -0.3, 0.1);
   glScalef(0.5,0.5,0.1);
   square();
   glPopMatrix();

   //chad
   glPushMatrix();
   glColor3f(0.1,0.2,0);
   glTranslatef(-1.1, 0.7, 0.1);
   glScalef(0.7,0.15,0.0);
   square();
   glPopMatrix();
   
   //door back side
   glPushMatrix();

   glColor3f(0.8,0.8,1);
   glTranslatef(-0.47, -0.3, 0);
   glScalef(0.08,0.2,0.05);
   square();
   glPopMatrix();

   //1st door
   glPushMatrix();

   glColor3f(1,0.2,0.7);
   glTranslatef(-0.5-doorx, -0.3, 0);
   glScalef(0.06,0.2,0.05);
   square();
   glPopMatrix();

   //2nd door
   glPushMatrix();
   glColor3f(1,0.2,0);
   glTranslatef(-0.4+doorx, -0.3, 0);
   glScalef(0.07,0.2,0.05);
   square();
   glPopMatrix();

   //2nd one
}

void home2(){
   glPushMatrix();
   glColor3f (1,0.4,0.4);
   glTranslatef(-0.9, -0.3, 0.1);
   glScalef(0.5,0.5,0.1);
   square();
   glPopMatrix();

   //chad
   glPushMatrix();
   glColor3f(0.1,0.2,0);
   glTranslatef(-1.1, 0.7, 0.1);
   glScalef(0.7,0.15,0.0);
   square();
   glPopMatrix();
   
   //door
   glPushMatrix();

   glColor3f(0.8,0.8,1);
   glTranslatef(-0.47, -0.3, 0);
   glScalef(0.08,0.2,0.05);
   square();
   glPopMatrix();


}
void ballMoveFront(void)
{
    Sx = Sx + 0.5;
    Sy = Sy + 0.5;
    Sz = Sz + 0.5;

    if(Sx > 9 || Sy > 9 || Sz > 9)
    {
        Sx = Sx - 9;
        Sy = Sy - 9;
        Sz = Sz - 9;
    }

    tx = tx - 0.1;
    ty = ty - 0.1;
    tz = tz + 0.1;

    if(tx < -1.9 || ty < -1.9 || tz > 1.9)
    {
        tx = tx + 1.9;
        ty = ty + 1.9;
        tz = tz - 1.9;
    }

    glutPostRedisplay();
}

void ballMoveBack(void)
{
    Sx = Sx - 0.5;
    Sy = Sy - 0.5;
    Sz = Sz - 0.5;

    if(Sx <= 0.5 || Sy <= 0.5 || Sz <= 0.5)
    {
        Sx = 0;
        Sy = 0;
        Sz = 0;
    }

    tx = tx + 0.1;
    ty = ty + 0.1;
    tz = tz - 0.1;

    if(tx >= 3 || ty >= 3 || tz <= -3)
    {
        tx = 0;
        ty = 0;
        tz = 0;
    }

    glutPostRedisplay();
}


void sun(){
    glColor3f(1.0, 1.0, 0);
    glPushMatrix();
        glTranslatef(-0.28, 0.02, 1.43);
        glScalef(1+big,1+big,1.1+big);
        glutSolidSphere(0.08,36,2);
    glPopMatrix();
}

void mountain()
{
    glBegin(GL_TRIANGLES);
        //front
        glVertex3f(-2,-0.28,0);
        glVertex3f(-1, 0.3,-0.5);
        glVertex3f(0.5,-0.28,0);
        //right
        glVertex3f(0.5, -0.28, 0);
        glVertex3f(-1, 0.3,-0.5);
        glVertex3f(0.5, -0.28,-1);
        //back
        glVertex3f(0.5, -0.28,-1);
        glVertex3f(-1, 0.3,-0.5);
        glVertex3f(-2, -0.28,-1);
        //left
        glVertex3f(-2, -0.28,0);
        glVertex3f(-1, 0.3,-0.5);
        glVertex3f(-2, -0.28,-1);
        //bottom
        glVertex3f(-2, -0.28,0);
        glVertex3f(0.5, -0.28,0);
        glVertex3f(0.5, -0.28,-1);
        glVertex3f(-2, -0.28,-1);
    glEnd();

    glColor3f (0, 0, 0);
    glBegin(GL_LINES);
        //1
        glVertex3f(-2, -0.28, 0);
        glVertex3f(-1, 0.3,-0.5);
    glEnd();
    glBegin(GL_LINES);
        //2
        glVertex3f(0.5, -0.28, 0);
        glVertex3f(-1, 0.3,-0.5);
    glEnd();
    glBegin(GL_LINES);
        //3
        glVertex3f(0.5, -0.28, -1);
        glVertex3f(-1, 0.3,-0.5);
    glEnd();
    glBegin(GL_LINES);
        //4
        glVertex3f(0.5, -0.28, 0);
        glVertex3f(0.5, -0.28,-1);
    glEnd();
    glBegin(GL_LINES);
        //5
        glVertex3f(-2, -0.28, -1);
        glVertex3f(-1, 0.3,-0.5);
    glEnd();
}

// void draw_car(){
//      // Car Body
//     glPushMatrix();
//     glColor3f(1.0f, 0.0f, 0.0f); // Red color
//     glScalef(2.0f, 0.5f, 0.5f); // Scale to create the body
//     glutSolidCube(1.0);
//     glPopMatrix();

//     // Car Roof (Window)
//     glPushMatrix();
//     glColor3f(0.0f, 0.0f, 1.0f); // Blue color
//     glTranslatef(0.5f, 0.25f, 0.25f);
//     glScalef(0.5f, 0.25f, 0.25f); // Scale to create the roof
//     glutSolidCube(1.0);
//     glPopMatrix();

//     // Car Windows
//     glPushMatrix();
//     glColor3f(0.0f, 1.0f, 0.0f); // Green color
//     glTranslatef(1.0f, 0.25f, 0.25f);
//     glScalef(0.05f, 0.25f, 0.25f); // Scale to create the windows
//     glutSolidCube(1.0);
//     glPopMatrix();

//     // Car Wheels
//     glPushMatrix();
//     glColor3f(0.0f, 1.0f, 0.0f); // Black color
//     glTranslatef(-0.4f, -0.25f, 0.3f);
//     glutSolidTorus(0.1, 0.1, 50, 50); // Rear wheel
//     glPopMatrix();

//     glPushMatrix();
//     glTranslatef(0.6f, -0.25f, 0.3f);
//     glutSolidTorus(0.1, 0.1, 50, 50); // Front wheel
//     glPopMatrix();
// }

void car(){
   //glColor3f (0,0.2,0.2);
//    glTranslatef(0.3, -2, -2);
//    glScalef(0.9,0.9,0.3);
//    draw_car();
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glTranslatef(movecar+0.0f, 0.05f, 0.25f);
    glScalef(2.0f, 0.5f, 0.5f); // Scale to create the body
    glutSolidCube(1.0);
    glPopMatrix();

    // Car Roof (Window)
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glTranslatef(movecar+0.5f, 0.25f, 0.25f);
    glScalef(0.5f, 0.25f, 0.25f); // Scale to create the roof
    glutSolidCube(1.0);
    glPopMatrix();

    // Car Wheels
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f); // Black color
    glTranslatef(-0.4f+movecar, -0.25f, 0.3f);
    glutSolidTorus(0.1, 0.1, 50, 50); // Rear wheel
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6f+movecar, -0.25f, 0.3f);
    glutSolidTorus(0.1, 0.1, 50, 50); // Front wheel
    glPopMatrix();
}



void traffic(){
    //stand
    glPushMatrix();
    glColor3f(0.7,0.2,0.1);
    glTranslatef(6.2,-0.3,-8);
    glScalef(0.1,1,0.5);
    square();
    glPopMatrix();
    //

    glPushMatrix();
        glColor3f(0.2,0,0.7);
        glTranslatef(6,1.0,0);
        glScalef(0.3,1.2,0.5);
        square();
    glPopMatrix();
}
void drawCircle() {
    if(light==1){
        //Red
        glPushMatrix();
            glColor3f(0.5,0.5,0.5);
            glTranslatef(6.3, 3.0, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();

        //Yellow (1,1,0)
        glPushMatrix();
            glColor3f(0.5,0.5,0.5);
            glTranslatef(6.3, 2.3, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();

        //Green
        glPushMatrix();
            glColor3f(0,1,0);
            glTranslatef(6.3, 1.6, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();
    }
    else if(light==2){
        //Red
        glPushMatrix();
            glColor3f(0.5,0.5,0.5);
            glTranslatef(6.3, 3.0, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();

        //Yellow (1,1,0)
        glPushMatrix();
            glColor3f(1,1,0);
            glTranslatef(6.3, 2.3, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();

        //Green
        glPushMatrix();
            glColor3f(0.5,0.5,0.5);
            glTranslatef(6.3, 1.6, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();
    }
    else{
        //Red
        glPushMatrix();
            glColor3f(01,0,0);
            glTranslatef(6.3, 3.0, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();

        //Yellow (1,1,0)
        glPushMatrix();
            glColor3f(0.5,0.5,0.5);
            glTranslatef(6.3, 2.3, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();

        //Green
        glPushMatrix();
            glColor3f(0.5,0.5,0.5);
            glTranslatef(6.3, 1.6, 0);
            glutSolidSphere(0.25,36,2);
        glPopMatrix();
    }
}
void display() {

  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
    glTranslatef(0,0.6,0);
    glScalef(3,2.5,2.5);
    background();
  glPopMatrix();

  glPushMatrix();
    glScalef(1.5,1,1);
    glTranslatef(-2.5 + x,-0.9,0);
    cloud();
  glPopMatrix();

  glPushMatrix();
    glScalef(1.5,1,1.5);
    glTranslatef(-0.5,1,0);
    sun();
  glPopMatrix();

  //left windmill
  glPushMatrix();
    glTranslatef(0.8,0,0);
    glRotatef(10,0,-1,0);
    tiang();
  glPopMatrix();


  glPushMatrix();
    glTranslatef(0.8,0,0);
    glRotatef(10,0,-1,0);
    glTranslatef(-0.275,0.45,0.2);
    glRotatef((GLfloat)a1,0,0,1);
    glTranslatef(0.275,-0.45,-0.2);
    fan();
  glPopMatrix();


  glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(1.1 + tx, -0.3 + ty, 0 + tz);
    glScalef(1 + Sx, 1 + Sy, 1 + Sz);
    glutSolidSphere(0.05,20,20);
  glPopMatrix();

  ////

  glPushMatrix();
    // glTranslatef(-0.9, -0.3, 0.5);
    // glScalef(0.3,0.2,0.0);
    home();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(1.8, 0, 0);
    glScalef(0.7,0.7,0.7);
    home2();
  glPopMatrix();

  //Tree
   glPushMatrix();
    glTranslatef(1, 0, -1.5);
    //glScalef(1.2,0.3,1.2);
    tree();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(1, 0, -1);
    //glScalef(1.2,0.3,1.2);
    tree();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(1, 0, -0.5);
    //glScalef(1.2,0.3,1.2);
    tree();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(1, 0, 0);
    //glScalef(1.2,0.3,1.2);
    tree();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(1, 0, .5);
    //glScalef(1.2,0.3,1.2);
    tree();
  glPopMatrix();
  glPushMatrix();
    glTranslatef(1, 0, 1);
    //glScalef(1.2,0.3,1.2);
    tree();
  glPopMatrix();

  ///road_light 1 2 3 4 5
   glPushMatrix();
    glTranslatef(-0.8, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-0.5, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-0.2, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.1, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.4, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.7, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(1, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(1.3, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(1.6, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(1.9, -0.5, 1.5);
    glScalef(0.8,0.6,0.5);
    lamp();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-0.9, -0.55, 2.75);
    glScalef(0.3,0.2,0.0);
    // glTranslatef(0.3, -2, -2);
//    glScalef(0.9,0.9,0.3);
    traffic();
  glPopMatrix();

   glPushMatrix();
    glTranslatef(-0.9, -0.55, 2.75);
    glScalef(0.3,0.2,0.0);
    // glTranslatef(0.3, -2, -2);
//    glScalef(0.9,0.9,0.3);
    car();
  glPopMatrix();


  glPushMatrix();
    glTranslatef(-0.9, -0.55, 2.75);
    glScalef(0.3,0.2,0);
    drawCircle();
  glPopMatrix();



//   //road
//    glPushMatrix();
//     glTranslatef(0.64, 0, 0.5);
//     glColor3f(0,0,0);
//     road();
//   glPopMatrix();


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(posx, posy, posz, eyex, eyey, eyez, upx, upy, upz);

  glFlush();
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void init() {

    // Set the current clear color to black and the current drawing color to
  // white.
  glClearColor (0.4, 0.85, 1.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);

  // Set the camera lens to have a 60 degree (vertical) field of view, an
  // aspect ratio of 4/3, and have everything closer than 1 unit to the
  // camera and greater than 40 units distant clipped away.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(100.0, 4.0/3.0, 1, 20);

  // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
  // <0, 1, 0> pointing upward.


}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(250, 0);
  glutInitWindowSize(1100, 700);
  glutCreateWindow("Project");

  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glutSpecialFunc(special);
  glutTimerFunc(25, spin, 0);
  glutTimerFunc(0, update, 0);
  init();
  glutMainLoop();
}
