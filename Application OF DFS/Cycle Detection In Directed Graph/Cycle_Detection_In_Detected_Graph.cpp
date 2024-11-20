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

bool dfs(int source)
{
  visited[source]=1;
  for(auto adj_node:Adj_list[source])
  {
     if(visited[adj_node] == -1)
     {
         bool cycle=dfs(adj_node);
         if(cycle)
         {
             return true;
             break;
         }
     }
     else if(visited[adj_node]==1)
     {
         return true;
     }
  }
  visited[source]=2;
  return false;
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
    }
    bool ans=false;
    mem(visited,-1);
    for(int i=1; i<=n; i++)
    {
       if(visited[i] == -1)
       {
           bool exist_cycle=dfs(i);
           if(exist_cycle)
           {
               ans=exist_cycle;
               break;
           }
       }
    }
    if(ans) cout<<"Yes,Cycle"<<endl;
    else cout<<"No,Cycle"<<endl;
    return 0;
}
/*
input:
6 7
1 4
1 3
4 5
3 5
3 2
2 6
6 3
output: Yes, Cycle

input:
5 5
1 2
2 3
2 4
3 5
4 5

output: No, Cycle

input:
4 4
1 2
2 3
3 4
4 2
output:Yes, Cycle
*/

