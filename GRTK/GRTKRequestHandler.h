namespace GRTK {
	enum RequestType
	{
		Predict,
		Train,
		Unknown
	};
	class RequestHandler
	{
	public:
		RequestType requestType;
		int opCode;
		int responseLength;
		const char * message;
		bool handle();
		RequestHandler(char *message);
		~RequestHandler();
	private:
		void trainModel();
		void predictGesture();
	};
}


