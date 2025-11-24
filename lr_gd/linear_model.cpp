#include <vector>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <random>
using namespace std;

class SimpleLinearModel
{
    public:
    // Define weights and biases:
    // TODO: Infer dimensionality when we go up from 1D vectors
    double W;
    double b;

    // Set up constructor:
    SimpleLinearModel(){
        // Just instantiate some arbitrary numbers:
        W = 0.0;
        b = 0.0;
    }
    
    double get_weight(){
        return W;
    }

    double get_bias(){
        return b;
    };

    void update_weight(double new_weight){
        W = new_weight;
    };

    void update_bias(double new_bias){
        b = new_bias;
    };

    double mean_squared_error(vector<double> x, vector<double> y){
        /*
        Calculate mean squared error loss term. 

        @param x input data
        @param y output data

        @returns MSE Loss 
        */
        double n = x.size();
        double coeff = (1/n);

        double mse_prenorm = 0.0;
        for (int i=0; i<n; i++){
            double x_i = x[i];
            double y_i = y[i];
            mse_prenorm += pow((y_i - (W*x_i + b)), 2);
        };
        return coeff * mse_prenorm;
    };

    double get_weight_grad(vector<double> x, vector<double> y) {
        /*
        Calculate gradient of weight term.

        @param x input data
        @param y output data

        @returns gradient of weight term.
        */
        double n = x.size();
        double coeff = -2 / n; 
        double grad_W = 0.0;

        for (int i=0; i<n; i++){
            double x_i = x[i];
            double y_i = y[i];
            grad_W = grad_W + (x_i * (y_i - (W*x_i + b)));
        };
        return coeff * grad_W;
    };

    float get_bias_grad(vector<double> x, vector<double> y) {
        /*
        Calculate gradient of bias (or intercept) term.

        @param x input data
        @param y output data

        @returns gradient of bias (or intercept) term.
        */
        int n = x.size();
        double coeff = -2 / n;
        double grad_b = 0.0;
        for (int i=0; i<n; i++){
            double x_i = x[i];
            double y_i = y[i];
            grad_b = grad_b + (y_i - (W*x_i + b));
        };
        return coeff * grad_b;
    };

    void backpropogate(double grad_W, double grad_b, double lr){
        /*
        Simple backpropogation function.
        
        @param grad_W gradient of the weight(s)
        @param grad_b gradient of the bias(es)
        @param lr learning rate for gradient descent
        */

        // TODO: W and b aren't updating properly.
        W = get_weight();
        b = get_bias();

        W = W - (lr * grad_W);
        b = b - (lr * grad_b);

        update_weight(W);
        update_bias(b);
    };

    vector<double> predict(vector<double> x){
        /*
        Get predictions 

        @param x input data

        @returns y_pred predicted output
        */
        int n = x.size();
        vector<double> y_pred(n);
        for (int i; i<n; i++){
            y_pred[i] = (W * x[i] + b);
        };
        return y_pred;
    };

    // Train function:
    void train(vector<double> x, vector<double> y, int num_epochs, double lr){
        /*
        Core training loop of the linear model. 

        @param x input data
        @param y output data
        @param num_epochs number of epochs to train for
        @param lr learning rate for gradient descent
        */
        for (int epoch_num=0; epoch_num<num_epochs; epoch_num++){
            cout << "Epoch" << epoch_num+1 << "\n" << endl;
            double mse_loss = mean_squared_error(x, y);
            cout << "MSE Loss:" << mse_loss << "\n" << endl;

            double grad_W = get_weight_grad(x, y);
            double grad_b = get_bias_grad(x, y);

            backpropogate(grad_W, grad_b, lr);
        };

    };
};

pair <vector<double>, vector<double>>  generate_training_data(int N, int true_W, int true_b){
    /*
    Simulate random training data for the Linear Model: 
    
    @param N number of samples to randomly generate
    @param true_W true weight of the linear model to be predicted 
    @param true_b true bias of the linear model to be predicted

    @returns generated x_train, y_train data pairs of shape (N,).
    */

    // Generate random device, set seed, and generate
    // a random gaussian:
    mt19937 generator(36);
    normal_distribution<double> standard_gaussian(0, 1);
    uniform_real_distribution<double> uniform(0, 100);

    // Generate dummy x_train data: 
    vector<double> x_train(N), y_train(N);

    // Construct the data: 
    for (int i=0; i<N; i++){
        double random_input = uniform(generator);
        double random_error = standard_gaussian(generator);

        x_train[i] = random_input;
        y_train[i] = (true_W * random_input) + true_b + random_error;
    }

    return make_pair(x_train, y_train);
};

// Main function to test the linear model:
int main(){
    // Params for training:
    int num_epochs = 1000;
    double lr = 0.1;

    // This can be really whatever
    int N = 10000;
    int true_W = 5;
    int true_b = 22;

    // This is C++ 17.
    // Guess I'm using this for now
    auto [x_train, y_train] = generate_training_data(N, true_W, true_b);
    SimpleLinearModel lm;
    lm.train(x_train, y_train, num_epochs, lr);
    return 0;
}