#pragma once

#include "api.h"
#include "Types.h"

namespace SEngine {
	class Scene
	{
	public:
		SENGINE_API Scene(InitFunction function);

		SENGINE_API void SetInit(InitFunction function);

		void Load();

		void Unload();

		void Reload();

		void Update(float delta);

		void Render(const Window& window);

	private:
		InitFunction Init;
	};
}
