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

const int N=101;
vector<int>Adj_list[N+1];

int visited[N+1];
void dfs(int source)
{
   visited[source]=1;
   cout<<source<<" ";
   for(auto u:Adj_list[source])
   {
       if(visited[u] != 1)
       {
           dfs(u);
       }
   }
}

int main()
{
    //optimize();
    int Node,Edge;
    cout<<"Enter Number of Nodes and Edges respectively: ";
    cin>>Node>>Edge;
    cout<<"Enter The values for graph representation: "<<endl;
    for(int i=1; i<=Edge; i++)
    {
        int u,v;
        cin>>u>>v;
        Adj_list[u].push_back(v);
        Adj_list[v].push_back(u);
    }
    cout<<"Enter Source Node: ";
    int source;
    cin>>source;
    dfs(source);
    return 0;
}

/*
input:
6 6
0 1
1 2
1 5
2 3
2 4
5 4
0
output
DFS: 0 1 2 3 4 5
*/
