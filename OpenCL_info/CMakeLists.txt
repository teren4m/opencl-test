# CMakeList.txt : CMake project for TestCMake, include source and define
# project specific logic here.
#

# Add source to this project's executable.
#add_executable (TestCMake "TestCMake.cpp" "TestCMake.h")

add_library(OpenCL_info STATIC   "include/TestCMake.h" "src/TestCMake.cpp")
target_include_directories(OpenCL_info PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(OpenCL REQUIRED)
target_link_libraries(OpenCL_info OpenCL::OpenCL)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/cl
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OpenCL_info PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
