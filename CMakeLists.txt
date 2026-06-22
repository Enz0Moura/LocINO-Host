cmake_minimum_required(VERSION 3.20)

project(my_project LANGUAGES CXX)

add_subdirectory(external/LoRaLibrary/libs/locino_host)

add_executable(sender
    src/sender.cpp
)

add_executable( receiver
    src/receiver.cpp

)

target_link_libraries(sender PRIVATE
    locino_host
)

target_link_libraries(receiver PRIVATE
    locino_host
)