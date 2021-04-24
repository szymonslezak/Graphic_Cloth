#pragma once
#include <vector>
class Spring_Data
{
public:
	std::vector<std::vector<std::vector<double>>> _pos;
	std::vector<std::vector<std::vector<double>>> _pos_prev;
	std::vector<std::vector<std::vector<double>>> _pos_next;
	std::vector<std::vector<std::vector<double>>> _vel;
	std::vector<std::vector<std::vector<double>>> _acc;
	std::vector<double> _d0;
	std::vector<std::vector<double>> _mass;
	std::vector<std::vector<int>> _springs; //format [x1][y1][x2][y2]
public:
	Spring_Data()
	{

	}
	Spring_Data(const unsigned int rows,const unsigned int cols)
	{
		for (unsigned int i = 0; i < cols; i++)
		{
			std::vector<std::vector<double>> col_data;
			std::vector<double> d_data;

			for (unsigned int x = 0; x < rows; x++)
			{
				col_data.push_back(std::vector<double>{0.0, 0.0, 0.0});
				d_data.push_back(0.0);
			}
			_pos.push_back(col_data);
			_pos_prev.push_back(col_data);
			_pos_next.push_back(col_data);
			_vel.push_back(col_data);
			_acc.push_back(col_data);
			//_d0.push_back(d_data);
			_mass.push_back(d_data);
		}
		/*_pos.resize(count, std::vector<std::vector<double>>{0.0, 0.0, 0.0});
		_pos_prev.resize(count, std::vector<double>{0.0, 0.0, 0.0});
		_pos_next.resize(count, std::vector<double>{0.0, 0.0, 0.0});*/
		/*_vel.resize(count, std::vector<double>{0.0, 0.0, 0.0});
		_acc.resize(count, std::vector<double>{0.0, 0.0, 0.0});
		_d0.resize(count, 0);
		_mass.resize(count, 1);*/
	}
	void reasign_pos(){
		_pos_prev = _pos;
		_pos = _pos_next;
	}


};

