//50. Pow(x, n)
class Solution {
public:

 double solve(double x,int n){

          if(n==0){

            return 1; //power of 0 is 1;

        }

       double temp=myPow(x,n/2);

        temp=temp*temp;

        if(n%2==0){

            return temp;

        }

        else{

            return temp*x;

        }

    }

    double myPow(double x, int n) {

        double ans=solve(x,abs(n));

        if(n<0)

            return 1/ans;

            return ans;

       

    }
        
    
};
