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

void pushdown(ll n)
{
    ll temp=tree[n].lazy%3;
    if(temp==1)
    {
        tree[n<<1].swap();
        tree[(n<<1)+1].swap();

    }
    else
    {
        tree[n<<1].swap();
        tree[(n<<1)+1].swap();
        tree[n<<1].swap();
        tree[(n<<1)+1].swap();
    }
    tree[n<<1].lazy+=tree[n].lazy;
    tree[(n<<1)+1].lazy+=tree[n].lazy;
    tree[n].lazy=0;
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
    if((tree[node].lazy%3)!=0)
    {
        pushdown(node);
    }
    update(node<<1,start,(start+end)>>1,i,j);
    update((node<<1)+1,((start+end)>>1)+1,end,i,j);
    tree[node].marge(tree[node<<1],tree[(node<<1)+1]);
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
///solution 02
/*
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


void pushdown(ll n)
{
    ll temp=tree[n].lazy%3;
    if(temp==1)
    {
        tree[n<<1].swap();
        tree[(n<<1)+1].swap();

    }
    else
    {
        tree[n<<1].swap();
        tree[(n<<1)+1].swap();
        tree[n<<1].swap();
        tree[(n<<1)+1].swap();
    }
    tree[n<<1].lazy+=tree[n].lazy;
    tree[(n<<1)+1].lazy+=tree[n].lazy;
    tree[n].lazy=0;
}


void update(ll node,ll start,ll end,ll i,ll j)
{
    if(i>end || j<start)
        return;
    if(start>=i && end<=j)
    {
        tree[node].lazy+=1;
        tree[node].swap();
        //cout<<"up "<<start<<" "<<end<<" "<<tree[node].count_0<<" "<<tree[node].count_1<<" "<<tree[node].count_2<<endl;
        return;
    }
    if((tree[node].lazy%3)!=0)
    {
        pushdown(node);
    }

    update(node<<1,start,(start+end)>>1,i,j);
    update((node<<1)+1,((start+end)>>1)+1,end,i,j);
    tree[node].marge(tree[node<<1],tree[(node<<1)+1]);
    // cout<<"up "<<start<<" "<<end<<" "<<tree[node].count_0<<" "<<tree[node].count_1<<" "<<tree[node].count_2<<endl;
}

ll query(ll node,ll start,ll end,ll i,ll j)
{
    if(i>end || j<start)
        return 0;
    if(start>=i && end<=j)
    {
        return
         tree[node].count_0;
    }
    if((tree[node].lazy%3)!=0)
    {
        pushdown(node);
        tree[node].lazy=0;
    }
    ll p1=query(node<<1,start,(start+end)>>1,i,j);
    ll p2=query((node<<1)+1,((start+end)>>1)+1,end,i,j);
    return p1+p2;
}

int main()
{
    ll n,q;
    //freopen("aaa.txt","w",stdout);
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
}*/

///solution 3
/*
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int lazy[4*N];
struct segment
{
    int _count0,_count1,_count2;
    void add()
    {
        int temp=_count0;
        _count0=_count2;
        _count2=_count1;
        _count1=temp;
    }
    void mergee(segment left,segment right)
    {
        _count0=left._count0+right._count0;
        _count1=left._count1+right._count1;
        _count2=left._count2+right._count2;
    }
} seg[4*N];

void build(int low,int high,int node)
{
    if(low>high)
        return;
    if(low == high)
    {
        seg[node]._count0=1;
        seg[node]._count1=0;
        seg[node]._count2=0;
        return ;
    }
    int mid=low+high>>1;
    build(low,mid,node<<1);
    build(mid+1,high,(node<<1)+1);
    seg[node].mergee(seg[node<<1],seg[(node<<1)+1]);
}
void update(int low,int high,int lq,int hq,int node)
{
    if(lazy[node]%3 == 1)
    {
        seg[node].add();
        if(low!=high)
        {
            lazy[node<<1]+=lazy[node]%3;
            lazy[(node<<1)+1]+=lazy[node]%3;
        }
    }
    else if(lazy[node]%3 == 2)
    {
        seg[node].add();
        seg[node].add();
        if(low!=high)
        {
            lazy[node<<1]+=lazy[node]%3;
            lazy[(node<<1)+1]+=lazy[node]%3;
        }
    }
    else if(lazy[node] && lazy[node]%3 == 0)
    {
        if(low!=high)
        {
            lazy[node<<1]+=lazy[node]%3;
            lazy[(node<<1)+1]+=lazy[node]%3;
        }
    }
    lazy[node]=0;
    if(low>high || low>hq || high<lq)
        return;
    if(lq<=low && high<=hq)
    {
        seg[node].add();
        if(low!=high)
        {
            lazy[node<<1]+=1;
            lazy[(node<<1)+1]+=1;
        }
        //cout<<low<<" "<<high<<" "<<seg[node]._count0<<" "<<seg[node]._count1<<" "<<seg[node]._count2<<endl;
        return;
    }
    int mid=low+high>>1;
    update(low,mid,lq,hq,node<<1);
    update(mid+1,high,lq,hq,(node<<1)+1);
    seg[node].mergee(seg[node<<1],seg[(node<<1)+1]);
    //cout<<low<<" "<<high<<" "<<seg[node]._count0<<" "<<seg[node]._count1<<" "<<seg[node]._count2<<endl;
}

segment query(int low,int high,int lq,int hq,int node)
{
    segment ans;
    ans._count0=0;
    ans._count1=0;
    ans._count2=0;
    if(lazy[node]%3 == 1)
    {
        seg[node].add();
        if(low!=high)
        {
            lazy[node<<1]+=lazy[node];
            lazy[(node<<1)+1]+=lazy[node];
        }
    }
    else if(lazy[node]%3 == 2)
    {
        seg[node].add();
        seg[node].add();
        if(low!=high)
        {
            lazy[node<<1]+=lazy[node];
            lazy[(node<<1)+1]+=lazy[node];
        }
    }
    else if(lazy[node] && lazy[node]%3 == 0)
    {
        if(low!=high)
        {
            lazy[node<<1]+=lazy[node];
            lazy[(node<<1)+1]+=lazy[node];
        }
    }
    lazy[node]=0;
    if(low>high || low>hq || high<lq)
        return ans;
    if(lq<=low && high<=hq)
    {
        return seg[node];
    }
    int mid=low+high>>1;
    segment left = query(low,mid,lq,hq,node<<1);
    segment right = query(mid+1,high,lq,hq,(node<<1)+1);
    ans.mergee(left,right);
    return ans;
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    int type,a,b;
    build(1,n,1);
    while(q--)
    {
        scanf("%d %d %d",&type,&a,&b);
        if(type)
        {
            printf("%d\n",query(1,n,a+1,b+1,1)._count0);
        }
        else
        {
            update(1,n,a+1,b+1,1);
        }
    }
    return 0;
}
*/
