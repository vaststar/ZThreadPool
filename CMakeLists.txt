cmake_minimum_required(VERSION 3.1)

project(testUtil)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    message(STATUS "build ThreadPool with Debug mode")
    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/install/Debug)
else()
    message(STATUS "build ThreadPool with Release mode")
    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_LIST_DIR}/install/Release)
endif()

set(CMAKE_MACOSX_RPATH OFF)

add_subdirectory(MasterLog)
add_subdirectory(ThreadPool)

#build exe
add_executable(${PROJECT_NAME}  main.cpp)
target_link_libraries(${PROJECT_NAME}  PRIVATE ThreadPool MasterLog)

install(TARGETS ${PROJECT_NAME} 
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION bin
		ARCHIVE DESTINATION lib)

enable_testing()