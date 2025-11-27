#include "GameForm.h"

using namespace Game2048;

void GameForm::CreateGrid(int size)
{
	tableLayoutPanel1->RowStyles->Clear();
	tableLayoutPanel1->ColumnStyles->Clear();
	tableLayoutPanel1->Controls->Clear();

	tableLayoutPanel1->RowCount = size;
	tableLayoutPanel1->ColumnCount = size;

	for (int i = 0; i < size; i++) {
		tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 100.0f / size));
		tableLayoutPanel1->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100.0f / size));
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			Label^ lbl = gcnew Label();
			lbl->Dock = DockStyle::Fill;
			lbl->Font = gcnew Drawing::Font("Arial", tableLayoutPanel1->Width / size * 0.2f, FontStyle::Bold);
			lbl->TextAlign = ContentAlignment::MiddleCenter;
			lbl->Margin = System::Windows::Forms::Padding(0);
			lbl->BorderStyle = BorderStyle::FixedSingle;
			
			tableLayoutPanel1->Controls->Add(lbl, j, i);
		}
	}
}

void GameForm::MakeMove()
{
	int direction = userInteract.GetDirection();

	if (gameManager->CanMoveOrMerge(direction))
	{
		gameManager->SaveHistory();
		gameManager->MoveAllTiles(direction);
		gameManager->SaveDataToFile();

		UpdateGrid();
		UpdateScore();

		buttonRestart_Click(nullptr, nullptr);
	}
}

void GameForm::UpdateGrid()
{
	int size = gameManager->GetSize();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			Label^ lbl = (Label^)tableLayoutPanel1->GetControlFromPosition(j, i);

			int value = gameManager->GetValueOfTile(i, j);

			lbl->Text = (value == 0) ? "" : value.ToString();
			lbl->BackColor = GetTileColor(value);
		}
	}
}

void GameForm::UpdateScore()
{
	this->labelActualScore->Text = L"Ñ×¨Ò\r\n" + gameManager->GetScore().ToString();
	this->labelBestScore->Text = L"ÐÅÊÎÐÄ\r\n" + gameManager->GetBestScore().ToString();
}

Color GameForm::GetTileColor(int value)
{
	switch (value)
	{
	case 0: return Color::FromArgb(205, 193, 180); ; break;
	case 2: return Color::FromArgb(238, 228, 218); break;
	case 4: return Color::FromArgb(237, 224, 200); break;
	case 8: return Color::FromArgb(242, 177, 121); break;
	case 16: return Color::FromArgb(245, 149, 99); break;
	case 32: return Color::FromArgb(246, 124, 95); break;
	case 64: return Color::FromArgb(246, 94, 59); break;
	case 128: return Color::FromArgb(237, 207, 114); break;
	case 256: return Color::FromArgb(237, 204, 97); break;
	case 512: return Color::FromArgb(237, 200, 80); break;
	case 1024: return Color::FromArgb(237, 197, 63); break;
	case 2048: return Color::FromArgb(237, 194, 46); break;
	default: return Color::FromArgb(60, 58, 50); break;
	}
}

System::Void GameForm::buttonHome_Click(System::Object^ sender, System::EventArgs^ e)
{
	aldForm->Show();
	this->Close();
}

System::Void GameForm::buttonBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (gameManager->CanCancelMove())
	{
		gameManager->CancelMove();
		gameManager->SaveDataToFile();

		UpdateGrid();
		UpdateScore();
	}
}

System::Void GameForm::buttonRestart_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ message = "";

	if (sender == nullptr && gameManager->CheckWin()) {
		message = userInteract.GetMessage('w');
	}
	else if (sender == nullptr && gameManager->CheckGameOver()) {
		message = userInteract.GetMessage('l');
	}
	else if (sender != nullptr) {
		message = userInteract.GetMessage('r');
	}

	if (message != "")
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			message,
			"Êîíåö",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			int size = gameManager->GetSize();

			delete gameManager;
			gameManager = new GameManager(size);
			gameManager->SaveDataToFile();

			UpdateGrid();
			UpdateScore();
		}
	}
}

System::Void GameForm::GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	int direction;

	switch (e->KeyCode)
	{
	case Keys::W: direction = 0; break;
	case Keys::A: direction = 1; break;
	case Keys::S: direction = 2; break;
	case Keys::D: direction = 3; break;
	default: return;
	}

	userInteract.SetDirection(direction);

	MakeMove();
}

System::Void GameForm::GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (!aldForm->Visible)
	{
		Application::Exit();
	}
}