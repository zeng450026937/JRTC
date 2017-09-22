cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME "LibIDN")

project(${PROJECT_NAME})

message(STATUS "Configuring ${PROJECT_NAME}")

include(CheckFunctionExists)
check_function_exists(strcasecmp HAVE_STRCASECMP)
check_function_exists(strncasecmp HAVE_STRNCASECMP)
check_function_exists(stricmp HAVE_STRICMP)
check_function_exists(strnicmp HAVE_STRNICMP)
check_function_exists(memmove HAVE_MEMMOVE)

if(NOT HAVE_STRCASECMP)
	if(NOT HAVE_STRICMP)
		message(FATAL_ERROR "Error: Cannot find strcasecmp() or stricmp()")
		exit()
	endif()
endif()
		
if(NOT HAVE_STRNCASECMP)
	if(NOT HAVE_STRNICMP)
		message(FATAL_ERROR "Error: Cannot find strncasecmp() or strnicmp()")
		exit()
	endif()
endif()

include_directories(
	src
	stubs
	src/gl
)

if(WIN32)
	include_directories(stubs/win32)
	if(MSVC_VERSION VERSION_LESS 1400)
		include_directories(stubs/win32/stdbool)
	endif()
	if(MSVC_VERSION VERSION_EQUAL 1500)
		include_directories(stubs/win32/VC2008)
	endif()
endif()

set(SRC
	"src/stringprep.c"
	"src/profiles.c"
	"src/rfc3454.c"
	"src/punycode.c"
	"src/idna.c"
	"src/toutf8.c"
	"src/nfkc.c"
	"src/gl/c-ctype.c"
	"src/gl/c-strcasecmp.c"
	"src/gl/c-strncasecmp.c"
	"src/gl/unistr/u8-check.c"
)

add_library(${PROJECT_NAME} OBJECT ${SRC})

target_compile_definitions(${PROJECT_NAME} INTERFACE HAVE_LIBIDN)
target_compile_definitions(${PROJECT_NAME} PRIVATE LIBIDN_STATIC HAVE_CONFIG_H)

if( NOT HAVE_STRCASECMP )
	if(HAVE_STRICMP)
		target_compile_definitions(${PROJECT_NAME} PRIVATE strcasecmp=stricmp)
	endif()
endif()

if( NOT HAVE_STRNCASECMP )
	if(HAVE_STRNICMP)
		target_compile_definitions(${PROJECT_NAME} PRIVATE strncasecmp=strnicmp)
	endif()
endif()
	
	
	