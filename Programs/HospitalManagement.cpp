#include <graphics.h>
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <process.h>
#include <dos.h>
class Patient
{
    int id;
    char name[20], address[50];
    char phone[12], disease[20], doctor[20];
    float due;

public:
    void input();
    void display();
    int funid()
    {
        return id;
    }
    void getid()
    {
        cin >> id;
    }
    void fundue(int x)
    {
        due = x;
    }
    void doc()
    {
        if (strcmp(disease, "heart") == 0)
            strcpy(doctor, "Dr.Ramesh Garg");
        else if (strcmp(disease, "skin") == 0)
            strcpy(doctor, "Dr.Sunidhi Bansal");
        else if (strcmp(disease, "teeth") == 0)
            strcpy(doctor, "Dr.Sunil Mangla");
        else if (strcmp(disease, "hair") == 0)
            strcpy(doctor, "Dr.Manoj Pathak");
        else if (strcmp(disease, "liver") == 0)
            strcpy(doctor, "Dr.B.S. Sinha");
        else if (strcmp(disease, "kidney") == 0)
            strcpy(doctor, "Dr.Shalini Sharma");
    }
};

void Patient::input()
{
    clrscr();
    gotoxy(10, 2);
    cout << "PatientID";
    gotoxy(10, 4);
    cout << "Name";
    gotoxy(10, 6);
    cout << "Address";
    gotoxy(10, 8);
    cout << "Phone Number";
    gotoxy(10, 10);
    cout << "Choose Disease to be treated of \n Heart, Skin, Teeth, Hair, Liver, Kidney:";
    gotoxy(35, 2);
    cin >> id;
    gotoxy(35, 4);
    gets(name);
    gotoxy(35, 6);
    gets(address);
    gotoxy(35, 8);
    gets(phone);
    gotoxy(50, 11);
    gets(disease);
    doc();
}

void Patient::display()
{
    gotoxy(10, 2);
    cout << "PatientID :";
    gotoxy(35, 2);
    cout << id;
    gotoxy(10, 4);
    cout << "Name :";
    gotoxy(35, 4);
    puts(name);
    gotoxy(10, 6);
    cout << "Address :";
    gotoxy(35, 6);
    puts(address);
    gotoxy(10, 8);
    cout << "Phone Number :";
    gotoxy(35, 8);
    puts(phone);
    gotoxy(10, 10);
    cout << "Disease :";
    gotoxy(35, 10);
    puts(disease);
    gotoxy(10, 12);
    cout << " Concerned Doctor :";
    gotoxy(35, 12);
    puts(doctor);
    cout << endl;
}

void retake(Patient &p2)
{
    clrscr();
    fstream abc;
    abc.open("Patient.dat", ios::in | ios::binary);
    Patient p3;
    while (!abc.eof())
    {
        abc.read((char *)&p3, sizeof(p3));
        if (abc.eof())
            break;
        if (p2.funid() == p3.funid())
        {
            do
            {
                cout << " ID :\t" << p2.funid() << "is already in use. Please enter another ID: ";
                p2.getid();
            }
            while (p2.funid() == p3.funid());
            abc.seekg(0);
        }
    }
}

void bill(Patient p1, long posi)
{
    clrscr();
    fstream abc;
    abc.open("Patient.dat", ios::out | ios::in | ios::binary);

    int paid;
    clrscr();
    gotoxy(35, 1);
    cout << "PATIENT BILL\n";
    cout << "Consultation Charges are :\t Rs.1200";

    cout << "\n Amount Paid:\t";
    cin >> paid;
    if (paid < 1200)
    {
        cout << "Amount Due:\t" << 1200 - paid;
        p1.fundue(1200 - paid);
        abc.seekg(posi);
        abc.write((char *)&p1, sizeof(p1));
    }
    else if (paid > 1200)
        cout << "Amount To be Returned:\t" << paid - 1200;
    cout << "\nGet Well Soon ";
    getchar();
    abc.close();
}

void writing()
{
    fstream abc, d;
    abc.open("Patient.dat", ios::app | ios::binary);
    Patient p1;
    p1.input();
    retake(p1);

    abc.write((char *)&p1, sizeof(Patient));
    abc.close();
}

void count()
{
    clrscr();
    fstream abc;
    abc.open("Patient.dat", ios::in | ios::binary);
    if (!abc)
    {
        cout << "File not Present";
        exit(1);
    }
    Patient p1;
    int s = 0;
    while (!abc.eof())
    {
        abc.read((char *)&p1, sizeof(Patient));
        s++;
    }
    cout << "Records : " << s - 1;
    getchar();
    abc.close();
}

void search()
{
    clrscr();
    fstream abc;
    abc.open("Patient.dat", ios::binary | ios::in);
    if (!abc)
    {
        cout << "File Not Present";
        exit(1);
    }
    Patient p1;
    int id1, c = 0;
    cout << "Enter PatientID ";
    cin >> id1;
    while (!abc.eof())
    {
        abc.read((char *)&p1, sizeof(p1));
        if (id1 == p1.funid())
        {
            c++;
            p1.display();
        }
    }
    if (c == 0)
    {
        cout << "No Record Found";
    }
    getchar();
    abc.close();
}

