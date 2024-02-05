#include "Presentation.h"
#include "SlideType.h"
#include "SlideList.h"
#include "Slide.h"

using namespace kurs1401;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Xml::Serialization;

[STAThreadAttribute]

// ������� ������� ����������
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    kurs1401::Presentation form;
    Application::Run(% form);
    return 0;
}


System::Void kurs1401::Presentation::Presentation_Load(System::Object^ sender, System::EventArgs^ e) {
        textBoxTitle->Text = "��������� ������";
        textBoxContent->Text = "���������� ������"; 
}

System::Void kurs1401::Presentation::textBoxTitle_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (textBoxTitle->Text == "��������� ������")
        textBoxTitle->Text = "";
}

System::Void kurs1401::Presentation::textBoxTitle_Enter(System::Object^ sender, System::EventArgs^ e)
{
    activeTextBox = textBoxTitle;
}

System::Void kurs1401::Presentation::textBoxContent_Enter(System::Object^ sender, System::EventArgs^ e)
{
    activeTextBox = textBoxContent;
}

System::Void kurs1401::Presentation::textBoxContent_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (textBoxContent->Text == "���������� ������")
        textBoxContent->Text = "";
}

System::Void kurs1401::Presentation::comboBoxStyle_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (activeTextBox != nullptr) {
        if (comboBoxStyle->SelectedItem->ToString() == "������") {
            activeTextBox->Font = gcnew System::Drawing::Font(activeTextBox->Font, FontStyle::Bold);
        }
        else if (comboBoxStyle->SelectedItem->ToString() == "���������") {
            activeTextBox->Font = gcnew System::Drawing::Font(activeTextBox->Font, FontStyle::Italic);
        }
        else if (comboBoxStyle->SelectedItem->ToString() == "������������") {
            activeTextBox->Font = gcnew System::Drawing::Font(activeTextBox->Font, FontStyle::Underline);
        }
        else {
            activeTextBox->Font = gcnew System::Drawing::Font(activeTextBox->Font, FontStyle::Regular);
        }
    }
}

System::Void kurs1401::Presentation::comboBoxFont_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedFont = comboBoxFont->Text;
    float fontSize = (float)numericUpDownText->Value;
    if (activeTextBox != nullptr) {
        activeTextBox->Font = gcnew System::Drawing::Font(selectedFont, fontSize);
    }
}

System::Void kurs1401::Presentation::numericUpDownText_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    float fontSize = (float)numericUpDownText->Value;
    if (activeTextBox != nullptr) {
        activeTextBox->Font = gcnew System::Drawing::Font(activeTextBox->Font->FontFamily, fontSize);
    }
}

System::Void kurs1401::Presentation::comboBoxAlign_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (activeTextBox != nullptr) {
        if (comboBoxAlign->SelectedItem->Equals("�� ������ ����")) {
            activeTextBox->TextAlign = HorizontalAlignment::Left;
        }
        else if (comboBoxAlign->SelectedItem->Equals("�� ������")) {
            activeTextBox->TextAlign = HorizontalAlignment::Center;
        }
        else if (comboBoxAlign->SelectedItem->Equals("�� ������� ����")) {
            activeTextBox->TextAlign = HorizontalAlignment::Right;
        }
    }
}

System::Void kurs1401::Presentation::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    openFileDialog->Filter = "XML Files (.xml)|.xml|All Files (.)|.";
    openFileDialog->FilterIndex = 1;
    openFileDialog->InitialDirectory = "C:\\";

    SlideList^ slideList = gcnew SlideList();
    slideList->slides = gcnew List<Slide^>();
    slideList->Open(openFileDialog->FileName);
}

System::Void kurs1401::Presentation::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
    saveFileDialog->Filter = "XML Files (.xml)|.xml|All Files (.)|.";
    saveFileDialog->FilterIndex = 1;
    saveFileDialog->InitialDirectory = "C:\\";
    saveFileDialog->FileName = "example.xml";

    SlideList^ slideList = gcnew SlideList();
    slideList->slides = gcnew List<Slide^>();
    slideList->Save(saveFileDialog->FileName);
    
}

