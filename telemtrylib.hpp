#include <array>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define PACKET_LENGTH 100
using packet = array<uint8_t, PACKET_LENGTH>;

vector<packet> encode_data(string& data);
tuple<bool, string> decode_data(vector<packet> packets);
