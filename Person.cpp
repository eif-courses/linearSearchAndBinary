//
// Created by Marius on 3/30/2020.
//

#include <algorithm>
#include "Person.h"

Person::Person(int id, int age, const std::string &name) : id(id), age(age), name(name) {

}

int Person::getId() const {
  return id;
}

int Person::getAge() const {
  return age;
}

const std::string &Person::getName() const {
  return name;
}

int Person::binarySearchByPersonId(int id) {

  int l = 0;
  int r = getSizeOfPersonList()-1;
  while(l <= r){
    int m = l + ( r - 1 ) / 2;

    if(persons[m]->getId() == id){
      return m;
    }
    if(persons[m]->getId() < id){
      l = m + 1;
    }else{
      r = m - 1;
    }
  }
  return -1;
}

bool Person::comparePersonByAge(Person *p1, Person *p2) {
  return p1->getId() < p2->getId();
}

Person::Person() {

  auto *peter = new Person(255511, 62, "Peter");
  auto *john = new Person(35522, 33, "john");
  auto *catherine = new Person(11221, 22, "catherine");

  persons.push_back(peter);
  persons.push_back(john);
  persons.push_back(catherine);

  sortPersonById();
}

void Person::sortPersonById() {
  sort(persons.begin(), persons.end(), comparePersonByAge);
}

int Person::getSizeOfPersonList() {
  return persons.size();
}
