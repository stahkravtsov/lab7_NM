#include <cmath>
#include <iostream>
#include <iomanip>
#include "lab7.h"
using namespace std;

double f1(double x, double y) {
		return y + sin(x - 1) - 1.3;
}

double f2(double x, double y) {
		return x - sin(y + 1) - 0.8;
}

double fi_x(double x, double y) {
		return 0.8 + sin(y + 1);
}

double fi_y(double x, double y) {
		return 1.3 - sin(x - 1);
}

double dfdx(int df, int dx, double x, double y) {
		if(df == 0 && dx == 0) {
				return 0;
		} else if(df == 0 && dx == 1) {
				return cos(y + 1);
		} else if(df == 1 && dx == 0) {
				return -cos(x - 1);
		} else {
				return 0;
		}
		return 0.0;
}

void Iterations(double& x0, double& y0, double eps) {
		double dSumMax = 0;
		for(int i = 0; i < 2; i++) {
				double dSumL = 0, dSumC = 0;
				for(int j = 0; j < 2; j++) {
						dSumL += abs(dfdx(i, j, x0, y0));
						dSumC += abs(dfdx(j, i, x0, y0));
				}
				if(dSumMax < dSumC) dSumMax = dSumC;
				if(dSumMax < dSumL) dSumMax = dSumL;
		}
		double xTemp, yTemp, Delta = 0;
		int i = 0;
		cout << "N  " << " X\t      " << "Y          " << "Delta" << endl;
		if(dSumMax > 1) {
				std::cout << "The iteration proces is NOT convergent" << std::endl;
				return;
		}
		do {
				xTemp = x0;
				yTemp = y0;
				x0 = fi_x(x0, y0);
				y0 = fi_y(x0, y0);

				i++;

				Delta = sqrt(( xTemp - x0 ) * ( xTemp - x0 ) +
						( yTemp - y0 ) * ( yTemp - y0 ));
				cout << i << ")  ";

				cout.precision(7);
				cout.width(8);
				cout.fill('0');
				cout << x0 << "  " << y0 << "  " << Delta << endl;

		} while(Delta > eps);
}

void Newton(double& x0, double& y0, double eps) {
		double Delta = 0, xTemp = 0, yTemp = 0;
		int i = 0;
		cout << "N  " << " X\t      " << "Y          " << "Delta" << endl;
		do {
				double Jacobean = dfdx(0, 0, x0, y0) * dfdx(1, 1, x0, y0) -
						dfdx(1, 0, x0, y0) * dfdx(0, 1, x0, y0);
				double DeltaX = -( 1 / Jacobean ) * ( f1(x0, y0) * dfdx(1, 1, x0, y0)
						- f2(x0, y0) * dfdx(0, 1, x0, y0) );
				double DeltaY = -( 1 / Jacobean ) * ( f2(x0, y0) * dfdx(0, 0, x0, y0)
						- f1(x0, y0) * dfdx(1, 0, x0, y0) );

				xTemp = x0;
				yTemp = y0;
				x0 = x0 + DeltaX;
				y0 = y0 + DeltaY;

				i++;
				Delta = 1;

				Delta = abs(DeltaX) > eps || abs(DeltaY) > eps;
				cout << i << ")  ";

				cout.precision(7);
				cout.width(8);
				cout.fill('0');
				cout << DeltaX << "  " << DeltaY << "  " << Jacobean << endl;
				//char j;
				//cin.get(j);

		} while(Delta);
}

