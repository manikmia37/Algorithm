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
vector<int>Adj_list[N];
bool visited[N];

void dfs(int source)
{
   stack<int>st;
   st.push(source);
   visited[source]=true;
   while(!st.empty())
   {
      int head=st.top();
      st.pop();
      cout<<head<<" ";
      for(auto adj_node:Adj_list[head])
      {
         if(!visited[adj_node])
         {
             st.push(adj_node);
             visited[adj_node]=true;
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
        int u,v;
        cin>>u>>v;
        Adj_list[u].push_back(v);
        Adj_list[v].push_back(u);
    }
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
output: (iterative DFS)
0 1 5 4 2 3
*/

