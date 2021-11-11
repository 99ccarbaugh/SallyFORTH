cmake_minimum_required(VERSION 3.17.2)

project(Sally)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} driver1.cpp ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #$(CMAKE_INSTALL_PREFIX}/bin
#install(FILES "driver1.cpp" DESTINATION src)       #$(CMAKE_INSTALL_PREFIX}/src