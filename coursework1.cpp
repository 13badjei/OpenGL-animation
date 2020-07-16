// #include loads up library files, the order can matter
// generally load glut.h last
#include <stdio.h>  // this library is for standard input and output
#include "glut.h"// this library is for glut the OpenGL Utility Toolkit
#include <math.h>
// this is an example of creating a global variable called counter
int counter = 0;
float tx = 0;
float ty = 0;
float txInc = 1.0;

//this function draws the stickperson's head
void drawHead(double radius, double xc, double yc) {
	int i;
	double angle = 2 * 3.1415 / 20; // circle is drawn using 20 line.
	double x, y;
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	for (i = 0; i < 20; i++) {
		x = radius * cos(i * angle) + xc;
		y = radius * sin(i * angle) + yc;
		glVertex2f(x, y);
	}
	glEnd();
}

//this function draws the stickperson's left eye
void drawLeftEye(double radius, double xc, double yc) {
	int i;
	double angle = 2 * 3.1415 / 20; // circle is drawn using 20 line.
	double x, y;
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	for (i = 0; i < 20; i++) {
		x = radius * cos(i * angle) + xc;
		y = radius * sin(i * angle) + yc;
		glVertex2f(x, y);
	}
	glEnd();
}

//this function draws the stickperson's right eye
void drawRightEye(double radius, double xc, double yc) {
	int i;
	double angle = 2 * 3.1415 / 20; // circle is drawn using 20 line.
	double x, y;
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	for (i = 0; i < 20; i++) {
		x = radius * cos(i * angle) + xc;
		y = radius * sin(i * angle) + yc;
		glVertex2f(x, y);
	}
	glEnd();
}
int P1[] = { 97.0,144.0 }; int P2[] = { 102.0, 144.0 }; int P3[] = { 104.0, 146.0 };
//this function draws the stickperson's mouth for scenes 1 and 2
void drawMouth() {
	glBegin(GL_LINE_STRIP); // get ready to draw lines
	glColor3f(1.0, 1.0, 1.0);
	glVertex2iv(P1); // start point of the line
	glVertex2iv(P2);
	glVertex2iv(P3); // end point of the line
	glEnd();// end of line drawing
}
int P12[] = { 97.0,140.0 }; int P22[] = { 102.0, 144.0 }; int P32[] = { 104.0, 140.0 };
//this function draws the stickperson's mouth for scene 3
void drawMouth2() {
	glBegin(GL_LINE_STRIP); // get ready to draw lines
	glColor3f(1.0, 1.0, 1.0);
	glVertex2iv(P12); // start point of the line
	glVertex2iv(P22);
	glVertex2iv(P32); // end point of the line
	glEnd();// end of line drawing
}

int P13[] = { 397.0,140.0 }; int P23[] = { 402.0, 144.0 }; int P33[] = { 404.0, 140.0 };
//this function draws the stickperson's mouth for scene 4
void drawMouth3() {
	glBegin(GL_LINE_STRIP); // get ready to draw lines
	glColor3f(1.0, 1.0, 1.0);
	glVertex2iv(P13); // start point of the line
	glVertex2iv(P23);
	glVertex2iv(P33); // end point of the line
	glEnd();// end of line drawing
}

//this function draws the stickperson's mouth for scene 6
void drawMouth4() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(95.0, 149.0); // start point of the line
	glVertex2d(110.0, 140.0); // end point of the line
	glEnd();// end of line drawing
}

//this function draws the stickperson's left arm for scene 1
void drawLeftArm() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(100.0, 104.0); // start point of the line
	glVertex2d(150.0, 136.0); // end point of the line
	glEnd();// end of line drawing
}
//this function draws the stickperson's right arm for scene 1
void drawRightArm() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(100.0, 104.0); // start point of the line
	glVertex2d(150.0, 136.0); // end point of the line
	glEnd();// end of line drawing
}

