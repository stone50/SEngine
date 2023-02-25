#include "pch.h"

#include <iostream>

#include "Debug.h"

using namespace SEngine;

void Debug::Log(const String& message) {
	std::cout << message;
}
