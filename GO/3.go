func lengthOfLongestSubstring(s string) int {
	max:=0
	l:=len(s)
    i:=0
    j:=1
    if l==1 {
        return 1
    }
	for ; j<l; j++ {
        pos:=strings.Index(s[i:j],s[j:j+1])
		if pos!=-1 {
			if(j-i>max){
				max=j-i
			}
			i=i+pos+1
		}else if(j==l-1){
			if(j-i+1>max){
				max=j-i+1
			}
		}
	}
    return max
}

// GO中 字符串切片[i:j]
// strings.Contains 返回true/false
// strings.Index 返回索引