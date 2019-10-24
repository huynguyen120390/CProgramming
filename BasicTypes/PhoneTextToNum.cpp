#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct charArrObj{
    char * arr;
    int size;
};

#define MAXSIZE 14;
void print_charArray(vector<char> arr);
vector<char> read_charArray(vector<char> vec);
vector<char> convert_phoneNum(vector<char> phoneArr);
char convert(char ch);
bool belong(char ch, vector<char> arr);

int main(int argc, char ** argv){
    printf("Type phone number:\n");
    vector <char> phoneArr;
    printf("The collected phone number:\n");
    phoneArr =  read_charArray(phoneArr);
    print_charArray(phoneArr);
    printf("The converted phone number:\n");
    phoneArr = convert_phoneNum(phoneArr);
    print_charArray(phoneArr);
    return 0;
}

vector<char> convert_phoneNum(vector<char> phoneArr){
    for(int i = 0; i < phoneArr.size();i++){
        phoneArr[i] = convert(phoneArr[i]);
    }
    return phoneArr;
}

bool belong(char ch, string str){
    for(int i = 0; i < str.size(); i++){
        if(ch == str[i]){
            return true;
        }
    }
    return false;
}

char convert(char ch){
    char ori = ch;
    if(belong(ch,"ABC")){
        ch = '2';
    }else if(belong(ch,"DEF")){
        ch = '3';
    }else if(belong(ch,"GHI")){
        ch = '4';
    }else if(belong(ch,"JKL")){
        ch = '5';
    }else if(belong(ch,"MNO")){
        ch = '6';
    }else if(belong(ch,"PRS")){
        ch = '7';
    }else if(belong(ch,"TUV")){
        ch = '8';
    }else if(belong(ch,"WXY")){
        ch = '9';
    }
    return ch;
}

vector<char> read_charArray(vector <char> vec){
    
    char ch;
    do{
        ch = cin.get(); //fail to use cin >> ch, scanf here
        vec.push_back(ch);
    }while(ch != '\n');
    //vec.push_back('\0');
    return vec;

}


void print_charArray(vector<char> arr){
    for(int i = 0; i < arr.size(); i++){
        printf("%c",arr[i]);
    }
    cout << endl;
}








