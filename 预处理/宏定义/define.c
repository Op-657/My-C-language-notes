#define SQR(x) (x)*(x)
#define EMPTY
#include "stdio.h"
#define add(x)   (x)+(x)//C语言用空格区分宏替身和替换的对象，当着只是在定义的时候有效，在使用的时候空格会被编译器忽略 
int main()
{
	printf("SQR(10)");
	printf("%d\n",SQR(10));
	printf("%d\n",SQR(10+1));
	printf("%d\n",add    (1));//着两种调用宏函数的结果是一样的 
	printf("%d\n",add(1));
	return 0;
}
