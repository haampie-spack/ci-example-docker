add_executable(main main.cpp)

target_link_libraries(main mypkg)

install(TARGETS main
        DESTINATION ${CMAKE_INSTALL_BINDIR})