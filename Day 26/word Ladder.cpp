class Solution {
public:
    bool canEdge(string s1,string s2){
        int n = s1.length();
        int diff = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]) diff++;
            if(diff > 1) return false;
        }
        return diff == 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<int,string> m;
        int n = wordList.size();
        m[0] = beginWord;
        bool check = false;
        for(int i = 0; i < n; i++){
            m[i+1] = wordList[i];
            if(wordList[i] == endWord) check = true;
        }
        if(!check) return 0;

        vector<vector<int>> adjList(n+1);

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(canEdge(wordList[i], wordList[j])){
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
            if(canEdge(beginWord, wordList[i])) adjList[0].push_back(i+1);
        }

        vector<int> vis(n+1, 0);
        queue<pair<int, int>> q; // {steps, index}
        q.push({1, 0});
        while(!q.empty()){
            int curr = q.front().second;
            int step = q.front().first;
            q.pop();
            vis[curr] = 1;
            if(m[curr] == endWord) return step;
            for(int neighbor : adjList[curr]){
                if(!vis[neighbor]) q.push({step+1, neighbor});
            }
        }
        return 0;
    }
};
