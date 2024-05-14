#include<iostream>
#define V 9
#define INT_MAX 9999
using namespace std;

void shortestpath(int graph[V][V],int source,int dest)
{
	int dist[V];
	bool visited[V];
	
	//step 1 initialize everything
	for(int i=0;i<V;i++)
	{
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	
	//step 2 distance of source from itself will be zero
	dist[source]  = 0;
	
	//step 3 for loop excluding source node that ends after step 7
	
	for(int count=0;count<V-1;count++)
	{
		int min=INT_MAX; //stores the minimum dist
		int minindex;  //vertex with minimum distance that will be visted next
		//step 4 find the vertex with minmum distance of all that is to be next visted
		for(int i=0;i<V;i++)
		{
			//if the node is not visited and distance of that node is less than minimum distnace
			if(!visited[i] && dist[i]<=min)
			{
				min  = dist[i];
				minindex = i;
			}
		}
		
		//step 5 set the node with minimum distance as visted
		visited[minindex] = true;
		
		//step 6 update the distance of all the vertex adjancent to the recently visted vertex 
		//if 1.that adjacent vertex is not viisted
		//if 2.there exists an edge between them
		//if 3.the distnace of recently visted vertex is not infinity
		//if 4. the distance of that adjacent vertex id less than the distnace from the source vertex
		for(int v=0;v<V;v++)
		{
			if(!visited[v] && graph[minindex][v] && dist[minindex]!=INT_MAX && dist[v] > dist[minindex]+graph[minindex][v])
			{
				//if satisfies all the conditions then
				dist[v] = dist[minindex] + graph[minindex][v];
			}
		}
		
	}
	
	cout<<"Vertex\tDistance from the source node"<<endl;
	for(int i=0;i<V;i++)
	{
		
			cout<<i<<"\t\t\t\t"<<dist[i]<<endl;
		
	}
	
	cout<<"The distance of source to destination is: ";
	cout<<dist[dest]<<endl;
} 



int main()
{
	
//	int graph[V][V]={
//		{0,2,0,6,0},
//		{2,0,3,0,5},
//		{0,3,0,0,0},
//		{6,0,0,0,0},
//		{0,5,0,0,0}};

int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	
	shortestpath(graph,0,4);
}