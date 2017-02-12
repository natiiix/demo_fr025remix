#include "OpenGLWindow.hpp"

OpenGLWindow * win;

int main(void)
{
	const char * winTitle = "test window title";
	const bool winFullscreen = true;
	const int winWidth = 640;
	const int winHeight = 480;
	const char * musicPath = "song.wav";

	win = new OpenGLWindow(winTitle, winFullscreen, winWidth, winHeight);
	if (win->LoadMusic(musicPath))
	{
		win->Run();
	}

	// This return is supposed to be unreachable.
	// Running instance of OpenGLWindow runs in a infinite loop.
	// When ESCAPE is pressed exit(0) is called and the program exits successfully.
	// Reaching this return statement indicates a problem with the OpenGLWindow loop.
	return -1;
}

