#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI5Comm23");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int m, n, x, y;
    if (rank == 0)
    {
        pt >> m;
        pt >> n;
    }
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_INT,0,MPI_COMM_WORLD);
    MPI_Comm comm;
    int dims[] = { m, n };
    int periods[] = { 1, 0 };
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 0, &comm);
    if (rank>=m*n) return;
    pt >> x;
    pt >> y;
    int xy[] = { x, y };
    MPI_Comm_set_errhandler(comm, MPI_ERRORS_RETURN);
    int sym = MPI_Cart_rank(comm, xy, &rank);
    if (sym == MPI_SUCCESS)
    {
        pt << rank;
    }
    else pt << -1;
}
