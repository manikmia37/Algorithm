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
queue<int>q;
int level[N];

void bfs(int source)
{
   level[source]=0;
   q.push(source);
   while(!q.empty())
   {
       int head=q.front();
       q.pop();
       for(auto adj_node : Adj_list[head])
       {
           if(level[adj_node] == -1)
           {
               level[adj_node]=level[head]+1;
               q.push(adj_node);
           }
       }
   }
}

void  Findout_Single_Source_Shortest_distance(int source)
{
   bfs(source);
}

int main()
{
    //optimize();
    int Node,Edge;
    cin>>Node>>Edge;
    for(int i=1; i<=Edge; i++)
    {
        int u,v;
        cin>>u>>v;
        Adj_list[u].push_back(v);
        Adj_list[v].push_back(u);
    }
    int source;
    cin>>source;
    int destination;
    cin>>destination;
    mem(level,-1);
    Findout_Single_Source_Shortest_distance(source);
    cout<<"Shortest Distance of Destination is: ";
    cout<<level[destination]<<endl;
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
3
output: 3
*/
