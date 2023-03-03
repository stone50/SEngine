#pragma once

#include "api.h"
#include "Types.h"
#include "Object.h"

namespace SEngine {
	class InitializingObject :
		virtual public Object
	{
	public:
		InitFunction<InitializingObject> init;

		SENGINE_API void SetInit(const InitFunction<InitializingObject>& function);
	};
}
