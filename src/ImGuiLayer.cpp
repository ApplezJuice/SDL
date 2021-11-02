#include "ImGui/ImGuiLayer.h"

ImGuiLayer::ImGuiLayer()
	: Layer("ImGuiLayer")
{
}

ImGuiLayer::~ImGuiLayer()
{

}

void ImGuiLayer::OnAttach(RenderWindow* renderer)
{
	ImGui::CreateContext();

	// ImGuiIO& io = ImGui::GetIO();
	// io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
	// io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
	
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	const char* glsl_version = "#version 430";
	ImGui_ImplSDL2_InitForOpenGL(renderer->GetWindow(), renderer->GetContext());
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void ImGuiLayer::OnDetach()
{
	ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::Begin()
{
	// Begin a new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
}

void ImGuiLayer::End()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::OnImGuiRender()
{
	static bool show = true;
	ImGui::ShowDemoWindow(&show);

	// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
	{
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

		ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
		ImGui::Checkbox("Demo Window", &show);      // Edit bools storing our window open/close state

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}
}