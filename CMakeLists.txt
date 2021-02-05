cmake_minimum_required(VERSION 3.16)
project(proj)

set(CMAKE_CXX_STANDARD 11)

add_executable(proj main.cpp)
add_executable(hospital Hospital.cpp)
add_executable(healthcenter Healthcenter.cpp)
add_executable(hosA HospitalA.cpp)
add_executable(hosB HospitalB.cpp)
add_executable(hosC HospitalC.cpp)