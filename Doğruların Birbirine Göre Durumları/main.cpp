// Doğruların Birbirine Göre Durumları.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
using namespace std;



class Coordinate
{
private:
    double first_x;
    double first_y;
    double second_x;
    double second_y;

public:
    Coordinate() = default;
    Coordinate(double x1, double y1, double x2, double y2) {
        first_x = x1;
        first_y = y1;
        second_x = x2;
        second_y = y2;
    }
    
    double slope() {
        return ((second_y - first_y) / (second_x - first_x));
    }

    void position(Coordinate& line) {
        if (line.slope() == slope()) {
            // y-y1 = m(x-x1) y = mx-mx1+y1=y
            if (((line.slope() * line.first_x) + line.first_y) == (slope() * first_x + first_y))
                cout << "Bu dogrular cakisiktir.";
            else
            cout << "Bu dogrular birbirine paraleldir.";
        }
        else if (line.slope() * slope() == -1) {
            cout << "Bu dogrular birbirine diktir.";
        }
        else if(line.slope()!=slope())
            cout << "Bu dogrular birbirini keser.";
    }
};

int main()
{

    double p[4] = {0};
    double y[4] = { 0 };
    int count = 0;
    cout << "1.dogru" << endl;
    do {
        if (count != 0)
            cout << "girdiginiz kordinatlar ayni nokta oldugundan dogru belirtmez. Tekrar giriniz:" << endl;
        cout << "1.noktanin x koordinati: ";
        cin >> p[0];
        cout << "1.noktanin y koordinati: ";
        cin >> p[1];
        cout << "2.noktanin x koordinati: ";
        cin >> p[2];
        cout << "2.noktanin y koordinati: ";
        cin >> p[3];
        count++;
    } while (p[0] == p[2] && p[1] == p[3]);

    Coordinate point1(p[0], p[1], p[2], p[3]);

    count = 0;

    cout<< "2.dogru" << endl;
    do {
        if(count!=0)
            cout << "girdiginiz kordinatlar ayni nokta oldugundan dogru belirtmez. Tekrar giriniz:" << endl;
        cout << "1.noktanin x koordinati: ";
        cin >> y[0];
        cout << "1.noktanin y koordinati: ";
        cin >> y[1];
        cout << "2.noktanin x koordinati: ";
        cin >> y[2];
        cout << "2.noktanin y koordinati: ";
        cin >> y[3];
    } while (y[0] == y[2] && y[1] == y[3]);

    Coordinate point2(y[0], y[1], y[2], y[3]);


    cout << endl;
    point1.position(point2);
}

