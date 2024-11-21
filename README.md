# An attempt to build an autonomous drone

## Demo
https://github.com/PrathameshBhagat/Drone-Branches-Project/assets/90595097/4626cd12-0045-4e3d-8046-53edd3de42e9




# Note 
- The transmitter and reciver was ***programmed completely from scratch*** in JS & C++, saving ₹4K to ₹10K to make delivery of medicines and goods cost effective.


- The ***transmitter*** was self programmed by me and was just a vanilla J.S. page with two joysticks operated from a smart phone it self.

- The ***receiver*** was as well self programmed in C++ and executed by an ESP8266/ESP 32 board, just a web server, serving the J.S. page and providing the recieved pitch, yaw, roll values to the flight controller.

- The ***flight controller*** was an Arduino UNO R3 executing a third party C++ code provided by the YMFC-AL open source project, not getting an F.C. from the market added savings of atleast ₹5K to ₹15K. Totalling saving between ₹9K to ₹25K.

- Later the transmitter was served by a separate Python server to reduce the load on the tiny ESP8266 as it used to get really hot 🔥 and perform an auto reset and execute the code from the beginning.

- The drone isn't very stable cause the **PID (Proportional, Integral, Derivative)** values need to be tuned and lacking an aeronautics background made it difficult to tune those values.
  
# IMP

This repo unfortunately **lacks** clean code, comments and has snippets scattered in various files, making it difficult to get used to. So please consider contacting the developer a to get an overview of the project.

Please call +91 705-803-1648 or mail at prathameshbhagat0608@gmail.com.
