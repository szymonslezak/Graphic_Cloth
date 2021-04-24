#include "Spring_Renderer.h"


void Spring_Renderer::render(Spring_Data& data) const
{
	ofSetColor(255, 40, 0);
	for (size_t i = 0; i < data._pos.size(); i++)
	{
		if (i == data._pos.size() / 2)
		{
			ofSetColor(255, 255, 255);
		}
		for (size_t x = 0; x < data._pos[i].size(); x++)
		{
			if (i != 0)

			ofDrawSphere(data._pos[i][x][0], data._pos[i][x][1], data._pos[i][x][2], _r);
		}
	}
	ofSetColor(255, 40, 0);
	for (size_t i = 0; i < data._springs.size(); i++)
	{
		if (i > ((data._springs.size() / 2)+20))
		{
			ofSetColor(255, 255, 255);
		}
		std::vector<double> pos1 = data._pos[data._springs[i][0]][data._springs[i][1]];
		std::vector<double> pos2 = data._pos[data._springs[i][2]][data._springs[i][3]];
		ofDrawLine(pos1[0],pos1[1], pos1[2], pos2[0], pos2[1], pos2[2]);

	}
}
