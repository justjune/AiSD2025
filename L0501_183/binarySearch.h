#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> 
#include <algorithm> 

using namespace std;

template <typename T>
void binary_search(vector<T>& data, const T& key, size_t low, size_t high, size_t& index) {

	// проверка на границы
	if (low > high)
		throw out_of_range("Некорректные границы");

	// устанавливаем середину массива
	size_t middle = (low + high) / 2;

	// если в середине нашлось искомое значение, отправляем его индекс обратно
	if (data[middle] == key){
		index = middle;
		return;
	}
	// если в середине нашлось значение, меньшее искомого, ищем значение в правой части массива
	else if (data[middle] < key)
		binary_search(data, key, middle + 1, high, index);

	// если в середине нашлось значение, больше искомого, ищем значение в левой части массива
	else if (data[middle] > key)
		binary_search(data, key, low, middle - 1, index);


};
#endif