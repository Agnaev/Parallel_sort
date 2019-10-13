#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

void swap(vector<int> list, int a, int b) {
	int tmp = list[a];
	list[a] = list[b];
	list[b] = list[a];
}

void Sort(vector<int>& list) {
	try
	{
		if (list.size() == 2 && list[0] > list[1])
		{
			swap(list, 0, 1);
			return;
		}

		if (list.size() == 2 || list.size() == 1 || list.size() == 0)
			return;

		int middle = list.size() / 2;
		int pivot = list[middle];
		vector<int> firstHalf, secondHalf;
		for (int i = 0; i < list.size(); i++)
			if (i != list.size() / 2)
			
				if (list[i] < pivot)
					firstHalf.push_back(list[i]);
				else if (list[i] >= pivot)
					secondHalf.push_back(list[i]);
			

		Sort(firstHalf);
		Sort(secondHalf);

		list.clear();

		for (auto& elem : firstHalf) 
			list.push_back(elem);
		list.push_back(pivot);
		for (auto& elem : secondHalf) 
			list.push_back(elem);
		
		//return list;
	}
	catch (...) {
		cout << "Error while sorting." << endl;
	}
}

void Run() {
	try {
		vector<int> first_half, second_half, list = { 2, 4, 1, 6, 7, 4, 1, 10, 7, 6, 14, 19, 9 };

		for (auto elem : list) 
			if (elem < list[list.size() / 2]) 
				first_half.push_back(elem);
			else 
				second_half.push_back(elem);

		thread th(Sort, ref(second_half));
		Sort(first_half);

		list.clear();

		for (auto elem : first_half) 
			list.push_back(elem);

		if (th.joinable())  //wait
			th.join();

		for (auto elem : second_half) 
			list.push_back(elem);

		for (auto elem : list) 
			printf("%d ", elem);
		
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
