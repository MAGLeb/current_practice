#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FunctionPart {
public:
    FunctionPart(const char& new_operation, const double& new_value) {
        value = new_value;
        operation = new_operation;
    }

    void Invert() {
        if(operation == '+') {
            operation = '-';
        } else if(operation == '/') {
            operation = '*';
        } else if(operation == '-') {
            operation = '+';
        } else if(operation == '*') {
            operation = '/';
        }
    }

    void GetOperation() {
        cout << operation << " value: " << value << endl;
    }

    double Apply(const double& new_value) const {
        if(operation == '-') {
            return new_value - value;
        } else if(operation == '+') {
            return new_value + value;
        } else if(operation == '*') {
            return new_value * value;
        } else if(operation == '/') {
            return new_value / value;
        }
    }
private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(const char& operation, const double& value) {
        parts.push_back({operation, value});
    };

    void Invert() {
        for(auto& part : parts) {
            part.Invert();
        }
        reverse(parts.begin(), parts.end());
    };

    double Apply(const double& value) const {
        double result = value;
        for(auto& part : parts) {
            result = part.Apply(result);
        }
        return result;
    };

private:
    vector<FunctionPart> parts;
};
//
//struct Image {
//    double quality;
//    double freshness;
//    double rating;
//};
//
//struct Params {
//    double a;
//    double b;
//    double c;
//};
//
//Function MakeWeightFunction(const Params& params,
//                            const Image& image) {
//    Function function;
//    function.AddPart('*', params.a);
//    function.AddPart('-', image.freshness * params.b);
//    function.AddPart('+', image.rating * params.c);
//    return function;
//}
//
//double ComputeImageWeight(const Params& params, const Image& image) {
//    Function function = MakeWeightFunction(params, image);
//    return function.Apply(image.quality);
//}
//
//double ComputeQualityByWeight(const Params& params,
//                              const Image& image,
//                              double weight) {
//    Function function = MakeWeightFunction(params, image);
//    function.Invert();
//    return function.Apply(weight);
//}
//
//int main() {
//    Image image = {10, 2, 6};
//    Params params = {4, 2, 6};
//    // 10 * 4 - 2 * 2 + 6 * 6 = 72
//    // 5 * 4 - 2 * 2 + 6 * 6 = 52 // 20-4+36=52
//    // 52 - 6 * 6 + 2 * 2 / 4 = 5
//    cout << ComputeImageWeight(params, image) << endl;
//    cout << ComputeQualityByWeight(params, image, 52) << endl;
//    return 0;
//}