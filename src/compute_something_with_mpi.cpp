#include <mypkg/mypkg.hpp>

#if defined(MYPKG_USE_MPI)
#include <mpi.h>
#include <iostream>

double compute_something() {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (world_size != 2) {
        std::cerr << "World size must be two!\n";
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    double value = world_rank == 0 ? 0.0 : 1.0;

    if (world_rank == 0) {
        MPI_Send(&value, 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        std::cout << "Sending " << value << " to proc 1\n";
    } else {
        MPI_Recv(&value, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Received " << value << '\n';
    }

    MPI_Finalize();

    return value;
}

#else

double compute_something() { return 0.0; }

#endif