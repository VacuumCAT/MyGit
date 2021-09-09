#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n;

static bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}

int main(){
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end(),cmp);
    int dot=-1,cnt=0;
    for(int i=0;i<vec.size();i++){
        if(dot<vec[i].first){
            dot=vec[i].second;
            cnt++;
        }
    }
    cout<<cnt;
    reutrn 0;
}