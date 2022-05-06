#include <iostream>
#include <cmath>

class Complex{
public:
    void Cin();
    Complex sum(Complex n);
    void Cout();
    double modul();
    Complex ym(Complex n);
    Complex del(Complex n);
private:
    double im, re;
};
class Vector{
public:
    void Cin();
    Vector sum(Vector n);
    void Cout();
    double lenght();
    double scalar(Vector q);
private:
    double x, y, z;
};


void Complex::Cin(){
    std::cout << "Введите комплексное число :";
    double a, b;
    std::cin >> a >> b;
    this->re = a;
    this->im = b;

}

Complex Complex::sum(Complex n){
    Complex z;
    z.re = this->re + n.re;
    z.im = this->im + n.im;
    return z;
}

void Complex::Cout(){
    std::cout << this->re << " " << this->im <<"i " <<std::endl;;
}

double Complex::modul(){
    return sqrt(pow(this->im, 2) + pow(this->re, 2));
}

Complex Complex::ym(Complex n){
    Complex z;
    z.re = this->im * n.re + this->re * n.im;
    z.im = (this->im * n.im) * (-1) + this->re * n.re;
    return z;
}

Complex Complex::del(Complex n){
    Complex z;
    z.re = (this->im * n.re + this->re * (-1) * n.im) / (pow(n.re, 2) + pow(n.im, 2));
    z.im = ((this->im * n.im) * (-1) + this->re * n.re) / (pow(n.re, 2) + pow(n.im, 2));
    return z;
}

void Vector::Cin(){
    int x1, y1, z1;
    std::cout << "Введите координаты x y z:";
    std::cin >> x1 >> y1 >> z1;
    this->x = x1;
    this->y = y1;
    this->z = z1;
}

Vector Vector::sum(Vector n){
    Vector q;
    q.x = this->x + n.x;
    q.y = this->y + n.y;
    q.z = this->z + n.z;
    return q;
}

void Vector::Cout(){
    std::cout << "{" << this->x << ',' << this->y << ',' << this->z << '}' << std::endl;
}

double Vector::lenght(){

    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

double Vector::scalar(Vector q){
    double grad;
    std::cout << "Введите градиент:";
    std::cin >> grad;
    grad = grad * (3.14 / 180);
    return this->lenght() * q.lenght() * cos(grad);
}

int main(){
    Complex a, b, c, s, x; double q, w, e;
    Vector a1, b1, c1;
    a.Cin();
    b.Cin();
    c = a.sum(b);
    q = a.modul();
    s = a.ym(b);
    x = a.del(b);
    c.Cout();
    s.Cout();
    x.Cout();
    std::cout << q << std::endl;
    a1.Cin();
    b1.Cin();
    c1 = a1.sum(b1);
    w = a1.lenght();
    e = a1.scalar(b1);
    c1.Cout();
    std::cout << w << ' ' << e;
}