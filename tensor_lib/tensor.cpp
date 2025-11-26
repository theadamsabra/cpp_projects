#include <vector>
#include <iostream>
#include <optional>
#include <cassert>
#include <any>
using namespace std;

struct Vector 
{
    /*
    Core Vector type.

    @param data
    */

private:
    vector<double> data;

public:
    // Default constructor is an emtpy tensor:
    Vector(vector<double> d = {})
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
    Vector operator+(Vector &t)
    {
        int n = data.size();
        int m = t.size();
        assert(n == m);
        vector<double> output(n);

        for (int i = 0; i < n; i++)
        {
            output[i] = data[i] + t[i];
        };

        return Vector(output);
    };

    // Overload * to be (scalar) entry-wise multiplication
    Vector operator*(int &scalar)
    {
        int n = data.size();
        vector<double> output(n);

        for (int i = 0; i < n; i++)
        {
            output[i] = data[i] * scalar;
        };

        return Vector(output);
    };

    // Overload / to be (scalar) entry-wise multiplication
    Vector operator/(int &scalar)
    {
        int n = data.size();
        vector<double> output(n);

        for (int i = 0; i < n; i++)
        {
            output[i] = data[i] / scalar;
        };

        return Vector(output);
    };
};

int main(){
    Vector t({1,1,1});
    return 0;
};