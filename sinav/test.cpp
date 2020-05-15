#include <GL/glut.h>
 
void renderScene(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);
    glPointSize(2);
	glBegin(GL_POINTS);
		glVertex2f(-0.5, -0.5);
	glEnd();

    glPointSize(10);
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2f(0.0, 0.5);
	glEnd();
 
    glutSwapBuffers();
}
 
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Sinav");
 
	glutDisplayFunc(renderScene);
	glutMainLoop();
 
	return 1;
}