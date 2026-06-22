#include <LocINO/LocINOSerialClient.hpp>
#include <LocINO/LocINOCLI.hpp>
#include <LocINO/Types.hpp>
#include <chrono>

int main() {
    LocINO::LocINOSerialClient client("/dev/ttyACM0", 9600);
    LocINO::EventPacket event;
    while (true){
        while ((client.receiveEvent(event)) && (event.type == LocINO::CpuEventType::LoRaRx)){
            LocINO::CLI::printEvent(event);
            client.listenRecord();
        }
        std::chrono::seconds(3);
    }

}