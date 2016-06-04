#include<stdio.h>
#include<string.h>
#define MAX 60
#define FLOAT 9
int num[3][MAX];
void MultiplyTen(int a){		//곱하기 10
	for(int i = 1; i < MAX - 1; i++)
	num[a][i] = num[a][i + 1];
	num[a][MAX-1] = 0;
}
void DivideTen(int a){
	for(int i = 2; i < MAX; i++)
	num[a][i] = num[a][i - 1];
	num[a][1] = 0;
}
int compare(int a,int b){		//비교	//(a가크면 a) (b가 크면 b) (같으면 0) 리턴
	for(int i = 1; i < MAX; i++){
		if(num[a][i] < num[b][i])
			return b;//B가크다
		else if(num[a][i] > num[b][i])
			return a;//A가크다
	}
	return 0;
}

int divide(int a,int b)	//일단은 이론만	//a와 b를 넣으면
{
	int size = 0;	//10의 - 몇승?
	int answer = 0;
	부호 = (a의부호 + b의부호) % 2;	//부호 결정
	while(size != -9){	//
		while(compare(a,b) != a){	// a <= b	이면
			a -= b;
			answer += (10 ^ (size));	//	10^(size)
		}
		size--;
		MultiplyTen(a);	//a *= 10;
	}
}	// 나누기된 c가 온다
나누기를하려면 플러스마이너스가 필요한데 그거만 넣으면 됨 
int rest(int a,int b){
	c= divide(a,b);
	
	for(int i = MAX - FLOAT; i < MAX; i++)	//소수점 아래수 전부 버리기
		num[c][i] = 0;
	c = multiply(a,b);
	return a - c;

}




int main(void){
	int a,b,c;
	a = input();
	b = input();
	c = divide(a,b);
	remove(a);
	remove(b);
	return 0;


}
/알고리즘 만들어 났으니까 니네소스집어넣기만하면 끝이야
