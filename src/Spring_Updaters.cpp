#include "Spring_Updaters.h"

void Spring_Updater_Gravity::update(const double& dt, Spring_Data& data)
{
	for (size_t i = 0; i < data._acc.size(); i++)
	{
		for(size_t x = 0; x < data._acc[i].size();x++)
			data._acc[i][x][1] -= g;
	}

}

void Spring_Updater_Zero::update(const double& dt, Spring_Data& data)
{
	for (size_t i = 0; i < data._acc.size(); i++)
	{
		for (size_t x = 0; x < data._acc[i].size(); x++)
			data._acc[i][x] = std::vector<double>{ 0.0,0.0,0.0 };
	}
}

void Spring_Updater_Spring::update(const double& dt, Spring_Data& data)
{//change for springs
	for (size_t i = 0; i < data._springs.size(); i++) 
	{
		std::vector<double> pos1 = data._pos[data._springs[i][0]][data._springs[i][1]];
		std::vector<double> pos2 = data._pos[data._springs[i][2]][data._springs[i][3]];
		const double d = distance(pos1, pos2);
		double dx = d - data._d0[i];
		const double kb = 2.0;
		if (abs(dx) < 0.001)
		{
			dx = 0.0;
		}
		const double F = (-(_k)) * dx; //- kb * distance(data._vel[i], data._vel[i - 1]);

		const double nx = (pos1[0] - pos2[0]) / d;
		const double ny = (pos1[1] - pos2[1]) / d;
		const double nz = (pos1[2] - pos2[2]) / d;

		const double fx = F * nx;
		const double fy = F * ny;
		const double fz = F * nz;
		if (abs(F) > 100)
		{
			const double a = 1;
		}
		data._acc[data._springs[i][0]][data._springs[i][1]][0] += fx;
		data._acc[data._springs[i][0]][data._springs[i][1]][1] += fy;
		data._acc[data._springs[i][0]][data._springs[i][1]][2] += fz;
		data._acc[data._springs[i][2]][data._springs[i][3]][0] -= fx;
		data._acc[data._springs[i][2]][data._springs[i][3]][1] -= fy;
		data._acc[data._springs[i][2]][data._springs[i][3]][2] -= fz;
	}
}

void Spring_Updater_Collision::update(const double& dt, Spring_Data& data)
{
	for (size_t i = 0; i < data._pos.size(); i++)
	{
		for (size_t x = 0; x < data._pos[i].size(); x++)
		{
			if (data._pos[i][x][0] < 5 + _R)
			{
				data._pos[i][x][0] = 100.0 + _R + 1;
				data._vel[i][x][0] = -data._vel[i][x][0];
			}
			else if (data._pos[i][x][0] > _H - _R)
			{
				data._pos[i][x][0] = _H - _R - 1;
				data._vel[i][x][0] = -data._vel[i][x][0];
			}
			if (data._pos[i][x][1] < 5 + _R)
			{
				data._pos[i][x][1] = 100.0 + _R + 1;
				data._vel[i][x][1] = -data._vel[i][x][1];
			}
			else if (data._pos[i][x][1] > _W - _R)
			{
				data._pos[i][x][1] = _W - _R - 1;
				data._vel[i][x][1] = -data._vel[i][x][1];
			}
		}
	}
}

void Spring_Updater_Verlette::update(const double& dt, Spring_Data& data)
{
	if (is_over_one)
	{
		for (size_t i = 0; i < data._pos.size(); i++)
		{
			for (size_t x = 0; x < data._pos[i].size(); x++)
			{

				if (!((i == 0 && (x == 0 || x == (data._pos[0].size() - 1)))||(i == (data._pos.size() - 1) && (x == 0 || x == (data._pos[0].size() - 1)))))
				{
					data._pos_next[i][x][0] = 2 * data._pos[i][x][0] - data._pos_prev[i][x][0] + dt * dt * data._acc[i][x][0] / data._mass[i][x];
					data._pos_next[i][x][1] = 2 * data._pos[i][x][1] - data._pos_prev[i][x][1] + dt * dt * data._acc[i][x][1] / data._mass[i][x];
					data._pos_next[i][x][2] = 2 * data._pos[i][x][2] - data._pos_prev[i][x][2] + dt * dt * data._acc[i][x][2] / data._mass[i][x];
					data._vel[i][x][0] = (data._pos_next[i][x][0] - data._pos_prev[i][x][0]) / (2 * dt);
					data._vel[i][x][1] = (data._pos_next[i][x][1] - data._pos_prev[i][x][1]) / (2 * dt);
					data._vel[i][x][2] = (data._pos_next[i][x][2] - data._pos_prev[i][x][2]) / (2 * dt);
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < data._pos.size(); i++)
		{
			for (size_t x = 0; x < data._pos[i].size(); x++)
			{
					data._vel[i][x][0] = dt * data._acc[i][x][0];
					data._vel[i][x][1] = dt * data._acc[i][x][1];
					data._vel[i][x][2] = dt * data._acc[i][x][2];
					data._pos_next[i][x][0] = data._pos[i][x][0] + dt * data._vel[i][x][0] / data._mass[i][x];
					data._pos_next[i][x][1] = data._pos[i][x][1] + dt * data._vel[i][x][1] / data._mass[i][x];
					data._pos_next[i][x][2] = data._pos[i][x][2] + dt * data._vel[i][x][2] / data._mass[i][x];
			}
		}
		is_over_one = true;

	}
	data.reasign_pos();
}

void Spring_Updater_Simple_Wind::update(const double& dt, Spring_Data& data)
{

	const int x_lim_0= ofRandom(0, data._pos.size());
	const int x_lim_1 = ofRandom(x_lim_0, data._pos.size());
	for (int i = x_lim_0; i < x_lim_1; i++)
	{
		const int y_lim_0 = ofRandom(0, data._pos[i].size());
		const int y_lim_1 = ofRandom(y_lim_0, data._pos[i].size());
		for (int x = y_lim_0; x < y_lim_1; x++)
		{
			data._acc[i][x][2] += _force;
		}
	}

}
