/*
 *	server_BoolProtected.cpp
 */

#include "server_BoolProtected.h"

BoolProtected::BoolProtected() : value(true) { }

BoolProtected::BoolProtected(bool value) : value(value) { }

bool BoolProtected::get_value() {
	std::unique_lock<std::mutex> mlock(m);
	return this->value;
}

void BoolProtected::set_value(bool value) {
	std::unique_lock<std::mutex> mlock(m);
	this->value = value;
}
