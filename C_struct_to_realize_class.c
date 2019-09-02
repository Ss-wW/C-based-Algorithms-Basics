#include <stdio.h>
//C 语言没有类，但可以用结构体充当一个类
//与类不同，结构体只能定义变量，不能够定义函数，可以通过函数指针的方法来实现其功能
//定义“类 ”的成员变量以及方法
typedef struct Person{
    char name;
    int age;
    void (*EatFunction)(struct Person _this,int num);
}Person;
//定义函数功能
void EatFunction(struct Person _this, int num){
    printf("Test\n");
}
//定义“类 ”的构造函数
//与面向对象不同，C语言的“类”的 构造函数不能放在“类”中，只能放在“类”外
//构造函数主要完成 变量的初始化，以及函数指针的赋值
Person *NewPerson(Person *_this){
    _this->name = 'A';
    _this->age = 18;
    _this->EatFunction = EatFunction;
}
//主函数调用
int main(){
    Person person;
    NewPerson(&person);
    person.EatFunction(person,0);
    return 0;
}