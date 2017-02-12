#include "render.hpp"
#include "ObjectGL.hpp"

ObjectGL * objects[OBJLEN];
double timePassed = 0;

void render(const double deltaTime)
{
	timePassed += deltaTime;

	if (timePassed == 0)
	{
		for (int i = 0; i < OBJLEN; i++)
		{
			float _x = ((i % 8) - 4) * OBJX + OBJX / 2;
			float _y = (i / 8) * (OBJY / (OBJLEN / 8)) - OBJYHALF;
			objects[i] = new CubeGL(_x, _y, -OBJZ, 0.02f, 0.01f, 0.02f);
		}
	}

	for (int i = 0; i < OBJLEN; i++)
	{
		objects[i]->Move(0.0f, 1.0f * -(float)deltaTime, 0.0f);
		while (objects[i]->GetY() < -OBJYHALF)
		{
			objects[i]->Move(0.0f, OBJY, 0.0f);
		}
	}

	for (int i = 0; i < OBJLEN; i++)
	{
		objects[i]->Draw();
	}
}
