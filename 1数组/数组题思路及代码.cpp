1、删除排序数组中的重复项
//对数组元素进行扫描，如果具有相同元素，right向右移动，
//比较途中用后面的元素覆盖前面重复的元素，数组长度缩短即可

int removeDuplicates(vector<int>& nums) {
        if(nums.empty()||nums.size() == 0){
            return 0;
        }
        int left = 0;
        for(int right = 1;right<nums.size();right++){
            if(nums[left]!=nums[right]){
                nums[++left] = nums[right];
            }
        }
        return ++left;
}

2、买卖股票的最佳时机 II
//本题目可以使用动态规划解决，但有点不划算，仔细观察
//可以发现使用贪心的思想更加简单，遍历每一天的价格，然后观察价格变化
//得出普遍规律为如果第二天的价格大于前一天，则加入该差价，即可获得最大收益

int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int res = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i]){                       //如果第二天价格高，则加入
                res += (prices[i+1]-prices[i]);
            }
        }
        return res;
}

3、旋转数组
//这道题在问数组元素向右移动的操作，在链表中同样有这个问题，在链表中我们可以
//找到倒数第k个节点的前驱节点，改变指针
//在数组中的考虑方法如下：
//“循环交换每个数与其即将到达的新位置的数”，处理完一个循环后i++，处理下一个循环
//直到完成交换

void rotate(vector<int>& nums, int k) {
        if(k <= 0 || nums.size()<2){
            return;
        }
        int len = nums.size();
        int step = k % len;                                    //每个数要移动的步数
        int repeat = 0;                                        //第一个循环，尚未重复交换
        int temp = nums[0];                                    //第一个循环，从第一个元素开始换
        for(int i = step,cn = 0;cn<len;i+=step,cn++){          //cn为交换次数，n个数交换n 次
            int t = nums[i%len];
            nums[i%len] = temp;
            temp = t;
            if(i%len == repeat){
                i = ++repeat;
                temp = nums[i%len];
            }
        }
    }
	
4、存在重复元素
//这个题目比较简单，此方法为使用了C++ API直接得出的结果
//先排序，相同的元素呆在一起，相邻元素之间判断即可

bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return unique(nums.begin(),nums.end())!=nums.end();
    }
	
5、只出现一次的数字
//位运算小技巧，同样的数异或为0，把所有的数异或在一起
//答案就是那个单独的数

int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i:nums){
            res = res^i;
        }
        return res;
    }
	
6、两个数组的交集 II
//先排序，两个数组开始比较，相等计入结果数组，不相等小的那方向后遍历

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        for(vector<int>::iterator it1=nums1.begin(),it2=nums2.begin();it1!=nums1.end()&&it2!=nums2.end();)
        {
            if(*it1<*it2 ) it1++;
            else if(*it1==*it2)
            {
                res.push_back(*it1);
                 it1++;
                 it2++;
            }
            else if(*it1>*it2 ) it2++;
        }
        return res;
    }
	
7、加一
//这道题关键在于进位，如果9999 +1 那么还需要扩充一位
//从后往前遍历，+1之后如果不为0，直接return，否则前一位+1，如果一直进位
//最后digits[0]置1，后面追加一个0

vector<int> plusOne(vector<int>& digits) {
        for(vector<int>::reverse_iterator it = digits.rbegin();it != digits.rend();it++){
            (*it)++;
            (*it) = (*it) % 10;
            if((*it) != 0) return digits;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
	
8、移动零（将所有0移动到数组的末尾，同时保持非零元素的相对顺序）
//j从前往后有遍历，碰到0的话用i记住有几个0，在碰到非0时直接置换即可

void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0;j<nums.size();j++){
            if(nums[j] == 0){
                i++;
            }else{
                if(i != 0){
                nums[j-i] = nums[j];                        //j前面有i个0，所以把j的值和最前面0交换
                nums[j] = 0;
                }
            }
        }
    }

9、两数之和
//本题可以空间换时间用hashmap解决，对于元素j，看一下哈希表里有没有i使得i+j=target，
//如果有，那么输出二者下标，如果没有就加入哈希表，j继续遍历

10、有效的数独
//为了表示9*9的数独中每一行，每一列，每个方框中元素是否唯一
//可以开辟三个数组，分别存放9个数字出现的次数。

bool isValidSudoku(vector<vector<char>>& board) {
        int r[9] = {0};
        int c[9] = {0};
        int s[9] = {0};
        int shift = 0;
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board.size();j++){
                if(board[i][j] == '.'){
                    continue;
                }
                shift = 1 << (board[i][j]-'0');                 //方便比较速度
                int k = (i / 3) * 3 + j / 3;                    //第几个方块
                if((r[i] & shift)!=0 || (c[j] & shift)!=0 || (s[k] & shift)!=0){
                    return false;
                }
                r[i] |= shift;                                  //第一次出现则加入数组
                c[j] |= shift;
                s[k] |= shift;
            }
        }
        return true;
    }

11、旋转图像（将n阶方阵顺时针旋转90度）
//和旋转数组相比，这个旋转内容变成了2维，其实道理相似，关键在于每一个元素它下一个要去的地方
//在二维数组中怎么表示，表示成功之后就只需要整体做循环交换即可

void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        for (int i = 0; i < length / 2; i++)                           //旋转一半就够
            for (int j = i; j < length - i - 1; j++) {                 //列同理，参与调整的仅为一半
                int temp = matrix[i][j];
                int m = length - j - 1;                                //这里遇到旋转坐标的选定
                int n = length - i - 1;                                //可以尝试画图，会更容易看出对应关系
                matrix[i][j] = matrix[m][i];
                matrix[m][i] = matrix[n][m];
                matrix[n][m] = matrix[j][n];
                matrix[j][n] = temp;
            }
    }
