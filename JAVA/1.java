class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> diff = new HashMap<Integer, Integer>();
        int l=nums.length;
        for(int i=0; i<l; ++i){
            if(diff.containsKey(nums[i])){
                return new int[]{diff.get(nums[i]),i};
            }
            diff.put(target-nums[i],i);
        }
        return new int[]{0};
    }
}