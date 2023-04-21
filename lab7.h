#ifndef LAB7_H
#define LAB7_h

double f1(double x, double y);

double f2(double x, double y);

double fi_x(double x, double y);

double fi_y(double x, double y);

double dfdx(int df, int dx, double x, double y);

void Iterations(double& x0, double& y0, double eps);

void Newton(double& x0, double& y0, double eps);

#endif // !LAB7_H

