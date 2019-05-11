#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
int main()
{
    set< int > s;
    s.insert( 10 ); s.insert( 5 ); s.insert( 9 );

    set< int > :: iterator it;
    for(it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }

    set<int>st;
    st.insert(13);
    st.insert(10);
    st.insert(5);
    st.insert(17);
    st.insert(15);
    st.insert(11);
    st.insert(9);

    set<int>:: iterator r;
    for(r=st.begin(); r!=st.end(); r++){
        cout<<*r<<endl;
    }
return 0;
}
