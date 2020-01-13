#include<stdlib.h>
#include<string.h>
#include "Poly.h"

//delete和"生命域"的区别;
//delete是删除了指针指向的空间(该空间不可访问)
//"生命域"结束只是该变量被删除,不再指向该空间,空间仍然保留,可被别的指针指向

void Poly::Insert(int a, int b) {
	//1.排序 2.合并 3.除零
	if(exp == NULL) {
	    //此时temp为局部变量, Insert函数结束后会自动delete
//		PNode temp(a, b);
//		exp = &temp;
        exp = new PNode(a, b);
	} else {
		//合并
		int is_combine = 0;
		PNode *temp = exp;
		PNode *last = temp;
		while(temp != NULL) {
			if(temp->expn == b) {
                is_combine = 1;
				temp->coef += a;
				//系数除零
				if(temp->coef == 0) {
					if(temp == exp) {
						exp = exp->next;
						delete temp;
					} else {
						temp = temp->next;
						last->next = temp;
					}
				}
				break;      //一项一项添加,最多只可能有一个同类项,找到则break
			}
			last = temp;
			temp = temp->next;
		}

		//排序--指数从小到大(没有合并才要排序)
		if(is_combine == 0) {
            temp = exp;
            PNode *last;
            PNode *add = new PNode(a, b);
            while(temp != NULL && b > temp->expn) {
                last = temp;
                temp = temp->next;
            }

            if(temp == exp) {
                add->next = temp;
                exp = add;
            } else {
                last->next = add;
                add->next = temp;
            }
        }
	}	
}

Poly::Poly() {
	exp = NULL;
}

Poly::Poly(const char *str) {
	exp = NULL;
	while((*str) != 0) {
		cout << "asd" << endl;
		int coef = getCoef(str);
		cout << "coef  " << coef << endl;
		int expn = getExpn(str);
		cout << "expn  " << expn << endl;
		if(coef != 0)
            Insert(coef, expn);
	}
}

Poly::Poly(const Poly &src) {
	//偷懒版拷贝构造函数，删除 text2 后 text1 也会被删除 
	exp = src.exp;
}

int Poly::getCoef(const char *&str) {
	const char *pt;
	char data[8];	//最多存放8位数
	pt = str;
	if(*str == '-' || *str == '+')
		str++;
	while('0' <= *str && *str <= '9')
		str++;
	
	int k = str - pt;
	if(k == 0) {	//无系数则为1,为第一项无系数作准备
		k = 1;
		return k;
	} else if (k == 1 && (*pt == '+' || *pt == '-')) {
		k = (*pt == '+' ? 1 : -1);
		return k;
	} else {
		strncpy(data, pt, k);
		data[k] = 0;
		return atoi(data);
	}
}

int Poly::getExpn(const char *&str) {
	const char *pt;
	char data[8];	//最多存8位数
	if(*str != 'x' && *str != 'X')
		return 0;
	str++;
	
	if(*str != '^')		//x的1次方
		return 1;
		
	pt = ++str;
	while('0' <= *str && *str <= '9')
		str++;
	int k = str - pt;
	strncpy(data, pt, k);
	data[k] = 0;
	return atoi(data);
}

double Poly::Calculate(double x) {
	double result = 0;
	PNode *temp = exp;
	while(temp != NULL) {
		double value1 = temp->coef;
		for(int i = 0; i < temp->expn; ++i)
			value1 *= x;
		result += value1;
		temp = temp->next;
	}
	return result;
}

bool Poly::operator == (const Poly &a) const {
	PNode *t1 = exp;
	PNode *t2 = a.exp;
	while(t1 != NULL && t2 != NULL) {
		if(t1->coef != t2->coef || t1->expn != t2->expn)
			return false;
		t1 = t1->next;
		t2 = t2->next;
	}
	if(t1 != NULL || t2 != NULL)
		return false;
	return true;
}

