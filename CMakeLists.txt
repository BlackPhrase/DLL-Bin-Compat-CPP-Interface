cmake_minimum_required(VERSION 3.8)
project(DLL-Bin-Compat-CPP-Interface)

option(WANNABECOM "Wanna be COM" OFF)

if(WANNABECOM)
	add_definitions(-DWANNABECOM)
endif()

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(app)
add_subdirectory(lib)