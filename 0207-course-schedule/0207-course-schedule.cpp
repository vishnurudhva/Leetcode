class Solution {
public:
    
    vector<vector<int>> getReverseAdjList(vector<vector<int>>& preList, int n) {
        vector<vector<int>> adjList(n);
        for (vector<int> pre: preList) {
            adjList[pre[1]].push_back(pre[0]);
        }
        return adjList;
    }
    
    vector<int> getInDegrees(vector<vector<int>>& adjList) {
        vector<int> inDegrees(adjList.size());
        for (int i = 0; i < adjList.size(); i++) {
            for (int v: adjList[i])
                inDegrees[v]++;
        }
        return inDegrees;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList = getReverseAdjList(prerequisites, numCourses);
        vector<int> inDegrees = getInDegrees(adjList);
        for (int i = 0; i < adjList.size(); i++) {
            int j = 0;
            for (; j < inDegrees.size(); j++) {
                if (!inDegrees[j]) break;
            }
            
            if (j == inDegrees.size()) return false;
            
            inDegrees[j]--;
            
            for (int v: adjList[j])
                inDegrees[v]--;
        }
        
        return true;
    }
};