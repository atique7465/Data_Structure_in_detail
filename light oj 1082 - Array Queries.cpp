///Returns the minimum value between range using segment tree.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mx 100010
#define inf 99999999
ll arr[mx];
ll tree[3*mx];

void create(ll node,ll start,ll end)
{
    if(start==end)
    {
        tree[node]=arr[start];
        return;
    }
    ll left=2*node;
    ll right=2*node+1;
    ll mid=(start+end)/2;
    create(left,start,mid);
    create(right,mid+1,end);
    tree[node]=min(tree[left],tree[right]);
}

ll query(ll node,ll start,ll end,ll i,ll j)
{
    if(i>end || j<start)
        return inf;
    else if(start>=i && end<=j)
        return tree[node];
    ll left=2*node;
    ll right=2*node+1;
    ll mid=(start+end)/2;
    return min(query(left,start,mid,i,j),query(right,mid+1,end,i,j));
}

int main()
{
    ll t;
    scanf("%lld",&t);
    ll cas=1;
    while(cas<=t)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        for(ll i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
        create(1,1,n);
        printf("Case %lld:\n",cas);
        while(q--)
        {
            ll l,r;
            scanf("%lld %lld",&l,&r);
            printf("%lld",query(1,1,n,l,r));
            printf("\n");
        }
        cas++;
    }
    return 0;
}
