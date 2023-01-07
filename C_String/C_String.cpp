#include<iostream>
using namespace std;

class String
{
private:
	char* str;
	int length;


public:

	String()
	{
		str = nullptr;
		length = 0;
	}

	
	String(const char* str)
	{

		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';

	}
	~String()
	{
		delete[] this->str;
	}

	String(const String& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	String& operator =(const String& other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;

	}

	String operator+(const String& other)
	{
		
		String new_str;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		new_str.length = thisLength + otherLength;

		new_str.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			new_str.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			new_str.str[i] = other.str[j];
		}

		new_str.str[thisLength + otherLength] = '\0';

		return new_str;
	}

	void Print()
	{
		cout << str;
	}

	int Length()
	{
		return length;
	}

	bool operator ==(const String& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator !=(const String& other)
	{
		return !(this->operator==(other));
	}

	char& operator [](int index)
	{
		return this->str[index];
	}

	String(String&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
};

int main()
{
	String str1("Hello ");
	String str2("World");

	String result;
	result = str1 + str2;

	result.Print();
	cout << endl;
}