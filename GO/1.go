package test

func twoSum(nums []int, target int) []int {
	var diff map[int]int
	diff=make(map[int]int)
	l:= len(nums)
	for i:=0; i<l; i++ {
		index,ok:=diff[nums[i]]
		if(ok){
			return []int{index,i}
		}
		diff[target-nums[i]]=i
	}
	return []int{0}
}