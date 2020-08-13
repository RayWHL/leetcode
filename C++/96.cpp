//动态规划
class Solution {
public:
    int numTrees(int n) {
        int *dynamic=new int[n+1];
        dynamic[0]=1;
        dynamic[1]=1;
        for(int i=2;i<=n;++i){
            dynamic[i]=0;
            for(int j=0;j<i;++j)
                dynamic[i]+=dynamic[j]*dynamic[i-j-1];
        }
        if(n==0) return 0;
        else return dynamic[n];
    }
};

//数组需要初始化， line9