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
	//�ȴ����ն���
	pobject = cJSON_CreateObject();
	//�����������Ӽ�ֵ��
	cJSON_AddStringToObject(pobject,"name","RUIWEN");
	//����������������
	cJSON_AddItemToObject(pobject,"addr",parray=cJSON_CreateArray());
	//�������м������ 
	cJSON_AddItemToArray(parray,parr_ob = cJSON_CreateObject()) ;
	//�������еĶ�����Ӽ�ֵ��
	 cJSON_AddStringToObject(parr_ob,"Round","Jianxi");
	cJSON_AddItemToArray(parray,parr_ob = cJSON_CreateObject()) ;
	cJSON_AddStringToObject(parr_ob,"specific","Ganzhou");
		//����������������
	cJSON_AddNumberToObject(pobject,"age",23.5);
	//��Json���ݽṹת�����ַ��� 
//	cJSON_Delete(parr_ob);
	 p_Json_char = cJSON_Print(pobject);
	 //��������ɹ����в������ڴ�

	cJSON_Delete(pobject);
	//parr_ob��ָ��Ķ���������pobject�������ģ���pobject�Ѿ��������
	//���Բ�������� 
	//printf("%s",cJSON_Print(parr_ob));
	 //��ӡ���ɵ�Json��ʽ 
	 printf("%s",p_Json_char);
	
	return 0;
}
