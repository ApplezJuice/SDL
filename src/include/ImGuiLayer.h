#pragma once
#include "Layer.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include "Utility/Log.h"
#include "RenderWindow.h"

class ImGuiLayer : public Layer
{
public:
	ImGuiLayer();
	~ImGuiLayer();

	void OnAttach(RenderWindow* renderer);
	void OnDetach();
	void OnUpdate();
private:

};