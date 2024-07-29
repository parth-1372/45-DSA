class Solution {
public:
    void helper(int num,vector<pair<char,int>>& vec,string& ans){
        if(num==0)return;
        string temp = to_string(num);
        if(temp[0]=='1'){
            num=num-pow(10,temp.length()-1);
            if(temp.length()-1==0)ans+='I';
            else if(temp.length()-1==1)ans+='X';
            else if(temp.length()-1==2)ans+='C';
            else if(temp.length()-1==3)ans+='M';
            helper(num,vec,ans);
        }
        else if(temp[0]=='2'){
            num=num-2*pow(10,temp.length()-1);
            if(temp.length()-1==0)ans+="II";
            else if(temp.length()-1==1)ans+="XX";
            else if(temp.length()-1==2)ans+="CC";
            else if(temp.length()-1==3)ans+="MM";
            helper(num,vec,ans);
        }
         else if(temp[0]=='3'){
            num=num-3*pow(10,temp.length()-1);
            if(temp.length()-1==0)ans+="III";
            else if(temp.length()-1==1)ans+="XXX";
            else if(temp.length()-1==2)ans+="CCC";
            else if(temp.length()-1==3)ans+="MMM";
            helper(num,vec,ans);
        }
        else if(temp[0]=='4'){
            num=num-4*pow(10,temp.length()-1);
            
            if(temp.length()-1==0)ans+="IV";
            else if(temp.length()-1==1)ans+="XL";
            else if(temp.length()-1==2)ans+="CD";
            helper(num,vec,ans);
        }
        else if(temp[0]=='5'){
            num=num-5*pow(10,temp.length()-1);
            if(temp.length()-1==0)ans+='V';
            else if(temp.length()-1==1)ans+='L';
            else if(temp.length()-1==2)ans+='D';
            helper(num,vec,ans);
        }
        else if(temp[0]=='6'){
            num=num-6*pow(10,temp.length()-1);
            if(temp.length()-1==0)ans+="VI";
            else if(temp.length()-1==1)ans+="LX";
            else if(temp.length()-1==2)ans+="DC";
            helper(num,vec,ans);
        }
        else if(temp[0]=='7'){
            num=num-7*pow(10,temp.length()-1);
            if(temp.length()-1==0)ans+="VII";
            else if(temp.length()-1==1)ans+="LXX";
            else if(temp.length()-1==2)ans+="DCC";
            helper(num,vec,ans);
        }
        else if(temp[0]=='8'){
            num=num-8*pow(10,temp.length()-1);
            if(temp.length()-1==0)ans+="VIII";
            else if(temp.length()-1==1)ans+="LXXX";
            else if(temp.length()-1==2)ans+="DCCC";
            helper(num,vec,ans);
        }
        else if(temp[0]=='9'){
            num=num-9*pow(10,temp.length()-1);
            if(temp.length()-1==0)ans+="IX";
            else if(temp.length()-1==1)ans+="XC";
            else if(temp.length()-1==2)ans+="CM";
            helper(num,vec,ans);
        }
    }
    string intToRoman(int num) {
        string ans="";
        vector<pair<char,int>> vec={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        helper(num,vec,ans);
        return ans;
    }
};