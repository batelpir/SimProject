# Flight Simulator Project
Flight Simulator is a cpp program that controls an airplane in Flight Gear game which is a free, open source multi-platform.
This program provides the option to fly planes , take off, land and simulate various aircraft faults.
## About The Project
The program acts as both Client and Server sides.\
**Client Side** - It parses the commands from fly.txt file and connects as Client to the simulaltor, as long as there are new commands, 
it sends them to the simulator and changes the airplain's behavior accordingly.\
**Server Side** - It creates a server which listens to new clients, parses the recieved data from the simulator and updates it in the corresponding data structures. 

## Prerequisites
Linux environment for running the code.
## Installation
### Windows Users:
Install [FlightGear](https://sourceforge.net/projects/flightgear/files/) to install Flight Simulator.
### Dualboot Users(Ubuntu):
Install *FlightGear* from the app store (software center) provided by Ubuntu.


## Setting FlightGear Simulator
1. Add *generic_small.xml* file in the FlightGear Game Folder : *game/flightgear/Protocol*. 
   The file is located in the project directory (in GitHub).
2. Open the FlightGear app and go to *settings>Additional Settings* and add the following commands:
```
    --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
    --telnet=socket,in,10,127.0.0.1,5402,tcp
```

## Steps For Executing The Program
1. Download the code from this repository.
2. Enter the directory which has the code in it.
3. Compile the code by running the folowing command
```
    g++ -std=c++11 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
```
4. Run the program by running the following command
```
    ./a.out fly.txt
```
5. Open Flight Gear game (which was downloaded before) and click *Fly!*
