#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

/*
1.数字，直接加入
2.括号：
    （入栈，）不入栈直到弹出（
3.运算符：
    若优先级高于栈顶运算符或栈顶为（则直接入栈
    若优先级低于或等于栈顶运算符，则依次弹出栈中运算符并加入后缀表达式，
    直到栈空 栈顶为（ 或遇到优先级更低的运算符，再将当前运算符入栈
*/
unordered_map<char,int> high;

string midToSuf(string& s){
    int n = s.size();
    string res = "";
    stack<char> st;
    for(int i = 0; i < n; i++){
        char x = s[i];
        if(x >= '0' && x <= '9'){
            res += x;
        }else if(x == '(' || x == ')'){
            if(x == '('){
                st.push('(');
            }else{
                while(!st.empty() && st.top() != '('){
                    res += st.top();
                    st.pop();
                }
                if(st.top() == '(')st.pop();
            }
        }else{
            while (!st.empty() && st.top() != '(' && high[st.top()] >= high[x]) {
                res += st.top();
                st.pop();
            }
            st.push(x); 
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    high['*'] = 1;
    high['/'] = 1;
    high['+'] = 0;
    high['-'] = 0;
    string s = "1+2*(3-4)-5/6";
    cout<<"转换后的表达式为：";
    cout<<midToSuf(s)<<endl;
    return 0;
}