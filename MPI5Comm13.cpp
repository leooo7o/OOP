#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI5Comm13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n;
    if (rank == 0)
    {
        pt >> n;
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Comm comm;
    int dims[] = { n, size / n };
    int periods[] = { 0, 0 };
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 0, &comm);
    int xy[2];
    int n_rank;
    MPI_Comm_rank(comm, &n_rank);
    MPI_Cart_coords(comm, n_rank, 2, xy);
    pt << xy[0];
    pt << xy[1];
}
