#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:

  Human(string name) {
    Name = name;
    type = "someone";
  }

  virtual void Walk(const string& destination) const {
    cout << "Someone: " << Name << " walks to: " << destination << endl;
  }

  string getType() const {
    return type;
  }

  string getName() const {
    return Name;
  }

protected:
  string Name;
  string type;
};

class Student : public Human {
public:

  Student(string name, string favouriteSong) : Human(name) {
    FavouriteSong = favouriteSong;
    type = "Student";
  }

  void Walk(const string& destination) const override {
    cout << "Student " << Name << " walks to " << destination << endl;
  }


  void Learn() {
    cout << "Student " << Name << " learns" << endl;
  }

  void SingSong() {
    cout << "Student " << Name << " sings a song " << FavouriteSong << endl;
  }

public:
  string FavouriteSong;
};


class Teacher : public Human {
public:

  Teacher(string name, string subject) : Human(name) {
    Subject = subject;
    type = "Teacher";
  }

  void Walk(const string& destination)const override {
    cout << "Teacher " << Name << " walks to " << destination << endl;
  }

  void Teach() {
    cout << "Teacher " << Name << " teaches " << Subject << endl;
  }

public:
  string Subject;
};


class Policeman : public Human {
public:
  Policeman(string name) : Human(name) {
    type = "Policeman";
  }

  void Walk(const string& destination) const override {
    cout << "Policeman " << Name << " walks to " << destination << endl;
  }

  void Check(const Human& human) const {
    cout << "Policeman " << Name << " checks " << human.getType() << "." << human.getType() << "'s name is " << human.getName() << endl;
  }
};


void VisitPlaces(const Human& human, vector<string> places) {
  for (const string& p : places) {
    human.Walk(p);
  }
}

int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob"), pp("Job");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  p.Check(pp);
  VisitPlaces(s, {"Moscow", "London"});
  return 0;
}