//为什么不直接clear然后赋值?   a = a
void Poly::operator = (const Poly &a) {
	PNode *head, *tail;
    PNode *new_head;
    PNode *t1 = a.exp;
    while(t1 != NULL) {
        if(t1 == a.exp) {
            head = new PNode(t1->coef, t1->expn);
            new_head = head;
        } else {
            tail = new PNode(t1->coef, t1->expn);
            head->next = tail;
            head = tail;
        }
        t1 = t1->next;
    }

    this->Clear();
    exp = new_head;
}

Poly Poly::operator + (const Poly &a) {
	Poly result;

    PNode *t1 = exp;
    PNode *t2 = a.exp;
    while(t1 != NULL && t2 != NULL)
    {
        if(t1->expn == t2->expn) {
            if(t1->coef + t2->coef != 0)
                result.Insert(t1->coef + t2->coef, t1->expn);
            t1 = t1->next;
            t2 = t2->next;
        } else if(t1->expn < t2->expn) {
            result.Insert(t1->coef, t1->expn);
            t1 = t1->next;
        } else {
            result.Insert(t2->coef, t2->expn);
            t2 = t2->next;
        }
    }

    while(t1 != NULL) {
        result.Insert(t1->coef, t1->expn);
        t1 = t1->next;
    }
    while(t2 != NULL) {
        result.Insert(t2->coef, t2->expn);
        t2 = t2->next;
    }

    return result;
}

Poly Poly::operator - (const Poly &a) {
	Poly result;

    PNode *t1 = exp;
    PNode *t2 = a.exp;
    while(t1 != NULL && t2 != NULL)
    {
        if(t1->expn == t2->expn) {
            if(t1->coef - t2->coef != 0)
                result.Insert(t1->coef - t2->coef, t1->expn);
            t1 = t1->next;
            t2 = t2->next;
        } else if(t1->expn < t2->expn) {
            result.Insert(t1->coef, t1->expn);
            t1 = t1->next;
        } else {
            result.Insert(-t2->coef, t2->expn);
            t2 = t2->next;
        }
    }

    while(t1 != NULL) {
        result.Insert(t1->coef, t1->expn);
        t1 = t1->next;
    }
    while(t2 != NULL) {
        result.Insert(-t2->coef, t2->expn);
        t2 = t2->next;
    }

    return result;
}

Poly Poly::operator * (const Poly &a) {
	Poly result;
    PNode *t1 = exp;
    while(t1 != NULL)
    {
    	PNode *t2 = a.exp;
        while(t2 != NULL) {
        	result.Insert(t1->coef * t2->coef, t1->expn + t2->expn);
			t2 = t2->next;
		}
		t1 = t1->next;
    }
    return result;
}

Poly Poly::operator / (const Poly &a) {
	Poly result;
    PNode *t1 = exp;
    while(t1 != NULL)
    {
    	PNode *t2 = a.exp;
        while(t2 != NULL) {
        	result.Insert(t1->coef / t2->coef, t1->expn - t2->expn);
			t2 = t2->next;
		}
		t1 = t1->next;
    }
    return result;
}

void Poly::Display() {
	PNode *temp = exp;
	while(temp != NULL) {
//	     cout << "hhhh    " << temp->coef << "  " << temp->expn << endl;
		//系数--不用考虑系数为0, Insert有除零功能
		if(temp->coef == -1)
			cout << "-";
        else if(temp != exp && temp->coef == 1)
            cout << "+";
		else if(temp->coef != 1) {
			if(temp == exp)
				cout << *noshowpos << temp->coef;
			else
				cout << showpos << temp->coef;
		}

		//指数
		if(temp->expn != 0) {
			cout << "x";
			if(temp->expn != 1) {
				cout << "^";
				if(temp->expn < 0)
					cout << "(" << temp->expn << ")";
				else if(temp->expn > 0)
					cout << *noshowpos << temp->expn;
			}
		}
		temp = temp->next;
	}
	cout << endl;
}

void Poly::Clear() {
	PNode *temp = exp;
	while(temp != NULL) {
		temp = temp->next;
		delete exp;
		exp = temp;
	}
}

Poly::~Poly() {
	Clear();
	delete exp;
} 
