#include "Spring_Generators.h"

void Spring_Genartor_Pos::generate(Spring_Data& data)
{
	
	for (size_t i = 0; i < data._pos.size()	; i++)
	{
		for (size_t x = 0; x < data._pos[0].size(); x++)
		{
			data._pos[i][x][0] = (double)x * _step + 500;
			data._pos[i][x][1] = (double)i * _step + 200;
			data._pos[i][x][2] = 0;
		}


	}
}

void Spring_Generator_D0::generate(Spring_Data& data)
{
	//Do it for springs
	for (size_t i = 0; i < data._springs.size(); i++)
	{
		std::vector<double> pos1 = data._pos[data._springs[i][0]][data._springs[i][1]];
		std::vector<double> pos2 = data._pos[data._springs[i][2]][data._springs[i][3]];
		data._d0.push_back(distance(pos1, pos2));
	}
}

void Spring_Genartor_Mass::generate(Spring_Data& data)
{
	for (size_t i = 0; i < data._mass.size(); i++)
	{
		for (size_t x = 0; x < data._mass[0].size(); x++)
		{
			data._mass[i][x] = _mass;
		}	
	}
}

void Spring_Genartor_Simple_Connect::generate(Spring_Data& data)
{
	for (int i = 0; i < (int)data._pos.size()-1; i++)
	{
		for (int x = 0; x < (int)data._pos[i].size()-1; x++)
		{
			data._springs.push_back(std::vector<int>{i, x,i+1,x});
			data._springs.push_back(std::vector<int>{i, x,i,x+1});
		}
		data._springs.push_back(std::vector<int>{i, (int)data._pos[i].size() - 1, i + 1, (int)data._pos[i+1].size() - 1});
	}
	for (int i = 0; i < (int)data._pos[data._pos.size() - 1].size() - 1; i++)
	{
		data._springs.push_back(std::vector<int>{(int)data._pos.size() - 1, i, (int)data._pos.size() - 1, i + 1});
	}
}
