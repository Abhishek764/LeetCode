class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int totalResult = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] != "C" && operations[i] != "D" && operations[i] != "+") {
                st.push(stoi(operations[i]));
            } else if (operations[i] == "C") {
                if (st.size() > 0) st.pop();
            } else if (operations[i] == "D") {
                if (st.size() > 0) st.push(st.top() * 2);
            } else {
                if (st.size() > 0) {
                    int prevFirstScore = st.top();
                    st.pop();
                    if (st.size() > 0) {
                        int prevSecondScore = st.top();
                        st.push(prevFirstScore);
                        st.push(prevFirstScore + prevSecondScore);
                    } else st.push(prevFirstScore);
                }
            }
        }
        while (st.size() > 0) {
            totalResult += st.top();
            st.pop();
        }
        return totalResult;
    }
};