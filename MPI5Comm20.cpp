#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI5Comm20");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm comm;
    int dims[] = { 2, 2, size / 4 }, periods[] = { 0, 0 },dims2[] = { 1, 1, 0 };;
    MPI_Cart_create(MPI_COMM_WORLD, 3, dims, periods, 0, &comm);
    MPI_Comm comm_sub;
    MPI_Cart_sub(comm,dims2, &comm_sub);
    MPI_Comm_size(comm_sub, &size);
    MPI_Comm_rank(comm_sub, &rank);
    int a, * b = new int[size];
    pt >> a;
    MPI_Gather(&a, 1, MPI_INT, b, 1, MPI_INT, 0, comm_sub);
    if (rank == 0)
    {
        for (int i = 0; i < size; i++)
            pt << b[i];
    }
}
