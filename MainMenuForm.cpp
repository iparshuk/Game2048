#include "MainMenuForm.h"
#include "GameForm.h"

#include "random"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Game2048::MainMenuForm());

	return 0;
}

using namespace Game2048;
using namespace std;

void MainMenuForm::HighlightButton(Button^ sender)
{
	button4x4->BackColor = Color::FromArgb(240, 228, 218);
	button5x5->BackColor = Color::FromArgb(240, 228, 218);
	button6x6->BackColor = Color::FromArgb(240, 228, 218);
	button8x8->BackColor = Color::FromArgb(240, 228, 218);

	sender->BackColor = Color::FromArgb(243, 177, 107);
}

System::Void MainMenuForm::sizeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sender == button4x4) {
		size = 4;
	}
	else if (sender == button5x5) {
		size = 5;
	}
	else if (sender == button6x6) {
		size = 6;
	}
	else if (sender == button8x8) {
		size = 8;
	}
	HighlightButton(dynamic_cast<Button^>(sender));
}

System::Void MainMenuForm::startButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (size != 0) {
		GameForm^ game = gcnew GameForm(size, this);
		this->Hide();
		game->Show();
	}
}