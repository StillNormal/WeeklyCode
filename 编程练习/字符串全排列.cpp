#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

void my_print(char* str, char* Str2Print, int index) {
    if (str == NULL || str == "")
        return;

    if (index == strlen(str)) {
        cout << Str2Print << endl;
        return;
    }

    for (int i = index; i < strlen(str); i++) {
        Str2Print[index] = str[i];
        char* save = new char[strlen(str) + 1];//方法没错 这是关键所在
        strcpy(save, str);
        save[strlen(str)] = '\0';
        char temp = str[i];
        str[i] = str[index];
        str[index] = temp;
        my_print(str, Str2Print, index+1);
        strcpy(str, save);
    }

    return;
}

int main () {
    char* str = new char[99];
    cin >> str;
    //str = "abc";//分配在常量区 不容改变!!! 并且char* str是指针，只能strcpy赋值，要么str[]=‘bc’这样初始化
    char* Str2Print = new char[strlen(str) + 1];
    Str2Print[strlen(str)] = '\0';
    my_print(str, Str2Print, 0);
    return 0;
}
