#include <iostream>
#include <cmath>
using namespace std;

class Punkt {
    protected:
        double x;
        double y;
    public:
        Punkt(void);
        Punkt(double X, double Y);
        double get_x(void);
        double get_y(void);
        void set_x(double X);
        void set_y(double Y);
        double modul(void);
};

class Kolo{
    private:
        double promien;
        Punkt srodek;
    public:
        Kolo();
        Kolo(double r, double x, double y);
        Kolo(double r, Punkt p);
        double obwod();
        double pole();
        void set_r(double x);
        double get_r();
        void set_srodek(Punkt p);
        Punkt get_srodek();
};

int main(){
    double a, b;
    cout << "Podaj wspolrszedne punktu: \n";
    cin >>a>>b;
    Punkt p1(a,b);
    cout << "Punkt (" << p1.get_x()<<","<<p1.get_y()<<") ";
    cout << "jest oddalony od punktu (0,0) o " << p1.modul() << endl;

    Punkt p2;
    p2.set_x(a);
    p2.set_y(b);

    cout << "Podaj promien kola 1: ";
    double pr;
    cin >> pr;
    cout << "Podaj wspórzędne srodka kola 1: \n";
    double x, y;
    cin >> x >> y;

    Kolo k1(pr, x, y);

    cout << "Obwod kola 1 wynosi: ";
    cout << k1.obwod()<<endl;
    cout << "Pole kola 1 wynosi: ";
    cout << k1.pole()<<endl;

    cout << "Podaj promien kola 2: ";
    cin >> pr;
    cout << "Podaj wsporzedne srodka kola 2: \n";
    cin >> x >> y;
    Punkt sr(x,y);
    Kolo k2(pr, sr);

    cout << "Obwod kola 2 wynosi: ";
    cout << k2.obwod()<<endl;
    cout << "Pole kola 2 wynosi: ";
    cout << k2.pole()<<endl;
}

Punkt::Punkt(){}
Punkt::Punkt(double X, double Y){
    x = X;
    y = Y;
}
double Punkt::get_x(){
    return x;
}
double Punkt::get_y(){
    return y;
}
void Punkt::set_x(double X){
    x = X;
}
void Punkt::set_y(double Y){
    y = Y;
}
double Punkt::modul(void){
    return sqrt((pow(0-get_x(), 2))+ pow(0-get_y(), 2) );
}

double Kolo::get_r(){
    return promien;
}
void Kolo::set_r(double x){
    promien = x;
}
double Kolo::obwod(){
    return M_PI*promien;
}
double Kolo::pole(){
    return M_PI*promien*promien;
}
Kolo::Kolo(double r, double x, double y){
    promien = r;
    srodek.set_x(x);
    srodek.set_y(y);
}
Kolo::Kolo(double r, Punkt p){
    promien = r;
    srodek.set_x(p.get_x());
    srodek.set_y(p.get_y());
}
Kolo::Kolo(){}
void Kolo::set_srodek(Punkt p){
    srodek = p;
}
Punkt Kolo::get_srodek(void){
   return srodek;
}