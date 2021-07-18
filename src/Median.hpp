#include <vector>
#include <iostream>

template <typename T>
class MedianVector
{
private:
	std::vector<T> numbers;
	double median;
	void InsertSorted(T num, size_t start, size_t end);
	void CalcMedian();
public:
	void Insert(T x);
	double GetMedian();
};