//this function draws the stickperson's arms for scene 2
void drawArms2() {
	glBegin(GL_LINES); // get ready to draw lines
	glColor3f(1.0, 1.0, 1.0);
	glVertex2d(100.0, 104.0); // start point of the line
	glVertex2d(74.0, 104.0); // end point of the line
	glVertex2d(100.0, 104.0); // start point of the line
	glVertex2d(130.0, 104.0); // end point of the line
	glEnd();// end of line drawing
}

//this function draws the stickperson's arms for scene 3
void drawArms3() {
	glBegin(GL_LINES); // get ready to draw lines
	glColor3f(1.0, 1.0, 1.0);
	glVertex2d(100.0, 104.0); // start point of the line
	glVertex2d(150.0, 136.0); // end point of the line
	glVertex2d(100.0, 104.0); // start point of the line
	glVertex2d(150.0, 110.0); // end point of the line
	glEnd();// end of line drawing
}

float leftArmAngle = 0; float lInc = 5.0;
void leftArmTransformations() {
	//fixed point rotation
	glTranslatef(100, 104, 0.0);
	glRotatef(leftArmAngle, 0.0, 0.0, 1.0);
	glTranslatef(-100, -104, 0.0);
	leftArmAngle = leftArmAngle + lInc;
	if (leftArmAngle > 50) {
		lInc = -lInc;
	}
	else if (leftArmAngle < -50) {
		lInc = -lInc;
	}
}

float rightArmAngle = 100; float rInc = -5.0;
void rightArmTransformations() {
	//fixed point rotation
	glTranslatef(100, 104, 0.0);
	glRotatef(rightArmAngle, 0.0, 0.0, 1.0);
	glTranslatef(-100, -104, 0.0);
	rightArmAngle = rightArmAngle + rInc;
	if (rightArmAngle > 100) {
		rInc = -rInc;
	}
	else if (rightArmAngle < 0) {
		rInc = -rInc;
	}
}

//this function draws and moves the stickperson's arms
void drawArms() {
	glPushMatrix();
	glColor3f(1, 0, 0);
	leftArmTransformations();
	drawLeftArm();
	glColor3f(1, 1, 1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 1, 0);
	rightArmTransformations();
	drawRightArm();
	glColor3f(1, 1, 1);
	glPopMatrix();
}

// this function draws the stickperson's body
void drawBody() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(100.0, 136.0); // start point of the line
	glVertex2d(100.0, 50.0); // end point of the line
	glEnd();// end of line drawing
}

// this function draws the stickperson's legs
void drawLegs() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(100.0, 50.0); // start point of the line
	glVertex2d(90.0, 40.0); // end point of the line
	glVertex2d(100.0, 50.0); // start point of the line
	glVertex2d(110.0, 40.0); // end point of the line
	glEnd();// end of line drawing
}

// this function draws the table
void drawTable() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(184.0, 130.0); // start point of the line
	glVertex2d(144.0, 128.0); // end point of the line
	glVertex2d(144.0, 128.0); // start point of the line
	glVertex2d(154.0, 70.0); // end point of the line
	glVertex2d(154.0, 70.0); // start point of the line
	glVertex2d(154.0, 24.0); // end point of the line
	glEnd();// end of line drawing
}

// this function draws the sheet with triforce on it
void drawSheet() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(200.0, 72.0); // start point of the line
	glVertex2d(160.0, 72.0); // end point of the line
	glVertex2d(160.0, 72.0); // start point of the line
	glVertex2d(160.0, 24.0); // end point of the line
	glVertex2d(160.0, 24.0); // start point of the line
	glVertex2d(200.0, 24.0); // end point of the line
	glVertex2d(200.0, 24.0); // start point of the line
	glVertex2d(200.0, 72.0); // end point of the line
	glEnd();// end of line drawing
}
int P14[] = { 168.0,34.0 }; int P24[] = { 188.0, 34.0 }; int P34[] = { 180.0, 68.0 };

// this function draws the triangle on the sheet
void drawTriangle() {
	glBegin(GL_POLYGON); // get ready to draw a polygon
	glVertex2iv(P14); 
	glVertex2iv(P24); 
	glVertex2iv(P34); 
	glEnd();// end of line drawing
}

