#include "render.hpp"
#include "gl_Shape.hpp"

#include <vector>
#include <GL\freeglut.h>

//std::vector<gl::Shape *> glObjects;

#include "obj.hpp"

extern std::vector<obj::Object> g_objects;
extern std::vector<obj::Property3f> g_vertices;
extern std::vector<obj::Property3f> g_textures;
extern std::vector<obj::Property3f> g_normals;

void drawVertex(const obj::VertexSet & vertSet)
{
	obj::Property3f propVert = g_vertices[vertSet.getVertex()];
	obj::Property3f propNorm = g_normals[vertSet.getNormal()];

	glNormal3f(propNorm.getX(), propNorm.getY(), propNorm.getZ());
	glVertex3f(propVert.getX(), propVert.getY(), propVert.getZ());
}

void render(ChronoClock & clock)
{
	clock.getDeltaTime();
	//float deltaTime = (float)clock.getDeltaTime();
	float totalTime = (float)clock.getTotalTime();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(totalTime * 90.0f, 0.25f, 0.5f, 0.25f);

	glBegin(GL_TRIANGLES);
	for (unsigned i = 0; i < g_objects.size(); i++)
	{
		std::vector<obj::Face> & faces = g_objects[i].getFaces();
		for (unsigned j = 0; j < faces.size(); j++)
		{
			std::vector<obj::VertexSet> vertSets = faces[j].getVertexSets();
			if (vertSets.size() == 3)
			{
				for (int k = 0; k < 3; k++)
				{
					drawVertex(vertSets[k]);
				}
			}
		}
	}
	glEnd();

	glBegin(GL_QUADS);
	for (unsigned i = 0; i < g_objects.size(); i++)
	{
		std::vector<obj::Face> & faces = g_objects[i].getFaces();
		for (unsigned j = 0; j < faces.size(); j++)
		{
			std::vector<obj::VertexSet> vertSets = faces[j].getVertexSets();
			if (vertSets.size() == 4)
			{
				for (int k = 0; k < 4; k++)
				{
					drawVertex(vertSets[k]);
				}
			}
		}
	}
	glEnd();

	glPopMatrix();

	/*if (totalTime == 0.0)
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
	glPopMatrix();*/
}
