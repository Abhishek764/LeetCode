class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        /*
            STEP 1: Count student preferences.

            count[0] = Number of students who want circular sandwiches.
            count[1] = Number of students who want square sandwiches.
        */

        vector<int> count(2, 0);

        for (int student : students) {
            count[student]++;
        }

        /*
            STEP 2: Process sandwiches from the top of the stack.

            sandwiches[0] is the first sandwich.
            sandwiches[1] is the second sandwich.
            And so on.
        */

        for (int sandwich : sandwiches) {

            /*
                If nobody wants the current sandwich,
                nobody else can eat because students can
                only rotate in the queue.

                Therefore, return the total remaining students.
            */

            if (count[sandwich] == 0) {
                return count[0] + count[1];
            }

            /*
                One student takes this sandwich.

                Decrease the count of students who want
                this particular sandwich.
            */

            count[sandwich]--;
        }

        /*
            All students successfully received sandwiches.
        */

        return 0;
    }
};