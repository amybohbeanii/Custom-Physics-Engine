/*This program generates one ball bouncing according to gravity. 
	To run put this in terminal: g++ -o bounces bounces.cpp ball.cpp -lglut -lGLU -lGL -lm && ./bounces */

#include <cmath>
#include "ball.h"
#include <GL/glut.h>

double windowWidth = 1000;
double windowHeight = 500;

double velocity = 3.0;
double gravity = -0.00001;
double friction = 0.9999;
double x;
double y;

Ball newBall;

/*This function will draw the ball on the screen*/
void DrawBall(double x1, double y1, double radius)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<32; i++)
	{
		double theta = (double)i/32.0 * 2.0 * 3.1415926;
		double x = x1 + radius * cos(theta);
		double y = y1 + radius * sin(theta);
		glColor3f(0.9, 0.3, 0.2); 
		glVertex2d(x, y);
	}
	glEnd();
}

/*This function will display the ball on the screen*/
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	double xVelocity = newBall.getXVelocity();
	double yVelocity = newBall.getYVelocity();
	yVelocity += gravity;
	yVelocity *= friction;
	xVelocity *= friction;

	// Handle ball-wall collisions
	double radius = newBall.getRadius();
	double x = newBall.getX();
	double y = newBall.getY();

	// Handle collisions with right wall
	if (x + radius >= windowWidth)
		xVelocity = -fabs(xVelocity);

	// Handle collisions with left wall
	if (x - radius <= 0)
		xVelocity = fabs(xVelocity);

	// Handle collisions with ceiling
	if (y + radius >= windowHeight)
		yVelocity = -fabs(yVelocity);

	// Handle collisions with floor
	if (y - radius <= 0)
		yVelocity = fabs(yVelocity);

	// Store ball's velocity
	newBall.setXVelocity(xVelocity);
	newBall.setYVelocity(yVelocity);

	// Have velocities update positions
	x = newBall.getNextX();
	newBall.setX(x);
	y = newBall.getNextY();
	newBall.setY(y);
	
	DrawBall(x, y, radius);
	glutSwapBuffers();
	glutPostRedisplay();
}

/*This function will resize the window*/
void resize(int w, int h)
{
	const float ar = (float) w / (float) h; 	
	windowWidth = w;
	windowHeight = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*This function will create a new ball*/
void CreateBall()
{
	double radius = 25.0;
	double xVelocity = velocity;
	double yVelocity = velocity;
	double x = 50.0;
	double y = 50.0;
	newBall = Ball(x,y,radius,xVelocity,yVelocity);	
}

/* Program Entry */ 
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(10, 10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	glutCreateWindow("One Bouncing Ball with Gravity");
	CreateBall();	
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMainLoop();
	return EXIT_SUCCESS;
}
