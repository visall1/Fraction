#include<iostream>
using namespace std;
class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int num,int den);

	operator int() const {
		return numerator;
	}
	int getNumerator() const {
		return numerator;
	}
	int getDenominator() const {
		return denominator;
	}
	double decimalValue()const {
		return static_cast<double>(numerator) / denominator;
	}

	void simplyfy();
	
private:
	int calculateGCD(int a, int b)const {
		if (b == 0) {
			return a;
		}
		return calculateGCD(b, a % b);
	}

};

Fraction::Fraction():numerator(0),denominator(1){}

Fraction::Fraction(int num, int den): numerator(num),denominator(den){}

void Fraction::simplyfy()
{
	int gdc = calculateGCD(numerator, denominator);
	numerator /= gdc;
	denominator /= gdc;
}
ostream& operator<<(ostream& os, const Fraction& f) {
	os << f.getNumerator() << "/" << f.getDenominator();
	return os;
}
int main() {
	Fraction f1;
	cout << "Fraction 1: " << f1 << endl;

	Fraction f2(8, 12);
	cout << "Fraction 2: " << f2 << endl;

	double decimalValue = f2.decimalValue();
	cout << "Decimal Value of fraction 2: " << decimalValue << endl;

	f2.simplyfy();
	cout << "Fraction 2 simplification: " <<f2 << endl;
	cout << endl;
}
