/*
 *	server_Lock.cpp
 */

#include "Header Files/common_Lock.h"

Lock::Lock(std::mutex &m) : m(m) {
	m.lock();
}

Lock::~Lock() {
	m.unlock();
}

