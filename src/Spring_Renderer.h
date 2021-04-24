#pragma once
#include <vector>
#include "Spring_Data.h"
#include "ofMain.h"
class Spring_Renderer
{

	const unsigned int _r;
	//const unsigned int _d;
public:
	Spring_Renderer(const unsigned int& r):_r(r)
	{

	}
	void render(Spring_Data& data) const;
};

