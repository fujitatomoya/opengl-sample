/*
 * ================================================================
 *	OpenGL polygon.c
 *	Note: glut sample app to show polygon.
 *  Build: gcc polygon.c -lGL -lglut
 * ================================================================
 */

#include<GL/glut.h>
#include<GL/gl.h>

static GLfloat rot;

void display_func(void)
{
	static GLfloat vert[][4]={
		{-1.0,  1.0, 0.0, 0.0},
		{ 0.0,  1.0, 0.0, 0.0},
		{ 1.0,  1.0, 0.0, 0.0},
		{-1.0, -1.0, 0.0, 0.0},
		{ 0.0, -1.0, 0.0, 0.0},
		{ 1.0, -1.0, 0.0, 0.0},
	};

	static GLfloat color[][4]={
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glTranslatef(0.0, 0.0, -10.0);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	glRotatef(rot, 0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
		glColor3fv(color[0]);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[3]);
		glVertex3fv(vert[4]);
		glVertex3fv(vert[1]);

		glColor3fv(color[1]);
		glVertex3fv(vert[1]);		
		glVertex3fv(vert[4]);		
		glVertex3fv(vert[5]);		
		glVertex3fv(vert[2]);		
	glEnd();

	glPopMatrix();	

	glutSwapBuffers();
}

void reshape_func(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 3.0, 10000.0);

	glMatrixMode(GL_MODELVIEW);
}

void idle_func(void)
{
	rot=0.1*(GLfloat)glutGet(GLUT_ELAPSED_TIME);

	glutPostRedisplay();	
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(300,300);

	glutCreateWindow("Sample 10");

	glutDisplayFunc(display_func);

	glutReshapeFunc(reshape_func);

	glutIdleFunc(idle_func);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);

	glutMainLoop();
	return 0;
}