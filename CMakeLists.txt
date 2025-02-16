cmake_minimum_required(VERSION 3.10)

# Set the project name
project(YapyapLife)

# Find Ogre
set(CMAKE_PREFIX_PATH="/usr/include/OGRE/") # Remplacez par le chemin correct vers votre installation d'Ogre
find_package(OGRE REQUIRED)

# Add the executable
add_executable(YapyapLife main.cpp)

# Include Ogre directories
include_directories(${OGRE_INCLUDE_DIRS})

# Link Ogre libraries
target_link_libraries(YapyapLife ${OGRE_LIBRARIES})

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
