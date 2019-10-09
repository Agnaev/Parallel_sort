// Parallel_processing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

vector<int> Sort(vector<int>& list) {
	try
	{
		if (list.size() == 2 && list[0] > list[1])
		{
			int tmp = list[0];
			list[1] = list[0];
			list[0] = tmp;
			return list;
		}

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

void Run() {
	vector<int> first_half, second_half, list = { 2, 4, 1, 6, 7, 4, 1, 10, 7, 6, 14, 19, 9 };

	for (auto elem : list) {
		if (elem < list[list.size() / 2]) {
			first_half.push_back(elem);
		}
		else {
			second_half.push_back(elem);
		}
	}

	thread th(Sort, ref(first_half));
	Sort(second_half);

	if (th.joinable()) {
		th.join();
	}

	list.clear();

	/*memcpy(&list, &first_half, first_half.size());
	memcpy(&list, &second_half, second_half.size());*/

	for (auto elem : first_half) {
		list.push_back(elem);
	}
	for (auto elem : second_half) {
		list.push_back(elem);
	}

	for (auto elem : list) {
		printf("%d ", elem);
	}
	printf("\n");
}

int main()
{
	Run();
	system("pause");
}
