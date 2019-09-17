#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isValid(char * p){
    if (*p>='a'&&*p<='z' || *p>='A'&&*p<='Z' || *p>='0'&&*p<='9'){
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    char str[250];// char * str 会有问题；从标准输入中读取字符串，要声明为字符数组，不能是一个指向字符的指针
    char * p = str;
    char myChar[100];
    char myCharArray[100][20]={'\0'};
    char (*pc)[20];
    pc = myCharArray;
    gets(str);// scanf("%s",str); scanf 遇到空格字符会停止;gets 可以读取一行，遇到换行符停止
    // I am an 20-years  out--standing @ * -stu- dent
    // printf("%s\n",str);// 测试是否读取成功。
    int len = strlen(str);
    for (int i = 0;i<len;i++){
        if (isValid(p)){
            myChar[i] = *p;
        }
        else if (*p=='-' && isValid(p-1)&&isValid(p+1)){
            myChar[i] = *p;
        }
        else{
            myChar[i] = ' ';
        }
        p++;
    }
    myChar[len]='\0';

    // printf("%s\n",myChar);
    int i = 0;
    int j = 0;//行的索引，有几个单词
    int k = 0;//列的索引，每个单词有几个字符
    while(myChar[i]!='\0'){
        if(isValid(myChar+i) || myChar[i]=='-'){
            *(*(pc+j)+k) = myChar[i];
            k++;
        }
        else{
            j++;
            k = 0;
        }
        i++;
    }
    // for(int i=0;i<15;i++){
    //     printf("%s",*(pc+i));
    // }

    for (int i=j;i>=0;i--){
        if (*(*(pc+i))!='\0'){
            printf("%s ",*(pc+i));
        }
    }
    printf("\n");

    system("pause");
    return 0;
}