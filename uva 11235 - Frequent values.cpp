/// I used segment tree consept here . it can be solved using MO's algo or
/// square root decomposition or RMQ approaches.
/// I kept track for 5 values for every node.
#include<bits/stdc++.h>
#define ll long long int
#define sz 100010
using namespace std;
ll arr[sz];
struct info
{
    ll a,b,c,d,mx;
    void marge(info left,info right)
    {
        if(left.d==right.b)
        {
            a=left.a;
            b=left.b;
            c=right.c;
            d=right.d;
            if(left.d!=9999999)
            {
                if(left.b==left.d)
                    a=left.c+right.a;
                if(right.b==right.d)
                    c=left.c+right.a;
                if(left.b!=left.d && right.b!=right.d)
                    mx=max(a,(max(c,left.c+right.a)));
                else
                    mx=max(a,c);
                mx=max(mx,max(left.mx,right.mx));
            }
            else
                mx=max(left.mx,right.mx);
        }
        else
        {
            a=left.a;
            b=left.b;
            c=right.c;
            d=right.d;
            mx=max(left.mx,right.mx);
        }
    }
} tree[4*sz];


void create(ll node,ll s,ll f)
{
    if(s==f)
    {
        tree[node].a=1;
        tree[node].b=arr[s];
        tree[node].c=1;
        tree[node].d=arr[s];
        tree[node].mx=1;
        return;
    }
    ll left=node<<1;
    ll right=(node<<1)+1;
    create(left,s,(s+f)>>1);
    create(right,((s+f)>>1)+1,f);
    tree[node].marge(tree[left],tree[right]);
}

info query(ll node,ll s,ll f,ll i,ll j)
{
    info ans;
    ans.a=1;
    ans.b=9999999;
    ans.c=1;
    ans.d=9999999;
    ans.mx=1;
    if(i>f || j<s)
        return ans;
    if(s>=i && f<=j)
    {
        return tree[node];
    }
    ll left=node<<1;
    ll right=(node<<1)+1;
    info p1=query(left,s,(s+f)>>1,i,j);
    info p2=query(right,((s+f)>>1)+1,f,i,j);
    ans.marge(p1,p2);
    return ans;
}

int main()
{
    //freopen("res.txt","w",stdout);
    //freopen("a.txt","r",stdin);
    ll n,q,i;
    scanf("%lld",&n);
    while(n!=0)
    {
        scanf("%lld",&q);
        for(i=1; i<=n; i++)
            scanf("%lld",&arr[i]);
        create(1,1,n);
        while(q--)
        {
            ll l,r;
            scanf("%lld %lld",&l,&r);
            printf("%lld\n",query(1,1,n,l,r).mx,l,r);
        }
        scanf("%lld",&n);
    }
}
