if [ -f 'tensor' ]; then
    rm tensor;
fi
g++ -std=c++17 tensor.cpp -o tensor;
./tensor;