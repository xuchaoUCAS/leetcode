class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> s;
        bool num = false;
        preorder.push_back(',');
        for(auto c : preorder){
            if(c == '#'){
                while(!s.empty() && s.top() == '#'){
                    s.pop();
                    if(s.empty() || s.top() == '#')
                        return false;
                    s.pop();
                }
                s.push('#');
            }
            else if(c == ','){
                if(num)
                    s.push('1');
                num = false;
            }
            else
                num = true;
        }
        return s.size() == 1 && s.top() == '#';
    }
};