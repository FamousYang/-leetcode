1、Fizz Buzz
//按照题目要求写就行了
vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1;i<n+1;i++){
            if(i % 15 == 0){
                res.push_back("FizzBuzz");
                continue;
            }
            if(i % 3 == 0){
                res.push_back("Fizz");
            }else if(i % 5 == 0){
                res.push_back("Buzz");
            }else{
                res.push_back(to_string(i));
            }
        }
        return res;
    }
	
2、计数质数
//经典算法，埃氏筛选法

int countPrimes(int n) {
        if(n<3){
            return 0;
        }
        int res = 0;
        vector<bool> sta(n,true);
        for(int i = 2;i<n;i++){
            if(sta[i]){
                res++;
                for(int j = i;j<n;j+=i){
                    sta[j] = false;
                }
            }
        }
        return res;
    }
	
3、3的幂

bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        int power=log(INT_MAX)/log(3);  //计算整型范围内3的最大幂
        int max=pow(3,power);
        return max%n == 0?true:false;     //最大幂一定是小幂的整数倍
    }
	
4、罗马数字转整数
//小的在大的左边，就减去这个小的
int romanToInt(string s) {
        int res = 0,x = XXX(s[0]);
        for(int i = 1;i<s.size();i++){
            int temp = XXX(s[i]);
            if(x < temp){
                res -= x;
            }else{
                res += x;
            }
            x = temp;
        }
        res += x;
        return res;
    }
int XXX(char a){
        switch(a){
            case 'I':
                return 1;
            case 'V':
                return 5;     
            case 'X':
                return 10; 
            case 'L':
                return 50; 
            case 'C':
                return 100; 
            case 'D':
                return 500; 
            case 'M':
                return 1000; 
        }
        return 0;
    }