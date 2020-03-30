#include <iostream>
#include <vector>
#include "Person.h"


// std::list => list
int linearSearch(std::vector<int> &list, int searchItem);

// 50, 30, 40, 10, 20, 90, 44  left[0..6]right ,
int binarySearch(std::vector<int> &list, int left, int right, int searchKey);

int binaryS(const int array[], int l, int r, int searchItem) {

  //  int array[] = {2, 3, 4, 10, 40}; -> size 6

  while (l <= r) {  // 0 <= 6

    int m = l + (r - 1) / 2;

    // Search item => 10

    // WE MOVING TO RIGTH SIDE AFTER FIRST ITERATION AND REMOVE LEFT HALF ELEMENTS
    // int array[] = {2, 3, 4, 10, 40}; -> size 6

    // m = 0 + (6 - 1) / 2 = 2
    // middle element => 4, element index = 2

    //if 4 == 10 false
    if (array[m] == searchItem) {
      return m;
    }

    // if 4 < 10 true
    if (array[m] < searchItem) {
      l = m + 1; // l = 2 + 1 = 3
    } else {
      r = m - 1;
    }
  }
  return -1;
}



int main() {

  std::vector<int> list = {50, 30, 40, 10, 20, 90, 44};
  std::vector<int> sorted_list = {10, 20, 30, 50, 77, 99, 88};


//  int input = 0;
//  std::cout << "Enter search item int value:";
//  std::cin >> input;
//
//  int result = linearSearch(list, input);
//
//  if(result != -1){
//    std::cout << "founded at index: " << result << " iterations: " << result + 1 << std::endl;
//    std::cout << "founded value: "<< list[result]<<std::endl;
//  }else{
//    std::cout << "elemenet not founded!" << std::endl;
//  }




 // std::vector<int> sorted_list = {10, 20, 30, 50, 77, 99, 88};

 Person *p = new Person(22, 22, "");

 int founded_value = p->binarySearchByPersonId( 35522);

  if(founded_value != -1) {
    std::cout << "founded index: "<< founded_value<<std::endl;
  }else{
    std::cout << "elemenet not founded!" << std::endl;
  }


  return 0;
}

int binarySearch(std::vector<int> &list, int left, int right, int searchKey){
  // searchKey = 77
  // sorted_list = {10, 20, 30, 50, 77, 99, 88};
  while(left <= right){ // 0 <= 6

    int middle = left + (right - 1) / 2; // 0 + (7-1) / 2 = index of middle element 3

    if(list[middle] == searchKey){
      return middle; // return founded element index
    }
    if(list[middle] < searchKey){ // 50 < 77 true
      left = middle + 1; // take the right sublist  0 + 3 + 1 = 4
    }else{
      right = middle - 1; // take left sublist right 6 - 3 - 1 = 2
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
