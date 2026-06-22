#include <LocINO/LocINOSerialClient.hpp>
#include <LocINO/LocINOCLI.hpp>
#include <LocINO/Types.hpp>
#include <chrono>

int main() {
    LocINO::LocINOSerialClient client("/dev/ttyACM0", 9600);
    LocINO::EventPacket event;

    while (true){
        
        auto packet = LocINO::LoRaPacket::fromText("Hello, World!");
        client.sendMessage(packet);

        while (client.receiveEvent(event)){
            LocINO::CLI::printEvent(event);
            if (event.type == LocINO::CpuEventType::LoRaTxOk) break;
        }
        std::chrono::seconds(10);
    
    }
}