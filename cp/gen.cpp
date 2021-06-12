#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
// #define int long long
#define pii pair<int,int>
#define test() int t;cin>>t;while(t--)
#define loop(i,start,end) for(int i=start;i<end;i++)
#define pb push_back
#define nl cout<<"\n"
#define all(v) v.begin(),v.end()
#define oa(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define ov(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";nl

const int N = 1e5+5;
const int MOD = 1e9+7;
const int LOGN = 21;
const int INF = 1e9;

template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }
template<class T1, class T2> void add( T1 &x, T2 y, int m = MOD ){x += y;if( x >= m )x -= m;}
template<class T1, class T2> void sub( T1 &x, T2 y, int m = MOD ){x -= y;if( x < 0 )x += m;}
int mod( int n, int m=MOD ){ n%=m;if(n<0)n+=m;return n; }
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

void solve()
{
	int n = rand(1,10);
	cout<<n<<endl;
	int mn,mx;
	mn = -15007;
	mx = 15007;
	mn = -10;
	mx = 10;
	for(int i = 0;i<n;i++)
	{
		cout<<rand(mn,mx)<<" ";
	}
	int q = 10;
	cout<<q<<endl;
	while(q--)
	{
		int l = rand(1,n);
		int r = rand(1,n);
		cout<<min(l,r)<<" "<<max(l,r)<<endl;
	}
}
int main(int argc, char* argv[]) 
{
	if(argc>1)
		srand(atoi(argv[1]));
	else 
		srand(time(0));
	fastio();
	#ifdef sarthakag
		// freopen("in.txt","r",stdin);
		freopen("in.txt","w",stdout);
	#endif
	int t=1;
	// cin>>t;
	while(t--)
		solve();


	return 0;
}
