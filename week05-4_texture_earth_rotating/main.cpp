#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle = 0;
GLUquadric *quad = NULL;///�Ψӵe�a�y��quad�G������
void display(){
    glEnable(GL_DEPTH_TEST);///�}��3D���\��(�`�״���)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///(�M�I��)
    glPushMatrix();
        glRotatef(90,1,0,0);///�⥦��90�סA�K�O�W�U���b�A��_�Ӥ���n��
        glRotatef(angle++,0,0,1);///���Z�b��A�]���a�y���n�_���bZ�b
        gluSphere(quad,1,30,30);///�ΤG�������e�Ӷ�y�A��a�y
    glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05-4 texture_earth_rotating");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    quad = gluNewQuadric();///�ǳƦnquad�G������
    myTexture("c:/earth.jpg");
    gluQuadricTexture(quad,1);///�ǳƦnquad�G���������K��
    glutMainLoop();
}