System::Void kurs1401::Presentation::buttonTextColor_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (activeTextBox != nullptr) {
        ColorDialog^ colorDialog = gcnew ColorDialog();
        if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            activeTextBox->ForeColor = colorDialog->Color;
            buttonTextColor->BackColor = colorDialog->Color;
        }
    }
}

System::Void kurs1401::Presentation::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void kurs1401::Presentation::��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Slide^ slide = gcnew Slide();
    slide->type = SlideType::TitleWithText;
    slide->title = textBoxTitle->Text;
    slide->content = textBoxContent->Text;
    //slide->imagePath = pictureBoxBackground->ImageLocation;
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    slide->indexSlide = selectedValueInt;

    SlideList^ slideList = gcnew SlideList();
    slideList->slides = gcnew List<Slide^>();
    slideList->slides->Add(slide);

    slideList->Save("slides.xml");

    textBoxTitle->Clear();
    textBoxContent->Clear();
    pictureBoxBackground->Image = nullptr;

    pictureBoxBackground->Visible = !pictureBoxBackground->Visible;
    textBoxContent->Visible = textBoxContent->Visible;
}

System::Void kurs1401::Presentation::��������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Slide^ slide = gcnew Slide();
    slide->type = SlideType::TitleWithText;
    slide->title = textBoxTitle->Text;
    //slide->content = textBoxContent->Text;
    slide->imagePath = pictureBoxBackground->ImageLocation;
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    slide->indexSlide = selectedValueInt;

    SlideList^ slideList = gcnew SlideList();
    slideList->slides = gcnew List<Slide^>();
    slideList->slides->Add(slide);

    slideList->Save("slides.xml");

    textBoxTitle->Clear();
    textBoxContent->Clear();
    pictureBoxBackground->Image = nullptr;

    textBoxContent->Visible = !textBoxContent->Visible;
    pictureBoxBackground->Visible = pictureBoxBackground->Visible;
}

System::Void kurs1401::Presentation::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    textBoxTitle->Clear();
    textBoxContent->Clear();
    pictureBoxBackground->Image = nullptr;

}

System::Void kurs1401::Presentation::������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();

    openFileDialog1->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.bmp";
    openFileDialog1->Title = "Select an Image File";

    if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        System::String^ imgPath = openFileDialog1->FileName;
        pictureBoxBackground->ImageLocation = imgPath;
    }
}

System::Void kurs1401::Presentation::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void kurs1401::Presentation::buttonMark_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (activeTextBox != nullptr) {
        String^ selectedText = activeTextBox->SelectedText;

        // ���������� ������� "-" � ����������� ������
        String^ markedText = "- " + selectedText;
        String^ modifiedText = selectedText->Replace(Environment::NewLine, Environment::NewLine + "-");


        // ������ ����������� ������ �� ����� � ����������� ��������
        activeTextBox->SelectedText = modifiedText;
    }
}

System::Void kurs1401::Presentation::buttonPrevious_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    SlideList^ slideList = gcnew SlideList();
    int listSize = slideList->slides->Count;
    int selectedIndex = listBoxSlides->SelectedIndex;

    if (selectedIndex >= 0 && selectedIndex < listSize)
    {
        Slide^ selectedElement = slideList->slides[selectedIndex];

        textBoxTitle->Text = selectedElement->title;
        textBoxContent->Text = selectedElement->content;
        pictureBoxBackground->ImageLocation = selectedElement->imagePath;

        String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
        int selectedValueInt = Convert::ToInt32(selectedValueString);
        selectedElement->indexSlide = selectedValueInt;
    }

    int itemHeight = listBoxSlides->Height / listSize;
    listBoxSlides->ItemHeight = itemHeight;
}

