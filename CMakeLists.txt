# cmake arguments
# CMAKE_BUILD_TYPE:			Compilation target (Debug or Release defaults to Debug)
#
# pandemonium-cpp cmake arguments
# PANDEMONIUM_HEADERS_DIR:		This is where the gdnative include folder is (pandemonium_source/modules/gdn/include)
# PANDEMONIUM_CUSTOM_API_FILE:	This is if you have another path for the pandemonium_api.json
#
# Android cmake arguments
# CMAKE_TOOLCHAIN_FILE:		The path to the android cmake toolchain ($ANDROID_NDK/build/cmake/android.toolchain.cmake)
# ANDROID_NDK:				The path to the android ndk root folder
# ANDROID_TOOLCHAIN_NAME:	The android toolchain (arm-linux-androideabi-4.9 or aarch64-linux-android-4.9 or x86-4.9 or x86_64-4.9)
# ANDROID_PLATFORM:			The android platform version (android-23)
# More info here: https://pandemonium.readthedocs.io/en/latest/development/compiling/compiling_for_android.html
#
# Examples
#
# Builds a debug version:
# cmake .
# cmake --build .
#
# Builds a release version with clang
# CC=/usr/bin/clang CXX=/usr/bin/clang++ cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" .
# cmake --build .
#
# Builds an android armeabi-v7a debug version:
# cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake -DANDROID_NDK=$ANDROID_NDK \
#		-DANDROID_TOOLCHAIN_NAME=arm-linux-androideabi-4.9 -DANDROID_PLATFORM=android-23 -DCMAKE_BUILD_TYPE=Debug .
# cmake --build .
#
# Protip
# Generate the buildfiles in a sub directory to not clutter the root directory with build files:
# mkdir build && cd build && cmake -G "Unix Makefiles" .. && cmake --build .
#
# Todo
# Test build for Windows, Mac and mingw.

project(pandemonium-cpp)
cmake_minimum_required(VERSION 3.6)

option(GENERATE_TEMPLATE_GET_NODE "Generate a template version of the Node class's get_node." ON)

# Change the output directory to the bin directory
set(BUILD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BUILD_PATH}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BUILD_PATH}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_PATH}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${BUILD_PATH}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${BUILD_PATH}")

# Default build type is Debug in the SConstruct
if("${CMAKE_BUILD_TYPE}" STREQUAL "")
	set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
	add_definitions(-D_DEBUG)
else()
	add_definitions(-DNDEBUG)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

# Set the c++ standard to c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT DEFINED BITS)
	set(BITS 32)
	if(CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(BITS 64)
	endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
endif()

# Input from user for pandemonium headers and the api file
set(PANDEMONIUM_HEADERS_DIR "pandemonium_headers" CACHE STRING "")
set(PANDEMONIUM_CUSTOM_API_FILE "pandemonium_headers/api.json" CACHE STRING "")

set(PANDEMONIUM_COMPILE_FLAGS )
set(PANDEMONIUM_LINKER_FLAGS )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# using Visual Studio C++
	set(PANDEMONIUM_COMPILE_FLAGS "/EHsc /WX") # /GF /MP

	if(CMAKE_BUILD_TYPE MATCHES Debug)
		set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} /MDd") # /Od /RTC1 /Zi
	else()
		set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} /MD /O2") # /Oy /GL /Gy
		STRING(REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
		string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
	endif(CMAKE_BUILD_TYPE MATCHES Debug)

	# Disable conversion warning, trunkation, unreferenced var, signed missmatch
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} /wd4244 /wd4305 /wd4101 /wd4018 /wd4267")

	# Todo: Check if needed.
	add_definitions(-DWIN32_LEAN_AND_MEAN -D_CRT_SECURE_NO_WARNINGS)

	# Unkomment for warning level 4
	#if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
	#	string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	#endif()

