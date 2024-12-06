#pragma once
#include "SlideType.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Xml::Serialization;

ref class Slide {
public:
    SlideType type;
    String^ title;
    String^ content;
    String^ imagePath;
    int indexSlide;
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

Slide::Slide()
{
    type = SlideType::TitleWithText;
    title = "";
    content = "";
    imagePath = "";
    indexSlide = -1;
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

