#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

bool isValid(string& s) {
    int n = s.size();
    if (n == 0) return true;
    if (n % 2 == 1) return false;

    unordered_map<char, char> hash = {
        {')', '('},
        {'}', '{'},
        {']', '['},
        {'>', '<'}
    };

    stack<char> st;
    for (char c : s) {
        if (hash.count(c)) {    // 如果是右括号
            // 如果栈已空
            if (st.empty()) return false;

            // 如果不匹配
            if (st.top() != hash[c]) return false;

            st.pop();       // 如果匹配，栈顶出栈
        } else {            // 如果是左括号
            st.push(c);     // 入栈
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;
    if (isValid(s)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}