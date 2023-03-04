#pragma once

#include "api.h"
#include "Types.h"
#include "CameraObject.h"
#include "GraphicObject.h"
#include "UpdatingObject.h"
#include "InitializingObject.h"

namespace SEngine {
	typedef Set<CameraObject*> Cameras;
	typedef Set<GraphicObject*> Graphics;
	typedef Set<LoadingObject*> Loaders;
	typedef Set<UpdatingObject*> Updaters;
	typedef Set<InitializingObject*> Initializers;
	typedef Set<Object*> Objects;

	class Scene
	{
	public:
		Scene(const InitFunction<Scene>& function);

		template <class T>
		SENGINE_API void* AddObject();

		SENGINE_API bool RemoveObject(Object* object);

		void Load();

		void Unload();

		void Reload();

		void Update(const float delta);

		void Render(Window& window);

	private:
		InitFunction<Scene> init;

		Cameras cameras;

		Graphics graphics;

		Loaders loaders;

		Updaters updaters;

		Initializers initializers;

		Objects objects;
	};
}
