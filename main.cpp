#include <iostream>
#include <utility>
#include <vector>

/*
Дана последовательность отсчетов, представляющих собой пары (int Х : int Y).
Отсчеты упорядочены по значениям Х.
В этой последовательности могут встречаться непрерывные подпоследовательности,
состоящие из идентичных отсчетов. Идентичные отсчеты имеют одинаковые значения Y.
Реализовать функцию, прореживающую исходную последовательность следующим
образом:
В каждой подпоследовательности идентичных отсчетов оставить только первый и
последний отсчеты, а так же каждый n-ный отсчет (n > 2).
Вывести на экран последовательность до и после применения функции прореживания.
Язык программирования: C++.
Тип приложения: консольное.
Входные данные задаются непосредственно в тексте программы (жесткое кодирование).
Пример.
Исходная: (1, 10) (2, 11), (3, 11), (4, 11), (5, 11) (6, 10) (7,
11) (8, 11) (9, 11) (10, 11) (11, 10)
Результат при n = 3: (1, 10) (2, 11), (4, 11), (5, 11) (6, 10) (7, 11)
(9, 11) (10, 11) (11, 10)
Результат при n = 4: (1, 10) (2, 11), (5, 11) (6, 10) (7, 11) (10, 11)
(11, 10)


(1, 10) (2, 11) (4, 11)
*/

std::vector<std::pair<int,int>> base_data = {
  {1, 10}, {2, 11}, {3, 11}, {4, 11}, {5, 11},
  {6, 10}, {7, 11}, {8, 11}, {9, 11}, {10, 11},
  {11, 10}
};

void print(const std::vector<std::pair<int,int>>& data) {
  for (const auto& p : data) {
    std::cout << "(" << p.first << ", " << p.second << ") ";
  }
  std::cout << std::endl;
}

std::vector<std::pair<int,int>> seq_reduction(const std::vector<std::pair<int,int>>& data, int n) {
  std::vector<std::pair<int,int>> result;
  if (data.empty()) return result;
  if (n < 3) return result;

  size_t data_size = data.size();
  size_t curr_index = 0;
  size_t block_start=0;
  while (curr_index < data_size) {
    if (result.empty()){
      result.push_back(data[curr_index]);
      curr_index++;
      continue;
    }

    if(data[curr_index].second == data[block_start].second){
      if(curr_index - block_start == n-1){
        result.push_back(data[curr_index]);
        block_start = curr_index;
      }
    } else {
      if((curr_index - block_start <= n-1) && (curr_index - block_start > 1)){
        result.push_back(data[curr_index-1]);
      }
      result.push_back(data[curr_index]);
      block_start = curr_index;
    }
    curr_index++;
  }
  return result;
}

int main(){

  std::cout << "base data: ";
  print(base_data);
  std::vector<std::pair<int,int>> result;
  std::cout<< "result data n = 3: ";
  print(seq_reduction(base_data, 3));
  std::cout << "result data n = 4: ";
  print(seq_reduction(base_data, 4));
  std::cout << "result data n = 5: ";
  print(seq_reduction(base_data, 5));
  return 0;
}