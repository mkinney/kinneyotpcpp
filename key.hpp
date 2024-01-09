#include <iostream>
#include <random>
#include <string>

using std::string;
using std::rand;

class Key {

private:
    string seed;
    int length;
    string alphabet;
    std::mt19937 generator;

public:
    Key(long seed = 0, int length = 20, string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
        if (seed == 0) {
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // seed the generator
            this->generator = gen;
        } else {
            std::mt19937 gen(seed); // seed the generator
            this->generator = gen;
        }
        this->seed = seed;
        this->length = length;
        this->alphabet = alphabet;
    }

    string gen() {
        std::uniform_int_distribution<> distr(0, alphabet.length()); // define the range
        string out = "";
        for (int i = 0; i < length; i++) {
            int x = distr(generator);
            out += alphabet[x];
        }
        return out;
    }
};


