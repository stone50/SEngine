#pragma once

#include "Object.h"

namespace SEngine {
	class LoadingObject :
		virtual public Object
	{
	public:
		SENGINE_API virtual void Load() = 0;

		SENGINE_API virtual void Unload() = 0;
	};
}
