#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;
int t,n,k;
int q[110];

unordered_set<int> get_devisors(int x)
{
    unordered_set<int> res;
    for(int i=1;i<=x/i;i++){
        if(x%i==0){
            res.insert(i);
            res.insert(x/i);
        }
    }
    return res;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        memset(q,0,sizeof q);
        auto res=get_devisors(k);
        int ans=1;
        for(int i=0;i<n;i++){
            cin>>q[i];
            if(res.find(q[i])!=res.end()) ans=max(ans,q[i]);
        }
        cout<<k/ans<<endl;
    }
    return 0;
}