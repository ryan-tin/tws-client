add_executable(main main.cpp)
# TEST:
target_include_directories(
  main
  PUBLIC ${CMAKE_SOURCE_DIR}/include
  PRIVATE $<BUILD_INTERFACE:/usr/local/include/twsapi>)

set_target_properties(main PROPERTIES BUILD_RPATH "/usr/local/lib/"
                                      INSTALL_RPATH "lib/")

# TEST: Does it work without linking twsapi and threads?
target_link_libraries(main PUBLIC client)

# find_library(TWSAPI twsapid REQUIRED)
# message(TWSAPI_FOUND)
# target_link_libraries(main PUBLIC ${TWSAPI})
find_package(Threads REQUIRED)
target_link_libraries(main PUBLIC Threads::Threads)

include(CMakePrintHelpers)
# TODO:
message("external dependencies: ${client_LIBS}")
cmake_print_properties(TARGETS main PROPERTIES INCLUDE_DIRECTORIES)
