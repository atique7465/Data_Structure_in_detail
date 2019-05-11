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
     char line[1000];
    while( gets( line ) ) {
        stringstream ss( line ); // initialize kortesi
        int num; vector< int > v;
        while( ss >> num ) v.push_back( num ); // :P
        sort( v.begin(), v.end() );
        // print routine
    }
    return 0;
}
