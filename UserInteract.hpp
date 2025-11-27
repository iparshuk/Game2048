#pragma once

ref class UserInteract
{
private:
	int direction;
	System::String^ youWin;
	System::String^ youLost;
	System::String^ question;
public:
	UserInteract();

	void SetDirection(int direction);
	int GetDirection();
	System::String^ GetMessage(char mess);
};