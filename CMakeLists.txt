cmake_minimum_required(VERSION 3.5)
project(pvr.filmon)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR})

find_package(Kodi REQUIRED)
find_package(p8-platform REQUIRED)
find_package(JsonCpp REQUIRED)

include_directories(${p8-platform_INCLUDE_DIRS}
                    ${JSONCPP_INCLUDE_DIRS}
                    ${KODI_INCLUDE_DIR})

set(DEPLIBS ${p8-platform_LIBRARIES} ${JSONCPP_LIBRARIES})

set(FILMON_SOURCES src/client.cpp
                   src/FilmonAPI.cpp
                   src/PVRFilmonData.cpp
                   src/md5.cpp)

set(FILMON_HEADERS src/client.h
                   src/FilmonAPI.h
                   src/md5.h
                   src/PVRFilmonData.h)

build_addon(pvr.filmon FILMON DEPLIBS)

include(CPack)
