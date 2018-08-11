cmake_minimum_required(VERSION 3.5.1)
project(EventManager)

# Define Custom Variable.
# Force norme C++
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PROJECT_SRC_DIR src)
set(PROJECT_INC_DIR inc)
set(PROJECT_TEST_DIR test)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Create code from a list of Qt designer ui files.
set(CMAKE_AUTOUIC ON) # use this if you have CMake 3.x instead of the following

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# CMake compilation option
set(CMAKE_CXX_FLAGS ${GCC_C_NORME})

# Find the QtWidgets library
find_package(Qt5 COMPONENTS Widgets Core Test REQUIRED)

include_directories(${PROJECT_INC_DIR})

file(GLOB_RECURSE CPP_LIST "${PROJECT_SRC_DIR}/*.cpp")
file(GLOB_RECURSE H_LIST "${PROJECT_INC_DIR}/*.h")
file(GLOB_RECURSE TEST_LIST "${PROJECT_TEST_DIR}/*.cpp")
file(GLOB_RECURSE TEST_H "${PROJECT_TEST_DIR}/*.h")
set(PRINCIPAL_MAIN main.cpp)
# Tell CMake to create the event manager executable
add_executable(eventmanager ${PRINCIPAL_MAIN} ${CPP_LIST} ${H_LIST})

# Tell CMake to create the event manager test executable
add_executable(test_eventmanager ${TEST_LIST} ${TEST_H} ${CPP_LIST} ${H_LIST})
# Check norme of  C++
target_compile_features(eventmanager PUBLIC cxx_nullptr)

# Use the Widgets module from Qt 5.
if (Qt5_FOUND)
	target_link_libraries(eventmanager Qt5::Core Qt5::Widgets )
        target_link_libraries(test_eventmanager Qt5::Core Qt5::Widgets Qt5::Test)
else ()
	message(FATAL_ERROR "Qt5 not found")
endif()

# launch Test
add_test(name test_eventmanager command test_eventmanager)

# Install the executable
install(TARGETS eventmanager DESTINATION bin)
