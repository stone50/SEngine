#include "pch.h"

#include "Game.h"
#include "Resources.h"

using namespace SEngine;

InitFunction Game::Init = NULL;
Window Game::window;
bool Game::playing = false;
Scenes Game::scenes = {};
size_t Game::currentSceneIndex = 0;

bool Game::Play(const WindowSettings& windowSettings) {
	if (playing) {
		return false;
	}

	Init();

	if (scenes.size() == 0) {
		return false;
	}

	playing = true;

	scenes[0]->Load();

	InitWindow(windowSettings);

	Clock clock;
	while (true)
	{
		HandleWindowEvents();

		if (!playing) {
			return true;
		}

		Update(clock.restart().asSeconds());

		RenderFrame();
	}

	return true;
}

bool Game::End() {
	if (!playing) {
		return false;
	}

	playing = false;

	scenes[currentSceneIndex]->Unload();

	UnloadScenes();

	Resources::UnloadAll();

	window.close();

	return true;
}

Window& Game::GetWindow() {
	return window;
}

void Game::AddScene(Scene* scene) {
	scenes.push_back(scene);
}

size_t Game::GetCurrentSceneIndex() {
	return currentSceneIndex;
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
	scenes.~vector();
}