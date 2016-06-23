class Solution {
public:
    //G(n): 1……n构成的BST; f(i):以i为根构成的BST。-->[1,2,3,4,5,6,7]: f(3) = G(2) + G(4);
    //所以：G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)
    int numTrees(int n) {
        int *a = new int[n + 1];
        for(int i = 0;i < n + 1; ++i)
            a[i] = 0;
        a[0] = a[1] = 1;
        for(int i = 2;i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                a[i] += a[j - 1] * a[i -j];
            }
        }
        return a[n];
    }
};