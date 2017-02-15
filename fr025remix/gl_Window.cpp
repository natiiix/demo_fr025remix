#include "gl_Window.hpp"

namespace gl
{
	const char * Window::WINDOW_DEFAULT_TITLE = "OpenGL Window";

	void Window::Setup(const char * const title, const bool fullscreen, const int width, const int height)
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

	bool Window::LoadMusic(const std::string & musicPath)
	{
		bool loadSuccessful = m_buffer.loadFromFile(musicPath);
		if (loadSuccessful)
			m_sound.setBuffer(m_buffer);
		return loadSuccessful;

		//return m_music.openFromFile(musicPath);
	}

	void Window::Run(void)
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		// Set the window size
		glutInitWindowSize(m_width, m_height);

		// Create the window
		glutCreateWindow(m_title);
		if (m_fullscreen)
			glutFullScreen();
		// Initialize rendering
		gl::initRendering();

		// Set handler functions for drawing, keypresses, and window resizes
		glutDisplayFunc(gl::drawScene);
		glutKeyboardFunc(gl::handleKeypress);
		glutReshapeFunc(gl::handleResize);

		/*if (m_music.getDuration().asSeconds() > 0)
			m_music.play();*/

		m_sound.play();

		// Start the main loop. glutMainLoop doesn't return.
		glutMainLoop();
	}

	Window & Window::getInstance(void)
	{
		static Window winInstance;
		return winInstance;
	}

#define RESOLUTIONS_COUNT 3
	const void Window::askForResolution(bool & fullscreen, int & width, int & height)
	{
		const int resolutions[RESOLUTIONS_COUNT][2] =
		{
			{ 640, 480 },
			{ 800, 600 },
			{ 1280, 720 }
		};

		std::cout << "Select resolution!" << std::endl;
		std::cout << "0. Fullscreen" << std::endl;
		for (int i = 0; i < RESOLUTIONS_COUNT; i++)
		{
			std::cout << (i + 1) << ". Windowed " << resolutions[i][0] << " x " << resolutions[i][1] << std::endl;
		}

		std::cout << std::endl << "Resolution choice (default = 0): ";

		// Create string and int to store the choice
		std::string strResChoice = "";
		int iResChoice = 0;
		// Get the choice as a string and convert it to int if anything was entered
		std::getline(std::cin, strResChoice);
		if (strResChoice.length() > 0)
			iResChoice = std::stoi(strResChoice);

		if (iResChoice > 0 && iResChoice <= RESOLUTIONS_COUNT)
		{
			fullscreen = false;
			width = resolutions[iResChoice - 1][0];
			height = resolutions[iResChoice - 1][1];
		}
		else
		{
			fullscreen = true;
		}
	}
}
