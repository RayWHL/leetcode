class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=s.length();
        if(l==1) return 1;
        int i,j;
        int max=0;
        for(i=0,j=1;j<l;++j){
            int pos=s.substr(i,j-i).find(s[j]);
            if(pos!=-1){
                if(j-i>max) max=j-i;
                i+=pos+1;
                continue;
            }
            if(j==l-1){
                if(j-i+1>max) max=j-i+1;
            }
        }
        return max;
    }
};

//注意长度为0、1和最后没有重复但最长的情况


//substr(i,j) 从i开始，长度为j