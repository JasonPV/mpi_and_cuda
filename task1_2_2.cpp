#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char** argv)
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;
	int msg = 1;

	if (!rank)
	{
		for (int r = 1; r < size; r++)
			MPI_Send(&msg, 1, MPI_INT, r, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Recv(&msg, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		cout << "rank " << rank << " get msg from 0: " << msg << endl;

	}
	MPI_Finalize();
	return 0;
}