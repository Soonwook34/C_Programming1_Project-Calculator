#include <stdio.h>
#include <string.h>

#define StoD(X) (X==0? 0:X-'0')

void reverse(char *arr, int len);

int main(){
	char a[3][51]={0};
	int len, i, j, down = 0;
	printf("첫번째 수를 입력하시오 : ");
	scanf("%s", a[0]);
	printf("두번째 수를 입력하시오 : ");
	scanf("%s", a[1]);

	if(strlen(a[0])>strlen(a[1])){                                                               
		len=strlen(a[0]);
	}
	else len=strlen(a[1]);

	reverse(a[0], strlen(a[0]));
	reverse(a[1], strlen(a[1]));

	for(i=0; i<=len; i++){
		if((StoD(a[0][i])-StoD(a[1][i]))<0)
		{	
		a[2][i]=(StoD(a[0][i])-StoD(a[1][i])+down+10) + '0';
		down = -1; 
		}
		else 
		{
		a[2][i]=StoD(a[0][i])-StoD(a[1][i]) + down + '0';
		down = 0;
		}
	}

	if(a[2][len]=='0') a[2][len]=0; 

	reverse(a[2], strlen(a[2]));

	printf("차는 %s입니다\n", a[2]);

	return 0;
}

void reverse(char *arr, int len){
	char temp;
	int i;
	for(i=0; i<len/2; i++){
		temp=arr[i];
		arr[i]=arr[len-1-i];
		arr[len-1-i]=temp;
	}
}
