#pragma once
#include <iostream>
#include "typeLawan.h"
#include "factory.h"

using namespace std;

class Lawan
{
public:
	Lawan();
	~Lawan();

	void setLawanPos(float _x, float _y);
	void settypeLawan(typeLawan _type);
	void update();

	float x;
	float y;
	typeLawan type;
};