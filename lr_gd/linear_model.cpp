#include <vector>
using namespace std;

class LinearModel
{
    private:
    // Define weights and biases:
    vector<double> W;
    vector<double> b;

    public:

    // Train function:
    void train(vector<double> x, vector<double> y, int num_epochs, float lr){

    };
};

tuple < vector<double>, vector<double> > generate_training_data(){
    // TODO: Properly generate random numbers (ideally betweeen 0 and 1)
    vector<double> x_train = generate(0, 1000);

    // TODO: Update this to loop:
    vector<double> y_train = 5*x_train + 22;

    return make_tuple(x_train, y_train);
};

// Main function to test the linear model:
int main(){
    int num_epochs = 10;
    float lr = 0.01;

    vector<double> x_train, y_train = generate_training_data();
    LinearModel lm = LinearModel();
    lm.train(x_train, y_train, num_epochs, lr);
}