#include <conio.h>
#include <stdio.h>
int main()
{   long moneyToBuy;
    int cout =0;
    
    long cashes[8] = {500000, 200000, 100000, 20000, 10000, 5000, 2000, 1000};
    long cash;
 	    for(int i=0; i<9; i++){

            cash = moneyToBuy / cashes[i]; 
            
            if (cash!=0)
            {
                 printf("%ld\n",cashes[i]);
            }
            moneyToBuy  = moneyToBuy % cashes[i];	 
               cout ++;       
         }
         printf("%d", cout);
    getch();
    return 0;
}