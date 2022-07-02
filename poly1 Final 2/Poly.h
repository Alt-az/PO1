#ifndef __Poly_H__
#define __Poly_H__
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

class Poly {
  private:
	double** co;
	int de = 1;
	double p;

  public:
	Poly(double a = 0) {
		co = (double**)malloc(2 * sizeof(double*));
		co[0] = (double*)malloc(de * sizeof(double));
		co[1] = (double*)malloc(de * sizeof(double));
		co[0][0] = a;
		co[1][0] = 0;
	};
	~Poly() {
		if (co != NULL) {
			free(co[0]);
			free(co[1]);
			free(co);
		}
	};
	double operator()(double a) const {
		double d = 0;
		for (int i = 0; i < this->de; i++) {
			d += (this->co[0][i] * (pow(a, this->co[1][i])));
		}
		return d;
	};
	Poly& operator[](unsigned int c) {
		p = (double)c;
		return *this;
	};
	void so(double** co, int de) {
		int index;
		for (int i = 0; i < de - 1; i++) {
			index = i;
			for (int j = i + 1; j < de; j++)
				if (co[1][j] < co[1][index])
					index = j;
			swap(co[0][i], co[0][index]);
			swap(co[1][i], co[1][index]);
		}
	};
	Poly& operator=(double a) {
		int o=0;
		for(int i=this->de-1;i>=0;i--){
			if(p==this->co[1][i]){
				co[0][i]=a;
				co[1][i]=p;
				o=1;
				}
			}
		if (o!=1){
			de++;
			co[1] = (double*)realloc(co[1], this->de * sizeof(double));
			co[0] = (double*)realloc(co[0], this->de * sizeof(double));
			co[0][this->de - 1] = a;
			co[1][this->de - 1] = p;
			so(this->co, this->de);
		}
		return *this;
	};
	Poly& operator=(const Poly a) {
		copy(a, co, de);
		return *this;
	};
	Poly(const Poly& a) {
		de = a.de;
		co = (double**)malloc(2 * sizeof(double*));
		co[1] = (double*)malloc(de * sizeof(double));
		co[0] = (double*)malloc(de * sizeof(double));
		for (int i = 0; i < de; i++) {
			co[0][i] = a.co[0][i];
			co[1][i] = a.co[1][i];
		}
	};
	friend ostream& operator<<(ostream& s, const Poly& c) {
		if (c.de > 1) {
			s << c.co[0][c.de - 1] << " x ^ " << c.co[1][c.de - 1];
			for (int i = c.de - 2; i > 0; i--) {
				if (c.co[0][i] >= 0)
					s << " + " << c.co[0][i] << " x ^ " << c.co[1][i];
				else
					s << " - " << abs(c.co[0][i]) << " x ^ " << c.co[1][i];
			}
			if (c.co[0][0] > 0)
				s << " + " << c.co[0][0];
			else if (c.co[0][0] < 0)
				s << " - " << abs(c.co[0][0]);
		} else
			s << c.co[0][0];
		return s;
	};
	void copy(const Poly& a, double** co, int& de) {
		de = a.de;
		co[1] = (double*)realloc(co[1], de * sizeof(double));
		co[0] = (double*)realloc(co[0], de * sizeof(double));
		for (int i = 0; i < de; i++) {
			co[0][i] = a.co[0][i];
			co[1][i] = a.co[1][i];
		}
	};
	friend Poly operator+(Poly a, Poly b) {
		Poly n;
		n.copy(a, n.co, n.de);
		int doc = n.de;
		int o = 0;
		for (int i = 0; i < b.de; i++) {
			for (int j = 0; j < doc; j++) {
				if (b.co[1][i] == n.co[1][j]) {
					n.co[0][j] += b.co[0][i];
					o = 1;
				}
			}
			if (o == 0) {
				n.de++;
				n.co[1] = (double*)realloc(n.co[1], n.de * sizeof(double));
				n.co[0] = (double*)realloc(n.co[0], n.de * sizeof(double));
				n.co[0][n.de - 1] = b.co[0][i];
				n.co[1][n.de - 1] = b.co[1][i];
			}
			o = 0;
		}
		n.so(n.co, n.de);
		return n;
	};
	friend Poly operator-(Poly a, Poly b) {
		Poly n;
		n.copy(a, n.co, n.de);
		int k = 0;
		int o = 0;
		for (int i = 0; i < b.de; i++) {
			for (int j = 0; j < n.de; j++) {
				if (b.co[1][i] == n.co[1][j]) {
					n.co[0][j] -= b.co[0][i];
					k = j;
					o = 1;
				}
			}
			n.po(n, k);
			k = 0;
			n.o(n, b, o, i);
			o = 0;
		}
		n.so(n.co, n.de);
		return n;
	};
	void po(Poly& n, int k) {
		if (n.co[0][k] == 0 && n.co[1][k] != 0) {
			swap(n.co[0][k], n.co[0][n.de - 1]);
			swap(n.co[1][k], n.co[1][n.de - 1]);
			n.de--;
			n.co[0] = (double*)realloc(n.co[0], n.de * sizeof(double));
			n.co[1] = (double*)realloc(n.co[1], n.de * sizeof(double));
			n.so(n.co, n.de);
		}
	}
	void o(Poly& n, Poly& b, int o, int i) {
		if (o == 0) {
			n.de++;
			n.co[1] = (double*)realloc(n.co[1], n.de * sizeof(double));
			n.co[0] = (double*)realloc(n.co[0], n.de * sizeof(double));
			n.co[0][n.de - 1] = (-1) * b.co[0][i];
			n.co[1][n.de - 1] = b.co[1][i];
		}
	}
	friend Poly operator*(Poly a, Poly b) {
		Poly n;
		Poly k;
		for (int i = 0; i < a.de; i++) {
			for (int j = 0; j < b.de; j++) {
				k[a.co[1][i] + b.co[1][j]] = a.co[0][i] * b.co[0][j];
				n = n + k;
				k = k - k;
			}
		}
		return n;
	};
};

#endif /* __Poly H__ */
