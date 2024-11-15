#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
#define MOD 1000000007
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(5); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a,b,sizeof(a));
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

const int N=100;
int visited[N+1];
queue<int>q;
vector<int>Adjacent_List[N+1];
void BFS(int source)
{
   visited[source]=1;
   q.push(source);
   while(!q.empty())
   {
       int current_vertex=q.front();
       q.pop();
       cout<<current_vertex<<" ";
       for(auto adjacent_vertex:Adjacent_List[current_vertex])
       {
           if(visited[adjacent_vertex]==0)
           {
               visited[adjacent_vertex]=1;
               q.push(adjacent_vertex);
           }
       }
   }
}
int main()
{
    //optimize();
    cout<<"Enter Number of Nodes: ";
    int Node;
    cin>>Node;
    cout<<"Enter Number of Edges: ";
    int Edges;
    cin>>Edges;
    for(int i=1; i<=Edges; i++)
    {
        int u,v;
        cin>>u>>v;
        Adjacent_List[u].push_back(v);
        Adjacent_List[v].push_back(u);
    }
    cout<<"Enter the Source Node: ";
    int source;
    cin>>source;
    BFS(source);
    return 0;
}

/*
input is given for unweighted and undirected graph
input:
6 6
0 1
1 2
1 5
2 3
2 4
5 4
0
output:
Level Order Traversal: 0 1 2 5 3 4
*/

