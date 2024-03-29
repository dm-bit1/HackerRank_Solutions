#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <ostream>
#include <cctype>
using namespace std;

// Overload operator +. E.g. type operator sign (parameters) { /*... body ...*/ }
class Complex {
    public:
        int re, im;
        
        Complex operator+(const Complex& other); // operator overload
    
        Complex(int re, int im); // constructor
        
        Complex operator<<(const Complex& other);
        
        friend ostream& operator<<(ostream& output, const Complex& R) {
            output << R.re << "+i" << R. im;
            return output;
        }
};

Complex::Complex(int re, int im) {
    this->re = re;
    this->im = im;
}

Complex Complex:: operator+(const Complex& other) {
    Complex res(0, 0); // declare instance for C. I.e. A + B = C.
    
    res.re = other.re + this->re;
    
    res.im = other.im + this->im;
    
    return res;
}


// Returns the string result to match the terminal's output.
string Result(const Complex& R){
    string res = to_string(R.re) + "+i" + to_string(R.im) + "\n";
    
    return res;
}

// Converts string to integer in a complex term, e.g. 10+i12.
// Args; string, Return; vector with 2 elements; real, imaginary.
void get_num(string input, vector<int>& res) {
    string temp = "";
    
    res.clear(); // clear the vector
    
    int i = 0;
    
    while (isdigit(input[i])) {
        temp += input[i];
        i++;
    }
    

    res.push_back(stoi(temp));
    
    i += 2; // input has "+i" so advance 2 positions.
    
    temp.clear();
    
    while (isdigit(input[i])) {
        temp += input[i];
        i++;
    }
    
    res.push_back(stoi(temp));
}
// Takes 2 terms and computes the resulting term.
void get_inputs() {
    string s1 = "", s2 = "";

    cin >> s1 >> s2;
    
    vector<int> numbers = {};
    
    get_num(s1, numbers);

    Complex N(numbers[0], numbers[1]);
    
    get_num(s2, numbers);
    
    Complex M(numbers[0], numbers[1]);

    Complex R = N + M;
    
    cout << R << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   \
    // assume 2 inputs 
    get_inputs();
    
    return 0;
}
