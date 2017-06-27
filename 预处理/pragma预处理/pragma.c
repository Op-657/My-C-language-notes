/*#pragma预处理，#pragma的作用是设定编译器的状态或者是指示编译器完成一些特定的动作*/
/* 使用格式为： #pragma para       //para 为参数*/

//#pragma once //这里只是例子，本来应该放在头文件中的 
#include "stdio.h" 
/* 
使用方法1：#pragma message("消息文本")
意义：能够在编译信息输出窗口中输出相应的信息，对于源代码信息的控制是非常重要的
具体应用情景：当你不清楚一个宏定义是否定义是，可使用如下指令：
       #ifdef      X86
       #pragma message("X86 is defined")
       #endif
当X86被定义的时候，#pragme被执行，编译信息的输出窗口输出 X86 is defined 的编译信息
*/ 
#define X86 1
#ifdef	X86
#pragma message("X86 is defined")
#endif



/*
使用方法2：#pragma code_seg
作用：设该指令用来指定函数在.obj文件中存放的节,函数在.obj文件中默认的存放节为.text节，
如果code_seg没有带参数的话,则函数存放在.text节中。
使用格式：#pragma code_seg( [ [ { push | pop}, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )
		push (可选参数) 将一个记录放到内部编译器的堆栈中,可选参数可以为一个标识符或者节名
		pop(可选参数) 将一个记录从堆栈顶端弹出,该记录可以为一个标识符或者节名
		identifier (可选参数) 当使用push指令时,为压入堆栈的记录指派的一个标识符,当该标识符被删除的时候和其相关的堆栈中的记录将被弹出堆栈
		"segment-name" (可选参数) 表示函数存放的节名
例如：
//默认情况下，放在.text中 
void func1() {                   // stored in .text
}

//将函数存放在.my_data1节中
#pragma code_seg(".my_data1")
void func2() {                   // stored in my_data1
}

//r1为标识符,将函数放入.my_data2节中
#pragma code_seg(push, r1, ".my_data2")
void func3() {                   // stored in my_data2
} 
*/ 

/*
使用方法3：#pragma once
作用：只要将这条语句放在头文件开头，就可以保证头文件只被编译一次，当然也可以用#ifndef   #endif
*/


/*
使用方法4：#pragma hdrstop
作用：表示预编译头文件到此为止，后面的头文件不进行预编译
*/


/*
使用方法5：#pragma comment
作用：该指令将一个注释记录放入一个对象文件或可执行文件中
格式：#pragma comment(...)
例子：
(1)关键字：lib   将lib文件加入到工程
#pragma comment(lib,"user32")      //支持相对路径
(2) 关键字：linker   将一个链接选项放入目标文件中，你可以使用这个指令来代替由命令行传入的
或在开发环境中设置的连接选项，你可以指定/include 选项来强制包含某个对象
#pragma comment(linker,"/inclde:___mySymbol");
*/


/*
使用方法6：#pragma pack(n)
作用：指示编译器按n字节对齐，当n缺省时，表示按编译器默认的字节对齐方式
使用格式：
				#pragma pack(n)
				。。。。。
				。。。。。
				。。。。。
				#pragma pack()
中间的代码，按指定的n字节对齐
*/ 
#define MEMORY_ALIGNMENT 1

#ifdef MEMORY_ALIGNMENT//如果定义自定义内存对齐，则执行下面的指令， 
#pragma pack(1) //pirntf 得出的结果为0 1 3 4,
struct TestStuct1{
	char c1;
	short s;
	char c2;
	int i;
};
#pragma pack()
#else  // 采用默认的对齐方式 ：pirntf 得出的结果为0 2 4 8 
struct TestStuct1{
	char c1;
	short s;
	char c2;
	int i;
};
#endif

#pragma pack(4) //
struct TestStruct4{
	char a;
	long b;
};
struct TestStruct5{
	char c;
	struct TestStruct4 d;
	long long e;
};
#pragma pack()



int main()
{
	struct TestStuct1 TestStuct={1,2,3,4};//结果体直接初始化用{}，元素之间用逗号隔开 
	struct TestStruct5 TestStructure;
	//探究内存对齐问题
	printf("c1 %p, s %p,c2 %p,i %p\n",&TestStuct.c1,&TestStuct.s,&TestStuct.c2,&TestStuct.i);
	//得出来的结果为 0 2 4 8，本来按照类型的实际内存分配，得到的结果应该是0,1,3,4，不一样的原因就是因为
	//内存对齐的问题 
	printf("hello world\n");
	printf("%d\n",sizeof(TestStructure));//n=1 输出为14，n=2输出为16，n=4,输出为20，n=8 输出为24 
	printf("sizeof(long long) = %d\n",sizeof(long long));
	printf("sizeof(int) = %d\n",sizeof(int));
	printf("sizeof(long) = %d\n",sizeof(long));
	return 0;
}
