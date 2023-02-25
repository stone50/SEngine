#pragma once

#include "api.h"
#include "Types.h"
#include "Resource.h"

namespace SEngine {
	typedef Map<String, BaseResource*> ResourcePool;

	class Resources
	{
	public:
		SENGINE_API static const Image* LoadImage(const String& nickname, const String& filePath);

		SENGINE_API static const Texture* LoadTexture(const String& nickname, const String& filePath, RectInt area = RectInt());

		SENGINE_API static const Font* LoadFont(const String& nickname, const String& filePath);

		SENGINE_API static const SoundBuffer* LoadSoundBuffer(const String& nickname, const String& filePath);

		SENGINE_API static const Shader* LoadShader(const String& nickname, const String& filePath, ShaderType type);

		SENGINE_API static const Shader* LoadShader(const String& nickname, const String& vertexShaderFilePath, const String& fragmentShaderFilePath);

		SENGINE_API static const Shader* LoadShader(const String& nickname, const String& vertexShaderFilePath, const String& geometryShaderFilePath, const String& fragmentShaderFilePath);

		SENGINE_API static bool Loaded(const String& nickname);

		SENGINE_API static const Image* GetImage(const String& nickname);

		SENGINE_API static const Texture* GetTexture(const String& nickname);

		SENGINE_API static const Font* GetFont(const String& nickname);

		SENGINE_API static const SoundBuffer* GetSoundBuffer(const String& nickname);

		SENGINE_API static const Shader* GetShader(const String& nickname);

		SENGINE_API static void Unload(const String& nickname);

		SENGINE_API static void UnloadAll();

		SENGINE_API static String GetNickname(const BaseResource* resource);

	private:
		static ResourcePool resources;

	};
}
