#include "render.hpp"
#include "gl_Shape.hpp"

#include <vector>
#include <GL\freeglut.h>

std::vector<gl::Shape *> glObjects;

void render(ChronoClock & clock)
{
	float deltaTime = (float)clock.getDeltaTime();
	float totalTime = (float)clock.getTotalTime();

	if (totalTime == 0.0)
	{
		glObjects.push_back(new gl::Cube(0.0f, 0.0f, -5.0f, 2.0f, 2.0f, 2.0f));
		glObjects.back()->SetColor(VERTEX_LEFT_BOTTOM_FRONT, 1.0f, 0.0f, 0.0f);
	}

	//glObjects.back()->Draw();
	glObjects.back()->Rotate(deltaTime * 360.0f, 0.0f, 0.0f);

	const unsigned char str1[] = "tonight";
	const unsigned char str2[] = "tonight tonight";

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-200.0f, -200.0f, -900.0f);
	if (totalTime > 62.0f) {}
	else if (totalTime >= 60.38f)
		glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char *)&str2);
	else if (totalTime >= 59.45f)
		glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char *)&str1);
	glPopMatrix();
}
