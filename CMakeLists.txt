cmake_minimum_required(VERSION 3.31)
project(charm++ CXX)

set(WARNINGS -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)

add_library(charm++cpp libcharm++go.h)
target_compile_features(charm++cpp PUBLIC cxx_std_23)
target_compile_options(charm++cpp PRIVATE ${WARNINGS})
target_include_directories(charm++cpp
	SYSTEM PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
	               src/go
)
target_sources(charm++cpp
	PUBLIC FILE_SET CXX_MODULES
	       FILES src/charm.cpp

	             # Public API
	             src/go.cpp
	             src/key.cpp
	             src/logging.cpp
	             src/tea.cpp
	             src/utils.cpp

	             # Implementation details
	             src/detail/go.cpp
	             src/detail/interop.cpp
	             src/detail/utils.cpp
)

add_custom_command(
	OUTPUT libcharm++go.h
	       libcharm++go.so
	COMMAND go build -o ${CMAKE_CURRENT_BINARY_DIR}/libcharm++go.so -buildmode=c-shared
	MAIN_DEPENDENCY src/go/main.go
	DEPENDS src/go/go.mod
	        src/go/go.sum
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/go
	CODEGEN
)

add_library(charm++go SHARED IMPORTED)
set_target_properties(charm++go
	PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/libcharm++go.so
)
target_link_libraries(charm++go INTERFACE charm++cpp)

add_library(charm++ INTERFACE)
target_link_libraries(charm++ INTERFACE charm++go)

add_executable(simple examples/simple/main.cpp)
target_link_libraries(simple charm++)
