#include "gl.hpp"

#define KEY_ESCAPE 27

namespace gl
{
	// Called when a key is pressed
	void handleKeypress(unsigned char key, int x, int y)
	{
		std::cout << "key:" << key << " x:" << x << " y:" << y << std::endl;

		switch (key)
		{
		case KEY_ESCAPE:
			// Exit the program
			exit(0);
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

		// Switch to setting the camera perspective
		glMatrixMode(GL_PROJECTION);

		// Set the camera perspective
		glLoadIdentity();			// Reset the camera
		gluPerspective(60.0,		// Camera vertical FOV angle
			(double)w / (double)h,	// Aspect ratio
			1.0,					// Near Z clipping coordinate
			1000.0);				// Far Z clipping coordinate
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

		// Switch to the drawing perspective
		glMatrixMode(GL_MODELVIEW);
		// Reset the drawing perspective
		glLoadIdentity();

		// Render the scene
		render(Window::getInstance().getClock());

		// Send the 3D scene to the screen
		glutSwapBuffers();
		// Render next frame
		glutPostRedisplay();
	}
}
