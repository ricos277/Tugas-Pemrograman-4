#pragma once
#include <iostream>

using namespace std;

class typeLawan
{
public:
	int id;
	float width;
	float height;
	float speed;
	int colour;

	typeLawan();
	~typeLawan();
	void setTypeValue(int _id, float _width, float _height, float _speed, int _colour);
};
