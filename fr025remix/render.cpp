#include "render.hpp"
#include "gl_Shape.hpp"

#include <vector>

namespace gl
{
	std::vector<Shape *> glObjects;

	void render(ChronoClock & clock)
	{
		float deltaTime = (float)clock.getDeltaTime();
		double totalTime = clock.getTotalTime();

		if (totalTime == 0.0)
		{
			glObjects.push_back(new Cube(0.0f, 0.0f, -5.0f, 2.0f, 2.0f, 2.0f));
			glObjects.back()->SetColor(VERTEX_LEFT_BOTTOM_FRONT, 1.0f, 0.0f, 0.0f);
		}

		glObjects.back()->Draw();
		glObjects.back()->Rotate(deltaTime * 360.0f, 0.0f, 0.0f);
	}
}
