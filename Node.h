#pragma once

#include "api.h"
#include "Types.h"

namespace SEngine {
	SENGINE_API class Node
	{
	public:
		Tags tags;

		virtual void Start() = 0;

		virtual void Update(double delta) = 0;
	};
}
