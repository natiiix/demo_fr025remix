//#include "gl_base.hpp"
#include "OpenGLWindow.hpp"
#include "render.hpp"

#include <GL\glut.h>
#include <iostream>

#define KEY_ESCAPE 27

// Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{
	std::cout << "key:" << key << " x:" << x << " y:" << y << std::endl;

	switch (key)
	{
	case KEY_ESCAPE:
		exit(0); // Exit the program
		break;
	}
}

// Initializes 3D rendering
void initRendering()
{
	// Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);

	// Makes it possible to use colors
	glEnable(GL_COLOR_MATERIAL);

	// Allows usage of lights
	glEnable(GL_LIGHTING);

	// Add first light to the scene
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}

// Called when the window is resized
void handleResize(int w, int h)
{
	// Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); // Switch to setting the camera perspective

								 // Set the camera perspective
	glLoadIdentity(); // Reset the camera
	gluPerspective(45.0,                  // The camera angle
		(double)w / (double)h, // The width-to-height ratio
		1.0,                   // The near z clipping coordinate
		200.0);                // The far z clipping coordinate
}

// Draws the 3D scene
void drawScene()
{
	// Set background color
	glClearColor(0.0f, 0.0f, 0.1f, 1.0f);

	// Set shade model
	glShadeModel(GL_SMOOTH);

	// Add ambient light
	GLfloat ambientColor[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add positioned light
	GLfloat lightColor0[] = { 0.0f, 0.8f, 0.8f, 1.0f };
	GLfloat lightPos0[] = { 4.0f, 0.0f, 8.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	GLfloat lightColor1[] = { 1.0f, 0.5f, 0.5f, 1.0f };
	GLfloat lightPos1[] = { -8.0f, 0.0f, -4.0f, 0.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	// Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); // Switch to the drawing perspective
	glLoadIdentity(); // Reset the drawing perspective

	render(win->getClockDeltaTime());

	glutSwapBuffers(); // Send the 3D scene to the screen
	glutPostRedisplay(); // Render next frame
}
