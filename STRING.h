#pragma once
class Mystring
{
private:
	int size;
	char* vs;
public:
	Mystring();
	Mystring(char);
	Mystring(const char*);
	Mystring(int,char);
	Mystring(int);
	Mystring(const Mystring&);
	void replace(int ,char);
	int len()const;
	int Atoi()const;
	Mystring Itoa(int num);
	void trim();
	char operator [](int)const;
	char& operator[](int i);
	bool operator==(const Mystring &b)const;
	bool operator<(const Mystring& b)const;
	bool operator>(const Mystring& b)const;
	bool operator<=(const Mystring& b)const;
	bool operator>=(const Mystring& b)const;
	bool operator!=(const Mystring& b)const;
	Mystring operator+(const Mystring& s2)const;
	Mystring& operator+=(const Mystring& s2);
	Mystring* split(char, int&)const;
	Mystring* tokenize(const char* delim, int& count) const;
	void remove_at(int); 
	void insert_at(int, char);
	void insert_at(int, const Mystring);
	//..........................
	
    int find_first(char ch) const;
	int find_last(char ch ) const;
	int* find_all(char ch, int& count) const;
	int find_first(const Mystring & substr) const;
	int find_last(const Mystring& substr) const;
	int* find_all(const Mystring & substr, int& count) const;

	//..........................
	void remove_first(char ch);
	void remove_last(char ch);
    void remove_all(char ch);
	//..........................
	void print()const;
	void clear();
    ~Mystring();
};