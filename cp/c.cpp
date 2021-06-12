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

vector<int>g[MAXN];
int n,m;
vector<int>rt,sz;
void initialise()
{
	rt.resize(n,0);
	sz.resize(n,0);
  for(int i=0;i<n;i++)
  {	
    rt[i]=i;
    sz[i]=1;
  }
}

int root(int i)
{
  while(i!=rt[i])
  {
    rt[i]=rt[rt[i]];
    i=rt[i];
  }
  return i;
}

void union1(int a,int b)
{
  if(root(a)==root(b))
    return;
  int rta=root(a);
  int rtb=root(b);
  int sza=sz[rta];
  int szb=sz[rtb];
  if(sza>=szb)
  {
    rt[rtb]=rt[rta];
    sz[rta]+=sz[rtb];
    sz[rtb]=0;
  }
  else
  {
    rt[rta]=rt[rtb];
    sz[rtb]+=sz[rta];
    sz[rta]=0;
  }
}
void solve()
{
	cin>>n;
	m =n-1;
	cin>>m;
	initialise();
	for(int i = 0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
		union1(u,v);
	}
	set<int>se;
	for(int i = 0;i<n;i++)se.insert(root(i));
	if(se.size()==2)
	{
		cout<<"WIN"<<endl;
		return;
	}
	if(se.size()==1)
	{
		cout<<"LOSE"<<endl;
		return;
	}
	// return;
	int sm2=0,sm = 0,ed=-m;
	for(auto i:se)
	{
		sm+=sz[i];
		ed+=sz[i]*(sz[i]-1)/2;
		sm2+=sz[i]*sz[i];
	}
	int tot = (sm*sm - sm2)/2 + ed;
	int par = tot&1;
	int fl =0;
	for(auto i:se)
	{
		int lol = sz[i];
		int left = n-sz[i];
		int num = lol*left-1;
		fl ^= ((num&1)^par);
		// if((num&1)^par)
		// {
		// 	cout<<"WIN"<<endl;
		// 	return;
		// }
	}
	if(!fl)
		cout<<"LOSE"<<endl;
	else
		cout<<"WIN"<<endl;



}
signed main() 
{
	fastio();
	#ifdef sarthakag
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int t=1;
	cin>>t;
	while(t--)
		solve();


	return 0;
}
