///Returns the num between range with update property between range.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mx 1000001
ll arr[mx];
struct info
{
    ll prop,num;
} tree[mx*3];

void create(ll node,ll start,ll end)
{
    if(start==end)
    {
        tree[node].num=arr[start];
        tree[node].prop=0;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(start+end)/2;
    create(left,start,mid);
    create(right,mid+1,end);
    tree[node].num=tree[left].num+tree[right].num;
}

void update(ll node,ll start,ll end,ll i,ll j,ll value)
{
    if(i>end || j<start)
        return;
    if(start>=i && end<=j)
    {
        tree[node].num+=((end-start+1)*value);
        tree[node].prop+=value;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(start+end)/2;
    update(left,start,mid,i,j,value);
    update(right,mid+1,end,i,j,value);
    tree[node].num=tree[left].num+tree[right].num;
}

ll query(ll node,ll start,ll end,ll i,ll j,ll carry=0)
{
    if(i>end || j<start)
        return 0;
    if(start>=i && end<=j)
        return tree[node].num+carry*(end-start+1);
    ll left=node<<1;
    ll right=(node<<1)+1;
    ll mid=(start+end)>>1;
    return query(left,start,mid,i,j,carry+tree[node].prop) + query(right,mid+1,end,i,j,carry+tree[node].prop);
}

int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
        scanf("%lld",&arr[i]);
    create(1,1,n);
    update(1, 1, n, 3, 5, 2);
    cout << query(1, 1, n, 3, 4) << endl;
    update(1, 1, n, 3, 5, -2);
    cout << query(1, 1, n, 3, 4) << endl;
    return 0;
}
