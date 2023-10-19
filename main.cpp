#include <iostream>
#include <windows.h>
#include <GL\glut.h>
#include <GL\freeglut_ext.h>
using namespace std;
void defaultDisplay();
void keyboardMonitor(unsigned char key, int x, int y);
void mouseMonitor(int button, int state, int x, int y);
void detectMotion(int x, int y);
void detectPassiveMotion(int x, int y);
void mouseEntryDetector(int state);
void animateText();
void animateString(int value);
float px, py;

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(200,50);
	glutCreateWindow("My First OpenGL");
	//glutFullScreen();
	glutDisplayFunc(defaultDisplay);
	glutKeyboardFunc(keyboardMonitor);
	glutMouseFunc(mouseMonitor);
	glutMotionFunc(detectMotion);
	glutPassiveMotionFunc(detectPassiveMotion);
	glutEntryFunc(mouseEntryDetector);
	//glutIdleFunc(animateText);
	glutMainLoop();
	return 0;
}

void mouseEntryDetector(int state){
	if(state == GLUT_LEFT){
	cout << "Mouse has left the application " <<endl;
	}else{
	cout << "Mouse has re-entered the application " << endl;
	}
}

void animateString(int value){
	if(value==1){
		px += 0.02;
	}else{
		px -= 0.02;
	}
	glutPostRedisplay();
}

void animateText(){
	Sleep(1000);
	px += .02f;
	glutPostRedisplay();
}

void detectMotion(int x, int y){
	cout << x << " " << y << endl;
}

void detectPassiveMotion(int x, int y){
	cout << x << "P " << y << endl;
}

void mouseMonitor(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON){
		if( state == GLUT_DOWN)
				cout << "Left button was clicked..." << endl;
		else
			cout << "Left button was released..." << endl;
		}else if(button == GLUT_RIGHT_BUTTON){
			cout << "Right button was clicked..." << endl;
	}else{
		cout << "Middle button was clicked..." << endl;
	}
	cout << x << " " << y << endl;
	//cout << button << endl;
}
void keyboardMonitor(unsigned char key, int x, int y){
	cout << key << endl;
	switch(key){
		case 'a':
			px -= .02f;
			break;
		case 'd':
			px += .02f;
			break;
		case 27:
			exit(0);
			break;
		default:
			px=0.0f;
	}
	glutPostRedisplay();
}

void defaultDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	const unsigned char str[100] = "FEU-TECH";
	glColor3f(0.0f,0.0f,1.0f); 
	glRasterPos2f(px,py);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, str);
	glFlush();
	glutTimerFunc(1500,animateString,2);
	
	
}
