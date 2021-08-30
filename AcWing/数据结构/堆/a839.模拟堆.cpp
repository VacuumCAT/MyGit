#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N=100010;

int h[N],ph[N],hp[N],cnt;

void heap_swap(int a,int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}