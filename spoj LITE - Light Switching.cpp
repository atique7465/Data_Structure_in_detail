/// Another laxy propagation problem :XD
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mx 100010
struct info
{
    ll lazy,on,off;
    void swap()
    {
        ll tmp=on;
        on=off;
        off=tmp;
    }
    void marge(info left,info right)
    {
        on=left.on+right.on;
        off=left.off+right.off;
    }
} tree[4*mx];

void create(ll node,ll s,ll f)
{
    if(s==f)
    {
        tree[node].on=0;
        tree[node].off=1;
        tree[node].lazy=0;
        return;
    }
    create(node<<1,s,(s+f)>>1);
    create((node<<1)+1,((s+f)>>1)+1,f);
    tree[node].marge(tree[node<<1],tree[(node<<1)+1]);
}

void update(ll node,ll s,ll f,ll i,ll j)
{
    if(i>f || j<s)
        return;
    if(s>=i && f<=j)
    {
        tree[node].lazy+=1;
        tree[node].swap();
        return;
    }
    update(node<<1,s,(s+f)>>1,i,j);
    update((node<<1)+1,((s+f)>>1)+1,f,i,j);
    tree[node].marge(tree[node<<1],tree[(node<<1)+1]);
    if(tree[node].lazy%2==1)
        tree[node].swap();
}

ll query(ll node,ll s,ll f,ll i,ll j,ll carry=0)
{
    if(i>f || j<s)
        return 0;
    if(s>=i && f<=j)
    {
        if(carry%2==1)
            return tree[node].off;
        else
            return tree[node].on;
    }
    ll p1=query(node<<1,s,(s+f)>>1,i,j,carry+tree[node].lazy);
    ll p2=query((node<<1)+1,((s+f)>>1)+1,f,i,j,carry+tree[node].lazy);
    return p1+p2;
}

int main()
{
    ll n,m;
    scanf("%lld %lld",&n,&m);
    create(1,1,n);
    while(m--)
    {
        ll type,p,q;
        scanf("%lld",&type);
        if(type==0)
        {
            scanf("%lld %lld",&p,&q);
            update(1,1,n,p,q);
        }
        else
        {
            scanf("%lld %lld",&p,&q);
            printf("%lld\n",query(1,1,n,p,q));
        }
    }
    return 0;
}
