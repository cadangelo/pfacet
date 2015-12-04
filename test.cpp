#include "mpi.h"
#include "moab/Interface.hpp"
#include "moab/Core.hpp"
#include "moab/Types.hpp"
#include "moab/ParallelComm.hpp"
#include "MBParallelConventions.h"
#include <stdio.h>
#include <string>
#include <iostream>

#define CHKERR if (MB_SUCCESS != rval) return rval

using namespace moab;

Tag category_tag;
Tag geom_tag;
Tag name_tag;
Tag obj_name_tag;
Tag dim_tag, id_tag, sense_tag;

//Interface *MBI;

int main(int argc, char* argv[])
{
  int my_rank; /* rank of process */
  int p; /* number of processes */
  int source; /* rank of sender */
  int dest; /* rank of receiver */
  int tag = 0; /* tag for messages */
  char message[100]; /* storage for message */
  MPI_Status status; /* return status for receive */
  
  MPI_Init(&argc, &argv); // Start up MPI
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); // Find out process rank
  MPI_Comm_size(MPI_COMM_WORLD, &p); // Find out number of processes

  Interface *mbi = new Core();
  

  if (my_rank != 0) {
      /* Create message */
      sprintf(message, "Greetings from process %d!", my_rank);
      dest = 0;
      /* Use strlen+1 so that '\0' gets transmitted */
      MPI_Send(message, strlen(message)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
  }
  else { /* my_rank ==0 */
      for (source = 1; source < p; source++) {
          MPI_Recv(message, 100, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
          printf("%s\n", message);
      }
  }

  MPI_Finalize(); // Shut down MPI
 
  return 0;
} /* main */



