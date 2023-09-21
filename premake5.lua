workspace "RockyEngine"
	architecture "x64"
	startproject "Wonderbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architechture}"

project "RockyEngine"
	location "RockyEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RK_PLATFORM_WINDOWS",
			"RK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Wonderbox")
		}
		
    filter "configurations:Debug"
		defines "RK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RK_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "RK_DIST"
		symbols "On"

project "Wonderbox"
	location "Wonderbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"RockyEngine/vendor/spdlog/include",
		"RockyEngine/src"
	}

	links
	{
		"RockyEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RK_PLATFORM_WINDOWS",
		}
		
    filter "configurations:Debug"
		defines "RK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RK_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "RK_DIST"
		symbols "On"

	