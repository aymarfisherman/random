workspace "Workspace"
	configurations {"Debug", "Release"}
	location "./build"
    
    common_deps_dir = "D:/workspace/common_deps/"
    reps_dir = "D:/workspace/"

	includedirs {
        common_deps_dir .. "boost_1_64_0",
        common_deps_dir .. "googletest/googletest/include",
		common_deps_dir .. "googletest/googlemock/include",
        reps_dir .. "gtest_wrapper/include",
	}
	
	libdirs {
        common_deps_dir .. "boost_1_64_0/stage/lib",
		common_deps_dir .. "googletest/lib",
	}
    
    filter "configurations:Debug"
		targetsuffix "_d"
		defines {"DEBUG", "_DEBUG", "_CRT_SECURE_NO_WARNINGS", "_SCL_SECURE_NO_WARNINGS", "MSVC_IMPLICIT_LINK"}
		flags {"Symbols", "Unicode"}
		
	filter "configurations:Release"        
		defines {"NDEBUG", "_CRT_SECURE_NO_WARNINGS", "_SCL_SECURE_NO_WARNINGS", "MSVC_IMPLICIT_LINK"}
		flags {"Unicode"}
		optimize "On"

project "Random"
	kind "StaticLib"
	targetdir "./lib"
	
	includedirs {
		"./include",
	}
	
	files {
		"./include/**.h",
		"./src/**.cpp",
	}
	
project "RandomTest"
	kind "ConsoleApp"
	targetdir "./bin"
	
	includedirs {
		"./include",
	}	
	
	files {
		"./tests/main.cpp",
	}
	
	links {
		"Random",
	}