// this function draws the keyboard
void drawKeyboard() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(160.0, 116.0); // start point of the line
	glVertex2d(150.0, 110.0); // end point of the line
	glVertex2d(150.0, 110.0); // start point of the line
	glVertex2d(160.0, 82.0); // end point of the line
	glVertex2d(160.0, 82.0); // start point of the line
	glVertex2d(170.0, 82.0); // end point of the line
	glVertex2d(170.0, 82.0); // start point of the line
	glVertex2d(160.0, 116.0); // end point of the line
	glEnd();// end of line drawing
}

// this function draws the computer screen for scene 1
void drawScreen() {
	glBegin(GL_POLYGON);
	glVertex2i(170, 166);
	glVertex2i(220, 166);
	glVertex2i(200, 90);
	glVertex2i(170, 110);
	glEnd();
}

// this function draws the computer screen for scene 2
void drawScreen2() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(170, 166);
	glVertex2i(220, 166);
	glVertex2i(220, 116);
	glVertex2i(170, 116);
	glEnd();
}

// the 2 functions below draw the exclamation mark on the computer screen
void drawExclamationMarkRectangle() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(185, 164);
	glVertex2i(192, 164);
	glVertex2i(192, 144);
	glVertex2i(185, 144);
	glEnd();
}

void drawExclamationPoint(double radius, double xc, double yc) {
	glColor3f(1.0, 0.0, 0.0);
	int i;
	double angle = 2 * 3.1415 / 20; // circle is drawn using 20 line.
	double x, y;
	glBegin(GL_LINE_LOOP);
	glBegin(GL_POLYGON);
	for (i = 0; i < 20; i++) {
		x = radius * cos(i * angle) + xc;
		y = radius * sin(i * angle) + yc;
		glVertex2f(x, y);
	}
	glEnd();
}

// this function draws the computer screen for scene 6
void drawScreen3() {
	glBegin(GL_POLYGON);
	glVertex2i(140, 104);
	glVertex2i(190, 104);
	glVertex2i(190, 54);
	glVertex2i(140, 54);
	glEnd();
}

int P15[] = { 397.0,140.0 }; int P25[] = { 402.0, 144.0 }; int P35[] = { 404.0, 140.0 };
//this function draws the stickperson's mouth for scene 4
void drawMouth5() {
	glBegin(GL_LINE_STRIP); // get ready to draw lines
	glVertex2iv(P15); // start point of the line
	glVertex2iv(P25);
	glVertex2iv(P35); // end point of the line
	glEnd();// end of line drawing
}

//this function draws the stickperson's head for scene 4
void drawHead()
{
	drawHead(10.0, 400, 146);
	drawLeftEye(1.0, 396, 151);
	drawRightEye(1.0, 403, 151);
	drawMouth5();
}

//this function draws the car's roof
void drawCarRoof() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2i(120, 135); // start point of the line
	glVertex2i(120, 170); //end point of the line
	glVertex2i(120, 170); // start point of the line
	glVertex2i(80, 170); //end point of the line
	glVertex2i(80, 170); // start point of the line
	glVertex2i(80, 135); //end point of the line
	glEnd();// end of line drawing
}

//this function draws the car's body
void drawCarBody() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2i(120, 135); // start point of the line
	glVertex2i(120, 108); // end point of the line
	glVertex2i(120, 108); // start point of the line
	glVertex2i(120, 135); // end point of the line
	glVertex2i(120, 135); // start point of the line
	glVertex2i(150, 135); //end point of the line
	glVertex2i(150, 135); // start point of the line
	glVertex2i(150, 108); //end point of the line
	glVertex2i(150, 108); // start point of the line
	glVertex2i(30, 108); //end point of the line
	glVertex2i(30, 108); // start point of the line
	glVertex2i(50, 135); //end point of the line
	glVertex2i(50, 135); // start point of the line
	glVertex2i(91, 135); //end point of the line
	glEnd();// end of line drawing
}

