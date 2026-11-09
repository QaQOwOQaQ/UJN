#include <iostream>
using namespace std ;
long long fastpower( long long  base , long long b , long long p ){
    long long  ans = 1   ;
    while ( b >0){
        if ( b%2==1 ){
            ans = (ans % p * base % p) % p ;
        } 
		b=b/2 ;
        base = base * base % p ;
      
    }
    return ans%p ;
}
 
int main(){
    long long  a , b , p ;
  scanf("%lld %lld %lld" , &a , &b , &p)  ;
        printf("%lld\n" , fastpower(a , b , p)) ;
    
    return 0 ;
}
