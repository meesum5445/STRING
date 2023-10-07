#include<iostream>
#include"bscs22048_lab3.h"
using namespace std;
Mystring::Mystring()
{
	this->size = 0;
	this->vs = nullptr;
}
Mystring::Mystring(char a)
{
	this->size = 1;
	this->vs = new char[2];
	this->vs[0] = a;
	this->vs[1] = '\0';
}
Mystring::Mystring(const char* a)
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	this->size = i;
	this->vs = new char[this->size +1];
	for (int i = 0; i < this->size; i++)
	{
		this->vs[i] = a[i];
	}
	this->vs[this->size] = '\0';
	
}
Mystring::Mystring(int size,char a)
{
	this->size = size;
	this->vs = new char[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		this->vs[i] = a;
	}
	this->vs[this->size] = '\0';
}
Mystring::Mystring(int num)
{
	int size = 0;
	int temp = num;
	while (temp != 0)
	{
		temp /= 10;
		size++;
	}
	this->size = size;
	this->vs = new char[this->size + 1];
	for (int i = this->size - 1; i >= 0; i--)
	{
		this->vs[i] = num%10+48;
		num /= 10;
	}
	this->vs[this->size] = '\0';
}
//Mystring::Mystring(const Mystring& a)
//{											//shallow copy
//	this->size = a.size;					// if copied is altered then original will be chamnged.
//	this->vs = a.vs;
//}
Mystring::Mystring(const Mystring & a)
{											
	this->size = a.size;					
	this->vs = new char[this->size+1];
	for (int i = 0; i < this -> size + 1; i++)
	{
		this->vs[i] = a.vs[i];
	}

}

