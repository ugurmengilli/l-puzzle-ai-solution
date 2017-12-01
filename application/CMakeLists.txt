cmake_minimum_required(VERSION 2.8.11)

project(me586th1ugurmengilli)

# Get the application files
file(GLOB PROJECT_FILES "*.h"
						"*.cpp"
						${UI_HEADERS})


set(CMAKE_INCLUDE_CURRENT_DIR ON)		# Find includes in corresponding build directories
set(CMAKE_AUTOMOC ON)					# Instruct CMake to run moc automatically when needed.

# Packages included in project
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${libAIalgorithms_INCLUDE_DIRS})
add_definitions(${libAIalgorithms_DEFINITIONS})		# Add definitions of subprojects projects

file(GLOB UI_FILES "*.ui")
qt5_wrap_ui(UI_HEADERS ${UI_FILES})
set(PROJECT_FILES ${UI_FILES} ${PROJECT_FILES})

# Output executable
add_executable(${PROJECT_NAME} ${PROJECT_FILES})

# Link agaist Qt libraries
target_link_libraries(${PROJECT_NAME} 
						Qt5::Core 
						Qt5::Gui
						Qt5::Widgets
						libAIalgorithms)