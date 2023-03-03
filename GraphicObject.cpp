#include "pch.h"
#include "GraphicObject.h"

using namespace SEngine;

Sprite& GraphicObject::GetSprite() {
	return sprite;
}

void GraphicObject::Render(Window& window) {
	window.draw(sprite);
}
