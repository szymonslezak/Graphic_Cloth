#include "Spring_System.h"

void Spring_System::update(const double& dt)
{
	for (auto& up : _Updaters)
	{
		up->update(dt, _data);
	}
}

void Spring_System::reset()
{
	_data = Spring_Data(_rows,_cols);
	
}

void Spring_System::generate()
{
	for (auto& up : _Generators)
	{
		up->generate(_data);
	}
}
