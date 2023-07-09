#include <iostream> 
 
int main() 
{ 
 int N; 
    
 std::cin >> N; 
 
 int A[N][N]; 
 int B[N][N]; 
 int C[N][N]; 
 
 for (int i = 0; i < N; i++) 
 { 
  for (int j = 0; j < N; j++) 
  { 
   std::cin >> A[i][j]; 
  } 
 } 
 
 std::cin >> N; 
 
 for (int i = 0; i < N; i++) 
 { 
  for (int j = 0; j < N; j++) 
  { 
   std::cin >> B[i][j]; 
  } 
 } 
 
 
 for (int i = 0; i < N; i++) 
  for (int j = 0; j < N; j++) 
  { 
   C[i][j] = 0; 
   for (int z = 0; z < N; z++) 
   { 
    C[i][j] = C[i][j] + A[i][z] * B[z][j]; 
   } 
  } 
     
 for (int i = 0; i < N; i++) 
 { 
  for (int j = 0; j < N; j++){ 
            if (j == N-1) std::cout << C[i][j]; 
            else std::cout << C[i][j] << ' '; 
        } 
        std::cout << std::endl; 
 
 
 } 
 
    return 0; 
}