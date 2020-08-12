#pragma once

#include <string>
#include <cmath>
#include <stdlib.h> 
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <stack>
#include <cctype>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>

#include "HeaderExport.h"

namespace Calculator2WinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form {
	public:	MyForm(void) {
		InitializeComponent();
	}
	protected:
		~MyForm() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;

		   const double ee = 2.71828182846;
		   int TextBoxZeroCounter = 0;
		   int Obracket = 0;
		   int Cbracket = 0;
		   int ndSelector = 0;

	private: System::Void numberInput(System::String^ numVariable) {
		String^ str = textBox1->Text;
		if (str == "0") { textBox1->Text = numVariable; }
		else if (textBox2->Text->LastIndexOf('+') > 0 && TextBoxZeroCounter == 0
				 || textBox2->Text->LastIndexOf('-') > 0 && TextBoxZeroCounter == 0
				 || textBox2->Text->LastIndexOf('*') > 0 && TextBoxZeroCounter == 0
				 || textBox2->Text->LastIndexOf('/') > 0 && TextBoxZeroCounter == 0
				 || textBox2->Text->LastIndexOf('^') > 0 && TextBoxZeroCounter == 0
				 || textBox2->Text->LastIndexOf('%') > 0 && TextBoxZeroCounter == 0
				 || textBox2->Text->LastIndexOf('s') > 0 && TextBoxZeroCounter == 0
				 || TextBoxZeroCounter == 2) {
			textBox1->Text = numVariable;
			TextBoxZeroCounter = 1;
		}
		else { if (str->Length < 10) { textBox1->Text = str + numVariable; } }
	}

	private: System::Double fact(double N) {
		if (N < 0) return 0;
		if (N == 0) return 1;
		else return N * fact(N - 1);
	}

