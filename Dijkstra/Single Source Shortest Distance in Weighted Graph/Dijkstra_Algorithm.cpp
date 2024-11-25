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

const int N=1e5+1;
vector<pair<int,int>>Adj_list[N];
int Distance_Array[N];
int visited[N];
const int INF=1e9;
int Node,Edge;

void Dijkstra(int source)
{
    for(int i=1; i<=Node; i++)
    {
        Distance_Array[i]=INF;
    }
    Distance_Array[source]=0;
    for(int i=1; i<=Node; i++)
    {
        int selected_node= -1;
        for(int j=1; j<=Node; j++)
        {
            if(visited[j] == -1)
            {
                if(selected_node== -1 || Distance_Array[j]<Distance_Array[selected_node])
                {
                   selected_node=j;
                }
            }
        }
        visited[selected_node] = 1;
        for(auto Adj_Pair:Adj_list[selected_node])
        {
           int Adj_node=Adj_Pair.first;
           int Edge_cost=Adj_Pair.second;
           if(Distance_Array[selected_node]+Edge_cost<Distance_Array[Adj_node])
           {
              Distance_Array[Adj_node]=Distance_Array[selected_node]+Edge_cost;
           }
        }
    }
}
int main()
{
    //optimize();
    cin>>Node>>Edge;

    for(int i=1; i<=Edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Adj_list[u].push_back(make_pair(v,w));
        Adj_list[v].push_back(make_pair(u,w));
    }
    mem(visited,-1);
    int source=1;
    Dijkstra(source);
    for(int i=1; i<=Node; i++)
    {
        cout<<"Distance From Source Node "<<source<<" To "<<i<<": ";
        cout<<Distance_Array[i]<<endl;
    }
    return 0;
}

/*
input:
6 8
1 2 4
1 3 4
2 3 2
3 4 3
3 5 1
3 6 6
4 6 2
5 6 3

output:
Distance From Source Node 1 To 1: 0
Distance From Source Node 1 To 2: 4
Distance From Source Node 1 To 3: 4
Distance From Source Node 1 To 4: 7
Distance From Source Node 1 To 5: 5
Distance From Source Node 1 To 6: 8
*/

