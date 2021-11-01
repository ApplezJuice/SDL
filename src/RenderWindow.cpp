#include "RenderWindow.h"
#include <iostream>

RenderWindow::RenderWindow(const char* title, int width, int height)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
								width, height, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "[ERROR] Window Failed to Init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
	{
		std::cout << "[ERROR] Failed to load a texture. Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* texture)
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

void RenderWindow::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
}

void RenderWindow::Update()
{
	// std::vector<Scene*> activeScenes = Core::GetInstance()->GetActiveScenes();
	// for(auto scene : activeScenes)
	// {
	// 	scene->RenderSprites(this);
	// }
}