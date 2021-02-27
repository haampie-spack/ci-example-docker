add_executable(tests_unit tests_unit.cpp)
target_link_libraries(tests_unit mypkg)
add_test(NAME tests_unit COMMAND tests_unit)

if (MYPKG_USE_MPI)
    add_executable(test_mpi tests_mpi.cpp)
    target_link_libraries(test_mpi mypkg)
    add_test(NAME test_mpi COMMAND mpiexec -np 2 $<TARGET_FILE:test_mpi>)
endif ()