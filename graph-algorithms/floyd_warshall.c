#include <stdio.h>


#define NUM_VERTICES 4
#define INFY 1000

void FLOYD_WARSHALL(void);
void PRINT_MATRIX(int [NUM_VERTICES][NUM_VERTICES]);

int first[NUM_VERTICES][NUM_VERTICES]={{0,INFY,3,5},{2,0,4,1},{3,4,0,1},{5,1,1,0}};
int second[NUM_VERTICES][NUM_VERTICES];

void main()
	{
	int i,j,k;
	
	FLOYD_WARSHALL();
	printf("All Pair shortest paths matrix :\n");
	PRINT_MATRIX(second);
	}

void FLOYD_WARSHALL(void)
	{
		int i,j,k,dist1,dist2;
		for (i=0;i<NUM_VERTICES;i++)
			{
				for (j=0;j<NUM_VERTICES;j++)
				{
					for (k=0;k<NUM_VERTICES;k++)
						{

							dist1=first[j][k];
							dist2=first[j][i]+first[i][k];
							if (dist1>dist2)
								second[j][k]=dist2;
							else
								second[j][k]=dist1;
						}
				}
			for (j=0;j<NUM_VERTICES;j++)
				{
				for (k=0;k<NUM_VERTICES;k++)
					{
						first[j][k]=second[j][k];
					}
				}


				
			}
		

	}

void PRINT_MATRIX(int matrix[NUM_VERTICES][NUM_VERTICES])
	{
	int i,j;
	for (i=0;i<NUM_VERTICES;i++)
	{
		for (j=0;j<NUM_VERTICES;j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	}			
