#pragma once
//---------------------
#include "standard_includes.h"


//---------------------
//Declare here

void print_in_color(string s, int color_number);
void print_in_color(string s, string back_color_name, string text_color_name);
int color_picker(string back, string text);
void print_line_in_color(unsigned int space_count, string color_name);
void go_fullscreen();
void cls();
void pause();
void disable_ctrl_c();
void enable_ctrl_c();

void print_vasat(string s, string back, string text, int columns);

void delay(unsigned int mss);


//////////////////////////////PROPER EXIT ro bayad kaamel benevisam. akharin line

//SetConsoleCtrlHandler(CtrlHandler, TRUE);

//------------------
//Define here!

void print_in_color(string s, int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
	std::cout << s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


void print_in_color(string s, string back_color_name, string text_color_name)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_picker(back_color_name, text_color_name));
	std::cout << s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


int color_picker(string back, string text)
{
	int back_color_number = 0;
	int text_color_number = 7;

	if (back == "default" || back == "def") back_color_number = 0; else
		if (back == "black") back_color_number = 0; else
			if (back == "blue") back_color_number = 1; else
				if (back == "green") back_color_number = 2; else
					if (back == "aqua") back_color_number = 3; else
						if (back == "red") back_color_number = 4; else
							if (back == "purple") back_color_number = 5; else
								if (back == "yellow") back_color_number = 6; else
									if (back == "light gray") back_color_number = 7; else
										if (back == "gray") back_color_number = 8; else
											if (back == "light blue") back_color_number = 9; else
												if (back == "light green") back_color_number = 10; else
													if (back == "light aqua") back_color_number = 11; else
														if (back == "light red") back_color_number = 12; else
															if (back == "light purple") back_color_number = 13; else
																if (back == "light yellow") back_color_number = 14; else
																	if (back == "white") back_color_number = 15; else
																		back_color_number = 0;


	if (text == "default" || text == "def") text_color_number = 7; else
		if (text == "black") text_color_number = 0; else
			if (text == "blue") text_color_number = 1; else
				if (text == "green") text_color_number = 2; else
					if (text == "aqua") text_color_number = 3; else
						if (text == "red") text_color_number = 4; else
							if (text == "purple") text_color_number = 5; else
								if (text == "yellow") text_color_number = 6; else
									if (text == "light gray") text_color_number = 7; else
										if (text == "gray") text_color_number = 8; else
											if (text == "light blue") text_color_number = 9; else
												if (text == "light green") text_color_number = 10; else
													if (text == "light aqua") text_color_number = 11; else
														if (text == "light red") text_color_number = 12; else
															if (text == "light purple") text_color_number = 13; else
																if (text == "light yellow") text_color_number = 14; else
																	if (text == "white") text_color_number = 15; else
																		text_color_number = 7;



	return (back_color_number * 16) + text_color_number;
}


void print_line_in_color(unsigned int space_count, string color_name)
{
	for (unsigned int i = 0; i < space_count; i++)
		print_in_color(" ", color_name, color_name);
}


void go_fullscreen()
{
	//system("mode 650");
	//system("mode con COLS=700");
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	//SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void cls()
{
	system("cls");
}

void pause()
{
	system("pause");
}

void disable_ctrl_c()
{
	SetConsoleCtrlHandler(NULL, true);
}

void enable_ctrl_c()
{
	SetConsoleCtrlHandler(NULL, false);
}


void print_vasat(string s, string back, string text, int columns)
{
	int leftspace = (columns - int(s.length())) / 2;;
	for (int i = 0; i < leftspace;i++) cout << " ";
	print_in_color(s, back, text);
}



/////////////////////////////////////////////////////////

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
		// Handle the CTRL-C signal.
		case CTRL_C_EVENT:
			//printf("Ctrl-C event\n\n");
			Beep(750, 300);
			return 0;

			// CTRL-CLOSE: confirm that the user wants to exit.
		case CTRL_CLOSE_EVENT:
			Beep(600, 200);
			//printf("Ctrl-Close event\n\n");
			return 0;

			// Pass other signals to the next handler.
		case CTRL_BREAK_EVENT:
			Beep(900, 200);
			//printf("Ctrl-Break event\n\n");
			return 0;

		case CTRL_LOGOFF_EVENT:
			Beep(1000, 200);
			//printf("Ctrl-Logoff event\n\n");
			return 0;

		case CTRL_SHUTDOWN_EVENT:
			Beep(750, 500);
			//printf("Ctrl-Shutdown event\n\n");
			return 0;

		default:
			return 0;
	}
}


void GOT_theme()
{
	////
	Beep(720, 1050);
	Beep(500, 1050);

	Beep(550, 200);
	Beep(650, 200);
	Beep(720, 1000);
	Beep(500, 1050);

	Beep(620, 200);
	Beep(720, 200);
	Beep(620, 2050 - 50 - 50 - 50);
	delay(750);
	////
	Beep(720 - 50, 1050);
	Beep(500 - 50, 1050);

	Beep(550 - 50, 200);
	Beep(650 - 50, 200);
	Beep(720 - 50, 1000);
	Beep(500 - 50, 1050);
	Beep(720, 200);
	Beep(620 - 30, 200);
	Beep(620 - 30, 2050);
}



void delay(unsigned int mss)
{
	clock_t goal = mss + clock();
	while (goal > clock());
}