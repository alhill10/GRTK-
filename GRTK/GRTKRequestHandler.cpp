#include "stdafx.h"
#include "GRTKRequestHandler.h"
#include <GRT.h>


namespace GRTK {

	RequestHandler::RequestHandler(char *message) 
	{
		if (sizeof(message) > 0) {

			std::string messageString = std::string(message);

			this->responseLength = 0;

			this->requestType = Unknown;

			if (messageString.find("PREDICT-") == 0) {
				this->requestType = Predict;
				this->opCode = 200;
			}

			if (messageString.find("TRAIN-") == 0) {
				this->requestType = Train;
				this->opCode = 200;
			}

		}
		else {
			this->responseLength = 0;
			this->requestType = Unknown;
			this->opCode = 400;
		}
	}

	bool RequestHandler::handle() 
	{

		if (this->requestType == Predict) {
			this->message = "PREDICTING";
		}

		if (this->requestType == Train) {
			this->message = "TRAINING";
		}

		if (this->requestType == Unknown) {
			this->message == "UNKNOWN REQUEST";
			return false;
		}

		this->responseLength = sizeof(this->message);

		return true;
	}

	RequestHandler::~RequestHandler()
	{

	}

	void RequestHandler::predictGesture() 
	{

	}

	void RequestHandler::trainModel() 
	{

	}
}
