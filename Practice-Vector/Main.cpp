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


	Vector& operator=(const Vector& other)
	{
		size = other.size;

		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}

		data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}

		return *this;
	}

	bool operator==(const Vector& other)
	{
		if (size != other.size)
		{
			return false;
		}

		for (int i = 0; i < size; i++)
		{
			if (data[i] != other.data[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator!=(const Vector& other)
	{
		if (size != other.size)
		{
			return true;
		}

		for (int i = 0; i < size; i++)
		{
			if (data[i] != other.data[i])
			{
				return true;
			}
		}

		return false;
	}

	Vector operator+(const Vector& other)
	{
		Vector temp;
		temp.size = this->size;
		temp.data = new int[temp.size];

		for (int i = 0; i < temp.size; i++)
		{
			temp.data[i] = this->data[i] + other.data[i];
		}

		return temp;
	}

	Vector operator-(const Vector& other)
	{
		Vector temp;
		temp.size = this->size;
		temp.data = new int[temp.size];

		for (int i = 0; i < temp.size; i++)
		{
			temp.data[i] = this->data[i] - other.data[i];
		}

		return temp;
	}

	Vector operator*(const int scalar)
	{
		Vector temp;
		temp.size = size;
		temp.data = new int[temp.size];

		for (int i = 0; i < size; i++)
		{
			temp.data[i] = data[i] * scalar;
		}

		return temp;
	}

	Vector operator/(const int scalar)
	{
		Vector temp;
		temp.size = size;
		temp.data = new int[temp.size];

		for (int i = 0; i < size; i++)
		{
			temp.data[i] = data[i] / scalar;
		}

		return temp;
	}

	Vector& operator++()
	{
		for (int i = 0; i < size; i++)
		{
			data[i]++;
		}

		return *this;
	}

	Vector& operator++(int value)
	{
		for (int i = 0; i < size; i++)
		{
			data[i]++;
		}

		return *this;
	}

	Vector& operator--()
	{
		for (int i = 0; i < size; i++)
		{
			data[i]--;
		}

		return *this;
	}

	Vector& operator--(int value)
	{
		for (int i = 0; i < size; i++)
		{
			data[i]--;
		}

		return *this;
	}

	int& operator[](const int index)
	{
		return data[index];
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

	void push_back(const int value)
	{
		int* temp = new int[++size];

		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = data[i];
		}
		temp[size - 1] = value;

		delete[] data;
		data = temp;
		temp = nullptr;
	}

	void push_front(const int value)
	{
		int* temp = new int[++size];

		for (int i = 1; i < size; i++)
		{
			temp[i] = data[i - 1];
		}
		temp[0] = value;
				
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
	a.push_front(100);
	a.print_vector();
}