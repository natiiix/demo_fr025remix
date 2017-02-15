#pragma once

#include "gl.hpp"
#include "ChronoClock.hpp"

#include <GL\glut.h>
#include <SFML\Audio.hpp>
#include <iostream>
#include <string>

namespace gl
{
	// Used to draw an OpenGL window on the screen and start the OpenGL program loop
	class Window
	{
	public:
		// Sets up this instance of an OpenGL window
		void Setup(const char * const title = nullptr, const bool fullscreen = WINDOW_DEFAULT_FULLSCREEN, const int width = NULL, const int height = NULL);

		// Loads music from a file
		bool LoadMusic(const std::string & musicPath);

		// Creates the actual window and starts the OpenGL loop
		void Run(void);

		// Returns the clock associated with this instance
		ChronoClock & getClock() { return m_clock; }

		// Creates an instance of the OpenGL Window and returns a reference to it
		static Window & getInstance(void);

		// Function used to get the resolution choice from the user
		static const void askForResolution(bool & fullscreen, int & width, int & height);

	private:
		static const bool WINDOW_DEFAULT_FULLSCREEN = false;
		static const int WINDOW_DEFAULT_WIDTH = 800;
		static const int WINDOW_DEFAULT_HEIGHT = 600;
		static const char * WINDOW_DEFAULT_TITLE;

	private:
		bool m_fullscreen;
		int m_width;
		int m_height;
		char m_title[256];

		//sf::Music m_music;
		sf::SoundBuffer m_buffer;
		sf::Sound m_sound;
		ChronoClock m_clock;
	};
}
