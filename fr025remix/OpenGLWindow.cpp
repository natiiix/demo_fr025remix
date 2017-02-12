#include "OpenGLWindow.hpp"
#include "gl_base.hpp"

#include <GL\glut.h>

const char * OpenGLWindow::WINDOW_DEFAULT_TITLE = "OpenGL Window";

OpenGLWindow::OpenGLWindow(const char * const title, const bool fullscreen, const int width, const int height)
{
	// Initialize GLUT
	int argc = 0;
	glutInit(&argc, NULL);

	// title
	if (title == nullptr)
		strcpy_s(m_title, WINDOW_DEFAULT_TITLE);
	else
		strcpy_s(m_title, title);

	// fullscreen
	m_fullscreen = fullscreen;

	// width
	if (width != NULL)
		m_width = width;
	else
		m_width = (m_fullscreen ? glutGet(GLUT_SCREEN_WIDTH) : WINDOW_DEFAULT_WIDTH);

	// height
	if (height != NULL)
		m_height = height;
	else
		m_height = (m_fullscreen ? glutGet(GLUT_SCREEN_HEIGHT) : WINDOW_DEFAULT_HEIGHT);
}

bool OpenGLWindow::LoadMusic(const std::string & musicPath)
{
	return m_music.openFromFile(musicPath);
}

void OpenGLWindow::Run()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(m_width, m_height);

	// Create the window
	glutCreateWindow(m_title);
	if (m_fullscreen)
		glutFullScreen();
	// Initialize rendering
	initRendering();

	// Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	if (m_music.getDuration().asSeconds() > 0)
		m_music.play();

	// Start the main loop. glutMainLoop doesn't return.
	glutMainLoop();
}
