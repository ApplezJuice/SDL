#pragma  once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "LayerStack.h"
#include "Layer.h"
#include "mainpch.h"
#include "Utility/Log.h"

// TEMP
#include "Renderer/Shader.h"

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
	LayerStack m_LayerStack;
	SDL_GLContext context;
	ImGuiLayer* m_ImGuiLayer;

	unsigned int m_VertextArray, m_VertexBuffer, m_IndexBuffer;
	std::unique_ptr<Shader> m_Shader;
};