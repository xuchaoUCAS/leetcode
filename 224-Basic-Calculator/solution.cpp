class Solution {
public:
    int calculate(string s) {
        stack<int> nums, ops;
        int num = 0;
        int sign = 1;
        int result = 0;
        for(auto c : s){
            if(isdigit(c))
                num = num * 10 + c - '0';
            else{
                result += num * sign;
                num = 0;
                if(c == '+')
                    sign = 1;
                if(c == '-')
                    sign = -1;
                if(c == '('){
                    nums.push(result);
                    ops.push(sign);
                    result = 0;
                    num = 0;
                    sign = 1;
                }
                if(c == ')'){
                    result = ops.top() * result + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }
        }
        result += sign *num;
        return result;
    }
};