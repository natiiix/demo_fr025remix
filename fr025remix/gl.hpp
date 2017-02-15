#pragma once

#include "gl_Window.hpp"
#include "render.hpp"

#include <GL\glut.h>
#include <iostream>

namespace gl
{
	void handleKeypress(unsigned char key, int x, int y);
	void initRendering();
	void handleResize(int w, int h);
	void drawScene();
}
