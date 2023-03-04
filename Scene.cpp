#include "pch.h"

#include "Scene.h"

#define ForObjects(objectSet, function) \
for (auto& object : objectSet) { \
	function; \
}

#define TestAdd(objectType, objectSet) \
if (std::is_base_of<objectType, T>) { \
	objectSet.insert((objectType*)newObject); \
	miscObject = false; \
}

#define TestRemove(objectType, objectName, objectSet) \
objectType* objectName = dynamic_cast<objectType*>(object); \
if (objectName != nullptr && objectSet.count(objectName)) { \
	objectSet.erase(objectName); \
	foundObject = true; \
}

using namespace SEngine;

Scene::Scene(const InitFunction<Scene>& function) : init(function) {}

template <class T>
void* Scene::AddObject() {
	if (!std::is_base_of<Object, T>) {
		return nullptr;
	}

	T* newObject = new T();

	bool miscObject = true;

	TestAdd(CameraObject, cameras);

	TestAdd(GraphicObject, graphics);

	TestAdd(LoadingObject, loaders);

	TestAdd(UpdatingObject, updaters);

	TestAdd(InitializingObject, initializers);

	if (miscObject) {
		objects.insert(dynamic_cast<Object*>(newObject));
	}

	return newObject;
}

bool Scene::RemoveObject(Object* object) {
	bool foundObject = false;

	LoadingObject* loadingObject = dynamic_cast<LoadingObject*>(object);
	if (loadingObject != nullptr && loaders.count(loadingObject)) {
		loadingObject->Unload();
		loaders.erase(loadingObject);
		foundObject = true;
	}

	TestRemove(CameraObject, cameraObject, cameras);

	TestRemove(GraphicObject, graphicObject, graphics);

	TestRemove(UpdatingObject, updatingObject, updaters);

	TestRemove(Object, removedObject, objects);

	if (!foundObject) {
		return false;
	}

	delete object;
	return true;
}

void Scene::Load() {
	init(this);

	ForObjects(loaders, object->Load());

	ForObjects(initializers, object->init(object));

	objects.insert(initializers.begin(), initializers.end());
	initializers.~Initializers();
}

void Scene::Unload() {
	ForObjects(loaders, object->Unload());

	ForObjects(cameras, delete object);
	cameras.~Cameras();

	ForObjects(graphics, delete object);
	graphics.~Graphics();

	ForObjects(loaders, delete object);
	loaders.~Loaders();

	ForObjects(updaters, delete object);
	updaters.~Updaters();

	ForObjects(objects, delete object);
	objects.~Objects();
}

void Scene::Reload() {
	Unload();
	Load();
}

void Scene::Update(const float delta) {
	ForObjects(updaters, object->Update(delta));
}

void Scene::Render(Window& window) {
	for (auto& camera : cameras) {
		window.setView(camera->view);
		for (auto& graphic : graphics) {
			window.draw(graphic->sprite);
		}
	}
}
