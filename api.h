#pragma once

#ifdef SENGINE_EXPORTS
#define SENGINE_API __declspec(dllexport)
#else
#define SENGINE_API __declspec(dllimport)
#endif