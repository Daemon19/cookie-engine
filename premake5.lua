workspace "cookie-engine"
    configurations {"Debug", "Release"}
    location "build"

project "cookie_engine"
    kind "StaticLib"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"

    includedirs {"include"}
    links {"SDL2main", "SDL2"}
    files {"include/**.h", "src/**.cc"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"