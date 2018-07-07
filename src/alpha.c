/*
 * ================================================================
 *	OpenGL alpha.c
 *	Note: glut sample app to show polygon alpha.
 *  Build: gcc alpha.c -lGL -lglut
 * ================================================================
 */

#include<stdlib.h>
#include<ctype.h>
#include<GL/glut.h>
#include<GL/gl.h>

static GLfloat alpha=0.5;

void display_func(void)
{
	GLfloat vert[][3]={
		{-1.0, -1.0},
		{ 1.0, -1.0},
		{ 1.0,  1.0},
		{-1.0,  1.0}
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0.0, 0.0, -15.0);

	glColor4f(1.0, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[1]);
		glVertex3fv(vert[2]);
		glVertex3fv(vert[3]);
	glEnd();

	glPopMatrix();	

	glPushMatrix();
	glTranslatef(-1.0, -1.0, -10.0);

	glColor4f(0.0, 0.0, 1.0, alpha);
	glBegin(GL_QUADS);
		glVertex3fv(vert[0]);
		glVertex3fv(vert[1]);
		glVertex3fv(vert[2]);
		glVertex3fv(vert[3]);
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

void key_func(unsigned char key, int x, int y)
{
	switch(toupper(key)){
	case 0x1b:	/* ESC */
	case 'Q':	/* Quit */
		exit(0);
		break;
	}
}

void skey_func(int key, int x, int y)
{
	switch(key){
	case GLUT_KEY_UP:
		if(alpha<1.0){
			alpha+=0.1;
		}
		break;
	case GLUT_KEY_DOWN:
		if(0.0<alpha){
			alpha-=0.1;
		}
		break;
	}
	
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(300,300);
	glutCreateWindow("Sample 13");

	glutDisplayFunc(display_func);
	glutReshapeFunc(reshape_func);

	glutKeyboardFunc(key_func);
	glutSpecialFunc(skey_func);
	
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	

	glutMainLoop();

	return 0;
}