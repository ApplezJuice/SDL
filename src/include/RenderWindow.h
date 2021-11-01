#pragma  once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "LayerStack.h"
#include "Layer.h"

class RenderWindow
{
public:
	RenderWindow(const char* title, int width, int height);
	SDL_Texture* loadTexture(const char* filePath);
	void clear();
	void render(SDL_Texture* texture);
	void display();
	void cleanUp();
	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);
	void Update();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	LayerStack m_LayerStack;
};