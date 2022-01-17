workspace "cookie-engine"
    configurations {"Debug", "Release"}
    language "C++"
    links {"SDL2main", "SDL2"}

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
    kind "ConsoleApp"
    targetdir "test/bin/%{cfg.buildcfg}"
    location "test/build"

    includedirs {"include"}
    links {"cookie_engine"}
    files {"test/**.h", "test/**.cc"}