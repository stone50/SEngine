#pragma once

#include "Types.h"
#include "Resource.h"

namespace SEngine {
	typedef Map<String, SEngine::BaseResource*> ResourcePool;

	class Resources
	{
	public:
		static ResourcePool resources;

		static const Image* LoadImage(const String& nickname, const String& filePath);

		static const Texture* LoadTexture(const String& nickname, const String& filePath, RectInt area = RectInt());

		static const Font* LoadFont(const String& nickname, const String& filePath);

		static const SoundBuffer* LoadSoundBuffer(const String& nickname, const String& filePath);

		static const Shader* LoadShader(const String& nickname, const String& filePath, ShaderType type);

		static const Shader* LoadShader(const String& nickname, const String& vertexShaderFilePath, const String& fragmentShaderFilePath);

		static const Shader* LoadShader(const String& nickname, const String& vertexShaderFilePath, const String& geometryShaderFilePath, const String& fragmentShaderFilePath);

		static bool Loaded(const String& nickname);

		static const Image* GetImage(const String& nickname);

		static const Texture* GetTexture(const String& nickname);

		static const Font* GetFont(const String& nickname);

		static const SoundBuffer* GetSoundBuffer(const String& nickname);

		static const Shader* GetShader(const String& nickname);

		static void Unload(const String& nickname);

		static void UnloadAll();
	};
}
