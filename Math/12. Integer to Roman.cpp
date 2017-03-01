class Solution {
public:
    string intToRoman(int num) {
        vector<string> thousands{"", "M", "MM", "MMM"};
        vector<string> houdreds{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> tens{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> ones{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return thousands[num / 1000] + houdreds[(num % 1000) / 100] + 
            tens[(num % 100) / 10] + ones[num % 10];
    }
};
