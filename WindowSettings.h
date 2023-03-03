#pragma once

#include "api.h"
#include "Types.h"

namespace SEngine {
	SENGINE_API struct WindowSettings {
		bool active = true;

		unsigned int framerateLimit = 60;

		unsigned int iconWidth = 0;
		unsigned int iconHeight = 0;
		unsigned char* iconPixels = nullptr;

		float joystickThreshold = 0.1f;

		bool keyRepeatEnabled = true;

		bool useDefaultCursor = true;
		Cursor mouseCursor;

		bool mouseCursorGrabbed = false;

		bool mouseCursorVisible = true;

		Vector2Int position = Vector2Int(0, 0);

		String title = "";

		bool verticalSyncEnabled = false;

		bool visible = true;

		VideoMode videoMode = VideoMode();

		unsigned int style = sf::Style::Default;

		ContextSettings contextSettings = ContextSettings();
	};
}
