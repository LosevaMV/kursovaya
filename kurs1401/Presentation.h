#pragma once

namespace kurs1401 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Presentation
	/// </summary>
	public ref class Presentation : public System::Windows::Forms::Form
	{
	public:
		Presentation(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Presentation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBoxStyle;
	private: System::Windows::Forms::ComboBox^ comboBoxAlign;


	private: System::Windows::Forms::ComboBox^ comboBoxFont;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownText;




	private: System::Windows::Forms::Button^ buttonTextColor;
	private: System::Windows::Forms::Button^ buttonMark;

	private: System::Windows::Forms::Button^ buttonPrevious;
	private: System::Windows::Forms::Button^ buttonNext;












	private: System::Windows::Forms::TextBox^ activeTextBox = nullptr;
	private: System::Drawing::Point startPoint;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::FontDialog^ fontDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::ListBox^ listBoxSlides;
	private: System::Windows::Forms::Panel^ panelSlide;
	private: System::Windows::Forms::TextBox^ textBoxContent;

	private: System::Windows::Forms::TextBox^ textBoxTitle;
	private: System::Windows::Forms::PictureBox^ pictureBoxBackground;
	private: System::Drawing::Point startLocation;
		   bool isResizing;
		   System::Drawing::Point mouseDownPos;
		   int initialWidth;













	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Presentation::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listBoxSlides = (gcnew System::Windows::Forms::ListBox());
			this->buttonMark = (gcnew System::Windows::Forms::Button());
			this->buttonTextColor = (gcnew System::Windows::Forms::Button());
			this->numericUpDownText = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBoxStyle = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxAlign = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxFont = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonPrevious = (gcnew System::Windows::Forms::Button());
			this->buttonNext = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->panelSlide = (gcnew System::Windows::Forms::Panel());
			this->textBoxContent = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTitle = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxBackground = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownText))->BeginInit();
			this->panelSlide->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBackground))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����ToolStripMenuItem,
					this->�����ToolStripMenuItem, this->��������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1248, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->���������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(69, 29);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(200, 34);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Presentation::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(200, 34);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Presentation::���������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->��������ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->������������ToolStripMenuItem
			});
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(77, 29);
			this->�����ToolStripMenuItem->Text = L"�����";
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->������ToolStripMenuItem,
					this->������ToolStripMenuItem
			});
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(232, 34);
			this->��������ToolStripMenuItem->Text = L"��������";
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->��������������ToolStripMenuItem,
					this->��������������������ToolStripMenuItem
			});
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(223, 34);
			this->������ToolStripMenuItem->Text = L"������";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(326, 34);
			this->��������������ToolStripMenuItem->Text = L"���������+�����";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Presentation::��������������ToolStripMenuItem_Click);
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(326, 34);
			this->��������������������ToolStripMenuItem->Text = L"���������+�����������";
			this->��������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Presentation::��������������������ToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(223, 34);
			this->������ToolStripMenuItem->Text = L"������ �����";
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Presentation::������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(232, 34);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Presentation::�������ToolStripMenuItem_Click);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(232, 34);
			this->������������ToolStripMenuItem->Text = L"��������� ���";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Presentation::������������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(118, 29);
			this->��������ToolStripMenuItem->Text = L"�����-���";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Presentation::��������ToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->listBoxSlides);
			this->groupBox1->Controls->Add(this->buttonMark);
			this->groupBox1->Controls->Add(this->buttonTextColor);
			this->groupBox1->Controls->Add(this->numericUpDownText);
			this->groupBox1->Controls->Add(this->comboBoxStyle);
			this->groupBox1->Controls->Add(this->comboBoxAlign);
			this->groupBox1->Controls->Add(this->comboBoxFont);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(0, 30);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1248, 127);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"������ ������������";
			// 
			// listBoxSlides
			// 
			this->listBoxSlides->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxSlides->FormattingEnabled = true;
			this->listBoxSlides->ItemHeight = 20;
			this->listBoxSlides->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->listBoxSlides->Location = System::Drawing::Point(1001, 13);
			this->listBoxSlides->Name = L"listBoxSlides";
			this->listBoxSlides->Size = System::Drawing::Size(120, 84);
			this->listBoxSlides->TabIndex = 12;
			this->listBoxSlides->SelectedIndexChanged += gcnew System::EventHandler(this, &Presentation::listBoxSlides_SelectedIndexChanged);
			// 
			// buttonMark
			// 
			this->buttonMark->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMark->Location = System::Drawing::Point(813, 29);
			this->buttonMark->Name = L"buttonMark";
			this->buttonMark->Size = System::Drawing::Size(75, 75);
			this->buttonMark->TabIndex = 10;
			this->buttonMark->Text = L"-";
			this->buttonMark->UseVisualStyleBackColor = true;
			this->buttonMark->Click += gcnew System::EventHandler(this, &Presentation::buttonMark_Click);
			// 
			// buttonTextColor
			// 
			this->buttonTextColor->Location = System::Drawing::Point(587, 29);
			this->buttonTextColor->Name = L"buttonTextColor";
			this->buttonTextColor->Size = System::Drawing::Size(75, 75);
			this->buttonTextColor->TabIndex = 8;
			this->buttonTextColor->Text = L"������� ���� ������";
			this->buttonTextColor->UseVisualStyleBackColor = true;
			this->buttonTextColor->Click += gcnew System::EventHandler(this, &Presentation::buttonTextColor_Click);
			// 
			// numericUpDownText
			// 
			this->numericUpDownText->Location = System::Drawing::Point(295, 71);
			this->numericUpDownText->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownText->Name = L"numericUpDownText";
			this->numericUpDownText->Size = System::Drawing::Size(120, 21);
			this->numericUpDownText->TabIndex = 7;
			this->numericUpDownText->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownText->ValueChanged += gcnew System::EventHandler(this, &Presentation::numericUpDownText_ValueChanged);
			// 
			// comboBoxStyle
			// 
			this->comboBoxStyle->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBoxStyle->FormattingEnabled = true;
			this->comboBoxStyle->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"�������", L"������", L"���������", L"������������" });
			this->comboBoxStyle->Location = System::Drawing::Point(24, 70);
			this->comboBoxStyle->Name = L"comboBoxStyle";
			this->comboBoxStyle->Size = System::Drawing::Size(204, 23);
			this->comboBoxStyle->TabIndex = 6;
			this->comboBoxStyle->Text = L"�������� ����������";
			this->comboBoxStyle->SelectedIndexChanged += gcnew System::EventHandler(this, &Presentation::comboBoxStyle_SelectedIndexChanged);
			// 
			// comboBoxAlign
			// 
			this->comboBoxAlign->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBoxAlign->FormattingEnabled = true;
			this->comboBoxAlign->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"�� ������", L"�� ������ ����", L"�� ������� ����" });
			this->comboBoxAlign->Location = System::Drawing::Point(254, 29);
			this->comboBoxAlign->Name = L"comboBoxAlign";
			this->comboBoxAlign->Size = System::Drawing::Size(204, 23);
			this->comboBoxAlign->TabIndex = 5;
			this->comboBoxAlign->Text = L"������������";
			this->comboBoxAlign->SelectedIndexChanged += gcnew System::EventHandler(this, &Presentation::comboBoxAlign_SelectedIndexChanged);
			// 
			// comboBoxFont
			// 
			this->comboBoxFont->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBoxFont->FormattingEnabled = true;
			this->comboBoxFont->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Times New Roman", L"Courier New", L"Tw Cen MT",
					L"Tw Cen MT Condensed", L"Vladimir Script"
			});
			this->comboBoxFont->Location = System::Drawing::Point(24, 29);
			this->comboBoxFont->Name = L"comboBoxFont";
			this->comboBoxFont->Size = System::Drawing::Size(204, 23);
			this->comboBoxFont->TabIndex = 4;
			this->comboBoxFont->Text = L"�������� �����";
			this->comboBoxFont->SelectedIndexChanged += gcnew System::EventHandler(this, &Presentation::comboBoxFont_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(992, 109);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(140, 15);
			this->label4->TabIndex = 3;
			this->label4->Text = L"��������� �� �������";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(823, 111);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"�������";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(602, 109);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"����";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(209, 111);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�����";
			// 
			// buttonPrevious
			// 
			this->buttonPrevious->Location = System::Drawing::Point(22, 627);
			this->buttonPrevious->Name = L"buttonPrevious";
			this->buttonPrevious->Size = System::Drawing::Size(125, 55);
			this->buttonPrevious->TabIndex = 2;
			this->buttonPrevious->Text = L"���������� �����";
			this->buttonPrevious->UseVisualStyleBackColor = true;
			this->buttonPrevious->Click += gcnew System::EventHandler(this, &Presentation::buttonPrevious_Click);
			// 
			// buttonNext
			// 
			this->buttonNext->Location = System::Drawing::Point(1105, 627);
			this->buttonNext->Name = L"buttonNext";
			this->buttonNext->Size = System::Drawing::Size(125, 55);
			this->buttonNext->TabIndex = 3;
			this->buttonNext->Text = L"��������� �����";
			this->buttonNext->UseVisualStyleBackColor = true;
			this->buttonNext->Click += gcnew System::EventHandler(this, &Presentation::buttonNext_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// panelSlide
			// 
			this->panelSlide->Controls->Add(this->textBoxContent);
			this->panelSlide->Controls->Add(this->textBoxTitle);
			this->panelSlide->Controls->Add(this->pictureBoxBackground);
			this->panelSlide->Location = System::Drawing::Point(156, 163);
			this->panelSlide->Name = L"panelSlide";
			this->panelSlide->Size = System::Drawing::Size(940, 460);
			this->panelSlide->TabIndex = 4;
			// 
			// textBoxContent
			// 
			this->textBoxContent->AllowDrop = true;
			this->textBoxContent->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->textBoxContent->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxContent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxContent->Location = System::Drawing::Point(98, 204);
			this->textBoxContent->Multiline = true;
			this->textBoxContent->Name = L"textBoxContent";
			this->textBoxContent->Size = System::Drawing::Size(748, 187);
			this->textBoxContent->TabIndex = 2;
			this->textBoxContent->Click += gcnew System::EventHandler(this, &Presentation::textBoxContent_Click);
			this->textBoxContent->Enter += gcnew System::EventHandler(this, &Presentation::textBoxContent_Enter);
			this->textBoxContent->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::textBoxContent_MouseDown);
			this->textBoxContent->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::textBoxContent_MouseMove);
			this->textBoxContent->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::textBoxContent_MouseUp);
			// 
			// textBoxTitle
			// 
			this->textBoxTitle->AllowDrop = true;
			this->textBoxTitle->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->textBoxTitle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxTitle->Location = System::Drawing::Point(98, 84);
			this->textBoxTitle->Multiline = true;
			this->textBoxTitle->Name = L"textBoxTitle";
			this->textBoxTitle->Size = System::Drawing::Size(748, 74);
			this->textBoxTitle->TabIndex = 1;
			this->textBoxTitle->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBoxTitle->Click += gcnew System::EventHandler(this, &Presentation::textBoxTitle_Click);
			this->textBoxTitle->Enter += gcnew System::EventHandler(this, &Presentation::textBoxTitle_Enter);
			this->textBoxTitle->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::textBoxTitle_MouseDown);
			this->textBoxTitle->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::textBoxTitle_MouseMove);
			this->textBoxTitle->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::textBoxTitle_MouseUp);
			// 
			// pictureBoxBackground
			// 
			this->pictureBoxBackground->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBoxBackground->Location = System::Drawing::Point(0, 0);
			this->pictureBoxBackground->Name = L"pictureBoxBackground";
			this->pictureBoxBackground->Size = System::Drawing::Size(940, 460);
			this->pictureBoxBackground->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxBackground->TabIndex = 0;
			this->pictureBoxBackground->TabStop = false;
			this->pictureBoxBackground->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::pictureBoxBackground_MouseDown);
			this->pictureBoxBackground->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::pictureBoxBackground_MouseMove);
			this->pictureBoxBackground->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Presentation::pictureBoxBackground_MouseUp);
			// 
			// Presentation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1248, 694);
			this->Controls->Add(this->panelSlide);
			this->Controls->Add(this->buttonNext);
			this->Controls->Add(this->buttonPrevious);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1270, 750);
			this->MinimumSize = System::Drawing::Size(1270, 750);
			this->Name = L"Presentation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��������� ��� �������� �����������";
			this->Load += gcnew System::EventHandler(this, &Presentation::Presentation_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownText))->EndInit();
			this->panelSlide->ResumeLayout(false);
			this->panelSlide->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBackground))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Presentation_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBoxTitle_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBoxTitle_Enter(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBoxContent_Enter(System::Object^ sender, System::EventArgs^ e);
private: System::Void textBoxContent_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void comboBoxStyle_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void comboBoxFont_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void numericUpDownText_ValueChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void comboBoxAlign_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonTextColor_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ��������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonMark_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonPrevious_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonNext_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void listBoxSlides_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBoxBackground_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void pictureBoxBackground_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void pictureBoxBackground_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void textBoxTitle_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void textBoxTitle_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void textBoxTitle_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void textBoxContent_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void textBoxContent_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void textBoxContent_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

};
}