//this function draws the car's left wheel
void drawCarLeftWheel(double radius, double xc, double yc) {
	int i;
	double angle = 2 * 3.1415 / 20; // circle is drawn using 20 line.
	double x, y;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 20; i++) {
		x = radius * cos(i * angle) + xc;
		y = radius * sin(i * angle) + yc;
		glVertex2f(x, y);
	}
	glEnd();
}

//this function draws the car's right wheel
void drawCarRightWheel(double radius, double xc, double yc) {
	int i;
	double angle = 2 * 3.1415 / 20; // circle is drawn using 20 line.
	double x, y;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 20; i++) {
		x = radius * cos(i * angle) + xc;
		y = radius * sin(i * angle) + yc;
		glVertex2f(x, y);
	}
	glEnd();
}

float txInc2 = 0.01;

//this function moves the car
void carTransformations() {
	glTranslatef(300.0, 0.0, 0.0);
	tx -= txInc2;
	ty = txInc2;
}

//this function draws the car in the new position
void car() {
	glPushMatrix();
	carTransformations();
	drawCarRoof();
	drawCarBody();
	drawCarLeftWheel(10.0, 52, 99);
	drawCarRightWheel(10.0, 105, 99);
	glPopMatrix();
}

void square() // draw 1 of the squares for the windows logo
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(160, 170);
	glVertex2i(160, 177);
	glVertex2i(170, 177);
	glVertex2i(170, 170);
	glEnd();
}

void square2() // draw 1 of the squares for the windows logo
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(180, 170);
	glVertex2i(180, 177);
	glVertex2i(190, 177);
	glVertex2i(190, 170);
	glEnd();
}

void square3() // draw 1 of the squares for the windows logo
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(160, 160);
	glVertex2i(160, 167);
	glVertex2i(170, 167);
	glVertex2i(170, 160);
	glEnd();
}

void square4() // draw 1 of the squares for the windows logo
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(180, 160);
	glVertex2i(180, 167);
	glVertex2i(190, 167);
	glVertex2i(190, 160);
	glEnd();
}
// this function draws the PC shop
void drawShop() {
	glBegin(GL_LINES); // get ready to draw lines
	glColor3f(1.0, 1.0, 1.0);
	glVertex2d(135.0, 40.0); // start point of the line
	glVertex2d(135.0, 160.0); // start point of the line
	glVertex2d(135.0, 160.0); // end point of the line
	glVertex2d(218.0, 160.0); // start point of the line
	glVertex2d(218.0, 160.0); // start point of the line
	glVertex2d(135.0, 160.0); // end point of the line
	glVertex2d(135.0, 160.0); // end point of the line
	glVertex2d(135.0, 180.0); // end point of the line
	glVertex2d(135.0, 180.0); // start point of the line
	glVertex2d(218.0, 180.0); // end point of the line
	glVertex2d(218.0, 180.0); // start point of the line
	glVertex2d(218.0, 40.0); // end point of the line
	glEnd();// end of line drawing
}

// this function draws the PC shop door
void drawShopDoor() {
	glBegin(GL_LINES); // get ready to draw lines
	glVertex2d(160.0, 40.0); // start point of the line
	glVertex2d(160.0, 104.0); // end point of the line
	glVertex2d(160.0, 104.0); // start point of the line
	glVertex2d(186.0, 104.0); // end point of the line
	glVertex2d(186.0, 104.0); // start point of the line
	glVertex2d(186.0, 40.0); // end point of the line
	glEnd();// end of line drawing
}

