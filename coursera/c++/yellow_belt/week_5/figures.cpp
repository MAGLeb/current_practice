#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <memory>

using namespace std;

class Figure {
public:
  Figure(const string &s) : type_(s){};

  string Name() const { return type_; }
  virtual double Perimeter() const = 0;
  virtual double Area() const = 0;

private:
  const string type_ = "FIGURE";
};

class Rect : public Figure {
public:
  Rect(const int &width, const int &height)
      : Figure("RECT"), width_(width), height_(height) {}

  double Perimeter() const { return (width_ + height_) * 2; }
  double Area() const { return width_ * height_; }

private:
  const int width_;
  const int height_;
};

class Triangle : public Figure {
public:
  Triangle(const int s_1, const int s_2, const int s_3)
      : Figure("TRIANGLE"), s_1_(s_1), s_2_(s_2), s_3_(s_3) {}

  double Perimeter() const { return s_1_ + s_2_ + s_3_; }
  double Area() const {
    double p_half = Perimeter() / 2;
    return sqrt(p_half) * sqrt(p_half - s_1_) * sqrt(p_half - s_2_) * sqrt(p_half - s_3_);
  };

private:
  const int s_1_;
  const int s_2_;
  const int s_3_;
};

class Circle : public Figure {
public:
  Circle(const int &radius) : Figure("CIRCLE"), r_(radius){};

  double Perimeter() const { return 2 * pi * r_; };
  double Area() const { return pi * r_ * r_; };

private:
  const double pi =  3.14;
  const int r_;
};

shared_ptr<Figure> CreateFigure(istream &is) {
  string type;
  is >> type;

  if(type == "RECT") {
    int w, h;
    is >> w >> h;
    return make_shared<Rect>(w, h);
  } else if(type == "TRIANGLE") {
    int s_1, s_2, s_3;
    is >> s_1 >> s_2 >> s_3;
    return make_shared<Triangle>(s_1, s_2, s_3);
  } else if(type == "CIRCLE") {
    int radius;
    is >> radius;
    return make_shared<Circle>(radius);
  }

  throw invalid_argument("No type of figure!");
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line);) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto &current_figure : figures) {
        cout << fixed << setprecision(3) << current_figure->Name() << " "
             << current_figure->Perimeter() << " " << current_figure->Area()
             << endl;
      }
    }
  }
  return 0;
}