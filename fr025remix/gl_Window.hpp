#pragma once

#include "ChronoClock.hpp"

#include <SFML\Audio.hpp>

namespace gl
{
	class Window
	{
		// public methods
	public:
		void Setup(const char * const title = nullptr, const bool fullscreen = WINDOW_DEFAULT_FULLSCREEN, const int width = NULL, const int height = NULL);
		bool LoadMusic(const std::string & musicPath);
		void Run(void);
		// Returns the clock associated with this instance
		ChronoClock & getClock() { return m_clock; }
		// Creates an instance of the OpenGL Window and returns a reference to it
		static Window & getInstance(void);
		// Function used to get the resolution choice from the user
		static const void askForResolution(bool & fullscreen, int & width, int & height);

		// constants
	private:
		static const bool WINDOW_DEFAULT_FULLSCREEN = false;
		static const int WINDOW_DEFAULT_WIDTH = 800;
		static const int WINDOW_DEFAULT_HEIGHT = 600;
		static const char * WINDOW_DEFAULT_TITLE;

		// member variables
	private:
		bool m_fullscreen;
		int m_width;
		int m_height;
		char m_title[256];

		sf::Music m_music;
		ChronoClock m_clock;
	};
}
