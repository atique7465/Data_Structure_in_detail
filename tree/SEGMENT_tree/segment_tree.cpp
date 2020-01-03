
///Returns the sum between range with update property.
#include<bits/stdc++.h>
using namespace std;
#define mx 1000001
int arr[mx];
int tree[mx*3];

void create(int node,int start,int end) ///complexity O(n log n).
{
    if(start==end)
    {
        tree[node]=arr[start];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(start+end)/2;
    create(left,start,mid);
    create(right,mid+1,end);
    tree[node]=tree[left ]+tree[right];
}

int query(int node,int start,int end,int i,int j) ///complexity O(log n).
{
    if(i>end || j<start)
        return 0;
    if(start>=i && end<=j)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(start+end)/2;
    return query(left,start,mid,i,j) + query(right,mid+1,end,i,j);
}

void update(int node,int start,int end,int i,int value) ///complexity O(log n).
{
    if(i>end || i<start)
        return;
    if(start==i && end==i)
      {
          tree[node]=value;
          return;
      }
    int left=node*2;
    int right=node*2+1;
    int mid=(start+end)/2;
    update(left,start,mid,i,value);
    update(right,mid+1,end,i,value);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int n;
    scanf("%lld",&n);
    for(int i=1; i<=n; i++)
        scanf("%lld",&arr[i]);
    create(1,1,n);
    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 20);
    cout << query(1, 1, n, 2, 2) << endl;
    return 0;
}
