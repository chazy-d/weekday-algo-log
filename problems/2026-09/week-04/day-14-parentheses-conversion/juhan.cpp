#include <bits/stdc++.h>
using namespace std;

bool isCorrect(string &s){
    if(s=="")return true;
    stack<char>st;
    for(char& c:s){
        if(c=='(')st.push(c);
        else{
            if(st.empty())return false;
            st.pop();
        }
    }
    if(!st.empty())return false;
    return true;
}
int index(string &s){
    int pre=0, per=0;
    for(int i=0;i<(int)s.size();++i){
        if(s[i]=='(') pre++;
        else per++;
        if(pre==per && pre!=0) return i;
    }
    return -1;
}
string opposite(string &s){
    string ss;
    for(int i=1;i<(int)s.size()-1;++i){
        if(s[i]=='(') ss+=')';
        else ss+='(';
    }
    return ss;
}
string f(string &s){
    if(isCorrect(s))return s;
    int idx=index(s);
    string s1=s.substr(0,idx+1); string s2=s.substr(idx+1);
    if(isCorrect(s1)) return s1+f(s2);
    return '('+f(s2)+')'+opposite(s1);
}

string solution(string p) {
    string answer = "";
    if(p=="")return answer;
    answer=f(p);

    return answer;
}
