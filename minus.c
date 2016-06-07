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
