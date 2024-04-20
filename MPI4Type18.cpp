#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI4Type18");
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
        int count;
        MPI_Probe(0, 0, MPI_COMM_WORLD, &s);
        MPI_Get_count(&s, MPI_INT, &count);
        int *nums=new int[count];
        MPI_Recv(nums, count, MPI_INT, 0, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        for (int i = 0; i < count; i++)
        {
            pt << nums[i];
        }
    }
    else 
    {
        int n;
        pt >> n;
        int num = n * n * (size - 1);
        int *nums=new int[num];
        for (int i = 0; i < num; i++)
        {
            pt >> nums[i];
        }
        for (int i = 1;i<size;i++)
        {
            MPI_Datatype mattrix;
            int *lengths=new int[n];
            int* dipls = new int[n];
            for (int j = 0; j < n; j++)
            {
                lengths[j] = j + 1;
            }
            for (int j = 0; j < n; j++)
            { 
                dipls[j] = ((i - 1) / 3) * n * n * 3 + ((i - 1) % 3) * n + 3 * n * j;
            }
            MPI_Type_indexed(n, lengths, dipls, MPI_INT, &mattrix);
            MPI_Type_commit(&mattrix);
            MPI_Send(nums, 1, mattrix, i, 0, MPI_COMM_WORLD);
        }
    }
}
