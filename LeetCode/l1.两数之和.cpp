//显然暴力算法为O(n^2)
//使用哈希表，时间复杂度可以到O(n)
//这题地位类似于背单词的abandon

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end()) return {i,hash[target-nums[i]]};
            hash[nums[i]]=i;
        }
        return {};
    }
};