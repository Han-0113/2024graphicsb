#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle = 0;
GLUquadric *quad = NULL;///用來畫地球的quad二次曲面
void display(){
    glEnable(GL_DEPTH_TEST);///開啟3D的功能(深度測試)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///(清背景)
    glPushMatrix();
        glRotatef(90,1,0,0);///把它轉90度，便是上下的軸，轉起來比較好看
        glRotatef(angle++,0,0,1);///對著Z軸轉，因為地球的南北極在Z軸
        gluSphere(quad,1,30,30);///用二次曲面畫個圓球，當地球
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
    quad = gluNewQuadric();///準備好quad二次曲面
    myTexture("c:/earth.jpg");
    gluQuadricTexture(quad,1);///準備好quad二次曲面的貼圖
    glutMainLoop();
}
