/*
 * ================================================================
 *	OpenGL material.c
 *	Note: glut sample app to show polygon material.
 *  Build: gcc material.c -lGL -lglut
 * ================================================================
 */

#include<GL/glut.h>
#include<GL/gl.h>

void init_light(void)
{
	static GLfloat lit_amb[4]={1.0, 1.0, 1.0, 0.0};
	static GLfloat lit_dif[4]={1.0, 1.0, 1.0, 0.0};
	static GLfloat lit_spc[4]={1.0, 1.0, 1.0, 0.0};
	static GLfloat lit_pos[4]={6.0, 6.0, -9.0, 1.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, lit_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lit_spc);
	glLightfv(GL_LIGHT0, GL_POSITION, lit_pos);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}


void display_func(void)
{
	static GLfloat mat_amb[4]={0.2, 0.2, 0.2, 0.0};
	static GLfloat mat_dif[4]={0.6, 0.6, 0.6, 0.0};
	static GLfloat mat_spc[4]={0.2, 0.2, 0.2, 0.0};
	static GLfloat mat_emi[4]={0.0, 0.0, 0.0, 0.0};
	static GLfloat mat_shi[1]={30.0};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glTranslatef(0.0, 0.0, -15.0);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_dif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spc);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shi);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emi);
	
	glutSolidSphere(2.0, 24, 24);

	glPopMatrix();	
	
	glFlush();
}

void reshape_func(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glFrustum(-1.0, 1.0, -1.0, 1.0, 3.0, 10000.0);

	glMatrixMode(GL_MODELVIEW);

	init_light();
}



int main(int argc, char *argv[])
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(300,300);

	glutCreateWindow("Sample 7");

	glutDisplayFunc(display_func);

	glutReshapeFunc(reshape_func);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 0;
}