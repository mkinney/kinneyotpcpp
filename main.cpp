#include <iostream>
#include <utility>

#include "key.hpp"
#include "otp.hpp"

using std::cout;
using std::endl;

int main() {
    Key key;
    cout << key.gen() << endl;
    Key key2(11);
    cout << key2.gen() << endl;

    string key3="APPLE";
    OTP otp(key3);
    pair<string, string> results;

    string encode="HELLO";
    results = otp.encode(encode);
    cout << "msg:" << results.first << endl;
    cout << "encoded:" << results.second << endl;

    OTP otp2("HTAWS");
    pair<string, string> results2;
    results2 = otp2.decode("APPLE");
    cout << "msg:" << results2.first << endl;
    cout << "decoded:" << results2.second << endl;


    return 0;
}
