#pragma once
#include "SlideType.h"
#include "Slide.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Xml::Serialization;
public ref class SlideList {
public:
    List<Slide^>^ slides;

    SlideList() {
        slides = gcnew List<Slide^>();
    }
    void Save(String^ fileName) {
        try {
            XmlSerializer^ serializer = gcnew XmlSerializer(SlideList::typeid);
            TextWriter^ writer = gcnew StreamWriter(fileName);
            serializer->Serialize(writer, this);
            writer->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при сохранении файла: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void Open(String^ fileName) {
        try {
            XmlSerializer^ serializer = gcnew XmlSerializer(SlideList::typeid);
            TextReader^ reader = gcnew StreamReader(fileName);
            SlideList^ loadedSlides = (SlideList^)serializer->Deserialize(reader);
            this->slides = loadedSlides->slides;
            reader->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при загрузке файла: " + ex->Message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
};
