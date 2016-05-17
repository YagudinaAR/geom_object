#pragma once
#include"shape.h"
#include"Gtable.h"
#include"htable.h"
#include<iostream>
#include <math.h>
namespace Igraphics {

	using namespace std;
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
	private: System::Windows::Forms::RadioButton^  rpoint;
	private: System::Windows::Forms::RadioButton^  rline;
	private: System::Windows::Forms::RadioButton^  rmove;







	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::RadioButton^  rdelete;
	private: System::Windows::Forms::RadioButton^  rcircle;
	private: System::Windows::Forms::RadioButton^  rrectangle;




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
			this->rpoint = (gcnew System::Windows::Forms::RadioButton());
			this->rline = (gcnew System::Windows::Forms::RadioButton());
			this->rmove = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->rdelete = (gcnew System::Windows::Forms::RadioButton());
			this->rcircle = (gcnew System::Windows::Forms::RadioButton());
			this->rrectangle = (gcnew System::Windows::Forms::RadioButton());
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
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"display";
			// 
			// rpoint
			// 
			this->rpoint->AutoSize = true;
			this->rpoint->Location = System::Drawing::Point(669, 48);
			this->rpoint->Name = L"rpoint";
			this->rpoint->Size = System::Drawing::Size(48, 17);
			this->rpoint->TabIndex = 3;
			this->rpoint->TabStop = true;
			this->rpoint->Text = L"point";
			this->rpoint->UseVisualStyleBackColor = true;
			// 
			// rline
			// 
			this->rline->AutoSize = true;
			this->rline->Location = System::Drawing::Point(669, 71);
			this->rline->Name = L"rline";
			this->rline->Size = System::Drawing::Size(41, 17);
			this->rline->TabIndex = 4;
			this->rline->TabStop = true;
			this->rline->Text = L"line";
			this->rline->UseVisualStyleBackColor = true;
			// 
			// rmove
			// 
			this->rmove->AutoSize = true;
			this->rmove->Location = System::Drawing::Point(669, 140);
			this->rmove->Name = L"rmove";
			this->rmove->Size = System::Drawing::Size(51, 17);
			this->rmove->TabIndex = 5;
			this->rmove->TabStop = true;
			this->rmove->Text = L"move";
			this->rmove->UseVisualStyleBackColor = true;
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
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
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
			// rdelete
			// 
			this->rdelete->AutoSize = true;
			this->rdelete->Location = System::Drawing::Point(669, 163);
			this->rdelete->Name = L"rdelete";
			this->rdelete->Size = System::Drawing::Size(65, 17);
			this->rdelete->TabIndex = 0;
			this->rdelete->TabStop = true;
			this->rdelete->Text = L"del point";
			this->rdelete->UseVisualStyleBackColor = true;
			// 
			// rcircle
			// 
			this->rcircle->AutoSize = true;
			this->rcircle->Location = System::Drawing::Point(669, 94);
			this->rcircle->Name = L"rcircle";
			this->rcircle->Size = System::Drawing::Size(50, 17);
			this->rcircle->TabIndex = 11;
			this->rcircle->TabStop = true;
			this->rcircle->Text = L"circle";
			this->rcircle->UseVisualStyleBackColor = true;
			// 
			// rrectangle
			// 
			this->rrectangle->AutoSize = true;
			this->rrectangle->Location = System::Drawing::Point(669, 117);
			this->rrectangle->Name = L"rrectangle";
			this->rrectangle->Size = System::Drawing::Size(69, 17);
			this->rrectangle->TabIndex = 12;
			this->rrectangle->TabStop = true;
			this->rrectangle->Text = L"rectangle";
			this->rrectangle->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkTurquoise;
			this->ClientSize = System::Drawing::Size(1057, 378);
			this->Controls->Add(this->rrectangle);
			this->Controls->Add(this->rcircle);
			this->Controls->Add(this->rdelete);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->rmove);
			this->Controls->Add(this->rline);
			this->Controls->Add(this->rpoint);
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
		Gtable *table= new Gtable();
		htable *tbl2 = new htable();
		Tpoint *tp1, *tp2,*tp3, *pnt=NULL;
		Ipoint *p1, *p2;
		Iline *ln = NULL;
		Icircle *cl = NULL;
		Irectangle *rc = NULL;
		int x, y, x0, y0;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		x = y = x0 = y0 = 0;
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
	tp2 = new Tpoint(e->X, e->Y);
	shape *s = table->findpoint(tp2);
	if ((rline->Checked) || (rmove->Checked) || (rcircle->Checked) || (rrectangle->Checked))
	{
		if (s != NULL)
			pnt = s->getbasepoint();
	}

}

	private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		tp1 = new Tpoint(e->X, e->Y);
		Graphics^ g = panel1->CreateGraphics();
		if (rpoint->Checked)
		{
			p1 = new Ipoint(tp1);
			table->add(p1);
			p1->Show(g);
			tbl2->addpoint(p1);
			tbl2->show(panel2, panel3);
		}

		if (rline->Checked)
		{
			shape *s = table->findpoint(tp1);
			if (s != NULL)
			{
				ln = new Iline(pnt, s->getbasepoint());
				table->add(ln);
				ln->Show(g);
			}
			else throw"not found point";

		}

		if (rrectangle->Checked)
		{
			shape *s = table->findpoint(tp1);
			if (s != NULL)
			{
				rc = new Irectangle(pnt, s->getbasepoint());
				table->add(rc);
				rc->Show(g);
			}
			else throw"not found point";
		}

		if (rcircle->Checked)
		{
			shape *s = table->findpoint(tp1);
			if (s != NULL)
			{
				cl = new Icircle(pnt, s->getbasepoint());
				table->add(cl);
				cl->Show(g);
			}
			else throw"not found point";
		}

		if (rmove->Checked)
		{
			Ipoint *pn = (Ipoint*)table->findpoint(tp2);
			shape *s=table->findpoint(pnt);
			if (s != NULL)
			{
				s->getbasepoint()->setmove(*tp1);
				Refresh();
				tbl2->add((Ipoint*)pn,tp1);
				tbl2->show(panel2, panel3);
			}

		}

		if (rdelete->Checked)
		{
			shape *s = table->findpoint(tp1);
			if (s != NULL)
			{
				table->del(s->getbasepoint());
				Refresh();
				tbl2->delIpoint((Ipoint*)s);
				tbl2->show(panel2, panel3);
			}
		}

	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		table->show(e->Graphics);
	}


};
}
