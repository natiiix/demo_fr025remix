#include "gl_Window.hpp"

#include "obj.hpp"
#include <vector>

std::vector<obj::Object> g_objects;
std::vector<obj::Property3f> g_vertices;
std::vector<obj::Property3f> g_textures;
std::vector<obj::Property3f> g_normals;

int main(void)
{
	const char * musicPath = "wayfinder - fr-025 (single edit).wav";
	const char * winTitle = "fr-025 remix";
	bool winFullscreen = false;
	int winWidth = 1280;
	int winHeight = 720;

	// Ask the user for what resolution does he desire and
	// whether he wants to run the OpenGLWindow in fullscreen
#ifndef _DEBUG
	gl::Window::askForResolution(winFullscreen, winWidth, winHeight);
#endif // !_DEBUG

	obj::objParse("test.obj", g_objects, g_vertices, g_textures, g_normals);

	gl::Window &winInstance = gl::Window::getInstance();

	winInstance.Setup(winTitle, winFullscreen, winWidth, winHeight);
	//if (winInstance.LoadMusic(musicPath))
	winInstance.Run();

	// This return is supposed to be unreachable.
	// Running instance of OpenGLWindow runs in a infinite loop.
	// When ESCAPE is pressed exit(0) is called and the program exits successfully.
	// Reaching this return statement indicates a problem with the OpenGLWindow loop.
	return -1;
}
