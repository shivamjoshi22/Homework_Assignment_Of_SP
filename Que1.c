
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	 pid_t childpid;
	childpid = fork();
	if (childpid == -1)
	{
		printf("\nChild creation failed");
	}
	else if(childpid == 0)
	{
	    int temp=childpid;
		childpid = fork();
		if(childpid !=0)
		{
		  // wait(NULL);
		    printf("\n\nFirst Child");
            printf("\n%d",temp);
		    printf("\t%d",childpid);    
		    printf("\nMy id is %d",getpid());
		}
		
		else
		{
    		printf("\n\nThird Child");
    		printf("\n%d",childpid);
    		printf("\t0");
    		printf("\nMy id is %d",getpid());
    	}	
	}
	else
	{ // wait(NULL);
    	int temp=childpid;
	    childpid =fork();
	    if(childpid == 0)
	    {
	        printf("\n\nSecond");
	        printf("\n%d",temp);
	        printf("\t%d",childpid);
	        printf("\nMy id is %d",getpid());
	        
	    }
	    else
	    {
	        //wait(NULL);
	        printf("\n\nParent");
	        printf("\n%d",temp);
	        printf("\t%d",childpid);
	        printf("\nMy id is %d",getpid());
	    }
	 }



	return 0;
}
