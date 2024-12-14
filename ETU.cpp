#include <iostream> 
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;

// Заполнение массива случайными числами и их вывод.
void FillArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		arr[i] = (rand() % 199) - 99; // Диапазон от -99 до 99
		cout << arr[i] << " "; 
	}
	cout << endl;
}

// Вывод массива.
void PrintArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
}
// Сортировка пузырьком.
void BubbleSort(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
// Сортировка шейкером.
void ShakerSort(int arr[], int arrSize)
{
	bool swapped = true;
	int start = 0;
	int end = arrSize - 1;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}
// Соритровка расчёской.
void CombSort(int arr[], int arrSize) {
	float k = 1.247;
	float S = arrSize - 1;
	int swap;
	int count = 0;

	while (S >= 1)
	{
		for (int i = 0; i + S < arrSize; i++)
		{
			if (arr[i] > arr[int(i + S)])
			{
				swap = arr[int(i + S)];
				arr[int(i + S)] = arr[i];
				arr[i] = swap;
			}
		}
		S /= k;
	}

	while (true)
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = swap;
			}
			else count++;
		}
		if (count == arrSize - 1)
			break;
		else
			count = 0;
	}

}
// Сортировка вставками
void InsertionSort(int arr[], int arrSize) {
	{
		for (int i = 1; i < arrSize; i++)
		{
			int j = i - 1;
			while (j >= 0 && arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				j--;
			}
		}
	}
}
// Быстрая сортировка.
void QuickSort(int arr[], int begin, int end) {
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l) {
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l) {
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) QuickSort(arr, begin, l);
	if (f < end) QuickSort(arr, f, end);
}
// Сортировка Шелла.
void ShellSort(int arr[], int arrSize)
{
	int i, j, step;
	int tmp;
	for (step = arrSize / 2; step > 0; step /= 2)
		for (i = step; i < arrSize; i++)
		{
			tmp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < arr[j - step])
					arr[j] = arr[j - step];
				else
					break;
			}
			arr[j] = tmp;
		}
}


// Структура минимального и максимального значений.
struct MinMax {
	int min;
	int max;
};

// Поиск минимальных и максимальных элементов.
MinMax MinAndMaxValue(int arr[], int arrSize, bool sorted) {
	MinMax result = { arr[0], arr[0] };
	if (sorted) {
		result.min = arr[0];
		result.max = arr[arrSize - 1];
	}
	else {
		for (int i = 1; i < arrSize; i++) {
			if (arr[i] < result.min) {
				result.min = arr[i];
			}
			if (arr[i] > result.max) {
				result.max = arr[i];
			}
		}
	}
	return result;
}
// Среднее значение минимального и максимального элементов
void AvgMinMax(int arr[], int arrSize, bool sorted) {
	MinMax resault = MinAndMaxValue(arr, arrSize, sorted);
	int avg = (float(resault.max + resault.min) / 2);
	int cnt = 0;
	cout << "Средний результат максимального и минимального элемента: " << avg << endl;
	cout << "Индексы элементов равные среднему значению: ";
	for (int i = 0; i < arrSize && (!sorted || arr[i] <= avg); i++) {
		if (arr[i] == avg) {
			cout << i << " ";
			++cnt;
		}

	}
	cout << "\nКол - во найденных : " << cnt << endl;


}


// Подсчёт количества элементов меньше заданного числа.
int CntLess(int arr[], int arrSize, int choice) {
	int cnt = 0;
	for (int i = 0; i < arrSize && arr[i] < choice; i++) {
		++cnt;
	}
return cnt;
}

// Подсчёт количества элементов больше заданного числа.
int CntUp(int arr[], int arrSize, int choice) {
	int cnt = 0;

	for (int i = arrSize - 1; i >= 0 && arr[i] > choice; i--) {
		++cnt;
	}
return cnt;
}
// Бинарный поиск.
bool BinarySearh(int arr[], int arrSize, int choice) {
	int low = 0;
	while (low <= arrSize) {
		int mid = low + (arrSize - low) / 2;

		if (arr[mid] == choice)
			return true;
		if (arr[mid] < choice)
			low = mid + 1;
		else
			arrSize = mid - 1;
	}
	return false;
}
// Обычный линейный поиск.
bool JustSearch(int arr[], int arrSize, int choice) {
	for (int i = 1; i < arrSize; i++) {
		if (arr[i] == choice) {
			return true;
		}
	}
	return false;
}


