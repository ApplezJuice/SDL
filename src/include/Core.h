#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <vector>
#include "Scene.h"
#include "Entity.h"
#include "Utility/Log.h"

class RenderWindow;
class Core
{
public:
	static Core* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Core(); }

	bool Init();
	bool Clean();
	void Quit();

	void Update();
	void Events();

	inline bool IsRunning() { return m_IsRunning; }
	inline std::vector<Scene*> GetActiveScenes() { return m_ActiveScenes; }

private:
	Core(){};
	static Core* s_Instance;
	bool m_IsRunning;
	std::vector<Scene*> m_ActiveScenes;
	RenderWindow* m_Window = nullptr;
};