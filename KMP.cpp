#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

int* get_next_array(char* sub_str);
int KMP(char* str, char* sub_str);
int get_max_length(char* sub_str, int i);
bool is_equal(char* str, int i, int post);
char* get_random_string(int n);

int main() {
    srand((unsigned)time(NULL));
    char* str = get_random_string(10000);
    char* sub_str = get_random_string(2);  

    cout << str << endl;
    cout << sub_str << endl; 
    int index = KMP(str, sub_str);
    cout << index << endl;
    return 0;
}

int KMP(char* str, char* sub_str) {
    int i = 0;
    int j = 0;
    int next_array[4] = {-1,0,0,1};
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

bool is_equal(char* str, int i, int postfix) {
    int m = 0; 
    while (postfix != i - 1 && str[m] == str[postfix]) {
        m++;
        postfix++;
    }
    return (str[m] == str[postfix]);
}

char* get_random_string(int n) {
    char* str = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}