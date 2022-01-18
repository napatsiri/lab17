#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *d,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << d[i];
        if(i%M >= (M-1)) cout << endl;
        else cout << " ";
    }
}

void randData(double *d,int N,int M){
    for(int i = 0; i < N*M; i++){
        d[i] = (rand()%101);
        d[i] /= 100;
    }
}

void findRowSum(const double *d,double *s1,int N,int M){
	for(int i = 0; i < N; i++){
		double s = 0;
		for(int j = 0; j < M; j++){
			s += *((d+j)+(M*i));
		}
	s1[i] = s;
	}
}


void findColSum(const double *d,double *s2,int N,int M){
	int i = 0, j = 0;
	s2[j] = 0;
	for(int k = 0; k < M; k++){
		i = k;
		for(int v = 0; v < N; v++){
			s2[j] += d[i];
			i += M;
		}
	j++;
	s2[j] = 0;
	}
}