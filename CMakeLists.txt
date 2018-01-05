cmake_minimum_required(VERSION 3.8)
project(DLL-Bin-Compat-CPP-Interface)

option(WANNABECOM "Wanna be COM" OFF)
option(WANNABECOM_INLINE_DESTRUCTOR "Use inlined destructor for IUnknown interface" OFF)

if(WANNABECOM)
	add_definitions(-DWANNABECOM)
	
	if(WANNABECOM_INLINE_DESTRUCTOR)
		add_definitions(-DWANNABECOM_INLINE_DESTRUCTOR)
	endif()
endif()

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(app)
add_subdirectory(lib)