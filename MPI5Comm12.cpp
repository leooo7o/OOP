#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI5Comm12");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n;
    pt >> n;
    MPI_Comm new_comm;
    MPI_Comm_split(MPI_COMM_WORLD, n, 2, &new_comm);
    int nc_size;
    int nc_rank;
    MPI_Comm_size(new_comm, &nc_size);
    MPI_Comm_rank(new_comm, &nc_rank);
    double a;
    pt >> a;
    double result;
    if (n == 1)
    {
        for (int i = 0; i < nc_size; i++)
        {
            MPI_Reduce(&a, &result, 1, MPI_DOUBLE, MPI_MIN, i, new_comm);
        }
        pt << result;
    }
    else
    {
        for (int i = 0; i < nc_size; i++)
        {
            MPI_Reduce(&a, &result, 1, MPI_DOUBLE, MPI_MAX, i, new_comm);
        }
        pt << result;
    }
}
