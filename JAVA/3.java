class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max=0;
        int l=s.length();
        int i,j;
        if(l==1) return 1;
        for(i=0,j=1;j<l;){
            int pos=s.substring(i,j).indexOf(s.charAt(j));
            if(pos!=-1){
                if(j-i>max) max=j-i;
                i=i+pos+1;
            }else if(j==l-1){
                if(j-i+1>max) max=j-i+1;
            }
            ++j;
        }
        return max;
    }
}

//java substring 为开始结束索引