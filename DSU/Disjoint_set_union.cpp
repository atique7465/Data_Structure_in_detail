///Maintaining a balance tree, will reduce complexity
///of union and find function from N to log2N.

///When we use Weighted-union with path compression it takes
///log * N for each union find operation,where N is the number of
///elements in the set.

///log *N is the iterative function which computes the number of
///times you have to take log of N till the value of N doesn’t reaches
///to 1.

///log*N is much better than log N, as its value reaches at most up to 5
/// in the real world.

///http://www.shafaetsplanet.com/?p=763
///https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
///https://cp-algorithms.com/data_structures/disjoint_set_union.html

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll parent[100];
ll sz[100],i,j,n;

void init()
{
    for(i=0; i<n; i++)
    {
        parent[i]=i;
        sz[i]=1;
    }
}

ll find_root(ll v)  ///path compression.
{
    if(v==parent[v])
        return v;
    return parent[v]=find_root(parent[v]);
}

void union_by_size(ll a,ll b)  /// balancing the tree.
{
    ll root_a=find_root(a);
    ll root_b=find_root(b);
    if(root_a!=root_b)
    {
        if(sz[root_a]<sz[root_b])
        {
            parent[root_a]=parent[root_b];
            sz[root_b]+=sz[root_a];
        }
        else
        {
            parent[root_b]=parent[root_a];
            sz[root_a]+=sz[root_b];
        }
    }
}

/*
int main()
{

    return 0;
}
*/
