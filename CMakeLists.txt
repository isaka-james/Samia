cmake_minimum_required(VERSION 3.10)

# Project Name
project(Samia)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source Files
set(SOURCES
    src/main.cpp
    src/server/http3_server.cpp
    src/utils/logger.cpp
    src/utils/config.cpp
)

# Executable
add_executable(Samia ${SOURCES})

# Link Libraries (e.g., OpenSSL, nghttp3)
find_package(OpenSSL REQUIRED)
target_link_libraries(Samia OpenSSL::SSL OpenSSL::Crypto)
