#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

int* get_next(char* sub_str);
int* get_next_array(char* sub_str);
int KMP(char* str, char* sub_str);
int get_max_length(char* sub_str, int i);
bool is_equal(char* str, int i, int post);
char* get_random_string(int n);

int main() {
    srand((unsigned)time(NULL));
    char* str = get_random_string(100);
    char* sub_str = get_random_string(2);  
    // char* str = (char*)"abcdefg";
    // char* sub_str = (char*)"def";
    cout << str << endl;
    cout << sub_str << endl; 
    int index = KMP(str, sub_str);
    cout << index << endl;
    return 0;
}

/**
  *  @paramter: str(主串) sub_str(模式串)
  *  @return: 返回匹配字符串的下标 (从0开始)， 不匹配时返回-1
  */
int KMP(char* str, char* sub_str) {
    int i = 0;
    int j = 0;
    int* next_array = get_next(sub_str);
    while (i <= strlen(str) - strlen(sub_str)) {
        while (str[i] == sub_str[j] && sub_str[j] != '\0') {
            i++;
            j++;
        }
        if (sub_str[j] == '\0') {
            return i - strlen(sub_str);
        }
        else {
            j = next_array[j];
            if (j == -1) {
                j = 0;
                i++;
            }
        }
    }
    return -1;
}

/**
  *  @paramter: sub_str(模式串)
  *  @return: 返回模式串对应的next数组
  */
int* get_next_array(char* sub_str) {
    int length = strlen(sub_str);
    int* next_array = (int*)malloc(sizeof(int) * length);

    for (int i = 0; i < length; i++) {    
        if (i == 0 || i == 1) {
            next_array[i] = i - 1;
        }
        else {
            next_array[i] = get_max_length(sub_str, i);
        }
    }
    return next_array;
}

/**
  *  @paramter: sub_str(模式串) i(下标)
  *  @return: 返回模式串对应的next数组第i个的值，即下标[0..i]的字符串的最长公共前后缀的长度
  */
int get_max_length(char* sub_str, int i) {
    int postfix = 1;
    int max_length = i - 1;
    while (postfix != i) {

        if (is_equal(sub_str, i, postfix)) {
            return max_length;
        }
        else {
            max_length--;
            postfix++;
        }
    }
    return 0;
}

/**
  *  @paramter: str(串) i(后缀结束下标的下一个位置) postfix(后缀起始下标)
  *  @return: 返回前缀后缀是否相等
  */
bool is_equal(char* str, int i, int postfix) {
    int m = 0; 
    while (postfix != i - 1 && str[m] == str[postfix]) {
        m++;
        postfix++;
    }
    return (str[m] == str[postfix]);
}

/**
  *  @paramter: n (产生的长度)
  *  @return: 返回产生的随机字符串指针
  */
char* get_random_string(int n) {
    char* str = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

/**
  *  @paramter: sub_str(模式串)
  *  @return: 返回模式串对应的next数组
  */
int* get_next(char* sub_str) {
    int length = strlen(sub_str);
    int* next = (int*)malloc(sizeof(int) * length);
    int i = 0;
    int j = -1;
    next[0] = -1;
    while (i < length) {
        if (j == -1 || sub_str[i] == sub_str[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
    return next;
}