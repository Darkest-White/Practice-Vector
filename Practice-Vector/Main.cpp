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

	Vector(const int size)
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
		cout << endl;
	}

	int get_size()
	{
		return size;
	}

	void insert(const int data, const int pos)
	{
		if (pos > size)
		{
			cout << "Going beyond the vector" << endl;
			return;
		}

		int* temp = new int[++size];

		for (int i = 0, j = 0; i < size; i++, j++)
		{
			if (i == pos)
			{
				temp[i] = data;
				i++;
			}
			temp[i] = p[j];
		}

		delete[] p;
		p = temp;
		temp = nullptr;
	}

	void del(const int pos)
	{
		int* temp = new int[--size];

		for (int i = 0, j = 0; i < size; i++, j++)
		{
			if (i == pos)
			{
				j++;
			}
			temp[i] = p[j];
		}
		delete[] p;
		p = temp;
		temp = nullptr;
	}
};


int main()
{
	srand(time(0));

	Vector a(10);
	a.print_vector();
	a.del(5);
	a.print_vector();
}