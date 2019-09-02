#include<stdio.h>
#include<stdlib.h>
void printNumDrink(int NumBottle){
    int NumDrink = 0;
    while (NumBottle > 2){
        NumDrink = NumDrink + (NumBottle/3);
        NumBottle = NumBottle%3 + (NumBottle/3);
    }
    if (NumBottle==2){
        NumDrink++; //最后剩下两个空瓶子的时候，可以先向老板借一个空瓶子，拿3个空瓶换一瓶饮料，喝完再把空瓶还给老板；
    }
    printf("%d\n",NumDrink);
    return;
}

int main(){
    int NumBottle[10]={0};
    int tmp = 0;
    int i = 0;
    //使用 scanf 时，要判断是否正常读取了输入
    while((scanf("%d", &tmp)!=EOF) && (tmp != 0)){
        NumBottle[i]=tmp;
        i++;
    }
    for (i=0;i<10;i++){
        if(NumBottle[i] != 0){
            printNumDrink(NumBottle[i]);
        }
        else{
            break;
        }
    }
    system("pause");
    return 0;
}