void Mystring::replace(int ind,char a)
{
	this->vs[ind] = a;
}
void Mystring::print()const
{
	int i = 0;
	while(this->vs[i]!='\0')
	{
		cout << this->vs[i];
		i++;
	}
}
int Mystring::len()const
{
	return this->size;
}
int Mystring::Atoi()const
{
	int num=0;
	int i = 0;
	while (this->vs[i] != '\0')
	{
		num *= 10;
		num += this->vs[i]-48;
		i++;
	}
	return num;
}
Mystring Mystring::Itoa(int num)
{
	Mystring temp(num);
	this->size=temp.size;
	this->vs=temp.vs;
	temp.vs=nullptr;
	return *this;
}
void Mystring::trim()
{
	//........................
	int count = 0;
	int bs = 0;
	while (this->vs[count] == ' ')
	{
		count++;
		bs++;
	}
	//...................
	int f = this->size-1;
	while (this->vs[f]  == ' ')
	{
		f--;
		count++;
	}
	//...................
	this->size -= count;
	char* temp = new char[this->size+1];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->vs[i+bs];
	}
	delete[]this->vs;
	this->vs = temp;
	this->vs[this->size] = '\0';
}
char Mystring::operator [](int ind)const
{
	return this->vs[ind];
}
char& Mystring::operator [](int ind)
{
	return this->vs[ind];
}
bool Mystring::operator==(const Mystring& b)const
{
	if (this->size != b.size)
		return false;
	int i = 0;
	while (this->vs[i] != '\0')
	{
		if (this->vs[i] != b.vs[i])
			return false;
		i++;
	}
	return true;
}
bool Mystring::operator<(const Mystring& b)const
{
	int ind = 0;
	for(int i=0;i<=this->size;i++)
	{
		if (this->vs[i] < b.vs[i])
			return true;
	    if(this->vs[i]>b.vs[i])
	        return false;
	}
	return false;
}
bool Mystring::operator>(const Mystring& b)const
{
	return b < *this;
}
bool Mystring::operator<=(const Mystring& b)const
{
	return (*this < b) || (*this==b);
}
bool Mystring::operator>=(const Mystring& b)const
{
	return (*this > b) || (*this == b);
}
bool Mystring::operator!=(const Mystring& b)const
{
	return !(*this == b);
}
Mystring Mystring::operator+(const Mystring& s2)const
{
    Mystring temp;  
    temp.size=this->size+s2.size;
    temp.vs=new char[temp.size+1];
    temp.vs[temp.size]='\0';
    int ind=0;
    for(int i=0;i<this->size;i++)
    {
        temp.vs[ind]=this->vs[i];
        ind++;
    }
    for(int i=0;i<s2.size;i++)
    {
        temp.vs[ind]=s2.vs[i];
        ind++;
    }
    return temp;
}
Mystring& Mystring::operator+=(const Mystring&s2)
{
    for(int i=0;i<s2.size;i++)
        this->insert_at(this->size,s2.vs[i]);
    return *this;
}
void Mystring::remove_at(int ind)
{
    char *t=new char[this->size];
    t[this->size-1]='\0';
    
    for(int i=0,j=0;i<this->size;i++,j++)
    {
        if(i==ind)i++;
        t[j]=this->vs[i];
    }
    delete []this->vs;
    this->vs=t;
    this->size-=1;
    
}
void Mystring::insert_at(int ind, char ch)
{
    char *t=new char[this->size+2];
    t[ind]=ch;
    t[this->size+1]='\0';

    for(int i=0,j=0;i<this->size;i++,j++)
    {
        if(i==ind) 
            j++;
        t[j]=this->vs[i];
        
    }
    delete []this->vs;
    this->vs=t;
    this->size+=1;
}
void Mystring::insert_at(int ind, const Mystring sub)
{
    for(int i=0;i<sub.size;i++)
    {
        this->insert_at(ind+i,sub[i]);
    }
}
Mystring* Mystring::split(char a, int &count)const
{
	Mystring* temp=nullptr;
	//................
	count = 0;
	int i = 0;
	while(this->vs[i]==a)i++;
	
	while (this->vs[i] != '\0')
	{
		if (this->vs[i] == a &&this->vs[i]!= this->vs[i-1])
			count++;
		i++;
	}
	count++;
	if(this->vs[this->size-1]==a)
	    count--;
	//................
	temp=new Mystring[count];
	//................
	i=0;
	int j=0;
	while(this->vs[i]==a)i++;
    Mystring t;
	while (j!=count)
	{
		if ((this->vs[i] == a && this->vs[i-1] != a) || this->vs[i]=='\0')
		{
		    temp[j]=t;
		    j++;
		    t.size=0;
		    t.vs=nullptr;
		}
		else if(this->vs[i] != a)
		{
		    t.insert_at(t.size,this->vs[i]);
		}
		i++;
	}
	return temp;
}
Mystring* Mystring::tokenize(const char* delim, int& count) const
{
    Mystring* temp=nullptr;
	//................
	count = 0;
	int i = 0;
	while(this->vs[i]!='\0')
	{
	    int j=0;
	    bool check=false;
	     while(delim[j]!='\0')
	    {
	        if (this->vs[i] == delim[j] &&this->vs[i]!= this->vs[i-1])
	        {
	            check=true;
	        }
	        j++;
	    }
	    if(check)
	        i++;
	    else
	        break;
	}
	while (this->vs[i] != '\0')
	{
	    int j=0;
	    bool check=false;
	    while(delim[j]!='\0')
	    {
	        if (this->vs[i] == delim[j] &&this->vs[i]!= this->vs[i-1])
	        {
	            check=true;
	            break;
	        }
	        j++;
	    }
		if (check)
			count++;
		i++;
	}
	count++;
	i=0;
	while(delim[i])
	{
	    if(this->vs[size-1]==delim[i])
	        {
	            count--;
	            break;
	        }
	    i++;
	}
	//............
	temp=new Mystring[count];
	//............
	int j=0;
	i = 0;
	while(this->vs[i]!='\0')
	{
	    int j=0;
	    bool check=false;
	     while(delim[j]!='\0')
	    {
	        if (this->vs[i] == delim[j])
	        {
	            check=true;
	        }
	        j++;
	    }
	    if(check)
	        i++;
	    else
	        break;
	}
    Mystring t;
    j=0;
	while (j!=count)
	{
	    int k=0;
	    bool check=false;
	    while(delim[k]!='\0')
	    {
	        if ((this->vs[i] == delim[k] && this->vs[i-1] != this->vs[i]) || this->vs[i]=='\0')
    		{
    		    check=true;
    		}
    		
	        k++;   
	    }
	    if(check)
	    {
	        temp[j]=t;
    		j++;
            t.size=0;
     	    t.vs=nullptr;
	    }
	    else if(!check)
    	{
    		t.insert_at(t.size,this->vs[i]);
    	}
		i++;
	}
	return temp;
}
int Mystring::find_first(char ch) const
{
    int i=0;
    while(this->vs[i]!=ch)i++;
    return i;
}
int Mystring::find_last(char ch) const
{
    int i=this->size-1;
    while(this->vs[i]!=ch)
    {
        i--;
    }
    return i;
}
int* Mystring::find_all(char ch,int &count) const
{
    count=0;
    int i=0;
    while(this->vs[i]!='\0')
    {
        if(this->vs[i]==ch)
            count++;
        i++;
    }
    int *temp=new int[count];
    i=0;
    int j=0;
    while(this->vs[i]!='\0')
    {
        if(this->vs[i]==ch)
        {
            temp[j]=i;
            j++;
        }
        i++;
    }
    return temp;
}
int Mystring::find_first(const Mystring & substr) const
{
    int i=0;
    while(this->vs[i]!='\0')
    {
        int c=i,j=0;
        while(this->vs[c]==substr.vs[j]&& substr.vs[j]!='\0') j++,c++;
        if(j==substr.size)
            return i;
        i++;
    }
    return -1;
}
int Mystring::find_last(const Mystring & substr) const
{
    int index=-1;
    int i=0;
    while(this->vs[i]!='\0')
    {
        int c=i,j=0;
        while(this->vs[c]==substr.vs[j] && substr.vs[j]!='\0') j++,c++;
        if(j==substr.size)
            index=i;
        i++;
    }
    return index;
}
int* Mystring::find_all(const Mystring & substr, int& count) const
{
    count=0;
    int i=0;
    while(this->vs[i]!='\0')
    {
        int c=i,j=0;
        while(this->vs[c]==substr.vs[j] && substr.vs[j]!='\0') j++,c++;
        if(j==substr.size)
            count++;
        i++;
    }
    //....................
    int *temp=new int[count];
    //....................
    i=0;
    int ind=0;
    while(this->vs[i]!='\0')
    {
        int c=i,j=0;
        while(this->vs[c]==substr.vs[j] && substr.vs[j]!='\0') j++,c++;
        if(j==substr.size)
        {
            temp[ind]=i;
            ind++;
        }
            
        i++;
    }
    return temp;
}
void Mystring::remove_first(char ch)
{
    this->remove_at(this->find_first(ch));
}
void Mystring::remove_last(char ch)
{
    this->remove_at(this->find_last(ch));
}
void Mystring::remove_all(char ch)
{
    int count=0;
    int *t=this->find_all(ch,count);
    for(int i=0;i<count;i++)
        this->remove_at(t[i]-i);
}
void Mystring::clear()
{
    this->size=0;
    delete[]this->vs;
    this->vs=nullptr;
}
Mystring::~Mystring()
{
    delete[]this->vs;
}