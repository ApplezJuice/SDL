#include "RenderWindow.h"
#include <iostream>
#include "Core.h"

RenderWindow::RenderWindow(const char* title, int width, int height)
	:window(NULL)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
								width, height, SDL_WINDOW_OPENGL);
	context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

	if (window == NULL)
	{
		std::cout << "[ERROR] Window Failed to Init. Error: " << SDL_GetError() << std::endl;
	}

	// Check OpenGL properties
	if(!gladLoadGLLoader(SDL_GL_GetProcAddress))
	{
		LOG_ERROR("Failed to init GLAD");
	}
	LOG_INFO("OpenGL loaded");

	m_ImGuiLayer = new ImGuiLayer();
	PushOverlay(m_ImGuiLayer);

	glGenVertexArrays(1, &m_VertextArray);
	glBindVertexArray(m_VertextArray);

	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

	float vertices[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

	unsigned int indices[3] = { 0, 1, 2};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	// texture = IMG_LoadTexture(renderer, filePath);

	// if (texture == NULL)
	// {
	// 	std::cout << "[ERROR] Failed to load a texture. Error: " << SDL_GetError() << std::endl;
	// }

	return texture;
}

void RenderWindow::Clear()
{
	
}

void RenderWindow::Render(SDL_Texture* texture)
{
	
}

void RenderWindow::Display()
{
	
}

void RenderWindow::Cleanup()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
}

void RenderWindow::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	layer->OnAttach(this);
}

void RenderWindow::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
	layer->OnAttach(this);
}

void RenderWindow::Update()
{
	// // Render sprites on active scenes
	// for(auto scene : Core::GetInstance()->GetActiveScenes())
	// 	scene->RenderSprites(this);
	glViewport(0, 0, 1280, 720);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(m_VertextArray);
	glDrawArrays( GL_TRIANGLES, 0, 3 );
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	
	// // Render layers
	m_ImGuiLayer->Begin();
	for (Layer* layer : m_LayerStack)
	{
		layer->OnUpdate();
		layer->OnImGuiRender();
	}
	m_ImGuiLayer->End();

	SDL_GL_SwapWindow(window);
}