pair<double,double> affine2D(double t,double x,double y,double a=0,double b=0){
	double X=cos(t)*(x-a)-sin(t)*(y-b)+a;
	double Y=sin(t)*(x-a)+cos(t)*(y-b)+b;
	return {X,Y};
}