	private: System::ComponentModel::IContainer^ components;
#pragma region Windows Form Designer generated code
		   void InitializeComponent(void) {
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());
			   this->button7 = (gcnew System::Windows::Forms::Button());
			   this->button8 = (gcnew System::Windows::Forms::Button());
			   this->button9 = (gcnew System::Windows::Forms::Button());
			   this->button10 = (gcnew System::Windows::Forms::Button());
			   this->button11 = (gcnew System::Windows::Forms::Button());
			   this->button12 = (gcnew System::Windows::Forms::Button());
			   this->button13 = (gcnew System::Windows::Forms::Button());
			   this->button14 = (gcnew System::Windows::Forms::Button());
			   this->button15 = (gcnew System::Windows::Forms::Button());
			   this->button16 = (gcnew System::Windows::Forms::Button());
			   this->button17 = (gcnew System::Windows::Forms::Button());
			   this->button18 = (gcnew System::Windows::Forms::Button());
			   this->button19 = (gcnew System::Windows::Forms::Button());
			   this->button20 = (gcnew System::Windows::Forms::Button());
			   this->button21 = (gcnew System::Windows::Forms::Button());
			   this->button22 = (gcnew System::Windows::Forms::Button());
			   this->button23 = (gcnew System::Windows::Forms::Button());
			   this->button24 = (gcnew System::Windows::Forms::Button());
			   this->button25 = (gcnew System::Windows::Forms::Button());
			   this->button26 = (gcnew System::Windows::Forms::Button());
			   this->button27 = (gcnew System::Windows::Forms::Button());
			   this->button28 = (gcnew System::Windows::Forms::Button());
			   this->button29 = (gcnew System::Windows::Forms::Button());
			   this->button30 = (gcnew System::Windows::Forms::Button());
			   this->button31 = (gcnew System::Windows::Forms::Button());
			   this->button32 = (gcnew System::Windows::Forms::Button());
			   this->button33 = (gcnew System::Windows::Forms::Button());
			   this->button34 = (gcnew System::Windows::Forms::Button());
			   this->button35 = (gcnew System::Windows::Forms::Button());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->SuspendLayout();
			   // 
			   // textBox1
			   // 
			   this->textBox1->Enabled = false;
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(204)));
			   this->textBox1->Location = System::Drawing::Point(12, 76);
			   this->textBox1->Multiline = true;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(359, 80);
			   this->textBox1->TabIndex = 1;
			   this->textBox1->Text = L"0";
			   this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(12, 169);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(67, 50);
			   this->button1->TabIndex = 6;
			   this->button1->Text = L"x^2 ";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // button2
			   // 
			   this->button2->Location = System::Drawing::Point(85, 169);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(67, 50);
			   this->button2->TabIndex = 7;
			   this->button2->Text = L"x^y";
			   this->button2->UseVisualStyleBackColor = true;
			   this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // button3
			   // 
			   this->button3->Location = System::Drawing::Point(158, 169);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(67, 50);
			   this->button3->TabIndex = 8;
			   this->button3->Text = L"sin";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			   // 
			   // button4
			   // 
			   this->button4->Location = System::Drawing::Point(231, 169);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(67, 50);
			   this->button4->TabIndex = 9;
			   this->button4->Text = L"cos";
			   this->button4->UseVisualStyleBackColor = true;
			   this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			   // 
			   // button5
			   // 
			   this->button5->Location = System::Drawing::Point(304, 169);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(67, 50);
			   this->button5->TabIndex = 10;
			   this->button5->Text = L"tan";
			   this->button5->UseVisualStyleBackColor = true;
			   this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			   // 
			   // button6
			   // 
			   this->button6->Location = System::Drawing::Point(12, 225);
			   this->button6->Name = L"button6";
			   this->button6->Size = System::Drawing::Size(67, 50);
			   this->button6->TabIndex = 11;
			   this->button6->Text = L"sqrt(x)";
			   this->button6->UseVisualStyleBackColor = true;
			   this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			   // 
			   // button7
			   // 
			   this->button7->Location = System::Drawing::Point(85, 225);
			   this->button7->Name = L"button7";
			   this->button7->Size = System::Drawing::Size(67, 50);
			   this->button7->TabIndex = 12;
			   this->button7->Text = L"10^x";
			   this->button7->UseVisualStyleBackColor = true;
			   this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			   // 
			   // button8
			   // 
			   this->button8->Location = System::Drawing::Point(158, 225);
			   this->button8->Name = L"button8";
			   this->button8->Size = System::Drawing::Size(67, 50);
			   this->button8->TabIndex = 13;
			   this->button8->Text = L"log";
			   this->button8->UseVisualStyleBackColor = true;
			   this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			   // 
			   // button9
			   // 
			   this->button9->Location = System::Drawing::Point(231, 225);
			   this->button9->Name = L"button9";
			   this->button9->Size = System::Drawing::Size(67, 50);
			   this->button9->TabIndex = 14;
			   this->button9->Text = L"Exp";
			   this->button9->UseVisualStyleBackColor = true;
			   this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			   // 
			   // button10
			   // 
			   this->button10->Location = System::Drawing::Point(303, 225);
			   this->button10->Name = L"button10";
			   this->button10->Size = System::Drawing::Size(67, 50);
			   this->button10->TabIndex = 15;
			   this->button10->Text = L"Mod";
			   this->button10->UseVisualStyleBackColor = true;
			   this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			   // 
			   // button11
			   // 
			   this->button11->Location = System::Drawing::Point(12, 281);
			   this->button11->Name = L"button11";
			   this->button11->Size = System::Drawing::Size(67, 50);
			   this->button11->TabIndex = 16;
			   this->button11->Text = L"2^nd";
			   this->button11->UseVisualStyleBackColor = true;
			   this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			   // 
			   // button12
			   // 
			   this->button12->Location = System::Drawing::Point(85, 281);
			   this->button12->Name = L"button12";
			   this->button12->Size = System::Drawing::Size(67, 50);
			   this->button12->TabIndex = 17;
			   this->button12->Text = L"CE";
			   this->button12->UseVisualStyleBackColor = true;
			   this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			   // 
			   // button13
			   // 
			   this->button13->Location = System::Drawing::Point(158, 281);
			   this->button13->Name = L"button13";
			   this->button13->Size = System::Drawing::Size(67, 50);
			   this->button13->TabIndex = 18;
			   this->button13->Text = L"C";
			   this->button13->UseVisualStyleBackColor = true;
			   this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			   // 
			   // button14
			   // 
			   this->button14->Location = System::Drawing::Point(231, 281);
			   this->button14->Name = L"button14";
			   this->button14->Size = System::Drawing::Size(67, 50);
			   this->button14->TabIndex = 19;
			   this->button14->Text = L"Backspace";
			   this->button14->UseVisualStyleBackColor = true;
			   this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			   // 
			   // button15
			   // 
			   this->button15->Location = System::Drawing::Point(303, 281);
			   this->button15->Name = L"button15";
			   this->button15->Size = System::Drawing::Size(67, 50);
			   this->button15->TabIndex = 20;
			   this->button15->Text = L"/";
			   this->button15->UseVisualStyleBackColor = true;
			   this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			   // 
			   // button16
			   // 
			   this->button16->Location = System::Drawing::Point(12, 337);
			   this->button16->Name = L"button16";
			   this->button16->Size = System::Drawing::Size(67, 50);
			   this->button16->TabIndex = 21;
			   this->button16->Text = L"Pi";
			   this->button16->UseVisualStyleBackColor = true;
			   this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			   // 
			   // button17
			   // 
			   this->button17->Location = System::Drawing::Point(303, 337);
			   this->button17->Name = L"button17";
			   this->button17->Size = System::Drawing::Size(67, 50);
			   this->button17->TabIndex = 22;
			   this->button17->Text = L"*";
			   this->button17->UseVisualStyleBackColor = true;
			   this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			   // 
			   // button18
			   // 
			   this->button18->Location = System::Drawing::Point(12, 393);
			   this->button18->Name = L"button18";
			   this->button18->Size = System::Drawing::Size(67, 50);
			   this->button18->TabIndex = 23;
			   this->button18->Text = L"n!";
			   this->button18->UseVisualStyleBackColor = true;
			   this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			   // 
			   // button19
			   // 
			   this->button19->Location = System::Drawing::Point(304, 393);
			   this->button19->Name = L"button19";
			   this->button19->Size = System::Drawing::Size(67, 50);
			   this->button19->TabIndex = 24;
			   this->button19->Text = L"-";
			   this->button19->UseVisualStyleBackColor = true;
			   this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			   // 
			   // button20
			   // 
			   this->button20->Location = System::Drawing::Point(12, 449);
			   this->button20->Name = L"button20";
			   this->button20->Size = System::Drawing::Size(67, 50);
			   this->button20->TabIndex = 25;
			   this->button20->Text = L"+/-";
			   this->button20->UseVisualStyleBackColor = true;
			   this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			   // 
			   // button21
			   // 
			   this->button21->Location = System::Drawing::Point(303, 449);
			   this->button21->Name = L"button21";
			   this->button21->Size = System::Drawing::Size(67, 50);
			   this->button21->TabIndex = 26;
			   this->button21->Text = L"+";
			   this->button21->UseVisualStyleBackColor = true;
			   this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			   // 
			   // button22
			   // 
			   this->button22->Location = System::Drawing::Point(12, 505);
			   this->button22->Name = L"button22";
			   this->button22->Size = System::Drawing::Size(67, 50);
			   this->button22->TabIndex = 27;
			   this->button22->Text = L"(";
			   this->button22->UseVisualStyleBackColor = true;
			   this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			   // 
			   // button23
			   // 
			   this->button23->Location = System::Drawing::Point(85, 505);
			   this->button23->Name = L"button23";
			   this->button23->Size = System::Drawing::Size(67, 50);
			   this->button23->TabIndex = 28;
			   this->button23->Text = L")";
			   this->button23->UseVisualStyleBackColor = true;
			   this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			   // 
			   // button24
			   // 
			   this->button24->Location = System::Drawing::Point(231, 505);
			   this->button24->Name = L"button24";
			   this->button24->Size = System::Drawing::Size(67, 50);
			   this->button24->TabIndex = 29;
			   this->button24->Text = L",";
			   this->button24->UseVisualStyleBackColor = true;
			   this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			   // 
			   // button25
			   // 
			   this->button25->Location = System::Drawing::Point(304, 505);
			   this->button25->Name = L"button25";
			   this->button25->Size = System::Drawing::Size(67, 50);
			   this->button25->TabIndex = 30;
			   this->button25->Text = L"=";
			   this->button25->UseVisualStyleBackColor = true;
			   this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			   // 
			   // button26
			   // 
			   this->button26->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button26->Location = System::Drawing::Point(158, 505);
			   this->button26->Name = L"button26";
			   this->button26->Size = System::Drawing::Size(67, 50);
			   this->button26->TabIndex = 31;
			   this->button26->Text = L"0";
			   this->button26->UseVisualStyleBackColor = false;
			   this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			   // 
			   // button27
			   // 
			   this->button27->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button27->Location = System::Drawing::Point(85, 449);
			   this->button27->Name = L"button27";
			   this->button27->Size = System::Drawing::Size(67, 50);
			   this->button27->TabIndex = 32;
			   this->button27->Text = L"1";
			   this->button27->UseVisualStyleBackColor = false;
			   this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			   // 
			   // button28
			   // 
			   this->button28->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button28->Location = System::Drawing::Point(158, 449);
			   this->button28->Name = L"button28";
			   this->button28->Size = System::Drawing::Size(67, 50);
			   this->button28->TabIndex = 33;
			   this->button28->Text = L"2";
			   this->button28->UseVisualStyleBackColor = false;
			   this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			   // 
			   // button29
			   // 
			   this->button29->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button29->Location = System::Drawing::Point(231, 449);
			   this->button29->Name = L"button29";
			   this->button29->Size = System::Drawing::Size(67, 50);
			   this->button29->TabIndex = 34;
			   this->button29->Text = L"3";
			   this->button29->UseVisualStyleBackColor = false;
			   this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			   // 
			   // button30
			   // 
			   this->button30->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button30->Location = System::Drawing::Point(85, 393);
			   this->button30->Name = L"button30";
			   this->button30->Size = System::Drawing::Size(67, 50);
			   this->button30->TabIndex = 35;
			   this->button30->Text = L"4";
			   this->button30->UseVisualStyleBackColor = false;
			   this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			   // 
			   // button31
			   // 
			   this->button31->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button31->Location = System::Drawing::Point(158, 393);
			   this->button31->Name = L"button31";
			   this->button31->Size = System::Drawing::Size(67, 50);
			   this->button31->TabIndex = 36;
			   this->button31->Text = L"5";
			   this->button31->UseVisualStyleBackColor = false;
			   this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			   // 
			   // button32
			   // 
			   this->button32->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button32->Location = System::Drawing::Point(231, 393);
			   this->button32->Name = L"button32";
			   this->button32->Size = System::Drawing::Size(67, 50);
			   this->button32->TabIndex = 37;
			   this->button32->Text = L"6";
			   this->button32->UseVisualStyleBackColor = false;
			   this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			   // 
			   // button33
			   // 
			   this->button33->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button33->Location = System::Drawing::Point(85, 337);
			   this->button33->Name = L"button33";
			   this->button33->Size = System::Drawing::Size(67, 50);
			   this->button33->TabIndex = 38;
			   this->button33->Text = L"7";
			   this->button33->UseVisualStyleBackColor = false;
			   this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			   // 
			   // button34
			   // 
			   this->button34->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button34->Location = System::Drawing::Point(158, 337);
			   this->button34->Name = L"button34";
			   this->button34->Size = System::Drawing::Size(67, 50);
			   this->button34->TabIndex = 39;
			   this->button34->Text = L"8";
			   this->button34->UseVisualStyleBackColor = false;
			   this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			   // 
			   // button35
			   // 
			   this->button35->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->button35->Location = System::Drawing::Point(230, 337);
			   this->button35->Name = L"button35";
			   this->button35->Size = System::Drawing::Size(67, 50);
			   this->button35->TabIndex = 40;
			   this->button35->Text = L"9";
			   this->button35->UseVisualStyleBackColor = false;
			   this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Enabled = false;
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(204)));
			   this->textBox2->Location = System::Drawing::Point(12, 2);
			   this->textBox2->Multiline = true;
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(359, 74);
			   this->textBox2->TabIndex = 41;
			   this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoSize = true;
			   this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			   this->ClientSize = System::Drawing::Size(382, 568);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->button35);
			   this->Controls->Add(this->button34);
			   this->Controls->Add(this->button33);
			   this->Controls->Add(this->button32);
			   this->Controls->Add(this->button31);
			   this->Controls->Add(this->button30);
			   this->Controls->Add(this->button29);
			   this->Controls->Add(this->button28);
			   this->Controls->Add(this->button27);
			   this->Controls->Add(this->button26);
			   this->Controls->Add(this->button25);
			   this->Controls->Add(this->button24);
			   this->Controls->Add(this->button23);
			   this->Controls->Add(this->button22);
			   this->Controls->Add(this->button21);
			   this->Controls->Add(this->button20);
			   this->Controls->Add(this->button19);
			   this->Controls->Add(this->button18);
			   this->Controls->Add(this->button17);
			   this->Controls->Add(this->button16);
			   this->Controls->Add(this->button15);
			   this->Controls->Add(this->button14);
			   this->Controls->Add(this->button13);
			   this->Controls->Add(this->button12);
			   this->Controls->Add(this->button11);
			   this->Controls->Add(this->button10);
			   this->Controls->Add(this->button9);
			   this->Controls->Add(this->button8);
			   this->Controls->Add(this->button7);
			   this->Controls->Add(this->button6);
			   this->Controls->Add(this->button5);
			   this->Controls->Add(this->button4);
			   this->Controls->Add(this->button3);
			   this->Controls->Add(this->button2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->textBox1);
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("0");
	}
	private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("1");
	}
	private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("2");
	}
	private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("3");
	}
	private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("4");
	}
	private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("5");
	}
	private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("6");
	}
	private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("7");
	}
	private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("8");
	}
	private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
		numberInput("9");
	}

	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) { // C
		textBox1->Text = "0";
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) { // CE
		textBox1->Text = "0";
		textBox2->Text = "";
	}


	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) { // delete last symbol, backspace
		String^ str = textBox1->Text;
		if (textBox1->Text->Length > 0) str = textBox1->Text->Substring(0, textBox1->Text->Length - 1);
		if ((textBox1->Text == "0") && (textBox2->Text->Length > 0)) {
			textBox1->Text = textBox2->Text;
			textBox2->Text = "";
			str = textBox1->Text->Substring(0, textBox1->Text->Length - 1);
		}
		if (textBox1->Text->Length == 1 || (textBox1->Text->Length == 2 && textBox1->Text->LastIndexOf("-") == 0)) str = "0";

		textBox1->Text = str;
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // x^2	x^3
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp *= temp;
			textBox1->Text = System::Convert::ToString(temp);
		}
		else if (ndSelector == 1) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp *= temp * temp;
			textBox1->Text = System::Convert::ToString(temp);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //x^y	sqrt(x), y
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			textBox2->Text += System::Convert::ToString(str) + "^";
			textBox1->Text = str;
			TextBoxZeroCounter = 0;
		}
		else if (ndSelector == 1) {
			String^ str = textBox1->Text;
			textBox2->Text += System::Convert::ToString(str) + "s";
			textBox1->Text = str;
			TextBoxZeroCounter = 0;
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { //sin	sin^-1 
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = sin(temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
		else if (ndSelector == 1) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = 1 / (sin(temp));
			textBox1->Text = System::Convert::ToString(temp);
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { //cos cos^-1 
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = cos(temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
		else if (ndSelector == 1) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = 1 / (cos(temp));
			textBox1->Text = System::Convert::ToString(temp);
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { //tan	tan^-1 
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = tan(temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
		else if (ndSelector == 1) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = 1 / (tan(temp));
			textBox1->Text = System::Convert::ToString(temp);
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { //sqrt(x)	1/x
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = sqrt(temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
		else if (ndSelector == 1) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = 1 / temp;
			textBox1->Text = System::Convert::ToString(temp);
		}
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { // 10^x	e^x
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = pow(10, temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
		else if (ndSelector == 1) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = pow(ee, temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { // log	ln
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = log10(temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
		else if (ndSelector == 1) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = log(temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) { // Exp	dms
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			double temp = System::Convert::ToDouble(str);
			temp = exp(temp);
			textBox1->Text = System::Convert::ToString(temp);
		}
		else if (ndSelector == 1) {
		}
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) { // Mod deg
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			textBox2->Text += System::Convert::ToString(str) + "%";
			textBox1->Text = str;
			TextBoxZeroCounter = 0;
		}
		else if (ndSelector == 1) {
		}
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) { //2^nd 
		if (ndSelector == 1) {
			button1->Text = "x^2";
			button2->Text = "x^y";
			button3->Text = "sin";
			button4->Text = "cos";
			button5->Text = "tan";
			button6->Text = "sqrt(x)";
			button7->Text = "10^x";
			button8->Text = "log";
			button9->Text = "Exp";
			button10->Text = "Mod";
			ndSelector = 0;
		}
		else if (ndSelector == 0) {
			button1->Text = "x^3";
			button2->Text = "sqrt(x), y";
			button3->Text = "sin^-1";
			button4->Text = "cos^-1";
			button5->Text = "tan^-1";
			button6->Text = "1/x";
			button7->Text = "e^x";
			button8->Text = "ln";
			button9->Text = "dms";
			button10->Text = "deg";
			ndSelector = 1;
		}
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) { // /
		String^ str = textBox1->Text;
		textBox2->Text += System::Convert::ToString(str) + "/";
		textBox1->Text = str;
		TextBoxZeroCounter = 0;
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) { // Pi
		textBox1->Text = System::Convert::ToString(3.1415926535897932384626433832795);
	}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) { // *
		String^ str = textBox1->Text;
		textBox2->Text += System::Convert::ToString(str) + "*";
		textBox1->Text = str;
		TextBoxZeroCounter = 0;
	}
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) { // !n
		double ch = System::Convert::ToDouble(textBox1->Text);
		double whole = 0.0, fractional = 0.0;
		fractional = modf(ch, &whole);
		if (fractional == 0.) {
			textBox1->Text = System::Convert::ToString(fact(ch));
		}
		else
			textBox1->Text = System::Convert::ToString(std::tgamma(ch + 1));

	}
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) { // -
		String^ str = textBox1->Text;
		textBox2->Text += System::Convert::ToString(str) + "-";
		textBox1->Text = str;
		TextBoxZeroCounter = 0;
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) { // "+/-"
		String^ str = textBox1->Text;
		double temp = System::Convert::ToDouble(str);
		temp = temp * -1;
		textBox1->Text = System::Convert::ToString(temp);
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) { // +
		String^ str = textBox1->Text;
		textBox2->Text += System::Convert::ToString(str) + "+";
		textBox1->Text = str;
		TextBoxZeroCounter = 0;
	}
	private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) { /* "," */
		if (textBox1->Text->LastIndexOf(",") == -1) {
			numberInput(",");
		}
	}
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) { // (
		Obracket++;
		numberInput("(");
	}
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) { // )
		if (Cbracket < Obracket) {
			numberInput(")");
			Cbracket++;
		}
	}
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) { // =

		while (Cbracket != Obracket) {
			numberInput(")");
			Cbracket++;
		}

		String^ str = textBox2->Text + textBox1->Text;

		if (str->Contains("/0")) {
			textBox1->Text = "Cannot divide by zero";
			return;
		}

		std::string sstr = msclr::interop::marshal_as<std::string>(str);
		char charArray[100] = {0};
		strcpy(charArray, sstr.c_str());
		float answ = RPN(charArray);

		textBox1->Text = System::Convert::ToString(answ);
		textBox2->Text = "";
		TextBoxZeroCounter = 2;

	}
	};
}
