class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        int n = path.length();
        int i = 0;
        
        while (i < n) {
            // Skip all the slashes
            while (i < n && path[i] == '/') i++;
            if (i == n) break;
            
            int start = i;
            // Read the current component
            while (i < n && path[i] != '/') i++;
            string component = path.substr(start, i - start);
            
            if (component == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (component != "." && !component.empty()) {
                stack.push_back(component);
            }
        }
        
        string result;
        for (string dir : stack) {
            result += "/" + dir;
        }
        
        return result.empty() ? "/" : result;
    }
};
