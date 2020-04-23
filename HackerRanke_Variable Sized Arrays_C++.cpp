#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int index,query,no_value;

    cin>> index >> query;

    int *arr[index];
    for(int i=0; i<index; i++)
    {
        cin>>no_value;
        arr[i] = new int[no_value];

        for(int j=0; j<no_value; j++)
        {
            cin>>arr[i][j];
        }

    }
    for(int i=0; i<query; i++)
    {
        int val1,val2;
        cin>>val1,val2;
        cout<<arr[val1][val2]<<endl;
    }

    return 0;

}
