class Solution {
public:
    string addBinary(string num1, string num2) {
        string result = "";
        int carry = 0;
        int index1 = 0, index2 = 0;
        int length1 = num1.length(), length2 = num2.length();
        
        while (index1 < length1 && index2 < length2) {
            int carrySum = carry + (num1[length1 - 1 - index1] - '0') + (num2[length2 - 1 - index2] - '0');
            if (carrySum == 3) {
                carry = 1;
                result += '1';
            } else if (carrySum == 2) {
                carry = 1;
                result += '0';
            } else if (carrySum == 1) {
                carry = 0;
                result += '1';
            } else {
                carry = 0;
                result += '0';
            }
            index1++;
            index2++;
        }
        
        while (index1 < length1) {
            int carrySum = carry + (num1[length1 - 1 - index1] - '0');
            if (carrySum == 2) {
                carry = 1;
                result += '0';
            } else if (carrySum == 1) {
                carry = 0;
                result += '1';
            } else {
                carry = 0;
                result += '0';
            }
            index1++;
        }
        
        while (index2 < length2) {
            int carrySum = carry + (num2[length2 - 1 - index2] - '0');
            if (carrySum == 2) {
                carry = 1;
                result += '0';
            } else if (carrySum == 1) {
                carry = 0;
                result += '1';
            } else {
                carry = 0;
                result += '0';
            }
            index2++;
        }

        if (carry == 1) {
            result += '1';
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
