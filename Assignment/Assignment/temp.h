#pragma once
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<iostream>


static float fingerBase = 0.0, fingerUp = 0.0, rhip = 0.0, rhip2 = 0.0, rknee = 0.0, lknee = 0.0, lhip = 0.0, lhip2 = 0.0, lmove = 0.0, Dmove = 0.0, umove = 0.0, Umove = 0.0, dmove = 0.0, rmove = 0.0;
static int shoulder = 0, elbow = 0, shoulderAngle = 0, shoulder2 = 0, elbow2 = 0, shoulderAngle2 = 0;
static int r_thigh = 0, R_thigh = 0, l_thigh = 0, L_thigh = 0, r_knee = 0, l_knee = 0;
static int fullbody = 0;
int moving, startx, starty;
float light_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
float light_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
float light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
float light_position[] = { 0.0, 0.0, 4.0, 1.0 };




GLfloat angle = 180.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */

double eye[] = { 0, 0, -20 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 0, -1 };
double perpendicular[] = { 0,0,-21 };
double c[] = { 0,0,-1 };
double direction[] = { 0,0,0 };
float speed = 0.1;

void DB(void)
{

	glPushMatrix();
	glRotatef((GLfloat)shoulderAngle, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0.5, 0.2, 0.3);
	glScalef(3.0, 1.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0.1, 0.2, 0.9);
	glScalef(3.0, 1.0, 0.5);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
}
void drawRobot(void)
{
	glPushMatrix();

	glTranslatef(3.0, 0.0, 1.0);
	glRotatef(GLfloat(fullbody), 0, 1, 0);
	glTranslatef(-3.0, 0.0, -1.0);

	glPushMatrix();

	glTranslatef(0.0, 2.5, 0.0);
	glutSolidSphere(0.7, 10.0, 10.0);



	glPopMatrix();
	glPushMatrix();

	glTranslatef(-0.5, -2.0, 1.0);
	glRotatef(GLfloat(L_thigh), 0, 0, 1);
	glTranslatef(0.5, 2.0, -1.0);
	glTranslatef(0.0, -2.0, 0.0);
	glRotatef(GLfloat(l_thigh), 1, 0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glPushMatrix();
	glScalef(0.5, 1.8, 1.0);
	glTranslatef(-1.5, -1.8, 0.0);
	glutWireCube(1);//left thigh
	glPopMatrix();
	glTranslatef(0.0, -4.2, 0.0);
	glRotatef(GLfloat(l_knee), 1, 0, 0);
	glTranslatef(0.0, 4.2, 0.0);
	glPushMatrix();

	glScalef(0.5, 2.0, 1.0);
	glTranslatef(-1.5, -2.5, 0.0);
	glutWireCube(1);//left lower leg
	glPopMatrix();
	glTranslatef(0.0, -6.0, 0.5);
	glScalef(0.5, 0.3, 1.0);
	glTranslatef(-1.5, 0.0, 0.0);
	glutSolidCube(1);//left feet

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0.5, -2.0, 1.0);
	glRotatef(GLfloat(R_thigh), 0, 0, 1);
	glTranslatef(-0.5, 2.0, -1.0);
	glTranslatef(0.0, -2.0, 0.0);
	glRotatef(GLfloat(r_thigh), 1, 0, 0);
	glTranslatef(0.0, 2.0, 0.0);
	glPushMatrix();
	glScalef(0.5, 1.8, 1.0);
	glTranslatef(1.5, -1.8, 0.0);
	glutWireCube(1);//right thigh
	glPopMatrix();
	glTranslatef(0.0, -4.2, 0.0);
	glRotatef(GLfloat(r_knee), 1, 0, 0);
	glTranslatef(0.0, 4.2, 0.0);
	glPushMatrix();

	glScalef(0.5, 2.0, 1.0);
	glTranslatef(1.5, -2.5, 0.0);
	glutWireCube(1);//right lower leg
	glPopMatrix();
	glTranslatef(0.0, -6.0, 0.5);
	glScalef(0.5, 0.3, 1.0);
	glTranslatef(1.5, 0.0, 0.0);
	glutSolidCube(1);//right feet

	glPopMatrix();

	glPushMatrix();
	glScalef(3.0, 4.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.8, 1.5, -0.1);
	glRotatef(-90, 0, 0, 1);
	//drawArm();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.8, 1.5, -0.1);
	glRotatef(90, 0, 0, 1);
	glRotatef(180, 0, 1, 0);
	//drawArm();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}


void init(void)
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(65.0, (GLfloat)1024 / (GLfloat)869, 1.0, 60.0);

}

void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}



void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta)*p[0];
	temp[1] += cos(theta)*p[1];
	temp[2] += cos(theta)*p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];

}

void Left()
{
	rotatePoint(up, GLfloat(lmove), eye);
	lmove += 0.001;


	// implement camera rotation arround vertical window screen axis to the left
	// used by mouse and left arrow
}

