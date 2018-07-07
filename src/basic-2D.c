/*
 * ================================================================
 *	OpenGL basic-2D.c
 *	Note: sample 2D image describe.
 *  Build: gcc basic-2D.c -lGL -lglut
 * ================================================================
 */

#include<GL/glut.h>
#include<GL/gl.h>

void display_func(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex2f(-0.9, 0.9);
		glVertex2f(-0.6, 0.6);

		glVertex2f(-0.6, 0.9);
		glVertex2f(-0.9, 0.6);
	glEnd();

	glBegin(GL_LINE_STRIP);
		glVertex2f(-0.9, 0.5);
		glVertex2f(-0.9, 0.2);
		glVertex2f(-0.6, 0.2);
		glVertex2f(-0.6, 0.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.9,  0.0);
		glVertex2f(-0.9, -0.3);
		glVertex2f(-0.6, -0.3);
		glVertex2f(-0.6,  0.0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.4, 0.9);
		glVertex2f(-0.4, 0.7);
		glVertex2f(-0.1, 0.9);

		glVertex2f(-0.1, 0.8);
		glVertex2f(-0.4, 0.6);
		glVertex2f(-0.1, 0.6);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-0.4, 0.5);
		glVertex2f(-0.1, 0.5);
		glVertex2f(-0.4, 0.3);

		glVertex2f(-0.1, 0.3);

		glVertex2f(-0.4, 0.1);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(-0.1, -0.3);
		glVertex2f(-0.1,  0.0);
		glVertex2f(-0.3, -0.1);

		glVertex2f(-0.4, -0.3);

		glVertex2f(-0.3, -0.5);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2f(0.1, 0.9);
		glVertex2f(0.1, 0.7);
		glVertex2f(0.4, 0.7);
		glVertex2f(0.4, 0.9);

		glVertex2f(0.1, 0.6);
		glVertex2f(0.2, 0.4);
		glVertex2f(0.3, 0.4);
		glVertex2f(0.4, 0.6);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUAD_STRIP);
		glVertex2f(0.1,  0.0);
		glVertex2f(0.4,  0.0);
		glVertex2f(0.2, -0.2);
		glVertex2f(0.3, -0.2);

		glVertex2f(0.1, -0.4);
		glVertex2f(0.4, -0.4);

		glVertex2f(0.2, -0.6);
		glVertex2f(0.3, -0.6);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2f(0.7, 0.9);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, 0.3);
		glVertex2f(0.6, 0.1);
		glVertex2f(0.8, 0.1);
		glVertex2f(0.9, 0.3);
		glVertex2f(0.9, 0.5);
	glEnd();
	glFlush();
}


void reshape_func(int width, int height)
{
	glViewport(0, 0, width, height);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowSize(400,400);

	glutCreateWindow("Sample 1");

	glutDisplayFunc(display_func);

	glutReshapeFunc(reshape_func);

	glutMainLoop();
	return 0;
}