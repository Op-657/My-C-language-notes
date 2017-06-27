#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"cJSON.h"

int main(void)
{
    
	cJSON * pobject;
	cJSON * parray; 
	cJSON * parr_ob;
	char * p_Json_char; 
	//先创建空对象
	pobject = cJSON_CreateObject();
	//向对象里面添加键值对
	cJSON_AddStringToObject(pobject,"name","RUIWEN");
	//向对象里面添加数组
	cJSON_AddItemToObject(pobject,"addr",parray=cJSON_CreateArray());
	//往数组中加入对象 
	cJSON_AddItemToArray(parray,parr_ob = cJSON_CreateObject()) ;
	//向数组中的对象添加键值对
	 cJSON_AddStringToObject(parr_ob,"Round","Jianxi");
	cJSON_AddItemToArray(parray,parr_ob = cJSON_CreateObject()) ;
	cJSON_AddStringToObject(parr_ob,"specific","Ganzhou");
		//向对象里面添加数字
	cJSON_AddNumberToObject(pobject,"age",23.5);
	//将Json数据结构转换成字符串 
//	cJSON_Delete(parr_ob);
	 p_Json_char = cJSON_Print(pobject);
	 //清除在生成过程中产生的内存

	cJSON_Delete(pobject);
	//parr_ob所指向的对象是属于pobject这个对象的，而pobject已经被清除了
	//所以不能再清除 
	//printf("%s",cJSON_Print(parr_ob));
	 //打印生成的Json格式 
	 printf("%s",p_Json_char);
	
	return 0;
}
