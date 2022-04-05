#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
  Person(const string &type, const string &name) : type_(type), name_(name){};

  string Name() const { return name_; };
  string Type() const { return type_; };
  virtual void Walk(const string &destination) const {
    cout << type_ << ": " << name_ << " walks to: " << destination << endl;
  };

private:
  string type_ = "Person type";
  string name_ = "person name";
};

class Student : public Person {
public:
  Student(const string &name, const string &favouriteSong)
      : Person("Student", name), favouriteSong_(favouriteSong) {}

  void Learn() const { cout << Type() << ": " << Name() << " learns" << endl; }

  void Walk(const string &destination) const override {
    Person::Walk(destination);
    SingSong();
  }

  void SingSong() const {
    cout << Type() << ": " << Name() << " sings a song: " << favouriteSong_
         << endl;
  }

private:
  const string favouriteSong_;
};

class Teacher : public Person {
public:
  Teacher(const string &name, const string &subject)
      : Person("Teacher", name), subject_(subject) {}

  void Teach() const {
    cout << Type() << ": " << Name() << " teaches: " << subject_ << endl;
  }

public:
  const string subject_;
};

class Policeman : public Person {
public:
  Policeman(const string &name) : Person("Policeman", name) {}

  void Check(const Person &person) const {
    cout << Type() << ": " << Name() << " checks " << person.Type() << ". "
         << person.Type() << "'s name is: " << person.Name() << endl;
  }
};

void VisitPlaces(const Person &person, const vector<string> &places) {
  for(auto place : places) {
    person.Walk(place);
  }
}

int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});
  return 0;
}
