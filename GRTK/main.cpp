#include "stdafx.h"
#include "GRTKRequestHandler.h"

int main() {
	
	std::vector<std::thread *> threads(std::thread::hardware_concurrency());

	std::transform(threads.begin(), threads.end(), threads.begin(), [](std::thread *t) {
		
		return new std::thread([]() {
		
			uWS::Hub h;

			h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {

				GRTK::RequestHandler *requestHandler = new GRTK::RequestHandler(message);
				
				if (requestHandler->handle()) {
					ws->send(requestHandler->message);
				} else {
					ws->send("BAD REQUEST");
				}
			});

			if (!h.listen(3000, nullptr, uS::ListenOptions::REUSE_PORT)) {
				std::cout << "Failed to listen. PLease ensure port 3000 is open for the Gesture Recognition server to function properly." << std::endl;
			}
			h.run();
		});
	});

	std::for_each(threads.begin(), threads.end(), [](std::thread *t) {
		t->join();
	});
}
