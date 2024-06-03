#include "client.h"

#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include<winsock2.h>
#pragma warning(disable: 4996)//��� inet_addr


using namespace System;
using namespace System::Windows::Forms;

void getLifeTime(SOCKET Connection)
{
	char buffer[1024] = { 0 };
	std::cout << "Waiting\n" << std::endl;

	while (recv(Connection, (char*)&buffer, 1024, NULL) > 0) {
		std::cout << buffer << std::endl;
		memset(buffer, 0, sizeof(buffer));
	}
}

[STAThread]
int main(array<System::String^>^ args) {
	setlocale(LC_ALL, "Russian");
	//�������� ����������
	WSAData wsaData; //������� ��������� ��� ��������
	WORD DLLVersion = MAKEWORD(2, 1); //������������� ������ ���������� winsock
	if (WSAStartup(DLLVersion, &wsaData) != 0) { //�������� ����������� ����������
		/*cerr << "Error: failed to link library.\n";*/
		return 1;
	}

	//��������� ���������� �� ������ ������
	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //�����
	addr.sin_port = htons(1111); //����
	addr.sin_family = AF_INET; //��������� ����������
	int sizeofaddr = sizeof(addr);

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	//����� ��� ������������� �����
	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	// ��������� �� ����������� � �������
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr))) {
		MessageBox::Show("Error: failed connect to the server.\n");
		/*cerr << "Error: failed connect to the server.\n";*/
		return 1;
	}

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm1 form;
	Application::Run(% form);

	getLifeTime(Connection);
	/*cout << "Server has been stopped\n";*/
	MessageBox::Show("Server has been stopped\n");
	if (closesocket(Connection) == SOCKET_ERROR)
		/*cerr << "Failed to terminate connection.\n Error code: " << WSAGetLastError();*/
		MessageBox::Show("Failed to terminate connection.\n");
	WSACleanup();
	/*cout << "Correct exit done\n";*/
	MessageBox::Show("Correct exit done\n");
	return 0;
}

