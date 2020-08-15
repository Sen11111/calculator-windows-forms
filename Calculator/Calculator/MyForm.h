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
#include <regex>


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
	private: System::Windows::Forms::Button^ powerX2;
	private: System::Windows::Forms::Button^ powerXY;
	private: System::Windows::Forms::Button^ Sin;
	private: System::Windows::Forms::Button^ Cos;
	private: System::Windows::Forms::Button^ Tan;
	private: System::Windows::Forms::Button^ Sqrt;
	private: System::Windows::Forms::Button^ Power10X;
	private: System::Windows::Forms::Button^ Log;
	private: System::Windows::Forms::Button^ exponent;
	private: System::Windows::Forms::Button^ Mod;
	private: System::Windows::Forms::Button^ ndPower2;
	private: System::Windows::Forms::Button^ ClearAll;
	private: System::Windows::Forms::Button^ Clear;
	private: System::Windows::Forms::Button^ Backspace;
	private: System::Windows::Forms::Button^ divide;
	private: System::Windows::Forms::Button^ NumberPi;
	private: System::Windows::Forms::Button^ multiply;
	private: System::Windows::Forms::Button^ factorial;
	private: System::Windows::Forms::Button^ Minus;
	private: System::Windows::Forms::Button^ ReversePlusMinus;
	private: System::Windows::Forms::Button^ Plus;
	private: System::Windows::Forms::Button^ OpenBracket;
	private: System::Windows::Forms::Button^ CloseBracket;
	private: System::Windows::Forms::Button^ Dot;
	private: System::Windows::Forms::Button^ equals;
	private: System::Windows::Forms::Button^ Number0;
	private: System::Windows::Forms::Button^ Number1;
	private: System::Windows::Forms::Button^ Number2;
	private: System::Windows::Forms::Button^ Number3;
	private: System::Windows::Forms::Button^ Number4;
	private: System::Windows::Forms::Button^ Number5;
	private: System::Windows::Forms::Button^ Number6;
	private: System::Windows::Forms::Button^ Number7;
	private: System::Windows::Forms::Button^ Number8;
	private: System::Windows::Forms::Button^ Number9;

	const double ee = 2.71828182846;
	int TextBoxZeroCounter = 0;
	int Obracket = 0;
	int Cbracket = 0;
	int ndSelector = 0;
	int factI = 0;

	private: System::Void numberInput(System::String^ numVariable) {
		String^ tb1;
		try {
			String^ str = textBox1->Text;
			tb1 = str;
			if (str == "0") {
				textBox1->Text = numVariable;
			}
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
			else {
				if (str->Length < 10) {
					textBox1->Text = str + numVariable;
				}
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}

		   double RPN(std::string inString) {

			   // split string
			   std::regex ws_re("\\s+");
			   std::stack <std::string> ReverseStack;
			   std::vector<std::string> result{
				   std::sregex_token_iterator(inString.begin(), inString.end(), ws_re, -1), {}
			   };
			   
			   for (unsigned int i = 0; i < result.size(); i++) {
				   ReverseStack.push(result[i]);
			   }

			   // reverse string
			   std::stack <std::string> inp;
			   while (!ReverseStack.empty()) {
				   inp.push(ReverseStack.top());
				   ReverseStack.pop();
			   }

			   // Sort Facility
			   std::stack <std::string> exitString;
			   std::stack <std::string> funcStack;

			   while (!inp.empty()) {
				   std::string str = inp.top();
				   inp.pop();
				   size_t foundIsdigitAndMin = str.find_first_not_of("1234567890,-");
				   if (foundIsdigitAndMin == std::string::npos && str != "-") {
					   if (str.find(",") != std::string::npos) {
						str.replace(str.find(","), sizeof(",") - 1, ".");
					   }
                        exitString.push(str);
				   }
				   if (str == "(") {
					   funcStack.push(str);
				   }
				   else if (str == ")") {
					   try {
						   while (funcStack.top() != "(") {
							   exitString.push(funcStack.top());
							   funcStack.pop();
						   }
					   }
					   catch (...) {
						   return -1;
					   }
					   funcStack.pop();
				   }
				   else if (str == "+" || str == "-" || str == "*" || str == "/" ||
							str == "^" || str == "%" || str == "s") {

					   // 1 s ^      2 % / *      3 + -
					   int strPriority = 5;
					   int stackPriority = 5;
					   if (str == "+" || str == "-") {
						   strPriority = 3;
					   }
					   else if (str == "*" || str == "/" || str == "%") {
						   strPriority = 2;
					   }
					   else if (str == "^" || str == "s") {
						   strPriority = 1;
					   }
					   while (true) { //---------------------------------------------------------
						   if (!funcStack.empty()) {
							   if (funcStack.top() == "+" || funcStack.top() == "-") {
								   stackPriority = 3;
							   }
							   else if (funcStack.top() == "*" || funcStack.top() == "/" || funcStack.top() == "%") {
								   stackPriority = 2;
							   }
							   else if (funcStack.top() == "^" || funcStack.top() == "s") {
								   stackPriority = 1;
							   }
							   else if (funcStack.top() == "(") {
								   stackPriority = 5;
							   }

							   if (stackPriority <= strPriority) {
								   exitString.push(funcStack.top());
								   funcStack.pop();
							   }
							   else break;
						   }
						   else break;
					   }
					   funcStack.push(str);
				   }
			   }
			   while (!funcStack.empty()) {
				   exitString.push(funcStack.top());
				   funcStack.pop();
			   }

			   // Calculating reverse polish notation
			   while (!exitString.empty()) {
				   funcStack.push(exitString.top());
				   exitString.pop();
			   }

			   while (!funcStack.empty()) {
				   std::string str = funcStack.top();
				   size_t foundIsdigitAndMin = str.find_first_not_of("1234567890.-");
				   if (foundIsdigitAndMin == std::string::npos && str != "-") {
					   exitString.push(str);
					   funcStack.pop();
				   }
				   else if (str == "+" || str == "-" || str == "*" || str == "/" ||
							str == "^" || str == "%" || str == "s") {
					   if (exitString.size() < 2 && funcStack.size() <= 1) break;
					   double rOperand = stof(exitString.top());
					   exitString.pop();
					   double lOperand = stof(exitString.top());
					   exitString.pop();
					   if (str == "+") {
						   funcStack.pop();
						   exitString.push(std::to_string(lOperand + rOperand));
					   }
					   else if (str == "-") {
						   funcStack.pop();
						   exitString.push(std::to_string(lOperand - rOperand));
					   }
					   else if (str == "*") {
						   funcStack.pop();
						   exitString.push(std::to_string(lOperand * rOperand));
					   }
					   else if (str == "/") {
						   funcStack.pop();
						   exitString.push(std::to_string(lOperand / rOperand));
					   }
					   else if (str == "%") {
						   funcStack.pop();
						   exitString.push(std::to_string(fmod(lOperand, rOperand)));
					   }
					   else if (str == "^") {
						   funcStack.pop();
						   exitString.push(std::to_string(pow(lOperand, rOperand)));
					   }
					   else if (str == "s") {
						   funcStack.pop();
						   exitString.push(std::to_string(pow(lOperand, 1 / rOperand)));
					   }
				   }
			   }
			   return atof(exitString.top().c_str());
		   }

	private: System::Double fact(double N) {
		String^ tb1;
		factI++;
		try {
			if (N < 0) return 0;
			if (N == 0) return 1;
			else return N * fact(N - 1);
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s, %s\n", __FUNCTION__, tb1, factI);
			fclose(LogFile);
		}
	}

	private: System::ComponentModel::IContainer^ components;
#pragma region Windows Form Designer generated code
		   void InitializeComponent(void) {
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->powerX2 = (gcnew System::Windows::Forms::Button());
			   this->powerXY = (gcnew System::Windows::Forms::Button());
			   this->Sin = (gcnew System::Windows::Forms::Button());
			   this->Cos = (gcnew System::Windows::Forms::Button());
			   this->Tan = (gcnew System::Windows::Forms::Button());
			   this->Sqrt = (gcnew System::Windows::Forms::Button());
			   this->Power10X = (gcnew System::Windows::Forms::Button());
			   this->Log = (gcnew System::Windows::Forms::Button());
			   this->exponent = (gcnew System::Windows::Forms::Button());
			   this->Mod = (gcnew System::Windows::Forms::Button());
			   this->ndPower2 = (gcnew System::Windows::Forms::Button());
			   this->ClearAll = (gcnew System::Windows::Forms::Button());
			   this->Clear = (gcnew System::Windows::Forms::Button());
			   this->Backspace = (gcnew System::Windows::Forms::Button());
			   this->divide = (gcnew System::Windows::Forms::Button());
			   this->NumberPi = (gcnew System::Windows::Forms::Button());
			   this->multiply = (gcnew System::Windows::Forms::Button());
			   this->factorial = (gcnew System::Windows::Forms::Button());
			   this->Minus = (gcnew System::Windows::Forms::Button());
			   this->ReversePlusMinus = (gcnew System::Windows::Forms::Button());
			   this->Plus = (gcnew System::Windows::Forms::Button());
			   this->OpenBracket = (gcnew System::Windows::Forms::Button());
			   this->CloseBracket = (gcnew System::Windows::Forms::Button());
			   this->Dot = (gcnew System::Windows::Forms::Button());
			   this->equals = (gcnew System::Windows::Forms::Button());
			   this->Number0 = (gcnew System::Windows::Forms::Button());
			   this->Number1 = (gcnew System::Windows::Forms::Button());
			   this->Number2 = (gcnew System::Windows::Forms::Button());
			   this->Number3 = (gcnew System::Windows::Forms::Button());
			   this->Number4 = (gcnew System::Windows::Forms::Button());
			   this->Number5 = (gcnew System::Windows::Forms::Button());
			   this->Number6 = (gcnew System::Windows::Forms::Button());
			   this->Number7 = (gcnew System::Windows::Forms::Button());
			   this->Number8 = (gcnew System::Windows::Forms::Button());
			   this->Number9 = (gcnew System::Windows::Forms::Button());
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
			   // powerX2
			   // 
			   this->powerX2->Location = System::Drawing::Point(12, 169);
			   this->powerX2->Name = L"powerX2";
			   this->powerX2->Size = System::Drawing::Size(67, 50);
			   this->powerX2->TabIndex = 6;
			   this->powerX2->Text = L"x^2 ";
			   this->powerX2->UseVisualStyleBackColor = true;
			   this->powerX2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // powerXY
			   // 
			   this->powerXY->Location = System::Drawing::Point(85, 169);
			   this->powerXY->Name = L"powerXY";
			   this->powerXY->Size = System::Drawing::Size(67, 50);
			   this->powerXY->TabIndex = 7;
			   this->powerXY->Text = L"x^y";
			   this->powerXY->UseVisualStyleBackColor = true;
			   this->powerXY->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // Sin
			   // 
			   this->Sin->Location = System::Drawing::Point(158, 169);
			   this->Sin->Name = L"Sin";
			   this->Sin->Size = System::Drawing::Size(67, 50);
			   this->Sin->TabIndex = 8;
			   this->Sin->Text = L"sin";
			   this->Sin->UseVisualStyleBackColor = true;
			   this->Sin->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			   // 
			   // Cos
			   // 
			   this->Cos->Location = System::Drawing::Point(231, 169);
			   this->Cos->Name = L"Cos";
			   this->Cos->Size = System::Drawing::Size(67, 50);
			   this->Cos->TabIndex = 9;
			   this->Cos->Text = L"cos";
			   this->Cos->UseVisualStyleBackColor = true;
			   this->Cos->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			   // 
			   // Tan
			   // 
			   this->Tan->Location = System::Drawing::Point(304, 169);
			   this->Tan->Name = L"Tan";
			   this->Tan->Size = System::Drawing::Size(67, 50);
			   this->Tan->TabIndex = 10;
			   this->Tan->Text = L"tan";
			   this->Tan->UseVisualStyleBackColor = true;
			   this->Tan->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			   // 
			   // Sqrt
			   // 
			   this->Sqrt->Location = System::Drawing::Point(12, 225);
			   this->Sqrt->Name = L"Sqrt";
			   this->Sqrt->Size = System::Drawing::Size(67, 50);
			   this->Sqrt->TabIndex = 11;
			   this->Sqrt->Text = L"sqrt(x)";
			   this->Sqrt->UseVisualStyleBackColor = true;
			   this->Sqrt->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			   // 
			   // Power10X
			   // 
			   this->Power10X->Location = System::Drawing::Point(85, 225);
			   this->Power10X->Name = L"Power10X";
			   this->Power10X->Size = System::Drawing::Size(67, 50);
			   this->Power10X->TabIndex = 12;
			   this->Power10X->Text = L"10^x";
			   this->Power10X->UseVisualStyleBackColor = true;
			   this->Power10X->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			   // 
			   // Log
			   // 
			   this->Log->Location = System::Drawing::Point(158, 225);
			   this->Log->Name = L"Log";
			   this->Log->Size = System::Drawing::Size(67, 50);
			   this->Log->TabIndex = 13;
			   this->Log->Text = L"log";
			   this->Log->UseVisualStyleBackColor = true;
			   this->Log->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			   // 
			   // exponent
			   // 
			   this->exponent->Location = System::Drawing::Point(231, 225);
			   this->exponent->Name = L"exponent";
			   this->exponent->Size = System::Drawing::Size(67, 50);
			   this->exponent->TabIndex = 14;
			   this->exponent->Text = L"Exp";
			   this->exponent->UseVisualStyleBackColor = true;
			   this->exponent->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			   // 
			   // Mod
			   // 
			   this->Mod->Location = System::Drawing::Point(303, 225);
			   this->Mod->Name = L"Mod";
			   this->Mod->Size = System::Drawing::Size(67, 50);
			   this->Mod->TabIndex = 15;
			   this->Mod->Text = L"Mod";
			   this->Mod->UseVisualStyleBackColor = true;
			   this->Mod->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			   // 
			   // ndPower2
			   // 
			   this->ndPower2->Location = System::Drawing::Point(12, 281);
			   this->ndPower2->Name = L"ndPower2";
			   this->ndPower2->Size = System::Drawing::Size(67, 50);
			   this->ndPower2->TabIndex = 16;
			   this->ndPower2->Text = L"2^nd";
			   this->ndPower2->UseVisualStyleBackColor = true;
			   this->ndPower2->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			   // 
			   // ClearAll
			   // 
			   this->ClearAll->Location = System::Drawing::Point(85, 281);
			   this->ClearAll->Name = L"ClearAll";
			   this->ClearAll->Size = System::Drawing::Size(67, 50);
			   this->ClearAll->TabIndex = 17;
			   this->ClearAll->Text = L"CE";
			   this->ClearAll->UseVisualStyleBackColor = true;
			   this->ClearAll->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			   // 
			   // Clear
			   // 
			   this->Clear->Location = System::Drawing::Point(158, 281);
			   this->Clear->Name = L"Clear";
			   this->Clear->Size = System::Drawing::Size(67, 50);
			   this->Clear->TabIndex = 18;
			   this->Clear->Text = L"C";
			   this->Clear->UseVisualStyleBackColor = true;
			   this->Clear->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			   // 
			   // Backspace
			   // 
			   this->Backspace->Location = System::Drawing::Point(231, 281);
			   this->Backspace->Name = L"Backspace";
			   this->Backspace->Size = System::Drawing::Size(67, 50);
			   this->Backspace->TabIndex = 19;
			   this->Backspace->Text = L"Backspace";
			   this->Backspace->UseVisualStyleBackColor = true;
			   this->Backspace->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			   // 
			   // divide
			   // 
			   this->divide->Location = System::Drawing::Point(303, 281);
			   this->divide->Name = L"divide";
			   this->divide->Size = System::Drawing::Size(67, 50);
			   this->divide->TabIndex = 20;
			   this->divide->Text = L"/";
			   this->divide->UseVisualStyleBackColor = true;
			   this->divide->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			   // 
			   // NumberPi
			   // 
			   this->NumberPi->Location = System::Drawing::Point(12, 337);
			   this->NumberPi->Name = L"NumberPi";
			   this->NumberPi->Size = System::Drawing::Size(67, 50);
			   this->NumberPi->TabIndex = 21;
			   this->NumberPi->Text = L"Pi";
			   this->NumberPi->UseVisualStyleBackColor = true;
			   this->NumberPi->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			   // 
			   // multiply
			   // 
			   this->multiply->Location = System::Drawing::Point(303, 337);
			   this->multiply->Name = L"multiply";
			   this->multiply->Size = System::Drawing::Size(67, 50);
			   this->multiply->TabIndex = 22;
			   this->multiply->Text = L"*";
			   this->multiply->UseVisualStyleBackColor = true;
			   this->multiply->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			   // 
			   // factorial
			   // 
			   this->factorial->Location = System::Drawing::Point(12, 393);
			   this->factorial->Name = L"factorial";
			   this->factorial->Size = System::Drawing::Size(67, 50);
			   this->factorial->TabIndex = 23;
			   this->factorial->Text = L"n!";
			   this->factorial->UseVisualStyleBackColor = true;
			   this->factorial->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			   // 
			   // Minus
			   // 
			   this->Minus->Location = System::Drawing::Point(304, 393);
			   this->Minus->Name = L"Minus";
			   this->Minus->Size = System::Drawing::Size(67, 50);
			   this->Minus->TabIndex = 24;
			   this->Minus->Text = L"-";
			   this->Minus->UseVisualStyleBackColor = true;
			   this->Minus->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			   // 
			   // ReversePlusMinus
			   // 
			   this->ReversePlusMinus->Location = System::Drawing::Point(12, 449);
			   this->ReversePlusMinus->Name = L"ReversePlusMinus";
			   this->ReversePlusMinus->Size = System::Drawing::Size(67, 50);
			   this->ReversePlusMinus->TabIndex = 25;
			   this->ReversePlusMinus->Text = L"+/-";
			   this->ReversePlusMinus->UseVisualStyleBackColor = true;
			   this->ReversePlusMinus->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			   // 
			   // Plus
			   // 
			   this->Plus->Location = System::Drawing::Point(303, 449);
			   this->Plus->Name = L"Plus";
			   this->Plus->Size = System::Drawing::Size(67, 50);
			   this->Plus->TabIndex = 26;
			   this->Plus->Text = L"+";
			   this->Plus->UseVisualStyleBackColor = true;
			   this->Plus->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			   // 
			   // OpenBracket
			   // 
			   this->OpenBracket->Location = System::Drawing::Point(12, 505);
			   this->OpenBracket->Name = L"OpenBracket";
			   this->OpenBracket->Size = System::Drawing::Size(67, 50);
			   this->OpenBracket->TabIndex = 27;
			   this->OpenBracket->Text = L"(";
			   this->OpenBracket->UseVisualStyleBackColor = true;
			   this->OpenBracket->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			   // 
			   // CloseBracket
			   // 
			   this->CloseBracket->Location = System::Drawing::Point(85, 505);
			   this->CloseBracket->Name = L"CloseBracket";
			   this->CloseBracket->Size = System::Drawing::Size(67, 50);
			   this->CloseBracket->TabIndex = 28;
			   this->CloseBracket->Text = L")";
			   this->CloseBracket->UseVisualStyleBackColor = true;
			   this->CloseBracket->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			   // 
			   // Dot
			   // 
			   this->Dot->Location = System::Drawing::Point(231, 505);
			   this->Dot->Name = L"Dot";
			   this->Dot->Size = System::Drawing::Size(67, 50);
			   this->Dot->TabIndex = 29;
			   this->Dot->Text = L",";
			   this->Dot->UseVisualStyleBackColor = true;
			   this->Dot->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			   // 
			   // equals
			   // 
			   this->equals->Location = System::Drawing::Point(304, 505);
			   this->equals->Name = L"equals";
			   this->equals->Size = System::Drawing::Size(67, 50);
			   this->equals->TabIndex = 30;
			   this->equals->Text = L"=";
			   this->equals->UseVisualStyleBackColor = true;
			   this->equals->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			   // 
			   // Number0
			   // 
			   this->Number0->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number0->Location = System::Drawing::Point(158, 505);
			   this->Number0->Name = L"Number0";
			   this->Number0->Size = System::Drawing::Size(67, 50);
			   this->Number0->TabIndex = 31;
			   this->Number0->Text = L"0";
			   this->Number0->UseVisualStyleBackColor = false;
			   this->Number0->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			   // 
			   // Number1
			   // 
			   this->Number1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number1->Location = System::Drawing::Point(85, 449);
			   this->Number1->Name = L"Number1";
			   this->Number1->Size = System::Drawing::Size(67, 50);
			   this->Number1->TabIndex = 32;
			   this->Number1->Text = L"1";
			   this->Number1->UseVisualStyleBackColor = false;
			   this->Number1->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			   // 
			   // Number2
			   // 
			   this->Number2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number2->Location = System::Drawing::Point(158, 449);
			   this->Number2->Name = L"Number2";
			   this->Number2->Size = System::Drawing::Size(67, 50);
			   this->Number2->TabIndex = 33;
			   this->Number2->Text = L"2";
			   this->Number2->UseVisualStyleBackColor = false;
			   this->Number2->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			   // 
			   // Number3
			   // 
			   this->Number3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number3->Location = System::Drawing::Point(231, 449);
			   this->Number3->Name = L"Number3";
			   this->Number3->Size = System::Drawing::Size(67, 50);
			   this->Number3->TabIndex = 34;
			   this->Number3->Text = L"3";
			   this->Number3->UseVisualStyleBackColor = false;
			   this->Number3->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			   // 
			   // Number4
			   // 
			   this->Number4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number4->Location = System::Drawing::Point(85, 393);
			   this->Number4->Name = L"Number4";
			   this->Number4->Size = System::Drawing::Size(67, 50);
			   this->Number4->TabIndex = 35;
			   this->Number4->Text = L"4";
			   this->Number4->UseVisualStyleBackColor = false;
			   this->Number4->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			   // 
			   // Number5
			   // 
			   this->Number5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number5->Location = System::Drawing::Point(158, 393);
			   this->Number5->Name = L"Number5";
			   this->Number5->Size = System::Drawing::Size(67, 50);
			   this->Number5->TabIndex = 36;
			   this->Number5->Text = L"5";
			   this->Number5->UseVisualStyleBackColor = false;
			   this->Number5->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			   // 
			   // Number6
			   // 
			   this->Number6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number6->Location = System::Drawing::Point(231, 393);
			   this->Number6->Name = L"Number6";
			   this->Number6->Size = System::Drawing::Size(67, 50);
			   this->Number6->TabIndex = 37;
			   this->Number6->Text = L"6";
			   this->Number6->UseVisualStyleBackColor = false;
			   this->Number6->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			   // 
			   // Number7
			   // 
			   this->Number7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number7->Location = System::Drawing::Point(85, 337);
			   this->Number7->Name = L"Number7";
			   this->Number7->Size = System::Drawing::Size(67, 50);
			   this->Number7->TabIndex = 38;
			   this->Number7->Text = L"7";
			   this->Number7->UseVisualStyleBackColor = false;
			   this->Number7->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			   // 
			   // Number8
			   // 
			   this->Number8->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number8->Location = System::Drawing::Point(158, 337);
			   this->Number8->Name = L"Number8";
			   this->Number8->Size = System::Drawing::Size(67, 50);
			   this->Number8->TabIndex = 39;
			   this->Number8->Text = L"8";
			   this->Number8->UseVisualStyleBackColor = false;
			   this->Number8->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			   // 
			   // Number9
			   // 
			   this->Number9->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Number9->Location = System::Drawing::Point(230, 337);
			   this->Number9->Name = L"Number9";
			   this->Number9->Size = System::Drawing::Size(67, 50);
			   this->Number9->TabIndex = 40;
			   this->Number9->Text = L"9";
			   this->Number9->UseVisualStyleBackColor = false;
			   this->Number9->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
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
			   this->Controls->Add(this->Number9);
			   this->Controls->Add(this->Number8);
			   this->Controls->Add(this->Number7);
			   this->Controls->Add(this->Number6);
			   this->Controls->Add(this->Number5);
			   this->Controls->Add(this->Number4);
			   this->Controls->Add(this->Number3);
			   this->Controls->Add(this->Number2);
			   this->Controls->Add(this->Number1);
			   this->Controls->Add(this->Number0);
			   this->Controls->Add(this->equals);
			   this->Controls->Add(this->Dot);
			   this->Controls->Add(this->CloseBracket);
			   this->Controls->Add(this->OpenBracket);
			   this->Controls->Add(this->Plus);
			   this->Controls->Add(this->ReversePlusMinus);
			   this->Controls->Add(this->Minus);
			   this->Controls->Add(this->factorial);
			   this->Controls->Add(this->multiply);
			   this->Controls->Add(this->NumberPi);
			   this->Controls->Add(this->divide);
			   this->Controls->Add(this->Backspace);
			   this->Controls->Add(this->Clear);
			   this->Controls->Add(this->ClearAll);
			   this->Controls->Add(this->ndPower2);
			   this->Controls->Add(this->Mod);
			   this->Controls->Add(this->exponent);
			   this->Controls->Add(this->Log);
			   this->Controls->Add(this->Power10X);
			   this->Controls->Add(this->Sqrt);
			   this->Controls->Add(this->Tan);
			   this->Controls->Add(this->Cos);
			   this->Controls->Add(this->Sin);
			   this->Controls->Add(this->powerXY);
			   this->Controls->Add(this->powerX2);
			   this->Controls->Add(this->textBox1);
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			   this->Text = L"Calculator";
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
		Obracket = 0;
		Cbracket = 0;
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) { // CE
		textBox1->Text = "0";
		textBox2->Text = "";
		Obracket = 0;
		Cbracket = 0;
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) { // delete last symbol, backspace
		String^ tb1;
		try {
			String^ str = textBox1->Text;
			tb1 = str;
			if (textBox1->Text->Length > 0) str = textBox1->Text->Substring(0, textBox1->Text->Length - 1);
			if ((textBox1->Text == "0") && (textBox2->Text->Length > 0)) {
				textBox1->Text = textBox2->Text;
				textBox2->Text = "";
				str = textBox1->Text->Substring(0, textBox1->Text->Length - 1);
			}
			if (textBox1->Text->Length == 1 || (textBox1->Text->Length == 2 && textBox1->Text->LastIndexOf("-") == 0)) str = "0";

			textBox1->Text = str;
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // x^2	x^3
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp *= temp;
				textBox1->Text = System::Convert::ToString(temp);
			}
			else if (ndSelector == 1) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp *= temp * temp;
				textBox1->Text = System::Convert::ToString(temp);
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //x^y	sqrt(x), y
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				textBox2->Text += System::Convert::ToString(str) + " ^ ";
				textBox1->Text = str;
				TextBoxZeroCounter = 0;
			}
			else if (ndSelector == 1) {
				String^ str = textBox1->Text;
				tb1 = str;
				textBox2->Text += System::Convert::ToString(str) + " s ";
				textBox1->Text = str;
				TextBoxZeroCounter = 0;
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { //sin	sin^-1 
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = sin(temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
			else if (ndSelector == 1) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = 1 / (sin(temp));
				textBox1->Text = System::Convert::ToString(temp);
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { //cos cos^-1 
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = cos(temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
			else if (ndSelector == 1) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = 1 / (cos(temp));
				textBox1->Text = System::Convert::ToString(temp);
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { //tan	tan^-1 
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = tan(temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
			else if (ndSelector == 1) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = 1 / (tan(temp));
				textBox1->Text = System::Convert::ToString(temp);
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { //sqrt(x)	1/x
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = sqrt(temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
			else if (ndSelector == 1) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = 1 / temp;
				textBox1->Text = System::Convert::ToString(temp);
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { // 10^x	e^x
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = pow(10, temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
			else if (ndSelector == 1) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = pow(ee, temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { // log	ln
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = log10(temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
			else if (ndSelector == 1) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = log(temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) { // Exp	dms
		String^ tb1;
		try {
			if (ndSelector == 0) {
				String^ str = textBox1->Text;
				tb1 = str;
				double temp = System::Convert::ToDouble(str);
				temp = exp(temp);
				textBox1->Text = System::Convert::ToString(temp);
			}
			else if (ndSelector == 1) {
			}
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) { // Mod deg
		if (ndSelector == 0) {
			String^ str = textBox1->Text;
			textBox2->Text += System::Convert::ToString(str) + " % ";
			textBox1->Text = str;
			TextBoxZeroCounter = 0;
		}
		else if (ndSelector == 1) {
		}
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) { //2^nd 
		if (ndSelector == 1) {
			powerX2->Text = "x^2";
			powerXY->Text = "x^y";
			Sin->Text = "sin";
			Cos->Text = "cos";
			Tan->Text = "tan";
			Sqrt->Text = "sqrt(x)";
			Power10X->Text = "10^x";
			Log->Text = "log";
			exponent->Text = "Exp";
			Mod->Text = "Mod";

			ndSelector = 0;
		}
		else if (ndSelector == 0) {
			powerX2->Text = "x^3";
			powerXY->Text = "sqrt(x), y";
			Sin->Text = "sin^-1";
			Cos->Text = "cos^-1";
			Tan->Text = "tan^-1";
			Sqrt->Text = "1/x";
			Power10X->Text = "e^x";
			Log->Text = "ln";
			exponent->Text = "dms";
			Mod->Text = "deg";

			ndSelector = 1;
		}
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) { // /
		String^ str = textBox1->Text;
		textBox2->Text += System::Convert::ToString(str) + " / ";
		textBox1->Text = str;
		TextBoxZeroCounter = 0;
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) { // Pi
		textBox1->Text = System::Convert::ToString(3.1415926535897932384626433832795);
	}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) { // *
		String^ str = textBox1->Text;
		textBox2->Text += System::Convert::ToString(str) + " * ";
		textBox1->Text = str;
		TextBoxZeroCounter = 0;
	}
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) { // !n
		String^ tb1;
		try {
			tb1 = textBox1->Text;
			double ch = System::Convert::ToDouble(textBox1->Text);
			double whole = 0.0, fractional = 0.0;
			fractional = modf(ch, &whole);
			if (fractional == 0.) {
				textBox1->Text = System::Convert::ToString(fact(ch));
			}
			else
				textBox1->Text = System::Convert::ToString(std::tgamma(ch + 1));
			factI = 0;
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) { // -
		String^ str = textBox1->Text;
		textBox2->Text += System::Convert::ToString(str) + " - ";
		textBox1->Text = str;
		TextBoxZeroCounter = 0;
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) { // "+/-"
		String^ tb1;
		try {
			String^ str = textBox1->Text;
			tb1 = str;
			double temp = System::Convert::ToDouble(str);
			temp = temp * -1;
			textBox1->Text = System::Convert::ToString(temp);
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) { // +
		String^ str = textBox1->Text;
		textBox2->Text += System::Convert::ToString(str) + " + ";
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
		numberInput(" ( ");
	}
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) { // )
		if (Cbracket < Obracket) {
			numberInput(" ) ");
			Cbracket++;
		}
	}
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) { // =
		String^ tb1;
		try {
			while (Cbracket != Obracket) {
				numberInput(" ) ");
				Cbracket++;
			}

			String^ str = textBox2->Text + textBox1->Text;
			tb1 = str;

			if (str->Contains("/0")) {
				textBox1->Text = "Cannot divide by zero";
				return;
			}

			std::string sstr = msclr::interop::marshal_as<std::string>(str);

			textBox1->Text = System::Convert::ToString(RPN(sstr));
			textBox2->Text = "";
			TextBoxZeroCounter = 2;
		}
		catch (...) {
			FILE* LogFile = fopen("Exceptions.log", "a+");
			fprintf(LogFile, "%s, %s\n", __FUNCTION__, tb1);
			fclose(LogFile);
		}
	}

	};
}
