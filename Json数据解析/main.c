#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"cJSON.h"
char * Json_char="{\"name\": \"RUIWEN\",\"addr\": [{\"Round\":\"Jianxi\"}, {\"specific\":\"Ganzhou\"}],\"age\":23}";
const char * json_char2= "{\"name\":\"RUIWEN\",\"addr\":\"jianxi\"}"; 

int main(void)
{
    cJSON * pobject;
    cJSON * PItem; 
	pobject = cJSON_Parse(json_char2);
	PItem = cJSON_GetObjectItem(pobject,"addr");
	if(PItem!=NULL)
	printf("%d\n",pobject->type);
	printf("%d\n",pobject->next);
	printf("%d\n",pobject->prev);
	printf("%s\n",PItem->child);
	printf("%d\n",pobject->valueint);
	printf("%d\n",pobject->valuedouble);
	printf("%d\n",PItem->type);
	printf("%s\n",PItem->string);
	printf("%s\n",PItem->valuestring);
	
	return 0;
}
