#include "Core.h"

Core* Core::s_Instance = nullptr;

bool Core::Init()
{
	Log::Init();
	LOG_INFO("Initialized Logger");

	SDL_Init(SDL_INIT_EVERYTHING);

	// Request an OpenGL 4.5 context (should be core)
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	// Also request a depth buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	m_Window = new RenderWindow("Test Game V0.1", 1280, 720);

	m_ActiveScenes.push_back(new Scene);

	// Testing texture on main scene
	Entity testEntity = m_ActiveScenes[0]->CreateEntity("Test");
	testEntity.AddComponent<SpriteRendererComponent>();
	SpriteRendererComponent& sprite = testEntity.GetComponent<SpriteRendererComponent>();
	sprite.texture = m_Window->LoadTexture("resources/gfx/serverdown.png");

	m_IsRunning = true;

	// Check OpenGL properties
	LOG_INFO("OpenGL loaded");
	if(!gladLoadGLLoader(SDL_GL_GetProcAddress))
	{
		LOG_ERROR("Failed to init GLAD");
	}

	LOG_INFO("Vendor:   " + std::string((char *)glGetString(GL_VENDOR)));
	LOG_INFO("Renderer: " + std::string((char *)glGetString(GL_RENDERER)));
	LOG_INFO("Version:  " + std::string((char *)glGetString(GL_VERSION)));

	//m_Window->PushOverlay(new ImGuiLayer());

	return m_IsRunning;
}

bool Core::Clean()
{
	m_Window->Cleanup();
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
	// Render Update
	m_Window->Update();	
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