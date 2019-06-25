
#include<iostream>
#include<cstring>
#include <stdlib.h>
// 找到数组中重复的数字 
using namespace std;

bool duplicate_fun(int number[],int length,int &a)
{
 if (number==NULL||length<=0)
 {
 return false;
 }  //判断数组是不是空的，长度是不是有效的
 
 for(int i = 0;i<length;i++)
 {
 if(0>number[i]||number[i]>length-1)
 return false;
 } //判断数组中的值是不是在0到n-1区间 
 for(int i=0;i<length;i++)
 {
  if(number[i]!=i)
  {
   if(number[i]==number[number[i]])
   {
    a = number[i];
    return true;
   }
   // 交换number[i] 和 number[number[i]] 的值
  int temp = number[i];
   number[i] = number[temp];
   number[temp] = temp;
   
  }
 
 }
  return false;
}
int main()
{
 int number[] ={2,3,1,0,4,5,3};
    int leng =  sizeof(number)/sizeof(number[0]);
    int a=0;
    duplicate_fun(number,leng,a);
    cout<< a <<endl;
    system("pause");//需要添加 #include <stdlib.h>
    return 0;
}