System::Void kurs1401::Presentation::buttonNext_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    SlideList^ slideList = gcnew SlideList();
    int listSize = slideList->slides->Count;
    int selectedIndex = listBoxSlides->SelectedIndex;

    if (selectedIndex >= 0 && selectedIndex < listSize)
    {
        Slide^ selectedElement = slideList->slides[selectedIndex];

        textBoxTitle->Text = selectedElement->title;
        textBoxContent->Text = selectedElement->content;
        pictureBoxBackground->ImageLocation = selectedElement->imagePath;

        String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
        int selectedValueInt = Convert::ToInt32(selectedValueString);
        selectedElement->indexSlide = selectedValueInt;
    }

    int itemHeight = listBoxSlides->Height / listSize;
    listBoxSlides->ItemHeight = itemHeight;
}

System::Void kurs1401::Presentation::listBoxSlides_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    SlideList^ slideList = gcnew SlideList();
    int listSize = slideList->slides->Count;
    int selectedIndex = listBoxSlides->SelectedIndex;

    if (selectedIndex >= 0 && selectedIndex < listSize)
    {
        Slide^ selectedElement = slideList->slides[selectedIndex];

        textBoxTitle->Text = selectedElement->title;
        textBoxContent->Text = selectedElement->content;
        pictureBoxBackground->ImageLocation = selectedElement->imagePath;

        String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
        int selectedValueInt = Convert::ToInt32(selectedValueString);
        selectedElement->indexSlide = selectedValueInt;
    }

    int itemHeight = listBoxSlides->Height / listSize;
    listBoxSlides->ItemHeight = itemHeight;
}

System::Void kurs1401::Presentation::pictureBoxBackground_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
        if (e->Button == System::Windows::Forms::MouseButtons::Left) {
            pictureBoxBackground->Tag = "MouseDown";
            pictureBoxBackground->Cursor = Cursors::SizeAll; // �������� ������ ��� ����������� ������ ��������������
            startPoint = e->Location; // ��������� ������� ���������� PictureBox
        }
}

System::Void kurs1401::Presentation::pictureBoxBackground_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (pictureBoxBackground->Tag == "MouseDown") { // ���� �������������� ��������
        Point currentPoint = e->Location;
        pictureBoxBackground->Left += (currentPoint.X - startPoint.X); // ��������� ���������� Left
        pictureBoxBackground->Top += (currentPoint.Y - startPoint.Y); // ��������� ���������� Top
        startPoint = currentPoint; // ��������� ��������� �����
    }
}

System::Void kurs1401::Presentation::pictureBoxBackground_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        pictureBoxBackground->Tag = nullptr;
        pictureBoxBackground->Cursor = Cursors::Default; // ���������� ������ �� ���������
    }
}

System::Void kurs1401::Presentation::textBoxTitle_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        startLocation = e->Location;
    }
}

System::Void kurs1401::Presentation::textBoxTitle_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        // ��������� ������� ����� ������� �������� � ��������� ��������
        int deltaX = e->X - startLocation.X;
        int deltaY = e->Y - startLocation.Y;

        // ��������� ������� TextBox � ������ ��������
        textBoxTitle->Left += deltaX;
        textBoxTitle->Top += deltaY;
    }
}

System::Void kurs1401::Presentation::textBoxTitle_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        // ���������� ��������� �������
        startLocation = Point::Empty;
    }
}

System::Void kurs1401::Presentation::textBoxContent_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        // ��������� ��������� ������� ��� ������� ����
        startLocation = e->Location;
    }
}

System::Void kurs1401::Presentation::textBoxContent_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        // ��������� ������� ����� ������� �������� � ��������� ��������
        int deltaX = e->X - startLocation.X;
        int deltaY = e->Y - startLocation.Y;

        // ��������� ������� TextBox � ������ ��������
        textBoxContent->Left += deltaX;
        textBoxContent->Top += deltaY;
    }
}

System::Void kurs1401::Presentation::textBoxContent_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        startLocation = Point::Empty;
    }
}

System::Void kurs1401::Presentation::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    FontDialog^ fontDialog = gcnew FontDialog();
            if (fontDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                activeTextBox->Font = fontDialog->Font;
            }
}

