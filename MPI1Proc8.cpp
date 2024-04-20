#include "pt4.h"
#include "mpi.h"
#include <vector>
using namespace std;
void Solve()
{
    Task("MPI1Proc8");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int n;
    float x, sum = 0;
    pt >> n;
    for (int i = 0; i < n; i++)
    {
        pt >> x;
        sum += x;
    }
    if (rank % 2 == 0)
        pt << sum;
    else
        pt << sum / n / 1.0;
}
