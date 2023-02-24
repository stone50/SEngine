#pragma once

#include "Types.h"

namespace SEngine {
	class BaseResource {};

	template <class T>
	class Resource :
		public BaseResource
	{
	public:
		Resource(T*& resource);

		~Resource();

		T* rawResource;
	};
	typedef Resource<sf::Image> Image;
	typedef Resource<sf::Texture> Texture;
	typedef Resource<sf::Font> Font;
	typedef Resource<sf::SoundBuffer> SoundBuffer;
	typedef Resource<sf::Shader> Shader;
}
