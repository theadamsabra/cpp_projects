if [ -f 'lm' ]; then
    rm lm;
fi
g++ -std=c++17 lr_gd/linear_model.cpp -o lm;
./lm;