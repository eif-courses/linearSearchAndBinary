//
// Created by Marius on 3/30/2020.
//

#ifndef SEARHINGTECHNIQUES_PERSON_H
#define SEARHINGTECHNIQUES_PERSON_H
#include <iostream>
#include <vector>

class Person {
  int id{};
  int age{};
  std::string name;
  std::vector<Person*> persons;
public:
  Person();
  Person(int id, int age, const std::string &name);
  int getId() const;
  int getAge() const;
  const std::string &getName() const;
  int binarySearchByPersonId(int id);
  void sortPersonById();
  int getSizeOfPersonList();
  static bool comparePersonByAge(Person *p1, Person *p2);

};


#endif //SEARHINGTECHNIQUES_PERSON_H
