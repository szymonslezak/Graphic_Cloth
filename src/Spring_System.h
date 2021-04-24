#pragma once
#include "Spring_Data.h"
#include "Spring_Updaters.h"
#include "Spring_Generators.h"
#include "Spring_Renderer.h"
#include <iostream>
class Spring_System
{
	Spring_Data _data;
	std::vector<std::shared_ptr<Spring_Generator>> _Generators;
	std::vector<std::shared_ptr<Spring_Updater>> _Updaters;
	std::shared_ptr<Spring_Renderer> _Renderer;
	const unsigned int _rows;
	const unsigned int _cols;
public:
	Spring_System(const int& rows, const int& cols):_rows(rows),_cols(cols)
	{
		reset();
	}
	void update(const double& dt);
	void reset();
	void addUpdater(std::shared_ptr<Spring_Updater> em) { _Updaters.push_back(em); }
	void addGenerator(std::shared_ptr<Spring_Generator> em) { _Generators.push_back(em); }
	void set_renderer(std::shared_ptr < Spring_Renderer> em) { _Renderer = em; }
	void render() { _Renderer->render(_data); }
	void generate();


};

