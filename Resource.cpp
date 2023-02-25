#include "pch.h"

#include "Types.h"
#include "Resource.h"

using namespace SEngine;

template <class T>
Resource<T>::Resource(const T* resource) : rawResource(resource) {}

template <class T>
Resource<T>::~Resource() {
	delete rawResource;
	rawResource = nullptr;
}

template class Resource<RawImage>;
template class Resource<RawTexture>;
template class Resource<RawFont>;
template class Resource<RawSoundBuffer>;
template class Resource<RawShader>;