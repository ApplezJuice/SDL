#pragma  once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "LayerStack.h"
#include "Layer.h"

class ImGuiLayer;
class RenderWindow
{
public:
	RenderWindow(const char* title, int width, int height);
	SDL_Texture* LoadTexture(const char* filePath);
	void Clear();
	void Render(SDL_Texture* texture);
	void Display();
	void Cleanup();
	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);
	void Update();

	inline SDL_Window* GetWindow() { return window; }
	inline SDL_GLContext& GetContext() { return context; }

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	LayerStack m_LayerStack;
	SDL_GLContext context;
	ImGuiLayer* m_ImGuiLayer;
};