#pragma once

#include "api.h"
#include "Types.h"
#include "Resource.h"

namespace SEngine {
	typedef Map<std::string, BaseResource*> ResourcePool;

	class Resources
	{
	public:
		SENGINE_API static const Image* LoadImage(const String& name, const String& filePath);

		SENGINE_API static const Texture* LoadTexture(const String& name, const String& filePath, const RectInt& area = RectInt());

		SENGINE_API static const Font* LoadFont(const String& name, const String& filePath);

		SENGINE_API static const SoundBuffer* LoadSoundBuffer(const String& name, const String& filePath);

		SENGINE_API static const Shader* LoadShader(const String& name, const String& filePath, const ShaderType& type);

		SENGINE_API static const Shader* LoadShader(const String& name, const String& vertexShaderFilePath, const String& fragmentShaderFilePath);

		SENGINE_API static const Shader* LoadShader(const String& name, const String& vertexShaderFilePath, const String& geometryShaderFilePath, const String& fragmentShaderFilePath);

		SENGINE_API static bool Loaded(const String& name);

		SENGINE_API static const void* Get(const String& name);

		SENGINE_API static bool Unload(const String& name);

		SENGINE_API static void UnloadAll();

	private:
		static ResourcePool resources;

	};
}
