#include <GL/glut.h>
#include <stdio.h>
float teapotX = 0,teapotY = 0;///新加的程式，用來放茶壺的座標

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glTranslatef(teapotX,teapotY,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣

    glutSwapBuffers();
}
         ///state: 0下去,1上來
void mouse (int button,int state,int x,int y ){
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 mouse glTranslatef");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);///這一行設定mouse函式

    glutMainLoop();
}
