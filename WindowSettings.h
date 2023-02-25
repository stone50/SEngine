#pragma once

#include "api.h"
#include "Types.h"

namespace SEngine {
	SENGINE_API struct WindowSettings {
		bool active = true;

		unsigned int framerateLimit = 60;

		unsigned int iconWidth = 0;
		unsigned int iconHeight = 0;
		sf::Uint8* iconPixels = nullptr;

		float joystickThreshold = 0.1f;

		bool keyRepeatEnabled = true;

		bool useDefaultCursor = true;
		sf::Cursor mouseCursor;

		bool mouseCursorGrabbed = false;

		bool mouseCursorVisible = true;

		sf::Vector2i position = sf::Vector2i(0, 0);

		std::string title = "";

		bool verticalSyncEnabled = false;

		bool visible = true;

		sf::VideoMode videoMode = sf::VideoMode();

		unsigned int style = sf::Style::Default;

		sf::ContextSettings contextSettings = sf::ContextSettings();
	};
}
