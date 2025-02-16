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
	             src/commands.cpp
	             src/focus.cpp
	             src/go.cpp
	             src/key.cpp
	             src/logging.cpp
	             src/mouse.cpp
	             src/options.cpp
	             src/screen.cpp
	             src/standard_renderer.cpp
	             src/tea.cpp
	             src/utils.cpp

	             # Implementation details
	             src/detail/go.cpp
	             src/detail/interop.cpp
	             src/detail/key.cpp
	             src/detail/mouse.cpp
	             src/detail/standard_renderer.cpp
	             src/detail/utils.cpp
)

add_custom_command(
	OUTPUT libcharm++go.h
	       libcharm++go.so
	COMMAND go build -o ${CMAKE_CURRENT_BINARY_DIR}/libcharm++go.so -buildmode=c-shared
	MAIN_DEPENDENCY src/go/main.go
	DEPENDS src/go/go.mod
	        src/go/go.sum
	        src/go/commands.go
	        src/go/goobject.go
	        src/go/interop.go
	        src/go/interop.h
	        src/go/logging.go
	        src/go/main.go
	        src/go/model.go
	        src/go/mouse.go
	        src/go/options.go
	        src/go/tea.go
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

add_executable(focus-blur examples/focus-blur/main.cpp)
target_link_libraries(focus-blur charm++)

add_executable(debounce examples/debounce/main.cpp)
target_link_libraries(debounce charm++)

add_executable(fullscreen examples/fullscreen/main.cpp)
target_link_libraries(fullscreen charm++)

add_executable(mouse examples/mouse/main.cpp)
target_link_libraries(mouse charm++)

add_executable(result examples/result/main.cpp)
target_link_libraries(result charm++)

add_executable(simple examples/simple/main.cpp)
target_link_libraries(simple charm++)

add_executable(suspend examples/suspend/main.cpp)
target_link_libraries(suspend charm++)

add_executable(window-size examples/window-size/main.cpp)
target_link_libraries(window-size charm++)
