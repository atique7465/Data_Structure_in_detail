/// A Simple segment tree problem  :XD
#include<bits/stdc++.h>
#define ll long long int
#define mx 100010
using namespace std;
ll arr[mx];
ll tree[4*mx];

void create(ll node,ll s,ll f)
{
    if(s==f)
    {
        tree[node]=arr[s];
        return;
    }
    create(node<<1,s,((s+f)>>1));
    create((node<<1)+1,((s+f)>>1)+1,f);
    tree[node]=tree[node<<1]+tree[(node<<1)+1];
}

void update(ll node,ll s,ll f,ll i,ll v)
{
    if(i>f || i<s)
        return;
    if(s==i && f==i)
    {
        if(v==0)
        {
            printf("%lld\n",tree[node]);
            tree[node]=0;
        }
        else
            tree[node]+=v;
        return;
    }
    update(node<<1,s,((s+f)>>1),i,v);
    update((node<<1)+1,((s+f)>>1)+1,f,i,v);
    tree[node]=tree[node<<1]+tree[(node<<1)+1];
}

ll query(ll node,ll s,ll f,ll i,ll j)
{
    if(i>f || j<s)
        return 0;
    if(s>=i && f<=j)
    {
        return tree[node];
    }
    return query(node<<1,s,((s+f)>>1),i,j)+query((node<<1)+1,((s+f)>>1)+1,f,i,j);
}

int main()
{
    ll t,i;
    scanf("%lld",&t);
    ll cas=1;
    while(cas<=t)
    {
        ll n,q;
        scanf("%lld %lld",&n,&q);
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        create(1,1,n);
        printf("Case %lld:\n",cas);
        while(q--)
        {
            ll type,l,r,v;
            scanf("%lld",&type);
            if(type==1)
            {
                scanf("%lld",&l);
                update(1,1,n,l+1,0);
            }
            else if(type==2)
            {
                scanf("%lld %lld",&l,&v);
                update(1,1,n,l+1,v);
            }
            else
            {
                scanf("%lld %lld",&l,&r);
                printf("%lld\n",query(1,1,n,l+1,r+1));
            }
        }
        cas++;
    }
    return 0;
}
