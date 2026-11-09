class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        // Store how many tickets the target person needs.
        int target = tickets[k];

        // Store the total time required.
        int time = 0;

        // Traverse every person in the queue.
        for (int i = 0; i < tickets.size(); i++) {

            /*
                People before or at index k get a chance
                to buy tickets in the final round as well.

                People after index k do not get that final turn
                because person k finishes before them.
            */

            if (i <= k) {
                time += min(tickets[i], target);
            }
            else {
                time += min(tickets[i], target - 1);
            }
        }

        // Return the total time taken by person k to finish.
        return time;
    }
};