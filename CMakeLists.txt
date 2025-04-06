cmake_minimum_required(VERSION 3.29)
project(OOPUzduotis1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

# Include directories
include_directories(
    common
    src/abstract
    src/models
    src/repositories/abstract
    src/repositories/contracts
    src/services/abstract
    src/services/usecases
    src/tests/abstract
)

# Source files
set(SOURCES
    src/main.cpp
    src/students-data-sort-runner.cpp
    src/repositories/input-manager-repository.cpp
    src/repositories/students-vector-repository.cpp
    src/repositories/students-list-repository.cpp
    src/repositories/students-deque-repository.cpp
    src/services/create-students-automatically-service.cpp
    src/services/generate-students-by-hand-service.cpp
    src/services/generate-students-to-file-service.cpp
    src/services/get-user-input-service.cpp
    src/services/print-students-to-console-service.cpp
    src/services/print-students-to-file-service.cpp
    src/services/save-students-data-from-file-service.cpp
    src/services/sort-students-service.cpp
    src/services/sort-students-to-bad-and-good-service.cpp
    src/services/sort-students-to-bad-and-good-strategy-2-service.cpp
    src/tests/tests-controller.cpp
    src/tests/module-test.cpp
    src/tests/generate-file-duration-test.cpp
    src/tests/input-duration-test.cpp
)

# Add executable
add_executable(OOPUzduotis2 ${SOURCES})
