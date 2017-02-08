/********************************************************************************	
*										*
*	Calligo Technologies Pvt Ltd. Training Program				*
*										*
*	Program  :: openmp_example10.c						*
*	Description :: Illustration of private, firstprivate and lastprivate	*
*										*
* ©2015 Calligo Technologies Pvt. Ltd.,All rights reserved. All other trademarks*
* or registered trademarks are the property of their respective owners		*
*********************************************************************************/ 

#include<stdio.h>
#include<omp.h>

void main()
{
	int i,tid,fpriv=10,lpriv=20,priv=30;
	//Set number of threads to 2
	omp_set_num_threads(2);
	//Print to check values intially
	printf("Intially: \nprivate=%d\tfirstprivate=%d\tlastprivate=%d\n",priv,fpriv,lpriv);
	//Say priv and tid to be private and fpriv to be firstprivate
	#pragma omp parallel private(priv,tid) firstprivate(fpriv) 
	{
		//Get thread id
		tid=omp_get_thread_num();
		if (tid==0)
		printf("After Entering parallel region: \n ");
		//Check the values in parallel region, priv will be unintialized where as in fpriv will be
		printf("%d thread ==> private=%d\tfirstprivate=%d\tlastprivate=%d\n",tid,priv,fpriv,lpriv);
		//Change the value of lpriv, we must get last updated value
		#pragma omp parallel for lastprivate(lpriv)  
		for(i=1;i<=10;i++)
			lpriv=i*i;
		if (tid==0)
		printf("Before exiting parallel region: \n");
		//Check the values before exiting
		printf("%d thread ==> private=%d\tfirstprivate=%d\tlastprivate=%d\n",tid,priv,fpriv,lpriv);
	}
	
	printf("Finally:\nprivate=%d\tfirstprivate=%d\tlastprivate=%d\n",priv,fpriv,lpriv);
	fflush(0);
}//end of main
