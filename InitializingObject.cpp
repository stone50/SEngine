#include "pch.h"
#include "InitializingObject.h"

using namespace SEngine;

void InitializingObject::SetInit(const InitFunction<InitializingObject>& function) {
	init = function;
}