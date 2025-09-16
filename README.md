# Telemetry Application
This repo contains the telemetry coding question which is part of the electrical application of Agnirath

### The situation:
- You're part of a team exploring new undescovered terrain
- You dont have Wifi, no g-cloud, no supabase to upload and sync to.
- Your goal is to transmit critical messages from the vehicle and relay it to the control tower
- The hardware setup is taken care of, but we need you to write the algorithm
- The weather is harsh and data may not reach the receiver as it was sent

### The requirements:
- You must design a system (an encoder function and a decoder function) that takes in any input string and gets it across to the other side
- The hardware restricts you to transmit data packets only as a bytestream with a maximum length of 100 bytes each
- You must only transmit data that is correct, you cannot affort to relay any corrupted data.
- However, loss of information is acceptable as the transmission is not in your hand
- The output should be the validity flag and the original string. (Note: even if one of the packets is corrupted / lost, the validity should be false and the output should be an empty string)

### More explicitly:
- There is a telemetrylib.cpp file, which contain 2 main funcitons: encode_data and decode_data.
- Your task is to complete these functions which will then be utilisted in the encoder and decoder systems.
- You are provided with a test_telemetry.cpp file which you can run as a preliminary check.
- You will finally be evaluated with a more rigorous hidden test file. 

### Tips:
- You should know how to chunk your data and put it back together in order
- You should implement some form of integrity check for your data
- You may use extra packets if needed

### Clarifications:
- Your decode_data function does not have context of the original string, all it gets is a list of packets from which it must reconstruct as well as verify the original string.
- Your outputs of the decode_data would either be {true, "original string"} or {false, ""}