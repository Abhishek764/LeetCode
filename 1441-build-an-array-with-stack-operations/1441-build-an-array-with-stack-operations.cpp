class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        /*
            result stores the operations required
            to build the target array.
        */
        vector<string> result;

        /*
            i tracks the current element we need
            from the target array.
        */
        int i = 0;

        /*
            num represents the numbers coming from
            the stream: 1, 2, 3, ..., n.
        */
        for (int num = 1; num <= n; num++) {

            /*
                Every number read from the stream
                must first be pushed into the stack.
            */
            result.push_back("Push");

            /*
                If the current number is what we need,
                keep it in the stack.
            */
            if (num == target[i]) {

                // Move to the next required target element.
                i++;

                /*
                    If all target elements are collected,
                    stop reading more numbers.
                */
                if (i == target.size()) {
                    break;
                }
            }

            /*
                If the current number is not needed,
                remove it from the stack immediately.
            */
            else {
                result.push_back("Pop");
            }
        }

        // Return all operations in the required order.
        return result;
    }
};