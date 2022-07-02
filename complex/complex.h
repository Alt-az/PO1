#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex {
  private:
	double Real, Imag;

  public:
	Complex(double Real=0,double Imag=0){
		this->Real=Real;
		this->Imag=Imag;
		};

	float abs() { return (sqrt(pow(Real, 2) + pow(Imag, 2))); };
	float phase() {
		if (Real > 0)
			return atan(Imag / Real);
		else if (Real<0)
			return (atan(Imag / Real) + 3.14);
		else {
			return 0;
		 }
	}
	Complex& conj() {
		Imag = this->Imag * (-1);
		return *this;
	};

	Complex& operator=(const Complex& s) {
		Real = s.Real;
		Imag = s.Imag;
		return *this;
	};

	Complex operator-() const { return Complex(-Real, -Imag); };

	Complex& operator=(double co) {
		Real = co;
		Imag = 0;
		return *this;
	};

	Complex operator+(const Complex& co) const {
		Complex n;
		n.Real = this->Real + co.Real;
		n.Imag = this->Imag + co.Imag;
		return n;
	};

	Complex& operator-=(Complex co) {
		Real -= co.Real;
		Imag -= co.Imag;
		return *this;
	};

	Complex& operator/=(Complex co) {
		Real /= co.Real;
		Imag /= co.Imag;
		return *this;
	};
	friend Complex operator/(Complex a,Complex b){
		Complex n;
		n.Real = a.Real / b.Real;
		n.Imag = a.Imag / b.Imag;
		return n;
	};
	friend Complex operator-(Complex, Complex);
	friend ostream& operator<<(ostream& s, const Complex& c) {
		s << "(" << c.Real << "," << c.Imag << ")";
		return s;
	};
};

inline Complex operator-(Complex s1, Complex s2) {
	Complex n(s1);
	return n -= s2;
}

#endif /* __Complex_H__ */
