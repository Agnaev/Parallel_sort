#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

template<class T>
void swap(std::vector<T> &list, int a, int b) {
	int tmp = list[a];
	list[a] = list[b];
	list[b] = list[a];
}

template<typename T>
void AddRange(std::vector<T> &from, std::vector<T> &to) {
	for (T& elem : from) {
		to.push_back(elem);
	}
}

void Sort(std::vector<int>& list) {
	try
	{
		if (list.size() == 2 && list[0] > list[1])
		{
			swap(list, 0, 1);
			return;
		}

		if (list.size() == 2 || list.size() == 1 || list.size() == 0) {
			return;
		}

		int middle = list.size() / 2;
		int pivot = list[middle];
		std::vector<int> firstHalf, secondHalf;
		for (int i = 0; i < list.size(); i++) {
			if (i != list.size() / 2) {
				if (list[i] < pivot) {
					firstHalf.push_back(list[i]);
				}
				else if (list[i] >= pivot) {
					secondHalf.push_back(list[i]);
				}
			}
		}

		Sort(firstHalf);
		Sort(secondHalf);

		list.clear();

		AddRange(firstHalf, list);
		list.push_back(pivot);
		AddRange(secondHalf, list);
	}
	catch (...) {
		printf("Error while sorting.\n");
	}
}

void Run() {
	try {
		std::vector<int> first_half, second_half, list = { 2, 4, 1, 6, 7, 4, 8, 10, 7, 6, 14, 19, 9 };

		for (auto elem : list) {
			if (elem < list[list.size() / 2]) {
				first_half.push_back(elem);
			}
			else {
				second_half.push_back(elem);
			}
		}
		std::thread th(Sort, ref(second_half));
		Sort(first_half);

		list.clear();

		AddRange(first_half, list);

		if (th.joinable()) {  //wait
			th.join();
		}

		AddRange(second_half, list);

		for (auto elem : list) {
			printf("%d ", elem);
		}
		
		printf("\n");
	}
	catch (...) {
		printf("Error while runing.");
	}
}

int main()
{
	Run();
	system("pause");
	return 0;
}
