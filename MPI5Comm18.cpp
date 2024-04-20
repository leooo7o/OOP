#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI5Comm18");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm comm;
    int dims[] = { size / 3, 3 };
    int periods[] = { 0, 0 };
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 1, &comm);
    MPI_Comm comm2;
    int dims2[] = { 1, 0 };
    MPI_Cart_sub(comm, dims2, &comm2);
    MPI_Comm_size(comm2, &size);
    MPI_Comm_rank(comm2, &rank);
    int xy[2];
    MPI_Cart_coords(comm, rank, 2, xy);
    int a;
    int * b = new int[size];
    if (rank == 0)
    {
        for (int i = 0; i < size; i++)
            pt >> b[i];
    }
    MPI_Scatter(b, 1, MPI_INT, &a, 1, MPI_INT, 0, comm2);
    pt << a;
}
