#pragma once
#include <vector>
#include "typeLawan.h"

class factory
{
public:
	static vector<typeLawan*> arrayOftypeLawan;
	static typeLawan* getType(int _id, float _width, float _height, float _speed, int _colour);
	factory();
	~factory();
};
