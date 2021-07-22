1、位1的个数

int hammingWeight(uint32_t n) {
        int res = 0;
        while(n != 0){
            n -= (n & (~n+1));   //n每次减去最右边的1
            res++;               //记忆：最右边的1计算方法->(n & (~n+1))
        }
        return res;
    }
	
2、汉明距离

int hammingDistance(int x, int y) {
        int n = x^y;                    //异或，不一样的地方都是1
        int res = 0;                    //计算1的个数
        while(n != 0){
            n -= (n & (~n+1));
            res++;
        }
        return res;
    }
	
3、颠倒二进制位
//原数右移一个，答案左移一个

uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(short i=0;i<32;i++){
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
	
4、杨辉三角

vector<vector<int>> generate(int numRows) {
        if(numRows<=0){
            return {};
        }
        vector<vector<int>> res;
        for(int i = 0;i<numRows;i++){
            vector<int> a;
            for(int j = 0;j<=i;j++){
                if(j == 0 || j == i){
                    a.push_back(1);
                }else{
                    a.push_back(res[i-1][j-1]+res[i-1][j]);
                }
            }
            res.push_back(a);
        }
        return res;
    }
	
5、有效的括号

bool isValid(string s) {
        if(s.size() % 2 != 0){
            return false;
        }
        stack<char> sta;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                sta.push(')');
            }else if(s[i] == '['){
                sta.push(']');
            }else if(s[i] == '{'){
                sta.push('}');
            }else if(!sta.empty() && sta.top()==s[i]){
                sta.pop();
            }else{
                return false;
            }
        }
        return sta.empty();
    }
	
6、缺失数字
//异或，相同为0，全部异或起来，会得到0或两个只出现了一次的数
//0的话少了最大的那个，异或得到答案，两个不同数的话少了中间一个，异或消除最大的那个

int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n<=0){
            return 0;
        }
        int a = 0;
        for(int i=0;i<n;i++){
            a = a^nums[i]^i;
        }
        return a^n;
    }