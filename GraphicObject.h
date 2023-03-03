#pragma once

#include "api.h"
#include "Types.h"
#include "LoadingObject.h"

namespace SEngine {
	class GraphicObject :
		virtual public LoadingObject
	{
	public:
		Sprite sprite;

		SENGINE_API Sprite& GetSprite();

		void Render(Window& window);
	};
}
