#pragma once
#include "Gameplay.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace cli;

// ���� ������� ����� ���
public ref class ORDNCHS : public System::Windows::Forms::Form
{
private:
	// ������������� ��� ����
	enum class Theme
	{
		Light,
		Dark
	};

	Panel^ panel1; // ������ ��� ���
	Label^ turnLabel; // ������ � ����������� ��� �������� ���
	Theme currenttheme = Theme::Dark; // ������� ���� ���
	Button^ themebutton; // ������ ��� ���� ����
	MenuStrip^ menuStrip1; // ����
	ToolStripMenuItem^ ��������������ToolStripMenuItem; // ����� ���� "������ ��������"
	ToolStripMenuItem^ �����������ToolStripMenuItem; // ����� ���� "�������� ���"

public:
	Panel^ ORDNCHS::GetPanel()
	{
		return panel1;
	}

	// �����������
	ORDNCHS(void)
	{
		InitializeComponent();

		// ����������� ����� ���
		panel1 = gcnew Panel();
		panel1->Size = Drawing::Size(301, 301);
		int centerX = (this->ClientSize.Width - panel1->Size.Width) / 2;
		int centerY = (this->ClientSize.Height - panel1->Size.Height) / 2;
		panel1->Location = Drawing::Point(centerX, centerY);
		this->Controls->Add(panel1);
		panel1->Paint += gcnew PaintEventHandler(this, &ORDNCHS::gamepanel_Paint);
		panel1->MouseClick += gcnew MouseEventHandler(this, &ORDNCHS::gamepanel_MouseClick);
		panel1->BackColor = Color::SlateGray;

		// ����������� ������� ��� �������� ���
		turnLabel = gcnew Label();
		turnLabel->Text = "����� ������ ������� 1 (�������)";
		turnLabel->ForeColor = Color::White;
		turnLabel->Dock = DockStyle::Bottom; // ��������� ������� ��� �������
		this->Controls->Add(turnLabel);
	}

	// ������� ��� ���� ����
	void Switch_theme()
	{
		if (currenttheme == Theme::Light)
		{
			currenttheme = Theme::Dark;
			this->BackColor = System::Drawing::Color::FromArgb(51, 51, 51);
			panel1->BackColor = System::Drawing::Color::SlateGray;
			turnLabel->ForeColor = System::Drawing::Color::White;
		}
		else
		{
			currenttheme = Theme::Light;
			this->BackColor = Color::Linen;
			panel1->BackColor = Color::LightCyan;
			turnLabel->ForeColor = Color::Black;
		}
	}

	// ������� ��� ��������� ������� ��� �������� ���
	void PlayerTurn(Gameplay gameplay)
	{
		if (gameplay.GetTurn())
		{
			turnLabel->Text = "����� ������ ������� 1 (�������)";
		}
		else
		{
			turnLabel->Text = "����� ������ ������� 2 (����)";
		}
	}

protected:
	// ����������
	~ORDNCHS()
	{
		if (components)
		{
			delete components;
		}
	}

private:
	System::ComponentModel::Container^ components;

	// �����, ��������� ����������� ���������� Windows Form
#pragma region Windows Form Designer generated code
	void InitializeComponent(void)
	{
		this->themebutton = (gcnew System::Windows::Forms::Button());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
		this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->menuStrip1->SuspendLayout();
		this->SuspendLayout();
		// 
		// themebutton
		// 
		this->themebutton->FlatAppearance->BorderColor = System::Drawing::Color::White;
		this->themebutton->FlatStyle = System::Windows::Forms::FlatStyle::System;
		this->themebutton->Location = System::Drawing::Point(382, 436);
		this->themebutton->Name = L"themebutton";
		this->themebutton->Size = System::Drawing::Size(48, 36);
		this->themebutton->TabIndex = 0;
		this->themebutton->TabStop = false;
		this->themebutton->Text = L"Switch Theme";
		this->themebutton->UseVisualStyleBackColor = true;
		this->themebutton->Click += gcnew System::EventHandler(this, &ORDNCHS::SwitchTheme);
		// 
		// menuStrip1
		// 
		this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
			this->��������������ToolStripMenuItem,
				this->�����������ToolStripMenuItem
		});
		this->menuStrip1->Location = System::Drawing::Point(0, 0);
		this->menuStrip1->Name = L"menuStrip1";
		this->menuStrip1->Size = System::Drawing::Size(442, 24);
		this->menuStrip1->TabIndex = 1;
		this->menuStrip1->Text = L"menuStrip1";
		// 
		// ��������������ToolStripMenuItem
		// 
		this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
		this->��������������ToolStripMenuItem->Size = System::Drawing::Size(113, 20);
		this->��������������ToolStripMenuItem->Text = L"������ ��������";
		this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &ORDNCHS::��������������ToolStripMenuItem_Click);

		// 
		// �����������ToolStripMenuItem
		// 
		this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
		this->�����������ToolStripMenuItem->Size = System::Drawing::Size(94, 20);
		this->�����������ToolStripMenuItem->Text = L"�������� ���";
		this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &ORDNCHS::�����������ToolStripMenuItem_Click);

		// 
		// ORDNCHS
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
			static_cast<System::Int32>(static_cast<System::Byte>(51)));
		this->ClientSize = System::Drawing::Size(442, 484);
		this->Controls->Add(this->themebutton);
		this->Controls->Add(this->menuStrip1);
		this->MainMenuStrip = this->menuStrip1;
		this->Name = L"ORDNCHS";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"ORDNCHS";
		this->Load += gcnew System::EventHandler(this, &ORDNCHS::ORDNCHS_Load);
		this->menuStrip1->ResumeLayout(false);
		this->menuStrip1->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();
	}
#pragma endregion	
private:
	// ������, �� ���������� �� ��䳿 �������� ���������
	Void gamepanel_Paint(Object^ sender, PaintEventArgs^ e);
	Void gamepanel_MouseClick(Object^ sender, MouseEventArgs^ e);
	void ORDNCHS::SwitchTheme(Object^ sender, EventArgs^ e);
	Void ��������������ToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
	Void �����������ToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
	Void ORDNCHS_Load(System::Object^ sender, System::EventArgs^ e);
};