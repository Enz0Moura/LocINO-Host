#include <LocINO/LocINOSerialClient.hpp>
#include <LocINO/LocINOCLI.hpp>
#include <LocINO/Types.hpp>

int main() {
    LocINO::LocINOSerialClient client("/dev/ttyACM0", 9600);
    LocINO::EventPacket event;

    client.listenRecord();

    while (client.receiveEvent(event)){
        LocINO::CLI::printEvent(event);
        client.listenRecord();
    }

}