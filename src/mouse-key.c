/*
 * ================================================================
 *	OpenGL mouse-key.c
 *	Note: glut sample app to show mouse and keyboard event.
 *  Build: gcc mouse-key.c -lGL -lglut
 * ================================================================
 */

#include<stdlib.h>
#include<ctype.h>
#include<GL/glut.h>
#include<GL/gl.h>

static GLfloat rot_y, rot_x;
static GLfloat bgn_y, bgn_x;
static int mouse_x, mouse_y;
static GLuint cubelist;

void display_func(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glTranslatef(0.0, 0.0, -15.0);

	glRotatef(rot_x, 1.0, 0.0, 0.0);
	glRotatef(rot_y, 0.0, 1.0, 0.0);

	glCallList(cubelist);

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


	list=glGenLists(1);

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

void mouse_func(int button, int stat, int x, int y)
{
	if(GLUT_DOWN==stat && GLUT_LEFT==button){
		mouse_x=x;
		mouse_y=y;
		bgn_y=rot_y;
		bgn_x=rot_x;
	}
}

void drag_func(int x, int y)
{
	rot_x=(GLfloat)(y-mouse_y)+bgn_x;
	rot_y=(GLfloat)(x-mouse_x)+bgn_y;

	if(90<rot_x){
		rot_x=90;
	}
	if(rot_x<-90){
		rot_x=-90;
	}
	
	glutPostRedisplay();
}

void key_func(unsigned char key, int x, int y)
{
	switch(toupper(key)){
	case 0x1b:	/* ESC */
	case 'Q':	/* Q */
		exit(0);
		break;
	}
}

void skey_func(int key, int x, int y)
{
	switch(key){
	case GLUT_KEY_UP:
		if(rot_x<180){
			rot_x+=10;
		}
		break;
	case GLUT_KEY_DOWN:
		if(-180<rot_x){
			rot_x-=10;
		}
		break;
	case GLUT_KEY_LEFT:
		rot_y+=10;
		break;
	case GLUT_KEY_RIGHT:
		rot_y-=10;
		break;
	}
	
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(300,300);

	glutCreateWindow("Sample 6");

	glutDisplayFunc(display_func);

	glutReshapeFunc(reshape_func);

	glutKeyboardFunc(key_func);
	glutSpecialFunc(skey_func);
	
	glutMotionFunc(drag_func);
	glutMouseFunc(mouse_func);

	glEnable(GL_DEPTH_TEST);
	
	cubelist=make_cube();

	glutMainLoop();

	return 0;
}