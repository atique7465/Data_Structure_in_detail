/// time complexity O( sqrt(n) );
/// resource: http://www.shafaetsplanet.com/?p=3416
/// two types of query:
/// type 01 -> update a value in an array
/// type 02 -> print the sum between a range l & r

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll segment[10000];
ll segment_size,n,q,input[100000000];

void preprocess()
{
    ll current_segment = -1;
    for(ll i=0; i<n; i++)
    {
        if(i%segment_size == 0)
            current_segment++;
        segment[current_segment]+=input[i];
    }
}

ll query(ll l,ll r) /// time complexity O( sqrt(n) );
{
    ll sum = 0;
    while(l<r && l%segment_size != 0) /// iterate until we reach r or a starting index of next segment
    {
        sum+=input[l];
        l++;
    }
    while(l + segment_size <= r)  /// iterate until we reach the segment that contains r
    {
        sum += segment[ l / segment_size ];
        l += segment_size;
    }
    while(l<=r) /// sum up rest of the values until r
    {
        sum += input[l];
        l++;
    }
    return sum;
}

void update(ll index,ll value) /// time complexity O(1);
{
    segment[ index / segment_size ] -= input[index];
    segment[ index / segment_size ] += value;
    input[index] = value;
}

int main()
{
    ll type,index,l,r,value;
    cout<<"Enter the number of values : ";
    cin>>n;
    for(ll i=0; i<n; i++)
        cin>>input[i];

    segment_size = sqrt(n);
    cout<<segment_size<<endl;
    preprocess();

    cout<<"Enter the number of query : ";
    cin>>q;
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>index>>value;
            update(index-1,value);
        }
        else
        {
            cin>>l>>r;
            cout<<query(l-1,r-1)<<endl;
        }
    }
    return 0;
}
