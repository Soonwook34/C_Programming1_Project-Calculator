/******************************************
 *** 1학년 1학기 프로젝트 : 큰수계산기	***
 *** 시작 날짜 : 2016년5월 29일			***
 *** 팀원 :	박순욱(20160290)			***
 ***		임규형(20160318)			***
 ***		전혜윤(20160326)			***
 ***		배서현(20160294)			***
 ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void inputNum(char input[]);
void reverse(char rev[], int n);
void integer(char inte[], int n);
int plus(char a[], int n, char b[], int m, char answer[]);

int main()
{
	while(1){
		char input[10000] = {0};
		inputNum(input);
		if(input[0]=='e' && input[1]=='n' && input[2]=='d' && input[3]=='\0'){
			break;
		}
		if(input[0]=='c' && input[1]=='l' && input[2]=='e' && input[3]=='a' && input[4]=='r' && input[5]=='\0'){
			system("clear");
		}
	}
	return 0;
}

void inputNum(char input[])
{
	//수와 문자와 기호를 저장할 배열
	char value[N][59] = {0};
	//소수
	char deciCount[N][2] = {0};
	int c, i=0, j, k, n, m, l;

	printf("입력 : ");

	//처음 입력 받기
	while(1){
		//수식 입력의 마지막 처리
		c = getchar();
		if((c=='\n') || (c==EOF)){
			input[i] = '\0';
			break;
		}
		//띄어쓰기 무시
		else if(c==' '){
			continue;
		}
		//받을 수 있는 것(숫자, 알파벳, 수식 기호, 소수점)은 input배열에 저장한다
		else if(((c>='0') && (c<='9')) || (c>='a') && (c<='z') || (c>='A') && (c<='Z') || (c=='+') || (c=='-') || (c=='*') || (c=='/') || (c=='%') || (c=='=') || (c=='.')){
			input[i] = c;
			i++;
		}
		//나머지를 받았을 경우
		else{
			printf("error");
			return;
		}
	}

	//수식 구분하기
	for(i=0, j=0, k=0, l=0; i<strlen(input); i++){
		c = input[i];

		//숫자
		if((c>='0') && (c<='9')){
			if(deciCount[j][0]){
				deciCount[j][1]+=1;
			}
			value[j][k] = c;
			k++;
		}

		//알파벳
		else if((c>='a') && (c<='z') || (c>='A') && (c<='Z')){
			if(deciCount[j][0]){
				printf("error\n");
				break;
			}
			value[j][k] = c;
			k++;
		}

		//수식기호
		else if((c=='+') || (c=='-') || (c=='*') || (c=='/') || (c=='%') || (c=='=')){
			if(value[j][0]>='0' && value[j][0]<='9'){
				for(m=deciCount[j][1];m<9;m++){
					value[j][k]='0';
					k++;
				}
			}
			value[j][k]='\0';
			value[j+1][0] = c;
			j+=2;
			k=0;
		}

		//소수점
		else if (c=='.'){
			if(deciCount[j][0]){
				printf("error\n");
				break;
			}
			deciCount[j][0]=1;
		}

		//배열의 끝
		else if(c=='\0'){
			value[j][k]='\0';
			break;
		}
		//자리수가 초과하는지 검사
		if(deciCount[j][0]){
			if(deciCount[j][1]==10){
				printf("decimal place error\n\n\n");
				break;
			}
		}
		else{
			if(k==51){
				printf("integer place error\n\n\n");
				break;
			}
		}
	}

	//마지막 수의 소수자리 처리
	if(value[j][0]>='0' && value[j][0]<='9'){
		for(m=deciCount[j][1];m<9;m++){
			value[j][k]='0';
			k++;
		}
	}

	//end
	if(input[0]=='e' && input[1]=='n' && input[2]=='d' && input[3]=='\0'){
		return;
	}

	//clear
	if(input[0]=='c' && input[1]=='l' && input[2]=='e' && input[3]=='a' && input[4]=='r' && input[5]=='\0'){
		return;
	}
	//나눈 배열 확인
	/*for(k=0; k<j+1; k++){
		printf("Value%d = %s, %d\n", k, value[k], deciCount[k][1]);
	}

	//배열의 길이 확인
	for(k=0; k<j+1; k++){
		printf("%d\n", strlen(value[k]));
	}*/

	char answer[59] = {0};
	int v1=strlen(value[0]);
	int v2=strlen(value[2]);
	int tmp;
	if(value[1][0]=='+'){
		integer(value[0],v1);
		integer(value[2],v2);
		reverse(value[0],v1);
		reverse(value[2],v2);

		tmp = plus(value[0],v1,value[2],v2,answer);

		reverse(answer,tmp);
		
		printf("답 : ");
		for(l=0, i=0; i<tmp; i++){
			if(i==tmp-9){
				printf(".");
			}
			else if(l%3==tmp%3 && l!=0 && i!=1){
				printf(",");
			}
			printf("%d", answer[i]);
			l++;
		}
	}
	//출력
	/*printf("전체 수식 : ");
	for(k=0, l=0; k<j+1; k++){
		for(n=0; n<strlen(value[k]); n++){
			if(n==strlen(value[k])-9){
				printf(".");
			}
			else if(l%3==strlen(value[k])%3 && l!=0 && strlen(value[k])!=1){
				printf(",");
			}
			printf("%d", value[k][n]);
			l++;
		}
		printf(" ");
		l=0;
	}*/
	printf("\n");
	return;
}

int plus(char a[], int n, char b[], int m, char answer[])
{
	int i, j;
	
	if(n>=m){
		j=n;
	}
	else{
		j=m;
	}

	for(i=0;i<j;i++){
		answer[i] = a[i] + b[i];
	}
	for(i=0;i<=j;i++){
		if(answer[i] >= 10){
			answer[i] -= 10;
			answer[i+1] += 1;
		}
	}
	return j;
}

void reverse(char rev[], int n)
{
	char tmp;
	int i;
	for(i=0;i<n/2;i++){
		tmp = rev[i];
		rev[i] = rev[n-1-i];
		rev[n-1-i] = tmp;
	}
	return;
}

void integer(char inte[], int n)
{
	int i;
	for(i=0;i<n;i++){
		if(inte[i]!=0){
			inte[i] -= '0';
		}
	}
	return;
}
