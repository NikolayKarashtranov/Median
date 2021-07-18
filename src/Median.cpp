#include "Median.hpp"
#include "Tests.hpp"

template<typename T>
void MedianVector<T>::InsertSorted(T num, size_t start, size_t end)
{
	if (start >= end)
	{
		numbers.insert(numbers.begin() + end, num);
		return;
	}
	size_t middle = (start + end) / 2;
	if (num <= numbers[middle])
		InsertSorted(num, start, middle);
	else
		InsertSorted(num, middle + 1, end);
}

template<typename T>
void MedianVector<T>::CalcMedian()
{
	size_t half_size = numbers.size()/2;
	if (numbers.size() % 2 == 0)
		median = (numbers[half_size - 1] + numbers[half_size]) / 2.0;
	else
		median = numbers[half_size];
}

template<typename T>
void MedianVector<T>::Insert(T num)
{
	InsertSorted(num, 0, numbers.size());
	CalcMedian();
}

template<typename T>
double MedianVector<T>::GetMedian()
{
	return median;
}

void TestMedian_Even()
{
	MedianVector<int> m;
	m.Insert(1);
	m.Insert(10);
	m.Insert(10);
	m.Insert(10);
	m.Insert(10);
	m.Insert(4);
	m.Insert(5);
	m.Insert(3);
	m.Insert(3);
	m.Insert(3);
	double median = 4.5;
	ALEPH_ASSERT_EQUAL(median, m.GetMedian());
}

void TestMedian_Odd()
{
	MedianVector<int> m;
	m.Insert(1);
	m.Insert(10);
	m.Insert(10);
	m.Insert(10);
	m.Insert(10);
	m.Insert(4);
	m.Insert(5);
	m.Insert(3);
	m.Insert(3);
	m.Insert(3);
	m.Insert(1);
	double median = 4.0;
	ALEPH_ASSERT_EQUAL(median, m.GetMedian());
}

void TestMedian_Float()
{
	MedianVector<float> m;
	m.Insert(5.0f);
	m.Insert(3.0f);
	m.Insert(3.1f);
	double median = 3.1f;
	ALEPH_ASSERT_EQUAL(median, m.GetMedian());
	m.Insert(1.1f);
	m.Insert(6.1f);
	m.Insert(7.1f);
	median = 4.05f;
	ALEPH_ASSERT_EQUAL(median, m.GetMedian());
}

int main()
{
	TestMedian_Even();
	TestMedian_Odd();
	TestMedian_Float();
}