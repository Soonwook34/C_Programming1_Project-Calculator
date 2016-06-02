#include <stdio.h>
#include <string.h>

#define N 20

void mul(char ans[][N], char a[], char b[], int length1, int length2);
void rvs(char p[], int length);


/*메인함수*/

int main(void)
{
	int i,length1, length2, length3;					//배열의 길이
	char temp[N] = {0};
	char a[N] = {1,2,4};								//첫번째 입력 숫자
	char b[N] = {9,2};									//두번째 입력 숫자
	char ans[N][N] = {0};								//답

	length1 = strlen(a);
	length2 = strlen(b);


	for(i = length1-1;i>=0;--i)
		printf("%d ",a[i]);
	printf("\n");
	for(i = length2-1 ;i>=0;--i)
		printf("%d ",b[i]);
	printf("\n");

	rvs(a,length1);										//역행시키기
	rvs(b,length2);

	if(length1 >= length2)								// 2번째 입력된 숫자의 자릿수가 더 클 경우
	{													// a와 b 를 swap한다.
		mul(ans,a,b,length1,length2);
	}
	else mul(ans,b,a,length2,length1);
	

	length3 = strlen(ans);


	printf("answer = ");
	rvs(ans,length3);
	for(i=0;i <= length3-1; i++)
		printf("%d",ans[0][i]);
	printf("\n");

	return 0;
}


/*곱하기 함수*/
void mul(char ans[][N], char a[N], char b[N], int length1, int length2)
{

	int i,j;
    int carry=0;
		for(j=0;j<N;j++)
		for(i=0;i<N;i++)
		  {
			 ans[j][i] = (a[i] * b[j]  + carry)%10;
		  	 carry = (a[i] * b[j] + carry)/10;
		  }
	/* for(j=0;j<N;j++)
	 	for(i=0;i<N;i++)
		  {
			  printf("%d", ans[j][i]);
		  }
	*/
	
	//곱해준다.


	//한자리씩 올려준다
	for(j=1;j<N;j++)
	{
		for(i=N-1;i>=0;i--)
			ans[j][i+j] = ans[j][i];
	}

	//필요없는 값 정리
	for(j=1;j<=N;j++)
	{
		for(i=1;i<=j;i++)
			ans[j][j-i] = 0;
	}

	printf("%d %d %d \n%d %d %d %d %d\n",ans[0][0],ans[0][1],ans[0][2],ans[1][0],ans[1][1],ans[1][2],ans[1][3],ans[1][4]);

	//더해준다
	carry=0;

		for(j=0;j<N;j++)
		for(i=0;i<N;i++)
		  {
			  if(carry +ans[0][i] + ans[j+1][i] >= 10)
			  {/*
			 	ans[0][i] = (ans[0][i] + ans[j+1][i] + carry)%10;
			 	carry = (ans[0][i] + ans[j+1][i] + carry)/10;
			 */
				  
			 	ans[0][i] = (ans[0][i] + ans[j+1][i] + carry)-10;
				carry=1;
				  }
			  else
			  {
				  ans[0][i] = ans[0][i] + ans[j+1][i] + carry;
				  carry=0;
			  }
		  }

		printf("%d %d %d %d %d",ans[0][0],ans[0][1],ans[0][2],ans[0][3],ans[0][4]);


}


/*역행 함수*/
void rvs(char p[],int length)
{
	char tmp;
	int i;
	for(i=0;i<length/2;i++)
	{
		tmp = p[i];
		p[i] = p[length-1-i];
		p[length-1-i] = tmp;
	}

}
