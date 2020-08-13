func numTrees(n int) int {
	var dynamic []int
	dynamic=make([]int,n+1)
	dynamic[0]=1
	dynamic[1]=1
	for i:=2;i<=n;i++ {
		dynamic[i]=0
		for j:=0;j<i;j++ {
			dynamic[i]+=dynamic[j]*dynamic[i-j-1]
		}
	}
	if n==0 {
		return 0
	}else{
		return dynamic[n]
	}
}

//GO 不能定义动态数组，需要使用切片 make