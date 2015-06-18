// DFS program for graph using C Language
// Status Color g:Grey, w:White , b:Black
// I=infinity (I just take it as -1. What ever you can take it works.)
// Time Complexity O(|V|+|E|).
// Any Doubts regarding this mail me @ Bharath Ambati, bharath.hussy@gmail.com,RGUKT NUZVID


#include <stdio.h>
#include <stdlib.h>
#define I -1
#define NUM_VERTICES 8

struct vertex 
	{
		int value;
		struct vertex *next;
	};

void DFS(int);
void VISIT_NODE(int);
typedef struct vertex node;

int distance[NUM_VERTICES+1],status[NUM_VERTICES+1],parent[NUM_VERTICES+1],discover_time[NUM_VERTICES+1],finish_time[NUM_VERTICES+1];
int global_time_stamp=0;
node * create_edges(node *,int [],int);
node * vertices[NUM_VERTICES+1]={NULL};


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
		

		DFS(3);
		printf("Node    Parent    Discover_time   Finish_time\n");
		for (i=1;i<=NUM_VERTICES;i++)
			{
				printf("%d\t %d\t %d \t\t %d \n",i,parent[i],discover_time[i],finish_time[i]);
			}	
	}

void DFS(int source)
	{
		int i;
		for (i=1;i<=NUM_VERTICES;i++)
			{
				status[i]='w';
				parent[i]=I;
			}
		status[source]='g';
		discover_time[source]=global_time_stamp;
		VISIT_NODE(source);
		for (i=1;i<=NUM_VERTICES;i++)
			{
				if (qwstatus[i]=='w')
					{
						VISIT_NODE(i);
					}
			}


	}

void VISIT_NODE(int current_node)
	{

		discover_time[current_node]=global_time_stamp++;
		status[current_node]='g';
		node * adj_list=vertices[current_node];

		while (adj_list)
			{
				if (status[adj_list->value]=='w')
					{
						parent[adj_list->value]=current_node;
						VISIT_NODE(adj_list->value);						
					}
			adj_list=adj_list->next;
			}
		
		status[current_node]='b';
		finish_time[current_node]=global_time_stamp++;

	}

