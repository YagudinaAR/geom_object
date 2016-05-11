#pragma once
#include"shape.h"
#include"Gtable.h"
namespace Igraphics {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;


	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::RadioButton^  radioButton4;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(669, 343);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"clear";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(796, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"points";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(951, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(669, 48);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(48, 17);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"point";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(669, 71);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(41, 17);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"line";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(669, 94);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(51, 17);
			this->radioButton3->TabIndex = 5;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"move";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(908, 343);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::DarkTurquoise;
			this->panel1->Location = System::Drawing::Point(3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(660, 364);
			this->panel1->TabIndex = 9;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseDown);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel1_MouseUp);
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(751, 48);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(135, 289);
			this->panel2->TabIndex = 10;
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(908, 48);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(137, 289);
			this->panel3->TabIndex = 0;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(669, 117);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(65, 17);
			this->radioButton4->TabIndex = 0;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"del point";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkTurquoise;
			this->ClientSize = System::Drawing::Size(1057, 378);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Gtable *s= new Gtable();
		Tpoint *p1, *p2, *pnt=NULL;
		int x, y, x0, y0;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		x = y = x0 = y0 = 0;
	}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{
}
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
{
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	panel1->Refresh();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Application::Exit();
}

private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	x = e->X;
	y = e->Y;

	if (radioButton3->Checked)
	{
		if (s->findpoint(x, y))
		{
			Graphics^ g = this->panel1->CreateGraphics();
			Ipoint *pn = new Ipoint(s->findpoint(x, y));
			pn->Hide(g);
		}
		if (s->findline(x, y))
		{
			Graphics^ g1 = this->panel1->CreateGraphics();
			Iline *ln = new Iline(s->findline(x, y)->l, s->findline(x, y)->r);
			ln->Hide(g1);
		}

	}



}

private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
	x0 = e->X;
	y0 = e->Y;
	Graphics^ g = this->panel1->CreateGraphics();
	if (radioButton1->Checked)
	{
		Tpoint *p = new Tpoint(x0, y0);
		Ipoint *pp = new Ipoint(p);
		s->add(pp);
		pp->Show(g);
		s->draw(panel2);
	}
	if (radioButton2->Checked)
	{
		Tpoint *p1 = new Tpoint( x,y);
		if (s->findpoint(x0, y0))
		{
			Tpoint *p2 = new Tpoint(x0,y0);
			Iline *ln = new Iline(p1, p2);
			s->add(ln);
			ln->Show(g);
		}
	}
	if (radioButton3->Checked)
	{
		
		if (s->findpoint(x, y))
		{
			if (s->findline(x, y))
			{
				Graphics^ g1 = this->panel1->CreateGraphics();
				Iline *ln = new Iline(s->findline(x, y)->l, s->findline(x, y)->r);
				ln->setmove(s->findpoint(x, y), e->X, e->Y);
				ln->Show(g1);
			}
			Graphics^ g2 = this->panel1->CreateGraphics();
			Ipoint *pn = new Ipoint(s->findpoint(x, y));
			pn->setmove(e->X, e->Y);
			pn->Show(g2);

		}

	}

	if (radioButton4->Checked)
	{
		if (s->findline(x0, y0))
			s->delline(s->findline(x0, y0), g);
		if (s->findpoint(x0, y0))
			s->delpoint(x0, y0,g);
	}
}


};
}
