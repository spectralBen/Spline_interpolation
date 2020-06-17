#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct uFP{
	uint16_t m;	// The mantissa
	uint16_t e;	// The exponent
};


struct sFP{
	int16_t m;
	int16_t e;
};

struct uFP u_fixed_mult(struct uFP a, struct uFP b){

	struct uFP c;
	c.m = (a.m) * (b.m);
	c.e = (a.e) + (b.e);	

	return c;
}

struct sFP s_fixed_mult(struct sFP a, struct sFP b){

	struct sFP c;
	c.m = (a.m) * (b.m);
	c.e = (a.e) + (b.e);

	return c;
}

void u_fixed_print(struct uFP a){

	double d;
	d = a.m * pow(10,a.e);
	
	printf("Mantissa m:\t%d\n", a.m);
	printf("Exponent e:\t%d\n", a.e);
	printf("As a double:\t%f\n", d);
}

void s_fixed_print(struct sFP a){

	double d;
	d = a.m * pow(10,a.e);

	printf("Mantissa m:\t%d\n", a.m);
	printf("Exponent e:\t%d\n", a.e);
	printf("As a double:\t%f\n", d);
}

int main(/* int argc, char* argv[] */){

	struct uFP a;
	a.m = 10;
	a.e = 1;

	struct uFP b;
	b.m = 30;
	b.e = 1;

	struct uFP c;
	c = u_fixed_mult(a,b);

	u_fixed_print(a);
	u_fixed_print(b);
	u_fixed_print(c);

	struct sFP d;
	d.m = 10;
	d.e = 1;

	struct sFP e;
	e.m = 30;
	e.e = 1;

	struct sFP f;
	f = s_fixed_mult(d,e);

	s_fixed_print(d);
	s_fixed_print(e);
	s_fixed_print(f);

	return 0;
}
