#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    vector<int>vect;
     int n,input;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        vect.push_back(input);
    }
    /*OR,
   
    int m;
    cin>>m;
    vector<int>vect(m);
    for (int i = 0; i < m; i++){
       cin >> vect[i];
    }
    */
    int Queries,Q_value;
    cin>>Queries;
    while(Queries--){
        cin>>Q_value;
       vector<int>::iterator lower;
       lower=lower_bound(vect.begin(),vect.end(),Q_value);
       if(vect[lower-vect.begin()]==Q_value){
        cout<<"Yes "<<(lower-vect.begin())+1<<endl;/*the output formate shows the index(which is 1-based).
                                                   thats why, we added the number 1  */
       }
       else{
        cout<<"No "<<(lower-vect.begin())+1<<endl;
       }
    }
    return 0;
}

