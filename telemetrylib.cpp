
#include "telemtrylib.hpp"
#include <cstring>
#include <cstdint>
#include <algorithm>

/* 
### Helper function to calculate CRC ###
uint8_t calculate_crc(const uint8_t* data, size_t len) {
	- You may use this function or any other helper functions to process data
	- Lookup what a CRC is and why its helpful
	return crc;
}
*/

vector<packet> encode_data(string& data) {
	vector<packet> packets;
	vector<uint8_t> bytes(data.begin(), data.end());
	/*
	- Input: an arbitrary string 
	- Output: a set of network packets
	- Constraints: Each network packet must be a bytestream of atmost 100 bytes
	- Tips:
		- Ensure the packets are chunked and in sequence so they can be reconstructed
		- Have some form of integrity check incase of chanel corruption
		- You may send extra packets to keep track of any losses
	*/
       return packets;
}


tuple<bool, string> decode_data(vector<packet> packets){
	bool valid = true;
	string result;
	/*
	- Input: a set of network packets
	- Output: boolean for validity and the reconstructed string given valid packets
	- Tips:
		- This function only has the bytes of packets and no context of what the string is
		- You should be able to re-do the encoding process as well as ensure no losses / corruption has occured
	*/
    return {valid, result};
}