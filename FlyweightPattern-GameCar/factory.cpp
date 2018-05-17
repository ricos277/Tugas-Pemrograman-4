#include "stdafx.h"
#include "factory.h"
#include "typeLawan.h"

vector <typeLawan*> factory::arrayOftypeLawan;


typeLawan* factory::getType(int _id, float _width, float _height, float _speed, int _colour) {
	for (vector<typeLawan*>::const_iterator i = arrayOftypeLawan.begin(); i != arrayOftypeLawan.end(); ++i) {
		if ((*i)->id == _id) {
			return *i;
		}
	}
	typeLawan* newType = new typeLawan();
	newType->setTypeValue(_id, _width, _height, _speed, _colour);
	factory::typeLawan.push_back(newType);
	return newType;
}

factory::factory()
{
}

factory::~factory()
{
}