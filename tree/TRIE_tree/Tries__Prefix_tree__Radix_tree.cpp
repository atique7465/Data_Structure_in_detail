//------------------------------------------------------------------------------------------------------------------
/// resource: http://www.shafaetsplanet.com/?p=1679
/// Time complexity of insertion & searching : O( length of string ).
/// Memory complexity depends on implementation & most importantly the matching probability of prefixes of words.
/// where there's some sort of validation against some other input that's where we'd often end up using Trie.
/// phone number check, string check, dictionary check, check the frequency of prefix, contacts check,
/// longest common substring (not subsequence->DP) and many other application.
//------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct node
{
    bool fullword; /// will define whether the sequence up to that node is a word or not.
    node *next[26 + 1]; /// every node has 26 another nodes as child like child node for 'a', 'b', 'c' and so on.
    node()
    {
        /// a constructor for node.
        fullword = false;
        for(ll i=0; i<26; i++)
            next[i] = NULL;
    }
};

class trie
{
private:
    node *root;
public:
    trie();
    ~trie();
    void Insert(string s);
    bool Search(string s);
    void Delete(node *cur);
};

trie::trie()
{
    root = new node;
}

void trie::Insert(string s)
{
    ll ln = s.size();
    node *cur = root;
    for(ll i = 0; i < ln; i++)
    {
        ll id = s[i] - 'a';
        if(cur->next[id] == NULL)
            cur->next[id] = new node;
        cur = cur->next[id];
    }
    cur->fullword = true;
}

bool trie::Search(string s)
{
    node *cur = root;
    ll ln = s.size();
    for(ll i=0; i<ln; i++)
    {
        ll id = s[i] - 'a';
        if(cur->next[id] == NULL)
            return false;
        cur = cur->next[id];
    }
    return cur->fullword;
}

trie::~trie()
{
    Delete(root);
}

void trie::Delete(node *cur)
{
    /// delete the trie.
    for(ll i=0; i<26; i++)
    {
        if(cur->next[i] != NULL)
            Delete(cur->next[i]);
    }
    delete(cur);
}

int main()
{
    trie T;
    ll n,q;
    string s;
    cout<<"Enter the number of word to be inserted ? ";
    scanf("%lld",&n);
    cout<<"Enter the words one by one"<<endl;
    while(n--)
    {
        cin>>s;
        T.Insert(s);
    }
    cout<<"how many string to be searched ? ";
    scanf("%lld",&q);
    while(q--)
    {
        cout<<"Enter the word to be searched"<<endl;
        cin>>s;
        if(T.Search(s))
            cout<<"FOUND"<<endl;
        else
            cout<<"NOT FOUND"<<endl;
    }
    return 0;
}
