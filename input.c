#include <stdio.h>
#include <string.h>

#define N 20

int main()
{
	char input[1000]="";
	char value[N][60];
	int c, i=0, j, k, n;
	printf("입력 : ");
	while(1){
		c = getchar();
		if((c=='\n') || (c==EOF)){
			input[i] = '\0';
			break;
		}
		else if(c==' '){
			;
		}
		else if(((c>='0') && (c<='9')) || (c=='+') || (c=='-') || (c=='*') || (c=='/') || (c=='%') || (c=='=') || (c=='.')){
			input[i] = c;
			i++;
		}
		else{
			printf("error");
			return 0;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			value[i][j]=0;
		}
	}

	for(n=0, j=0, k=0; n<strlen(input); n++){
		c = input[n];

		if((c>='0') && (c<='9')){
			value[j][k] = c;
			k++;
		}
		else if((c=='+') || (c=='-') || (c=='*') || (c=='/') || (c=='%')){
			value[j+1][0] = c;
			j+=2;
			k=0;
		}
		else if(c=='\0'){
			break;
		}
	}
	for(k=0; k<j+1; k++){
		printf("Value%d = %s\n", k, value[k]);
	}
	printf("전체 수식 : ");
	for(k=0; k<j+1; k++){
		printf("%s ",value[k]);
	}
	return 0;
}
