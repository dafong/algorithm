cmake_minimum_required(VERSION 3.5)
project(test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ReverseLinkedList.cpp)
add_executable(ReverseLinkedList ${SOURCE_FILES})

set(SOURCE_FILES ConstTest.cpp)
add_executable(ConstTest ${SOURCE_FILES})

set(SOURCE_FILES HeapSort.cpp)
add_executable(HeapSort ${SOURCE_FILES})

set(SOURCE_FILES QuickSort.cpp)
add_executable(QuickSort ${SOURCE_FILES})

set(SOURCE_FILES MergeSort.cpp)
add_executable(MergeSort ${SOURCE_FILES})

set(SOURCE_FILES RandomSelect.cpp)
add_executable(RandomSelect ${SOURCE_FILES})

set(SOURCE_FILES BinaryTree.cpp Knapsack.cpp)
add_executable(BinaryTree ${SOURCE_FILES})

set(SOURCE_FILES LIS.cpp)
add_executable(LIS ${SOURCE_FILES})

set(SOURCE_FILES LCS.cpp)
add_executable(LCS ${SOURCE_FILES})

set(SOURCE_FILES CutRob.cpp)
add_executable(CutRob ${SOURCE_FILES})

set(SOURCE_FILES MatrixChainOrder.cpp)
add_executable(MatrixChainOrder.cpp ${SOURCE_FILES})

set(SOURCE_FILES Knapsack.cpp)
add_executable(Knapsack ${SOURCE_FILES})

set(SOURCE_FILES Graph.cpp)
add_executable(Graph ${SOURCE_FILES})