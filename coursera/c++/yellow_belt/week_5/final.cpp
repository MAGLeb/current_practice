#include <iostream>
#include <vector>

using namespace std;

class Human {
public:
  Human(const string &type, const string &name) : type_(type), name_(name){};

  string Name() const { return name_; };
  string Type() const { return type_; };
  virtual void Walk(const string &destination) const {
    cout << type_ << ": " << name_ << " walks to: " << destination << endl;
  };

private:
  const string type_ = "Human type";
  const string name_ = "Human name";
};

class Student : public Human {
public:
  Student(const string &name, const string &favouriteSong)
      : Human("Student", name), favouriteSong_(favouriteSong) {}

  void Learn() const { cout << Type() << ": " << Name() << " learns" << endl; }

  void Walk(const string &destination) const override {
    Human::Walk(destination);
    SingSong();
  }

  void SingSong() const {
    cout << Type() << ": " << Name() << " sings a song: " << favouriteSong_
         << endl;
  }

private:
  const string favouriteSong_;
};

class Teacher : public Human {
public:
  Teacher(const string &name, const string &subject)
      : Human("Teacher", name), subject_(subject) {}

  void Teach() const {
    cout << Type() << ": " << Name() << " teaches: " << subject_ << endl;
  }

public:
  const string subject_;
};

class Policeman : public Human {
public:
  Policeman(const string &name) : Human("Policeman", name) {}

  void Check(const Human &human) const {
    cout << Type() << ": " << Name() << " checks " << human.Type() << ". "
         << human.Type() << "'s name is: " << human.Name() << endl;
  }
};

void VisitPlaces(Human &human, const vector<string> &places) {
  for(auto place : places) {
    human.Walk(place);
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