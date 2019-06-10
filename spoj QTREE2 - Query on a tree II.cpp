/// CLASSICAL LCA PROBLEM
#include<bits/stdc++.h>
#define ll long long int
#define rep0(i,n) for(i=0; i<(ll)n; i++)
#define rep1(i,n) for(i=1; i<=(ll)n; i++)
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define mp make_pair
#define read(f) freopen("in.txt","r",stdin)
#define write(f) freopen("","w",stdin)
#define mx 100000
#define pi 3.1415926535897932384626433832795
using namespace std;
ll i,j,t,a,b,c,k;
string s;
ll parent[10010];
ll level[10010];
ll cost[10010];
ll parse[10010][20];

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

void dfs(vector<pair<ll,ll> >e[10010], ll root, ll curr, ll dep)
{
    parent[curr]=root;
    level[curr]=dep;
    for(int h=0; h<e[curr].size(); h++)
    {
        if(e[curr][h].first==root)
            continue;
        cost[e[curr][h].first]=e[curr][h].second+cost[curr];
        dfs(e,curr,e[curr][h].first,dep+1);
    }
}

void lca_init(ll n)
{
    mem(parse,-1);
    for(i=1; i<=n; i++)
        parse[i][0]=parent[i];

    for(j=1; (1<<j)<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(parse[i][j-1]!=-1)
            {
                parse[i][j]=parse[parse[i][j-1]][j-1];
            }
        }
    }
}

ll lca_query(ll n, ll p, ll q) ///n is number of nodes, p and q are the nodes for those we will calculate lca.
{
    ll tmp,log;
    if(level[p]<level[q])
        tmp=p,p=q,q=tmp;

    log=1;
    while(1) /// find the highest power of 2 <=level[p];
    {
        ll next=log+1;
        if((1<<next)>level[p])
            break;
        log ++;
    }

    for(i=log; i>=0; i--) /// making level p as same as q;
    {
        if(level[p]-(1<<i)>=level[q])
            p=parse[p][i];
    }

    if(p==q)  /// if they are same node now
        return p;
    for(i=log; i>=0; i--)
    {
        if(parse[p][i]!=-1 && parse[p][i]!=parse[q][i])
            p=parse[p][i],q=parse[q][i];
    }
    return parent[p];
}

ll kth(ll n,ll p, ll q, ll k)
{
    ll a = lca_query(n,p,q), d ;

    if( a == p )
    {
        d = level[q] - level[p] + 1 ;
        swap(p,q); // ans lies on the q side
        k = d - k + 1 ;
    }
    else if( a == q ) ; // do nothing as ans lies on p side
    else
    {
        if( k > level[p] - level[a] + 1 )   // if k lies form p to lca + lca to ... means ans is on the q side so substact the k from p to lca dist
        {
            d = level[p] + level[q] - 2 * level[a] + 1 ;
            k = d - k + 1 ;
            swap(p,q);
        }
        else ; // do nothing as k lies from p to under the lca means it is in p side
    }
    ll lg ;
    for( lg = 1 ; (1 << lg) <= level[p] ; ++lg )
        ;
    lg--;
    k--;
    for( int i = lg ; i >= 0 ; i-- )
    {
        if( (1 << i) <= k )
        {
            p = parse[p][i];
            k -= ( 1 << i );
        }
    }
    return p;
}

int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll g=n-1;
        vector<pair<ll,ll> >e[10010];
        while(g--)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            e[a].push_back(make_pair(b,c));
        }
        cost[1]=0;
        dfs(e,1,1,0);
        lca_init(n+1);
        while(1)
        {
            cin>>s;
            if(s=="DONE")
            {
                printf("\n");
                break;
            }
            else if(s=="DIST")
            {
                scanf("%lld %lld",&a,&b);
                ll lca=lca_query(n,a,b);
                ll dist=cost[a]+cost[b]-(2*cost[lca]);
                printf("%lld\n",dist);
            }
            else
            {
                scanf("%lld %lld %lld",&a,&b,&k);
                ll knode=kth(n,a,b,k);
                printf("%lld\n",knode);
            }
        }
    }
    return 0;
}

