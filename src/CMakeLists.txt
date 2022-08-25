cmake_minimum_required(VERSION 3.21)
project(letcode_Reverse_Nodes_in_k_Group)

set(CMAKE_CXX_STANDARD 14)

add_executable(letcode_Reverse_Nodes_in_k_Group main.cpp ${MY_INCLUDE_DIR}/listnode.h listnode.cpp)

link_libraries(letcode_Reverse_Nodes_in_k_Group PRIVATE ${MY_INCLUDE_DIR})