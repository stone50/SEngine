#pragma once

#include "api.h"

namespace SEngine {
	typedef List<String> FilePaths;

	class BaseResource {
	public:
		SENGINE_API String GetName();

		SENGINE_API size_t FilePathCount();

		SENGINE_API String GetFilePath(const size_t index);

		virtual void Unload() = 0;

	protected:
		String name;

		FilePaths filePaths;
	};

	template <class T>
	class Resource :
		public BaseResource
	{
	public:
		Resource(const String& name, const FilePaths& filePaths, const T* resource);

		void Unload() override;

		const T* rawResource;

	private:
		String name;

		FilePaths filePaths;
	};
	typedef Resource<RawImage> Image;
	typedef Resource<RawTexture> Texture;
	typedef Resource<RawFont> Font;
	typedef Resource<RawSoundBuffer> SoundBuffer;
	typedef Resource<RawShader> Shader;
}
