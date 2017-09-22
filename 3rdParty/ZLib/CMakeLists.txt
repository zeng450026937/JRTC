cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME "ZLib")

project(${PROJECT_NAME})

message(STATUS "Configuring ${PROJECT_NAME}")

set(SRC
	"src/adler32.c"
	"src/compress.c"
	"src/crc32.c"
	"src/deflate.c"
	"src/gzio.c"
	"src/infback.c"
	"src/inffast.c"
	"src/inflate.c"
	"src/inftrees.c"
	"src/trees.c"
	"src/uncompr.c"
	"src/zutil.c"
)

add_library(${PROJECT_NAME} OBJECT ${SRC})

target_compile_definitions(${PROJECT_NAME} INTERFACE HAVE_ZLIB)