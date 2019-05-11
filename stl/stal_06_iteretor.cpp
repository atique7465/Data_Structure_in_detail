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
vector< int > v;
 v.push_back( 1 );
  v.push_back( 2 );
   v.push_back( 3 );

    vector< int > :: iterator i;
    for( i = v.begin(); i < v.end(); i++ ) {
        printf("%d\n", *i);
        // ei khane gola kato!
    }
   return 0;
}
