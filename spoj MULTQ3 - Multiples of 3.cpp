#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mx 1000001
struct info
{
    ll lazy,count_0,count_1,count_2;
    void swap()
    {
        ll tmp=count_0;
        count_0=count_2;
        count_2=count_1;
        count_1=tmp;
    }
    void marge(info left,info right)
    {
        count_0=left.count_0+right.count_0;
        count_1=left.count_1+right.count_1;
        count_2=left.count_2+right.count_2;
    }
} tree[mx*4];

void create(ll node,ll start,ll end)
{
    if(start==end)
    {
        tree[node].count_0=1;
        tree[node].count_1=tree[node].count_2=0;
        tree[node].lazy=0;
        return;
    }
    create(node<<1,start,(start+end)>>1);
    create((node<<1)+1,((start+end)>>1)+1,end);
    tree[node].marge(tree[node<<1],tree[(node<<1)+1]);
}

void update(ll node,ll start,ll end,ll i,ll j)
{
    if(i>end || j<start)
        return;
    if(start>=i && end<=j)
    {
        tree[node].lazy+=1;
        tree[node].swap();
        return;
    }
    update(node<<1,start,(start+end)>>1,i,j);
    update((node<<1)+1,((start+end)>>1)+1,end,i,j);
    tree[node].marge(tree[node<<1],tree[(node<<1)+1]);
    if(tree[node].lazy%3==1)
        tree[node].swap();
    else if (tree[node].lazy%3==2)
    {
        tree[node].swap();
        tree[node].swap();
    }
}

ll query(ll node,ll start,ll end,ll i,ll j,ll carry=0)
{
    if(i>end || j<start)
        return 0;
    if(start>=i && end<=j)
    {
        if(carry%3==1)
            return tree[node].count_2;
        else if(carry%3==2)
        {
            return tree[node].count_1;
        }
        return tree[node].count_0;
    }
    ll p1=query(node<<1,start,(start+end)>>1,i,j, carry+tree[node].lazy);
    ll p2=query((node<<1)+1,((start+end)>>1)+1,end,i,j,carry+tree[node].lazy);
    return p1+p2;
}

int main()
{
    ll n,q;
    scanf("%lld %lld",&n,&q);
    create(1,1,n);
    while(q--)
    {
        ll cas,a,b;
        scanf("%lld %lld %lld",&cas,&a,&b);
        if(cas==0)
            update(1,1,n,a+1,b+1);
        else
            printf("%lld\n",query(1,1,n,a+1,b+1));
    }
    return 0;
}
