#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

unordered_map<char, char> matHash = {
    {'}', '{'},
    {']', '['},
    {')', '('},
    {'>', '<'}
};

unordered_map<char, int> priHash = {
    {'{', 1},
    {'[', 2},
    {'(', 3},
    {'<', 4}
};


bool isValid(string& s) {
    int n = s.size();
    if (n == 0) return true;
    if (n % 2 == 1) return false;

    stack<char> st;
    for (char c : s) {
        if (matHash.count(c)) {    // 如果是右括号
            // 如果栈已空
            if (st.empty()) return false;

            // 如果不匹配
            if (st.top() != matHash[c]) return false;

            st.pop();       // 如果匹配，栈顶出栈
        } else {            // 如果是左括号
            if (!st.empty()) {
                // 如果前面一个括号优先级高
                if (priHash[st.top()] > priHash[c]) return false;
            }

            st.push(c);     // 入栈
        }
    }

    return st.empty();
}

void input() {
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (isValid(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    input();
    return 0;
}