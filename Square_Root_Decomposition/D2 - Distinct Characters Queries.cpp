/// https://codeforces.com/contest/1234/problem/D
/// time complexity O( sqrt(n) );
/// solved by sqrt decomposition

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string s;
ll segment[320][26];
ll temp[26];
ll segment_size,n,q;

void preprocess()
{
    ll current_segment = -1;
    for(ll i=0; i<n; i++)
    {
        if(i%segment_size == 0)
            current_segment++;
        segment[current_segment][s[i]-'a']++;
    }
}

ll query(ll l,ll r) /// time complexity O( sqrt(n) );
{
    memset(temp,0,sizeof(temp));
    while(l<r && l%segment_size != 0) /// iterate until we reach r or a starting index of next segment
    {
        temp[ s[l]-'a' ]++;
        l++;
    }
    while(l + segment_size <= r)  /// iterate until we reach the segment that contains r
    {
        for(ll i=0; i<26; i++)
            temp[i]+= segment[ l / segment_size ][i];
        l += segment_size;
    }

    while(l<=r) /// sum up rest of the values until r
    {
        temp[ s[l]-'a' ]++;
        l++;
    }

    ll sum = 0;
    for(ll i=0; i<26; i++)
    {
        if(temp[i]>0)
            sum++;
    }
    return sum;
}

void update(ll index,char ch) /// time complexity O(1);
{
    segment[ index / segment_size ][ s[index]-'a' ]--;
    segment[ index / segment_size ][ ch-'a' ]++;
    s[index] = ch;
}

int main()
{
    ll type,index,l,r;
    char ch;
    cin>>s;

    n = s.size();
    segment_size = sqrt(n);
    preprocess();

    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld",&type);
        if(type==1)
        {
            scanf("%lld",&index);
            cin>>ch;
            update(index-1,ch);
        }
        else
        {
            scanf("%lld %lld",&l,&r);
            printf("%lld\n",query(l-1,r-1));
        }
    }
    return 0;
}

