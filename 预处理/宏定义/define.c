#define SQR(x) (x)*(x)
#define EMPTY
#include "stdio.h"
#define add(x)   (x)+(x)//C�����ÿո����ֺ�������滻�Ķ��󣬵���ֻ���ڶ����ʱ����Ч����ʹ�õ�ʱ��ո�ᱻ���������� 
int main()
{
	printf("SQR(10)");
	printf("%d\n",SQR(10));
	printf("%d\n",SQR(10+1));
	printf("%d\n",add    (1));//�����ֵ��ú꺯���Ľ����һ���� 
	printf("%d\n",add(1));
	return 0;
}
