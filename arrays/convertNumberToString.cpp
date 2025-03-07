// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<string>
using namespace std;

// Given a number as input, return the english translation for the same.

// 123456
// One hundred twenty three thousand four hundred fifty six
vector<string> ones = {"" , "One","Two","Three","Four","Five","Six","Seven","Eight", "Nine"};
vector<string> teenty = {"Eleven", "Twelve", "Thirteen" ,"Fourteen", "Fifteen", "Sixteen", "Seventeen" , "Eighteen", "Ninteen", };
vector<string> tens = {"", "Ten","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
vector<string> thousands = {"", "Thousands","Million","Billion"};


string convertNumber(int num) {
    string ans;
    if(num >=100){
        ans = ans + ones[num / 100] + "Hundred";
        num = num % 100;
    }
    if(num >= 11 && num <=19){
        ans = ans + teenty[num - 11] + " ";
    }else{
        if(num >=20){
            ans= ans+tens[num /10] + " ";
            num = num %10;
        }
    }
    if(num >=1 && num <=9){
        ans= ans + ones[num] + " ";
    }
    return ans;
}

string numberToWord(int num){
    // first check if it is a valid number or not?
    if(num == 0) return "zero";
    string result;
   
    int index =0 ;
    // untill nthe numbre is getting 0
    while(num > 0){
        int n = num % 1000;
        if(n !=0){
            result = convertNumber(n) + thousands[index] + " " + result;
        }
        num /=1000;
        index ++ ;
    }
    return result;
}

int main() {
    // Write C++ code here
    // cout << "Try programiz.pro";
    int number = 23456789;
    cout << "the number is" << number << "and in words is" << numberToWord(number) <<endl;
    return 0;
}