#include "pch.h"
#include "Resource.h"

using namespace SEngine;

template <class T>
Resource<T>::Resource(T*& resource) : rawResource(resource) {}

template <class T>
Resource<T>::~Resource() {
	delete rawResource;
}

template class Resource<sf::Image>;
template class Resource<sf::Texture>;
template class Resource<sf::Font>;
template class Resource<sf::SoundBuffer>;
template class Resource<sf::Shader>;