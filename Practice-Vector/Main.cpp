#include <iostream>
using namespace std;


class Vector
{
private:

	int* data;
	int size;

public:

	Vector()
	{
		data = nullptr;
		size = 0;
	}

	Vector(const int size)
	{
		this->size = size;
		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = rand() % 11;
		}
	}

	Vector(const Vector& other)
	{
		size = other.size;
		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}

	~Vector()
	{
		delete[] data;
		data = nullptr;
		size = 0;
	}


	Vector& operator=(const Vector& v)
	{
		size = v.size;

		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}

		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = v.data[i];
		}
		return *this;
	}

	bool operator==(const Vector& v)
	{
		if (size != v.size)
		{
			return false;
		}

		for (int i = 0; i < size; i++)
		{
			if (data[i] != v.data[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(const Vector& v)
	{
		if (size != v.size)
		{
			return true;
		}

		for (int i = 0; i < size; i++)
		{
			if (data[i] != v.data[i])
			{
				return true;
			}
		}

		return false;
	}

	Vector operator+(const Vector& v)
	{
		Vector tmp;
		tmp.size = this->size + v.size;
		tmp.data = new int[tmp.size];

		int it = this->size;
		for (int i = 0; i < this->size; i++)
		{
			tmp.data[i] = this->data[i];
		}

		for (int i = 0; i < v.size; i++, it++)
		{
			tmp.data[it] = v.data[i];
		}

		return tmp;
	}

	Vector& operator++()
	{
		int* tmp = new int[++size];

		for (int i = 0; i < size - 1; i++)
		{
			tmp[i] = data[i];
		}
		tmp[size - 1] = rand() % 11;

		delete[] data;
		data = tmp;
		tmp = nullptr;

		return *this;
	}

	Vector& operator++(int value)
	{
		Vector v = *this;

		int* tmp = new int[++size];
		
		for (int i = 0; i < size - 1; i++)
		{
			tmp[i] = data[i];
		}
		tmp[size - 1] = rand() % 11;

		delete[] data;
		data = tmp;
		tmp = nullptr;

		return v;
	}


	void print_vector()
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

	int get_size()
	{
		return size;
	}

	void insert(const int value, const int pos)
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
				temp[i] = value;
				i++;
			}
			temp[i] = data[j];
		}

		delete[] data;
		data = temp;
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
			temp[i] = data[j];
		}
		delete[] data;
		data = temp;
		temp = nullptr;
	}
};


int main()
{
	srand(time(0));

	Vector a(5);
	a.print_vector();
	a++;
	a.print_vector();
	a++;
	a.print_vector();
}