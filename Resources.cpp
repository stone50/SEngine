#include "pch.h"

#include "Resources.h"

#define BRACED_INIT_LIST(...) {__VA_ARGS__}

#define LoadResource(rawType, type, loadFromFileFunction, filePaths) \
if (name == "") { \
	return nullptr; \
} \
rawType* rawResource = new rawType(); \
if (rawResource->loadFromFileFunction) { \
	type* resource = new type(name, BRACED_INIT_LIST(filePaths), rawResource); \
	resources[name] = resource; \
	return resource; \
} \
return nullptr;

using namespace SEngine;

ResourcePool Resources::resources = {};

const Image* Resources::LoadImage(const String& name, const String& filePath) {
	LoadResource(RawImage, Image, loadFromFile(filePath), filePath);
}

const Texture* Resources::LoadTexture(const String& name, const String& filePath, const RectInt& area) {
	LoadResource(RawTexture, Texture, loadFromFile(filePath, area), filePath);
}

const Font* Resources::LoadFont(const String& name, const String& filePath) {
	LoadResource(RawFont, Font, loadFromFile(filePath), filePath);
}

const SoundBuffer* Resources::LoadSoundBuffer(const String& name, const String& filePath) {
	LoadResource(RawSoundBuffer, SoundBuffer, loadFromFile(filePath), filePath);
}

const Shader* Resources::LoadShader(const String& name, const String& filePath, const ShaderType& type) {
	LoadResource(RawShader, Shader, loadFromFile(filePath, type), filePath);
}

const Shader* Resources::LoadShader(const String& name, const String& vertexShaderFilePath, const String& fragmentShaderFilePath) {
	LoadResource(RawShader, Shader, loadFromFile(vertexShaderFilePath, fragmentShaderFilePath), (vertexShaderFilePath, fragmentShaderFilePath));
}

const Shader* Resources::LoadShader(const String& name, const String& vertexShaderFilePath, const String& geometryShaderFilePath, const String& fragmentShaderFilePath) {
	String filePath = vertexShaderFilePath;
	LoadResource(RawShader, Shader, loadFromFile(vertexShaderFilePath, geometryShaderFilePath, fragmentShaderFilePath), (vertexShaderFilePath, geometryShaderFilePath, fragmentShaderFilePath));
}

bool Resources::Loaded(const String& name) {
	return resources.count(name);
}

const void* Resources::Get(const String& name) {
	try {
		return resources.at(name);
	}
	catch (std::out_of_range) {
		return nullptr;
	}
}

bool Resources::Unload(const String& name) {
	try {
		BaseResource* resource = resources.at(name);
		resource->Unload();
		delete resource;
		resources.erase(name);
		return true;
	}
	catch (std::out_of_range) {
		return false;
	}
}

void Resources::UnloadAll() {
	for (auto& [name, resource] : resources) {
		resource->Unload();
		delete resource;
	}
	resources.~ResourcePool();
}
