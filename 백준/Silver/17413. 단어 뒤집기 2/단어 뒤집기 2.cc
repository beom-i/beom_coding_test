#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <iomanip>
#include <set>
#include <map>
#include <deque>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string strings;
    getline(cin,strings);
    string str;
    vector<string> vec;
    bool tag_mode = false;
    string output;
    for(char c : strings){
        if(c == '<'){
            // 거꾸로
            if(str!=""){
                for(int i = str.length()-1;i>=0;i--){
                    output+=str[i];
                }
                str="";
            }
            str+=c;
            tag_mode = true;
        }
        else if(c=='>'){
            str+=c;
            output+=str; // 최종 넣음
            str="";
            tag_mode = false;
        }
        else if(c==' ' && !tag_mode){
            // 거꾸로
            for(int i = str.length()-1;i>=0;i--){
                output +=str[i];
            }
            output+=' ';
            str="";
        }
        // tag + 문자
        else if(tag_mode){
            str +=c;
        }
        // tag x + 문자
        else if(!tag_mode){
            str +=c;
        }
    }
    if(str!=""){
        if(str[0] == '<') output+=str;
        else{
            for(int i = str.length()-1;i>=0;i--){
                output +=str[i];
            }
        }
    }
    cout<<output;
    return 0;
}