1、打乱数组                          //这两个问题都比较简单

class Solution {
private:
    vector<int>& mynums;
public:
    Solution(vector<int>& nums) : mynums(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return mynums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffling(mynums);
        for(int i = 0; i < mynums.size(); i++){
            swap(shuffling[i], shuffling[rand() % (i + 1)]);
        }
        return shuffling;
    }
};

2、最小栈

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stack1;
    stack<int> stack2;
    MinStack() {

    }
    
    void push(int val) {
        stack1.push(val);
        if(stack2.size() == 0 || val<=getMin() ){
            stack2.push(val);
        }
    }
    
    void pop() {
        int a = stack1.top();
        if(a == getMin()){
            stack2.pop();
        }
        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
};