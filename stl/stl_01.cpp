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
int main() {
    vector< int > v;
    v.push_back( 1 );
    v.push_back( 2 );
    v.push_back( 3 );
    v.push_back( 4 );

    for(int i=0; i<v.size(); i++) cout << v[i] << endl;


    vector< int > atique,t;

    atique.push_back(10);
    atique.push_back(11);
    atique.push_back(12);
    atique.push_back(13);
    atique.push_back(14);

    for(int k=0; k<atique.size(); k++) cout<<atique[k]<<endl;

    t=v;
    for(int l=0; l<t.size(); l++) cout<<t[l]<<endl;
    return 0;
}








