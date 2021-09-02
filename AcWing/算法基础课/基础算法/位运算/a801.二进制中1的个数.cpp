#include <iostream>
using namespace std;

const int N=100010;
int n;
int q[N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    for(int i=0;i<n;i++){
        int res=0;
        while(q[i]){
            res++;
            q[i]=q[i]&(q[i]-1);
        }
        printf("%d ",res);
    }
    return 0;
}
//求n的最后一位数字：(lowbit(x))
//x&-x
//求n的二进制表示第k位是几？n=n>>k&1;

//y总的代码用的是：lowbit
//二进制负数计数用补码：取反加1
//那么~x为x每一位取反后+1
//那么第一个进位的位置（是1）与原码按位与后就被保存下来了