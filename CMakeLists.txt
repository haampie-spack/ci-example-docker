cmake_minimum_required(VERSION 3.17.0)

project(MyPkg LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

option(MYPKG_USE_CUDA "Enable CUDA support" OFF)
option(MYPKG_USE_MPI  "Enable MPI support" OFF)
option(MYPKG_BUILD_SHARED "Build shared library" ON)

include(GNUInstallDirs)

if (MYPKG_BUILD_SHARED)
    set(MYPKG_LIBRARY_TYPE SHARED)
else ()
    set(MYPKG_LIBRARY_TYPE STATIC)
endif ()

if (MYPKG_USE_CUDA)
    find_package(CUDAToolkit REQUIRED)
endif ()

if (MYPKG_USE_MPI)
    find_package(MPI REQUIRED)
endif ()

add_subdirectory(src)
add_subdirectory(apps)

if (MYPKG_BUILD_TESTS)
    include(CTest)
    add_subdirectory(test)
endif ()

## install

include(CMakePackageConfigHelpers)

configure_package_config_file(MyPkgConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/MyPkgConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/MyPkg/cmake
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/MyPkgConfigVersion.cmake
    VERSION 1.2.3
    COMPATIBILITY SameMajorVersion)

install(TARGETS mypkg
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        EXPORT mypkg)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/mypkg
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/MyPkgConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/MyPkgConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake )

install(EXPORT mypkg
        FILE MyPkgTargets.cmake
        NAMESPACE mypkg::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake)