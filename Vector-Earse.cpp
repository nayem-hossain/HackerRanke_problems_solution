#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int>v;
    int N,i,j,inputelement,x,a,b;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>inputelement;
        v.push_back(inputelement);
    }
    cin>>x;
    cin>>a>>b;

    v.erase(v.begin()+x-1);
    v.erase(v.begin()+a-1,v.begin()+b-1);
    int size;
    size=v.size();
    cout<<size<<endl;
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}

