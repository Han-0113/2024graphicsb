#include <GL/glut.h>
#include <stdio.h>
float teapotX = 0,teapotY = 0;///�s�[���{���A�Ψө�������y��
float angle = 0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ��x�}
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();
}
         ///state: 0�U�h,1�W��
void mouse (int button,int state,int x,int y ){
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;

}
void motion(int x,int y){
    angle = x;
    display();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 mouse glRotatef");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);///�o�@��]�wmouse�禡
    glutMotionFunc(motion);///�o��]�wmouse��motion�ʧ@

    glutMainLoop();
}
