workspace "cookie-engine"
    configurations {"Release", "Debug"}
    language "C++"
    links {"SDL2", "SDL2_image"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"

project "cookie_engine"
    kind "StaticLib"
    targetdir "bin/%{cfg.buildcfg}"
    location "build"

    includedirs {"include/cookie"}
    files {"include/**.h", "src/**.cc"}

project "cookie_engine_test"
    kind "WindowedApp"
    targetdir "test/bin/%{cfg.buildcfg}"
    location "test/build"

    includedirs {"include"}
    links {"SDL2main", "cookie_engine"}
    files {"test/**.h", "test/**.cc"}