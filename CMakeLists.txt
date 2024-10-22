cmake_minimum_required(VERSION 3.10)
project(Syncio VERSION 1.0.0 LANGUAGES C CXX)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

set(SOURCES
    src/syncio.c
)

if(WIN32)
    add_library(sync STATIC ${SOURCES})
    set_target_properties(sync PROPERTIES OUTPUT_NAME "sync")
elseif(UNIX)
    add_library(sync SHARED ${SOURCES})
    set_target_properties(sync PROPERTIES OUTPUT_NAME "sync")
endif()

target_include_directories(sync PUBLIC include)

install(TARGETS sync
        EXPORT SyncioTargets
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/
            DESTINATION include/Syncio  # Create a Syncio directory for headers
            FILES_MATCHING PATTERN "*.h"  # Adjust if you have different header file extensions
            PATTERN "*.hpp" EXCLUDE)  # Exclude if you want to filter certain types
