/// complexity: parse table number of row n and column logn
/// so ,preprocessing complexity O(n long n); and Query complexity O( log n);
/// http://www.shafaetsplanet.com/?p=1831
#include<bits/stdc++.h>
#define ll long long int
#define rep0(i,n) for(i=0; i<(ll)n; i++)
#define rep1(i,n) for(i=1; i<=(ll)n; i++)
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define mp make_pair
#define uu first
#define vv second
#define read(f) freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdin)
#define mx 100000
using namespace std;
ll i,j,n,t;
vector<ll>g[mx];
ll parent[mx];
ll level[mx];
ll parse[mx][20];

void dfs(ll root, ll curr, ll dep)
{
    parent[curr]=root;
    level[curr]=dep;
    for(ll k=0; k<g[curr].size(); k++)
    {
        if(g[curr][k]==root)
            continue;
        dfs(curr,g[curr][k],dep+1);
    }
}

void lca_init(ll n)
{
    memset(parse,-1,sizeof(parse)); /// initialize parse as -1 in all cell.
    for(i=0; i<n; i++) /// initialize the 2^0 th parent of all node.
        parse[i][0]=parent[i];

    for(j=1; (1<<j) < n; j++)
    {
        for(i=0; i<n; i++)
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

int main()
{
    g[0].pb(1);
    g[1].pb(2);
    g[1].pb(8);
    g[2].pb(3);
    g[3].pb(4);
    g[4].pb(5);
    g[5].pb(6);
    g[6].pb(7);
    g[6].pb(14);
    g[8].pb(9);
    g[9].pb(10);
    g[10].pb(11);
    g[11].pb(15);
    g[11].pb(12);
    g[12].pb(16);
    g[12].pb(13);
    dfs(0, 0, 0);
    lca_init(17);
    printf( "The Lowest Common Ancestor is %lld\n", lca_query(17,14,11));
    return 0;
}
