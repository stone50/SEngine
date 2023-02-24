#pragma once

#include <unordered_set>
#include <unordered_map>
#include <string>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Shader.hpp>

namespace SEngine {
	template <class T>
	using Set = std::unordered_set<T>;
	template <class K, class V>
	using Map = std::unordered_map<K, V>;
	typedef std::string String;
	typedef Set<String> Tags;
	typedef sf::IntRect RectInt;
	typedef sf::Shader::Type ShaderType;
}