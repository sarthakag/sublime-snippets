#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define test() int t;cin>>t;while(t--)
#define loop(i,start,end) for(int i=start;i<end;i++)
#define pb push_back
#define nl cout<<"\n"
#define all(v) v.begin(),v.end()
#define oa(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define ov(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";nl
 
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
const int LOGN = 21;
const int INF = 1e17;
 
template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }
template<class T1, class T2> void add( T1 &x, T2 y, int m = MOD ){x += y;if( x >= m )x -= m;}
template<class T1, class T2> void sub( T1 &x, T2 y, int m = MOD ){x -= y;if( x < 0 )x += m;}
int mod( int n, int m=MOD ){ n%=m;if(n<0)n+=m;return n; }
 
 
vector<int>g[MAXN],vis(MAXN),idx(MAXN),ans;
stack<int>st;
void dfs(int u)
{
    for(auto v:g[u])
    {
        if(!vis[v])
        {
            vis[v] = vis[u];
            dfs(v);
        }
    }
    st.push(u);
}
void solve()
{
    int n,m;
    cin>>n;
    m =n-1;
    cin>>m;
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].pb(v);
    }
    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i] = i+1;
            dfs(i);
        }
    }
    int it = 0;
    while(!st.empty())
    {
        ans.pb(st.top()+1);
        idx[st.top()]=it++;
        st.pop();
    }
 
    for(int i = 0;i<n;i++)
    {
        for(auto j:g[i])
        {
            if(idx[i]>idx[j])
            {
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    ov(ans);
}
signed main() 
{
    fastio();
    #ifdef sarthakag
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--)
        solve();
 
 
    return 0;
}