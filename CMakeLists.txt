CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT(game-of-life)

# All directories
INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(third-party)

# Creates a list called SRC
# with all the .cpp files from within the src folder
file(GLOB_RECURSE SRC src/*.cpp)

# Removes the file containing the main function declaration
# from the list of .cpp files
list(REMOVE_ITEM SRC "src/game-of-life-main.cpp")

# Creates a list called INCLUDE
# with all the .h files inside the include folder
file(GLOB_RECURSE INCLUDE include/*.h)

# Adds all .h and .cpp to the core library

ADD_LIBRARY(core ${INCLUDE} ${SRC})

# Adds .cpp with the main function to the boilerplate
ADD_EXECUTABLE(game-of-life src/game-of-life-main.cpp)

# Links the library (core) to the executable (game-of-life)
TARGET_LINK_LIBRARIES(game-of-life core)

enable_testing()

add_subdirectory(third-party/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# Create a list called TEST
# with all the .cpp files from inside the test folder
file(GLOB_RECURSE TEST test/*.cpp)

#ADD_EXECUTABLE(tests ${TEST})

# Links all necessary libraries
# to the executable (test), including the library
#(core) to be tested
#target_link_libraries(tests
#        pthread
#        gtest
#        gtest_main
 #      core)

# Release x debug build# 
#The -Werror tag forces warning as a compilation error
# The -Wall and -Wextra tags force more things to be reported as warnings
# The -o2 tag in the release build optimizes the code
# The -g tag in the non-release build enables the debugging code
IF(RELEASE)
    SET(CMAKE_CXX_FLAGS "-Wall -Werror -o2 -std=c++17")
ELSE()
    SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++17")
ENDIF()