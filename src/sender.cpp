#include <LocINO/LocINOSerialClient.hpp>
#include <LocINO/LocINOCLI.hpp>
#include <LocINO/Types.hpp>
#include <chrono>
#include <thread>

int main() {
    LocINO::LocINOSerialClient client = LocINO::LocINOSerialClient("/dev/ttyACM1", 9600);
    LocINO::EventPacket event;
    

    int txCount = 0;

    while (true) {
        std::cout << "Sending #" << ++txCount << std::endl;
        auto packet = LocINO::LoRaPacket::fromText("Hello, World!");

        client.sendMessage(packet);

        while ((client.receiveEvent(event, 200)) ) {
            LocINO::CLI::printEvent(event);
        }

        //std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}