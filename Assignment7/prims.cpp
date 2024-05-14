#include <iostream>
#include <cstring>
using namespace std;
#define v 5
#define INF 999
int main()
{
    int G[v][v] = {{0, 6,5,0,0}, {6,0,2,7,5}, {5,2,0,0,1}, {0,7,0,0,2},{0,5,1,2,0}};
    bool visited[v];
    memset(visited, false, sizeof(visited));
    visited[0] = true;
    int edges = 0;
    int total = 0;
    cout << "node1\tnode2\t\tvalue\n";
    while (edges < v - 1)
    {
        int x = 0;
        int y = 0;
        int min = INF;
        for (int i = 0; i < v; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < v; j++)
                {
                    if (!visited[j] && G[i][j])
                    {
                        if (G[i][j] < min)
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        visited[y] = true;
        cout << x << "---------->" << y << "\t\t" << min << "\n";
        total += min;
        edges++;
    }
    cout << "total= " << total;
    return 0;
}

// #include <iostream>
// #include <cstring>
// using namespace std;

// #define INF 999
// #define v 4

// int main(){

// int G[v][v] = {{0, 2, 0, 5}, {2, 0, 3, 1}, {0, 3, 0, 4}, {5, 1, 4, 0}};

// bool visited[v];

// memset(visited, false, sizeof(visited));
// visited[0] = true;
// int noofedges = 0;
// int total = 0;

// while(noofedges < v-1){
// int x = 0;
// int y = 0;
// int min = INF;
// for(int i = 0; i < v; i++){
//     if(visited[i]){
//         for(int j = 0; j<v; j++){
//             if(!visited[j] && G[i][j]){
//                 if(G[i][j] < min){
//                     min = G[i][j];
//                     x = i;
//                     y = j;

//                 }
//             }
//          }
//     }

// }

// cout<<x<<"-->"<<y<<"  "<<min<<endl;
// visited[y] = true;
// total+=min;
// noofedges++;
// }

// cout<<total;

// return 0;
// }
