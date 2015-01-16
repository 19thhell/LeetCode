class Solution {
public:
    string intToRoman(int num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        string result;
        int cnt = 0;
        while (num){
            while (num >= value[cnt]){
                num -= value[cnt];
                result += roman[cnt];
            }
            cnt++;
        }
        return result;
    }
private:
    const string roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    const int value[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
};
