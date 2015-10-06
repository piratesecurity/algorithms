#include <stdio.h>
#include <stdlib.h>
#define INFY 1000
void Build_min_heap(int [],int [],int);
void min_heapify(int adj_matrix[],int track_index[],int i,int lenght);
int Find_Min(int *array1,int[],int length);
int *array1,*array2;
int find(int [],int);
int Union(int[],int,int);
int global_min,total_sum=0;

void main()
	{
	
	FILE *graph=fopen("graph.txt","r");
	if (graph==NULL) { printf("graph File not found :graph.txt ");exit(0);}
	int n_vertices,length;	
	fscanf(graph," %d ",&n_vertices);	
	length=n_vertices*n_vertices;
	int *adj_matrix=(int *) malloc(sizeof(int)*length),*track_index=(int *) malloc(sizeof(int)*length);
	int i,j,src,dst,weight,arr;	
	for (i=0;i<length;i++)
		{
		adj_matrix[i]=INFY;
		}
	while(fscanf(graph,"%d\t%d\t %d\n",&src,&dst,&weight) == 3) 
			{	
			adj_matrix[(src-1)*n_vertices+(dst-1)]=weight;
			track_index[(src-1)*n_vertices+(dst-1)]=(src-1)*n_vertices+(dst-1);
			if (src==dst)
				{
				adj_matrix[(src-1)*n_vertices+(dst-1)]=INFY;
				}
			//printf("%d \n",(src-1)*n_vertices+(dst-1));
			}
	//for (i=0;i<n_vertices;i++) printf("%d \n",adj_matrix[i]);
		
	Build_min_heap(adj_matrix,track_index,length);
	int min_edge,edge_src,edge_dst,parent[n_vertices],src_root,dst_root,forest_edges=1;
	for (i=0;i<n_vertices;i++) parent[i]=0;
	printf("src\tdst\tweight \n");
	 while (forest_edges<n_vertices)
			{
			min_edge=Find_Min(array1,track_index,length);
			edge_src=min_edge/n_vertices;
			edge_dst=min_edge%n_vertices;
			src_root=find(parent,edge_src);
			dst_root=find(parent,edge_dst);
			if (Union(parent,src_root,dst_root))
				{
				printf("%d\t%d\t%d\n",edge_src,edge_dst,global_min);
				total_sum+=global_min;
				}
			forest_edges++;
			}

	printf("\nMST SUM IS :%d \n\n",total_sum);
	

	}
	

void Build_min_heap(int adj_matrix[],int track_index[],int length)
	{
	int i;
	for(i=length/2;i>=0;i--)
		min_heapify(adj_matrix,track_index,i,length);
	array1=adj_matrix,array2=track_index;	
	}



void min_heapify(int adj_matrix[],int track_index[],int i,int length)
	{
		int l=i*2;
		int r=i*2+1;
		int smallest;
		if(l<=length & adj_matrix[i]>adj_matrix[l])
			smallest=l;
		else	
			smallest=i;
		if(r<=length & adj_matrix[r]<adj_matrix[smallest])
			smallest=r;
		if (smallest != i)
			{
			int temp=adj_matrix[i],temp1=track_index[i];
			adj_matrix[i]=adj_matrix[smallest];
			track_index[i]=track_index[smallest];				
			adj_matrix[smallest]=temp;
			track_index[smallest]=temp1;
			min_heapify(adj_matrix,track_index,smallest,length);
			}			
	}

int Find_Min(int *array1,int track_index[] ,int length)
{
	if (length<1)
		printf("heap underflow\n");
	global_min=array1[0];
	int min_index=track_index[0];
	array1[0]=array1[length-1];
	track_index[0]=track_index[length-1];
	length=length-1;
	min_heapify(array1,track_index,0,length);	
	return min_index;
}



int find(int parent[],int i)
	{	
		while (parent[i])
			i=parent[i];
		return i;
	}


int Union(int parent[],int x, int y)
	{
	if (x!=y)
		{
		parent[y]=x;
		return 1;
		}
	return 0;
	}
