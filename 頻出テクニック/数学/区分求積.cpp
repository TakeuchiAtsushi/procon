// double s, t;
// double f(double x){
//     return (x-s)*(x-t);
// }
// f(x)に求めたい面積の関数を定義 ※10^-4の誤差であればn=10^5でOK
double integral(double a, double b, double n){
    double res = 0;
    double x = a;
    double h = 1/n;
    while(x < b){
        res += abs((f(x)+f(x+h))*h/2);
        x += h;
    }
    return res;
}