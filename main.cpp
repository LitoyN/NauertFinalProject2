
#include <cstdlib>
#include <iostream>


// fact[x] = smallest prime factor of x (1 if x is prime)
int *fact;

// Euler's Totient function
int phi(int x) {
    
  if(x <= 1)
      return 1;
  
  int f = fact[x];
  
  if(f == 1)
      return x-1;
  
  int p = 1;
  int fp = 1;
  
  while((x /= f) % f == 0){
      p++;
      fp *= f;
  }
  
  return phi(x)*(f-1)*fp;
}

int main() {
    
  int upperLimit = 1000000;
  
  // Compute fact[]
  fact = new int[upperLimit];
  for(int i = 0; i <= upperLimit; i++){
      fact[i] = 1;
  }
  
  for(int i=2; i <= upperLimit; i++){
    if(fact[i] == 1) {
        for(int k=i+i; k <= upperLimit; k+=i){
            if(fact[k] == 1){
                fact[k] = i;
            }
        }
    }
  }

  // Sum phi(2) .. phi(M)
  unsigned long int total = 0;
  for(int i=2; i <= upperLimit; i++){
      total += phi(i);
  }
  std::cout << "Total RPFs: " << total;
  return 0;
}