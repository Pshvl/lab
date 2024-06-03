#include "Server.h"
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <winsock2.h>
#include <fstream>
#include <string>
#include <chrono>
#include <sstream>
#include <vector>
#include <thread>
#include <cstdlib> // ƒл€ функций rand() и srand()
#include <sstream>


#pragma warning(disable: 4996)//дл€ inet_addr


int numberOfClients = 2;

using namespace System;
using namespace System::Windows::Forms;
SOCKET sListen;
SOCKADDR_IN addr;
int sizeOfAddr = sizeof(addr);



std::vector<SOCKET> clientSockets;
std::vector<int> clientLifetimes;
SOCKET Connections[100];
int connectionsCounter = 0;



const char* CD = "cd C:\\Users\\polin\\Documents\\GitHub\\LAB\\lab\\lr6\\x64\\Debug";
const char* START = "start C:\\Users\\polin\\Documents\\GitHub\\LAB\\lab\\lr6\\x64\\Debug\\lr6.exe";

 

void startClient()
{
	int command_not_execute = system(CD);
	if (command_not_execute)
	{
		std::cout << "Failed to start" << '\n';
		exit(1);
	}
	system(START);

}

System::Void Project2::MyForm::UpdateUI(System::String^ message) {
	// ќбновление пользовательского интерфейса с помощью полученного сообщени€
	label1->Text = message;
}



void sendRemainingTimeToClient(SOCKET clientSocket, int lifetime) {
	std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

	while (true) {
		std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
		std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
		int remainingTime = lifetime - elapsedTime.count();

		if (remainingTime <= 0) {
			std::string message = "Remaining time: Time is up.";
			int result = send(clientSocket, message.c_str(), message.length(), 0);
			break;
		}


		std::string message = "Remaining time: " + oss.str() + " seconds.";

		int result = send(clientSocket, message.c_str(), message.length(), 0);

		if (result == SOCKET_ERROR) {
			/*cout << "Error with sending remaining time to client." << endl;
			cout << "Error code: " << WSAGetLastError() << endl;*/
			break;
		}

		Sleep(1000); // Check remaining time every second until the connection ends
	}
}



void createAndConnect(SOCKET &sListen, SOCKADDR_IN &addr, int sizeofaddr, int amount_of_clients) {
	std::vector<int> clientLifetimes;
	srand(time(NULL));
	int max = 30;
	int min = 4;
	// «аполнение массива длительностей жизни клиентов
	for (int i = 0; i < amount_of_clients; ++i) {
		int clientLifetime = rand() % (max - min+ 1) + min;
		clientLifetimes.push_back(clientLifetime);
	}

	std::vector<SOCKET> clientSockets; // ¬ектор сокетов клиентов

	// «апуск процессов с соответствующей длительностью
	for (int i = 0; i < amount_of_clients; ++i) {
		startClient();
		SOCKET newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		if (newConnection == 0) {
			MessageBox::Show("Socket Connection Error");
			/*cout << "Socket Connection Error" << endl;*/
		}
		else {
			/*cout << "Client connected Successfully!" << endl;*/
			MessageBox::Show("Client connected Successfully!");

			if (clientLifetimes[i] > 0) {

				// ƒополнительна€ нить дл€ отправки оставшегос€ времени клиенту
				std::thread timeThread(sendRemainingTimeToClient, newConnection, clientLifetimes[i]);
				timeThread.detach();
			}

			clientSockets.push_back(newConnection);
		}
	}
}


System::Void Project2::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Project2::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	int numberOfClients = getSocketNumber(MyForm::input);
	MessageBox::Show(Convert::ToString(numberOfClients));
	MessageBox::Show("rrrrrr.\n");
	createAndConnect(sListen, addr, sizeof(addr), numberOfClients);
	return System::Void();
}


int Project2::MyForm::getSocketNumber(System::Windows::Forms::TextBox^ textBox) {
	int clientNumber = 1000;
	int min = 2; // ћинимальное значение изменено на 2
	int max = 5; // ћаксимальное значение изменено на 5
	try {
		clientNumber = System::Convert::ToInt32(textBox->Text);
		if (clientNumber < min || clientNumber > max) {
			throw gcnew System::Exception("Error: Input correct number of Clients (between 2 and 5)...");
		}
	}
	catch (System::Exception^ e) {
		MessageBox::Show(e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return -1; // ¬озвращаем -1 в случае ошибки
	}
	return clientNumber;
}

[STAThread]
int main(array<System::String^>^ args)
{
	WSAData wsaData; //создаем структуру дл€ загрузки
	WORD DLLVersion = MAKEWORD(2, 1); // ¬ерси€ библиотеки winsock
	MessageBox::Show("wsdata.\n");
	if (WSAStartup(DLLVersion, &wsaData) != 0) { // инициализаци€ библиотеки Winsock
		MessageBox::Show("getaddrinfo failed.\n");
		printf("Error: failed to link library.\n");
		return 1;
	}

	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); //сокет дл€ прослушивани€ соединений на указанном адресе и порту.
	MessageBox::Show("bin.\n");
	if (bind(sListen, (SOCKADDR*)&addr, sizeOfAddr) == SOCKET_ERROR) {//прив€зываетс€ адрес сокета к указанному IP и порту
		//прив€зка адреса сокету
		printf("Error bind %d\n", WSAGetLastError());
		closesocket(sListen);
		WSACleanup();
		return 1;
	} //запуск прослушивани€ на созданном сокете с максимальным размером очереди
	MessageBox::Show("listen.\n");
	if (listen(sListen, SOMAXCONN) == SOCKET_ERROR) {
		printf( "Listen failed;\n");
		closesocket(sListen);
		WSACleanup();
		return 1;
	}


    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project2::MyForm form;
    Application::Run(% form);


	
		
	return 0;
}
