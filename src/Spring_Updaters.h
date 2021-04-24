#pragma once
#include "Spring_Data.h"
#include "ofMain.h"
class Spring_Updater
{
public:
	Spring_Updater()
	{

	}
	virtual void update(const double& dt, Spring_Data& data) = 0;
};

class Spring_Updater_Gravity : public Spring_Updater
{
	const double g;
public:
	Spring_Updater_Gravity(const double& acc = -9.81) :g(acc)
	{

	}
		void update(const double& dt, Spring_Data& data) override;
};

class Spring_Updater_Zero : public Spring_Updater
{
public:
	void update(const double& dt, Spring_Data& data) override;
};

class Spring_Updater_Spring : public Spring_Updater
{
	const double _k;
public:
	Spring_Updater_Spring(const double& k) :_k(k)
	{

	}
	void update(const double& dt, Spring_Data& data) override;

private:
	double distance(const std::vector<double>v1, const std::vector<double>v2) const
	{
		return sqrt((v1[0] - v2[0]) * (v1[0] - v2[0]) + (v1[1] - v2[1]) * (v1[1] - v2[1]) + (v1[2] - v2[2]) * (v1[2] - v2[2]));
	}
};

class Spring_Updater_Collision : public Spring_Updater
{
	const unsigned int _H;
	const unsigned int _W;
	const unsigned int _R;
public:
	Spring_Updater_Collision(const unsigned int& H, const unsigned int& W,const unsigned int& R) : _H(H), _W(W),_R(R)
	{

	}
	void update(const double& dt, Spring_Data& data) override;

};

class Spring_Updater_Verlette : public Spring_Updater
{
	bool is_over_one = false;
public:
	void set_is_over_one(const bool& one) { is_over_one = one; }
	void update(const double& dt, Spring_Data& data) override;

};

class Spring_Updater_Simple_Wind : public Spring_Updater
{
	const double _force;
public:
	Spring_Updater_Simple_Wind(const double force) :_force(force)
	{

	}
	void update(const double& dt, Spring_Data& data) override;
};

