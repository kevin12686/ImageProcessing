#pragma once
#include <stack>
#include <regex>
#include <cmath>
#include <msclr/marshal_cppstd.h>
#include "InputForm.h"
#include "StrechForm.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int *arr, int front, int end) {
	int pivot = arr[end];
	int i = front - 1;
	for (int j = front; j < end; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	i++;
	swap(&arr[i], &arr[end]);
	return i;
}
void QuickSort(int *arr, int front, int end) {
	if (front < end) {
		int pivot = Partition(arr, front, end);
		QuickSort(arr, front, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

unsigned char mean(int size, int* arr) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum / size;
}

unsigned char median(int size, int* arr) {
	QuickSort(arr, 0, size);
	if (size % 2 == 0) {
		return (arr[int(size / 2)] + arr[int(size / 2 - 1)]) / 2;
	}
	else {
		return arr[int(size / 2)];
	}
}

int TH = 75;
unsigned char threshold(int size, int*arr) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum >= TH ? 255 : 0;
}

namespace ImageProcessing {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	typedef struct ArrayRGB {
		unsigned char*** arr;
		int Height;
		int Width;
	}arrayRGB;

	public class Status {
	public:
		arrayRGB ori_pic;
		arrayRGB first_pic;
		arrayRGB second_pic;
		arrayRGB third_pic;
		string first_label;
		string second_label;
		string third_label;
	};

	stack <Status*>history;

	int source = 0;

	/// <summary>
	/// MainForm 的摘要
	/// </summary>

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox_s;
	protected:

	protected:

	private: System::Windows::Forms::GroupBox^  groupBox_function;
	private: System::Windows::Forms::Button^  button7;

	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button_open;
	private: System::Windows::Forms::Button^  button_save;


	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button2;



	private: System::Windows::Forms::Button^  button12;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::PictureBox^  pictureBox_1;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label_1;

	private: System::Windows::Forms::Button^  button_undo;
	private: System::Windows::Forms::Label^  label_3;




	private: System::Windows::Forms::OpenFileDialog^  openFileDialog_read;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog_save;
	private: System::Windows::Forms::Button^  button15;

	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button17;

	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::PictureBox^  pictureBox_2;
	private: System::Windows::Forms::PictureBox^  pictureBox_3;
	private: System::Windows::Forms::Label^  label_2;



	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox_s = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox_function = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button_open = (gcnew System::Windows::Forms::Button());
			this->button_save = (gcnew System::Windows::Forms::Button());
			this->pictureBox_1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_1 = (gcnew System::Windows::Forms::Label());
			this->button_undo = (gcnew System::Windows::Forms::Button());
			this->label_3 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog_read = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog_save = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pictureBox_2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_3 = (gcnew System::Windows::Forms::PictureBox());
			this->label_2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_s))->BeginInit();
			this->groupBox_function->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox_s
			// 
			this->pictureBox_s->Location = System::Drawing::Point(18, 15);
			this->pictureBox_s->Name = L"pictureBox_s";
			this->pictureBox_s->Size = System::Drawing::Size(320, 240);
			this->pictureBox_s->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_s->TabIndex = 0;
			this->pictureBox_s->TabStop = false;
			this->pictureBox_s->Click += gcnew System::EventHandler(this, &MainForm::pictureBox_s_Click);
			// 
			// groupBox_function
			// 
			this->groupBox_function->Controls->Add(this->button1);
			this->groupBox_function->Controls->Add(this->button2);
			this->groupBox_function->Controls->Add(this->button15);
			this->groupBox_function->Controls->Add(this->button5);
			this->groupBox_function->Controls->Add(this->button11);
			this->groupBox_function->Controls->Add(this->button17);
			this->groupBox_function->Controls->Add(this->button6);
			this->groupBox_function->Controls->Add(this->button19);
			this->groupBox_function->Controls->Add(this->button12);
			this->groupBox_function->Controls->Add(this->button4);
			this->groupBox_function->Controls->Add(this->button7);
			this->groupBox_function->Controls->Add(this->button16);
			this->groupBox_function->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox_function->Location = System::Drawing::Point(12, 577);
			this->groupBox_function->Name = L"groupBox_function";
			this->groupBox_function->Size = System::Drawing::Size(685, 216);
			this->groupBox_function->TabIndex = 1;
			this->groupBox_function->TabStop = false;
			this->groupBox_function->Text = L"Function";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(188, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(273, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Color extraction (1)";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 33);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(176, 39);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Grayscale (1)";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(-526, 213);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(127, 39);
			this->button15->TabIndex = 0;
			this->button15->Text = L"button1";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(6, 123);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(176, 39);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Median filter (2)";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(6, 78);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(176, 39);
			this->button11->TabIndex = 0;
			this->button11->Text = L"Mean filter (2)";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MainForm::button11_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(188, 123);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(273, 39);
			this->button17->TabIndex = 0;
			this->button17->Text = L"Binarization (4)";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MainForm::button17_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(467, 123);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(212, 39);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Image stretching (7)";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(467, 78);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(212, 39);
			this->button19->TabIndex = 0;
			this->button19->Text = L"Image rotation (7)";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MainForm::button19_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(467, 33);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(212, 39);
			this->button12->TabIndex = 0;
			this->button12->Text = L"Edge overlap (6)";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MainForm::button12_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(188, 168);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(273, 39);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Edge detection (5)";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(188, 78);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(273, 39);
			this->button7->TabIndex = 0;
			this->button7->Text = L"Histogram equalization (3)";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(139, -29);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(127, 23);
			this->button16->TabIndex = 0;
			this->button16->Text = L"button1";
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button_open
			// 
			this->button_open->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_open->Location = System::Drawing::Point(18, 810);
			this->button_open->Name = L"button_open";
			this->button_open->Size = System::Drawing::Size(127, 39);
			this->button_open->TabIndex = 0;
			this->button_open->Text = L"Open";
			this->button_open->UseVisualStyleBackColor = true;
			this->button_open->Click += gcnew System::EventHandler(this, &MainForm::button_open_Click);
			// 
			// button_save
			// 
			this->button_save->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_save->Location = System::Drawing::Point(158, 810);
			this->button_save->Name = L"button_save";
			this->button_save->Size = System::Drawing::Size(127, 39);
			this->button_save->TabIndex = 0;
			this->button_save->Text = L"Save";
			this->button_save->UseVisualStyleBackColor = true;
			this->button_save->Click += gcnew System::EventHandler(this, &MainForm::button_save_Click);
			// 
			// pictureBox_1
			// 
			this->pictureBox_1->Location = System::Drawing::Point(367, 15);
			this->pictureBox_1->Name = L"pictureBox_1";
			this->pictureBox_1->Size = System::Drawing::Size(320, 240);
			this->pictureBox_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_1->TabIndex = 0;
			this->pictureBox_1->TabStop = false;
			this->pictureBox_1->Click += gcnew System::EventHandler(this, &MainForm::pictureBox_1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(20, 260);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Original (0)";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1
			// 
			this->label_1->AutoSize = true;
			this->label_1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_1->Location = System::Drawing::Point(370, 260);
			this->label_1->Name = L"label_1";
			this->label_1->Size = System::Drawing::Size(50, 25);
			this->label_1->TabIndex = 2;
			this->label_1->Text = L"Null";
			this->label_1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_undo
			// 
			this->button_undo->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_undo->Location = System::Drawing::Point(560, 810);
			this->button_undo->Name = L"button_undo";
			this->button_undo->Size = System::Drawing::Size(127, 39);
			this->button_undo->TabIndex = 0;
			this->button_undo->Text = L"Undo";
			this->button_undo->UseVisualStyleBackColor = true;
			this->button_undo->Click += gcnew System::EventHandler(this, &MainForm::button_undo_Click);
			// 
			// label_3
			// 
			this->label_3->AutoSize = true;
			this->label_3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_3->Location = System::Drawing::Point(370, 537);
			this->label_3->Name = L"label_3";
			this->label_3->Size = System::Drawing::Size(50, 25);
			this->label_3->TabIndex = 2;
			this->label_3->Text = L"Null";
			this->label_3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openFileDialog_read
			// 
			this->openFileDialog_read->Filter = L"點陣圖 (*.bmp) | *.bmp";
			this->openFileDialog_read->Title = L"讀取影像";
			// 
			// saveFileDialog_read
			// 
			this->saveFileDialog_save->Filter = L"點陣圖 (*.bmp) | *.bmp";
			this->saveFileDialog_save->SupportMultiDottedExtensions = true;
			this->saveFileDialog_save->DefaultExt = L"txt";
			this->saveFileDialog_save->FileName = L"output";
			this->saveFileDialog_save->Title = L"儲存影像";
			// 
			// pictureBox_2
			// 
			this->pictureBox_2->Location = System::Drawing::Point(18, 288);
			this->pictureBox_2->Name = L"pictureBox_2";
			this->pictureBox_2->Size = System::Drawing::Size(320, 240);
			this->pictureBox_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_2->TabIndex = 0;
			this->pictureBox_2->TabStop = false;
			this->pictureBox_2->Click += gcnew System::EventHandler(this, &MainForm::pictureBox_2_Click);
			// 
			// pictureBox_3
			// 
			this->pictureBox_3->Location = System::Drawing::Point(367, 288);
			this->pictureBox_3->Name = L"pictureBox_3";
			this->pictureBox_3->Size = System::Drawing::Size(320, 240);
			this->pictureBox_3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_3->TabIndex = 0;
			this->pictureBox_3->TabStop = false;
			this->pictureBox_3->Click += gcnew System::EventHandler(this, &MainForm::pictureBox_3_Click);
			// 
			// label_2
			// 
			this->label_2->AutoSize = true;
			this->label_2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_2->Location = System::Drawing::Point(20, 537);
			this->label_2->Name = L"label_2";
			this->label_2->Size = System::Drawing::Size(50, 25);
			this->label_2->TabIndex = 2;
			this->label_2->Text = L"Null";
			this->label_2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(709, 862);
			this->Controls->Add(this->label_2);
			this->Controls->Add(this->label_3);
			this->Controls->Add(this->label_1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox_function);
			this->Controls->Add(this->pictureBox_2);
			this->Controls->Add(this->pictureBox_3);
			this->Controls->Add(this->pictureBox_1);
			this->Controls->Add(this->pictureBox_s);
			this->Controls->Add(this->button_undo);
			this->Controls->Add(this->button_open);
			this->Controls->Add(this->button_save);
			this->MaximumSize = System::Drawing::Size(727, 909);
			this->MinimumSize = System::Drawing::Size(727, 909);
			this->Name = L"MainForm";
			this->Text = L"Image Processing";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_s))->EndInit();
			this->groupBox_function->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: arrayRGB cloneArrayRGB(arrayRGB arr) {
		arrayRGB temp;
		temp.Height = arr.Height;
		temp.Width = arr.Width;
		temp.arr = new unsigned char**[temp.Height];
		for (int i = 0; i < arr.Height; i++) {
			temp.arr[i] = new unsigned char*[temp.Width];
			for (int j = 0; j < arr.Width; j++) {
				temp.arr[i][j] = new unsigned char[3];
				for (int k = 0; k < 3; k++) {
					temp.arr[i][j][k] = arr.arr[i][j][k];
				}
			}
		}
		return temp;
	}

	private: arrayRGB kernelSlide(arrayRGB pic, int size, int** kenel, bool zero, unsigned char(*fp)(int, int*)) {
		arrayRGB temp = cloneArrayRGB(pic);
		int center = (size - 1) / 2;
		int kenel_len = size * size;

		int k = pic.Height, l = pic.Width;
		if (!zero) {
			k -= center;
			l -= center;
		}

		for (int h = 0; h < 3; h++) {
			for (int i = zero ? 0 : center; i < k; i++) {
				for (int j = zero ? 0 : center; j < l; j++) {
					int* flaten = new int[kenel_len];

					// Kernel
					for (int m = 0; m < size; m++) {
						for (int n = 0; n < size; n++) {
							int x = j - n + center;
							int y = i - m + center;
							if (x < 0 || y < 0 || x >= pic.Width || y >= pic.Height) {
								flaten[m*size + n] = 0;
							}
							else {
								flaten[m*size + n] = pic.arr[y][x][h] * kenel[m][n];
							}
						}
					}

					temp.arr[i][j][h] = (*fp)(kenel_len, flaten);
				}
			}
		}
		return temp;
	}

	private: arrayRGB histogram(arrayRGB img) {
		const int max_width = 240;
		int* lev_count = new int[256];
		for (int i = 0; i < 256; i++) {
			lev_count[i] = 0;
		}
		int count_max = 0;
		for (int i = 0; i < img.Height; i++) {
			for (int j = 0; j < img.Width; j++) {
				lev_count[img.arr[i][j][0]]++;
				if (lev_count[img.arr[i][j][0]] > count_max)
					count_max = lev_count[img.arr[i][j][0]];
			}
		}

		arrayRGB hg;
		hg.Height = max_width;
		hg.Width = 256;
		hg.arr = new unsigned char**[hg.Height];
		for (int i = 0; i < hg.Height; i++) {
			hg.arr[i] = new unsigned char*[hg.Width];
			for (int j = 0; j < hg.Width; j++) {
				hg.arr[i][j] = new unsigned char[3]{ 255, 255, 255 };
			}
		}

		for (int i = 0; i < hg.Width; i++) {
			int t = hg.Height - int(lev_count[i] * hg.Height / count_max);
			for (int j = hg.Height - 1; j >= t; j--) {
				hg.arr[j][i][0] = 0;
				hg.arr[j][i][1] = 0;
				hg.arr[j][i][2] = 0;
			}
		}
		return hg;
	}

	private: arrayRGB histogramEQ(arrayRGB img) {
		arrayRGB hg;
		hg.Height = img.Height;
		hg.Width = img.Width;
		hg.arr = new unsigned char**[hg.Height];
		for (int i = 0; i < hg.Height; i++) {
			hg.arr[i] = new unsigned char*[hg.Width];
			for (int j = 0; j < hg.Width; j++) {
				hg.arr[i][j] = new unsigned char[3];
			}
		}
		int total_pixel = img.Height * img.Width;

		for (int h = 0; h < 3; h++) {
			int* lev_count = new int[256];
			for (int i = 0; i < 256; i++) {
				lev_count[i] = 0;
			}
			for (int i = 0; i < img.Height; i++) {
				for (int j = 0; j < img.Width; j++) {
					lev_count[img.arr[i][j][h]]++;
				}
			}
			for (int i = 255; i > -1; i--) {
				int sum = lev_count[i];
				for (int j = 0; j < i; j++) {
					sum += lev_count[j];
				}
				lev_count[i] = sum;
			}
			int cdf_min = lev_count[0];

			int* map_lev = new int[256];
			for (int i = 0; i < 256; i++) {
				map_lev[i] = int(round((lev_count[i] - cdf_min) * 255 / (total_pixel - cdf_min)));
			}

			for (int i = 0; i < hg.Height; i++) {
				for (int j = 0; j < hg.Width; j++) {
					hg.arr[i][j][h] = map_lev[img.arr[i][j][h]];
				}
			}
		}
		return hg;
	}

	private: int* findboundary(arrayRGB img, int theta) {
		double angle = 3.14159265358979323846 * theta / 180.0;

		int** point = new int*[4];
		point[0] = new int[2]{ 0, 0 };
		point[1] = new int[2]{ img.Width - 1, 0 };
		point[2] = new int[2]{ 0, img.Height - 1 };
		point[3] = new int[2]{ img.Width - 1, img.Height - 1 };

		double** newPoint = new double*[4];
		for (int i = 0; i < 4; i++) {
			newPoint[i] = new double[2]{ cos(angle) * point[i][0] + sin(angle) * point[i][1] , cos(angle) * point[i][1] - sin(angle) * point[i][0] };
		}

		double min_x = min(newPoint[0][0], min(newPoint[1][0], min(newPoint[2][0], newPoint[3][0])));
		double max_x = max(newPoint[0][0], max(newPoint[1][0], max(newPoint[2][0], newPoint[3][0])));
		double min_y = min(newPoint[0][1], min(newPoint[1][1], min(newPoint[2][1], newPoint[3][1])));
		double max_y = max(newPoint[0][1], max(newPoint[1][1], max(newPoint[2][1], newPoint[3][1])));
		return new int[2]{ int(max_x - min_x + 1), int(max_y - min_y + 1) };
	}

	private: arrayRGB rotation(arrayRGB img, int theta) {
		theta %= 360;
		theta = 360 - theta;
		int* boundary = findboundary(img, theta);
		int oldWidth = img.Width;
		int oldHeight = img.Height;
		int oldCenterX = (oldWidth - 1) / 2;
		int oldCenterY = (oldHeight - 1) / 2;

		int newWidth = boundary[0];
		int newHeight = boundary[1];
		int newCenterX = (newWidth - 1) / 2;
		int newCenterY = (newHeight - 1) / 2;

		arrayRGB newImg;
		newImg.Height = newHeight;
		newImg.Width = newWidth;
		newImg.arr = new unsigned char**[newImg.Height];
		for (int i = 0; i < newImg.Height; i++) {
			newImg.arr[i] = new unsigned char*[newImg.Width];
			for (int j = 0; j < newImg.Width; j++) {
				newImg.arr[i][j] = new unsigned char[3]{ 0, 0, 0 };
			}
		}

		theta = (360 - theta) % 360;
		double angle = 3.14159265358979323846 * theta / 180.0;

		double sinT = sin(angle);
		double cosT = cos(angle);

		for (int i = 0; i < newHeight; i++) {
			for (int j = 0; j < newWidth; j++) {

				int refX = int(round(cosT * (j - newCenterX) + sinT * (i - newCenterY))) + oldCenterX;
				int refY = int(round(-sinT * (j - newCenterX) + cosT * (i - newCenterY))) + oldCenterY;
				if (refX >= 0 && refX < img.Width && refY >= 0 && refY < img.Height) {
					newImg.arr[i][j] = img.arr[refY][refX];
				}
			}
		}

		return newImg;
	}

	private: arrayRGB stretch(arrayRGB img, int width, int height) {
		int oldWidth = img.Width;
		int oldHeight = img.Height;

		int newWidth = width;
		int newHeight = height;

		double scale_w = double(oldWidth) / newWidth;
		double scale_h = double(oldHeight) / newHeight;

		arrayRGB newImg;
		newImg.Height = newHeight;
		newImg.Width = newWidth;
		newImg.arr = new unsigned char**[newImg.Height];
		for (int i = 0; i < newImg.Height; i++) {
			newImg.arr[i] = new unsigned char*[newImg.Width];
			for (int j = 0; j < newImg.Width; j++) {
				newImg.arr[i][j] = new unsigned char[3]{ 0, 0, 0 };
			}
		}

		for (int i = 0; i < newHeight; i++) {
			for (int j = 0; j < newWidth; j++) {

				int refX = int(round(j * scale_w));
				int refY = int(round(i * scale_h));
				if (refX >= 0 && refX < img.Width && refY >= 0 && refY < img.Height) {
					newImg.arr[i][j] = img.arr[refY][refX];
				}
			}
		}

		return newImg;
	}

	private: System::Void pictureBox_s_Click(System::Object^  sender, System::EventArgs^  e) {
		source = 0;
		label1->Text = "Original (0)";
	}

	private: System::Void pictureBox_1_Click(System::Object^  sender, System::EventArgs^  e) {
		source = 1;
		label1->Text = "Original (1)";
	}

	private: System::Void pictureBox_2_Click(System::Object^  sender, System::EventArgs^  e) {
		source = 2;
		label1->Text = "Original (2)";
	}

	private: System::Void pictureBox_3_Click(System::Object^  sender, System::EventArgs^  e) {
		source = 3;
		label1->Text = "Original (3)";
	}

	public: System::Windows::Forms::PictureBox^ get_source() {
		if (source == 1 && pictureBox_1->Image) {
			return pictureBox_1;
		}
		else if (source == 2 && pictureBox_2->Image) {
			return pictureBox_2;
		}
		else if (source == 3 && pictureBox_3->Image) {
			return pictureBox_3;
		}
		else {
			return this->pictureBox_s;
		}
	}

	public: string tostr(String^ s) {
		return msclr::interop::marshal_as<string>(s);
	}

	public: bool isNumber(string token)
	{
		return regex_match(token, regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")));
	}

	public:Void save_status() {
		Status* temp = new Status();
		if (this->pictureBox_s->Image) {
			Bitmap^ b = gcnew Bitmap(this->pictureBox_s->Image);
			temp->ori_pic = map2arr(b);
		}
		else {
			temp->ori_pic = arrayRGB{ NULL, 0, 0 };
		}

		if (this->pictureBox_1->Image) {
			Bitmap^ b = gcnew Bitmap(this->pictureBox_1->Image);
			temp->first_pic = map2arr(b);
		}
		else {
			temp->first_pic = arrayRGB{ NULL, 0, 0 };
		}

		if (this->pictureBox_2->Image) {
			Bitmap^ b = gcnew Bitmap(this->pictureBox_2->Image);
			temp->second_pic = map2arr(b);
		}
		else {
			temp->second_pic = arrayRGB{ NULL, 0, 0 };
		}

		if (this->pictureBox_3->Image) {
			Bitmap^ b = gcnew Bitmap(this->pictureBox_3->Image);
			temp->third_pic = map2arr(b);
		}
		else {
			temp->third_pic = arrayRGB{ NULL, 0, 0 };
		}
		temp->first_label = tostr(this->label_1->Text);
		temp->second_label = tostr(this->label_2->Text);
		temp->third_label = tostr(this->label_3->Text);
		history.push(temp);
	}
	public: arrayRGB map2arr(Bitmap^ bm) {
		if (!bm) return arrayRGB{ NULL, 0, 0 };
		int height = bm->Height;
		int width = bm->Width;
		unsigned char*** arr;
		arr = new unsigned char **[height];
		for (int i = 0; i < height; i++) {
			arr[i] = new unsigned char *[width];
			for (int j = 0; j < width; j++) {
				arr[i][j] = new unsigned char[3];
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				Color color = bm->GetPixel(j, i);
				arr[i][j][0] = color.R;
				arr[i][j][1] = color.G;
				arr[i][j][2] = color.B;
			}
		}
		return arrayRGB{ arr, height, width };
	}

	public: Bitmap^ arr2map(arrayRGB arr) {
		if (!arr.arr) return nullptr;
		int height = arr.Height;
		int width = arr.Width;
		Bitmap^ map = gcnew Bitmap(width, height);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				map->SetPixel(j, i, Color::FromArgb(arr.arr[i][j][0], arr.arr[i][j][1], arr.arr[i][j][2]));
			}
		}
		return map;
	}

	private: System::Void button_open_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog_read->ShowDialog() == System::Windows::Forms::DialogResult::OK && openFileDialog_read->FileName->Length > 0) {
			Bitmap^ image_source = gcnew Bitmap(openFileDialog_read->FileName);
			pictureBox_s->Image = image_source;
			source = 0;
			while (!history.empty())
				history.pop();
			save_status();
		}
	}

	private: System::Void button_save_Click(System::Object^  sender, System::EventArgs^  e) {
		if (pictureBox_s->Image || pictureBox_1->Image || pictureBox_2->Image || pictureBox_3->Image) {
			if (saveFileDialog_save->ShowDialog() == System::Windows::Forms::DialogResult::OK && saveFileDialog_save->FileName->Length > 0) {
				String^ sfd = saveFileDialog_save->FileName;
				if (pictureBox_s->Image) {
					pictureBox_s->Image->Save(sfd->Split('.')[0] + "0." + sfd->Split('.')[1], System::Drawing::Imaging::ImageFormat::Bmp);
				}
				if (pictureBox_1->Image) {
					pictureBox_1->Image->Save(sfd->Split('.')[0] + "1." + sfd->Split('.')[1], System::Drawing::Imaging::ImageFormat::Bmp);
				}
				if (pictureBox_2->Image) {
					pictureBox_2->Image->Save(sfd->Split('.')[0] + "2." + sfd->Split('.')[1], System::Drawing::Imaging::ImageFormat::Bmp);
				}
				if (pictureBox_3->Image) {
					pictureBox_3->Image->Save(sfd->Split('.')[0] + "3." + sfd->Split('.')[1], System::Drawing::Imaging::ImageFormat::Bmp);
				}
			}
		}
		else {
			MessageBox::Show("These is no image.");
		}
	}
	private: System::Void button_undo_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!history.empty()) {
			Status* temp = history.top();
			history.pop();
			if (temp->ori_pic.arr) {
				pictureBox_s->Image = arr2map(temp->ori_pic);
			}
			else {
				pictureBox_s->Image = nullptr;
			}
			if (temp->first_pic.arr) {
				pictureBox_1->Image = arr2map(temp->first_pic);
			}
			else {
				pictureBox_1->Image = nullptr;
			}
			if (temp->second_pic.arr) {
				pictureBox_2->Image = arr2map(temp->second_pic);
			}
			else {
				pictureBox_2->Image = nullptr;
			}
			if (temp->third_pic.arr) {
				pictureBox_3->Image = arr2map(temp->third_pic);
			}
			else {
				pictureBox_3->Image = nullptr;
			}
			label_1->Text = gcnew String(temp->first_label.c_str());
			label_2->Text = gcnew String(temp->second_label.c_str());
			label_3->Text = gcnew String(temp->third_label.c_str());
			delete temp;
		}
		else {
			MessageBox::Show("You should do something.");
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			save_status();
			pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
			source = 0;
			label1->Text = "Original (0)";
			Bitmap^ gray = gcnew Bitmap(pictureBox_s->Image);
			for (int i = 0; i < gray->Height; i++) {
				for (int j = 0; j < gray->Width; j++) {
					Color rgb = gray->GetPixel(j, i);
					int temp = rgb.R * 0.299 + rgb.G * 0.587 + rgb.B * 0.114;
					gray->SetPixel(j, i, Color::FromArgb(temp, temp, temp));
				}
			}
			pictureBox_1->Image = gray;
			label_1->Text = "Gray";
			pictureBox_2->Image = nullptr;
			label_2->Text = "Null";
			pictureBox_3->Image = nullptr;
			label_3->Text = "Null";
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			save_status();
			pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
			source = 0;
			label1->Text = "Original (0)";
			Bitmap^ r = gcnew Bitmap(pictureBox_s->Image);
			for (int i = 0; i < r->Height; i++) {
				for (int j = 0; j < r->Width; j++) {
					Color rgb = r->GetPixel(j, i);
					r->SetPixel(j, i, Color::FromArgb(rgb.R, rgb.R, rgb.R));
				}
			}
			pictureBox_1->Image = r;
			label_1->Text = "Red";
			Bitmap^ g = gcnew Bitmap(pictureBox_s->Image);
			for (int i = 0; i < g->Height; i++) {
				for (int j = 0; j < g->Width; j++) {
					Color rgb = g->GetPixel(j, i);
					g->SetPixel(j, i, Color::FromArgb(rgb.G, rgb.G, rgb.G));
				}
			}
			pictureBox_2->Image = g;
			label_2->Text = "Green";
			Bitmap^ b = gcnew Bitmap(pictureBox_s->Image);
			for (int i = 0; i < b->Height; i++) {
				for (int j = 0; j < b->Width; j++) {
					Color rgb = b->GetPixel(j, i);
					b->SetPixel(j, i, Color::FromArgb(rgb.B, rgb.B, rgb.B));
				}
			}
			pictureBox_3->Image = b;
			label_3->Text = "Blue";
		}
	}

	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			save_status();
			pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
			source = 0;
			label1->Text = "Original (0)";
			arrayRGB temp = map2arr(gcnew Bitmap(pictureBox_s->Image));
			int** kernel;
			kernel = new int*[3];
			for (int i = 0; i < 3; i++) {
				kernel[i] = new int[3];
				for (int j = 0; j < 3; j++) {
					kernel[i][j] = 1;
				}
			}
			pictureBox_1->Image = arr2map(kernelSlide(temp, 3, kernel, false, mean));
			label_1->Text = "Mean filter";
			pictureBox_2->Image = nullptr;
			label_2->Text = "Null";
			pictureBox_3->Image = nullptr;
			label_3->Text = "Null";
		}
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			save_status();
			pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
			source = 0;
			label1->Text = "Original (0)";
			arrayRGB temp = map2arr(gcnew Bitmap(pictureBox_s->Image));
			int** kernel;
			kernel = new int*[3];
			for (int i = 0; i < 3; i++) {
				kernel[i] = new int[3];
				for (int j = 0; j < 3; j++) {
					kernel[i][j] = 1;
				}
			}
			pictureBox_1->Image = arr2map(kernelSlide(temp, 3, kernel, true, median));
			label_1->Text = "Median filter";
			pictureBox_2->Image = nullptr;
			label_2->Text = "Null";
			pictureBox_3->Image = nullptr;
			label_3->Text = "Null";
		}
	}

	private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			InputForm^ form = gcnew InputForm();
			form->setLabelText("Threshold");
			form->ShowDialog();
			string s = tostr(form->getTH());
			int n = -1;
			if (isNumber(s)) {
				n = stoi(s);
			}
			if (n >= 0 && n <= 255) {
				save_status();
				pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
				Bitmap^ binPic = gcnew Bitmap(get_source()->Image);
				source = 0;
				label1->Text = "Original (0)";
				for (int i = 0; i < binPic->Height; i++) {
					for (int j = 0; j < binPic->Width; j++) {
						Color rgb = binPic->GetPixel(j, i);
						int r = rgb.R < n ? 0 : 255;
						int g = rgb.G < n ? 0 : 255;
						int b = rgb.B < n ? 0 : 255;
						binPic->SetPixel(j, i, Color::FromArgb(r, g, b));
					}
				}
				pictureBox_1->Image = binPic;
				label_1->Text = "Binarizition";
				pictureBox_2->Image = nullptr;
				label_2->Text = "Null";
				pictureBox_3->Image = nullptr;
				label_3->Text = "Null";
			}
			else {
				MessageBox::Show("Input must be number from range 0 to 255.");
			}
		}
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			InputForm^ form = gcnew InputForm();
			form->setLabelText("Threshold");
			form->ShowDialog();
			string s = tostr(form->getTH());
			int n = -1;
			if (isNumber(s)) {
				n = stoi(s);
			}
			if (n >= 0 && n <= 255) {
				save_status();
				TH = n;
				pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
				source = 0;
				label1->Text = "Original (0)";
				int** vkernel = new int*[3];
				vkernel[0] = new int[3]{ -1, 0, 1 };
				vkernel[1] = new int[3]{ -1, 0, 1 };
				vkernel[2] = new int[3]{ -1, 0, 1 };
				int** hkernel = new int *[3];
				hkernel[0] = new int[3]{ 1, 1, 1 };
				hkernel[1] = new int[3]{ 0, 0, 0 };
				hkernel[2] = new int[3]{ -1, -1, -1 };

				arrayRGB temp = map2arr(gcnew Bitmap(pictureBox_s->Image));

				pictureBox_1->Image = arr2map(kernelSlide(temp, 3, vkernel, false, threshold));
				label_1->Text = "Vertical";
				pictureBox_2->Image = arr2map(kernelSlide(temp, 3, hkernel, false, threshold));
				label_2->Text = "Horizontal";

				arrayRGB vt = kernelSlide(temp, 3, vkernel, false, threshold);
				arrayRGB ht = kernelSlide(temp, 3, hkernel, false, threshold);
				for (int h = 0; h < 3; h++) {
					for (int i = 0; i < vt.Height; i++) {
						for (int j = 0; j < vt.Width; j++) {
							double vt_v = double(vt.arr[i][j][h]);
							double vt_h = double(ht.arr[i][j][h]);
							int k = int(sqrt(pow(vt_v, 2) + pow(vt_h, 2)));
							temp.arr[i][j][h] = k >= TH ? 255 : 0;
						}
					}
				}

				pictureBox_3->Image = arr2map(temp);
				label_3->Text = "Combined";

			}
			else {
				MessageBox::Show("Input must be number from range 0 to 255.");
			}
		}
	}

	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			InputForm^ form = gcnew InputForm();
			form->setLabelText("Threshold");
			form->ShowDialog();
			string s = tostr(form->getTH());
			int n = -1;
			if (isNumber(s)) {
				n = stoi(s);
			}
			if (n >= 0 && n <= 255) {
				save_status();
				TH = n;
				pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
				source = 0;
				label1->Text = "Original (0)";
				int** vkernel = new int*[3];
				vkernel[0] = new int[3]{ -1, 0, 1 };
				vkernel[1] = new int[3]{ -1, 0, 1 };
				vkernel[2] = new int[3]{ -1, 0, 1 };
				int** hkernel = new int *[3];
				hkernel[0] = new int[3]{ 1, 1, 1 };
				hkernel[1] = new int[3]{ 0, 0, 0 };
				hkernel[2] = new int[3]{ -1, -1, -1 };

				arrayRGB temp = map2arr(gcnew Bitmap(pictureBox_s->Image));

				arrayRGB ori_v = cloneArrayRGB(temp);
				arrayRGB temp_v = kernelSlide(temp, 3, vkernel, false, threshold);
				for (int i = 0; i < ori_v.Height; i++) {
					for (int j = 0; j < ori_v.Width; j++) {
						if (temp_v.arr[i][j][0] == 255) {
							ori_v.arr[i][j][0] = 0;
							ori_v.arr[i][j][1] = 255;
							ori_v.arr[i][j][2] = 0;
						}
					}
				}

				pictureBox_1->Image = arr2map(ori_v);
				label_1->Text = "Vertical (OL)";

				arrayRGB ori_h = cloneArrayRGB(temp);
				arrayRGB temp_h = kernelSlide(temp, 3, hkernel, false, threshold);
				for (int i = 0; i < ori_h.Height; i++) {
					for (int j = 0; j < ori_h.Width; j++) {
						if (temp_h.arr[i][j][0] == 255) {
							ori_h.arr[i][j][0] = 0;
							ori_h.arr[i][j][1] = 255;
							ori_h.arr[i][j][2] = 0;
						}
					}
				}

				pictureBox_2->Image = arr2map(ori_h);
				label_2->Text = "Horizontal (OL)";

				arrayRGB vt = kernelSlide(temp, 3, vkernel, false, threshold);
				arrayRGB ht = kernelSlide(temp, 3, hkernel, false, threshold);

				for (int i = 0; i < vt.Height; i++) {
					for (int j = 0; j < vt.Width; j++) {
						double vt_v = double(vt.arr[i][j][0]);
						double vt_h = double(ht.arr[i][j][0]);
						int k = int(sqrt(pow(vt_v, 2) + pow(vt_h, 2)));
						if (k >= TH) {
							temp.arr[i][j][0] = 0;
							temp.arr[i][j][1] = 255;
							temp.arr[i][j][2] = 0;
						}
					}
				}
				pictureBox_3->Image = arr2map(temp);
				label_3->Text = "Combined (OL)";

			}
			else {
				MessageBox::Show("Input must be number from range 0 to 255.");
			}
		}
	}

	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			save_status();
			pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
			source = 0;
			label1->Text = "Original (0)";
			Bitmap^ ori = gcnew Bitmap(pictureBox_s->Image);
			arrayRGB ori_arr = map2arr(ori);
			arrayRGB eq = histogramEQ(ori_arr);
			pictureBox_1->Image = arr2map(eq);
			label_1->Text = "EQ";
			pictureBox_2->Image = arr2map(histogram(ori_arr));
			label_2->Text = "Histogram (ORI)";
			pictureBox_3->Image = arr2map(histogram(eq));
			label_3->Text = "Histogram (EQ)";
		}
	}

	private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {

			InputForm^ form = gcnew InputForm();
			form->setLabelText("Angle");
			form->ShowDialog();
			string s = tostr(form->getTH());
			int n = -1;
			if (isNumber(s)) {
				save_status();
				n = stoi(s) % 360;
				pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
				source = 0;
				label1->Text = "Original (0)";
				Bitmap^ ori = gcnew Bitmap(pictureBox_s->Image);
				arrayRGB ori_arr = map2arr(ori);
				arrayRGB ro = rotation(ori_arr, n);
				pictureBox_1->Image = arr2map(ro);
				label_1->Text = "Rotated";
				pictureBox_2->Image = nullptr;
				label_2->Text = "Null";

				pictureBox_3->Image = nullptr;
				label_3->Text = "Null";
			}
			else {
				MessageBox::Show("Input must be a number.");
			}
		}
	}

	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (get_source()->Image) {
			StrechForm^ form = gcnew StrechForm();
			form->setWH("320", "240");
			form->ShowDialog();
			string ws = tostr(form->getWidth());
			string hs = tostr(form->getHeight());
			if (isNumber(ws) && isNumber(hs) && stoi(ws) > 0 && stoi(hs) > 0) {
				save_status();
				int new_Width = stoi(ws);
				int new_Height = stoi(hs);
				pictureBox_s->Image = gcnew Bitmap(get_source()->Image);
				source = 0;
				label1->Text = "Original (0)";
				Bitmap^ ori = gcnew Bitmap(pictureBox_s->Image);
				arrayRGB ori_arr = map2arr(ori);

				arrayRGB ro = stretch(ori_arr, new_Width, new_Height);

				pictureBox_1->Image = arr2map(ro);
				label_1->Text = "Stretch";
				pictureBox_2->Image = nullptr;
				label_2->Text = "Null";

				pictureBox_3->Image = nullptr;
				label_3->Text = "Null";
			}
			else {
				MessageBox::Show("Input must be a number.");
			}
		}
	}
	};
}
