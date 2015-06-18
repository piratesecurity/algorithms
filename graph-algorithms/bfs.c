// BFS program for undirected graph using C Language
// Status Color g:Grey, w:White , b:Black
// I=infinity (I just take it as -1. What ever you can take it works.)
// Time Complexity O(|V|+|E|).
// Any Doubts regarding this mail me @ Bharath Ambati, bharath.hussy@gmail.com,RGUKT NUZVID


#include <stdio.h>
#include <stdlib.h>
#define I -1

struct vertex 
	{
		int value;
		struct vertex *next;
	};


typedef struct vertex node;
int num_vertices=8,enqueue_index=1,dequeue_index=1;
void BFS(int source);
node * create_edges(node *,int [],int);
node * vertices[6]={NULL};

node * create_edges(node *root,int list[],int length)
	{
	
		int i,j;
		for (i=0;i<length;i++)
			{
				node * new_node =(node *) malloc(sizeof(node));
				new_node->value=list[i];
				new_node->next=root;
				root=new_node;
			}
		return root;
	}


void main()
	{
		int i,array1[1]={2},array2[2]={1,3},array3[2]={2,4},array4[3]={3,5,6},array5[3]={4,6,7},array6[4]={4,5,7,8},array7[3]={5,6,8},array8[2]={6,7};
		vertices[1]=create_edges(vertices[1],array1,1);
		vertices[2]=create_edges(vertices[2],array2,2);
		vertices[3]=create_edges(vertices[3],array3,2);
		vertices[4]=create_edges(vertices[4],array4,3);
		vertices[5]=create_edges(vertices[5],array5,3);
		vertices[6]=create_edges(vertices[6],array6,4);
		vertices[7]=create_edges(vertices[7],array7,3);
		vertices[8]=create_edges(vertices[8],array8,2);

		BFS(3);
	}



void BFS(int source)
	{
		int total_complexity=0;
		int queue[num_vertices+1],distance[num_vertices+1],parent[num_vertices+1];
		char status[num_vertices+1]; 
		int i,current_node;
		for (i=1;i<=num_vertices;i++)
			{
				status[i]='w';
				distance[i]=I;
				parent[i]=I;
			}
		distance[source]=0;
		status[source]='g';
		parent[source]=-1;
		queue[1]=source;

		while(dequeue_index<=num_vertices)
			{

				current_node=queue[dequeue_index++];
				
				node * adj_list=vertices[current_node];
				while (adj_list)
					{
						total_complexity++;
						if (status[adj_list->value]=='w')
							{
								parent[adj_list->value]=current_node;
								distance[adj_list->value]=distance[current_node]+1;
								status[adj_list->value]='g';
								queue[++enqueue_index]=adj_list->value;

							}
					adj_list=adj_list->next;		
					}
				status[current_node]='b';
			}
	printf("Node   Parent   Distance\n");
	for (i=1;i<=num_vertices;i++)
		{	
			printf("%d\t",i );
			printf("%d\t",distance[i]);
			printf("%d\n",parent[i]);
		}
	printf("%d ",total_complexity);
	}
