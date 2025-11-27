#include "UserInteract.hpp"

UserInteract::UserInteract()
{
	direction = -1;
	youWin = "Вы победили\n";
	youLost = "Вы проиграли\n";
	question = "Начать заново?";
}

void UserInteract::SetDirection(int direction)
{
	UserInteract::direction = direction;
}

int UserInteract::GetDirection()
{
	return direction;
}

System::String^ UserInteract::GetMessage(char mess)
{
	if (mess == 'w') {
		return youWin + question;
	}
	else if (mess == 'l') {
		return youLost + question;
	}
	else if (mess == 'r') {
		return question;
	}
}