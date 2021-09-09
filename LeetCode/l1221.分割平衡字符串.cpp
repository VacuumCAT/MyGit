class Solution {
public:
    int balancedStringSplit(string s) {
        int l=0,r=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') l++;
            else r++;
            if(l==r){
                cnt++;
            }
        }
        return cnt;
    }
};