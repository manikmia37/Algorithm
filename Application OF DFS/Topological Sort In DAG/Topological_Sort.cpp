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
stack<int>st;
int visited[N];

void Topological_Sort(int source)
{
    visited[source]=1;
    for(auto adj_node:Adj_list[source])
    {
        if(visited[adj_node]==0)
        {
            Topological_Sort(adj_node);
        }
    }
    st.push(source);
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
    }
    mem(visited,0);
    for(int i=1; i<=Node; i++)
    {
        if(visited[i]==0)
        {
            Topological_Sort(i);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}

/*
For Directed Acyclic Graph
input:
5 3
1 2
3 1
4 5
output: 4 5 3 1 2
*/

