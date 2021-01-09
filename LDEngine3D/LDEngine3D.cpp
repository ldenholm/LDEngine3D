#include "olcConsoleGameEngine.h"
using namespace std;

struct vec3d
{
	// these represent coords in 3d space
	float x, y, z;
};

struct triangle
{
	// array of 'points' made up of x,y,z's
	vec3d p[3];
};

struct mesh
{
	// vector of tris representing an object
	vector<triangle> tris;
};

class LDEngine3D : public olc::PixelGameEngine
{
public:
	LDEngine3D()
	{
		sAppName = "3D Demo";
	}

private:
	mesh meshCube;

public:
	bool OnUserCreate() override
	{
		// building triangles to represent cube (start clockwise at 0,0,0)
		meshCube.tris = {
			//SOUTH (side)
			{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,	1.0f, 1.0f, 0.0f },
			{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,	1.0f, 0.0f, 0.0f },

			//EAST
			{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,	1.0f, 1.0f, 1.0f },
			{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,	1.0f, 0.0f, 1.0f },

			//NORTH
			{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,	0.0f, 1.0f, 1.0f },
			{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,	0.0f, 0.0f, 1.0f },

			//WEST
			{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,	0.0f, 1.0f, 0.0f },
			{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,	0.0f, 0.0f, 1.0f },

			//TOP
			{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,	1.0f, 1.0f, 1.0f },
			{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,	1.0f, 1.0f, 0.0f },

			//BOTTOM
			{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,	0.0f, 0.0f, 0.0f },
			{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,	1.0f, 0.0f, 0.0f },
		};

		return true;
	}

public:
	bool OnUserUpdate(float fElapsedTime) override
	{
		return true;
	}
};

int main()
{
	LDEngine3D demo;
	if (demo.Construct(256, 240, 4, 4))
		// on successfull construction of console, lets start
		demo.Start();
	return 0;
}