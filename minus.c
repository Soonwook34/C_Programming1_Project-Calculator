<<<<<<< HEAD
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
=======
#include<stdio.h>
#include<string.h>
#define MAX 100
int main(){
	char num[3][MAX] = {0};
	char litter1, litter2;


	printf("A = ");
	scanf("%s", num[0]);
	fflush(stdin);
	printf("B = ");
	scanf("%s", num[1]);	
	litter1 = strlen(num[0]);
	litter2 = strlen(num[1]);
	for(int i = 0 ; i < MAX; i++){//문자열 -> 숫자
		if(num[0][i] != 0)
			num[0][i] -= '0';
		if(num[1][i] != 0)
			num[1][i] -= '0';
	}
	for(int i = 0 ; i < litter1; i++){	// 반전
		num[0][MAX-litter1+i] = num[0][i];
		num[0][i] = 0;
	}
   	for(int i = 0 ; i < litter2; i++){	//반전2
		num[1][MAX-litter2+i] = num[1][i];
		num[1][i] = 0;
	}
	for(int i = 0 ; i < MAX; i++)		//전부 더하기
		num[2][i] = num[0][i] - num[1][i];
	for(int i = MAX -1 ; i >= 0; i--)
		if(num[2][i] < 0){		// 올림
			num[2][i] += 10;
			num[2][i-1] -= 1;
		}
	int start;
	for(int i = 0; i < MAX; i++)		//00000000302323 일때 00000000(여기부터)302323 (start구하기)
		if(num[2][i] != 0){
			start = i;
			break;
		}
	printf("    ");
	for(int i = start ; i < MAX; i++)	//출력
		printf("%d",num[2][i]);
}
>>>>>>> 50a4fe12bb3d302e21e6d8be117dd43bb58bf822
