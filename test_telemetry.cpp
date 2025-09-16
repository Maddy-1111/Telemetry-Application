/*
- just give back the contents
- corrupt packet content
- drop one of the packets
- add extra packet
- truncate packets (this do for all)
- rearrange packts
- drop some content in packet
*/

#include "telemtrylib.hpp"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

string generate_random_string(size_t length) {
    static const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(0, sizeof(charset) - 2);
    string str;
    str.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        str += charset[dis(gen)];
    }
    return str;
}

void run_tests() {
    string original = generate_random_string(500);
    auto packets = encode_data(original);
    cout << "Original string length: " << original.size() << endl;
    cout << "Packets generated: " << packets.size() << endl;

    // 1. Just give back the contents
    {
        auto [ok, decoded] = decode_data(packets);
        cout << "Test 1 - Direct decode: " << (ok && decoded == original ? "PASS" : "FAIL") << endl;
    }

    // 2. Corrupt packet content
    {
        auto corrupted = packets;
        if (!corrupted.empty()) {
            corrupted[0][1] ^= 0xFF; // flip bits in first data byte
        }
        auto [ok, decoded] = decode_data(corrupted);
        cout << "Test 2 - Corrupt packet: " << (!ok ? "PASS" : "FAIL") << endl;
    }
}

int main() {
    run_tests();
    return 0;
}