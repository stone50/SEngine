#pragma once

namespace SEngine {

#pragma region std

	template <class T>
	using InitFunction = std::function<void(const T* initObject)>;

#pragma region containers

	template <class T>
	using Set = std::unordered_set<T>;

	template <class K, class V>
	using Map = std::unordered_map<K, V>;

	template <class T>
	using List = std::vector<T>;

#pragma endregion containers

#pragma endregion std

#pragma region sf

#pragma region audio

	typedef sf::SoundBuffer RawSoundBuffer;

#pragma endregion audio

#pragma region graphics

	typedef sf::Color Color;

	typedef sf::Font RawFont;

	typedef sf::Image RawImage;

	typedef sf::Shader RawShader;

	typedef sf::Sprite Sprite;

	typedef sf::Texture RawTexture;

	typedef sf::IntRect RectInt;

	typedef sf::Shader::Type ShaderType;

	typedef sf::View View;

#pragma endregion graphics

#pragma region network

#pragma endregion network

#pragma region system

	typedef sf::Clock Clock;

	typedef sf::String String;

	typedef sf::Vector2i Vector2Int;

#pragma endregion system

#pragma region window

	typedef sf::ContextSettings ContextSettings;

	typedef sf::Cursor Cursor;

	typedef sf::Event Event;

	typedef sf::RenderWindow Window;

	typedef sf::VideoMode VideoMode;

#pragma endregion window

#pragma endregion sf

	typedef Set<String> Tags;
}