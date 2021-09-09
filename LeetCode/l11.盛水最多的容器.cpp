//双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] > height[j]) j -- ;
            else i ++ ;
        }
        return res;
    }
};

//单调？
class Solution {
public:
    int maxArea(vector<int>& height) {
        //first存放高度，second存放下标
        vector<pair<int,int>> q;
        int res=0;
        for(int i=0;i<height.size();i++){
            for(int j=0;j<q.size();j++){
                if(!q.empty()) res=max(res,min(height[i],q[j].first)*(i-q[j].second));
                if(!q.empty()&&q[j].first>=height[i]) break;
            }
            if(q.empty()||height[i]>q.back().first) q.push_back({height[i],i});
        }
        return res;
    }
};