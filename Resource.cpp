#include "pch.h"

#include "Types.h"
#include "Resource.h"

using namespace SEngine;

String BaseResource::GetName() {
	return name;
}

size_t BaseResource::FilePathCount() {
	return filePaths.size();
}

String BaseResource::GetFilePath(size_t index) {
	if (index >= filePaths.size()) {
		return "";
	}

	return filePaths[index];
}

template <class T>
Resource<T>::Resource(const String& name, const FilePaths& filePaths, const T* resource) : name(name), filePaths(filePaths), rawResource(resource) {}

template <class T>
void Resource<T>::Unload() {
	delete rawResource;
	rawResource = nullptr;
}

template class Resource<RawImage>;
template class Resource<RawTexture>;
template class Resource<RawFont>;
template class Resource<RawSoundBuffer>;
template class Resource<RawShader>;