#include "Presentation.h"
#include "SlideType.h"
#include "SlideList.h"
#include "Slide.h"
#include "Globals.h"

using namespace kurs1401;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Xml::Serialization;

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
    openFileDialog->Filter = "XML Files (.xml)|.xml|All Files (.)|.";
    openFileDialog->FilterIndex = 1;
    openFileDialog->InitialDirectory = "C:\\";

    SlideList^ slideList = gcnew SlideList();
    slideList->slides = gcnew List<Slide^>();
    slideList->Open(openFileDialog->FileName);
}

System::Void kurs1401::Presentation::сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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

System::Void kurs1401::Presentation::пустойToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void kurs1401::Presentation::заголовокТекстToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Убедитесь, что slideList и его коллекция слайдов инициализированы
    if (Globals::slideList != nullptr && Globals::slideList->slides != nullptr) {
        Slide^ slide = gcnew Slide();
        slide->type = SlideType::TitleWithText;
        slide->title = textBoxTitle->Text;
        slide->content = textBoxContent->Text;
        slide->indexSlide = Globals::slideList->slides->Count;

        // Добавление слайда в список
        Globals::slideList->slides->Add(slide);

        // Сохранение изменений в файл
        Globals::slideList->Save("slides.xml");

        // Очистка полей
        textBoxTitle->Clear();
        textBoxContent->Clear();
        pictureBoxBackground->Image = nullptr;

        // Переключение видимости элементов
        pictureBoxBackground->Visible = !pictureBoxBackground->Visible;
        textBoxContent->Visible = textBoxContent->Visible;
    }
    else {
        // Выводим сообщение об ошибке, если слайды не инициализированы
        MessageBox::Show("Слайды не были загружены или инициализированы!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void kurs1401::Presentation::заголовокИзображениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Slide^ slide = gcnew Slide();
    slide->type = SlideType::TitleWithText;
    slide->title = textBoxTitle->Text;
    //slide->content = textBoxContent->Text;
    slide->imagePath = pictureBoxBackground->ImageLocation;
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    slide->indexSlide = selectedValueInt;

    Globals::slideList->slides = gcnew List<Slide^>();
    Globals::slideList->slides->Add(slide);

    Globals::slideList->Save("slides.xml");

    textBoxTitle->Clear();
    textBoxContent->Clear();
    pictureBoxBackground->Image = nullptr;

    textBoxContent->Visible = !textBoxContent->Visible;
    pictureBoxBackground->Visible = pictureBoxBackground->Visible;
}

System::Void kurs1401::Presentation::очиститьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
    this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

    // Скрыть элементы управления редактированием
    textBoxTitle->Visible = false;
    textBoxContent->Visible = false;
    menuStrip1->Visible = false;

    int currentSlideIndex = listBoxSlides->SelectedIndex;
    if (Globals::slideList != nullptr && currentSlideIndex >= 0 && currentSlideIndex < Globals::slideList->slides->Count) {
        Slide^ currentSlide = Globals::slideList->slides[currentSlideIndex];
        if (currentSlide != nullptr) {
            textBoxTitle->Text = currentSlide->title;
            pictureBoxBackground->ImageLocation = currentSlide->imagePath;
        }
    }

    this->KeyPreview = true;
    this->KeyDown += gcnew KeyEventHandler(this, &Presentation::ExitSlideshowMode);
}

System::Void kurs1401::Presentation::buttonMark_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (activeTextBox != nullptr) {
        String^ selectedText = activeTextBox->SelectedText;

        // Добавление маркера "-" к выделенному тексту
        String^ markedText = "- " + selectedText;
        String^ modifiedText = selectedText->Replace(Environment::NewLine, Environment::NewLine + "-");


        // Замена выделенного текста на текст с добавленным маркером
        activeTextBox->SelectedText = modifiedText;
    }
}

