#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
void drawmodel(void){
    if(!pmodel){
        pmodel = glmReadOBJ("data/porsche.obj");
        if(!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90.0);
    }
    glmDraw(pmodel,GLM_SMOOTH | GLM_MATERIAL);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH);
    drawmodel();///glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06-3 glm obj model");
    glutDisplayFunc(display);
    glutMainLoop();
}
