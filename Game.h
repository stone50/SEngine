#pragma once

#include "api.h"
#include "Types.h"
#include "WindowSettings.h"
#include "Scene.h"

namespace SEngine {
	typedef List<Scene*> Scenes;

	class Game
	{
	public:
		SENGINE_API static bool Play(const WindowSettings& windowSettings = WindowSettings());

		SENGINE_API static bool End();

		SENGINE_API static const Scene* GetCurrentScene();

		SENGINE_API static bool SetCurrentScene(const size_t index);

		SENGINE_API static size_t GetCurrentSceneIndex();

		SENGINE_API static size_t SceneCount();

		SENGINE_API static void AddScene(const InitFunction<Scene>& function);

	private:
		static Window window;

		static Scenes scenes;

		static size_t currentSceneIndex;

		static void InitWindow(const WindowSettings& windowSettings);

		static void HandleWindowEvents();

		static void Update(const float delta);

		static void RenderFrame();

		static void UnloadScenes();
	};
}
