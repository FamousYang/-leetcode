1、爬楼梯
//类似斐波那契数列，关键是把题目看懂就行了

int climbStairs(int n) {
        if(n<3){
            return n;
        }
        vector<int> a(n+1);
        a[1] = 1;
        a[2] = 2;
        for(int i = 3;i<=n;i++){
            a[i] = a[i-1]+a[i-2];
        }
        return a[n];
    }
	
2、买卖股票的最佳时机
//之前数组那见过，这里用简单的动态规划解，双指针也能解

int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int hold = -prices[0];               //第一天买了
        int no = 0;                           //第一天没买
        for(int i=1;i<prices.size();i++){
            hold = max(hold,-prices[i]);      //之前有不卖，或之前没有现在买
            no = max(no,hold+prices[i]);      //之前有卖卖掉，或之前就没买
        }
        return no;
    }
	
3、最大子序和
//前面子序为正，前加后
//否则0+后
//count记录最大的子序和

int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
            return 0;
        }
        int count = nums[0],res = nums[0];
        for(int i = 1;i<size;i++){
            res = max(res,0) + nums[i];
            count = max(res,count);
        }
        return count;
    }
	
4、打家劫舍

int rob(vector<int>& nums) {
        int n = nums.size();
        int rob = nums[0];         //第一个抢
        int no = 0,temp;           //第一个不抢
        for(int i = 1;i<n;i++){
            temp = rob;
            rob = nums[i] + no;     //第i个抢
            no = max(no,temp);      //第i个不抢
        }
        return max(no,rob);
    }