#include "pt4.h"
#include "mpi.h"

void Solve()
{
    Task("MPI5Comm2");
    int flag;
    MPI_Initialized(&flag);
    if (flag == 0)
        return;
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int n = size / 2;
	int* even = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		even[i] = 2 * i;
	}
	MPI_Group group_all, group_odd;
	MPI_Comm_group(MPI_COMM_WORLD, &group_all);
	if (size % 2 == 1) {
		MPI_Group_excl(group_all, n+1, even, &group_odd);
	}
	else {
		MPI_Group_excl(group_all, n, even, &group_odd);
	}
	MPI_Comm comm_odd;
	MPI_Comm_create(MPI_COMM_WORLD, group_odd, &comm_odd);

	int odd_rank = -1, odd_size = -1;

	if (MPI_COMM_NULL != comm_odd) {
		MPI_Comm_rank(comm_odd, &odd_rank);
		MPI_Comm_size(comm_odd, &odd_size);
		double* rBuf = new double[odd_size * 2];
		double* sBuf = new double[2];
		int* sCount = new int[odd_size];
		int* rCount = new int[odd_size];
		int* rs = new int[odd_size];
		int* ss = new int[odd_size];
		for (int i = 0; i < odd_size; i++) {
			sCount[i] = 2;
			rCount[i] = 2;
			rs[i] = i * 2;
			ss[i] = 0;
		}

		for (int i = 0; i < 2; i++) {
			pt >> sBuf[i];
		}
		MPI_Alltoallv(sBuf, sCount, ss, MPI_DOUBLE, rBuf, rCount, rs, MPI_DOUBLE, comm_odd);
		for (int i = 0; i < odd_size * 2; i++) {
			pt << rBuf[i];
		}
	}
}
