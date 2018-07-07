/*
 * ================================================================
 *	OpenGL list.c
 *	Note: sample 3D image describe using list.
 *  Build: gcc list.c -lGL -lglut
 * ================================================================
 */

#include <unistd.h>
#include <GL/glut.h>
#include <GL/gl.h>

static GLfloat rot;
static GLuint cubelist;

void display_func(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //sleep(1);

	glPushMatrix();

	glTranslatef(0.0, 0.0, -10.0);

	glRotatef(rot, 1.0, -1.0, 0.0);

	glPushMatrix();

	glTranslatef(0.0, 0.0, -5.0);
	glRotatef(rot*2, 1.0, 0.0, 0.0);
	glCallList(cubelist);

	glPopMatrix();	

	glPushMatrix();

	glTranslatef(0.0, 0.0, 5.0);
	glRotatef(rot*2, 1.0, 0.0, 0.0);
	glCallList(cubelist);

	glPopMatrix();	

	glPopMatrix();	

	glutSwapBuffers();
}

GLuint make_cube(void)
{
	GLint list;

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

	static GLfloat color[][4]={
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 1.0, 1.0, 0.0},
		{1.0, 0.0, 1.0, 0.0},
		{1.0, 1.0, 0.0, 0.0},
	};


	list = glGenLists(1);

	glNewList(list, GL_COMPILE);

	glBegin(GL_QUADS);
		glColor3fv(color[0]);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[1]);
		glVertex3fv(vert[2]);
		glVertex3fv(vert[3]);

		glColor3fv(color[1]);
		glVertex3fv(vert[4]);		
		glVertex3fv(vert[5]);		
		glVertex3fv(vert[6]);		
		glVertex3fv(vert[7]);		

		glColor3fv(color[2]);
		glVertex3fv(vert[0]);		
		glVertex3fv(vert[1]);		
		glVertex3fv(vert[5]);		
		glVertex3fv(vert[4]);

		glColor3fv(color[3]);
		glVertex3fv(vert[2]);		
		glVertex3fv(vert[3]);		
		glVertex3fv(vert[7]);		
		glVertex3fv(vert[6]);

		glColor3fv(color[4]);
		glVertex3fv(vert[3]);		
		glVertex3fv(vert[0]);		
		glVertex3fv(vert[4]);		
		glVertex3fv(vert[7]);

		glColor3fv(color[5]);
		glVertex3fv(vert[1]);		
		glVertex3fv(vert[2]);		
		glVertex3fv(vert[6]);		
		glVertex3fv(vert[5]);		

	glEnd();

	glEndList();
	
	return list;
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

	glutCreateWindow("Sample 5");

	glutDisplayFunc(display_func);

	glutReshapeFunc(reshape_func);

	glutIdleFunc(idle_func);

	glEnable(GL_DEPTH_TEST);
	
	cubelist = make_cube();

	glutMainLoop();
	return 0;
}