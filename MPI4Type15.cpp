#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI4Type15");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank != 0)
    {
        MPI_Status s;
        MPI_Probe(0, 1, MPI_COMM_WORLD, &s);
        int x;
        MPI_Get_count(&s, MPI_INT, &x);
        double* a = new double[x];
        MPI_Recv(a, size-1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, &s);
        for (int i = 0; i < size-1; i++)
        {
            pt << a[i];
        }
    }
    else
    {
        double* nums = new double[(size-1) * (size-1)];
        for (int i = 0; i < (size - 1) * (size - 1); i++)
        {
            pt >> nums[i];
        }
        MPI_Datatype t;
        int double_sz;
        MPI_Type_size(MPI_DOUBLE, &double_sz);
        MPI_Type_create_resized(MPI_DOUBLE, 0, (size - 1) * double_sz, &t);
        MPI_Type_commit(&t);
        for (int i = 1; i < size; i++) {
            MPI_Send(&nums[i - 1], size - 1, t, i, 1, MPI_COMM_WORLD);
        }
    }
}
