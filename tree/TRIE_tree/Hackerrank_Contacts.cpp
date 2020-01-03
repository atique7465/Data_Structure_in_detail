/// solution 01: using trie data structure.
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node
{
    ll fullword;
    node *next[26+1];
    node()
    {
        fullword = 0;
        for(ll i=0; i<26; i++)
            next[i] = NULL;
    }
};

class trie
{
private:
    node *root;
public:
    trie(){root = new node;}
    ~trie(){Delete(root);}

    void Delete(node *cur)
    {
        for(int i=0; i<26; i++)
        {
            if(cur->next[i] != NULL)
                Delete(cur->next[i]);
        }
        delete(cur);
    }

    void Insert(string s){add(root,s,0);}

    void add(node *cur, string s, ll i)
    {
        if(i > s.size())
            return;
        ll id = s[i] - 'a';
        if(cur->next[id] == NULL)
        {
            cur->next[id] = new node;
            add(cur->next[id], s, i+1);
        }
        else
            add(cur->next[id], s, i+1);
        cur->fullword++;
    }

    ll Search(string s)
    {
        node *cur = root;
        ll ln = s.size();
        for(ll i=0; i<ln; i++)
        {
            ll id = s[i] - 'a';
            if(cur->next[id]==NULL)
                return 0;
            cur = cur->next[id];
        }
        return cur->fullword;
    }
};

int main()
{
    ll n;
    trie T;
    string a,b;
    scanf("%lld",&n);
    while(n--)
    {
        cin>>a>>b;
        if(a == "add")
            T.Insert(b);
        else
            printf("%lld\n",T.Search(b));
    }
    return 0;
}

///solution 02: using map.
/* /// got tle
#include<bits/stdc++.h>
#define ll long long int
#define rep0(i,n) for(i=0; i<(ll)n; i++)
#define rep1(i,n) for(i=1; i<=(ll)n; i++)
#define pb(x) push_back(x)
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define mp make_pair
#define pi 3.1415926535897932384626433832795
using namespace std;
map<string,ll>m;
ll i,j;
void add(string s)
{
    ll ln=s.size();
    string p;
    for(j=0; j<ln; j++)
    {
        p+=s[j];
        if(!m.count(p))
            m[p]=1;
        else
            m[p]++;
    }
}

ll freq(string s)
{
    if(!m.count(s))
        return 0;
    else
        return m[s];
}

int main()
{
    ll n;
    scanf("%lld",&n);
    string o,s;
    while(n--)
    {
        cin>>o>>s;
        if(o=="add")
            add(s);
        else
        {
            printf("%lld\n",freq(s));
        }
    }
    return 0;
}
*/
