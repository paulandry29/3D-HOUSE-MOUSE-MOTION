#include <windows.h>
#include <GL/glut.h>

void init(void);
void tampil(void);
void keyboard(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mousemotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float a = 0.0, b = 0.0;
bool mousedown = false;
int is_depth;

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("PAULUS ANDRY LEKSONO - 672018178");

    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    //glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
    glutSpecialFunc(keyboard);

    glutIdleFunc(tampil);
    init();

    glutMainLoop();
    return 0;
}

void idle()
{
    if(!mousedown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void keyboard(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_F5 :
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
        break;

//    case GLUT_KEY_UP :
//        glTranslated(0.0, 0.0, 3.0);
//        b += 3.0;
//        break;
//
//    case GLUT_KEY_DOWN :
//        glTranslated(0.0, 0.0, -3.0);
//        b -= 3.0;
//        break;
//
//    case GLUT_KEY_LEFT :
//        glTranslated(-3.0, 0.0, 0.0);
//        a += 3.0;
//        break;
//
//    case GLUT_KEY_RIGHT :
//        glTranslated(3.0, 0.0, 0.0);
//        a -= 3.0;
//        break;



    }
//    glTranslated(a, 0.0, b);
//    glutPostRedisplay();
    tampil();
    //glutPostRedisplay();

//    if(key == 5){
//        if (is_depth)
//        {
//            is_depth = 0;
//            glDisable(GL_DEPTH_TEST);
//        }
//        else{
//            is_depth = 1;
//            glEnable(GL_DEPTH_TEST);
//        }
//        glutPostRedisplay();
//    }
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
//        is_depth = 0;
//        glDisable(GL_DEPTH_TEST);
    }
    else
    {
        mousedown = false;
//        is_depth = 1;
//        glEnable(GL_DEPTH_TEST);
    }


}

void mousemotion(int x, int y)
{
    if(mousedown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if(tinggi ==0 ) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, lebar/tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
//    gluLookAt(0.0f, 5.0f, 3.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth =1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(1.0);
}


///koordinat

void koordinat(void)
{
    //koordinat horizontal
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(-10000.0, 0.0, 0.0);
    glVertex3f(10000.0, 0.0, 0.0);
    glEnd();

    //vertical
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0.0, 10000.0, 0.0);
    glVertex3f(0.0, -10000.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0.0, 0.0, 10000.0);
    glVertex3f(0.0, 0.0, -10000.0);
    glEnd();

}


///bagian kanan

void wall_depan_bawah_r(void)
{
    //depan bawah
    glBegin(GL_POLYGON);
    glColor3f(0.2, 1.0,0.2);
    glVertex3f(0.0, -10.0, 10.0);
    glVertex3f(0.0, 10.0, 10.0);
    glVertex3f(20.0, 10.0, 10.0);
    glVertex3f(20.0, -10.0, 10.0);
    glEnd();
}

void pintu_depan_r(void)
{
    //pintu
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(6.0, 4.0, 10.1);
    glVertex3f(14.0, 4.0, 10.1);
    glVertex3f(14.0, -10.0, 10.1);
    glVertex3f(6.0, -10.0, 10.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.747059, 0.164706, 0.164706);
    glVertex3f(6.3, 3.7, 10.2);
    glVertex3f(13.7, 3.7, 10.2);
    glVertex3f(13.7, -10.0, 10.2);
    glVertex3f(6.3, -10.0, 10.2);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.547059, 0.144706, 0.144706);
    glVertex3f(10.0, 3.7, 10.3);
    glVertex3f(10.0, -10.0, 10.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.547059, 0.144706, 0.144706);
    glVertex3f(9.3, -2.0, 10.3);
    glVertex3f(9.3, -5.0, 10.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.547059, 0.144706, 0.144706);
    glVertex3f(10.7, -2.0, 10.3);
    glVertex3f(10.7, -5.0, 10.3);
    glEnd();
}