// this is the initialisation function, called once only
void init() {
	glClearColor(0.0, 1.0, 0.0, 0.0); // set what colour you want the background to be
	glMatrixMode(GL_PROJECTION); // set the matrix mode, we will look at this later
	// set the projection window size in x an y. Window will then
	// be mapped to the window created in the main function
	gluOrtho2D(0.0, 400, 0.0, 300.0);
}
// This is the display function it is called when ever you want to draw something
// all drawing should be called from here
float frame = 0.0;
void display() {
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen using the background colour
	frame++;
	if ((frame >= 0) && (frame < 50)) // scene 1
	{
		glClearColor(0.0, 0.0, 0.0, 0.0); // set what colour you want the background to be
		drawHead(10.0, 101, 146);
		drawLeftEye(1.0, 97, 151);
		drawRightEye(1.0, 104, 151);
		drawMouth();
		drawBody();
		drawLegs();
		drawTable();
		drawKeyboard();
		drawSheet();
		drawTriangle();
		drawScreen();
		drawArms();
		printf("scene 1 %f\n", frame);
	}

	else if ((frame >= 50) && (frame < 100)) // scene 2
	{
		glClearColor(0.0, 0.0, 0.0, 0.0); // set what colour you want the background to be
		drawHead(10.0, 101, 146);
		drawLeftEye(1.0, 97, 151);
		drawRightEye(1.0, 104, 151);
		drawMouth();
		drawArms2();
		drawBody();
		drawLegs();
		drawScreen2();
		drawExclamationMarkRectangle();
		drawExclamationPoint(5.0, 190, 135);
		printf("scene 2 %f\n", frame);
	}

	else if ((frame >= 100) && (frame < 300)) // scene 3
	{
		glClearColor(0.0, 0.0, 0.0, 0.0); // set what colour you want the background to be
		drawHead(10.0, 101, 146);
		drawLeftEye(1.0, 97, 151);
		drawRightEye(1.0, 104, 151);
		drawMouth2();
		drawArms3();
		drawBody();
		printf("scene 3 %f\n", frame);
	}

	else if ((frame >= 300) && (frame < 700)) // scene 4
	{
		glPushMatrix();
		glTranslatef(tx, ty, 0.0);
		drawHead();
		car();
		glPopMatrix();
		tx = tx - txInc;
		printf("scene 4 %f\n", frame);
	}

	else if ((frame >= 700) && (frame < 750)) // scene 5
	{
		glClearColor(0.0, 0.0, 0.0, 0.0); // set what colour you want the background to be
		drawHead(10.0, 101, 146);
		drawLeftEye(1.0, 97, 151);
		drawRightEye(1.0, 104, 151);
		drawMouth();
		drawArms2();
		drawBody();
		drawLegs();
		square();
		square2();
		square3();
		square4();
		drawShop();
		drawShopDoor();
		printf("scene 5 %f\n", frame);
	}

	else if ((frame >= 750) && (frame < 950)) // scene 6
	{
		drawHead(10.0, 101, 146);
		drawLeftEye(1.0, 97, 151);
		drawRightEye(1.0, 104, 151);
		drawMouth4();
		drawArms2();
		drawBody();
		drawLegs();
		drawScreen2(); 
		printf("scene 6 %f\n", frame);
	}
	else if (frame > 950) {
		frame = 0;
	}
	glutSwapBuffers();
	glFlush(); // force all drawing to finish
}

void Timer(int value)
{
	if (value) glutPostRedisplay();
	glutTimerFunc(20, Timer, value);
}

void visibility(int state)
{
	switch (state)
	{
	case GLUT_VISIBLE:
		Timer(1);
		break;
	case GLUT_NOT_VISIBLE:
		Timer(0);
		break;
	default:
		break;
	}
}

// As with many programming languages the main() function
// is the entry point for execution of the program
int main(int argc, char** argv) {
	glutInit(&argc, argv);  //perform the GLUT initialization
	glutInitDisplayMode(GLUT_DOUBLE); // more initialisation
	glutInitWindowSize(400, 300); // set window position
	glutInitWindowPosition(100, 100); // set window size
	glutCreateWindow("Hello"); // create a display with a given caption for the title bar
	init(); // call init function defined above
	//glutIdleFunc(idle); //  define what function to call when the program is idle
	glutDisplayFunc(display); // define what function to call to draw 
	// the last function in the program puts the program into infinite loop
	// effectively the loop repeatedly calls the idle function 
	glutVisibilityFunc(visibility);
	glutMainLoop();

	// this line exits the program
	return 0;
}