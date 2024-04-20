#include "pt4.h"
#include "mpi.h"
void Solve()
{
    Task("MPI4Type13");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    char packbuf[1000];
    int position;
    double a;
    int b;
    if (rank == 0)
    {
        for (int i = 1; i < size; i++)
        {
            position = 0;
            MPI_Recv(packbuf, 100, MPI_PACKED, i, 0, MPI_COMM_WORLD,MPI_STATUSES_IGNORE);
            MPI_Unpack(packbuf, 1, &position, &a, 1, MPI_DOUBLE, MPI_COMM_WORLD);
            pt << a;
            for (int j = 0; j < i; j++)
            {
                MPI_Unpack(packbuf, 1, &position, &b, 1, MPI_INT, MPI_COMM_WORLD);
                pt << b;
            }
        }
    }
    else
    {
        position = 0;
        pt >> a;
        int* bs = new int[rank];
        for (int i = 0; i < rank; i++)
        {
            pt >> bs[i];
        }
        MPI_Pack(&a, 1, MPI_DOUBLE, packbuf, 100, &position, MPI_COMM_WORLD);
        for (int i = 0; i < rank; i++)
        {
            b = bs[i];
            MPI_Pack(&b, 1, MPI_INT, packbuf, 100, &position, MPI_COMM_WORLD);
        }
        MPI_Send(packbuf, position, MPI_PACKED, 0, 0, MPI_COMM_WORLD);
    }
}
