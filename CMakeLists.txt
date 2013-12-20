project(rise CXX)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS -std=c++11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBXML++ REQUIRED libxml++-2.6)

include_directories(${CMAKE_SOURCE_DIR} ${LIBXML++_INCLUDE_DIRS})

file(GLOB SOURCE ${PROJECT_NAME}/*.cpp)
add_library(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} ${LIBXML++_LIBRARIES})
