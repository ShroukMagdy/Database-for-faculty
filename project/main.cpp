#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

const int number_database=10000;

 int n_student=0;
 int n_staff=0;

 int actual_size_student=0;
 int actual_size_staff=0;

 ifstream infile_student;
 ifstream infile_staff;

  int chosennumber_department_student;
  int chosennumber_department_staff;

  int chosennumber_year;
  int chosennumber_title;

  string newstudentname,newstudentcode,newstudentdepartment,newyear;
  string newstaffname,newstaffcode,newstaffdepartment,newtitle;

  string title[]={"Demonstrator","Teaching Assistant","Teacher","Assistant professor","Professor"};
  string year[]={"Freshmen","Sophomore","Junior","Senior I","Senior II" };
  string department[]={"Structure","Irrigation and hydraulics","Public works",
                    "Architecture","Urban Design and Planning","Power and Electrical Machines",
                    "Electronics and Electrical Communication","Computer and Systems",
                    "Mechatronics","Mechanical Power" ,"Automotive","Design and Production" };

  //start of student class
  class asustudent{
private:
    string studentname,studentcode,department,year;
public:
   void set_studentsname(string newstudentname){studentname=newstudentname;}
   void set_studentcode (string newstudentcode){studentcode=newstudentcode;}
   void set_department(string newstudentdepartment){department=newstudentdepartment;}
   void set_year(string newyear){year=newyear;}
   string get_studentname(){return studentname;}
   string get_studentcode(){return studentcode;}
   string get_department(){return department;}
   string get_year(){return year;}
   void print_data(){cout<<"name:"<<get_studentname()<<endl;
   cout<<"code:"<<get_studentcode()<<endl;
   cout<<"department:"<<get_department()<<endl;
   cout<<"year:"<<get_year()<<endl;}
    };
    asustudent students[number_database];
    //end of student class

    //start of staff class
    class asustaff{
private:
    string staffname,staffcode,department,title;
public:
   void set_staffname(string newstaffname){staffname=newstaffname;}
   void set_staffcode (string newstaffcode){staffcode=newstaffcode;}
   void set_department(string newstudentdepartment){department=newstudentdepartment;}
   void set_title(string newtitle){title=newtitle;}
   string get_staffname(){return staffname;}
   string get_staffcode(){return staffcode;}
   string get_department(){return department;}
   string get_title(){return title;}
   void print_data(){cout<<"name:"<<get_staffname()<<endl;
   cout<<"code:"<<get_staffcode()<<endl;
   cout<<"department:"<<get_department()<<endl;
   cout<<"title:"<<get_title()<<endl;}
    };
    asustaff staff[number_database];

    //end of staff class

   //function know number of students data
   void knownumberin_studentdata(){
 infile_student.open("students.csv");
     while(!infile_student.eof()){
        getline(infile_student,newstudentname,',');
        getline(infile_student,newstudentcode,',');
        getline(infile_student,newstudentdepartment,',');
        getline(infile_student,newyear);
        actual_size_student++;
             }
             actual_size_student--;
     infile_student.close();
     n_student=actual_size_student;
     cout<<"number of students till now="<<actual_size_student<<endl;
}
   //function know number of staff data
   void knownumberin_staffdata(){
 infile_staff.open("staff.csv");
     while(!infile_staff.eof()){
        getline(infile_staff,newstaffname,',');
        getline(infile_staff,newstaffcode,',');
        getline(infile_staff,newstaffdepartment,',');
        getline(infile_staff,newtitle);
        actual_size_staff++;
             }
             actual_size_staff--;
     infile_staff.close();
     n_staff=actual_size_staff;
     cout<<"number of staff till now="<<actual_size_staff<<endl;}


   //function to load student data
   void load_studentdata(){
 infile_student.open("students.csv");

       for(int j=0;j<actual_size_student;j++){
                getline(infile_student,newstudentname,',');
                students[j].set_studentsname(newstudentname);
                 getline(infile_student,newstudentcode,',');
                 students[j].set_studentcode(newstudentcode);
                  getline(infile_student,newstudentdepartment,',');
                  students[j].set_department(newstudentdepartment);
                   getline(infile_student,newyear);
                    students[j].set_year(newyear);

             }
              infile_student.close();
}
   //function to load staff data
   void load_staffdata(){
 infile_staff.open("staff.csv");

       for(int j=0;j<actual_size_staff;j++){
                getline(infile_staff,newstaffname,',');
                staff[j].set_staffname(newstaffname);
                 getline(infile_staff,newstaffcode,',');
                 staff[j].set_staffcode(newstaffcode);
                 getline(infile_staff,newstaffdepartment,',');
                  staff[j].set_department(newstaffdepartment);
                   getline(infile_staff,newtitle);
                    staff[j].set_title(newtitle);

             }
              infile_staff.close();   }



    //function for unique code for student
    /* max acceptable number of students =10000
    code consists of 2 digits for year - 2 digits for department - 4 digits for number */
    string unique_code_student(int number_department,int number_year){
     char uniquecode[4];
    switch(number_year){
case(1):        uniquecode[0]='0';         uniquecode[1]='1';           break;
case(2):        uniquecode[0]='0';         uniquecode[1]='2';           break;
case(3):        uniquecode[0]='0';         uniquecode[1]='3';           break;
case(4):        uniquecode[0]='0';         uniquecode[1]='4';           break;
case(5):        uniquecode[0]='0';         uniquecode[1]='5';           break;
default:        cout<<"error in the system";                             break;      }
    switch(number_department){
case(1):        uniquecode[2]='S';         uniquecode[3]='T';           break;
case(2):        uniquecode[2]='I';         uniquecode[3]='H';           break;
case(3):        uniquecode[2]='P';         uniquecode[3]='W';           break;
case(4):        uniquecode[2]='A';         uniquecode[3]='R';           break;
case(5):        uniquecode[2]='D';         uniquecode[3]='P';           break;
case(6):        uniquecode[2]='P';         uniquecode[3]='E';           break;
case(7):        uniquecode[2]='E';         uniquecode[3]='C';           break;
case(8):        uniquecode[2]='C';         uniquecode[3]='S';           break;
case(9):        uniquecode[2]='M';         uniquecode[3]='E';           break;
case(10):       uniquecode[2]='M';         uniquecode[3]='P';           break;
case(11):       uniquecode[2]='A';         uniquecode[3]='U';           break;
case(12):       uniquecode[2]='D';         uniquecode[3]='P';           break;
default:        cout<<"error in the system";                            break;      }
string firstpart_code=uniquecode;
ostringstream oss;
string thirdpart_code;
oss << n_student;
thirdpart_code=oss.str();
string secondpart_code;
    if(n_student<10&&n_student>=0){secondpart_code="000";                                                 return firstpart_code+secondpart_code+thirdpart_code;}
    else if(n_student<100&&n_student>=10){secondpart_code="00";                                           return firstpart_code+secondpart_code+thirdpart_code;}
    else if(n_student<1000&&n_student>=100){secondpart_code="0";                                          return firstpart_code+secondpart_code+thirdpart_code;}
    else if (n_student>=10000){cout<<"max. acceptable number=10000 & no standard coding"<<endl;   return firstpart_code+thirdpart_code;}
    else{cout<<"wrong number for number of students";                                     return firstpart_code+thirdpart_code;}       }

   //function for unique code for staff
    /* max acceptable number of staff =10000
    code consists of 2 digits for title - 2 digits for department - 4 digits for number */
    string unique_code_staff(int number_department,int number_title){
     char uniquecode_staff[4];
    switch(number_title){
case(1):        uniquecode_staff[0]='0';         uniquecode_staff[1]='1';           break;
case(2):        uniquecode_staff[0]='0';         uniquecode_staff[1]='2';           break;
case(3):        uniquecode_staff[0]='0';         uniquecode_staff[1]='3';           break;
case(4):        uniquecode_staff[0]='0';         uniquecode_staff[1]='4';           break;
case(5):        uniquecode_staff[0]='0';         uniquecode_staff[1]='5';           break;
default:        cout<<"error in the system";                             break;      }
    switch(number_department){
case(1):        uniquecode_staff[2]='S';         uniquecode_staff[3]='T';           break;
case(2):        uniquecode_staff[2]='I';         uniquecode_staff[3]='H';           break;
case(3):        uniquecode_staff[2]='P';         uniquecode_staff[3]='W';           break;
case(4):        uniquecode_staff[2]='A';         uniquecode_staff[3]='R';           break;
case(5):        uniquecode_staff[2]='D';         uniquecode_staff[3]='P';           break;
case(6):        uniquecode_staff[2]='P';         uniquecode_staff[3]='E';           break;
case(7):        uniquecode_staff[2]='E';         uniquecode_staff[3]='C';           break;
case(8):        uniquecode_staff[2]='C';         uniquecode_staff[3]='S';           break;
case(9):        uniquecode_staff[2]='M';         uniquecode_staff[3]='E';           break;
case(10):       uniquecode_staff[2]='M';         uniquecode_staff[3]='P';           break;
case(11):       uniquecode_staff[2]='A';         uniquecode_staff[3]='U';           break;
case(12):       uniquecode_staff[2]='D';         uniquecode_staff[3]='P';           break;
default:        cout<<"error in the system";                            break;      }
string firstpart_code=uniquecode_staff;
ostringstream oss;
string thirdpart_code;
oss << n_staff;
thirdpart_code=oss.str();
string secondpart_code;
    if(n_staff<10&&n_staff>=0){secondpart_code="000";                                                 return firstpart_code+secondpart_code+thirdpart_code;}
    else if(n_staff<100&&n_staff>=10){secondpart_code="00";                                           return firstpart_code+secondpart_code+thirdpart_code;}
    else if(n_staff<1000&&n_staff>=100){secondpart_code="0";                                          return firstpart_code+secondpart_code+thirdpart_code;}
    else if (n_staff>=10000){cout<<"max. acceptable number=10000 & no standard coding"<<endl;         return firstpart_code+thirdpart_code;}
    else{cout<<"wrong number for number of staff";                                                    return firstpart_code+thirdpart_code;}       }

    //to enter new name or change for student
    string new_change_name_student(){
    string firstpart_name,secondpart_name;
   cout<<"enter first name"<<endl;
   cin>>firstpart_name;
   cout<<"enter second name"<<endl;
   cin>>secondpart_name;
   newstudentname=firstpart_name+" "+secondpart_name;
   return newstudentname;}

   //to enter new name or change for staff
    string new_change_name_staff(){
    string firstpart_name,secondpart_name;
   cout<<"enter first name"<<endl;
   cin>>firstpart_name;
   cout<<"enter second name"<<endl;
   cin>>secondpart_name;
   newstaffname=firstpart_name+" "+secondpart_name;
   return newstaffname;}


  //number of department for student
  int number_department_student(){

      do{ cout<<"choose number of department"<<endl;
    cout<<"1-Structure"<<"\n"<<"2-Irrigation and hydraulics"<<"\n"<<"3-Public works"<<"\n"<<"4-Architecture"<<"\n"<<"5-Urban Design and Planning"<<endl;
    cout<<"6-Power and Electrical Machines"<<"\n"<<"7-Electronics and Electrical Communication"<<"\n"<<"8-Computer and Systems"<<"\n"<<"9-Mechatronics"<<endl;
    cout<<"10-Mechanical Power"<<"\n"<<"11-Automotive"<<"\n"<<"12-Design and Production"<<endl;
    cin>>chosennumber_department_student;      }
      while(chosennumber_department_student<0||chosennumber_department_student>12);

newstudentdepartment=department[chosennumber_department_student-1];       return chosennumber_department_student;}

  //number of department for staff
  int number_department_staff(){

      do{ cout<<"choose number of department"<<endl;
    cout<<"1-Structure"<<"\n"<<"2-Irrigation and hydraulics"<<"\n"<<"3-Public works"<<"\n"<<"4-Architecture"<<"\n"<<"5-Urban Design and Planning"<<endl;
    cout<<"6-Power and Electrical Machines"<<"\n"<<"7-Electronics and Electrical Communication"<<"\n"<<"8-Computer and Systems"<<"\n"<<"9-Mechatronics"<<endl;
    cout<<"10-Mechanical Power"<<"\n"<<"11-Automotive"<<"\n"<<"12-Design and Production"<<endl;
    cin>>chosennumber_department_staff;      }
      while(chosennumber_department_staff<0||chosennumber_department_staff>12);

newstaffdepartment=department[chosennumber_department_staff-1];       return chosennumber_department_staff;}

  //number of year for student
   int number_year(){

          do{cout<<"choose number of year"<<endl;
            cout<<"1-Freshmen       2-Sophomore          3-Junior            4-Senior I                5-Senior II"<<endl;
            cin>>chosennumber_year;
          }
          while(chosennumber_year<0||chosennumber_year>5);

 newyear=year[chosennumber_year-1];       return chosennumber_year;}

  //number of title for staff
  int number_title(){

          do{cout<<"choose number of title"<<endl;
            cout<<"1-Demonstrator       2-Teaching Assistant          3-Teacher            4-Assistant professor               5-Professor"<<endl;
            cin>>chosennumber_title;
          }
          while(chosennumber_title<0||chosennumber_title>5);

 newtitle=title[chosennumber_title-1];       return chosennumber_title;}

   //add student

   void add_student(){
    n_student++;
    actual_size_student++;
    newstudentname=new_change_name_student();
    newstudentcode=unique_code_student(number_department_student(),number_year());
for(int repeat_uniquecode=0;repeat_uniquecode<actual_size_student;repeat_uniquecode++){
        if(newstudentcode==students[repeat_uniquecode].get_studentcode()){n_student++; newstudentcode=unique_code_student(chosennumber_department_student,chosennumber_year);}
    }
    students[actual_size_student-1].set_studentsname(newstudentname);
    students[actual_size_student-1].set_studentcode(newstudentcode);
    students[actual_size_student-1].set_department(newstudentdepartment);
    students[actual_size_student-1].set_year(newyear);
    students[actual_size_student-1].print_data(); cout<<"the student is added"<<endl;
    }

    //add staff
    void add_staff(){
    n_staff++;
    actual_size_staff++;
    newstaffname=new_change_name_staff();
    newstaffcode=unique_code_staff(number_department_staff(),number_title());
for(int repeat_uniquecode=0;repeat_uniquecode<actual_size_staff;repeat_uniquecode++){
        if(newstaffcode==staff[repeat_uniquecode].get_staffcode()){n_staff++; newstaffcode=unique_code_staff(chosennumber_department_staff,chosennumber_title);}
    }
    staff[actual_size_staff-1].set_staffname(newstaffname);
    staff[actual_size_staff-1].set_staffcode(newstaffcode);
    staff[actual_size_staff-1].set_department(newstaffdepartment);
    staff[actual_size_staff-1].set_title(newtitle);
    staff[actual_size_staff-1].print_data(); cout<<"the staff member is added"<<endl;
    }


    //remove student
    void remove_student(){
    int counterremove_student=0;
    cout<<"enter student code"<<endl;
    cin>>newstudentcode;
  while(newstudentcode!=students[counterremove_student].get_studentcode()&&counterremove_student<actual_size_student){counterremove_student++;}
  if(counterremove_student<actual_size_student){
        students[counterremove_student].print_data();
       for(int countershift_student=counterremove_student;countershift_student<actual_size_student;countershift_student++){
        students[countershift_student].set_studentsname(students[countershift_student+1].get_studentname());
        students[countershift_student].set_studentcode(students[countershift_student+1].get_studentcode());
        students[countershift_student].set_department(students[countershift_student+1].get_department());
        students[countershift_student].set_year(students[countershift_student+1].get_year());    }
 cout<<"the student is removed"<<endl;   actual_size_student--; }
      else{cout<<"not in the system"<<endl;}
    }

    //remove staff member
     void remove_staff(){
    int counterremove_staff=0;
    cout<<"enter staff member code"<<endl;
    cin>>newstaffcode;
  while(newstaffcode!=staff[counterremove_staff].get_staffcode()&&counterremove_staff<actual_size_staff){counterremove_staff++;}
  if(counterremove_staff<actual_size_staff){
        staff[counterremove_staff].print_data();
       for(int countershift_staff=counterremove_staff;countershift_staff<actual_size_staff;countershift_staff++){
        staff[countershift_staff].set_staffname(staff[countershift_staff+1].get_staffname());
        staff[countershift_staff].set_staffcode(staff[countershift_staff+1].get_staffcode());
        staff[countershift_staff].set_department(staff[countershift_staff+1].get_department());
        staff[countershift_staff].set_title(staff[countershift_staff+1].get_title());    }
 cout<<"the staff member is removed"<<endl;   actual_size_staff--; }
      else{cout<<"not in the system"<<endl;}
    }

    //modify student
    void modify_student(){
 int counterchange_student=0;
int choicechange_student=0;
cout<<"enter student code"<<endl;
    cin>>newstudentcode;
  while(newstudentcode!=students[counterchange_student].get_studentcode()&&counterchange_student<actual_size_student){counterchange_student++;}
  if(counterchange_student<actual_size_student){
      students[counterchange_student].print_data();
      do{cout<<"change name?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicechange_student; }
      while(choicechange_student<0||choicechange_student>2);
      if(choicechange_student==1){students[counterchange_student].set_studentsname(new_change_name_student());}
         do{cout<<"change department?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicechange_student;}
      while(choicechange_student<0||choicechange_student>2);
       if(choicechange_student==1){students[counterchange_student].set_department(department[number_department_student()-1]);}
      do{cout<<"change year?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicechange_student;}
      while(choicechange_student<0||choicechange_student>2);
          if(choicechange_student==1){students[counterchange_student].set_year(year[number_year()-1]);}
      students[counterchange_student].print_data();
       }
      else{cout<<"not in the system"<<endl;}
    }

    //modify staff member
     void modify_staff(){
 int counterchange_staff=0;
int choicechange_staff=0;
cout<<"enter staff member code"<<endl;
    cin>>newstaffcode;
  while(newstaffcode!=staff[counterchange_staff].get_staffcode()&&counterchange_staff<actual_size_staff){counterchange_staff++;}
  if(counterchange_staff<actual_size_staff){
      staff[counterchange_staff].print_data();
      do{cout<<"change name?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicechange_staff; }
      while(choicechange_staff<0||choicechange_staff>2);
      if(choicechange_staff==1){staff[counterchange_staff].set_staffname(new_change_name_staff());}
         do{cout<<"change department?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicechange_staff;}
      while(choicechange_staff<0||choicechange_staff>2);
       if(choicechange_staff==1){staff[counterchange_staff].set_department(department[number_department_staff()-1]);}
      do{cout<<"change title?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicechange_staff;}
      while(choicechange_staff<0||choicechange_staff>2);
          if(choicechange_staff==1){staff[counterchange_staff].set_title(title[number_title()-1]);}
      staff[counterchange_staff].print_data();
       }
      else{cout<<"not in the system"<<endl;}
    }

    //search for a student
     void searchfor_student(){
    int counter_looking_student=0;
    int choicelooking_student=0;
    bool find_fullname_student=false;
    bool find_partname_student=false;
    do{cout<<"search by code?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicelooking_student; }
      while(choicelooking_student<0||choicelooking_student>2);
      if(choicelooking_student==1){cout<<"enter student code"<<endl;       cin>>newstudentcode;
  while(newstudentcode!=students[counter_looking_student].get_studentcode()&&counter_looking_student<actual_size_student){counter_looking_student++;}
  if(counter_looking_student<actual_size_student){
        students[counter_looking_student].print_data();  }
      else{cout<<"not in the system"<<endl;  }}

//searching by full name
else{
do{cout<<"search by full name?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicelooking_student; }
      while(choicelooking_student<0||choicelooking_student>2);
      if(choicelooking_student==1){cout<<"enter student full name"<<endl;       cin.ignore(); getline(cin,newstudentname);

      for(counter_looking_student=0;counter_looking_student<actual_size_student;counter_looking_student++){
        if(newstudentname==students[counter_looking_student].get_studentname()){students[counter_looking_student].print_data();find_fullname_student=true;}
      }

      if(find_fullname_student==false){cout<<"not in the system"<<endl;}       }
      //searching by part name
      else{
do{cout<<"search by part name?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicelooking_student; }
      while(choicelooking_student<0||choicelooking_student>2);
      if(choicelooking_student==1){cout<<"enter student part name"<<endl;       cin.ignore(); getline(cin,newstudentname);

       for(counter_looking_student=0;counter_looking_student<actual_size_student;counter_looking_student++){
        if(strstr(students[counter_looking_student].get_studentname().c_str(),newstudentname.c_str())){students[counter_looking_student].print_data();find_partname_student=true;}
      }
       if(find_partname_student==false){cout<<"not in the system"<<endl;}        }
      }             }         }

      //search for staff member
       void searchfor_staff(){
    int counter_looking_staff=0;
    int choicelooking_staff=0;
    bool find_fullname_staff=false;
    bool find_partname_staff=false;
    do{cout<<"search by code?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicelooking_staff; }
      while(choicelooking_staff<0||choicelooking_staff>2);
      if(choicelooking_staff==1){cout<<"enter staff member code"<<endl;       cin>>newstaffcode;
  while(newstaffcode!=staff[counter_looking_staff].get_staffcode()&&counter_looking_staff<actual_size_staff){counter_looking_staff++;}
  if(counter_looking_staff<actual_size_staff){
        staff[counter_looking_staff].print_data();  }
      else{cout<<"not in the system"<<endl;  }}

//searching by full name
else{
do{cout<<"search by full name?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicelooking_staff; }
      while(choicelooking_staff<0||choicelooking_staff>2);
      if(choicelooking_staff==1){cout<<"enter staff member full name"<<endl;       cin.ignore(); getline(cin,newstaffname);

      for(counter_looking_staff=0;counter_looking_staff<actual_size_staff;counter_looking_staff++){
        if(newstaffname==staff[counter_looking_staff].get_staffname()){staff[counter_looking_staff].print_data();find_fullname_staff=true;}
      }

      if(find_fullname_staff==false){cout<<"not in the system"<<endl;}       }
      //searching by part name
      else{
do{cout<<"search by part name?"<<endl;cout<<"1-yes   2-no"<<endl;cin>>choicelooking_staff; }
      while(choicelooking_staff<0||choicelooking_staff>2);
      if(choicelooking_staff==1){cout<<"enter staff member part name"<<endl;       cin.ignore(); getline(cin,newstaffname);

       for(counter_looking_staff=0;counter_looking_staff<actual_size_staff;counter_looking_staff++){
        if(strstr(staff[counter_looking_staff].get_staffname().c_str(),newstaffname.c_str())){staff[counter_looking_staff].print_data();find_partname_staff=true;}
      }
       if(find_partname_staff==false){cout<<"not in the system"<<endl;}        }
      }             }         }

    //save data of student
    void savedata_student(){
    int save_student=0;
ofstream outfile_student;
do{     cout<<"do you want to save your data?"<<endl;
        cout<<"1-yes   2-no"<<endl;   cin>>save_student;}
while(save_student<0||save_student>2);
if(save_student==1){
 outfile_student.open("students.csv" ,ios::out | ios::trunc);
for(int h=0;h<actual_size_student;h++){
           outfile_student<<students[h].get_studentname()<<","<<students[h].get_studentcode()<<","<<students[h].get_department()<<","<<students[h].get_year()<<"\n"; }
           cout<<"saved"<<endl;}
    else{cout<<"not saved"<<endl;}

outfile_student.close();    }

   //save data of staff member
   void savedata_staff(){
    int save_staff=0;
ofstream outfile_staff;
do{     cout<<"do you want to save your data?"<<endl;
        cout<<"1-yes   2-no"<<endl;   cin>>save_staff;}
while(save_staff<0||save_staff>2);
if(save_staff==1){
 outfile_staff.open("staff.csv" ,ios::out | ios::trunc);
for(int h=0;h<actual_size_staff;h++){
           outfile_staff<<staff[h].get_staffname()<<","<<staff[h].get_staffcode()<<","<<staff[h].get_department()<<","<<staff[h].get_title()<<"\n"; }
           cout<<"saved"<<endl;}
    else{cout<<"not saved"<<endl;}

outfile_staff.close();    }

int main()
{
    int studentorstaff=0;
    cout<<"the max. number for students = 10000"<<endl<<"the max. number for staff members = 10000"<<endl<<"any choice should be number"<<endl;
do{cout<<"1-students   2-staff"<<endl;   cin>>studentorstaff;}
while(studentorstaff<0||studentorstaff>2);

//work with student data only
if(studentorstaff==1){
bool repeat_code_student=true;


    knownumberin_studentdata();


        if(n_student<=number_database){
       load_studentdata();
              for(int firstcounter_repeat_student=0;firstcounter_repeat_student<n_student;firstcounter_repeat_student++){
                for(int secondcouter_repeat_student=firstcounter_repeat_student+1;secondcouter_repeat_student<n_student;secondcouter_repeat_student++){
                    if(students[firstcounter_repeat_student].get_studentcode()==students[secondcouter_repeat_student].get_studentcode()){repeat_code_student=false;}
                }
              }
int choice_student;


bool in_student=false;



if(repeat_code_student==true){
while(in_student!=true){
do{  cout<<"1-add student"<<endl;
     cout<<"2-remove student"<<endl;
     cout<<"3-search for a student"<<endl;
     cout<<"4-modify a student"<<endl;
     cout<<"press any other number to exit"<<endl;
     cout<<"choose what you want to do"<<endl;
cin>>choice_student;
}
while(choice_student<0);

switch(choice_student){
case(1)://add
    if(actual_size_student<=number_database){
    add_student();    }
    else{cout<<"you have the max. number of students"<<endl;}
    break;
case(2)://remove
remove_student();
        break;
case(3)://search
searchfor_student();
      break;

case(4)://modify
modify_student();
     break;
default:cout<<"out of the system"<<endl; in_student=true; break;}}
savedata_student();
}
else{cout<<"you have repeated code"<<endl;}

}
 else{cout<<"the file contains number of students greater than allowed"<<endl;}      }
 //work with staff data only
 else{
   bool repeat_code_staff=true;


    knownumberin_staffdata();


        if(n_staff<=number_database){
       load_staffdata();
              for(int firstcounter_repeat_staff=0;firstcounter_repeat_staff<n_staff;firstcounter_repeat_staff++){
                for(int secondcouter_repeat_staff=firstcounter_repeat_staff+1;secondcouter_repeat_staff<n_staff;secondcouter_repeat_staff++){
                    if(staff[firstcounter_repeat_staff].get_staffcode()==staff[secondcouter_repeat_staff].get_staffcode()){repeat_code_staff=false;}
                }
              }
int choice_staff;


bool in_staff=false;



if(repeat_code_staff==true){
while(in_staff!=true){
do{  cout<<"1-add staff member"<<endl;
     cout<<"2-remove staff member"<<endl;
     cout<<"3-search for a staff member"<<endl;
     cout<<"4-modify a staff member"<<endl;
     cout<<"press any other number to exit"<<endl;
     cout<<"choose what you want to do"<<endl;
cin>>choice_staff;
}
while(choice_staff<0);

switch(choice_staff){
case(1)://add
    if(actual_size_staff<=number_database){
    add_staff();    }
    else{cout<<"you have the max. number of staff members"<<endl;}
    break;
case(2)://remove
remove_staff();
        break;
case(3)://search
searchfor_staff();
      break;

case(4)://modify
modify_staff();
     break;
default:cout<<"out of the system"<<endl; in_staff=true; break;}}
savedata_staff();
}
else{cout<<"you have repeated code"<<endl;}

}
 else{cout<<"the file contains number of staff members greater than allowed"<<endl;}




 }
            }