void jendela_depan_r(void)
{
    //jendela depan kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(1, -6, 10.1);
    glVertex3f(4, -6, 10.1);
    glVertex3f(4, 6, 10.1);
    glVertex3f(1, 6, 10.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(1.3, -5.7, 10.2);
    glVertex3f(3.7, -5.7, 10.2);
    glVertex3f(3.7, 5.7, 10.2);
    glVertex3f(1.3, 5.7, 10.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(1.3, -5.7, 10.3);
    glVertex3f(3.7, -5.7, 10.3);
    glVertex3f(3.7, 5.7, 10.3);
    glEnd();

    //jendela depan kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(16, -6, 10.1);
    glVertex3f(19, -6, 10.1);
    glVertex3f(19, 6, 10.1);
    glVertex3f(16, 6, 10.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(16.3, -5.7, 10.2);
    glVertex3f(18.7, -5.7, 10.2);
    glVertex3f(18.7, 5.7, 10.2);
    glVertex3f(16.3, 5.7, 10.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2,0.2,0.2);
    glVertex3f(16.3, -5.7, 10.3);
    glVertex3f(18.7, -5.7, 10.3);
    glVertex3f(18.7, 5.7, 10.3);
    glEnd();
}

void wall_depan_atas_r(void)
{
    //depan atas
    glBegin(GL_POLYGON);
    glColor3f(0.2, 1.0,0.2);
    glVertex3f(0.0, 10.0, 10.1);
    glVertex3f(0.0, 15.0, 10.1);
    glVertex3f(5.0, 20.0, 10.1);
    glVertex3f(10.0, 28.0, 10.1);
    glVertex3f(15.0, 20.0, 10.1);
    glVertex3f(20.0, 15.0, 10.1);
    glVertex3f(20.0, 10.0, 10.1);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.5,0.0);
    glVertex3f(5.0, 20.0, 10.2);
    glVertex3f(10.0, 28.0, 10.2);
    glVertex3f(10.0, 28.0, 10.2);
    glVertex3f(15.0, 20.0, 10.2);
    glEnd();
    glLineWidth(2.0);

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(0.0, 10.0, 10.2);
    glVertex3f(0.0, 17.0, 10.2);
    glVertex3f(2.0, 18.0, 10.2);
    glVertex3f(2.0, 10.0, 10.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(2.5, 10.0, 10.2);
    glVertex3f(2.5, 19.0, 10.2);
    glVertex3f(4.5, 20.0, 10.2);
    glVertex3f(4.5, 10.0, 10.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(17.5, 10.0, 10.2);
    glVertex3f(17.5, 19.0, 10.2);
    glVertex3f(15.5, 20.0, 10.2);
    glVertex3f(15.5, 10.0, 10.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(20.0, 10.0, 10.2);
    glVertex3f(20.0, 17.0, 10.2);
    glVertex3f(18.0, 18.0, 10.2);
    glVertex3f(18.0, 10.0, 10.2);
    glEnd();
}

void salib(void)
{
    //salib
    glBegin(GL_LINES);
    glColor3f(1.0,0.2,0.0);
    glVertex3f(10.0, 24.0, 10.2);
    glVertex3f(10.0, 16.0, 10.2);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(8.5, 21.0, 10.2);
    glVertex3f(11.5, 21.0, 10.2);
    glEnd();
}

void lantai_depan(void)
{
    //lantai
    glBegin(GL_POLYGON);
    glColor3f(0.98, 0.98, 0.98);
    glVertex3f(2.0, -10.0, 15.0);
    glVertex3f(2.0, -10.0, 20.0);
    glVertex3f(18.0, -10.0, 20.0);
    glVertex3f(18.0, -10.0, 15.0);
    glVertex3f(20.0, -10.0, 15.0);
    glVertex3f(20.0, -10.0, 10.0);
    glVertex3f(-2.5, -10.0, 10.0);
    glVertex3f(-2.5, -10.0, 15.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.98, 0.98, 0.98);
    glVertex3f(0.0, -10.0, 10.0);
    glVertex3f(-2.5, -10.0, 10.0);
    glVertex3f(-2.5, -10.0, -20.0);
    glVertex3f(0.0, -10.0, -20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.98, 0.98, 0.98);
    glVertex3f(-20.0, -10.0, -25.0);
    glVertex3f(-20.0, -10.0, -20.0);
    glVertex3f(0.0, -10.0, -20.0);
    glVertex3f(0.0, -10.0, -25.0);
    glEnd();
}

void dak_depan(void)
{
    //depan dak
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(2.0, 10.0, 15.0);
    glVertex3f(2.0, 10.0, 20.0);
    glVertex3f(18.0, 10.0, 20.0);
    glVertex3f(18.0, 10.0, 15.0);
    glVertex3f(22.5, 10.0, 15.0);
    glVertex3f(22.5, 10.0, 10.0);
    glVertex3f(-2.5, 10.0, 10.0);
    glVertex3f(-2.5, 10.0, 15.0);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-2.5-0.1, 10.0, 10.0);
    glVertex3f(-2.5-0.1, 10.0, 15.0+0.1);
    glVertex3f(2.0, 10.0, 15.0+0.1);
    glVertex3f(2.0-0.1, 10.0, 20.0+0.1);
    glVertex3f(18.0, 10.0, 20.0+0.1);
    glVertex3f(18.0, 10.0, 15.0+0.1);
    glVertex3f(22.5, 10.0, 15.0+0.1);
    glVertex3f(22.5, 10.0, 10.0);
    glEnd();
    glLineWidth(2.0);

    glBegin(GL_POLYGON);
    glColor3f(0.3,0.8,0.3);
    glVertex3f(-2.5f, 10.0f, 10.0f);
    glVertex3f(-2.5f, 10.0f, 15.0f);
    glVertex3f(-2.5f, 8.0f, 15.0f);
    glVertex3f(-2.5f, 8.0f, 10.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-2.5f, 10.0f, 15.0f);
    glVertex3f(2.0f, 10.0f, 15.0f);
    glVertex3f(2.0f, 8.0f, 15.0f);
    glVertex3f(-2.5f, 8.0f, 15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(2.0f, 10.0f, 15.0f);
    glVertex3f(2.0f, 10.0f, 20.0f);
    glVertex3f(2.0f, 8.0f, 20.0f);
    glVertex3f(2.0f, 8.0f, 15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(2.0f, 10.0f, 20.0f);
    glVertex3f(18.0f, 10.0f, 20.0f);
    glVertex3f(18.0f, 8.0f, 20.0f);
    glVertex3f(2.0f, 8.0f, 20.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(18.0f, 10.0f, 20.0f);
    glVertex3f(18.0f, 10.0f, 15.0f);
    glVertex3f(18.0f, 8.0f, 15.0f);
    glVertex3f(18.0f, 8.0f, 20.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(18.0f, 10.0f, 15.0f);
    glVertex3f(22.5f, 10.0f, 15.0f);
    glVertex3f(22.5f, 8.0f, 15.0f);
    glVertex3f(18.0f, 8.0f, 15.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(22.5f, 10.0f, 15.0f);
    glVertex3f(22.5f, 10.0f, 10.0f);
    glVertex3f(22.5f, 8.0f, 10.0f);
    glVertex3f(22.5f, 8.0f, 15.0f);
    glEnd();
}

void tiang_depan(void)
{
    //tiang depan kiri
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(4.0, -10.0, 19.0);
    glVertex3f(4.0, 10.0, 19.0);
    glVertex3f(6.0, 10.0, 19.0);
    glVertex3f(6.0, -10.0, 19.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(4.0, -10.0, 18.0);
    glVertex3f(4.0, 10.0, 18.0);
    glVertex3f(6.0, 10.0, 18.0);
    glVertex3f(6.0, -10.0, 18.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(4.0, -10.0, 19.0);
    glVertex3f(4.0, 10.0, 19.0);
    glVertex3f(4.0, 10.0, 18.0);
    glVertex3f(4.0, -10.0, 18.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(6.0, -10.0, 19.0);
    glVertex3f(6.0, 10.0, 19.0);
    glVertex3f(6.0, 10.0, 18.0);
    glVertex3f(6.0, -10.0, 18.0);
    glEnd();

    //tiang depan kanan
    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(14.0, -10.0, 19.0);
    glVertex3f(14.0, 10.0, 19.0);
    glVertex3f(16.0, 10.0, 19.0);
    glVertex3f(16.0, -10.0, 19.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(14.0, -10.0, 18.0);
    glVertex3f(14.0, 10.0, 18.0);
    glVertex3f(16.0, 10.0, 18.0);
    glVertex3f(16.0, -10.0, 18.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(14.0, -10.0, 19.0);
    glVertex3f(14.0, 10.0, 19.0);
    glVertex3f(14.0, 10.0, 18.0);
    glVertex3f(14.0, -10.0, 18.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.2,0.2);
    glVertex3f(16.0, -10.0, 19.0);
    glVertex3f(16.0, 10.0, 19.0);
    glVertex3f(16.0, 10.0, 18.0);
    glVertex3f(16.0, -10.0, 18.0);
    glEnd();
}

void wall_kanan_r(void)
{
    //samping kanan
    glBegin(GL_QUADS);
    glColor3f(0.2, 1.0, 0.2);
    glVertex3f(20.0, -10.0, 10.0);
    glVertex3f(20.0, 13.0, 10.0);
    glVertex3f(20.0, 13.0, -60.0);
    glVertex3f(20.0, -10.0, -60.0);
    glEnd();
}

void jendela_kanan_r(void)
{
    //jendela samping kanan 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.1, -2.0, 2.0);
    glVertex3f(20.1, 5.0, 2.0);
    glVertex3f(20.1, 5.0, -3.0);
    glVertex3f(20.1, -2.0, -3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(20.2, -1.7, 1.7);
    glVertex3f(20.2, 4.7, 1.7);
    glVertex3f(20.2, 4.7, -2.7);
    glVertex3f(20.2, -1.7, -2.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(20.3, -2.0+0.3, -0.5);
    glVertex3f(20.3, 5.0-0.3, -0.5);
    glEnd();

    //jendela samping kanan 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.1, -2.0, -12.0);
    glVertex3f(20.1, 5.0, -12.0);
    glVertex3f(20.1, 5.0, -17.0);
    glVertex3f(20.1, -2.0, -17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(20.2, -1.7, -12.3);
    glVertex3f(20.2, 4.7, -12.3);
    glVertex3f(20.2, 4.7, -16.7);
    glVertex3f(20.2, -1.7, -16.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(20.3, -2.0+0.3, -14.5);
    glVertex3f(20.3, 5.0-0.3, -14.5);
    glEnd();

    //jendela samping kanan 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.1, -1.0, -29.5);
    glVertex3f(20.1, 5.0, -29.5);
    glVertex3f(20.1, 5.0, -34.5);
    glVertex3f(20.1, -1.0, -34.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(20.2, -0.7, -29.8);
    glVertex3f(20.2, 4.7, -29.8);
    glVertex3f(20.2, 4.7, -34.2);
    glVertex3f(20.2, -0.7, -34.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(20.3, -1.0+0.3, -32.0);
    glVertex3f(20.3, 5.0-0.3, -32.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(20.3, 2.0, -29.8);
    glVertex3f(20.3, 2.0, -34.2);
    glEnd();

    //jendela samping kanan 4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(20.1, -1.0, -52.5);
    glVertex3f(20.1, 5.0, -52.5);
    glVertex3f(20.1, 5.0, -57.5);
    glVertex3f(20.1, -1.0, -57.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(20.2, -0.7, -52.8);
    glVertex3f(20.2, 4.7, -52.8);
    glVertex3f(20.2, 4.7, -57.2);
    glVertex3f(20.2, -0.7, -57.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(20.3, -1.0+0.3, -55.0);
    glVertex3f(20.3, 5.0-0.3, -55.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(20.3, 2.0, -52.8);
    glVertex3f(20.3, 2.0, -57.2);
    glEnd();
}

void wall_kiri_r(void)
{
    //samping kiri
    glBegin(GL_QUADS);
    glColor3f(0.2, 1.0, 0.2);
    glVertex3f(0.0, -10.0, 10.0);
    glVertex3f(0.0, 13.0-0.1, 10.0);
    glVertex3f(0.0, 13.0-0.1, -25.0);
    glVertex3f(0.0, -10.0, -25.0);
    glEnd();
}

void jendela_kiri_r(void)
{
    //jendela samping kiri 1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.1, -5.0, 2.0);
    glVertex3f(-0.1, 5.0, 2.0);
    glVertex3f(-0.1, 5.0, -3.0);
    glVertex3f(-0.1, -5.0, -3.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-0.2, -5.0+0.3, 2.0-0.3);
    glVertex3f(-0.2, 5.0-0.3, 2.0-0.3);
    glVertex3f(-0.2, 5.0-0.3, -3.0+0.3);
    glVertex3f(-0.2, -5.0+0.3, -3.0+0.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.3, -4.7, -0.5);
    glVertex3f(-0.3, 4.7, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.3, 2.5, 1.7);
    glVertex3f(-0.3, 2.5, -2.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.3, 0.0, 1.7);
    glVertex3f(-0.3, 0.0, -2.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.3, -2.5, 1.7);
    glVertex3f(-0.3, -2.5, -2.7);
    glEnd();

    //jendela samping kiri 2
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.1, -5.0, -12.0);
    glVertex3f(-0.1, 5.0, -12.0);
    glVertex3f(-0.1, 5.0, -17.0);
    glVertex3f(-0.1, -5.0, -17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-0.2, -5.0+0.3, -12.0-0.3);
    glVertex3f(-0.2, 5.0-0.3, -12.0-0.3);
    glVertex3f(-0.2, 5.0-0.3, -17.0+0.3);
    glVertex3f(-0.2, -5.0+0.3, -17.0+0.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.3, -4.7, -14.5);
    glVertex3f(-0.3, 4.7, -14.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.3, -2.5, -11.7);
    glVertex3f(-0.3, -2.5, -16.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.3, 0.0, -11.7);
    glVertex3f(-0.3, 0.0, -16.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.3, 2.5, -11.7);
    glVertex3f(-0.3, 2.5, -16.7);
    glEnd();
}

void segitiga_r(void)
{
    glBegin(GL_POLYGON);
    glColor3f(0.2, 1.0,0.2);
    glVertex3f(20.0-0.1, 13.0, -60.0);
    glVertex3f(0.0, 13.0, -60.0);
    glVertex3f(10.0, 23.0-0.1, -60.0);
    glEnd();
}



///bagian kiri

void kanopi_depan(void)
{
    //kanopi
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.0, 1.0);
    glVertex3f(-0.1, 10.0, 10.0);
    glVertex3f(-20.0, 8.5, 10.0);
    glVertex3f(-20.0, 8.5, -20.0);
    glVertex3f(-0.1, 10.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.0, 1.0);
    glVertex3f(-2.5, 10.5, 9.9);
    glVertex3f(-20.1, 9.0, 9.9);
    glVertex3f(-20.1, 7.0, 9.9);
    glVertex3f(-2.5, 8.5, 9.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.0, 1.0);
    glVertex3f(-20.1, 9.0, 9.9);
    glVertex3f(-20.1, 7.0, 9.9);
    glVertex3f(-20.1, 7.0, -20.0);
    glVertex3f(-20.1, 9.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.0, 1.0);
    glVertex3f(-1.5, 10.5, -20.0);
    glVertex3f(-20.1, 9.0, -20.0);
    glVertex3f(-20.1, 7.0, -20.0);
    glVertex3f(-1.5, 8.5, -20.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(-19.0, 8.5, 9.0);
    glVertex3f(-19.0, -10.0, 9.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(-19.0, 8.5, -19.0);
    glVertex3f(-19.0, -10.0, -19.0);
    glEnd();
    glLineWidth(2.0);
}

void wall_depan_l(void)
{
    //depan wajah
    glBegin(GL_QUADS);
    glColor3f(0.2, 1.0,0.2);
    glVertex3f(0.0, -10.0, -25.0);
    glVertex3f(0.0, 13.0, -25.0);
    glVertex3f(-20.0, 13.0, -25.0);
    glVertex3f(-20.0, -10.0, -25.0);
    glEnd();
}

void segitiga_l(void)
{
    //segitiga dibawah atap
    glBegin(GL_POLYGON);
    glColor3f(0.2, 1.0,0.2);
    glVertex3f(-20.0-0.1, 13.0, -25.0);
    glVertex3f(0.0, 13.0, -25.0);
    glVertex3f(-10.0, 23.0-0.1, -25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 1.0,0.2);
    glVertex3f(-20.0-0.1, 9.0, -20.0);
    glVertex3f(-20.0-0.1, 13.0, -20.0);
    glVertex3f(-10.0, 23.0-0.1, -20.0);
    glVertex3f(0.0, 13.0, -20.0);
    glVertex3f(0.0, 10.0, -20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 1.0,0.2);
    glVertex3f(-20.0-0.1, 13.0, -60.0);
    glVertex3f(0.0, 13.0, -60.0);
    glVertex3f(-10.0, 23.0-0.1, -60.0);
    glEnd();
}

void pintu_depan_l(void)
{
    //pintu
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, -10.0, -24.9);
    glVertex3f(-1.0, 2.0, -24.9);
    glVertex3f(-6.0, 2.0, -24.9);
    glVertex3f(-6.0, -10.0, -24.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.747059, 0.164706, 0.164706);
    glVertex3f(-1.3, -10.0, -24.8);
    glVertex3f(-1.3, 1.7, -24.8);
    glVertex3f(-5.7, 1.7, -24.8);
    glVertex3f(-5.7, -10.0, -24.8);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.547059, 0.144706, 0.144706);
    glVertex3f(-5.0, -2.0, -24.7);
    glVertex3f(-5.0, -5.0, -24.7);
    glEnd();
}

void wall_kiri_l(void)
{
    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.2, 1.0, 0.2);
    glVertex3f(-20.0, -10.0, -25.0);
    glVertex3f(-20.0, 13.0, -25.0);
    glVertex3f(-20.0, 13.0, -60.0);
    glVertex3f(-20.0, -10.0, -60.0);
    glEnd();
}

void jendela_depan_l(void)
{
    //jendela depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-6.5, -7.0, -24.9);
    glVertex3f(-6.5, 2.0, -24.9);
    glVertex3f(-15.5, 2.0, -24.9);
    glVertex3f(-15.5, -7.0, -24.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-6.8, -6.7, -24.8);
    glVertex3f(-6.8, 1.7, -24.8);
    glVertex3f(-15.2, 1.7, -24.8);
    glVertex3f(-15.2, -6.7, -24.8);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-11.0, -6.7, -24.7);
    glVertex3f(-11.0, 1.7, -24.7);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-6.8, 0.0, -24.7);
    glVertex3f(-15.2, 0.0, -24.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-6.8, -2.5, -24.7);
    glVertex3f(-15.2, -2.5, -24.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-6.8, -5.0, -24.7);
    glVertex3f(-15.2, -5.0, -24.7);
    glEnd();

    glLineWidth(1.0);
}

void jendela_kiri_l(void)
{
    //jendela samping kiri 3
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.1, -1.0, -29.5);
    glVertex3f(-20.1, 5.0, -29.5);
    glVertex3f(-20.1, 5.0, -34.5);
    glVertex3f(-20.1, -1.0, -34.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-20.2, -1.0+0.3, -29.5-0.3);
    glVertex3f(-20.2, 5.0-0.3, -29.5-0.3);
    glVertex3f(-20.2, 5.0-0.3, -34.5+0.3);
    glVertex3f(-20.2, -1.0+0.3, -34.5+0.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-20.3, -1.0+0.3, -32.0);
    glVertex3f(-20.3, 5.0-0.3, -32.0);
    glEnd();

    //jendela samping kiri 4
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.1, -1.0, -41.0);
    glVertex3f(-20.1, 5.0, -41.0);
    glVertex3f(-20.1, 5.0, -46.0);
    glVertex3f(-20.1, -1.0, -46.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-20.2, -1.0+0.3, -41.0-0.3);
    glVertex3f(-20.2, 5.0-0.3, -41.0-0.3);
    glVertex3f(-20.2, 5.0-0.3, -46.0+0.3);
    glVertex3f(-20.2, -1.0+0.3, -46.0+0.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-20.3, -1.0+0.3, -43.5);
    glVertex3f(-20.3, 5.0-0.3, -43.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-20.3, 2.0, -41.0-0.3);
    glVertex3f(-20.3, 2.0, -46.0+0.3);
    glEnd();

    //fentilasi gudang
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-20.1, 5.0, -52.5);
    glVertex3f(-20.1, 7.0, -52.5);
    glVertex3f(-20.1, 7.0, -57.5);
    glVertex3f(-20.1, 5.0, -57.5);
    glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
    glColor3f(0.2,1.0,0.2);
    glVertex3f(-20.3, 5.0, -54.0);
    glVertex3f(-20.3, 7.0, -54.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.2,1.0,0.2);
    glVertex3f(-20.3, 5.0, -56.0);
    glVertex3f(-20.3, 7.0, -56.0);
    glEnd();
    glLineWidth(2.0);
}



///belakang

void wall_belakang(void)
{
    //sisi belakang
    glBegin(GL_QUADS);
    glColor3f(0.2, 1.0,0.2);
    glVertex3f(-20.0, -10.0, -60.0);
    glVertex3f(-20.0, 13.0, -60.0);
    glVertex3f(20.0, 13.0, -60.0);
    glVertex3f(20.0, -10.0, -60.0);
    glEnd();
}

void kanopi_belakang(void)
{
    //kanopi belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-20.0, 10.0, -60.0);
    glVertex3f(-20.0, 8.5, -70.0);
    glVertex3f(20.0, 8.5, -70.0);
    glVertex3f(20.0, 10.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-20.0, 10.5, -60.0);
    glVertex3f(-20.0, 9.0, -70.0);
    glVertex3f(-20.0, 7.0, -70.0);
    glVertex3f(-20.0, 8.5, -60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(20.0, 10.5, -60.0);
    glVertex3f(20.0, 9.0, -70.0);
    glVertex3f(20.0, 7.0, -70.0);
    glVertex3f(20.0, 8.5, -60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-20.0, 9.0, -70.0);
    glVertex3f(20.0, 9.0, -70.0);
    glVertex3f(20.0, 7.0, -70.0);
    glVertex3f(-20.0, 7.0, -70.0);
    glEnd();

    glLineWidth(6.0);
    glBegin(GL_LINES);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(-19.0, 8.5, -69.0);
    glVertex3f(-19.0, -10.0, -69.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(19.0, 8.5, -69.0);
    glVertex3f(19.0, -10.0, -69.0);
    glEnd();
    glLineWidth(2.0);
}

void lantai_belakang(void)
{
    //lantai belakang
    glBegin(GL_QUADS);
    glColor3f(0.97, 0.97, 0.97);
    glVertex3f(-20.0, -10.0, -60.0);
    glVertex3f(-20.0, -10.0, -65.0);
    glVertex3f(20.0, -10.0, -65.0);
    glVertex3f(20.0, -10.0, -60.0);
    glEnd();
}

void pintu_belakang(void)
{
    //pintu belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -10.0, -60.1);
    glVertex3f(1.0, 2.0, -60.1);
    glVertex3f(6.0, 2.0, -60.1);
    glVertex3f(6.0, -10.0, -60.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.747059, 0.164706, 0.164706);
    glVertex3f(1.0+0.3, -10.0, -60.2);
    glVertex3f(1.0+0.3, 2.0-0.3, -60.2);
    glVertex3f(6.0-0.3, 2.0-0.3, -60.2);
    glVertex3f(6.0-0.3, -10.0, -60.2);
    glEnd();
}

void jendela_belakang(void)
{
    //jendela belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-6.0, -5.0, -60.1);
    glVertex3f(-6.0, 2.0, -60.1);
    glVertex3f(-12.0, 2.0, -60.1);
    glVertex3f(-12.0, -5.0, -60.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(-6.0-0.3, -5.0+0.3, -60.2);
    glVertex3f(-6.0-0.3, 2.0-0.3, -60.2);
    glVertex3f(-12.0+0.3, 2.0-0.3, -60.2);
    glVertex3f(-12.0+0.3, -5.0+0.3, -60.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-9.0, -5.0+0.3, -60.3);
    glVertex3f(-9.0, 2.0-0.3, -60.3);
    glEnd();
}



///atap

void atap_kiri_depan_r(void)
{
    //atap kanan kiri depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-2.0, 11.0, 10.0);
    glVertex3f(10.0, 23.0, 10.0);
    glVertex3f(10.0, 23.0, -20.0);
    glVertex3f(-2.0, 11.0, -20.0);
    glEnd();
}

void atap_kiri_belakang_r(void)
{
    //atap kanan kiri belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(0.0, 13.0, -20.0);
    glVertex3f(10.0, 23.0, -20.0);
    glVertex3f(10.0, 23.0, -62.0);
    glVertex3f(0.0, 13.0, -62.0);
    glEnd();
}

void atap_kanan_r(void)
{
    //atap kanan kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(22.0, 11.5, 10.0);
    glVertex3f(10.0, 23.0, 10.0);
    glVertex3f(10.0, 23.0, -62.0);
    glVertex3f(22.0, 11.5, -62.0);
    glEnd();
}

void atap_kanan_l(void)
{
    //atap kiri kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(0.0, 13.0, -17.0);
    glVertex3f(-10.0, 23.0, -17.0);
    glVertex3f(-10.0, 23.0, -62.0);
    glVertex3f(0.0, 13.0, -62.0);
    glEnd();
}

void atap_kiri_l(void)
{
    //atap kiri kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(-22.0, 11.5, -17.0);
    glVertex3f(-10.0, 23.0, -17.0);
    glVertex3f(-10.0, 23.0, -62.0);
    glVertex3f(-22.0, 11.5, -62.0);
    glEnd();
}



///alas

void alas(void)
{
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-40, -10-0.2, 50);
    glVertex3f(40, -10-0.2, 50);
    glVertex3f(40, -10-0.2, -100);
    glVertex3f(-40, -10-0.2, -100);
    glEnd();
}



///dalam

void wall_depan_tengah(void)
{
    //batas ruang tamu & tengah
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-20.0+0.2, -10.0, -38.0);
    glVertex3f(20.0-0.4, -10.0, -38.0);
    glVertex3f(20.0-0.4, 13.0, -38.0);
    glVertex3f(-20.0+0.2, 13.0, -38.0);
    glEnd();
}

void wall_tengah_belakang(void)
{
    //batas ruang tengah & dapur
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-20.0+0.2, -10.0, -50.0);
    glVertex3f(20.0-0.4, -10.0, -50.0);
    glVertex3f(20.0-0.4, 13.0, -50.0);
    glVertex3f(-20.0+0.2, 13.0, -50.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glVertex3f(-20.0+0.2, -10.0, -59.9);
    glVertex3f(20.0-0.4, -10.0, -59.9);
    glVertex3f(20.0-0.4, 13.0, -59.9);
    glVertex3f(-20.0+0.2, 13.0, -59.9);
    glEnd();
}

void wall_kmr1_gereja(void)
{
    //batas ruang L & depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-20.0, -10.0, -25.0);
    glVertex3f(20.0-0.4, -10.0, -25.0);
    glVertex3f(20.0-0.4, 13.0, -25.0);
    glVertex3f(-20.0, 13.0, -25.0);
    glEnd();
}

void wall_kmr1_tamu(void)
{
    //kamar depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(7.0, -10.0, -25.0);
    glVertex3f(7.0, 13.0, -25.0);
    glVertex3f(7.0, 13.0, -38.0);
    glVertex3f(7.0, -10.0, -38.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(19.9, -10.0, -25.0);
    glVertex3f(19.9, 13.0, -25.0);
    glVertex3f(19.9, 13.0, -60.0);
    glVertex3f(19.9, -10.0, -60.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-19.9, -10.0, -25.0);
    glVertex3f(-19.9, 13.0, -25.0);
    glVertex3f(-19.9, 13.0, -60.0);
    glVertex3f(-19.9, -10.0, -60.0);
    glEnd();
}

void wall_kmr3_dapur(void)
{
    //kamar belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(7.0, -10.0, -50.0);
    glVertex3f(7.0, 13.0, -50.0);
    glVertex3f(7.0, 13.0, -60.0+0.1);
    glVertex3f(7.0, -10.0, -60.0+0.1);
    glEnd();
}

void wall_toilet(void)
{
    //toilet
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(12.0, -10.0, -38.0);
    glVertex3f(12.0, 13.0, -38.0);
    glVertex3f(12.0, 13.0, -50.0);
    glVertex3f(12.0, -10.0, -50.0);
    glEnd();

    //toilet
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(12.0, -10.0, -44.0);
    glVertex3f(12.0, 13.0, -44.0);
    glVertex3f(20.0-0.4, 13.0, -44.0);
    glVertex3f(20.0-0.4, -10.0, -44.0);
    glEnd();
}

void wall_kmr2_tengah(void)
{
    //kamar tengah
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-10.0, -10.0, -38.0);
    glVertex3f(-10.0, 13.0, -38.0);
    glVertex3f(-10.0, 13.0, -50.0);
    glVertex3f(-10.0, -10.0, -50.0);
    glEnd();
}

void wall_gudang_dapur(void)
{
    //gudang
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.5);
    glVertex3f(-15.0, -10.0, -50.0);
    glVertex3f(-15.0, 13.0, -50.0);
    glVertex3f(-15.0, 13.0, -60.0+0.1);
    glVertex3f(-15.0, -10.0, -60.0+0.1);
    glEnd();
}


///parabot
void tv(void)
{
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(6.9, -1.0, -28.0);
    glVertex3f(6.9, -1.0, -32.0);
    glVertex3f(6.9, -4.0, -32.0);
    glVertex3f(6.9, -4.0, -28.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(6.8, -1.0, -28.0);
    glVertex3f(6.8, -1.0, -32.0);
    glVertex3f(6.8, -4.0, -32.0);
    glVertex3f(6.8, -4.0, -28.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(6.7, -1.0, -28.0);
    glVertex3f(6.7, -1.0, -32.0);
    glVertex3f(6.7, -4.0, -32.0);
    glVertex3f(6.7, -4.0, -28.0);
    glEnd();
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex3f(6.6999, -3.8, -28.5);
    glEnd();
}

void lemari(void)
{
    glBegin(GL_QUADS);
    glColor3f(0.747059, 0.164706, 0.164706);
    glVertex3f(-8.0, -9.9, -49.9);
    glVertex3f(-8.0, 3.0, -49.9);
    glVertex3f(-8.0, 3.0, -46.9);
    glVertex3f(-8.0, -9.9, -46.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-3.0, -9.9, -49.9);
    glVertex3f(-3.0, 3.0, -49.9);
    glVertex3f(-3.0, 3.0, -46.9);
    glVertex3f(-3.0, -9.9, -46.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, 3.0, -46.9);
    glVertex3f(-8.0, -9.9, -46.9);
    glVertex3f(-3.0, -9.9, -46.9);
    glVertex3f(-3.0, 3.0, -46.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, 3.0, -49.9);
    glVertex3f(-8.0, -9.9, -49.9);
    glVertex3f(-3.0, -9.9, -49.9);
    glVertex3f(-3.0, 3.0, -49.9);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-8.0, -9.9, -49.9);
    glVertex3f(-8.0, -9.9, -46.9);
    glVertex3f(-3.0, -9.9, -46.9);
    glVertex3f(-3.0, -9.9, -49.9);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.547059, 0.164706, 0.164706);
    glVertex3f(-7.5, -9.5, -46.899);
    glVertex3f(-7.5, 2.5, -46.899);
    glVertex3f(-3.5, 2.5, -46.899);
    glVertex3f(-3.5, -9.5, -46.899);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-5.5, -9.5, -46.899);
    glVertex3f(-5.5, 2.5, -46.899);
    glEnd();
}

void kasur(void)
{
    //atas
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(19.9, -7.0, -25.5);
    glVertex3f(19.9, -7.0, -31.5);
    glVertex3f(10.0, -7.0, -31.5);
    glVertex3f(10.0, -7.0, -25.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(19.9, -8.5, -25.5);
    glVertex3f(19.9, -8.5, -31.5);
    glVertex3f(10.0, -8.5, -31.5);
    glVertex3f(10.0, -8.5, -25.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(19.9, -8.5, -31.5);
    glVertex3f(10.0, -8.5, -31.5);
    glVertex3f(10.0, -7.0, -31.5);
    glVertex3f(19.9, -7.0, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, -7.0, -31.5);
    glVertex3f(10.0, -7.0, -25.5);
    glVertex3f(10.0, -8.5, -25.5);
    glVertex3f(10.0, -8.5, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(19.9, -7.0, -31.5);
    glVertex3f(19.9, -7.0, -25.5);
    glVertex3f(19.9, -8.5, -25.5);
    glVertex3f(19.9, -8.5, -31.5);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(19.9, -8.5, -31.5);
    glVertex3f(10.0, -8.5, -31.5);
    glVertex3f(10.0, -9.9, -31.5);
    glVertex3f(19.9, -9.9, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(10.0, -9.9, -31.5);
    glVertex3f(10.0, -9.9, -25.5);
    glVertex3f(10.0, -8.5, -25.5);
    glVertex3f(10.0, -8.5, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(19.9, -9.9, -31.5);
    glVertex3f(19.9, -9.9, -25.5);
    glVertex3f(19.9, -8.5, -25.5);
    glVertex3f(19.9, -8.5, -31.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(19.9, -8.5, -25.5);
    glVertex3f(10.0, -8.5, -25.5);
    glVertex3f(10.0, -9.9, -25.5);
    glVertex3f(19.9, -9.9, -25.5);
    glEnd();
}

void sofa(void)
{
    //sandaran
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-19.9, -9.9, -25.2);
    glVertex3f(-19.9, -6.0, -25.2);
    glVertex3f(-19.9, -6.0, -35.0);
    glVertex3f(-19.9, -9.9, -35.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -9.9, -25.2);
    glVertex3f(-18.9, -6.0, -25.2);
    glVertex3f(-18.9, -6.0, -35.0);
    glVertex3f(-18.9, -9.9, -35.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -9.9, -25.2);
    glVertex3f(-18.9, -6.0, -25.2);
    glVertex3f(-19.9, -6.0, -25.2);
    glVertex3f(-19.9, -9.9, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -9.9, -35.0);
    glVertex3f(-18.9, -6.0, -35.0);
    glVertex3f(-19.9, -6.0, -35.0);
    glVertex3f(-19.9, -9.9, -35.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -6.0, -25.2);
    glVertex3f(-18.9, -6.0, -35.0);
    glVertex3f(-19.9, -6.0, -35.0);
    glVertex3f(-19.9, -6.0, -25.2);
    glEnd();

    //pegangan
    glBegin(GL_QUADS);
    glVertex3f(-18.9, -9.9, -25.2);
    glVertex3f(-18.9, -7.0, -25.2);
    glVertex3f(-17.5, -7.0, -25.2);
    glVertex3f(-17.5, -9.9, -25.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -9.9, -25.7);
    glVertex3f(-18.9, -7.0, -25.7);
    glVertex3f(-17.5, -7.0, -25.7);
    glVertex3f(-17.5, -9.9, -25.7);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -9.9, -34.5);
    glVertex3f(-18.9, -7.0, -34.5);
    glVertex3f(-17.5, -7.0, -34.5);
    glVertex3f(-17.5, -9.9, -34.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -9.9, -35.0);
    glVertex3f(-18.9, -7.0, -35.0);
    glVertex3f(-17.5, -7.0, -35.0);
    glVertex3f(-17.5, -9.9, -35.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -7.0, -35.0);
    glVertex3f(-17.5, -7.0, -35.0);
    glVertex3f(-17.5, -7.0, -34.5);
    glVertex3f(-18.9, -7.0, -34.5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-18.9, -7.0, -25.2);
    glVertex3f(-17.5, -7.0, -25.2);
    glVertex3f(-17.5, -7.0, -25.7);
    glVertex3f(-18.9, -7.0, -25.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-19.9, -8.5, -25.7);
    glVertex3f(-19.9, -8.5, -34.5);
    glVertex3f(-17.5, -8.5, -34.5);
    glVertex3f(-17.5, -8.5, -25.7);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-17.5, -8.5, -34.5);
    glVertex3f(-17.5, -8.5, -25.7);
    glVertex3f(-17.5, -9.9, -25.7);
    glVertex3f(-17.5, -9.9, -34.5);
    glEnd();


}

void meja(void)
{
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-16.0, -8.0, -27.0);
    glVertex3f(-10.0, -8.0, -27.0);
    glVertex3f(-10.0, -8.0, -31.0);
    glVertex3f(-16.0, -8.0, -31.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-16.0, -8.5, -27.0);
    glVertex3f(-10.0, -8.5, -27.0);
    glVertex3f(-10.0, -8.5, -31.0);
    glVertex3f(-16.0, -8.5, -31.0);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(-15.5, -8.1, -27.5);
    glVertex3f(-15.5, -9.9, -27.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-10.5, -8.1, -27.5);
    glVertex3f(-10.5, -9.9, -27.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-10.5, -8.1, -30.5);
    glVertex3f(-10.5, -9.9, -30.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-15.5, -8.1, -30.5);
    glVertex3f(-15.5, -9.9, -30.5);
    glEnd();
}



void tampil(void)
{
    if(is_depth){

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    else{
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glLoadIdentity();
//    gluLookAt(0.0f, 5.0f, 3.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);



    koordinat();
    ///alas
    alas();

    ///kanan
    wall_depan_bawah_r();
    pintu_depan_r();
    tiang_depan();
    lantai_depan();
    dak_depan();
    wall_depan_atas_r();
    salib();
    wall_kanan_r();
    wall_kiri_r();
    jendela_depan_l();
    jendela_kanan_r();
    jendela_kiri_r();
    segitiga_r();


    ///kiri
    wall_depan_l();
    wall_kiri_l();
    jendela_depan_l();
    pintu_depan_l();
    jendela_kiri_l();
    kanopi_depan();
    segitiga_l();


    ///belakang
    wall_belakang();
    pintu_belakang();
    jendela_belakang();
    kanopi_belakang();
    lantai_belakang();


    ///atap
    atap_kanan_l();
    atap_kanan_r();
    atap_kiri_belakang_r();
    atap_kiri_depan_r();
    atap_kiri_l();


    ///dalam
    wall_depan_tengah();
    wall_tengah_belakang();
    wall_kmr1_gereja();
    wall_kmr1_tamu();
    wall_kmr2_tengah();
    wall_toilet();
    wall_kmr3_dapur();
    wall_gudang_dapur();

    ///parabot
    tv();
    sofa();
    glPushMatrix();
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    glTranslatef(-17.5, 0.0, 41);
    sofa();
    glPopMatrix();
    lemari();
    kasur();
    glPushMatrix();
    glTranslatef(0.0, 0.0, -28);
    kasur();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0, 0.0, -1.5);
    meja();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();

}
