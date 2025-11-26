#include <vector>
#include <iostream>
#include <optional>
#include <cassert>
using namespace std;

struct Tensor
{
    /*
    Core Tensor type.

    @param data
    */

private:
    vector<double> data;

public:
    // Default constructor is an emtpy tensor:
    Tensor(vector<double> d = {})
    {
        data = d;
    };

    int size(){
        return data.size();
    };

    // Overload operators:

    // Overlaod indexing:
    double operator[](int i){
        return data[i];
    };

    // Overload + to be entry-wise addition
    Tensor operator+(Tensor t)
    {
        int n = data.size();
        int m = t.size();
        assert(n == m);
        vector<double> output(n);

        for (int i = 0; i < n; i++)
        {
            output[i] = data[i] + t[i];
        };

        return Tensor(output);
    };

    // Overload * to be (scalar) entry-wise multiplication
    Tensor operator*(int scalar)
    {
        int n = data.size();
        vector<double> output(n);

        for (int i = 0; i < n; i++)
        {
            output[i] = data[i] * scalar;
        };

        return Tensor(output);
    };
};