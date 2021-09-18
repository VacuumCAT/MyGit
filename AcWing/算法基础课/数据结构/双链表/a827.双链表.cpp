#include <iostream>
using namespace std;

const int N=100010;

int e[N],l[N],r[N],idx;
int m;

void init(){
    r[0]=1;
    l[1]=0;
    idx=2;
}

void insertR(int k,int x){
    e[idx]=x,r[idx]=r[k],l[r[k]]=idx,r[k]=idx,l[idx++]=k;
}

void remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}

int main(){
    cin>>m;
    init();
    string s;
    int x,k;
    while(m--){
        cin>>s;
        if(s=="R"){
            cin>>x;
            insertR(l[1],x);
        }
        else if(s=="L"){
            cin>>x;
            insertR(0,x);
        }
        else if(s=="IL"){
            cin>>k>>x;
            insertR(l[k+1],x);
            
        }
        else if(s=="IR"){
            cin>>k>>x;
            insertR(k+1,x);
        }
        else if(s=="D"){
            cin>>k;
            remove(k+1);
        }
    }
    
    for(int i=r[0];i!=1;i=r[i]){
        cout<<e[i]<<' ';
    }
    return 0;
}