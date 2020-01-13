#include"PNode.cpp"

class Poly{
private:
	PNode *exp;
	void Insert(int a, int b);

public:
    Poly();
	Poly(const char *str);
	Poly(const Poly &src);	

	int getCoef(const char *&str);
	int getExpn(const char *&str);
	double Calculate(double x);

	bool operator == (const Poly &a) const;
	void operator = (const Poly &a);
	Poly operator + (const Poly &a);
	Poly operator - (const Poly &a);
	Poly operator * (const Poly &a);
	Poly operator / (const Poly &a);

	void Display();
	void Clear();
	~Poly();
};

