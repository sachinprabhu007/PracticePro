1. Log on to Machine
   export $INTEL_PATH=/opt/apps/
   
2. Creating Work directory
	
	mkdir -p work
	cd work

3. Write openmp_lab1.c
	
	vi openmp_lab1.c

4. Compile and run
	source $INTEL_PATH/intel/composerxe/bin/compilervars.sh intel64			//Source for first time
	icc openmp_lab1.c -openmp -o openmp_lab1.out
	./openmp_lab1.out
	
5. Complete openmp_lab2.c ( Array sum program )
	
	cp ~/student<id>/labs/openmp_lab2.c . 
	vi openmp_lab2.c



6. Compile and run openmp_lab2.c
	///if not sourced, source as given in 4
	 icc openmp_lab2.c -openmp -o openmp_lab2.out
	 ./openmp_lab2.out 
	
7. Modify openmp_lab2.c to use partial sum array instead of atomic for synchronization
	cp openmp_lab2.c <newname>.c
	vi <newname>.c
	icc <newname>.c -openmp -o <newname>.out
	./<newname>.out
	
8. Complete openmp_lab3.c ( computing value of pi using area under the curve method )
	cp ~/student<id>/labs/openmp_lab3.c . 
	vi openmp_lab3.c

9. Compile and run openmp_lab3.c
	icc openmp_lab3.c -openmp -o openmp_lab3.out
	./openmp_lab3.out 
