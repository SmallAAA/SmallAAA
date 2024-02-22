#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Getnext(int *next, char *str2){
    int j = 0;
    int len = strlen(str2);
    next[0] = j;
    for (int i = 1; i < len; i ++){
        while (j > 0 && str2[i] != str2[j])//前后缀不相同
            j = next[j - 1];
        if (str2[i] == str2[j])//前后缀相同
            j ++;
        next[i] = j;
    }
}

int KMP(char *str1, char *str2){
    int i = 0;//字符串指针
    int j = 0;//模式串指针

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int *next = (int *)malloc(sizeof(int) * len2);
    Getnext(next, str2);//得到next数组

    if (len1 == 0 || len2 == 0 || len2 > len1)
        return -1;//判断字符串和模式串是否合法

    while (i < len1 && j < len2){
        if (str1[i] == str2[j]){//如果字符相等都往后移动一个字符
            i ++;
            j ++;
        }
        else if (str1[i] != str2[j] && j > 0){//如果不相等模式串指针回溯
            j = next[j - 1];
        }
        else if (str1[i] != str2[j] && j == 0){
            i ++;
        }
    }

    if (j >= len2)//寻找结束
        return i - j;

    return -1;
}

int main()
{
    char str1[100] = "", str2[100] = "";
    //printf ("请输入父字符串和模式串");
    scanf ("%[^\n] %[^\n]", str1, str2);
    int result = KMP(str1, str2);
    //printf ("如果查找失败，那么将返回-1，否则查找成功");
    printf ("%d", result);
    return 0;
}
