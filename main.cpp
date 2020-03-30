#include <iostream>
#include <vector>
#include "Person.h"


// std::list => list
int linearSearch(std::vector<int> &list, int searchItem);

// 50, 30, 40, 10, 20, 90, 44  left[0..6]right ,
int binarySearch(std::vector<int> &collection, int left, int right, int searchKey);


int main() {

  std::vector<int> list = {50, 30, 40, 10, 20, 90, 44};

  std::cout << "===================LINEAR SEARCHING ALGORITHM============="<< std::endl;

  int input = 0;
  std::cout << "Enter search item int value:";
  std::cin >> input;

  // variable result => linearSearch function result which returns founded element at index
  int result = linearSearch(list, input);

  if(result != -1){
    std::cout << "founded at index: " << result << " iterations: " << result + 1 << std::endl;
    std::cout << "founded value: "<< list[result]<<std::endl;
  }else{
    std::cout << "element not founded!" << std::endl;
  }

  std::vector<int> sorted_list = {10, 20, 30, 50, 60, 70, 80};

  std::cout << "======================BINARY SEARCHING ALGORITHM============="<< std::endl;

  int searchKey = 0;
  std::cout << "Enter search item int value:";
  std::cin >> searchKey;
  // variable int founded_value ->  function result which returns founded element at index

  int founded_value = binarySearch(sorted_list, 0, sorted_list.size() - 1, searchKey);

  if(founded_value != -1) {
    std::cout << "founded index: "<< founded_value<<std::endl;
    std::cout << "founded value: "<< sorted_list[founded_value]<<std::endl;
  }else{
    std::cout << "elemenet not founded!" << std::endl;
  }
  std::cout << "========USING PERSON OBJECT BINARY SEARCH ALGORITHM==============="<< std::endl;

  Person *person = new Person();

  // persons vector already have added some objects:
  // auto *peter = new Person(255511, 62, "Peter");
  //  auto *john = new Person(35522, 33, "john");
  //  auto *catherine = new Person(11221, 22, "catherine");


  // we picking john id 35522
  int personID = person->binarySearchByPersonId(35522);

  std::cout << "FOUNDED PERSON AT INDEX:" << personID << std::endl;


  return 0;
}

int binarySearch(std::vector<int> &collection, int l, int r, int searchKey){
  // searchKey = 77
  // sorted_list = {10, 20, 30, 50, 60, 70, 80};
  while(l <= r){ // 0 <= 6

    int middle = l + (r - l) / 2; // 0 + (7-1) / 2 = index of middle element 3

    if(collection[middle] == searchKey){
      return middle; // return founded element index
    }
    if(collection[middle] < searchKey){ // 50 < 77 true
      l = middle + 1; // take the right sublist  0 + 3 + 1 = 4
    }else{
      r = middle - 1; // take left sublist right 6 - 3 - 1 = 2
    }
  }
  return -1;
}

int linearSearch(std::vector<int> &list, int searchItem){
  int counter = 0;
  for(int item: list){

    if(item == searchItem){
      return counter;
    }
    counter++;
  }
  return -1;
}
