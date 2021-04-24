#pragma once
#include "Spring_Data.h"
class Spring_Generator
{
public:
	Spring_Generator()
	{

	}

	virtual void generate(Spring_Data& data) = 0;
};

class Spring_Genartor_Pos: public Spring_Generator
{
	const unsigned int _step;
	public:
		Spring_Genartor_Pos(const unsigned int& step) :_step(step)
		{

		}
		virtual void generate(Spring_Data& data) override;
};
class Spring_Genartor_Mass : public Spring_Generator
{
	const unsigned int _mass;
public:
	Spring_Genartor_Mass(const unsigned int& mass) :_mass(mass)
	{

	}
	virtual void generate(Spring_Data& data) override;
};
class Spring_Genartor_Simple_Connect : public Spring_Generator
{
public:
	Spring_Genartor_Simple_Connect()
	{

	}
	virtual void generate(Spring_Data& data) override;
};




class Spring_Generator_D0 :public Spring_Generator
{
	double distance(const std::vector<double>v1, const std::vector<double>v2) const
	{
		return sqrt((v1[0] - v2[0]) * (v1[0] - v2[0]) + (v1[1] - v2[1]) * (v1[1] - v2[1]) + (v1[2] - v2[2]) * (v1[2] - v2[2]));
	}
public:
	virtual void generate(Spring_Data& data) override;
};
