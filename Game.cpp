#include "pch.h"

#include "Game.h"
#include "Resources.h"

#define ValidateIndex(index) \
if (index >= scenes.size()) \
{ \
	return false; \
}

using namespace SEngine;

Window Game::window;
Scenes Game::scenes = {};
size_t Game::currentSceneIndex = 0;

bool Game::Play(const WindowSettings& windowSettings) {
	if (scenes.size() == 0) {
		return false;
	}

	scenes[0]->Load();

	InitWindow(windowSettings);

	Clock clock;
	while (true)
	{
		HandleWindowEvents();

		if (!window.isOpen()) {
			return true;
		}

		Update(clock.restart().asSeconds());

		RenderFrame();
	}
}

bool Game::End() {
	scenes[currentSceneIndex]->Unload();

	UnloadScenes();

	Resources::UnloadAll();

	window.close();

	return true;
}

const Scene* Game::GetCurrentScene() {
	return scenes[currentSceneIndex];
}

bool Game::SetCurrentScene(size_t index) {
	ValidateIndex(index);

	scenes[currentSceneIndex]->Unload();
	currentSceneIndex = index;
	scenes[currentSceneIndex]->Load();
	return true;
}

size_t Game::GetCurrentSceneIndex() {
	return currentSceneIndex;
}

size_t Game::SceneCount() {
	return scenes.size();
}

void Game::AddScene(const InitFunction<Scene>& function) {
	scenes.push_back(new Scene(function));
}

void Game::InitWindow(const WindowSettings& windowSettings) {
	window.create(windowSettings.videoMode, windowSettings.title, windowSettings.style, windowSettings.contextSettings);

	window.setActive(windowSettings.active);
	if (!windowSettings.verticalSyncEnabled) {
		window.setFramerateLimit(windowSettings.framerateLimit);
	}
	if (windowSettings.iconPixels != nullptr) {
		window.setIcon(windowSettings.iconWidth, windowSettings.iconHeight, windowSettings.iconPixels);
	}
	window.setJoystickThreshold(windowSettings.joystickThreshold);
	window.setKeyRepeatEnabled(windowSettings.keyRepeatEnabled);
	if (!windowSettings.useDefaultCursor) {
		window.setMouseCursor(windowSettings.mouseCursor);
	}
	window.setMouseCursorGrabbed(windowSettings.mouseCursorGrabbed);
	window.setMouseCursorVisible(windowSettings.mouseCursorVisible);
	window.setPosition(windowSettings.position);
	window.setVerticalSyncEnabled(windowSettings.verticalSyncEnabled);
	window.setVisible(windowSettings.visible);
}

void Game::HandleWindowEvents() {
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case Event::Closed:
			End();
			break;
		}
	}
}

void Game::Update(float delta) {
	scenes[currentSceneIndex]->Update(delta);
}

void Game::RenderFrame() {
	window.clear(Color::Black);
	scenes[currentSceneIndex]->Render(window);
	window.display();
}

void Game::UnloadScenes() {
	for (auto& scene : scenes) {
		delete scene;
	}
	scenes.~Scenes();
}