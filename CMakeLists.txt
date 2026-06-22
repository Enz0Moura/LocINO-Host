cmake_minimum_required(VERSION 3.20)

project(my_project LANGUAGES CXX)

add_subdirectory(external/LoRaLibrary/libs/locino_host)

add_executable(my_app
    src/sender.cpp
)

target_link_libraries(my_app PRIVATE
    locino_host
)