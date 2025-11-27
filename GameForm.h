#pragma once

#include "GameManager.hpp"
#include "UserInteract.hpp"

namespace Game2048 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class GameForm : public System::Windows::Forms::Form
	{
	private:
		Form^ aldForm;
		GameManager* gameManager;
		UserInteract userInteract;
	public:
		void CreateGrid(int size);
		void MakeMove();
		void UpdateGrid();
		void UpdateScore();
		Color GetTileColor(int value);

	public:
		GameForm(int size, Form^ form)
		{
			InitializeComponent();

			gameManager = new GameManager(size);

			gameManager->LoadDataFromFile();
			CreateGrid(size);
			UpdateGrid();
			UpdateScore();

			gameManager->CheckWin();
			if (gameManager->CheckGameOver()) {
				buttonRestart_Click(nullptr, nullptr);
			}

			aldForm = form;
		}

	protected:
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
			if (gameManager)
			{
				delete gameManager;
			}
		}
	private: System::Windows::Forms::Button^ buttonBack;
	private: System::Windows::Forms::Button^ buttonRestart;
	private: System::Windows::Forms::Button^ buttonHome;
	private: System::Windows::Forms::Label^ labelActualScore;
	private: System::Windows::Forms::Label^ labelBestScore;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->buttonRestart = (gcnew System::Windows::Forms::Button());
			this->buttonHome = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->labelActualScore = (gcnew System::Windows::Forms::Label());
			this->labelBestScore = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonBack
			// 
			this->buttonBack->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonBack.BackgroundImage")));
			this->buttonBack->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonBack->Location = System::Drawing::Point(124, 12);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(50, 50);
			this->buttonBack->TabIndex = 0;
			this->buttonBack->UseVisualStyleBackColor = true;
			this->buttonBack->Click += gcnew System::EventHandler(this, &GameForm::buttonBack_Click);
			// 
			// buttonRestart
			// 
			this->buttonRestart->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonRestart.BackgroundImage")));
			this->buttonRestart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonRestart->Location = System::Drawing::Point(68, 12);
			this->buttonRestart->Name = L"buttonRestart";
			this->buttonRestart->Size = System::Drawing::Size(50, 50);
			this->buttonRestart->TabIndex = 1;
			this->buttonRestart->UseVisualStyleBackColor = true;
			this->buttonRestart->Click += gcnew System::EventHandler(this, &GameForm::buttonRestart_Click);
			// 
			// buttonHome
			// 
			this->buttonHome->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonHome.BackgroundImage")));
			this->buttonHome->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonHome->Location = System::Drawing::Point(12, 12);
			this->buttonHome->Name = L"buttonHome";
			this->buttonHome->Size = System::Drawing::Size(50, 50);
			this->buttonHome->TabIndex = 2;
			this->buttonHome->UseVisualStyleBackColor = true;
			this->buttonHome->Click += gcnew System::EventHandler(this, &GameForm::buttonHome_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				450)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 150);
			this->tableLayoutPanel1->MaximumSize = System::Drawing::Size(450, 450);
			this->tableLayoutPanel1->MinimumSize = System::Drawing::Size(450, 450);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->Size = System::Drawing::Size(450, 450);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// labelActualScore
			// 
			this->labelActualScore->BackColor = System::Drawing::Color::Khaki;
			this->labelActualScore->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelActualScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelActualScore->Location = System::Drawing::Point(180, 12);
			this->labelActualScore->Name = L"labelActualScore";
			this->labelActualScore->Size = System::Drawing::Size(125, 50);
			this->labelActualScore->TabIndex = 3;
			this->labelActualScore->Text = L"Ñ×¨Ò\r\n0";
			this->labelActualScore->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelBestScore
			// 
			this->labelBestScore->BackColor = System::Drawing::Color::Khaki;
			this->labelBestScore->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->labelBestScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelBestScore->Location = System::Drawing::Point(313, 12);
			this->labelBestScore->Name = L"labelBestScore";
			this->labelBestScore->Size = System::Drawing::Size(125, 50);
			this->labelBestScore->TabIndex = 4;
			this->labelBestScore->Text = L"ÐÅÊÎÐÄ\r\n0";
			this->labelBestScore->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LemonChiffon;
			this->ClientSize = System::Drawing::Size(450, 600);
			this->Controls->Add(this->labelBestScore);
			this->Controls->Add(this->labelActualScore);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->buttonHome);
			this->Controls->Add(this->buttonRestart);
			this->Controls->Add(this->buttonBack);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->Name = L"GameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"2048";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GameForm::GameForm_FormClosing);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonHome_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonRestart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	private: System::Void GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	};
}