void del()
{
    clrscr();
    fstream abc, file;
    abc.open("Patient.dat", ios::in | ios::binary);
    file.open("temp.dat", ios::binary | ios::out);
    if (!abc)
    {
        cout << "File not present";
        exit(0);
    }
    Patient s;
    int x;
    char found = 'f', confirm = 'n';
    cout << " Enter ID of Patient to be deleted \n";
    cin >> x;
    while (!abc.eof())
    {
        abc.read((char *)&s, sizeof(s));
        if (s.funid() == x)
        {
            found = 't';
            cout << " \n are you sure you want to del?(y/n)";
            cin >> confirm;
            if (confirm == 'n')
                file.write((char *)&s, sizeof(s));
        }
        else
            file.write((char *)&s, sizeof(s));
        break;
    }

    if (found == 'f')
        cout << " File not present!\n";
    abc.close();
    file.close();
    remove("Patient.dat");
    rename("temp.dat", "Patient.dat");
}

void modify()
{
    clrscr();
    fstream abc;
    abc.open("Patient.dat", ios::out | ios::in | ios::binary);
    if (!abc)
    {
        cout << "File Not Present";
        exit(1);
    }
    Patient p1;
    int f = 0, id1;
    long pos;
    gotoxy(25, 10);
    cout << "Enter PatientID:\t";
    cin >> id1;
    while (!abc.eof())
    {
        pos = abc.tellg();
        abc.read((char *)&p1, sizeof(p1));
        if (abc.eof())
            break;
        if (p1.funid() == id1)
        {
            f = 1;
            p1.input();
            abc.seekg(pos);
            abc.write((char *)&p1, sizeof(p1));
        }
    }
    if (f == 0)
    {
        cout << "No Record Found";
        getchar();
    }
    abc.close();
}

void info()
{
    clrscr();
    gotoxy(30, 2);
    cprintf(" Information \n");
    gotoxy(5, 4);
    cprintf(" Name : Fortis Hospital ");
    gotoxy(5, 6);
    cprintf(" \nInspired by Research, Driven by Compassion");

    gotoxy(5, 10);
    cprintf("\nAddress: AA-3, Shalimar Bagh,Delhi-110088\n");

    gotoxy(5, 8);
    cprintf("\n We Provide Valueable and Reliable Services \n");
    getchar();
}

void show()
{
    int i;
    textcolor(8);
    for (i = 1; i <= 80; i++)
    {
        gotoxy(i, 6);
        cprintf("#");
    }
    for (i = 1; i <= 80; i++)
    {
        gotoxy(i, 17);
        cprintf("#");
    }
    for (i = 6; i <= 17; i++)
    {
        gotoxy(1, i);
        cprintf("#");
    }
    for (i = 6; i <= 17; i++)
    {
        gotoxy(80, i);
        cprintf("#");
    }
}

void color()
{
    clrscr();

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:/turboc3/bgi");

    setcolor(13);

    int i;
    for (i = 100; i < 150; i++)
    {
	circle(300, 200, i);

	delay(30);
    }
    setcolor(WHITE);
    outtextxy(260, 200, "WELCOME TO ");
    outtextxy(240, 210, " FORTIS HOSPITAL\n");

    setbkcolor(1);
    getchar();

    closegraph();
}

void main()
{
    color();
    clrscr();
    textbackground(3);
    fstream abc;
    Patient p;
    int ch, id1;
    char cho;
    long pos;
    {
	show();

	gotoxy(28, 10);
	cprintf("Welcome To FORTIS HOSPITAL");
	gotoxy(6, 13);
	cprintf("Made by Ritik");
	getchar();
    }
    {
	clrscr();
	show();
	gotoxy(5, 8);
	cout << "We Show Information About :";
	gotoxy(5, 10);
	cout << "-> PATIENT";
	gotoxy(5, 11);
	cout << "-> BILL";
	gotoxy(5, 12);
	cout << "->HOSPITAL ";
	getchar();
    }

    do
    {
	clrscr();
	gotoxy(15, 2);
	cout << "1. Admit New Patient";
	gotoxy(15, 4);
	cout << "2. Bill";
	gotoxy(15, 6);
	cout << "3. Search Record";
	gotoxy(15, 8);
	cout << "4. Modify Record";
	gotoxy(15, 10);
	cout << "5. Delete Record";
	gotoxy(15, 12);
	cout << "6. Count Total Records";
	gotoxy(15, 14);
	cout << "7. Information about Hospital";
	gotoxy(15, 16);
	cout << "0. Exit";
	gotoxy(10, 20);
	cout << "Enter your Choice - ";
	cin >> ch;
	switch (ch)
	{
	case 1:
	    writing();
	    break;
	case 2:
	    clrscr();
	    abc.open("patient.dat", ios::in | ios::binary);
	    int f = 0;
	    if (!abc)
	    {
		cout << "File not Present";
		exit(1);
	    }
	    gotoxy(30, 10);
	    cout << "Enter Patient ID:\t";
	    cin >> id1;
	    while (!abc.eof())
	    {
		pos = abc.tellg();
		abc.read((char *)&p, sizeof(p));
		if (abc.eof())
		    break;
		if (p.funid() == id1)
		{
		    f++;

		    bill(p, pos);
		}
	    }

	    if (f == 0)
	    {
		cout << "No Patient registered with PatientID: " << id1;
	    }
	    break;
	case 3:
	    search();
	    break;
	case 4:
	    modify();
	    break;
	case 5:
	    del();
	    break;
	case 6:
	    count();
	    break;
	case 7:
	    info();
	    break;
	case 0:
	    exit(0);
	default:
	    cout << "Please Choose Correct Option";
	}
    }
    while (ch != 0);
    getch();
    abc.close();
}
