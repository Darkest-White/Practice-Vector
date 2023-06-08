#include <iostream>
using namespace std;


class Vector
{
private:

	int* p;
	int size;

public:

	Vector()
	{
		p = nullptr;
		size = 0;
	}

	Vector(int size)
	{
		this->size = size;
		p = new int[size];

		for (int i = 0; i < size; i++)
		{
			p[i] = rand() % 11;
		}
	}

	Vector(const Vector& other)
	{
		this->size = other.size;
		this->p = new int[this->size];

		for (int i = 0; i < this->size; i++)
		{
			this->p[i] = other.p[i];
		}
	}

	~Vector()
	{
		delete[] p;
		p = nullptr;
		size = 0;
	}


	void print_vector()
	{
		for (int i = 0; i < size; i++)
		{
			cout << p[i] << " ";
		}
	}
};


int main()
{
	srand(time(0));

	Vector a(5);
	a.print_vector();
	cout << endl;
	Vector b(a);
	b.print_vector();
}