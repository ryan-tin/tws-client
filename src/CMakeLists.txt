file(GLOB sources CONFIGURE_DEPENDS *.cpp)
add_library(client ${sources})

target_include_directories(
  client
  PUBLIC ${CMAKE_SOURCE_DIR}/include
  PRIVATE
    $<BUILD_INTERFACE:/usr/local/include/twsapi>
)

find_library(TWSAPI twsapid REQUIRED)
message(TWSAPI_FOUND)
target_link_libraries(client PUBLIC ${TWSAPI})

find_package(Threads REQUIRED)
target_link_libraries(client PUBLIC Threads::Threads)
