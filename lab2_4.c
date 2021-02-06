/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name:Demetrius Christou
- 	Section:E
-	NetID:ddc
-	Date:9/5/2018
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{

    /* Put your code after this line */
	int a = 6427 + 1725, b = (6971 * 3925) - 95, e = (22 / 3) * 3, f = 22 / (3 * 3), j = 22.0 / (3 * 3.0);
	double c = 79 + 12 / 5, d = 3640.0 / 107.9, g = 22 / (3 * 3), h = 22 / 3 * 3, i = 22.0 / 3 * 3, k = 22.0 / 3.0 * 3.0;
	
	printf(" a = %d\n b = %d\n c = %.2lf\n d = %.2lf\n e = %d\n f = %d\n g = %.2lf\n h = %.2lf\n i = %.2lf\n j = %d\n k = %.2lf\n", a, b, c, d, e, f, g, h, i, j, k);
	
	// l.
	
	const double piVal = 3.1456;
	double circ = 23.567; //circ is circumference
	
	printf("(%.3lf * %.3lf )/(4 * pi) = %.3lf\n", circ, circ, (circ * circ) / (4 * piVal) );//I came up with the formula by googling for how to find the area of a circle with the circumference.

	// m.
	
	const double ftToM = 0.3048;
	int ft = 14;
	double meters = (double)ft * ftToM;
	printf("%d feet is %.2lf meters\n", ft, meters);//since I knew that 1 ft is .3048 meters i just multplied the amount of feet by .3048
    
	// n.
	
	int fahren = 76;
	
	printf("%d degrees fahrenheight is %.2lf degrees Centigrade\n", fahren, ( (double)fahren - 32) / 1.8 );//since the formula was given i just plugged fahren in while changing it to a double to allow it to return a decimal.
	return 0;

}

