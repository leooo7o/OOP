#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI4Type22");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Datatype t;
    int n = size - 1;
    MPI_Type_contiguous(n, MPI_DOUBLE, &t);
    MPI_Type_commit(&t);
    if(rank==0)
    {
        double *received=new double[n * n];
        for (int i = 1; i < size; ++i)
        {
            MPI_Recv(received + (i - 1) * n, 1, t, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                pt << received[j * n + i];
            }
        }
    }
    else
    {
        double *nums=new double[n];
        for (int i = 0; i < n; ++i)
        {
            pt >> nums[i];
        }
        MPI_Send(nums, 1, t, 0, 0, MPI_COMM_WORLD);
    }
}
