// Author: Nimish Khurana
#include<bits/stdc++.h>
using namespace std;

bool checkBalanced(const string &s) {
    bool isBalanced = true;
    stack<char> st;

    // Maps closing brackets to opening brackets (Just to make code clean, otherwise there will be more if else conditions)
    map<char, char> mp = { {')','('}, {']', '['}, {'}', '{'} };

    for(char c: s) {
        // Opening bracket
        if(mp.find(c) == mp.end()) {
            st.push(c);
        }

        // Closing bracket
        else {
            // Check if top of stack matches(opening bracket) matches with current closing bracket
            if(st.empty() || st.top() != mp[c]) {
                isBalanced = false;
                break;
            }
            st.pop();
        }
    }

    if(!st.empty()) 
        isBalanced = false;
    return isBalanced;
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        string s;
        cin>>s;
        bool isBalanced = checkBalanced(s);
        if(isBalanced) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
}
