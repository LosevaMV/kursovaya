#include "Presentation.h"
#include <string>
using namespace kurs1401;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;

enum class SlideType {
    TitleWithImage,
    TitleWithText
};

ref class Slide {    
public:
    SlideType type;
    String^ title;
    String^ content;
    String^ imagePath;
    Slide();
    Slide(SlideType type, String^ content, String^ title, String^ imagePath);
    ~Slide();
    SlideType GetSlideType()
    {
        return type;
    }
    void SetSlideType(SlideType type)
    {
        this->type = type;
    }
    String^ GetText()
    {
        return content;
    }
    void SetText(String^ text)
    {
        this->content = text;
    }
    String^ GetTitle()
    {
        return title;
    }
    void SetTitle(String^ title)
    {
        this->title = title;
    }
    String^ GetImage()
    {
        return imagePath;
    }
    void SetImage(Image^ image)
    {
        this->imagePath = imagePath;
    }
};

ref class PresentationApp : public Form {
private:
    List <Slide^>^ slides;
    int currentSlideIndex;
public:
    PresentationApp() {
        slides = gcnew List<Slide^>();
    }

    void createSlide(SlideType type, String^ title, String^ content, String^ imagePath) {
        Slide^ newSlide = gcnew Slide();
        // Создаем новый GroupBox
        GroupBox^ groupBox = gcnew GroupBox();

        // Добавляем PictureBox
        PictureBox^ pictureBox = gcnew PictureBox();
        if (newSlide->type == SlideType::TitleWithImage)
        {
            pictureBox->Image = Image::FromFile(newSlide->imagePath);
        }
        groupBox->Controls->Add(pictureBox);

        // Добавляем два TextBox
        TextBox^ textBox1 = gcnew TextBox();
        TextBox^ textBox2 = gcnew TextBox();
        if (newSlide->type == SlideType::TitleWithText)
        {
            textBox1->Text = newSlide->content;
        }
        groupBox->Controls->Add(textBox1);
        groupBox->Controls->Add(textBox2);
        this->Controls->Add(groupBox);

        newSlide->type = type;
        newSlide->title = title;
        if (type == SlideType::TitleWithImage) {
            newSlide->imagePath = imagePath;
        }
        else if (type == SlideType::TitleWithText) {
            newSlide->content = content;
        }
        slides->Add(newSlide);
    }

    void openSlide(int index)
    {
        // Получаем слайд с указанным индексом из списка
        Slide^ slideToOpen = slides[index];

        
    }

};

[STAThreadAttribute]

// Главная функция приложения
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    kurs1401::Presentation form;
    Application::Run(% form);
    return 0;
}

Slide::Slide()
{
    throw gcnew System::NotImplementedException();
}

Slide::Slide(SlideType type, String^ text, String^ title, String^ imagePath)
{
    throw gcnew System::NotImplementedException();
    this->content = text;
    this->type = type;
    this->title = title;
    this->imagePath = imagePath;
}

Slide::~Slide()
{
    throw gcnew System::NotImplementedException();
}

System::Void kurs1401::Presentation::Presentation_Load(System::Object^ sender, System::EventArgs^ e) {
        textBoxTitle->Text = "Заголовок слайда";
        textBoxContent->Text = "Содержимое слайда"; 
}

System::Void kurs1401::Presentation::textBoxTitle_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (textBoxTitle->Text == "Заголовок слайда")
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
    if (textBoxContent->Text == "Содержимое слайда")
        textBoxContent->Text = "";
}

System::Void kurs1401::Presentation::comboBoxStyle_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (activeTextBox != nullptr) {
        if (comboBoxStyle->SelectedItem->ToString() == "Жирный") {
            activeTextBox->Font = gcnew System::Drawing::Font(activeTextBox->Font, FontStyle::Bold);
        }
        else if (comboBoxStyle->SelectedItem->ToString() == "Курсивный") {
            activeTextBox->Font = gcnew System::Drawing::Font(activeTextBox->Font, FontStyle::Italic);
        }
        else if (comboBoxStyle->SelectedItem->ToString() == "Подчёркнутый") {
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
        if (comboBoxAlign->SelectedItem->Equals("По левому краю")) {
            activeTextBox->TextAlign = HorizontalAlignment::Left;
        }
        else if (comboBoxAlign->SelectedItem->Equals("По центру")) {
            activeTextBox->TextAlign = HorizontalAlignment::Center;
        }
        else if (comboBoxAlign->SelectedItem->Equals("По правому краю")) {
            activeTextBox->TextAlign = HorizontalAlignment::Right;
        }
    }
}

