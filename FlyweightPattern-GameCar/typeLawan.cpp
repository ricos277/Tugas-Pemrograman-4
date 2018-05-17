#include "stdafx.h"
#include "typeLawan.h"

typeLawan::typeLawan() {

}

void typeLawan::setTypeValue(int _id, float _width, float _height, float _speed, int _colour) {
	id = _id;
	width = _width;
	height = _height;
	speed = _speed;
	colour = _colour;
}

typeLawan::~typeLawan()
{
}