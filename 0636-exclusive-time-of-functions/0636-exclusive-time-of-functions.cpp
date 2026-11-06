class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        /*
            Store the exclusive execution time of every function.

            Initially, every function has executed for 0 units.
        */
        vector<int> result(n, 0);

        /*
            Stack stores the IDs of currently active functions.

            The function at the top is the one currently executing.
            A function can appear multiple times because recursion
            is allowed.
        */
        stack<int> st;

        /*
            prevTime represents the first timestamp that
            has NOT been counted yet.
        */
        int prevTime = 0;

        /*
            Process every log in chronological order.
        */
        for (string log : logs) {

            /*
                Each log has this format:

                "function_id:start:timestamp"
                "function_id:end:timestamp"

                Use stringstream to split the log using ':'.
            */
            stringstream ss(log);

            string idString, type, timeString;

            getline(ss, idString, ':');
            getline(ss, type, ':');
            getline(ss, timeString, ':');

            /*
                Convert function ID and timestamp
                from strings into integers.
            */
            int id = stoi(idString);
            int timestamp = stoi(timeString);

            /*
                CASE 1: A function starts.
            */
            if (type == "start") {

                /*
                    If another function is already running,
                    it must pause because the new function starts.

                    The currently running function is at the
                    top of the stack.

                    Count its execution from prevTime up to
                    timestamp - 1.

                    The current start timestamp belongs to
                    the newly started function.
                */
                if (!st.empty()) {
                    result[st.top()] += timestamp - prevTime;
                }

                /*
                    Push the newly started function.

                    It becomes the currently executing function.
                */
                st.push(id);

                /*
                    The new function starts at this timestamp.
                    Update the beginning of the next uncounted period.
                */
                prevTime = timestamp;
            }

            /*
                CASE 2: A function ends.
            */
            else {

                /*
                    The function at the top of the stack
                    is the function that is ending.

                    Add its execution time.

                    +1 is necessary because the end timestamp
                    is INCLUDED in its execution time.
                */
                result[st.top()] += timestamp - prevTime + 1;

                /*
                    The function has finished execution.
                    Remove it from the stack.
                */
                st.pop();

                /*
                    The ending timestamp has already been counted.

                    Therefore, the next uncounted timestamp
                    is timestamp + 1.

                    If a parent function exists, it resumes
                    from this next timestamp.
                */
                prevTime = timestamp + 1;
            }
        }

        /*
            Return the total exclusive execution time
            for every function.
        */
        return result;
    }
};