1、反转字符串
//首尾交换法

void reverseString(vector<char>& s) {
        int n = s.size();
        if(n<2){
            return;
        }
        for(int i = 0;i < n/2;i++){
            int temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
    }
	
2、整数反转
//每次摘取最右边值挂在最左边，如果越界则返回0

int reverse(int x) {
        long res = 0;                 
        while(x != 0){
            res = res*10 + x%10;
            x /= 10;
        }
        return (int)res == res ? res : 0;
    }
	
3、字符串中的第一个唯一字符
//自己设置一个索引结构，出现的字符位置+1，最后遍历返回出现一次的字符即可

int firstUniqChar(string s) {
        int a[26]={0};
        //int index[26];
        int size=s.size();
        for(int i=0;i<size;i++)
        {
            a[s[i]-'a']++;
            // if(a[s[i]-'a'] < 2){
            //     index[s[i]-'a']=i;
            // }
        }
        for(int i=0;i<size;i++)
        {
            if(a[s[i]-'a']==1)
            {
                return i;//index[s[i]-'a'];
            }
        }
        return -1;
    }
	
4、有效的字母异位词
//和上一道题大同小异，只是多了一个索引数组，遍历的时候比较
//一下两个串字符是否相同且一样多

bool isAnagram(string s, string t) {
        int ssize=s.size();
        int tsize=t.size();
        if(ssize != tsize){
            return false;
        }
        int a[26]={0};
        int b[26]={0};
        for(int i=0;i<ssize;i++)
        {
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
	
5、验证回文串
//链表的话翻转后半部分，然后首尾比较
//串的话跳过无效字符直接首尾比较即可

bool isPalindrome(string s) {
        if(s.size()<2){
            return true;
        }
        int n = s.size();
        for(int i = 0,j = n-1;i<j;i++,j--){
            while(!isalnum(s[i]) && i<j){                //跳过不是字母和数字的字符
                i++;
            }
            while(!sialnum(s[j]) && i<j){
                j--;
            }
            if(s[i]!=s[j] && (s[i]<'A' || s[j]<'A' || abs(s[i]-s[j])!=32)){
                return false;
            }
        }
        return true;
    }
	
6、字符串转换整数(atoi)
//这道题需要注意细节
//按照题目每一步的要求，完成相应的功能即可

int myAtoi(string s) {
        int A = 1;                         //符号位
        double B = 0;                      //数值位
        bool flag = true;                  //是否判断过符号位  
        for(int i=0;s[i]!=0;i++){
            if(flag && ' ' == s[i]){        //忽略空格
                continue;
            }
            if(flag && '+' == s[i]){
                A = 1;
                flag = false;
                continue;
            }
            if(flag && '-' == s[i]){
                A = -1;
                flag = false;
                continue;
            }
            if(!isdigit(s[i])){
                break;
            }else{
                flag = false;
                B = B*10 + (s[i]-'0');
                if( B>= 2147483648){           //B是否越界，如果越界，置为整型的最大值或最小值
                    return A == 1 ? 2147483647 : -2147483648;
                }
            }
        }
        return (int)A*B;
    }
	
7、实现strStr(KMP算法和暴力解法)
//直接KMP算法O（n）搞定，具体KMP算法的流程
//可以搜索相应的资料学习，这里只给出简单的注释

int strStr(string haystack, string needle) {
        int len_H = haystack.size();
        int len_N = needle.size();
        if(len_N>len_H) return -1;
        if(len_N==0) return 0;

        vector<int> next(len_N);          //首先求next数组

        if(len_N == 1){
            next[0] = -1;
        }else{
            next[0] = -1;                   //默认值        
            next[1] = 0;                    //0个首尾呼应
            int i = 2,cn = 0;               //cn用来记录上一个元素的next值
			
            while(i<needle.size()){
                if(needle[i-1] == needle[cn]){       
                    next[i++] = ++cn;
                }else if(cn > 0){
                    cn = next[cn];
                }else{
                    next[i++] = 0;
                }
            }
        }
        int i = 0,j = 0;
        while(i<len_H && j<len_N){
            if(haystack[i] == needle[j]){          //正式比较，相同一起加加
                i++;
                j++;
            }else if(j == 0){                    //不相同，但j已经到0了，从这个位置配不出来
                i++;
            }else{
                j = next[j];                   //字串滑动，整个过程主串从不回溯
            }
        }
        return j == len_N?i-j:-1;                 //字串前进完了，说明配出来了，返回匹配的位置
    }
	
8、外观数列
//一般从小到大都可以考虑递归，每一步只需要得到上一个串长什么样
//把它描述出来，扔给下一个状态，就可以了

string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string last = countAndSay(n-1),res;
        int count = 1;                                   //几个“某数”
        for(int i = 0;i<last.size();++i){
            if (i == last.size()-1 || last[i] != last[i+1]) {
                res.push_back(count+'0');
                res.push_back(last[i]);
                count= 1;
            } else {
                count++;
            }
        }
        return res;
    }
	
9、最长公共前缀
//假设第一个串全体就是最长的，用它依次往后比较，发现不一样的，直接删掉后面的

string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        if(strs.size() == 1){
            return strs.at(0);
        }
        string res = strs.at(0);
        int m = 0;
        for(int i = 1;i<strs.size();i++){
            m = 0;
            while(m<res.size() && m<strs[i].size()){      //开始比较
                if(res[m] == strs[i].at(m)){              //相同字符，往后比较
                    m++;
                }else{
                    res.erase(m,res.size()-m);            //发现不同，把不同后面的都删了，跳出while
                    break;
                }
            }
            if(m == strs[i].size()){                   //加入比较的那个串更小，交换
                res = strs[i];
            }
            if(res.size() == 0){                      //比着比着res删完了，不用比了，没有公共开头
                break;
            }
        }
        return res;
    }

