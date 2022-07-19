workspace "LakeEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "LakeEngine"
	location "LakeEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LE_PLATFORM_WINDOWS",
			"LE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sample")
		}

	filter "configurations:Debug"
		defines "LE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LE_DIST"
		optimize "On"

project "Sample"
	location "Sample"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"LakeEngine/vendor/spdlog/include",
		"LakeEngine/src"
	}
	
	links
	{
		"LakeEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LE_DIST"
		optimize "On"