#include "stdafx.h"
#include <mpi.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{

	MPI_Init(&argc, &argv);
	
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(processor_name, &name_len);

	cout << endl << "MPI Hello World Program";
	cout << endl << "Processor Name: " << processor_name;
	cout << endl << "Processor Rank: " << world_rank;
	cout << endl << "Wordl Size: " << world_size;
	cout << endl;


	MPI_Finalize();
	system("pause");
}
