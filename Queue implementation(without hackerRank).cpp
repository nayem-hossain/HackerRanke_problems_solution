#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int main()
{

    queue < string > q;
    int N;
    string input,u;
    cin>>N;
    for(int i=1; i<N; i++)
    {
        cin>>input;
        q.push(input);
    }
    cout<<"the capacity of Queue size is :"<<q.size()<<endl;
    cout<<"the FRONT element of the Queue is :"<<q.front()<<endl;
    cout<<"the REAR element of the Queue is :"<<q.back()<<"\n\n";
    q.pop();
    q.pop();
    q.pop();
    cout<<"after popping the capacity of Queue size is :"<<q.size()<<"\n";
    cout<<"after popping the FRONT element, the front element of the Queue is :"<<q.front()<<endl;
    if(!q.empty())
    {
        cout<<"queue is not empty"<<endl;
    }
    else{
        cout<<"queue is empty"<<endl;
    }
    q.push("a");
    q.push("z");
    cout<< "After Pushing at the REAR position, all element are :"<<"\n\n";
    while(!q.empty()){
		cout<<" "<<q.front();
		q.pop();
	}

}
