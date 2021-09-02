class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        for (auto x : nums)
            if (x < 0 || x >= n)
                return -1;
        for (int i = 0; i < n; i ++ ) {
            while (nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
            if (nums[i] != i) return nums[i];
        }
        return -1;
    }
};

/*
这道题的优化之处在于用给定的nums数组来存储自身出现过的数字。
对于任意遍历到的元素x，应当有nums[x]=x
也就是说nums[0]=0,nums[1]=1……以此类推
如果遍历到一个新的元素nums[i],把它放在它应该在的位置即nums[nums[i]]上
只有两种情况停止交换
1.nums[i]=nums[nums[i]]=i
这种情况下，说明将i放到了它该在的位置上，继续i++循环即可
2.nums[i]=nums[nums[i]]!=i
这种情况下，说明当前位置存放的数字与它的下标不符，但数组中仍然有两数相同，返回nums[i]
以上。
*/