#pragma once

namespace SEngine {
	class BaseResource {};

	template <class T>
	class Resource :
		public BaseResource
	{
	public:
		Resource(const T* resource);

		~Resource();

		const T* rawResource;
	};
	typedef Resource<RawImage> Image;
	typedef Resource<RawTexture> Texture;
	typedef Resource<RawFont> Font;
	typedef Resource<RawSoundBuffer> SoundBuffer;
	typedef Resource<RawShader> Shader;
}