void Right()
{
	rotatePoint(up, GLfloat(rmove), eye);
	rmove -= 0.001;
	// implement camera rotation arround vertical window screen axis to the right
	// used by mouse and right arrow
}

void Up()
{
	for (int i = 0; i < 3; i++)
	{
		perpendicular[i] = eye[i] - center[i];

	}

	crossProduct(up, perpendicular, c);
	normalize(c);

	rotatePoint(c, GLfloat(Umove), eye);
	rotatePoint(c, GLfloat(umove), up);
	Umove -= 0.001;
	umove -= 0.001;

	// implement camera rotation arround horizontal window screen axis +ve
	// used by up arrow
}

void Down()
{
	for (int i = 0; i < 3; i++)
	{
		perpendicular[i] = eye[i] - center[i];

	}
	crossProduct(up, perpendicular, c);
	normalize(c);
	rotatePoint(c, GLfloat(dmove), eye);
	rotatePoint(c, GLfloat(dmove), up);
	dmove += 0.001;

	//Dmove += 0.001;

	// implement camera rotation arround horizontal window screen axis 
	// used by down arrow
}

void moveForward()
{
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
	eye[0] += direction[0] * speed;
	eye[1] += direction[1] * speed;
	eye[2] += direction[2] * speed;

	center[0] += direction[0] * speed;
	center[1] += direction[1] * speed;
	center[2] += direction[2] * speed;
}

void moveBack()
{
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
	eye[0] -= direction[0] * speed;
	eye[1] -= direction[1] * speed;
	eye[2] -= direction[2] * speed;

	center[0] -= direction[0] * speed;
	center[1] -= direction[1] * speed;
	center[2] -= direction[2] * speed;
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glScalef(1.0, 3.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glutWireCube(1.0);
	glPopMatrix();
	drawRobot();




	// call the robotic body draw function here
	//drawArm();
	glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: Left(); break;
	case GLUT_KEY_RIGHT: Right(); break;
	case GLUT_KEY_UP:    Up(); break;
	case GLUT_KEY_DOWN:  Down(); break;
	}

	glutPostRedisplay();
}


static void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			moving = 1;
			startx = x;
			starty = y;
		}
		if (state == GLUT_UP) {
			moving = 0;
		}
	}
}

static void motion(int x, int y)
{

	angle = angle + (x - startx);
	angle2 = angle2 + (y - starty);
	startx = x;
	starty = y;
	glutPostRedisplay();

}


void keyboard(unsigned char key, int x, int y)
{
	// List all youe keyboard keys from assignment two her for body movement
	switch (key)
	{
	case 'f':
		moveForward();
		glutPostRedisplay();
		break;
	case 'b':
		moveBack();
		glutPostRedisplay();
		break;
	case 's':
		shoulder = (shoulder + 5) % 178;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 178;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 178;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 178;
		glutPostRedisplay();
		break;
	case 'a':
		shoulderAngle = (shoulderAngle + 5) % 90;

		glutPostRedisplay();
		break;
	case 'A':
		if (shoulderAngle > -1)
		{
			shoulderAngle = (shoulderAngle - 5) % 90;


			glutPostRedisplay();
		}
		break;
	case 'q':
		r_thigh = (r_thigh + 5) % 90;

		glutPostRedisplay();
		break;
	case 'Q':


		r_thigh = (r_thigh - 5) % 90;


		glutPostRedisplay();

		break;
	case 'n':
		R_thigh = (R_thigh + 5) % 90;

		glutPostRedisplay();
		break;
	case 'N':


		R_thigh = (R_thigh - 5) % 60;


		glutPostRedisplay();

		break;

	case 'k':
		r_knee = (r_knee + 5) % 90;

		glutPostRedisplay();
		break;
	case 'K':


		r_knee = (r_knee - 5) % 10;


		glutPostRedisplay();

		break;
	case 'c':
		l_thigh = (l_thigh + 5) % 90;

		glutPostRedisplay();
		break;
	case 'C':


		l_thigh = (l_thigh - 5) % 90;


		glutPostRedisplay();

		break;
	case 'j':
		L_thigh = (L_thigh + 5) % 90;

		glutPostRedisplay();
		break;
	case 'J':


		L_thigh = (L_thigh - 5) % 60;


		glutPostRedisplay();

		break;

	case 'm':
		l_knee = (l_knee + 5) % 90;

		glutPostRedisplay();
		break;
	case 'M':


		l_knee = (l_knee - 5) % 10;


		glutPostRedisplay();

		break;
	case 'x':
		fullbody = (fullbody + 3) % 360;

		glutPostRedisplay();
		break;

	case 'X':
		fullbody = (fullbody - 3) % 360;

		glutPostRedisplay();
		break;
	case'r':
		shoulder = 0;
		shoulder2 = 0;
		elbow = 0;
		elbow2 = 0;
		L_thigh = 0;
		l_thigh = 0;
		R_thigh = 0;
		r_thigh = 0;
		l_knee = 0;
		r_knee = 0;
		fullbody = 0;
		break;
	default:
		break;

	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("body");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	//glutReshapeFunc(reshape);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}

