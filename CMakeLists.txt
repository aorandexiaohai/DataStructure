
cmake_minimum_required(VERSION 3.10)
project(DataStructure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17") 

file(GLOB_RECURSE FILES  ${CMAKE_SOURCE_DIR} "*.cpp")
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR} "*.h")

FUNCTION (EXCLUDE_FILES_FROM_DIR_IN_LIST _InFileList _verbose)

  foreach (ITR ${_InFileList})

    if ("${_verbose}")

      message(STATUS "ITR=${ITR}")

    endif ("${_verbose}")



    #if ("${ITR}" MATCHES "(.*)/log/(.*)" OR "${ITR}" MATCHES "(.*)/process_init/(.*)")                   # Check if the item matches the directory name in _excludeDirName
    if ("${ITR}" MATCHES "(.*)/XTUtils/test.cpp")
      message(STATUS "Remove Item from List:${ITR}")

      list (REMOVE_ITEM _InFileList ${ITR})                              # Remove the item from the list

    endif ()



  endforeach(ITR)



  #Function return value

  set(SOURCE_FILES ${_InFileList} PARENT_SCOPE)                          # Return the SOURCE_FILES variable to the calling parent

ENDFUNCTION (EXCLUDE_FILES_FROM_DIR_IN_LIST)



#correct for vs2017

EXCLUDE_FILES_FROM_DIR_IN_LIST("${FILES}" FALSE)



set(FILES ${SOURCE_FILES})

message(${FILES})
message(${HEADERS})

include_directories(
    LinkedList
)

include_directories(
    ParamaterParse
)
include_directories(
    Queue
)
include_directories(
    Stack
)
include_directories(
    Tree
)

include_directories(
    XTUtils
)
include_directories(
    ColorConsole
)

add_executable(
    test_main
    ${FILES}
    ${HEADERS}
)