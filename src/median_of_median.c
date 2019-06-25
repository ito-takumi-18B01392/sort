#include <stdio.h>

// 素数
#define N 2999

int A[N];
int B[(N+4)/5];
// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int quick_select(int A[], int n, int k){
  int i, j, pivot;
  for(i = j = 1; i < n; i++){
    if(A[i] <= pivot){
      swap(A+i, A+j);
      j++;
    }
  }

  if(j == k+1) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+1, j-1, k);
}

int median(int A[], int n){
    if (n<5) {return A[0];}
    else {int i;
        for (i=0; i<n/5; i++){
            B[i] = quick_select(A+5*i,5,2); }
        if (n%5 != 0) {B[i+1] = quick_select(A+5*(i+1),n%5,(n%5)/2);
    }
        quick_select(B, (n+4)/5, (n+4)/10);
    
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
