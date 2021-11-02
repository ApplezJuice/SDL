cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(TestSDL
		VERSION 0.0.1
		LANGUAGES CXX)

target_include_directories(main PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include")

add_executable(
	main
	main.cpp
	Core.cpp
	Entity.cpp
	glad.c
	ImGuiLayer.cpp
	Layer.cpp
	Log.cpp
	RenderWindow.cpp
	Scene.cpp
	Renderer/Shader.cpp
	ImGui/imgui_demo.cpp
	ImGui/imgui_draw.cpp
	ImGui/imgui_impl_opengl3.cpp
	ImGui/imgui_impl_sdl.cpp
	ImGui/imgui_tables.cpp
	ImGui/imgui_widgets.cpp
	ImGui/imgui.cpp
)