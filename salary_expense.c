#include<stdio.h>
void main()
{
	float bs, ds, hr, gs;
	printf("enter the basic salary");
	scanf_s("%f", &bs);
	ds = (40 * bs) / 100;
	hr = (20 * bs) / 100;
	printf("the dearness salary=%f\n", ds);
	printf("house rent=%f\n", hr);
}