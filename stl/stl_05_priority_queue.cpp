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
  priority_queue< int > q;
    q.push( 10230 ); // inserting 10230
    q.push( 1021 ); // inserting 1021
    q.push( 102322 ); // inserting 102322

    while( !q.empty() ) {
        cout << q.top() << endl; // printing the top
        q.pop(); // removing that one
    }

    priority_queue< int > q2;
    q2.push(551354);
    q2.push(54684843);
    q2.push(54);

    while(!q2.empty()){
        cout<<q2.top()<<endl;
        q2.pop();
    }
    return 0;
}
