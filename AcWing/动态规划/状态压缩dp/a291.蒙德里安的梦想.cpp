//朴素写法
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 12, M = 1 << N;

int n, m;
//f[i][j]表示从第i-1列插到第i列且状态为j的情况下，又多少种合法的方案
//j的二进制位表示了这一列的状态
long long f[N][M];
bool st[M];

int main()
{
    while (cin >> n >> m, n || m)
    {
        //预处理出所有的情况
        //i从0到(1<<n)-1
        //如果这一列所有连续的空着的位置（用0表示）都为偶数则合法

        for (int i = 0; i < 1 << n; i ++ )
        {
            int cnt = 0;
            st[i] = true;
            for (int j = 0; j < n; j ++ )
                //如果i的第j位是1
                if (i >> j & 1)
                {
                    //如果此时，前面的0的个数是奇数，st[i]=false
                    if (cnt & 1) st[i] = false;
                    //记得清空cnt
                    cnt = 0;
                }
                //是0的话，cnt++
                else cnt ++ ;
            //当循环结束，可能此时还没有遇到1，因此需要判断x
            if (cnt & 1) st[i] = false;
        }
        //这样预处理之后，我们就可以很容易地判断一个状态是否合法

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        //从第一列开始遍历
        //第二层循环为状态j
        //第三层循环为下一层状态k
        //如果j与k 的组合状态合法，就令方案数加f[i-1][k]
        for (int i = 1; i <= m; i ++ )
            for (int j = 0; j < 1 << n; j ++ )
                for (int k = 0; k < 1 << n; k ++ )
                    if ((j & k) == 0 && st[j | k])
                        f[i][j] += f[i - 1][k];

        //前0~m-1列已经摆好
        cout << f[m][0] << endl;
    }
    return 0;
}

//去除无效状态的优化写法
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << N;

int n, m;
LL f[N][M];
vector<int> state[M];
bool st[M];

int main()
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < 1 << n; i ++ )
        {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                }
                else cnt ++ ;
            if (cnt & 1) is_valid = false;
            st[i] = is_valid;
        }

        for (int i = 0; i < 1 << n; i ++ )
        {
            state[i].clear();
            for (int j = 0; j < 1 << n; j ++ )
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
        }

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= m; i ++ )
            for (int j = 0; j < 1 << n; j ++ )
                for (auto k : state[j])
                    f[i][j] += f[i - 1][k];

        cout << f[m][0] << endl;
    }

    return 0;
}
