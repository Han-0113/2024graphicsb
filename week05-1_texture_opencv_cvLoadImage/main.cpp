#include <opencv/highgui.h>
#include <GL/glut.h>
void display(){
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    IplImage * img = cvLoadImage("C:/oppps.jpg");
    cvShowImage("opencv",img);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutMainLoop();
}
