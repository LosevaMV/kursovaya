#pragma once
#include "SlideType.h"
#include "Slide.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Xml::Serialization;
public ref class SlideList
{
public:
	List<Slide^>^ slides;

	void Save(String^ fileName)
	{
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "XML Files (.xml)|.xml|All Files (.)|.";
		saveFileDialog->FilterIndex = 1;
		saveFileDialog->InitialDirectory = "C:\\";
		saveFileDialog->FileName = "example.xml";

		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			System::String^ filePath = saveFileDialog->FileName;
			XmlSerializer^ serializer = gcnew XmlSerializer(SlideList::typeid);
			TextWriter^ writer = gcnew StreamWriter(filePath);
			serializer->Serialize(writer, this);
			writer->Close();
		}
	}

	void Open(String^ fileName) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "XML Files (.xml)|.xml|All Files (.)|.";
		openFileDialog->FilterIndex = 1;
		openFileDialog->InitialDirectory = "C:\\";
		openFileDialog->FileName = "example.xml";
		
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			System::String^ filePath = openFileDialog->FileName;
			XmlSerializer^ serializer = gcnew XmlSerializer(SlideList::typeid);
			TextReader^ reader = gcnew StreamReader(filePath);
			SlideList^ presentation = (SlideList^)serializer->Deserialize(reader);
			reader->Close();
		}
	}
};
