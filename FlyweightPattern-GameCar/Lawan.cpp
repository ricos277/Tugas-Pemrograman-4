#include "stdafx.h"
#include "Obstacle.h"
#include <iostream>
#include "typeLawan.h"
#include "factory.h"

using namespace std;

Lawan::Lawan() {
}

void Lawan::setLawanPos(float _x, float _y) {
	x = _x;
	y = _y;
}

void Lawan::settypeLawan(typeLawan _type) {
	type = _type;
}

void Lawan::update() {
	x -= type.speed;
}

Lawan::~Lawan()
{
}