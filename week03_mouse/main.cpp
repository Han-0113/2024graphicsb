#include <GL/glut.h>
#include <stdio.h>
void display(){
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
         ///state: 0�U�h,1�W��
void mouse (int button,int state,int x,int y ){

    ///button:0����,1����,2�k��
    ///printf("%d %d %d %d\n",button,state,x,y);
    if(state==GLUT_DOWN){
        printf("glVertex2((%d-150)/150.0, (%d-150)/150.0);\n", x,y);
    }

}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 mouse");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);///�o�@��]�wmouse�禡

    glutMainLoop();
}
