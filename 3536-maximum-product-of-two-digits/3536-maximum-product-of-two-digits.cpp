class Solution {
public:
    int maxProduct(int n) {
        int f1 = 0;
        int f2 = 0;

        while(n>0){
            int digit = n% 10;

            if(digit >= f1){
                f2 = f1;
                f1 = digit;
            }
            else if(digit >f2){
                f2 =digit;
            }
            n /= 10;
        }
        return f1 * f2;
    }
};