System::Void kurs1401::Presentation::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
    openFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
    openFileDialog->FilterIndex = 1;
    openFileDialog->InitialDirectory = "C:\\";
    openFileDialog->FileName = "example.txt";

    if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // Получить выбранный путь к файлу и обработать его
        System::String^ filePath = openFileDialog->FileName;
        // Добавить код для сохранения файла по выбранному пути
    }
}

System::Void kurs1401::Presentation::сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
    saveFileDialog->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
    saveFileDialog->FilterIndex = 1;
    saveFileDialog->InitialDirectory = "C:\\";
    saveFileDialog->FileName = "example.txt";

    if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        // Получить выбранный путь к файлу и обработать его
        System::String^ filePath = saveFileDialog->FileName;
        // Добавить код для сохранения файла по выбранному пути
    }
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

System::Void kurs1401::Presentation::пустойToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void kurs1401::Presentation::заголовокТекстToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Slide^ newSlide = gcnew Slide();
    PresentationApp^ myObject = gcnew PresentationApp();
    myObject->createSlide(newSlide->GetSlideType(), newSlide->title, newSlide->content, newSlide->imagePath);

}

System::Void kurs1401::Presentation::заголовокИзображениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void kurs1401::Presentation::удалитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    textBoxTitle->Clear();
    textBoxContent->Clear();
    pictureBoxBackground->Image = nullptr;

}

System::Void kurs1401::Presentation::загрузитьФонToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

System::Void kurs1401::Presentation::слайдшоуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void kurs1401::Presentation::buttonMark_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (activeTextBox != nullptr) {
        String^ selectedText = activeTextBox->SelectedText;

        // Добавление маркера "-" к выделенному тексту
        String^ markedText = "- " + selectedText;

        // Замена выделенного текста на текст с добавленным маркером
        activeTextBox->SelectedText = markedText;
    }
}

System::Void kurs1401::Presentation::buttonPrevious_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    PresentationApp^ myObject = gcnew PresentationApp();
    myObject->openSlide(selectedValueInt-1);
}

System::Void kurs1401::Presentation::buttonNext_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    PresentationApp^ myObject = gcnew PresentationApp();
    myObject->openSlide(selectedValueInt+1);
}

System::Void kurs1401::Presentation::listBoxSlides_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    PresentationApp^ myObject = gcnew PresentationApp();
    myObject->openSlide(selectedValueInt);
}

System::Void kurs1401::Presentation::pictureBoxBackground_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
        if (e->Button == System::Windows::Forms::MouseButtons::Left) {
            pictureBoxBackground->Tag = "MouseDown";
            pictureBoxBackground->Cursor = Cursors::SizeAll; // изменяем курсор для обозначения начала перетаскивания
            startPoint = e->Location; // сохраняем текущие координаты PictureBox
        }
}

System::Void kurs1401::Presentation::pictureBoxBackground_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (pictureBoxBackground->Tag == "MouseDown") { // если перетаскивание началось
        Point currentPoint = e->Location;
        pictureBoxBackground->Left += (currentPoint.X - startPoint.X); // обновляем координату Left
        pictureBoxBackground->Top += (currentPoint.Y - startPoint.Y); // обновляем координату Top
        startPoint = currentPoint; // обновляем стартовую точку
    }
}

System::Void kurs1401::Presentation::pictureBoxBackground_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        pictureBoxBackground->Tag = nullptr;
        pictureBoxBackground->Cursor = Cursors::Default; // возвращаем курсор по умолчанию
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
        // Вычисляем разницу между текущей позицией и начальной позицией
        int deltaX = e->X - startLocation.X;
        int deltaY = e->Y - startLocation.Y;

        // Обновляем позицию TextBox с учетом смещения
        textBoxTitle->Left += deltaX;
        textBoxTitle->Top += deltaY;
    }
}

System::Void kurs1401::Presentation::textBoxTitle_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        // Сбрасываем начальную позицию
        startLocation = Point::Empty;
    }
}

System::Void kurs1401::Presentation::textBoxContent_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        // Сохраняем начальную позицию при нажатии мыши
        startLocation = e->Location;
    }
}

System::Void kurs1401::Presentation::textBoxContent_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        // Вычисляем разницу между текущей позицией и начальной позицией
        int deltaX = e->X - startLocation.X;
        int deltaY = e->Y - startLocation.Y;

        // Обновляем позицию TextBox с учетом смещения
        textBoxContent->Left += deltaX;
        textBoxContent->Top += deltaY;
    }
}

System::Void kurs1401::Presentation::textBoxContent_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        // Сбрасываем начальную позицию
        startLocation = Point::Empty;
    }
}

