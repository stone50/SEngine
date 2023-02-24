#include "pch.h"
#include "Resources.h"

#define LoadResource(rawType, type, loadFromFileFunction) \
rawType* rawResource = new rawType(); \
if (rawResource->loadFromFileFunction) { \
	type* resource = new type(rawResource); \
	resources[nickname] = resource; \
	return resource; \
} \
return nullptr;

using namespace SEngine;

ResourcePool Resources::resources = {};

const Image* Resources::LoadImage(const String& nickname, const String& filePath) {
	LoadResource(sf::Image, Image, loadFromFile(filePath))
}

const Texture* Resources::LoadTexture(const String& nickname, const String& filePath, RectInt area) {
	LoadResource(sf::Texture, Texture, loadFromFile(filePath, area))
}

const Font* Resources::LoadFont(const String& nickname, const String& filePath) {
	LoadResource(sf::Font, Font, loadFromFile(filePath))
}

const SoundBuffer* Resources::LoadSoundBuffer(const String& nickname, const String& filePath) {
	LoadResource(sf::SoundBuffer, SoundBuffer, loadFromFile(filePath))
}

const Shader* Resources::LoadShader(const String& nickname, const String& filePath, ShaderType type) {
	LoadResource(sf::Shader, Shader, loadFromFile(filePath, type))
}

const Shader* Resources::LoadShader(const String& nickname, const String& vertexShaderFilePath, const String& fragmentShaderFilePath) {
	LoadResource(sf::Shader, Shader, loadFromFile(vertexShaderFilePath, fragmentShaderFilePath))
}

const Shader* Resources::LoadShader(const String& nickname, const String& vertexShaderFilePath, const String& geometryShaderFilePath, const String& fragmentShaderFilePath) {
	LoadResource(sf::Shader, Shader, loadFromFile(vertexShaderFilePath, geometryShaderFilePath, fragmentShaderFilePath))
}

bool Resources::Loaded(const String& nickname) {
	return resources.count(nickname);
}

const Image* Resources::GetImage(const String& nickname) {
	return (Image*)resources[nickname];
}

const Texture* Resources::GetTexture(const String& nickname) {
	return (Texture*)resources[nickname];
}

const Font* Resources::GetFont(const String& nickname) {
	return (Font*)resources[nickname];
}

const SoundBuffer* Resources::GetSoundBuffer(const String& nickname) {
	return (SoundBuffer*)resources[nickname];
}

const Shader* Resources::GetShader(const String& nickname) {
	return (Shader*)resources[nickname];
}

void Resources::Unload(const String& nickname) {
	delete resources[nickname];
	resources.erase(nickname);
}

void Resources::UnloadAll() {
	for (auto& [key, value] : resources) {
		delete value;
	}
	resources.~ResourcePool();
}
