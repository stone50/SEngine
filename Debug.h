#pragma once

#if defined(SENGINE_EXPORTS) || defined(_DEBUG)

#include "api.h"
#include "Types.h"

namespace SEngine {
	class Debug
	{
	public:
		SENGINE_API static void Write(const String& message);
	};
}

#endif
