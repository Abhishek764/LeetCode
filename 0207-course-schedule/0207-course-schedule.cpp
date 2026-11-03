class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Build adjacency list and calculate indegree of each course
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            // prerequisite must be completed before course
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Add courses with no prerequisites to the queue
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Count courses that can be completed
        int completed = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            completed++;

            // Remove this course as a prerequisite for its neighbors
            for (int next : adj[course]) {
                indegree[next]--;

                // If no prerequisites remain, process this course
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If all courses are completed, there is no cycle
        return completed == numCourses;
    }
};