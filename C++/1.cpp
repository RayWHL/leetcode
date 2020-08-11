
//O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=nums.size();
        for(int i=0;i<l;++i){
            for(int j=i+1;j<l;++j){
                if(nums[i]+nums[j]==target)
                    return vector<int>{i,j};
            }
        }
        return {0};
    }
};

//O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diff;
        int l=nums.size();
        for(int i=0;i<l;++i){
            if(diff.count(nums[i])){
                return {diff[nums[i]],i};
            }
            diff[target-nums[i]]=i;
        }
        return {0};
    }
};
