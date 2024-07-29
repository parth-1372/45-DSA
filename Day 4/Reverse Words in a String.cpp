class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec={};
        int i=0,n=s.length();
        while(i<n){
            while(s[i]==' ' && i<n)i++;
            string word="";
            while(s[i]!=' ' && i<n){
                word+=s[i];
                i++;
            }
            if(word!="")vec.push_back(word);
        }
        i=0;
        n=vec.size();
        int j=n-1;
        cout<<n<<endl;
        while(i<j){
            cout<<vec[i]<<" "<<vec[j];
            swap(vec[i],vec[j]);
            i++;
            j--;
        }
        string ans="";
        for(int i=0;i<n;i++){
            ans+=vec[i];
            if(i!=n-1)ans+=' ';
        }
        return ans;
    }
};