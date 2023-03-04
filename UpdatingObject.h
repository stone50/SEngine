#pragma once

#include "Object.h"

namespace SEngine {
	class UpdatingObject :
		virtual public Object
	{
	public:
		SENGINE_API virtual void Update(const float delta) = 0;
	};
}
