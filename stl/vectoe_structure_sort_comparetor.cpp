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
struct data
{
    char name [100];
    int height,weight;
    long long income;
}input;

bool comparetor(data x,data y)
{
    if(x.income==y.income){
        if(x.height==y.height){
            if(x.weight==y.weight)
                return strlen(x.name)<strlen(y.name);
            else
                return x.weight<y.weight;
        }
        else
            return x.height>y.height;
    }
    else
        return x.income>y.income;
}


/*int main()
{
    int n,i,j;
    cin>>n;
    data arr[100];
    for(i=0;i<n;i++)
    {
        cin>>arr[i].a>>arr[i].b;

    }
    sort(arr,arr+n,atik);
    cout<<"\n\nAfter sorting : ";

    for(i=0;i<n;i++)
    {
        cout<<arr[i].a<<"  "<<arr[i].b<<"\n";
    }*/
  int main()
  {
      int n,i,j;
      cin>>n;
      vector< data > v;
      //data arr[100];
      for(i=0; i<n; i++){
        //cin>>arr[i].name>>arr[i].height>>arr[i].weight>>arr[i].income;
        cin>>input.name>>input.height>>input.weight>>input.income;
        v.push_back(input);
      }

      //sort(arr,arr+n,comparetor);
      sort(v.begin(),v.end(),comparetor);
      cout<<"\n\nAfter sorting : "<<endl;

      for(i=0;i<n; i++){
        cout<<v[i].name<<endl;
      }

    return 0;
}




