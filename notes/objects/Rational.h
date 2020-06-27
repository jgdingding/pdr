#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
	public:
		Rational();
		~Rational();
		Rational(int numerator, int denominator);
		void print() const;
		Rational times(Rational b) const;
		Rational plus(Rational b) const;
		Rational reciprocal() const;
		Rational divides(Rational b) const;
	private:
		int num, den;
		static int gcd(int m, int n);
};

#endif
