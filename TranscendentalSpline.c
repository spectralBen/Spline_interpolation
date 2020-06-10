//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-INCLUDE--------------------------------------------------------------------//
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>


//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-DEFINE---------------------------------------------------------------------//
#define FIXED_POINT_FRACTIONAL_BITS 10
#define SPLINE_NUM 10
#define SPLINE_WIDTH 10
#define SPLINE_START 0


//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-TYPEDEF--------------------------------------------------------------------//
typedef uint32_t 	fixed_point_t;
typedef double	 	matrix[3][3];
typedef	double		vector[3];


//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-DECLARATIONS---------------------------------------------------------------//
inline double fixed_to_float(fixed_point_t input);
inline fixed_point_t float_to_fixed(double input);
void createSplinesExp(struct spline_tuple_t* splines, uint32_t num, uint32_t width, uint32_t start);
void polysolve(vector x, vector y);
uint32_t determinant_3(matrix m);
uint32_t determinant_2(matrix m);
void cofactor_3(matrix m);
void adjugate(matrix m);
void matrix_divide(matrix m, uint32_t divisor);
void matrix_mult(matrix m, vector x, vector y);


//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-STRUCTS--------------------------------------------------------------------//
struct spline_tuple_t{
	uint32_t range_start;
	uint32_t range_width;
	uint32_t cubic_coeff;
	uint32_t square_coeff;
	uint32_t linear_coeff;
};

struct spline_domain_t{
	uint32_t low;
	uint32_t mid;
	uint32_t high;
};

struct spline_range_t{
	fixed_point_t lowpoint;
	fixed_point_t midpoint;
	fixed_point_t highpoint;
};


//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//-FUNCTIONS------------------------------------------------------------------//
inline double fixed_to_float(fixed_point_t input){
	return ((double)input / (double)(1 << FIXED_POINT_FRACTIONAL_BITS));
}

inline fixed_point_t float_to_fixed(double input){
	return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));
}

void createSplinesExp(struct spline_tuple_t* splines, uint32_t num, uint32_t width, uint32_t start){

	for(int i = 0; i < num; i++){
		
		vector x;		
		vector y;
		vector coeffs;

		struct spline_tuple_t q;
		x[0] = (start + i * width);
		x[1] = (start + i * width + width / 2);
		x[2] = (start + i * width + width -1);

/*		y[0] = float_to_fixed(exp(x[0]));
		y[1] = float_to_fixed(exp(x[1]));
		y[2] = float_to_fixed(exp(x[2]));
*/
		y[0] = (exp(x[0]));
		y[1] = (exp(x[1]));
		y[2] = (exp(x[2]));

		polysolve(x,y);

		q.range_start = x[0];
		q.range_width = width;
		q.cubic_coeff = y[0];
		q.square_coeff = y[1];
		q.linear_coeff = y[2];

		splines[i] = q;
	}
}

void polysolve(vector x, vector y){

	uint32_t det;
	matrix poly;
	vector coeffs;

	poly[0][0] = *x[0] * *x[0];	poly[0][1] = *x[0];	poly[0][2] = 1;
	poly[1][0] = *x[1] * *x[1];	poly[1][1] = *x[1];	poly[1][2] = 1;
	poly[2][0] = *x[2] * *x[2];	poly[2][1] = *x[2];	poly[2][2] = 1;

	det = determinant_3(poly);
	cofactor_3(&poly);
	adjugate(&poly);
	matrix_divide(&poly,det);

	matrix_mult(poly, y, &x);

	return;
}

uint32_t determinant_3(matrix m){
	uint32_t determinant;
	determinant =	m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]);
	determinant -=	m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]);
	determinant +=	m[0][2]*(m[1][0]*m[2][1]-m[2][2]*m[2][0]);

	return determinant;
}

uint32_t determinant_2(matrix m){
	uint32_t determinant;
	determinant = m[0][0] * m[1][1] - m[0][1] * m[1][0];
	return determinant;
}

void cofactor_3(matrix m){
	matrix cofactor;

	matrix cof00 = {{m[1][1],m[1][2]},{m[2][1], m[2][2]}};
	matrix cof01 = {{m[1][0],m[1][2]},{m[2][0], m[2][2]}};
	matrix cof02 = {{m[1][0],m[1][1]},{m[2][0], m[2][1]}};
	matrix cof10 = {{m[0][1],m[0][2]},{m[2][1], m[2][2]}};
	matrix cof11 = {{m[0][0],m[0][2]},{m[2][0], m[2][2]}};
	matrix cof12 = {{m[0][0],m[0][1]},{m[2][0], m[2][1]}};
	matrix cof20 = {{m[0][1],m[0][2]},{m[1][1], m[1][2]}};
	matrix cof21 = {{m[0][0],m[0][2]},{m[1][0], m[1][2]}};
	matrix cof22 = {{m[0][0],m[0][1]},{m[1][0], m[1][1]}};

	*m[0][0] =  determinant_2(cof00);
	*m[0][1] = -determinant_2(cof01);
	*m[0][2] =  determinant_2(cof02);
	*m[1][0] = -determinant_2(cof10);
	*m[1][1] =  determinant_2(cof11);
	*m[1][2] = -determinant_2(cof12);
	*m[2][0] =  determinant_2(cof20);
	*m[2][1] = -determinant_2(cof21);
	*m[2][2] =  determinant_2(cof22);

	return;
}

void adjugate(matrix m){

	matrix transpose;
	int i,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j  < 3; j++){
			transpose[i][j] = *m[i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j  < 3; j++){
			*m[j][i] = transpose[i][j];
		}
	}
	return;
}

void matrix_divide(matrix m, uint32_t divisor){

	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j  < 3; j++){
			m[i][j] = m[i][j] / divisor;
		}
	}
	return;
}

void matrix_mult(matrix m, vector x, vector y){

	int i;
	for(i = 0; i < 3; i++){
		y[i] = m[i][1]*x[1] + m[i][2]*x[2] + m[i][3]*x[3];
	}
	return;
}

int main(/*int argc, char* argv[]*/){

	spline_tuple_t* splines[NUM_OF_SPLINES];
	createSplinesExp(splines, SPLINE_NUM, SPLINE_WIDTH, SPLINE_START);
	return 0;
}





