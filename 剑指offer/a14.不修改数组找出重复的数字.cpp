class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1; // 划分的区间：[l, mid], [mid + 1, r]
            int s = 0;
            for (auto x : nums) s += x >= l && x <= mid;
            if (s > mid - l + 1) r = mid;
            else l = mid + 1;，
        }
        return r;
    }
};
/*
这道题的难点有2，一个是要求不修改数组，另外一个是要求使用O(1)的额外空间
y总的做法是抽屉原理，这里不解释。
注意这里的l与r是数字大小的上下界，而不是下标！
那么，一开始l=1，r=n，(l+r)/2=(1+n)/2取整
例：n=4 mid=2 数组为{1,1,2,3,4}
那么分为两部分[1,2]和[3,5]
遍历数组，s统计大小在[1,2]范围内的数字出现过的次数
可想而知，s最大不超过3
如果s=3,说明[1,2]这段数据范围的数字其中有一个出现了两次，令r=mid，重新计数
那么l=1,r=2,mid=1，得到最后r=1，返回r即可
*/