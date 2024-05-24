#include"circle.h"
#include"square.h"
#include"rectangle.h"

int main(void)
{
	float r=2.5, l=10.2, b=12.5, a=3.5;

	printf("area of circle for r=%f is %f\n",r,area_of_circle(r));

	printf("area of rectangle for l=%f and b=%f is %f\n",l,b,area_of_rect(l,b));
	
	printf("area of sqaure for a=%f is %f\n",a,area_of_square(a));

	return 0;
}
