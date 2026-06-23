#include <LocINO/LocINOSerialClient.hpp>
#include <LocINO/LocINOCLI.hpp>
#include <LocINO/Types.hpp>
#include <chrono>
#include <thread>

int main() {
    LocINO::LocINOSerialClient client = LocINO::LocINOSerialClient("/dev/ttyACM1", 9600);
    LocINO::EventPacket event;

    while (true){
        client.listenRecord();
        while ((client.receiveEvent(event, 100))){
            LocINO::CLI::printEvent(event);   
        }
    }

}