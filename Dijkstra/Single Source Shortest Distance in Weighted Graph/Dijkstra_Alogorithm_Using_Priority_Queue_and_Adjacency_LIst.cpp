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

const int INF=1e9;
const int N=1e5+1;
vector<pair<int,int>>Adj_list[N];

int visited[N];
vector<int>Distance(N,INF);

void Dijkstra(int source)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push(make_pair(0,source));
    Distance[source]=0;
    while(!pq.empty())
    {
        int head=pq.top().second;
        //int cost=pq.top().first;
        pq.pop();
        if(visited[head]==1)
        {
            continue;
        }
        visited[head]=1;
        for(auto Adjacent_Pair:Adj_list[head])
        {
            int adj_node=Adjacent_Pair.first;
            int weight=Adjacent_Pair.second;
            if(Distance[head]+weight<Distance[adj_node])
            {
                Distance[adj_node]=Distance[head]+weight;
                pq.push(make_pair(Distance[adj_node],adj_node));
            }

        }
    }
}

int main()
{
    //optimize();
    int Node,Edge;
    cin>>Node>>Edge;
    for(int i=1; i<=Edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Adj_list[u].push_back(make_pair(v,w));
        Adj_list[v].push_back(make_pair(u,w));
    }
    memset(visited,-1,sizeof(visited));
    int source=1;
    Dijkstra(source);
    for(int i=1; i<=Node; i++)
    {
        cout<<"Distance From Source Node "<<source<<" To "<<i<<": ";
        cout<<Distance[i]<<endl;
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
