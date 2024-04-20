#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI3Coll26");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n = (size + 3) * size / 2;
    int*sbuf=new int[n];
    for (int i = 0; i < n; i++)
    {
        pt >> sbuf[i];
    }
    int* rbuf = new int[rank+2];
    int* rcounts = new int[size];
    for (int i = 0; i < size; i++)
    {
        rcounts[i] = i + 2;
    }
    MPI_Reduce_scatter(sbuf, rbuf,rcounts,MPI_INT, MPI_MIN, MPI_COMM_WORLD);
    for (int i = 0; i < rank+2; i++)
    {
        pt << rbuf[i];
    }
}