System::Void kurs1401::Presentation::buttonPrevious_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ selectedValueString = listBoxSlides->SelectedItem->ToString();
    int selectedValueInt = Convert::ToInt32(selectedValueString);
    int listSize = Globals::slideList->slides->Count;
    int selectedIndex = listBoxSlides->SelectedIndex;

    if (selectedIndex >= 0 && selectedIndex < listSize)
    {
        Slide^ selectedElement = Globals::slideList->slides[selectedIndex];

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
    int listSize = Globals::slideList->slides->Count;
    int selectedIndex = listBoxSlides->SelectedIndex;

    if (selectedIndex >= 0 && selectedIndex < listSize)
    {
        Slide^ selectedElement = Globals::slideList->slides[selectedIndex];

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
    if (Globals::slideList == nullptr || Globals::slideList->slides == nullptr || Globals::slideList->slides->Count == 0) {
        MessageBox::Show("Список слайдов пуст или не инициализирован!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    int selectedIndex = listBoxSlides->SelectedIndex;
    if (selectedIndex >= 0 && selectedIndex < Globals::slideList->slides->Count)
    {
        Slide^ selectedElement = Globals::slideList->slides[selectedIndex];
        if (selectedElement != nullptr) {
            textBoxTitle->Text = selectedElement->title;
            textBoxContent->Text = selectedElement->content;
            pictureBoxBackground->ImageLocation = selectedElement->imagePath;
        }
    }
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
System::Void kurs1401::Presentation::ExitSlideshowMode(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Escape) {
        // Восстановление интерфейса редактирования
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
        this->WindowState = System::Windows::Forms::FormWindowState::Normal;

        // Показать элементы редактирования
        textBoxTitle->Visible = true;
        textBoxContent->Visible = true;
        menuStrip1->Visible = true;

        // Вернуться к прежнему состоянию
        this->KeyPreview = false;
    }
}
// Пример парсера для сохранения презентации в "HTML-подобный" формат
System::Void kurs1401::Presentation::SavePresentation(String^ fileName)
{
    try {
        // Создание файла
        StreamWriter^ writer = gcnew StreamWriter(fileName);

        // Начало HTML-подобной структуры
        writer->WriteLine("<presentation>");

        // Сохранение слайдов
        for (int i = 0; i < Globals::slideList->slides->Count; i++) {
            Slide^ currentSlide = Globals::slideList->slides[i];
            writer->WriteLine("  <slide>");

            // Сохранение заголовка
            writer->WriteLine("    <title>" + currentSlide->title + "</title>");

            // Сохранение содержимого
            writer->WriteLine("    <content>" + currentSlide->content + "</content>");

            // Сохранение изображения, если оно есть
            if (currentSlide->imagePath != nullptr) {
                writer->WriteLine("    <image>" + currentSlide->imagePath + "</image>");
            }

            writer->WriteLine("  </slide>");
        }

        // Закрытие структуры
        writer->WriteLine("</presentation>");
        writer->Close();
    }
    catch (Exception^ ex) {
        MessageBox::Show("Ошибка при сохранении презентации: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

// Пример парсера для загрузки презентации из "HTML-подобного" формата
System::Void kurs1401::Presentation::LoadPresentation(String^ fileName)
{
    try {
        // Открытие файла для чтения
        StreamReader^ reader = gcnew StreamReader(fileName);
        String^ fileContent = reader->ReadToEnd();
        reader->Close();

        // Парсинг данных
        // Пример простого парсинга строк с использованием регулярных выражений или деления на части
        System::Text::RegularExpressions::Regex^ slideRegex = gcnew System::Text::RegularExpressions::Regex("<slide>(.*?)</slide>", System::Text::RegularExpressions::RegexOptions::Singleline);
        System::Text::RegularExpressions::MatchCollection^ matches = slideRegex->Matches(fileContent);

        // Очистить текущий список слайдов
        Globals::slideList->slides->Clear();

        // Разбор каждого слайда
        for each (System::Text::RegularExpressions::Match ^ match in matches) {
            String^ slideContent = match->Groups[1]->Value;

            // Извлекаем заголовок
            String^ title = ExtractTagContent(slideContent, "title");
            // Извлекаем содержимое
            String^ content = ExtractTagContent(slideContent, "content");
            // Извлекаем путь к изображению, если есть
            String^ imagePath = ExtractTagContent(slideContent, "image");

            // Создание нового слайда и добавление в список
            Slide^ newSlide = gcnew Slide();
            newSlide->title = title;
            newSlide->content = content;
            newSlide->imagePath = imagePath;

            Globals::slideList->slides->Add(newSlide);
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Ошибка при загрузке презентации: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::String^ kurs1401::Presentation::ExtractTagContent(String^ content, String^ tagName)
{
    // Используем регулярные выражения для извлечения содержимого между тегами
    System::Text::RegularExpressions::Regex^ tagRegex = gcnew System::Text::RegularExpressions::Regex("<" + tagName + ">(.*?)</" + tagName + ">", System::Text::RegularExpressions::RegexOptions::Singleline);
    System::Text::RegularExpressions::Match^ match = tagRegex->Match(content);

    // Если совпадение найдено, возвращаем содержимое между тегами
    if (match->Success) {
        return match->Groups[1]->Value;
    }

    // Если тег не найден, возвращаем пустую строку
    return "";
}
