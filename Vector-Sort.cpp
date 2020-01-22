#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int>v;
    int N,input;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>input;
        v.push_back(input);
    }
    sort(v.begin(),v.end());
    /* for(int j=0;j<v.size();j++)
       {
           cout<<v[j]<<" ";
       }

       OR,

        for (auto x : v){
        cout<< x <<" ";
     }

    */

    for(vector <int> :: iterator it = v.begin(); it != v.end(); it++)
        {
    	   printf("%d  ", *it);
        }

    return 0;
}
