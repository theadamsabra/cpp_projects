#include <vector>
#include <iostream>
#include <random>
using namespace std;

class SimpleLinearModel
{
    private:
    // Define weights and biases:
    double W = rand();
    double b = rand();

    public:

    // Train function:
    void train(vector<double> x, vector<double> y, int num_epochs, float lr){

    };
};

pair <vector<double>, vector<double>>  generate_training_data(int N, int true_W, int true_b){
    /*
    Simulate random training data for the Linear Model: 
    
    @param N number of samples to randomly generate
    @param true_W true weight of the linear model to be predicted 
    @param true_b true bias of the linear model to be predicted
    */

    // Generate random device, set seed, and generate
    // a random gaussian:
    mt19937 generator(36);
    normal_distribution<double> standard_gaussian(0, 1);

    // Generate dummy x_train data: 
    vector<double> x_train(N), y_train(N);

    // Construct the data: 
    for (int i=0; i<N; i++){
        double random_number = standard_gaussian(generator);
        x_train[i] = random_number;
        y_train[i] = (true_W * random_number) + true_b;
    }

    return make_pair(x_train, y_train);
};

// Main function to test the linear model:
int main(){
    // Params for training:
    int num_epochs = 10;
    float lr = 0.01;

    // This can be really whatever
    int N = 10000;
    int true_W = 5;
    int true_b = 22;

    // This is C++ 17.
    // Guess I'm using this for now
    auto [x_train, y_train] = generate_training_data(N, true_W, true_b);
    return 0;
}