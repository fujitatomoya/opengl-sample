/*
 * ================================================================
 *	OpenGL draw-cube.c
 *	Note: sample 3D cube image describe.
 *  Build: gcc draw-cube.c -lGL -lglut
 * ================================================================
 */

#include<GL/glut.h>
#include<GL/gl.h>

void draw_cube()
{
	static GLfloat vert[][4]={
		{ 1.0,  1.0,  1.0},
		{-1.0,  1.0,  1.0},
		{-1.0, -1.0,  1.0},
		{ 1.0, -1.0,  1.0},
		{ 1.0,  1.0, -1.0},
		{-1.0,  1.0, -1.0},
		{-1.0, -1.0, -1.0},
		{ 1.0, -1.0, -1.0},
	};

	glBegin(GL_QUADS);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[1]);
		glVertex3fv(vert[2]);
		glVertex3fv(vert[3]);

		glVertex3fv(vert[4]);		
		glVertex3fv(vert[5]);		
		glVertex3fv(vert[6]);		
		glVertex3fv(vert[7]);		

		glVertex3fv(vert[0]);		
		glVertex3fv(vert[1]);		
		glVertex3fv(vert[5]);		
		glVertex3fv(vert[4]);

		glVertex3fv(vert[2]);		
		glVertex3fv(vert[3]);		
		glVertex3fv(vert[7]);		
		glVertex3fv(vert[6]);

		glVertex3fv(vert[3]);		
		glVertex3fv(vert[0]);		
		glVertex3fv(vert[4]);		
		glVertex3fv(vert[7]);

		glVertex3fv(vert[1]);		
		glVertex3fv(vert[2]);		
		glVertex3fv(vert[6]);		
		glVertex3fv(vert[5]);		
	glEnd();
}

void display_func(void)
{
	static GLfloat color[][4]={
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glTranslatef(0.0, 0.0, -15.0);

	glRotatef(30, 0.0, 1.0, 0.0);

	glColor3fv(color[0]);
	draw_cube();

	glPopMatrix();	

	glPushMatrix();

	glRotatef(10, 0.0, 1.0, 0.0);	

	glTranslatef(0.0, 0.0, -20.0);

	glColor3fv(color[1]);
	draw_cube();

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

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(300,300);

	glutCreateWindow("Sample 3");

	glutDisplayFunc(display_func);

	glutReshapeFunc(reshape_func);

	glEnable(GL_DEPTH_TEST);
	
	glutMainLoop();

	return 0;
}