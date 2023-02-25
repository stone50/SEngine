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
		SENGINE_API static InitFunction Init;

		SENGINE_API static bool Play(const WindowSettings& windowSettings = WindowSettings());

		SENGINE_API static bool End();

		SENGINE_API static Window& GetWindow();

		SENGINE_API static const Scene* GetCurrentScene();

		SENGINE_API static void SetCurrentScene(size_t index);

		SENGINE_API static size_t GetCurrentSceneIndex();

		SENGINE_API static const Scene* GetSceneAt(size_t index);

		SENGINE_API static void SetSceneAt(size_t index, Scene* scene); // delete existing scene

		SENGINE_API static size_t SceneCount();

		SENGINE_API static void InsertScene(size_t index, Scene* scene);

		SENGINE_API static void DeleteSceneAt(size_t index);

		SENGINE_API static void AddScene(Scene* scene);

		SENGINE_API static void SwapScenes(size_t scene1Index, size_t scene2Index);

	private:
		static Window window;

		static bool playing;

		static Scenes scenes;

		static size_t currentSceneIndex;

		static void InitWindow(const WindowSettings& windowSettings);

		static void HandleWindowEvents();

		static void Update(float delta);

		static void RenderFrame();

		static void UnloadScenes();
	};
}
