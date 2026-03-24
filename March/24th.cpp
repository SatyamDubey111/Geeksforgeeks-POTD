#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Renamed from isPossible to canFinish to match Driver.cpp
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Step 1: Build the graph and calculate In-degree
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            // Edge direction: prereq -> course (prereq must be done first)
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        
        // Step 2: Push courses with 0 prerequisites into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int completedCourses = 0;
        
        // Step 3: Standard BFS for Topological Sort (Kahn's Algorithm)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++; 
            
            for (int nextCourse : adj[curr]) {
                indegree[nextCourse]--;
                
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // Step 4: If processed courses equals total courses, no cycle exists
        return completedCourses == n;
    }
};#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Renamed from isPossible to canFinish to match Driver.cpp
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Step 1: Build the graph and calculate In-degree
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            // Edge direction: prereq -> course (prereq must be done first)
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        
        // Step 2: Push courses with 0 prerequisites into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int completedCourses = 0;
        
        // Step 3: Standard BFS for Topological Sort (Kahn's Algorithm)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++; 
            
            for (int nextCourse : adj[curr]) {
                indegree[nextCourse]--;
                
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // Step 4: If processed courses equals total courses, no cycle exists
        return completedCourses == n;
    }
};#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Renamed from isPossible to canFinish to match Driver.cpp
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Step 1: Build the graph and calculate In-degree
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            // Edge direction: prereq -> course (prereq must be done first)
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        
        // Step 2: Push courses with 0 prerequisites into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int completedCourses = 0;
        
        // Step 3: Standard BFS for Topological Sort (Kahn's Algorithm)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++; 
            
            for (int nextCourse : adj[curr]) {
                indegree[nextCourse]--;
                
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // Step 4: If processed courses equals total courses, no cycle exists
        return completedCourses == n;
    }
};#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Renamed from isPossible to canFinish to match Driver.cpp
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        // Step 1: Build the graph and calculate In-degree
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            // Edge direction: prereq -> course (prereq must be done first)
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        
        // Step 2: Push courses with 0 prerequisites into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int completedCourses = 0;
        
        // Step 3: Standard BFS for Topological Sort (Kahn's Algorithm)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++; 
            
            for (int nextCourse : adj[curr]) {
                indegree[nextCourse]--;
                
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // Step 4: If processed courses equals total courses, no cycle exists
        return completedCourses == n;
    }
};