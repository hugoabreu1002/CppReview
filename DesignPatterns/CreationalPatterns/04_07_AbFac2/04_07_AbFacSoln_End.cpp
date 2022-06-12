// 04_07_AbFacSoln_Start.cpp 
//

#include "stdafx.h"
#include <iostream>
#include <GL/glut.h>


using namespace std;

class HANDLE{
	
};

void SetConsoleBackgGroundAttribute(HANDLE hconsole, float red, float green, float blue){
	glClearColor(red, green, blue, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void SetConsoleTextAttribute(HANDLE hconsole, char color){
	switch (color)
	{
	case 'k':
		cout << "\030[1;31mTheoreccally changed to black\033[0m\n";
		break;
	case 'r':
		cout << "\031[1;31mTheoreccally changed to black\033[0m\n";
		break;
	case 'g':
		cout << "\032[1;31mTheoreccally changed to black\033[0m\n";
		break;
	case 'y':
		cout << "\033[1;31mTheoreccally changed to black\033[0m\n";
		break;
	case 'b':
		cout << "\034[1;31mTheoreccally changed to black\033[0m\n";
		break;
	case 'm':
		cout << "\035[1;31mTheoreccally changed to black\033[0m\n";
		break;
	case 'c':
		cout << "\036[1;31mTheoreccally changed to black\033[0m\n";
		break;
	case 'w':
		cout << "\037[1;31mTheoreccally changed to black\033[0m\n";
		break;
	
	default:
		break;
	}

}

#pragma region Backgrounds
// Base Background class
class Background
{
protected:
	char _theme[10];
public:
	Background()
	{
	}
	virtual void getTheme() = 0;
};

// Derived Light Background class
class LightBkgd : public Background
{
public:
	LightBkgd(HANDLE hConsole)
	{
		SetConsoleBackgGroundAttribute(hConsole, 0.9,0.9,0.9);
		cout << "Making the background white" << endl;
		strcpy(_theme, "light");
	}
	void getTheme()
	{
		cout << "This is a part of the light theme" << endl;
	}
};

// Derived Dark Background class
class DarkBkgd : public Background
{
public:
	DarkBkgd(HANDLE hConsole)
	{
		SetConsoleBackgGroundAttribute(hConsole, 0.1,0.1,0.1);
		cout << "Making the background black" << endl;
		strcpy(_theme, "dark");
	}
	void getTheme()
	{
		cout << "This is a part of the dark theme" << endl;
	}
};
#pragma endregion Background

#pragma region Text
// Base Text class
class Text
{
protected:
	char _theme[10];
public:
	Text()
	{
	}
	virtual void message(HANDLE hConsole) = 0;
};

// Derived Black Text class
class BlackText : public Text
{
public:
	BlackText(HANDLE hConsole)
	{
		SetConsoleTextAttribute(hConsole, 'k');
		strcpy(_theme, "light");
		cout << "Making the text black" << endl;
	}
	void message(HANDLE hConsole)
	{
		SetConsoleTextAttribute(hConsole, 'w');
		cout << "This is the default font from the light theme" << endl;
	}
};

// Derived White Text class
class WhiteText : public Text
{
public:
	WhiteText(HANDLE hConsole)
	{
		SetConsoleTextAttribute(hConsole, 'w');
		strcpy(_theme, "dark");
		cout << "Making the text white" << endl;
	}
	void message(HANDLE hConsole)
	{
		SetConsoleTextAttribute(hConsole, 'y');
		cout << "This is the default font for the dark theme" << endl;
	}
};

// Derived Dark Green Text class
class DarkGreenText : public Text
{
public:
	DarkGreenText(HANDLE hConsole)
	{
		SetConsoleTextAttribute(hConsole, 'g');
		cout << "Making the text dark green" << endl;
	}
	void message(HANDLE hConsole)
	{
		SetConsoleTextAttribute(hConsole, 'g');
		cout << "This is the green font for the light theme" << endl;
	}
};

// Derived Light Green Text class
class LightGreenText : public Text
{
public:
	LightGreenText(HANDLE hConsole)
	{
		SetConsoleTextAttribute(hConsole, 'g');
		cout << "Making the text light green" << endl;
	}
	void message(HANDLE hConsole)
	{
		SetConsoleTextAttribute(hConsole, 'g');
		cout << "This is the green font for the dark theme" << endl;
	}
};
#pragma endregion Text

#pragma region Factories
// Base Factory
class ThemeFactory
{
public:
	virtual Background* setBackground(HANDLE hConsole) = 0;
	virtual Text* getDefaultText(HANDLE hConsole) = 0;
	virtual Text* getGreenText(HANDLE hConsole) = 0;
};

// Derived Light Theme Factory which pairs the white background with darker text
class LightFactory : public ThemeFactory
{
public:
	Background * setBackground(HANDLE hConsole)
	{
		return new LightBkgd(hConsole);
	}
	Text * getDefaultText(HANDLE hConsole)
	{
		return new BlackText(hConsole);
	}
	Text * getGreenText(HANDLE hConsole)
	{
		return new DarkGreenText(hConsole);
	}
};

// Derived Dark Theme Factory which pairs the black background with lighter text
class DarkFactory : public ThemeFactory
{
public:
	Background * setBackground(HANDLE hConsole)
	{
		return new DarkBkgd(hConsole);
	}
	Text * getDefaultText(HANDLE hConsole)
	{
		return new WhiteText(hConsole);
	}
	Text * getGreenText(HANDLE hConsole)
	{
		return new LightGreenText(hConsole);
	}
};
#pragma endregion Factories

void pause(){
   cin.get();
}

int main()
{
	// Configure console variables and colours
	HANDLE  hConsole;
	SetConsoleTextAttribute(hConsole, 30);

	ThemeFactory* app;
	int choice;

	cout << "Select a theme: " << endl;
	cout << "1: Light" << endl;
	cout << "2: Dark" << endl;
	cout << "Selection: ";
	cin >> choice;
	cout << endl;

	// Initiate the correct factory based on user input
	switch (choice)
	{
	case 1:
		app = new LightFactory;
		break;
	case 2:
		app = new DarkFactory;
		break;
	default:
		cout << "Invalid Selection" << endl;
		app = NULL;
		break;
	}

	// Get the correct objects based on factory selected
	if (app != NULL)
	{
		Background* appBkgd = app->setBackground(hConsole);
		Text *appDefaultText = app->getDefaultText(hConsole);
		Text *appGreenText = app->getGreenText(hConsole);

		appDefaultText->message(hConsole);
		appGreenText->message(hConsole);
	}

	cout << endl;
	pause();
}