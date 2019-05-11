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
    stack< int > st;
    st.push( 100 ); // inserting 100
    st.push( 101 ); // inserting 101
    st.push( 102 ); // inserting 102

    while( !st.empty() ) {
        cout << st.top() << endl; // printing the top
        st.pop(); // removing that one
    }

    stack< int > st2;
    st2.push(200);
    st2.push(201);
    st2.push(202);

    while(!st2.empty()){
        cout<<st2.top()<<endl;
        st2.pop();
    }

    return 0;

    }

