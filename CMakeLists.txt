cmake_minimum_required(VERSION 3.1.0)
project(ipa325_wsg50)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost
    REQUIRED COMPONENTS
    system
)

include_directories(
  include
  ${Boost_INCLUDE_DIRS}
)

add_executable(wsg_test
    src/test.cpp
    src/WSG50Subject.cpp
    src/WSG50Controller.cpp
    src/WSG50Communicator.cpp
)

target_link_libraries(wsg_test
  pthread
  rt
  ${Boost_LIBRARIES}
)