int main() {
	setlocale(0, ""); // Русский язык.
	srand(time(NULL));
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds resultTime;
	nanoseconds resultSorted;

	const unsigned int N = 600; // Размерность массива
	int arr[N]; // Сам массив
	
	bool started = true;
	bool choiseStarted = true;

	while (started) {
		bool notSorted = false;
		int sortChoice;
		int operationChoice;
		cout << "Размерность массива - " << N << endl;
		cout << "Неотсортированный массив со случайными числами:" << endl;
		FillArr(arr, N);

		cout << "Предстоит выбрать метод сортировки:" << endl;
		cout << " 1 | Bubble Sort" << endl;
		cout << " 2 | Shaker Sort" << endl;
		cout << " 3 | Comb Sort" << endl;
		cout << " 4 | Insertion sort" << endl;
		cout << " 5 | Quick sort" << endl;
		cout << " 6 | ShellSort" << endl;
		cout << " 7 | Не сортировать массив" << endl;
		cout << " 0 | Выход из программы" << endl;

		cin >> sortChoice;
		if (sortChoice == 0) {
			started = false;
			break;
		}
		start = steady_clock::now();
			switch (sortChoice) {
			case 1: BubbleSort(arr, N); break;
			case 2: ShakerSort(arr, N); break;
			case 3: CombSort(arr, N); break;
			case 4: InsertionSort(arr, N); break;
			case 5: QuickSort(arr, 0, N - 1); break;
			case 6: ShellSort(arr, N); break;
			case 7: notSorted = true; break;
			default: cout << "Неверный выбор" << endl;
		}

		end = steady_clock::now();
		resultSorted = duration_cast<nanoseconds>(end - start);

		cout << "Полученный массив: " << endl;
		PrintArr(arr, N);
		cout << "\nВремя, потраченное на сортировку: " << resultSorted.count() << endl;

		cout << "Теперь предстоит выбрать методы для работы с массивом: " << endl;

		while (choiseStarted) {

			int choiceNumber;
			int cnt;


			cout << " 1 | Найти минимальный и максимальный элементы" << endl;
			cout << " 2 | Найти среднее значение минимального и максимального элементов" << endl;
			cout << " 3 | Подсчитать количество элементов меньше числа a (для отсортированного массива)" << endl;
			cout << " 4 | Подсчитать количество элементов больше числа b (для отсортированного массива)" << endl;
			cout << " 5 | Найти число с помощью бинарного поиска" << endl;
			cout << " 6 | Найти число с помощью обычного перебора" << endl;
			cout << " 0 | Вернуться в главное меню" << endl;

			cin >> operationChoice;

			if (operationChoice == 0) {
				break;
			}

			switch (operationChoice) {
			case 1: {
				start = steady_clock::now();
				MinMax result = MinAndMaxValue(arr, N, !notSorted);
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);
				cout << "Минимальный элемент: " << result.min << " Максимальный элемент: " << result.max << "\nЗатраченное время: " << resultTime.count() << endl;;
				break;
			}
			case 2: {
				start = steady_clock::now();
				AvgMinMax(arr, N, !notSorted);
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);
				break;
			}
			case 3: {

				if (notSorted) { cout << "Нужен именно отсортированный массив!!" << endl; break; }


				cout << "Введите число а: " << endl;
				cin >> choiceNumber;

				start = steady_clock::now();
				cnt = CntLess(arr, N, choiceNumber);
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);
				cout << "Кол-во элементов меньших числа а: " << cnt << "\nЗатраченное время: " << resultTime.count() << endl;
				break;
			}
			case 4: {

				if (notSorted) { cout << "Нужен именно отсортированный массив!!" << endl; break; }

				cout << "Введите число b: " << endl;
				cin >> choiceNumber;

				start = steady_clock::now();
				cnt = CntUp(arr, N, choiceNumber);
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);

				cout << "Кол-во элементов меньших числа b: " << cnt << "\nЗатраченное время: " << resultTime.count() << endl;
				break;
			}
			case 5: {

				if (notSorted) { cout << "Нужен именно отсортированный массив!!" << endl; break; }

				cout << "Введите число, чтобы узнать есть ли он в массиве или нет." << endl;
				cin >> choiceNumber;

				start = steady_clock::now();
				cout << (BinarySearh(arr, N, choiceNumber) ? "Найдено" : "Не найдено") << endl;
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);

				cout << "Затраченное время : " << resultTime.count() << endl;
				break;
			}
			case 6: {

				if (notSorted) { cout << "Нужен именно отсортированный массив!!" << endl; break; }

				cout << "Введите число, чтобы узнать есть ли он в массиве или нет." << endl;
				cin >> choiceNumber;

				start = steady_clock::now();
				cout << (JustSearch(arr, N, choiceNumber) ? "Найдено" : "Не найдено") << endl;
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);

				cout << "Затраченное время : " << resultTime.count() << endl;
				break;
			}
			case 7: {
				int i1, i2;
				cout << "Введите два индекса для обмена: ";
				cin >> i1 >> i2;

				if (i1 >= 0 && i1 < N && i2 >= 0 && i2 < N) {
					start = steady_clock::now();
					swap(arr[i1], arr[i2]);
					end = steady_clock::now();
					resultTime = duration_cast<nanoseconds>(end - start);
				}
				else { cout << "Неверные индексы!" << endl; }

				cout << "Изменённый массив: " << endl;
				PrintArr(arr, N);

				cout << "Затраченное время: " << resultTime.count() << endl;
				break;
			}
			default:
				cout << "Неверный выбор" << endl;
			}
		}
	}
	return 0;
}