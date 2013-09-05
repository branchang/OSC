/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2011 02:47:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhang Ran (), orangezhr@gmail.com
 *        Company:  Sunniwell
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(void)
{
    int h;  /*  number of half dollars */
    int q;  /*  number of quarters     */
    int d;  /*  number of dimes        */
    int n;  /*  number of nickels      */
    int p;  /*  number of pennies      */

    /*  you fill in the rest */
    printf("How many half dollars do you have? ");
    scanf("%d", &h);

    printf("How many quarters do you have? ");
    scanf("%d", &q);
    
    printf("How many dimes do you have? ");
    scanf("%d", &d);

    printf("How many nickels do you have? ");
    scanf("%d", &n);

    printf("How many pennies do you have? ");
    scanf("%d", &p);

    printf("You entered:\t%d half dollars\n", h);
    printf("\t\t%d quarters\n", q);
    printf("\t\t%d dimes\n", d);
    printf("\t\t%d nickels \n", n);
    printf("\t\t%d pennies\n", p);
    
    printf("The value of your %d coins is equivalent to 203 pennies\n", h + q + d + n + p);

    return 0;
}
