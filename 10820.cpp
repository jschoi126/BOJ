//
// Created by Choi on 2017. 9. 27..
//
#include <stdio.h>
#include <string.h>

int main (){
    char str[101];
    while((gets(str)) > 0) {
        int len = strlen(str);
        int small = 0;
        int large = 0;
        int num = 0;
        int blank = 0;

        for(int i = 0; i < len; i++) {
            if(str[i] >= 'a' && str[i] <= 'z')
                small++;
            else if(str[i] >= 'A' && str[i] <= 'Z')
                large++;
            else if(str[i] >= '0' && str[i] <= '9')
                num++;
            else if(str[i] == ' ')
                blank++;
        }
        printf("%d %d %d %d\n", small, large, num ,blank);
    }
}