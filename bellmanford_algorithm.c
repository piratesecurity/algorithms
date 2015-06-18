#include <stdio.h>
#include <stdlib.h>

#define INFY 10000
#define NUM_VERTICES 4

void BELLANFORD(void);
void RELAX(int ,int );

int adj_matrix[NUM_VERTICES][NUM_VERTICES]={{0,2,3,5},{2,0,4,1},{3,4,0,1},{5,1,1,0}};
int distance[NUM_VERTICES]={INFY,INFY,INFY,INFY};


void main()
	{
	int source=0,i;
	distance[source]=0;
	BELLANFORD();
	for (i=0;i<NUM_VERTICES;i++)
		printf("%d ",distance[i]);
	}




void BELLANFORD(void)
	{
		int i,j,k;
		for (i=0;i<NUM_VERTICES-1;i++)
			{
				for (j=0;j<NUM_VERTICES;j++)
					{
						for (k=0;k<NUM_VERTICES;k++)
							{
								RELAX(j,k);
							}
					}
			}

		for (i=0;i<NUM_VERTICES;i++)
			{
				for (j=0;j<NUM_VERTICES;j++)
					{
						if (distance[j] > distance[i]+adj_matrix[i][j])
							{
								
								printf("Graph is having -ve Edge cycle ");
								exit(0);
							}
					}
			}



	}

void RELAX(int edg_src, int edg_dest)
	{
		int dist1,dist2;
		dist1=distance[edg_dest];
		dist2=distance[edg_src]+adj_matrix[edg_src][edg_dest];
		if (dist1>dist2)
			distance[edg_dest]=dist2;
		else
			distance[edg_dest]=dist1;
	}
