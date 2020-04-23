#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,q;
    cin>>n>>q;
    vector < vector<int> > arr;  //initialize 2D vector
    for(int i=0; i<n; i++)
    {
        int num_value;
        cin>>num_value;

        vector<int>temp;

        for(int j=0; j<num_value; j++)
        {
            int item;
            cin>>item;
            temp.push_back(item);
        }
        arr.push_back(temp);

    }

    for(int k=0; k<q; k++)
    {
        int x,y;
        cin>>x>>y;
        cout<<arr[x][y]<<endl;
    }

    return 0;
}
