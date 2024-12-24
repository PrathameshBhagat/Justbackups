# Attempt to build an autonomous drone

## Demo
https://github.com/PrathameshBhagat/Drone-Branches-Project/assets/90595097/4626cd12-0045-4e3d-8046-53edd3de42e9




# Note 
- The transmitter and reciver was ***programmed completely from scratch*** in JavaScript(J.S.) & C++, saving ₹4K to ₹10K to make delivery of medicines and goods cost effective and efficient with lowest carbon footprint.


- The ***transmitter*** was self programmed by me and was just a vanilla J.S. page with two joysticks operated from a smart phone it self.

- The ***receiver*** was as well self programmed in C++ and executed by a [Node MCU](https://en.m.wikipedia.org/wiki/NodeMCU), just a web server, serving the J.S. page and providing the recieved pitch, yaw, roll values to the flight controller.

- The ***flight controller*** was an [Arduino UNO R3](https://docs.arduino.cc/hardware/uno-rev3/) executing a third party C++ code provided by the YMFC-AL open source project. Not getting a traditional F.C. from the market added savings of atleast ₹5K to ₹15K. Totalling saving between ₹9K to ₹25K.

- Later the **transmitter** was served by a separate Python server to reduce the load on the tiny [Node MCU](https://en.m.wikipedia.org/wiki/NodeMCU), it used to get really hot 🔥 and hence causing an auto reset, resulting in execution of the code from the beginning of the program (which mid flight could have caused a lot of damage).

- The drone isn't very stable cause the **PID (Proportional, Integral, Derivative)** values need to be tuned and lacking an aeronautics background made it difficult to tune those values.
  
# IMP

This repo unfortunately **lacks** clean code, comments and has snippets scattered in various files, making it difficult to get used to. So please consider contacting the developer a to get an overview of the project.


## Contact 
For further details contact the developer:-  
   
**Name:**&emsp; &emsp; Prathamesh Bhagat  
**Phone:**&emsp; &emsp; +91 705-803-1648  
**Email:**&emsp; &emsp; &emsp; [prathameshbhagat0608@gmail.com](mailto:prathameshbhagat0608@gmail.com)  
**Website:**&emsp; &emsp; [https://prathameshbhagat.github.io](https://prathameshbhagat.github.io)  
**Linkedin:**&emsp; &emsp; [https://linkedin.com/in/prathameshvivekbhagat/](https://linkedin.com/in/prathameshvivekbhagat/)    
**What's App:**&emsp; [https://wa.me/917058031648](https://wa.me/917058031648)
