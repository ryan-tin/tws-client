cmake_minimum_required(VERSION 3.15...3.30)

project(TwsClient VERSION 1.0
  DESCRIPTION "Implmenetaion of TWS Client API in c++"
  LANGUAGES CXX OBJCXX
 )

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # generate compile_commands.json
# symlink compile_commands.json
file(CREATE_LINK
  "${CMAKE_BINARY_DIR}/compile_commands.json"
  "${CMAKE_SOURCE_DIR}/compile_commands.json"
  SYMBOLIC
)

# symlink the executable to avoid typing out full path to run from project root
# file(CREATE_LINK
#   "${CMAKE_BINARY_DIR}/src/main"
#   "${CMAKE_SOURCE_DIR}/main"
#   SYMBOLIC
# )

if(CMAKE_BUILD_TYPE STREQUAL "") # No build type passed
  set(MODE "Dev")
  option(PACKAGE_TESTS "build the tests" OFF)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(MODE "Debug")
  option(PACKAGE_TESTS "build the tests" ON)
  add_compile_options(-Wall -Werror -Wextra -Wshadow -Wformat=2 -Wunused -fsanitize=address)
  add_link_options(-fsanitize=address)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(MODE "Release")
endif()
message("MODE is " ${MODE})

add_subdirectory(src)
add_subdirectory(app)

if (PACKAGE_TESTS)
  enable_testing()
  include(GoogleTest)
  add_subdirectory(tests)
endif()

# uninstall target, can run with `cd build; make uninstall` (may need sudo)
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)
  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
