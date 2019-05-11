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
queue< int > q;
    q.push( 100 ); // inserting 100
    q.push( 101 ); // inserting 101
    q.push( 102 ); // inserting 102

    while( !q.empty() ) {
        cout << q.front() << endl; // printing the front
        q.pop(); // removing that one
    }

    queue< int > q2;

    q2.push(200);
    q2.push(201);
    q2.push(202);

    while(!q2.empty()){
        cout<<q2.front()<<endl;
        q2.pop();
    }

    return 0;
}
