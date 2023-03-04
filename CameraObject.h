#pragma once

#include "api.h"
#include "Types.h"
#include "Object.h"

namespace SEngine {
	class CameraObject :
		virtual public Object
	{
	public:
		View view;

		SENGINE_API View& GetView();
	};
}
