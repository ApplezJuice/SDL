workspace "SDLTesting"
	architecture "x86_64"
	startproject "SDLTest"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Glad"
	kind "StaticLib"
	language "C"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/include/glad/glad.h",
		"src/include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs
	{
		"src/include",
		"src/include"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

project "SDLTest"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"src/include"
	}

	libdirs
	{
		"src/lib"
	}

	links
	{
		"SDL2",
		"SDL2main",
		"opengl32.lib",
		"glad"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		
		postbuildcommands
		{
			"{COPYFILE} bin/SDL2.dll bin/" .. outputdir .. "/SDLTest"
		}

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
