#pragma once

namespace Game2048 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	private:
		int size;
	public:
		void HighlightButton(Button^ selected);

	public:
		MainMenuForm(void)
		{
			InitializeComponent();
			size = 0;
		}

	protected:
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button4x4;
	private: System::Windows::Forms::Button^ button5x5;
	private: System::Windows::Forms::Button^ button6x6;
	private: System::Windows::Forms::Button^ button8x8;
	private: System::Windows::Forms::Button^ startButton;
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->button4x4 = (gcnew System::Windows::Forms::Button());
			this->button5x5 = (gcnew System::Windows::Forms::Button());
			this->button6x6 = (gcnew System::Windows::Forms::Button());
			this->button8x8 = (gcnew System::Windows::Forms::Button());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button4x4
			// 
			this->button4x4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4x4->Location = System::Drawing::Point(46, 63);
			this->button4x4->Name = L"button4x4";
			this->button4x4->Size = System::Drawing::Size(150, 50);
			this->button4x4->TabIndex = 0;
			this->button4x4->Text = L"4x4";
			this->button4x4->UseVisualStyleBackColor = true;
			this->button4x4->Click += gcnew System::EventHandler(this, &MainMenuForm::sizeButton_Click);
			// 
			// button5x5
			// 
			this->button5x5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5x5->Location = System::Drawing::Point(234, 63);
			this->button5x5->Name = L"button5x5";
			this->button5x5->Size = System::Drawing::Size(150, 50);
			this->button5x5->TabIndex = 1;
			this->button5x5->Text = L"5x5";
			this->button5x5->UseVisualStyleBackColor = true;
			this->button5x5->Click += gcnew System::EventHandler(this, &MainMenuForm::sizeButton_Click);
			// 
			// button6x6
			// 
			this->button6x6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6x6->Location = System::Drawing::Point(46, 134);
			this->button6x6->Name = L"button6x6";
			this->button6x6->Size = System::Drawing::Size(150, 50);
			this->button6x6->TabIndex = 2;
			this->button6x6->Text = L"6x6";
			this->button6x6->UseVisualStyleBackColor = true;
			this->button6x6->Click += gcnew System::EventHandler(this, &MainMenuForm::sizeButton_Click);
			// 
			// button8x8
			// 
			this->button8x8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8x8->Location = System::Drawing::Point(234, 134);
			this->button8x8->Name = L"button8x8";
			this->button8x8->Size = System::Drawing::Size(150, 50);
			this->button8x8->TabIndex = 3;
			this->button8x8->Text = L"8x8";
			this->button8x8->UseVisualStyleBackColor = true;
			this->button8x8->Click += gcnew System::EventHandler(this, &MainMenuForm::sizeButton_Click);
			// 
			// startButton
			// 
			this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->startButton->Location = System::Drawing::Point(141, 244);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(150, 50);
			this->startButton->TabIndex = 4;
			this->startButton->Text = L"Играть";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &MainMenuForm::startButton_Click);
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LemonChiffon;
			this->ClientSize = System::Drawing::Size(434, 561);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->button8x8);
			this->Controls->Add(this->button6x6);
			this->Controls->Add(this->button5x5);
			this->Controls->Add(this->button4x4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainMenuForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"2048";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void sizeButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
