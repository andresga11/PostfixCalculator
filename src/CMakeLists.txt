cmake_minimum_required(VERSION 3.12) 
project(calc VERSION 1.0.0 LANGUAGES CXX)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wshadow -Wall")

# If not using tests list all source files here
add_executable(${PROJECT_NAME} BigInt.cpp Calculator.cpp Handler.cpp options.cpp AddHandler.cpp MultiplyHandler.cpp ExecuteHandler.cpp PowerHandler.cpp OperandPusher.cpp main.cpp)

# if using tests list all source files except main.cpp here
# add_library(${CMAKE_PROJECT_NAME} 
# )

# Uncomment the next line if you uncommented the add_library block
# target_link_libraries(${PROJECT_NAME} ${CMAKE_PROJECT_NAME})

#target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#)

file(COPY input.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

