#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    string compress(string str) {
        stack<int> st;
        for(int i=0;i<str.size();i++){
            if(str[i]=='['){
                st.push(i);
            }
            else if(str[i]==']'){
                int l=st.top()+1;
                st.pop();
                string ns;
                int m=0;
                while(l<i){
                    while(isdigit(str[l])){
                        m=m*10+str[l]-'0';
                        l++;
                    }
                    if(str[l]=='|') continue;
                    ns+=str[l];
                    l++;
                }
                return str;
                while(m--){
                    ns+=ns;
                }
                string tmp=str.substr(0,l)+ns+str.substr(i+1,str.size()+1);
                str=tmp;
            }
        }
        return str;
    }
};

int main(){
    string s="HG[3|B[2|CA]]F";
    Solution sol;
    string ans=sol.compress(s);
    return 0;
}

















