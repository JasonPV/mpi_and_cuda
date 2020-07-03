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

	for (int id = 0; id < size; id++)
	{
		if (id != rank)
			MPI_Send(&msg, 1, MPI_INT, id, 0, MPI_COMM_WORLD);
	}

	for (int i = 0; i < size - 1; i++)
	{
		MPI_Recv(&msg, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		cout << "rank " << rank << " get msg: " << msg << endl;
	}


	MPI_Finalize();
	return 0;
}