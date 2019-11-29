workspace "Kass"
	architecture "x64"
	
	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kass"
	location "Kass"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ksspch.h"
	pchsource "Kass/src/ksspch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"KSS_PLATFORM_WINDOWS",
			"KSS_BUILD_DLL",
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "KSS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KSS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KSS_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"Kass/vendor/spdlog/include",
		"Kass/src"
	}

	links{
		"Kass"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"KSS_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "KSS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KSS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "KSS_DIST"
		optimize "On"