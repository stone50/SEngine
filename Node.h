#pragma once

#include "Types.h"

namespace SEngine {
	class SNode
	{
	public:
		Tags tags;

		virtual void Start() = 0;

		virtual void Update(double delta) = 0;
	};
}