else()  # GCC/Clang
	set(PANDEMONIUM_LINKER_FLAGS "-static-libgcc -static-libstdc++ -Wl,-R,'$$ORIGIN'")

	if(NOT CMAKE_SYSTEM_NAME MATCHES "Windows")
		set(PANDEMONIUM_COMPILE_FLAGS "-fPIC")
	endif()
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -g -Wwrite-strings")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wchar-subscripts -Wcomment -Wdisabled-optimization")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wformat -Wformat=2 -Wformat-security -Wformat-y2k")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wimport -Winit-self -Winline -Winvalid-pch -Werror")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wmissing-braces -Wmissing-format-attribute")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wpointer-arith")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wredundant-decls -Wreturn-type -Wsequence-point")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wswitch -Wswitch-enum -Wtrigraphs")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wuninitialized -Wunknown-pragmas -Wunreachable-code -Wunused-label")
	set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wunused-value -Wvariadic-macros -Wvolatile-register-var -Wno-error=attributes")

	# -Wshadow -Wextra -Wall -Weffc++ -Wfloat-equal -Wstack-protector -Wunused-parameter -Wsign-compare -Wunused-variable -Wcast-align
	# -Wunused-function -Wstrict-aliasing -Wstrict-aliasing=2 -Wmissing-field-initializers

	if(NOT CMAKE_SYSTEM_NAME STREQUAL "Android")
		set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -Wno-ignored-attributes")
	endif()

	if(CMAKE_BUILD_TYPE MATCHES Debug)
		set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -fno-omit-frame-pointer -O0")
	else()
		set(PANDEMONIUM_COMPILE_FLAGS "${PANDEMONIUM_COMPILE_FLAGS} -O3")
	endif(CMAKE_BUILD_TYPE MATCHES Debug)
endif()

# Generate source from the bindings file
find_package(Python3 3.4 REQUIRED) # pathlib should be present
if(GENERATE_TEMPLATE_GET_NODE)
	set(GENERATE_BINDING_PARAMETERS "True")
else()
	set(GENERATE_BINDING_PARAMETERS "False")
endif()

message(STATUS "Generating Bindings")
execute_process(COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.print_file_list(\"${PANDEMONIUM_CUSTOM_API_FILE}\", \"${CMAKE_CURRENT_BINARY_DIR}\", headers=True)"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	RESULT_VARIABLE HEADERS_FILE_LIST_RESULT
	OUTPUT_VARIABLE HEADERS_FILE_LIST
)
set(HEADERS_FILE_LIST ${HEADERS_FILE_LIST})

execute_process(COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.print_file_list(\"${PANDEMONIUM_CUSTOM_API_FILE}\", \"${CMAKE_CURRENT_BINARY_DIR}\", sources=True)"
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	RESULT_VARIABLE SOURCES_FILE_LIST_RESULT
	OUTPUT_VARIABLE SOURCES_FILE_LIST
)
set(SOURCES_FILE_LIST ${SOURCES_FILE_LIST})

add_custom_command(OUTPUT ${HEADERS_FILE_LIST} ${SOURCES_FILE_LIST}
		COMMAND "${Python3_EXECUTABLE}" "-c" "import binding_generator; binding_generator.generate_bindings(\"${PANDEMONIUM_CUSTOM_API_FILE}\", \"${GENERATE_BINDING_PARAMETERS}\", \"${CMAKE_CURRENT_BINARY_DIR}\")"
		VERBATIM
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		MAIN_DEPENDENCY ${PANDEMONIUM_CUSTOM_API_FILE}
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/binding_generator.py
		COMMENT Generating Bindings
)

# Get Sources
file(GLOB_RECURSE SOURCES src/*.c**)
file(GLOB_RECURSE HEADERS include/*.h**)

# Define our pandemonium-cpp library
add_library(${PROJECT_NAME}
		${SOURCES}
		${SOURCES_FILE_LIST}
		${HEADERS}
		${HEADERS_FILE_LIST}
)
target_include_directories(${PROJECT_NAME}
	PUBLIC
	include
	include/core
	${CMAKE_CURRENT_BINARY_DIR}/include/gen/
)

# Put pandemonium headers as SYSTEM PUBLIC to exclude warnings from irrelevant headers
target_include_directories(${PROJECT_NAME}
	SYSTEM PUBLIC
	${PANDEMONIUM_HEADERS_DIR}
)

# Add the compile flags
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS ${PANDEMONIUM_COMPILE_FLAGS})
set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS ${PANDEMONIUM_LINKER_FLAGS})

# Create the correct name (pandemonium.os.build_type.system_bits)

string(TOLOWER "${CMAKE_SYSTEM_NAME}" SYSTEM_NAME)
string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE)

if(ANDROID)
	# Added the android abi after system name
	set(SYSTEM_NAME ${SYSTEM_NAME}.${ANDROID_ABI})
	# Android does not have the bits at the end if you look at the main pandemonium repo build
	set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME "pandemonium-cpp.${SYSTEM_NAME}.${BUILD_TYPE}")
else()
	set_property(TARGET ${PROJECT_NAME} PROPERTY OUTPUT_NAME "pandemonium-cpp.${SYSTEM_NAME}.${BUILD_TYPE}.${BITS}")
endif()
