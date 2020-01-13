#include "Polynomial.h"

Polynomial::Polynomial() {
}

Polynomial::Polynomial(const vector<Node> &a) {
	for(int i = 0; i < a.size(); ++i)
		entry.push_back(a[i]);
}

Polynomial::Polynomial(const Polynomial &a) {
	for(int i = 0; i < a.entry.size(); ++i)
		entry.push_back(a.entry[i]);
}

void Polynomial::entry_sort() {
	for(int i = 0; i < entry.size(); ++i) {
		for(int j = i + 1; j < entry.size(); ++j)
			if(entry[i].get_index() > entry[j].get_index())
				swap(entry[i], entry[j]);
	}
}

bool Polynomial::operator == (Polynomial a) {
	if(a.entry.size() != entry.size())
		return false;
		
	this->entry_sort();
	a.entry_sort();
	for(int i = 0; i < a.entry.size(); ++i)
		if(a.entry[i].get_coef() != entry[i].get_coef() || a.entry[i].get_index() != entry[i].get_index())
			return false;
	return true;
}

//不直接clear()然后赋值的原因: a = a, 自己赋值自己 
void Polynomial::operator = (const Polynomial &a) {
	vector<Node> temp;
	for(int i = 0; i < a.entry.size(); ++i)
		temp.push_back(a.entry[i]);
	
	entry.clear();
	for(int i = 0; i < temp.size(); ++i)
		entry.push_back(temp[i]);
}

Polynomial Polynomial::operator + (Polynomial a) {
	Polynomial result;
	
	this->entry_sort();
	a.entry_sort();
	
	int c1 = 0, c2 = 0;
	cout << entry.size() << "  11111111" << endl;
	cout << a.entry.size() << "  2222222" << endl;
	Node add;
	while(c1 < entry.size() && c2 < a.entry.size()) {
		if(entry[c1].get_index() == a.entry[c2].get_index()) {
			add.set_index(entry[c1].get_index());
			add.set_coef(entry[c1].get_coef() + a.entry[c2].get_coef());
			c1++;
			c2++;
		} else if(entry[c1].get_index() < a.entry[c2].get_index()) {
			add.set_index(entry[c1].get_index());
			add.set_coef(entry[c1].get_coef());
			c1++;
		} else {
			add.set_index(a.entry[c2].get_index());
			add.set_coef(a.entry[c2].get_coef());
			c2++;
		}
		if(add.get_coef() != 0)
			result.entry.push_back(add);
	}
	
	while(c1 < entry.size()) {
		add.set_index(entry[c1].get_index());
		add.set_coef(entry[c1].get_coef());
		if(add.get_coef() != 0)
			result.entry.push_back(add);
		c1++;
	}
	
	while(c2 < a.entry.size()) {
		add.set_index(a.entry[c2].get_index());
		add.set_coef(a.entry[c2].get_coef());
		if(add.get_coef() != 0)
			result.entry.push_back(add);
		c2++;
	}
	return result;
}

Polynomial Polynomial::operator - (Polynomial a) {
	Polynomial result;
	
	this->entry_sort();
	a.entry_sort();
	
	int c1 = 0, c2 = 0;
	Node add;
	while(c1 < entry.size() && c2 < a.entry.size()) {
		if(entry[c1].get_index() == a.entry[c2].get_index()) {
			add.set_index(entry[c1].get_index());
			add.set_coef(entry[c1].get_coef() - a.entry[c2].get_coef());
			c1++;
			c2++;
		} else if(entry[c1].get_index() < a.entry[c2].get_index()) {
			add.set_index(entry[c1].get_index());
			add.set_coef(entry[c1].get_coef());
			c1++;
		} else {
			add.set_index(a.entry[c2].get_index());
			add.set_coef(-a.entry[c2].get_coef());
			c2++;
		}
		if(add.get_coef() != 0)
			result.entry.push_back(add);
	}
	
	while(c1 < entry.size()) {
		add.set_index(entry[c1].get_index());
		add.set_coef(entry[c1].get_coef());
		if(add.get_coef() != 0)
			result.entry.push_back(add);
		c1++;
	}
	
	while(c2 < a.entry.size()) {
		add.set_index(a.entry[c2].get_index());
		add.set_coef(-a.entry[c2].get_coef());
		if(add.get_coef() != 0)
			result.entry.push_back(add);
		c2++;
	}
	return result;
}

void Polynomial::show() {
	for(int i = 0; i < entry.size(); ++i) {
		cout << i << "  系数为： " << entry[i].get_coef() << "  指数为：  " << entry[i].get_index() << endl;
	}
	
	for(int i = 0; i < entry.size(); ++i) {
		//系数
		if(entry[i].get_coef() == 0)
			continue;
		if(entry[i].get_coef() == -1)
			cout << "-";
        else if(i != 0 && entry[i].get_coef() == 1)
            cout << "+";
		else if(entry[i].get_coef() != 1) {
			if(i == 0)
				cout << *noshowpos << entry[i].get_coef();
			else
				cout << showpos << entry[i].get_coef();
		}

		//指数
		if(entry[i].get_index() != 0) {
			cout << "x";
			if(entry[i].get_index() != 1) {
				cout << "^";
				if(entry[i].get_index() < 0)
					cout << "(" << entry[i].get_index() << ")";
				else if(entry[i].get_index() > 0)
					cout << *noshowpos << entry[i].get_index();
			}
		}
	}
	cout << endl;
}
