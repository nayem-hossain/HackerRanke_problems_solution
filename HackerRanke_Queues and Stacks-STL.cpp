#include<bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
    //Write your code here
    public:
    stack<char>stk;
    queue<char>qu;

    char sc,qc;

    void pushCharacter(char pus)
    {
        stk.push(pus);
    }
    void enqueueCharacter(char enq)
    {
        qu.push(enq);
    }
    char popCharacter()
    {
        sc = stk.top();
        stk.pop();
        return sc;
    }
    char dequeueCharacter()
    {
        qc = qu.front();
        qu.pop();
        return qc;
    }

};

int main() {
    // read the string s.
    string s;
    getline(cin, s);

  	// create the Solution class object obj.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}
