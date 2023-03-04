#include "pch.h"

#include "Debug.h"

using namespace SEngine;

void Debug::Write(const String& message) {
	std::cout << (std::string)message;
}
