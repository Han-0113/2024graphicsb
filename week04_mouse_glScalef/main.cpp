#include <GL/glut.h>
float s=1;///一開始是原本一倍的大小
void display(){
    ///設定「清背景」的顏色
    glClearColor(1,1,0.9,1);///R,G,B,A
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清背景
    glColor3f(0,1,0);/// 3f就是R,G,B
    glPushMatrix();///備份矩陣
        glScalef(s,s,s); ///縮放S倍
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x,int y)
{
    s= 1 +(x-150)/150.0;///變大變小的變數0~1~2
    display();///重畫畫面
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 mouse glScalef");
    glutDisplayFunc(display);
    glutMotionFunc(motion);///拖動motion的時候
    glutMainLoop();
}
