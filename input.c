#include <stdio.h>
#include <string.h>

#define N 100

int main()
{
	//처음에 입력 받는 배열
	char input[1000] = {0};
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
			;
		}
		//받을 수 있는 것(숫자, 알파벳, 수식 기호, 소수점)은 input배열에 저장한다
		else if(((c>='0') && (c<='9')) || (c>='a') && (c<='z') || (c>='A') && (c<='Z') || (c=='+') || (c=='-') || (c=='*') || (c=='/') || (c=='%') || (c=='=') || (c=='.')){
			input[i] = c;
			i++;
		}
		//나머지를 받았을 경우
		else{
			printf("error");
			return 0;
		}
	}

	//수식 구분하기
	for(i=0, j=0, k=0, l=0; i<strlen(input); i++){
		c = input[i];

		//자리수가 초과하는지 검사
		if(deciCount[j][0]){
			if(l==9){
				printf("decimal place error\n\n\n");
				break;
			}
		}
		else{
			if(k==50){
				printf("integer place error\n\n\n");
			}
		}

		//숫자
		if((c>='0') && (c<='9')){
			if(deciCount[j][0]){
				deciCount[j][1]+=1;
				l++;
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
		else if((c=='+') || (c=='-') || (c=='*') || (c=='/') || (c=='%')){
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

		//'='기호
		else if (c=='='){
			if(value[j][0]>='0' && value[j][0]<='9'){
				for(m=deciCount[j][1];m<9;m++){
					value[j][k]='0';
					k++;
				}
			}
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
	}

	//마지막 수의 소수자리 처리
	if(value[j][0]>='0' && value[j][0]<='9'){
		for(m=deciCount[j][1];m<9;m++){
			value[j][k]='0';
			k++;
		}
	}

	//나눈 배열 확인
	for(k=0; k<j+1; k++){
		printf("Value%d = %s, %d\n", k, value[k], deciCount[k][1]);
	}
	
	//배열의 길이 확인
	for(k=0; k<j+1; k++){
		printf("%d\n", strlen(value[k]));
	}

	//출력
	printf("전체 수식 : ");
	for(k=0, l=0; k<j+1; k++){
		for(n=0; n<strlen(value[k]); n++){
			if(n==strlen(value[k])-9){
				printf(".");
			}
			else if(l%3==strlen(value[k])%3 && l!=0){
				printf(",");
			}
			printf("%c", value[k][n]);
			l++;
		}
		printf(" ");
	}
	return 0;
}
