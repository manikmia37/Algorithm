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

const int N=2e5+1;
vector<int>Adj_list[N];
int visited[N];
int level[N];
int parent[N];
queue<int>q;
void Find_Single_Source_Shortest_path(int source)
{
    visited[source]=1;
    level[source]=1;
    parent[source] = -1;
    q.push(source);
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(auto adj_node:Adj_list[head])
        {
           if(visited[adj_node] == -1)
           {
               visited[adj_node]=1;
               level[adj_node]=level[head]+1;
               parent[adj_node]=head;
               q.push(adj_node);
           }
        }
    }
}

int main()
{
    //optimize();
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        Adj_list[u].push_back(v);
        Adj_list[v].push_back(u);
    }
    mem(visited,-1);
    int source=1;
    Find_Single_Source_Shortest_path(source);
    int destination=n;
    if(level[destination]==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<level[destination]<<endl;

    vector<int>Final_result;
    Final_result.push_back(destination);

    while(parent[destination] != -1)
    {
       int value=parent[destination];
       Final_result.push_back(value);
       destination=value;
    }
    reverse(Final_result.begin(),Final_result.end());
    for(auto u:Final_result)
    {
        cout<<u<<" ";
    }
    return 0;
}
/*
input:
5 5
1 2
1 3
1 4
2 3
5 4
output:
Short Distance of destination: 3
Shortest path: 1 4 5
*/

