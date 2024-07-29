class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int left = 0 , right = n-1;
        while(left<right){
            if(s[left]!=s[right]){
                bool one , two;
                if(left==0){
                    string temp=s.substr(1);
                    string temp2=temp;
                    reverse(temp2.begin(),temp2.end());
                    if(temp==temp2)one =true;
                    else one =false;
                    temp=s.substr(0,n-1);
                    temp2=temp;
                    reverse(temp2.begin(),temp2.end());
                    if(temp==temp2)two =true;
                    else two =false;
                }
                else{
                    string temp = s.substr(0,left)+s.substr(left+1);
                    string temp2=temp;
                    reverse(temp2.begin(),temp2.end());
                    if(temp==temp2)one =true;
                    else one =false;
                    temp=s.substr(0,right)+s.substr(right+1);
                    temp2=temp;
                    reverse(temp2.begin(),temp2.end());
                    if(temp==temp2)two =true;
                    else two =false;
                }
                
                return one||two;
            }
           left++;
            right--;
        }
        return true;
    }
};