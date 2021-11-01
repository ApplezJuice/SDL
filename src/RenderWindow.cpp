#include "RenderWindow.h"
#include <iostream>
#include "Core.h"

RenderWindow::RenderWindow(const char* title, int width, int height)
	:window(NULL), renderer(NULL)
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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
	{
		std::cout << "[ERROR] Failed to load a texture. Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}

void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::Render(SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(renderer);
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
	
	// // Render layers
	for (Layer* layer : m_LayerStack)
		layer->OnUpdate();

	glViewport(0, 0, 1280, 720);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//TODO: Check if debug mode enabled
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window);
	
}