#include "Core.h"

Core* Core::s_Instance = nullptr;

bool Core::Init()
{
	Log::Init();
	LOG_INFO("Initialized Logger");

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::string message = "SDL_Init HAS FAILED. SDL_ERROR: " + std::string(SDL_GetError());
		LOG_ERROR(message);
	}
	

	if (!IMG_Init(IMG_INIT_JPG))
	{
		std::string message = "IMG_Init HAS FAILED. IMG_ERROR: " + std::string(SDL_GetError());
		LOG_ERROR(message);
	}

	m_Window = new RenderWindow("Test Game V0.1", 1280, 720);

	m_ActiveScenes.push_back(new Scene);

	// Testing texture on main scene
	Entity testEntity = m_ActiveScenes[0]->CreateEntity("Test");
	testEntity.AddComponent<SpriteRendererComponent>();
	SpriteRendererComponent& sprite = testEntity.GetComponent<SpriteRendererComponent>();
	sprite.texture = m_Window->loadTexture("resources/gfx/serverdown.png");

	m_IsRunning = true;

	return true;
}

bool Core::Clean()
{
	m_Window->cleanUp();
	Quit();
	for(auto scene : m_ActiveScenes)
	{
		delete scene;
	}
	return true;
}

void Core::Quit()
{
	SDL_Quit();
}

void Core::Update()
{
	m_ActiveScenes[0]->RenderSprites(m_Window);
}

void Core::Events()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				m_IsRunning = false;
				break;
		}
	}
}