#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void init(std::string in, int n);
void solve(std::string in, std::string out);
void readFromFile(std::string out);

int main() {

    srand(clock());

    std::string in = "./in.txt";
    std::string out = "./out.txt";


    // init file with 1 random numbers
 

    // read numbers from a file and write result to another
    solve(in, out);

    // print result to console
    readFromFile(out);

    return 0;
}

void init(std::string in, int n) {
    std::ofstream input(in, std::ios::binary);

    for (int i = 0; i < n; ++i) {
        input << rand() % 100 << " ";
    }

    input.close();
}

void solve(std::string in, std::string out) {
    std::ifstream input(in, std::ios::binary);
    std::ofstream output(out, std::ios::binary);

    int evenK = 0;
    int oddK = 0;
    int even = 0;
    int odd = 0;

    int n;

    while (!input.eof()) {
        input >> n;
        if (n % 2 == 0) { // if a number if even
            even += n;
            evenK++;
        }
        else { // otherwise
            odd += n;
            oddK++;
        }
    }

    input.close();

    output << "Average for even numbers = " << even / evenK << std::endl;
    output << "Average for odd numbers = " << odd / oddK << std::endl;

    output.close();
}

void readFromFile(std::string out) {
    std::ifstream in(out, std::ios::binary);

    std::string ch;

    while (std::getline(in, ch)) {
        std::cout << ch << std::endl;
    }
}