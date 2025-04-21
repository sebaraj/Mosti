#add_subdirectory(emulator)
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(Mosti STATIC ${LIB_SOURCES})

target_include_directories(Mosti
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)