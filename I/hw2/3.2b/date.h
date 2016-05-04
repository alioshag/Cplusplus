//definition of an operator< friend for a class date with the three private, non-static data members.
//

#ifndef DATEH
#define DATEH
#include <iostream>
using namespace std;

class date {
	int year;              //three private non-static data members (year, month, date)
        int month;
        int day;
	static const int length[];
	static const int    pre[];
public:
	enum month_type {     //indices into the length array
		january = 1,
		february,
		march,
		april,
		may,
		june,
		july,
		august,
		september,
		october,
		november,
		december
	};

	date(int month, int d, int year) {install(month, d, year);}
	date();               //initialize to the current date
	bool install(int month, int d, int year);

	int julian() const;
	void print() const;   //output the date to cout

//	bool operator==(const date& another) const {return day == another.day;}
	friend bool operator==(const date& d1, const date& d2){return d1.day==d2.day;}
	friend int  operator- (const date& d1, const date& d2){return d1.day-d2.day;}

//	friend bool operator!=(const date& d1, const date& d2){return d1.day!=d2.day;}
//	friend bool operator!=(const date& d1, const date& d2) {return !(d1 == d2);}

	date& operator+=(int count) {day += count; return *this;}
//	friend date& operator+=(date& d, int count) {d.day += count; return d;}
	date& operator-=(int count) {day -= count; return *this;}

//	const date operator+(int count) const {date d=*this; d.day+=count; return d;}
//	const date operator+(int count) const {date d = *this; return d += count;}

//	date& operator++() {++day; return *this;}                   //prefix
//	date& operator++() {return *this += 1;}                     //prefix

//	const date operator++(int) {                                //postfix
//		const date old = *this;
//		++day;
//		return old;
//	}

//	const date operator++(int) {                                //postfix
//		const date old = *this;
//		++*this;     //(*this).operator++();
//		return old;
//	}

	const date operator-() {date d = *this; d.day=-d.day; return d;} //unary

	operator int() const {return julian();}
	operator long() const {return day;}
	operator bool() const {return abs(day) < 4000 * 365;}

	friend ostream& operator<<(ostream& ost, const date& d);
	friend istream& operator>>(istream& ost,       date& d);

        friend bool operator< (const date& d1, const date& d2) 
        {
                return d1.year<d2.year || d1.year==d2.year && 
                        (d1.month<d2.month || d1.month==d2.month && d1.day<d2.day);
        }
};

inline bool operator!=(const date& d1, const date& d2) {return !(d1 == d2);}
inline bool operator!(const date& d) {return !static_cast<bool>(d);}//call l. 64

inline const date operator+(date d, int count) {return d += count;}
inline const date operator+(int count, date d) {return d += count;}
inline const date operator-(date d, int count) {return d -= count;}

inline date& operator++(date& d) {return d += 1;}               //prefix

inline const date operator++(date& d, int)                      //postfix
{
	const date old = d;
	++d;     //d.operator++();
	return old;
}

inline date::month_type& operator++(date::month_type& m)        //prefix
{
	if (m == date::december) {
		m = date::january;
	} else {
		m = static_cast<date::month_type>(m + 1);
	}
	return m;
}

inline const date::month_type operator++(date::month_type& m, int) //postfix
{
	const date::month_type old = m;
	++m;     //operator++(m);
	return old;
}
#endif
