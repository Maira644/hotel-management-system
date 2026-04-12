// #include <iostream>
// #include <string>
// using namespace std;

// class Teacher{
//     private:
//     string name;
//     string dept;
//     string subject;
//     double salary;

//     public:
//     Teacher(string n, string d, string s, double sal){
//         name = n;
//         dept = d;
//         subject = s;
//         salary = sal;
//     }
//     string getname(){
//         return name;
//     }
//     string getdept(){
//         return dept;
//     }
// };
// int main(){
//     Teacher t1("Maira", "Software", "OOP", 25000);
//     cout<<t1.getname()<<endl;
//     cout<<t1.getdept()<<endl;

//     return 0;
// }


// #include <iostream>
// using namespace std;

// class Fraction {
// private:
//     int numerator;
//     int denominator;

// public:
//     Fraction(int n, int d) {
//         if (d == 0) {
//             cout << "Error: Denominator cannot be zero!" << endl;
//             exit(1);
//         }
//         numerator = n;
//         denominator = d;
//     }
//     int gcd(int a, int b) {
//         while (b != 0) {
//             int temp = b;
//             b = a % b;
//             a = temp;
//         }
//         return a;
//     }
//     void simplify() {
//         int divisor = gcd(numerator, denominator);
//         numerator /= divisor;
//         denominator /= divisor;
//     }
//     void showFraction() {
//         simplify();  
//         cout << "Simplified Fraction: " << numerator << "/" << denominator << endl;
//     }
// };

// int main() {
//     Fraction frac(35, 56); 

//     frac.showFraction(); 

//     return 0;
// }


