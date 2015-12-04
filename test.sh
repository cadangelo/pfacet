#!/bin/sh
#SBATCH --partition=pre		# default "univ" if not specified
#SBATCH --time=23:00:00		# run time in days-hh:mm:ss

#SBATCH --ntasks=8
#SBATCH --mem-per-cpu=8000

#SBATCH --error=/home/cadangelo/pfacet/job.err
#SBATCH --output=/home/cadangelo/pfacet/job.%J.out

#Now list your executable command (or a string of them). Example:
##srun /home/adavis23/dagmc/mcnp5v16_dag/bin/mcnp5.mpi i=bllite33 g=blite_integrated_zip.h5m o=blite33.o x=/home/adavis23/dagmc/mcnp_data/xsdir.fendl2.1
mpirun -np 8 ./test
