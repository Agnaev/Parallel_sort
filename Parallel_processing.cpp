// Parallel_processing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;


class Sorting {
public:
	Sorting()
	{

	}
	~Sorting() {

	}
	static vector<int> Sort(vector<int>& list) {
		try
		{
			if (list.size() == 2 && list[0] > list[1])
				return swap(list, 0, 1);

			if (list.size() == 2 || list.size() == 1 || list.size() == 0)
				return list;

			int middle = list.size() / 2;
			int pivot = list[middle];
			vector<int> firstHalf, secondHalf;
			for (int i = 0; i < list.size(); i++)
			{
				if (i != list.size() / 2)
				{
					if (list[i] < pivot)
					{
						firstHalf.push_back(list[i]);
					}
					else if (list[i] >= pivot)
					{
						secondHalf.push_back(list[i]);
					}
				}
			}

			Sort(firstHalf);
			Sort(secondHalf);

			list.clear();

			for (auto& elem : firstHalf) {
				list.push_back(elem);
			}
			list.push_back(pivot);
			for (auto& elem : secondHalf) {
				list.push_back(elem);
			}
			return list;
		}
		catch (...) {
			cout << "Error while sorting." << endl;
		}
	}
private:
	static vector<int> swap(vector<int> mas, int i, int j) {
		int tmp = mas[0];
		mas[1] = mas[0];
		mas[0] = tmp;
		return mas;
	}

};

int main()
{
	vector<int> list = {2, 4, 1, 6, 7, 4, 1, 10, 7, 6, 14, 19, 9};
	/*list = Sort<int>(list);
	for (int i : list) {
		printf("%d ", i);
	}*/
	Sorting* sortPtr = new Sorting();
	std::thread th(&Sorting::Sort, sortPtr, list);
	th.join();
	system("pause");
}
