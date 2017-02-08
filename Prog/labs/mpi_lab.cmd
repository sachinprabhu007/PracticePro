1.Log on to Machine
  export INTEL_PATH=/opt/apps/
  
2. Creating Work directory
	mkdir -p work
	cd work
	
3. Write mpi_lab1.c
	vi mpi_lab1.c

4. Compile and run mpi_lab1.c
							/***Note: Source required only first time of every login ****/
		Source => source $INTEL_PATH/intel/composerxe/bin/compilervars.sh intel64
			 source $INTEL_PATH/intel/impi/5.0.1.035/bin64/mpivars.sh
		Compile => mpiicc mpi_lab1.c -o mpi_lab1.out
		Run without number of process => mpirun ./mpi_lab1.out 
		Run with number of process => mpirun -np <int> ./mpi_lab1.out
		
5. Complete mpi_lab2.c ( Array sum program )
	cp ~/student<id>/labs/mpi_lab2.c . 
	vi mpi_lab2.c

6. Compile and run mpi_lab2.c		
						///if not sourced, source as given in 4
		Compile => mpiicc mpi_lab2.c -o mpi_lab2.out
		Run without number of process => mpirun ./mpi_lab2.out 
		Run with number of process => mpirun -np <int> ./mpi_lab2.out
		
7. Complete mpi_lab3.c (Ring Topology)
	cp ~/student<id>/labs/mpi_lab3.c . 
	vi mpi_lab3.c	
	
8. Compile and run mpi_lab3.c
					///if not sourced, source as given in 4
		Compile => mpiicc mpi_lab3.c -o mpi_lab3.out
		Run without number of process => mpirun ./mpi_lab3.out 
		Run with number of process => mpirun -np <int> ./mpi_lab3.out
