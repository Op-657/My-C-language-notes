/*#pragmaԤ����#pragma���������趨��������״̬������ָʾ���������һЩ�ض��Ķ���*/
/* ʹ�ø�ʽΪ�� #pragma para       //para Ϊ����*/

//#pragma once //����ֻ�����ӣ�����Ӧ�÷���ͷ�ļ��е� 
#include "stdio.h" 
/* 
ʹ�÷���1��#pragma message("��Ϣ�ı�")
���壺�ܹ��ڱ�����Ϣ��������������Ӧ����Ϣ������Դ������Ϣ�Ŀ����Ƿǳ���Ҫ��
����Ӧ���龰�����㲻���һ���궨���Ƿ����ǣ���ʹ������ָ�
       #ifdef      X86
       #pragma message("X86 is defined")
       #endif
��X86�������ʱ��#pragme��ִ�У�������Ϣ������������ X86 is defined �ı�����Ϣ
*/ 
#define X86 1
#ifdef	X86
#pragma message("X86 is defined")
#endif



/*
ʹ�÷���2��#pragma code_seg
���ã����ָ������ָ��������.obj�ļ��д�ŵĽ�,������.obj�ļ���Ĭ�ϵĴ�Ž�Ϊ.text�ڣ�
���code_segû�д������Ļ�,���������.text���С�
ʹ�ø�ʽ��#pragma code_seg( [ [ { push | pop}, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )
		push (��ѡ����) ��һ����¼�ŵ��ڲ��������Ķ�ջ��,��ѡ��������Ϊһ����ʶ�����߽���
		pop(��ѡ����) ��һ����¼�Ӷ�ջ���˵���,�ü�¼����Ϊһ����ʶ�����߽���
		identifier (��ѡ����) ��ʹ��pushָ��ʱ,Ϊѹ���ջ�ļ�¼ָ�ɵ�һ����ʶ��,���ñ�ʶ����ɾ����ʱ�������صĶ�ջ�еļ�¼����������ջ
		"segment-name" (��ѡ����) ��ʾ������ŵĽ���
���磺
//Ĭ������£�����.text�� 
void func1() {                   // stored in .text
}

//�����������.my_data1����
#pragma code_seg(".my_data1")
void func2() {                   // stored in my_data1
}

//r1Ϊ��ʶ��,����������.my_data2����
#pragma code_seg(push, r1, ".my_data2")
void func3() {                   // stored in my_data2
} 
*/ 

/*
ʹ�÷���3��#pragma once
���ã�ֻҪ������������ͷ�ļ���ͷ���Ϳ��Ա�֤ͷ�ļ�ֻ������һ�Σ���ȻҲ������#ifndef   #endif
*/


/*
ʹ�÷���4��#pragma hdrstop
���ã���ʾԤ����ͷ�ļ�����Ϊֹ�������ͷ�ļ�������Ԥ����
*/


/*
ʹ�÷���5��#pragma comment
���ã���ָ�һ��ע�ͼ�¼����һ�������ļ����ִ���ļ���
��ʽ��#pragma comment(...)
���ӣ�
(1)�ؼ��֣�lib   ��lib�ļ����뵽����
#pragma comment(lib,"user32")      //֧�����·��
(2) �ؼ��֣�linker   ��һ������ѡ�����Ŀ���ļ��У������ʹ�����ָ���������������д����
���ڿ������������õ�����ѡ������ָ��/include ѡ����ǿ�ư���ĳ������
#pragma comment(linker,"/inclde:___mySymbol");
*/


/*
ʹ�÷���6��#pragma pack(n)
���ã�ָʾ��������n�ֽڶ��룬��nȱʡʱ����ʾ��������Ĭ�ϵ��ֽڶ��뷽ʽ
ʹ�ø�ʽ��
				#pragma pack(n)
				����������
				����������
				����������
				#pragma pack()
�м�Ĵ��룬��ָ����n�ֽڶ���
*/ 
#define MEMORY_ALIGNMENT 1

#ifdef MEMORY_ALIGNMENT//��������Զ����ڴ���룬��ִ�������ָ� 
#pragma pack(1) //pirntf �ó��Ľ��Ϊ0 1 3 4,
struct TestStuct1{
	char c1;
	short s;
	char c2;
	int i;
};
#pragma pack()
#else  // ����Ĭ�ϵĶ��뷽ʽ ��pirntf �ó��Ľ��Ϊ0 2 4 8 
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
	struct TestStuct1 TestStuct={1,2,3,4};//�����ֱ�ӳ�ʼ����{}��Ԫ��֮���ö��Ÿ��� 
	struct TestStruct5 TestStructure;
	//̽���ڴ��������
	printf("c1 %p, s %p,c2 %p,i %p\n",&TestStuct.c1,&TestStuct.s,&TestStuct.c2,&TestStuct.i);
	//�ó����Ľ��Ϊ 0 2 4 8�������������͵�ʵ���ڴ���䣬�õ��Ľ��Ӧ����0,1,3,4����һ����ԭ�������Ϊ
	//�ڴ��������� 
	printf("hello world\n");
	printf("%d\n",sizeof(TestStructure));//n=1 ���Ϊ14��n=2���Ϊ16��n=4,���Ϊ20��n=8 ���Ϊ24 
	printf("sizeof(long long) = %d\n",sizeof(long long));
	printf("sizeof(int) = %d\n",sizeof(int));
	printf("sizeof(long) = %d\n",sizeof(long));
	return 0;
}
