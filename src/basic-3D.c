/*
 * ================================================================
 *	OpenGL basic-3D.c
 *	Note: sample 3D image describe.
 *  Build: gcc basic-3D.c -lGL -lglut
 * ================================================================
 */

#include<GL/glut.h>
#include<GL/gl.h>

void display_func(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);

		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-1.0,  1.0,  -9.0);
		glVertex3f(-1.0,  1.0, -11.0);
		glVertex3f(-1.0, -1.0, -11.0);
		glVertex3f(-1.0, -1.0,  -9.0);		

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f( 1.0,  1.0,  -9.0);
		glVertex3f( 1.0,  1.0, -11.0);
		glVertex3f( 1.0, -1.0, -11.0);
		glVertex3f( 1.0, -1.0,  -9.0);		

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f( 1.0, 1.0,  -9.0);
		glVertex3f( 1.0, 1.0, -11.0);
		glVertex3f(-1.0, 1.0, -11.0);
		glVertex3f(-1.0, 1.0,  -9.0);		

		glColor3f(1.0, 1.0, 1.0);
		glVertex3f( 1.0, -1.0,  -9.0);
		glVertex3f( 1.0, -1.0, -11.0);
		glVertex3f(-1.0, -1.0, -11.0);
		glVertex3f(-1.0, -1.0,  -9.0);		
	glEnd();

	glFlush();
}


void reshape_func(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 3.0, 10000.0);

	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char *argv[])
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(400, 400);

	glutCreateWindow("Sample 2");

	glutDisplayFunc(display_func);

	glutReshapeFunc(reshape_func);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 0;
}