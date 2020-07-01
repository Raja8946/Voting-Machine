#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct facility
{
	char f[50];
};

void takeInput(int *facilityNumber, int *votersNumber)
{
	int i;
	
	printf("Enter Number of Facility: ");
	scanf("%d", facilityNumber);
	
	printf("\nEnter Number of Voters: ");
	scanf("%d", votersNumber);
}

void printingFacilities(struct facility *fac, int facilityNumber)
{
	int i;
	
		
	printf("\nFacilities Listed for Voting: \n");
	for(i=0;i<facilityNumber;i++)
	{
		printf("%d.",(i+1));
		puts(fac[i].f);
	}
	printf("\n");
}

void takingVotes(int *vote, int facilityNumber, int votersNumber)
{
	int num, n=9, currVote;
	
	printf("\nVote Your Facility\n"); 
	num = 1;
	n = votersNumber;
	
	while(n--)
	{
		printf("Voter %3d :  ", num++);
		scanf("%d", &currVote);
		
	    if(currVote < votersNumber)
		vote[currVote-1]++;
	} 
	printf("\n"); 
}

void calculatingResult(struct facility *fac, int *vote, int votersNumber, int facilityNumber)
{
	int index=-1,i;
	
	for(i=0; i<facilityNumber; i++)
	{
		printf("\nVote for ");
		printf("%s", fac[i].f);
		printf(" is : %3d", vote[i]);
		if(vote[i]>(votersNumber/2))
		  index=i;  
	}
	printf("\n");
	
	if(index==-1)
	  printf("\nNo Winning facility \n");
	else
	  printf("\nWinning Facility is ::  %s \n",fac[index].f);
}

int main()
{
	int votersNumber, facilityNumber, n, buffer, i;
	struct facility *fac;
	int *vote;
	 
	takeInput(&facilityNumber, &votersNumber);
	
	fac = (struct facility *)malloc(facilityNumber * sizeof(struct facility));
	vote = (int *)malloc(facilityNumber * sizeof(int));
	scanf("%c", &buffer);
	
	printf("\nEnter Facilities: \n");
	for(i=0; i<facilityNumber; i++)
	{
		gets(fac[i].f);
		vote[i] = 0;
	}
	
	printingFacilities(fac, facilityNumber);
	takingVotes(vote, facilityNumber, votersNumber);
	calculatingResult(fac, vote, votersNumber, facilityNumber);
	
	return 0;
}

