/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	 pid_t childpid;
    int array[10] ={ 3,1,5,10,9,4,6,2,8,7};

	childpid = fork();
	if (childpid == -1)
	{
		printf("\n Child creation failed");
	}
	else if(childpid == 0)
	{
	    printf("\nunsorted nos are :");
	    for(int i=0;i<10;i++)
	    printf("\t%d",array[i]);
	    printf("\n");
	    
    }
	else
	{  
	    wait(NULL);

         for (int i = 0; i < 10; i++)       
            for (int j = 0; j < 9; j++)  
                 if (array[j] > array[j+1]) 
                 {
                     int temp =array[j];
                     array[j]=array[j+1];
                     array[j+1]=temp;
                 }
             printf("\nsorted nos are :");
    	    for(int i=0;i<10;i++)
    	    printf("\t%d",array[i]);
    	    
	    
} 
    	
	return 0;
}
