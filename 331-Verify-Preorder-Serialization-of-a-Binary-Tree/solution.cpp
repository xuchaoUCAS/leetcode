class Solution {
public:
    bool isValidSerialization(string preorder) {
        bool num;
        preorder.push_back(',');
        int nullC = 0, nodesC = 0;
        for(int i = 0;i < preorder.length();++i){
            char c = preorder[i];
            if(c == '#'){
                nullC++;
                num = false;
            }
            else if(c == ','){
                if(num){
                    nodesC++;
                }
                num = false;
            }
            else
                num = true;
            if(nullC >= nodesC + 1 && i != preorder.length() - 2 && i != preorder.length() - 1)
                return false;
        }
        return nullC == nodesC + 1;
    }
};