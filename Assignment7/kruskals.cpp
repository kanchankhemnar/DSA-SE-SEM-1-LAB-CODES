#include <iostream>
using namespace std;
#define INF 999
#define v 5
int parent[v];

int findparent(int i){
    while (parent[i]!=i)
    {
        parent[i]=i;
    }
    return i;
    
}

void unionset(int m,int j){
    int s1=findparent(m);
    int s2=findparent(j);
    if (s1!=s2)
    {
        s1=parent[s2];
    }
    

}



int main(){
    // int G[v][v] = {{0, 2, 0, 5}, {2, 0, 3, 1}, {0, 3, 0, 4}, {5, 1, 4, 0}};
    int G[v][v] = {{0, 6,5,0,0}, {6,0,2,7,5}, {5,2,0,0,1}, {0,7,0,0,2},{0,5,1,2,0}};

    for (int i = 0; i < v; i++)
    {
        parent[i]=i;
    }
    int edges=0;
    int total=0;
    while (edges<v-1)
    {
        int min=INF;
        int a=-1,b=-1;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (parent[i]!=parent[j] && G[i][j]!=0 && G[i][j]<min)
                {
                    min=G[i][j];
                    a=i;
                    b=j;
                }
                
            }
            
        }
        if (a!=-1 && b!=-1 && findparent(a)!=findparent(b))     
        {
            cout<<a<<"--->"<<b<<"   "<<min<<endl;
            total+=min;
            G[a][b]=G[b][a]=0;
            edges++;
        }
        
        
    }
    cout<<"Total cost: "<<total;
    
    






return 0;
}












































// #include<iostream>
// using namespace std;

// #define INF 999
// #define v 4

// int parent[v];

// int findparent(int i){
//     while(parent[i]!= i){
//         parent[i] = i; 
//     }
//     return i;
// }

// void unionset(int m, int j){
//     int s1 = findparent(m);
//     int s2 = findparent(j);
//     if(s1!=s2){
//         s1=parent[s2];

//     }
// }

// int main(){
//     int G[v][v] = {{0, 7, 0, 5}, {7, 0, 3, 1}, {0, 3, 0, 41}, {5, 1, 41, 0}};
//     for(int i=0 ; i<v; i++){
//         parent[i] = i;
//     }
//     int noofedges= 0;
//     int total = 0;
//     while(noofedges<v-1){
//         int min = INF;
//         int a=-1,b=-1;
//         for(int i=0; i<v; i++){
//             for (int j=0; j<v; j++){
//                 if(parent[i]!=parent[j] && G[i][j]!=0 && G[i][j]<min){
//                     min = G[i][j];
//                     a= i;
//                     b= j;
//                 }
//             }
//         }
//         if(a!=-1 && b!=-1 && findparent(a)!=findparent(b)){
//             cout<<a<<"->"<<b<<"\t"<<min<<endl;
//             total+=min;
//             G[a][b] = G[b][a] =0;
//             noofedges++;
//         }
//     }
//     cout<<"Total cost: "<<total;
//     return 0;
// }