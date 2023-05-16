# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.22.1)

set(PROPERTIES BUILD_TESTING OFF)
set(BUILD_DOCS OFF)
set(BUILD_EXAMPLES OFF)
set(BUILD_TESTS OFF)
set(OPENCL_SDK_BUILD_SAMPLES OFF)
set(OPENCL_SDK_TEST_SAMPLES OFF)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("OpenCL_project")
#add_subdirectory(OpenCL_info)
add_subdirectory(OpenCL-SDK)




add_executable (OpenCL_project "main.cpp")
target_link_libraries(OpenCL_project PUBLIC OpenCL::OpenCL OpenCL::HeadersCpp)
