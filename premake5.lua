workspace "characterSheet5.5"
    architecture "ARM64"
    configurations { "Debug", "Release" }
    startproject "characterSheet5.5"

project "characterSheet5.5"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"

    buildoptions { "-std=c++23" }

    prebuildcommands {
        "mkdir -p bin-int/Debug && cp src/headers/pch.hpp bin-int/Debug/pch.hpp",
        "mkdir -p bin-int/Release && cp src/headers/pch.hpp bin-int/Release/pch.hpp",
    }

    files {
        "src/**.cpp",
        "src/headers/**.hpp",
        "externals/**.cpp",
        "externals/**.h"
    }

    includedirs {
        "src/headers",
        "src/enums",
        "/opt/homebrew/include",
        "externals/imgui-sfml",
        "externals/imgui",
        "/opt/homebrew/include",
        "/opt/homebrew/include/SFML"
    }

    libdirs {
        "/opt/homebrew/lib",
        "/opt/homebrew/Cellar/sfml/3.0.2/lib"
    }

    links {
        "ftxui-component",
        "ftxui-dom",
        "ftxui-screen",
        "sfml-graphics",
        "sfml-window",
        "sfml-system",
        "OpenGL.framework"
    }

    pchheader "src/headers/pch.hpp"
    pchsource "src/controller/pch.cpp"

    filter "system:macosx"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter {}
