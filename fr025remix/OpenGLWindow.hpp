#pragma once

#ifndef OPENGLWINDOW_HPP
#define OPENGLWINDOW_HPP

#include "ChronoClock.hpp"

#include <string>
#include <SFML\Audio.hpp>

class OpenGLWindow
{
	// public methods
public:
	OpenGLWindow(const char * const title = nullptr, const bool fullscreen = WINDOW_DEFAULT_FULLSCREEN, const int width = NULL, const int height = NULL);
	bool LoadMusic(const std::string & musicPath);
	void Run();
	double getClockDeltaTime() { return m_clock.getDeltaTime(); }

	// constants
private:
	static const bool WINDOW_DEFAULT_FULLSCREEN = false;
	static const int WINDOW_DEFAULT_WIDTH = 800;
	static const int WINDOW_DEFAULT_HEIGHT = 600;
	static const char * WINDOW_DEFAULT_TITLE;
	// member variables
	bool m_fullscreen;
	int m_width;
	int m_height;
	char m_title[256];

	sf::Music m_music;
	ChronoClock m_clock;
};


extern OpenGLWindow * win;

#endif // !OPENGLWINDOW_HPP
